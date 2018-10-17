function isPerfectSquare(num) {
  if (num <= 0) return false;
  return Math.ceil(Math.sqrt(num)) == Math.floor(Math.sqrt(num));
}
