(function(){
"use strict"

const isPalindrome = function(word) {
    //reverse the word, remove whitespace and check if it equals the original
    return (word.split("").reverse().join("").replace(/\s+/g, '') === word.replace(/\s+/g, ''))
}

module.exports = isPalindrome;

})();  