defmodule Palindrome do
  @moduledoc """
  Checks whether input string is a palindrome.
  """
  def is_palindrome?(""), do: nil
  def is_palindrome?(str) do
    check_palindrome(str, String.reverse(str))
  end

  defp check_palindrome(str, str), do: true
  defp check_palindrome(_str, _str1), do: false
end
