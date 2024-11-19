def print_puzzle(puzzle):
    for row in puzzle:
        print(" ".join(map(str, row)))
    print()

def move_blank(puzzle, direction):
    blank_row, blank_col = next((i, j) for i, row in enumerate(puzzle) for j, value in enumerate(row) if value == 0)
    
    if direction == 'u' and blank_row > 0:
        puzzle[blank_row][blank_col], puzzle[blank_row - 1][blank_col] = puzzle[blank_row - 1][blank_col], puzzle[blank_row][blank_col]
    elif direction == 'd' and blank_row < 2:
        puzzle[blank_row][blank_col], puzzle[blank_row + 1][blank_col] = puzzle[blank_row + 1][blank_col], puzzle[blank_row][blank_col]
    elif direction == 'l' and blank_col > 0:
        puzzle[blank_row][blank_col], puzzle[blank_row][blank_col - 1] = puzzle[blank_row][blank_col - 1], puzzle[blank_row][blank_col]
    elif direction == 'r' and blank_col < 2:
        puzzle[blank_row][blank_col], puzzle[blank_row][blank_col + 1] = puzzle[blank_row][blank_col + 1], puzzle[blank_row][blank_col]

def solve_puzzle(start_puzzle, moves):
    puzzle = [row[:] for row in start_puzzle]
    
    print("Initial Puzzle:")
    print_puzzle(puzzle)
    
    move_index = 0
    while move_index < len(moves):
        move = moves[move_index]
        move_blank(puzzle, move)
        print("Move {move_index + 1} ({move}):")
        print_puzzle(puzzle)
        move_index += 1

if __name__ == "__main__":
    start_puzzle = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 0, 8]
    ]
    moves = ['u', 'l', 'd', 'r']
    solve_puzzle(start_puzzle, moves)
