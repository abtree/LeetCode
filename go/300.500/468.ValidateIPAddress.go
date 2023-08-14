package main

import (
	"bytes"
	"fmt"
	"strconv"
)

func validV4(bs []byte) bool {
	size := len(bs)
	if size < 1 || size > 3 {
		return false
	}
	if size > 1 && bs[0] == '0' {
		return false
	}
	i, err := strconv.ParseInt(string(bs), 10, 32)
	if err != nil {
		return false
	}
	return i >= 0 && i < 256
}

func validV6(bs []byte) bool {
	size := len(bs)
	if size < 1 || size > 4 {
		return false
	}
	_, err := strconv.ParseInt(string(bs), 16, 64)
	return err == nil
}

func validIPAddress(queryIP string) string {
	byts := []byte(queryIP)
	if bytes.IndexByte(byts, '.') != -1 {
		//IPv4
		bs := bytes.Split(byts, []byte{'.'})
		if len(bs) != 4 {
			return "Neither"
		}
		for _, v := range bs {
			if !validV4(v) {
				return "Neither"
			}
		}
		return "IPv4"
	} else {
		//IPv6
		bs := bytes.Split(byts, []byte{':'})
		if len(bs) != 8 {
			return "Neither"
		}
		for _, v := range bs {
			if !validV6(v) {
				return "Neither"
			}
		}
		return "IPv6"
	}
}

func main() {
	fmt.Println(validIPAddress("172.16.254.1"), "IPv4")
	fmt.Println(validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"), "IPv6")
	fmt.Println(validIPAddress("256.256.256.256"), "Neither")
	fmt.Println(validIPAddress("2001:0db8:85a3::8A2E:037j:7334"), "Neither")
	fmt.Println(validIPAddress("02001:0db8:85a3:0000:0000:8a2e:0370:7334"), "Neither")
}
