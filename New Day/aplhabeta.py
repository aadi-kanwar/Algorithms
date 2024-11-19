import math

def alpha_beta_pruning(depth, node_index, is_max, scores, height, alpha, beta):
    # Base case: leaf node is reached
    if depth == height:
        return scores[node_index]

    if is_max:
        max_eval = -math.inf
        for i in range(2):
            eval = alpha_beta_pruning(depth + 1, node_index * 2 + i, False, scores, height, alpha, beta)
            max_eval = max(max_eval, eval)
            alpha = max(alpha, eval)
            if beta <= alpha:
                break  # Beta cut-off
        return max_eval
    else:
        min_eval = math.inf
        for i in range(2):
            eval = alpha_beta_pruning(depth + 1, node_index * 2 + i, True, scores, height, alpha, beta)
            min_eval = min(min_eval, eval)
            beta = min(beta, eval)
            if beta <= alpha:
                break  # Alpha cut-off
        return min_eval

# Example usage for Alpha-Beta Pruning:
scores = [1, 2, 3, 4, 5, 6, 7, 8]
height = math.log2(len(scores))
optimal_value_alpha_beta = alpha_beta_pruning(0, 0, True, scores, height, -math.inf, math.inf)
print("The optimal value using Alpha-Beta Pruning is:", optimal_value_alpha_beta)