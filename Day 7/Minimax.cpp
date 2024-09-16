// MiniMax Algorithm for Game Theory
//11.09.2024

#include <iostream>
#include <climits>

using namespace std;

// Node structure for binary tree
struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to evaluate the leaf nodes (static evaluation function)
int evaluateNode(Node* node) {
    return node->value;
}

// Minimax function
int minimax(Node* node, int depth, bool maximizingPlayer) {
    // Base case: if depth is 0 or node is a terminal node (leaf node)
    if (depth == 0 || (node->left == nullptr && node->right == nullptr)) {
        return evaluateNode(node);
    }

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        // Traverse both left and right children for maximizer
        if (node->left) {
            int eval = minimax(node->left, depth - 1, false);
            maxEval = max(maxEval, eval);
        }
        if (node->right) {
            int eval = minimax(node->right, depth - 1, false);
            maxEval = max(maxEval, eval);
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        // Traverse both left and right children for minimizer
        if (node->left) {
            int eval = minimax(node->left, depth - 1, true);
            minEval = min(minEval, eval);
        }
        if (node->right) {
            int eval = minimax(node->right, depth - 1, true);
            minEval = min(minEval, eval);
        }
        return minEval;
    }
}

int calculateDepth(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftDepth = calculateDepth(node->left);
    int rightDepth = calculateDepth(node->right);

    return 1 + max(leftDepth, rightDepth);
}


int main() {
    // Creating a simple binary tree
    Node* root = new Node(0);
    root->left = new Node(0);
    root->right = new Node(0);
    root->left->left = new Node(0);
    root->left->right = new Node(0);
    root->right->left = new Node(0);
    root->right->right = new Node(0);
    root->left->left->left = new Node(20);
    root->left->left->right = new Node(21);
    root->left->right->left = new Node(2);
    root->left->right->right = new Node(3);
    root->right->left->left = new Node(15);
    root->right->left->right = new Node(17);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(8);
    /*
                          0                     // Root -> Maximizer
                      /      \
                    /          \
                  0              0              // Level 1 -> Minimizer
                /   \          /    \
              0      0        0      0          // Level 2 -> Maximizer
             / \    / \      / \    / \
            20  21 2   3    15 17  9   8
    */
    int depth = calculateDepth(root); // Define the depth you want to go
    bool maximizingPlayer = true; // Start with Maximizer
    cout<< "Depth of the binary Tree is: "<< depth << endl;
    
    int result = minimax(root, depth, maximizingPlayer);
    cout << "The optimal value is: " << result << endl;

    return 0;
}
