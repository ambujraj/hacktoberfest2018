import random
import time
import os
import sys
from termcolor import colored


def init(height, width):
    '''Initializes a dead board with given height and width'''
    return [[0 for _ in range(width)] for _ in range(height)]


def resurrect_random(board):
    '''Randomly resurrects tiles on given board'''
    for row in board:
        for i in range(len(row)):
            if random.random() > 0.5:
                row[i] = 1

    return board


def pretty_print(board):
    '''Renders a given board to the shell'''
    string_list = []

    for row in board:
        for number in row:
            string_list.append('|')
            if number == 0:
                string_list.append(colored('.', 'red'))
            else:
                string_list.append(colored(u'\u2588', 'green'))
        string_list.append('|\n')

    print(''.join(string_list))


def count_neighbours(board, row, col):
    '''Counts amount of neighbors in the Moore Neighborhood'''
    count = 0
    current_tile = board[row][col]
    # loop around neighbours of given row/col combination
    for x in range((row - 1), (row + 1) + 1):
        # skip a neighbour if they're out of bounds
        if x < 0 or x >= len(board):
            continue
        for y in range((col - 1), (col + 1) + 1):
            # skip a neighbour if they're out of bounds
            if y < 0 or y >= len(board[0]):
                continue
            # skip current tile
            if x == row and y == col:
                continue
            if board[x][y] == 1:
                count += 1

    return count


def iterate(board):
    '''Computes next iteration of given board based on survival rules'''
    new_board = init(len(board), len(board[0]))
    for i in range(len(board)):
        for j in range(len(board[i])):
            count = count_neighbours(board, i, j)
            # rules for survival/death
            if board[i][j] == 1:
                if count < 2:
                    new_board[i][j] = 0
                elif count > 3:
                    new_board[i][j] = 0
                else:
                    new_board[i][j] = 1
            else:
                if count == 3:
                    new_board[i][j] = 1

    return new_board


def load_initial_state(file):
    '''Loads a .txt file into the program to be used as starting board'''
    file = 'designed/' + file
    initial_state = []
    with open(file, 'r') as f:
        for line in f.readlines():
            row = []
            for char in line:
                if not char == '\n':
                    row.append(int(char))
            initial_state.append(row)

    return initial_state


def play_game_of_life(initial_state):
    '''Runs the game of life forever'''
    board = initial_state
    pretty_print(board)
    print()

    while True:
        board = iterate(board)
        pretty_print(board)
        time.sleep(0.1)


def main():

    i = 0
    for file in os.listdir('designed'):
        print("{0}: {1}".format(i + 1, file))
        i += 1
    chosen_file = input("What file do you want to load?" +
                        "(if you want a randomly generated soup type x): ")
    if chosen_file == "x" or chosen_file == "X":
        height = input("What height should the soup be?: ")
        width = input("What width should the soup have?: ")
        board = init(int(height), int(width))
        board = resurrect_random(board)
        start = input("Do you want to start the game? (type yes or no): ")
        if start == "yes" or "y":
            play_game_of_life(board)
        else:
            sys.exit(0)
    else:
        chosen_file = int(chosen_file)
        file = os.listdir('designed')[chosen_file - 1]
        board = load_initial_state(file)
        start = str(input("Do you want to start the game? (type yes or no): "))
    if start == "yes" or "y":
        play_game_of_life(board)
    else:
        sys.exit(0)


if __name__ == "__main__":
    main()
