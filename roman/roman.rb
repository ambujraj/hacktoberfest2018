

  # Constant variable with 'unique' roman numerals, plus some special cases (e.g. "IV, IX, XC, CM...")
  ROMANS = {  1000 => "M",
              900 => "CM",
              500 => "D",
              400 => "CD",
              100 => "C",
              90 => "XC",
              50 => "L",
              40 => "XL",
              10 => "X",
              9 => "IX",
              5 => "V",
              4 => "IV",
              1 => "I" }

  def to_roman
    # If the number's already on the hash return the value, otherwise decompose it into numbers that are in it.
    ROMANS[self] || break_composite_roman(self)
  end

  private

  def break_composite_roman(num)
    # We start with an empty string and divide by the largest roman numeral possible in the hash
    # Then we keep breaking down the remainder until it is 0
    ROMANS.reduce("") do | memo, (arabic, roman) |
      quotient, num = num.divmod(arabic)
      # We multiply the quotient by the key's value (e.g. "I" * 3 = "III") and push it to the end of the string
      memo << roman * quotient
    end
  end

end