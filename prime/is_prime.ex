defmodule IsPrime do
  def is_prime(x) do
    if x < 2 do
      false
    else
      (2..x |> Enum.filter(fn a -> rem(x, a) == 0 end) |> length()) == 1
    end
  end
end
