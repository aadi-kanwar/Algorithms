import math

def minmax(depth, node_index, is_max, scores, height):
    # Base case: leaf node is reached
    if depth == height:
        return scores[node_index]

    if is_max:
        return max(minmax(depth + 1, node_index * 2, False, scores, height),
                   minmax(depth + 1, node_index * 2 + 1, False, scores, height))
    else:
        return min(minmax(depth + 1, node_index * 2, True, scores, height),
                   minmax(depth + 1, node_index * 2 + 1, True, scores, height))

# Example usage:
scores = [3, 5, 2, 9, 12, 5, 23, 23]
height = math.log2(len(scores))

optimal_value = minmax(0, 0, True, scores, height)
print("The optimal value is:", optimal_value)