package main

import "strings"

func main() {
	validNumber := "1111111111"
	badNumber := "11111111111"
	if validateNumber(validNumber) {
		fmt.Println(validNumber + " is valid!")
	} else {
		fmt.Println(validNumber + " is invalid!")
	}
	if validateNumber(badNumber) {
		fmt.Println(badNumber + " is valid!")
	} else {
		fmt.Println(badNumber + " is invalid!")
	}
}

func validateNumber(number string) bool {
	if number != nil && len(number) == 10 {
		return true
	} else {
		return false
	}
	return false
}
