def display_board(tc):
	print('\n'*10)
	print(f"\t{tc[7]} | {tc[8]} | {tc[9]}")
	print("\t----------")
	print(f"\t{tc[4]} | {tc[5]} | {tc[6]}")
	print("\t----------")
	print(f"\t{tc[1]} | {tc[2]} | {tc[3]}")
	print('\n'*3)
	
def take_input():
	mark=''
	while  mark!='X' and mark!='O':
		mark=input('Player1,Enter your mark(X/O): ')

	Player1=mark
	if Player1=='X':
		Player2='O'
	else:
		Player2='X'
	return (Player1,Player2)

def enter_mark(li,sub,play):
		
	if play=='X':
		li[sub]='X'
	else:
		li[sub]='O'

	if play=='X':
		li[sub]='X'
	else:
		li[sub]='O'
	return (li)

def win_check(board,mark):
	  return ((board[7] == mark and board[8] == mark and board[9] == mark) or   # across the top
    (board[4] == mark and board[5] == mark and board[6] == mark) or    # across the middle
    (board[1] == mark and board[2] == mark and board[3] == mark) or # across the bottom
    (board[7] == mark and board[4] == mark and board[1] == mark) or # down the middle
    (board[8] == mark and board[5] == mark and board[2] == mark) or # down the middle
    (board[9] == mark and board[6] == mark and board[3] == mark) or # down the right side
    (board[7] == mark and board[5] == mark and board[3] == mark) or # diagonal
    (board[9] == mark and board[5] == mark and board[1] == mark)) # diagonal


temp=['#',' ',' ',' ',' ',' ',' ',' ',' ',' ']
index=[]
win=draw=0
x=1
print("Welcome To Tic Tac Toe Game\n")
player1,player2=take_input()
print(f"Player1 is:{player1} \t Player2 is:{player2}")
while win==0 and draw==0:

	display_board(temp)
	
	if x%2!=0:
		pos=int(input(f"Enter your position Player1({player1}): "))
		while pos in index:
			pos=int(input("Enter correct position: "))
		index.append(pos)
		temp=enter_mark(temp,pos,player1)
	else:
		pos=int(input(f"Enter your position Player2({player2}): "))
		while pos in index:
			pos=int(input("Enter correct position: "))
		index.append(pos)
		temp=enter_mark(temp,pos,player2)
	if win_check(temp,player1):
		display_board(temp)
		print("Congratulations!! Player1 Won")
		win=1
	elif win_check(temp,player2):
		display_board(temp)
		print("Congratulations!! Player2 Won")
		win=1
	elif ' ' not in temp:
		display_board(temp)
		print("Match Drawn!!")
		draw=1
	else:
		pass
	x=x+1



	
		
	






