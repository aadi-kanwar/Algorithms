import heapq

class TreeNode:
    def __init__(self, label, heuristic, leftCost=0, rightCost=0):
        self.label = label
        self.leftCost = leftCost
        self.rightCost = rightCost
        self.heuristic = heuristic
        self.left = None
        self.right = None

def a_star_search(root, goal):
    # Priority queue for the A* algorithm (min-heap)
    pq = []
    heapq.heappush(pq, (root.heuristic, 0, root.label, [root.label], root))

    min_cost = float('inf')
    best_path = []

    while pq:
        fCost, gCost, current_label, path, node = heapq.heappop(pq)

        # Print the current node and its cost
        print(f"Visited node: {node.label} with cost: {gCost}")

        if node.label == goal:
            if gCost < min_cost:
                min_cost = gCost
                best_path = path
            print(f"Goal found: {node.label} with cost: {gCost}")
            continue

        if node.left:
            newPath = path + [node.left.label]
            newGCost = gCost + node.leftCost
            newFCost = newGCost + node.left.heuristic
            heapq.heappush(pq, (newFCost, newGCost, node.left.label, newPath, node.left))

        if node.right:
            newPath = path + [node.right.label]
            newGCost = gCost + node.rightCost
            newFCost = newGCost + node.right.heuristic
            heapq.heappush(pq, (newFCost, newGCost, node.right.label, newPath, node.right))

    return min_cost, best_path

def create_node(label, heuristic, leftCost=0, rightCost=0):
    return TreeNode(label, heuristic, leftCost, rightCost)

# Example usage
root = create_node('S', 7)
root.left = create_node('A', 6, 4)
root.right = create_node('B', 4, 2)

root.left.left = create_node('C', 5, 5)
root.left.right = create_node('D', 7, 10)

root.right.left = create_node('E', 3, 3)
root.right.right = create_node('F', 4, 1)

root.left.left.left = create_node('G', 0, 6)
root.left.left.right = create_node('H', 1, 2)

goal = 'G'
min_cost, best_path = a_star_search(root, goal)

print(f"Minimum cost path to {goal}: {' '.join(best_path)} with cost {min_cost}")