// Takes a number and returns a boolean for validity of being an armstrong number or not.


function armstrongNumber(number) {
    return number === number
                        .toString(10)
                        .split("")
                        .map(digit => Math.pow(Number(digit),3))
                        .reduce((memo,curr) => memo + curr);
}