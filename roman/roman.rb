VALUES = [
  ["M", 1000], 
  ["D", 500], 
  ["C", 100], 
  ["L", 50], 
  ["X", 10],
  ["IX", 9],
  ["V", 5],
  ["IV", 4]
  ["I", 1], 
]

def romanize n
  roman = ""

  VALUES.each do |pair|
    letter = pair[0]
    value = pair[1]
    roman += letter*(n / value)
    n = n % value
  end
  return roman
end
