const romanNumerals = {
  'M': 1000,
  'DM': 900,
  'D': 500,
  'CD': 400,
  'C': 100,
  'LC': 90,
  'L': 50,
  'XL': 40,
  'X': 10,
  'IX': 9,
  'V': 5,
  'IV': 4,
  'I': 1,
}

function romanNumeralConverter (num) {
  let result = '';
  num = Math.floor(num);
  while (num >= 1) {
    for (key in romanNumerals) {
      if (romanNumerals[key] <= num) {
        result += key;
        num = num - romanNumerals[key];
      }
    }
  }
  return result;
}
