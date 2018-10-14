// Run "node PalindromeNum.js ${yourNumber}" in command line
const num = parseInt(process.argv[2]);

const isNum = typeof num === 'number';
if (!isNum) {
  console.log('Not a number');
  return null;
}
const reverseNum = parseInt(
  num
    .toString()
    .split('')
    .reverse()
    .join(''),
);

const isPalindrome = num === reverseNum;
if (isPalindrome) {
  console.log(`${num} is a palindrome.`);
  return null;
}

console.log(`${num} is not a palindrome.`);
