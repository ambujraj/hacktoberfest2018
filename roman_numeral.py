"""
Easy Mode, Restrict to max single M value.

Happy Hacktoberfest!
"""

def romanDecimal(s):
  convert_map = {'M': 1000, 'D': 500, 'C': 100, 'L': 50, 'X': 10, 'V': 5, 'I': 1}
  numbers = [convert_map[i] for i in s.upper()]
  return sum([i if i>=numbers[min(j+1, len(numbers)-1)] else -i for j,i in enumerate(numbers)])

