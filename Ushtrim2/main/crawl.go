package main

import (
	"crypto/tls"
	"flag"
	"fmt"
	"net/http"
	"net/url"
	"os"

	"../collectlinks"
)

func usage() {
	fmt.Fprintf(os.Stderr, "usage: crawl http://example.com/path/file.html\n")
	flag.PrintDefaults()
	os.Exit(2)
}

func main() {

	flag.Usage = usage
	flag.Parse()

	args := flag.Args()
	fmt.Println(args)
	if len(args) < 1 {
		usage()
		fmt.Println("Please specify start page")
		os.Exit(1)
	}

	queue := make(chan string)
	filteredQueue := make(chan string)

	go func() { queue <- args[0] }()
	go filterQueue(queue, filteredQueue)

	// introduce a bool channel to synchronize execution of concurrently running crawlers
	done := make(chan bool)

	// pull from the filtered queue, add to the unfiltered queue
	for i := 0; i < 5; i++ {
		go func() {
			for uri := range filteredQueue {
				enqueue(uri, queue)
			}
			done <- true
		}()
	}
	<-done
}

func filterQueue(in chan string, out chan string) {
	var seen = make(map[string]bool)
	for val := range in {
		if !seen[val] {
			seen[val] = true
			out <- val
		}
	}
}

func enqueue(uri string, queue chan string) {
	fmt.Println("fetching", uri)
	transport := &http.Transport{
		TLSClientConfig: &tls.Config{
			InsecureSkipVerify: true,
		},
	}
	client := http.Client{Transport: transport}
	resp, err := client.Get(uri)
	if err != nil {
		return
	}
	defer resp.Body.Close()

	links := collectlinks.All(resp.Body)

	for _, link := range links {
		absolute := fixURL(link, uri)
		if uri != "" {
			go func() { queue <- absolute }()
		}
	}
}

func fixURL(href, base string) string {
	uri, err := url.Parse(href)
	if err != nil {
		return ""
	}
	baseURL, err := url.Parse(base)
	if err != nil {
		return ""
	}
	uri = baseURL.ResolveReference(uri)
	return uri.String()
}