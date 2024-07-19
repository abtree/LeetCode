package main

import (
	"encoding/json"
	"log"
)

const jdat = `{
	"Rate": 1.0,
	"Other": 2
}`

func main() {
	var dat interface{}
	err := json.Unmarshal([]byte(jdat), &dat)
	if err != nil {
		log.Fatalln(err)
	}
	log.Println(dat)
}
