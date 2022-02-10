import numpy as np
from collections import Counter
import random
#random.seed(1)

# create board
def create_board(n):
    board = np.zeros((n,n))
    return board


# place on board
# place 1
def place_board(board, player, pos):
    board[pos[0]][pos[1]] = player
    return board


# find blank space
def find_blank(board):
    return np.where(board==0)


# place random
def place_board_random(board, player):
    blank = find_blank(board)
    ind = random.choice(range(len(blank[0])))
    board[blank[0][ind], blank[1][ind]] = player
    return board

# determine winner (horz, vert, diag)
def horizontal_win(board, players):
    winner = 0
    for row in board:
        for player in players:
            if all(row == player):
                winner = player
    return winner


def vertical_win(board, players):
    winner = 0
    for col in board.transpose():
        for player in players:
            if all(col == player):
                winner = player
    return winner


def diagonal_win(board, players):
    winner = 0
    for player in players:
        if all(np.fliplr(board).diagonal() == player) or all(np.diagonal(board)==player):
            winner = player
    return winner


def find_winner(board, players):
    winner = 0
    status = [horizontal_win(board, players), vertical_win(board, players), diagonal_win(board, players)]
    if sum(status) != 0:
        new_stat = Counter(status)
        del new_stat[0]
        winner = new_stat.most_common(1)[0][0]
    if winner == 0 and np.sum(board == 0) == 0:
        winner = -1
    return winner


# play 1 game

def play_game(dimension, players):
    board = create_board(dimension)
    winner = 0
    while winner == 0:
        for player in players:
            place_board_random(board, player)
            winner = find_winner(board, players)
            if winner != 0:
                break
    return winner


# play multiple games

def play_games(times, dimensions, players):
    results = [play_game(dimensions, players) for i in range(times)]
    return results


game = play_games(1000,3,(1,2))
print(game.count(1))
print(game.count(2))
print(game.count(-1))



