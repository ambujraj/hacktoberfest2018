to_convert = [
  'MMXVIII'
  'MM'
  'XVII'
]

roman_to_int = (str = 'MMXVIII') ->
  num = dictionary[str[0]]

  for i in [1...str.length]
    now = dictionary[str[i]]
    prev = dictionary[str[i - 1]]
    throw new Error "Unexpected token #{str[if now? then i - 1 else i]} at position #{i}" unless now? and prev?
    num += if now <= prev then now else (-2 * pre) + curr

  return num;

dictionary =
  I: 1
  V: 5
  X: 10
  L: 50
  C: 100
  D: 500
  M: 1000

do main = ->
  to_convert
    .map roman_to_int
    .map (int) -> console.log int
