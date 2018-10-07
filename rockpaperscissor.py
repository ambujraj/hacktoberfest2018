"""A different implementation of classic problem of rock, paper and scissor 
using lists helping to achieve the result with lesser conditions.
PS: the code is in python3"""

def check_play(play):
    if play not in (1,2,3):
        print("**Invalid**")
        play = check_play(input("Enter again:"))
    return play

#--------------------main-----------------------
play1 = int(input("Player1's play:\n1.Rock\n2.Scissor\n3.Paper\n"))
play1 = check_play(play1)
play2 = int(input("Player2's play-\n1.Rock\n2.Scissor\n3.Paper\n"))
play2 = check_play(play2)

if play1==play2 :
    print("Tie game.")
else:
    line=[0,0,0]
    line[play1-1] = "Player1"
    line[play2-1] = "Player2"
    if not line[1]:
        print(line[2],"wins!")
    else:
        if line[0]:
            print(line[0],"wins!")
        else:
            print(line[1],"wins!")
