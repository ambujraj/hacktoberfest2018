const isPrime = num => {
  for (let i = 2; i < num; i++) 
    if ( num % i === 0 ) {
      return false;
    }
  return true;
}

const isPrimeList = num => {
  var arr = [2];
    for ( var i = 3; i < num; i+=2 ) {
      if ( isPrime(i) ) {
        arr.push(i);
      }
  }
    return arr
}

isPrimeList(50);
