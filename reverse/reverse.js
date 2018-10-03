function reverse_number(n){
  const a = n.toString().split('').reverse().join('');
  return parseInt(a) * Math.sign(n);
}

// STEPS EXPLAINED
// Make the number a string
// Convert the String to an Array and Reverse the Array
// Convert the Reversed Array to a String
// Make the String a number
// Apply the Sign using Math.sign for +ve or -ve integers

