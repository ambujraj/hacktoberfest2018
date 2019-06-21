/**
* In javascript, call by reference works only if we are passing an object(including array) 
* to a function, rest all are call by value. 
*/

function callByReference(a, b, c){
  a = 4;
  b[0] = 6;
  c.has = false
}

let x = 4;
let y = [1, 3, 4];
let z = {has: true};
callByReference(x, y, z);
console.log(x, y, z.has); // 4, [6, 3, 4], {has: false}
