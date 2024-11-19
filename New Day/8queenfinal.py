import numpy as np

def insertQueen(board, i, j):
    if i < 0 or j >= len(board):
        print("Invalid Index")
    else:
        board[i, j] = 1

def removeQueen(board, i, j):
    board[i, j] = 0

def is_valid(board, row, col):
    if row in invalid_row or col in invalid_col or (row - col) in major_diagonal or (row + col) in minor_diagonal:
        return False
    return True

def solve_n_queens(board, row=0):
    if row == len(board):
        return True
    
    for col in range(len(board)):
        if is_valid(board, row, col):
            insertQueen(board, row, col)
            invalid_row.append(row)
            invalid_col.append(col)
            major_diagonal.add(row - col)
            minor_diagonal.add(row + col)
            
            if solve_n_queens(board, row + 1):
                return True
            
            removeQueen(board, row, col)
            invalid_row.remove(row)
            invalid_col.remove(col)
            major_diagonal.remove(row - col)
            minor_diagonal.remove(row + col)
    
    return False


n = 8
board = np.zeros((n, n), dtype=int)

invalid_row = []
invalid_col = []
major_diagonal = set()
minor_diagonal = set()

print("Initial Board State:")
print(board)

if solve_n_queens(board):
    print("Final Board State:")
    print(board)
    print("Problem solved")
else:
    print("No solution found.")
