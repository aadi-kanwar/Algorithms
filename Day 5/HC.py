import random

def hill_climbing(problem):
    current_state = problem.initial_state()
    
    while True:
        neighbors = problem.generate_neighbors(current_state)
        best_neighbor = max(neighbors, key=lambda state: problem.evaluate(state))
        
        if problem.evaluate(best_neighbor) <= problem.evaluate(current_state):
            return current_state
        
        current_state = best_neighbor

# Example usage
class Problem:
    def initial_state(self):
        return random.randint(1, 100)
    
    def generate_neighbors(self, state):
        return [state + 1, state - 1]
    
    def evaluate(self, state):
        return -abs(state - 50)  # Minimize the distance from 50

problem = Problem()
solution = hill_climbing(problem)
print("Solution:", solution)