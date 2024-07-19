package main

import (
	"encoding/base64"
	"fmt"
	"strings"
)

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Encodes a URL to a shortened URL.
func (this *Codec) encode(longUrl string) string {
	url := "http://tinyurl.com/" + base64.StdEncoding.EncodeToString([]byte(longUrl))
	return url
}

// Decodes a shortened URL to its original URL.
func (this *Codec) decode(shortUrl string) string {
	url := strings.TrimPrefix(shortUrl, "http://tinyurl.com/")
	byts, _ := base64.StdEncoding.DecodeString(url)
	return string(byts)
}

func main() {
	cls := Constructor()
	url := cls.encode("https://leetcode.com/problems/design-tinyurl")
	fmt.Println("Encode: ", url)
	fmt.Println("Decode", cls.decode(url))
}
