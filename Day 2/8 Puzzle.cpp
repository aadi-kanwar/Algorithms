//31.07.2024
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

// Structure to represent the puzzle state
struct PuzzleState {
    int board[3][3];
    int zeroRow, zeroCol;
    string path;
};

// Function to check if the current state is the goal state
bool isGoalState(const PuzzleState& state) {
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state.board[i][j] != count % 9) {
                return false;
            }
            count++;
        }
    }
    return true;
}

// Function to swap two elements in the puzzle board
void swapElements(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to generate the next possible states from the current state
vector<PuzzleState> generateNextStates(const PuzzleState& currentState) {
    vector<PuzzleState> nextStates;
    int row = currentState.zeroRow;
    int col = currentState.zeroCol;

    // Move the empty space to the left
    if (col > 0) {
        PuzzleState nextState = currentState;
        swapElements(nextState.board[row][col], nextState.board[row][col - 1]);
        nextState.zeroCol = col - 1;
        nextState.path += "L";
        nextStates.push_back(nextState);
    }

    // Move the empty space to the right
    if (col < 2) {
        PuzzleState nextState = currentState;
        swapElements(nextState.board[row][col], nextState.board[row][col + 1]);
        nextState.zeroCol = col + 1;
        nextState.path += "R";
        nextStates.push_back(nextState);
    }

    // Move the empty space up
    if (row > 0) {
        PuzzleState nextState = currentState;
        swapElements(nextState.board[row][col], nextState.board[row - 1][col]);
        nextState.zeroRow = row - 1;
        nextState.path += "U";
        nextStates.push_back(nextState);
    }

    // Move the empty space down
    if (row < 2) {
        PuzzleState nextState = currentState;
        swapElements(nextState.board[row][col], nextState.board[row + 1][col]);
        nextState.zeroRow = row + 1;
        nextState.path += "D";
        nextStates.push_back(nextState);
    }

    return nextStates;
}

// Function to solve the 8-Puzzle using BFS
string solvePuzzle(const PuzzleState& initialState) {
    queue<PuzzleState> q;
    unordered_set<string> visited;

    q.push(initialState);
    visited.insert(initialState.path);

    while (!q.empty()) {
        PuzzleState currentState = q.front();
        q.pop();

        if (isGoalState(currentState)) {
            return currentState.path;
        }

        vector<PuzzleState> nextStates = generateNextStates(currentState);
        for (const PuzzleState& nextState : nextStates) {
            if (visited.find(nextState.path) == visited.end()) {
                q.push(nextState);
                visited.insert(nextState.path);
            }
        }
    }

    return "No solution found";
}

int main() {
    PuzzleState initialState;
    cout << "Enter the initial state of the puzzle (0 for empty space):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> initialState.board[i][j];
            if (initialState.board[i][j] == 0) {
                initialState.zeroRow = i;
                initialState.zeroCol = j;
            }
        }
    }

    string solution = solvePuzzle(initialState);
    cout << "Solution: " << solution << endl;

    return 0;
}