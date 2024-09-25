// Backtracking Search Algorithm for Graph Coloring Problem
// The problem is to assign colors to each vertex of a graph such that no two adjacent vertices have the same color
// 25.09.2024

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

const int var = 4;
const int col = 3;
const string COLORS[col] = {"Red", "Green", "Blue"};

bool isSafe(int v, int color[], int graph[var][var], int c) {
    for (int i = 0; i < var; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[var][var], int m, int color[], int v) {
    if (v == var) {
        return true;
    }

    for (int c = 0; c < m; c++) {
        if (isSafe(v, color, graph, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            color[v] = -1;
        }
    }
    return false;
}

bool graphColoring(int graph[var][var], int m) {
    int color[var];
    for (int i = 0; i < var; i++) {
        color[i] = -1;
    }

    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    cout << "Solution exists: Following are the assigned colors" << endl;
    cout << "Variable\tColor" << endl;
    for (int i = 0; i < var; i++) {
        cout << char('A' + i) << "\t\t" << COLORS[color[i]] << endl;
    }
    return true;
}

int main() {
    int graph[var][var] = {0};

    // Define the connections
    graph[0][1] = 1; // A to B
    graph[0][2] = 1; // A to C
    graph[0][3] = 1; // A to D
    graph[1][3] = 1; // B to D
    graph[2][3] = 1; // C to D

    // Since the graph is undirected, we need to mirror the connections
    graph[1][0] = 1;
    graph[2][0] = 1;
    graph[3][0] = 1;
    graph[3][1] = 1;
    graph[3][2] = 1;

    int m = col; // Number of colors
    graphColoring(graph, m);

    return 0;
}