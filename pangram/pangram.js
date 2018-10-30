const isPangram = function (string) {
    
    let stringArr = string.toLowerCase().split('');
    let pangram = {};
    for (let char of stringArr) {
        if (pangram[char] === undefined) {
            pangram[char] = 1;
        } else {
            pangram[char]++;
        }
    }
    
    let start = "a".charCodeAt(0),
        end = "z".charCodeAt(0);
    for (let i = start; i <= end; i++) {
        if (pangram[String.fromCharCode(i)] === undefined) {
            return false;
        }
    }
    return true;
}

console.log("Welcome to Hacktoberfest 2018");
console.log("This is a Pangram program in NodeJS");
console.log("'The quick brown fox jumps over the lazy dog' is " + (isPangram('The quick brown fox jumps over the lazy dog') ? '' : 'not ') + "a pangram");
console.log("'This is not a pangram' is " + (isPangram('This is not a pangram') ? '' : 'not ') + "a pangram");