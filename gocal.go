package main

//importing fmt package for basic functions
import "fmt"

//declaration of functions
func add(a float32, b float32) float32 {
	return a + b
}

func substract(a float32, b float32) float32 {
	return a - b
}

func multiply(a float32, b float32) float32 {
	return a * b
}

func divide(a float32, b float32) float32 {
	return a / b
}

//main function
func main() {

	//declaration of variables
	var num1, num2 float32
	var operator string
	fmt.Print("Enter No 1: ")
	fmt.Scanln(&num1)

	fmt.Print("Enter No 2: ")
	fmt.Scanln(&num2)

	fmt.Print("Enter operator: ")
	fmt.Scanln(&operator)

	var output float32
	switch operator {
	case "+":
		output = add(num1, num2)
	case "-":
		output = substract(num1, num2)
	case "*":
		output = multiply(num1, num2)
	case "/":
		output = divide(num1, num2)
	}
	fmt.Print("Your answer is: ")
	fmt.Println(output)
	fmt.Println("\n")
}
