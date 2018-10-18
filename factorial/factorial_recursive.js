const factorial = num => {
  if (!Number.isInteger(num)) {
    throw Error('Not an integer')
  }

  if (num < 0) {
    throw Error('Negative number')
  }

  if (num == 0 || num == 1) {
    return 1
  }

  return num * factorial(num-1);
}

console.log(factorial(5))
