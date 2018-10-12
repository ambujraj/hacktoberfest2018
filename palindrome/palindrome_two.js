const palindrome = (num) => {
  if (num < 10) {
    return true
  };

  const numArr = num.toString().split("");

  let reverse = "";

  for (let char of numArr) {
    reverse = char + reverse
  };

  return num.toString() === reverse;
}
