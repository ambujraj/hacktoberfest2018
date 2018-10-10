package main

import "fmt"

//Prime Sieve, or Sieve of Eratosthenes is an ancient algorithm
//for finding prime number up to the given limit. It works by
//eliminating multiples of all primes in a sequential manner.

//This is just an implementation of the Prime Sieve using Go Concurrency.
//Goroutines are used for filtering numbers.
//There is one goroutine for every Prime number discovered, and channels
//for sending numbers from the generators to the filters.
//When prime is found, it’s being sent via the channel to the main for output.
//This is just a proof of concept and this naive approach is not very efficient.
//Although this may be faster than many implementations in other languages.
//The for loop in the main function decides how many prime numbers is printed.

// Send the sequence 2, 3, 4, ... to channel 'ch'.
func Generate(ch chan<- int) {
	for i := 2; ; i++ {
		ch <- i // Send 'i' to channel 'ch'.

	}

}

// Copy the values from channel 'in' to channel 'out',
// removing those divisible by 'prime'.
func Filter(in <-chan int, out chan<- int, prime int) {
	for {
		i := <-in // Receive value from 'in'.
		if i%prime != 0 {
			out <- i // Send 'i' to 'out'.

		}

	}

}

// The prime sieve: Daisy-chain Filter processes.
func main() {
	ch := make(chan int)       // Create a new channel.
	go Generate(ch)            // Launch Generate goroutine.
	for i := 0; i < 100; i++ { //This allows 1st 100 prime numbers to be printed
		prime := <-ch
		fmt.Println(prime) //Printing the Prime number
		ch1 := make(chan int)
		go Filter(ch, ch1, prime)
		ch = ch1

	}

}
