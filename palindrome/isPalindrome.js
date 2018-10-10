const isPalindrome = str => {
  let arr = str.split("");
  let reversedStr = arr.reverse().join("");
  return reversedStr === str;
};

isPalindrome("kayak");
