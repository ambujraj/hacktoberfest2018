function reverse_number(n){
  const a = n.toString().split('').reverse().join('');
  return parseInt(a) * Math.sign(n);
}


