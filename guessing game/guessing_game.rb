guess_count_limit = 7
guess_count = 0
guess = nil
number = rand(100)

puts "Welcome to the game, try to guess the secret number between 1 and 100.  You have #{guess_count_limit} guesses."

while (guess_count != guess_count_limit) do
    guess = gets.chomp.to_i
    if guess.zero?
        puts "Invalid input, try again!"
        next
    end
    guess_count += 1
    if guess == number
        puts "You guessed the number in #{guess_count} #{guess_count == 1 ? 'try' : 'tries'}, congratulations!"
        break
    elsif guess_count == 7
        puts "Too bad, you didn't guess the secret number!  It was #{number}."
    else
        remaining = guess_count_limit - guess_count
        puts "That's not it, keep trying!  You have #{remaining} #{remaining == 1 ? 'guess' : 'guesses'} left."
        puts "Here's a hint, your guess was #{guess > number ? 'higher' : 'lower'} than the secret number."
    end
end

exit 0
