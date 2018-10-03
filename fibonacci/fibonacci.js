function fibonacci(num) {
    if (num <= 1) return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}


// implementing fibonacci using a for loop
function fibonacci(number) {
  let fibOne = 0, fibTwo = 1, next = 1;
  for (let i = 2; i <= number; i++) {
    next = fibOne + fibTwo;
    fibOne = fibTwo;
    fibTwo = next;
  }
  return next;
}



//implementing a fibonacci sequence using memoization technique
const fibonacci = (function () {
  let memo = [0, 1];
  let fib = function (n) {
      let result = memo[n];
      if (typeof result !== 'number') {
        result = fib(n - 1) + fib(n - 2);
        memo[n] = result;
      }
      return result;
      };
  return fib;
}());

