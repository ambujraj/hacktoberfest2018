import random
 
# A randomly generated score
your_score = 100 * random.randint(1, 1000)

# File that will be used to store the score
filename = "highscore.txt"

print("Your score was", your_score)

# It is beautiful how everyone starts as a winner
your_rank = 1
all_scores = []

# In case there are no other scores saved
try:
    with open(filename, 'r') as file:
        current_rank = 1
        finished = False
        for line in file.readlines():
            another_score = int(line)
            
            # If this is true, you are better than them!
            if (your_score > another_score and not finished):
                all_scores.append(your_score)
                your_rank = current_rank
                finished = True

            all_scores.append(another_score)
            current_rank += 1

        # After it is done checking the scores, announce the result
        print("And it was ranked #" + str(your_rank), "out of", current_rank)
            
except IOError:
    all_scores.append(your_score)
    print("It was the best, but the only one.")
    print("Glory can bring loneliness.")

# Then save the updated list
with open(filename, 'w') as file:
    for score in all_scores:
        file.write(str(score) + "\n")
    
    
     
