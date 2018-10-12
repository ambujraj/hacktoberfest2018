// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const isPalindrome = require('./isPalindrome');

describe("Check if it is a palindrome", () => {

  it('should check recognise the palindrome', () => {
  	expect(isPalindrome("racecar")).toBe(true);
    expect(isPalindrome("0011221100")).toBe(true);
    expect(isPalindrome("a nut for a jar of tuna")).toBe(true);
  })

  it('should check recognise that it is not a palindrome', () => {
  	expect(isPalindrome("Racecar")).toBe(false);
    expect(isPalindrome("0011223344")).toBe(false);
    expect(isPalindrome("this is not a palindrome")).toBe(false);
  })

});