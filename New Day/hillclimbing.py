import random


def f(x):
    return -x**2 + 4*x + 10


def hill_climbing(start, step, lower_bound, upper_bound, max_iterations):
    current = start
    current_value = f(current)
    
    for _ in range(max_iterations):
        
        neighbor_right = current + step
        neighbor_left = current - step

        
        if neighbor_right > upper_bound:
            neighbor_right = upper_bound
        if neighbor_left < lower_bound:
            neighbor_left = lower_bound

        value_right = f(neighbor_right)
        value_left = f(neighbor_left)

        
        if value_right > current_value and value_right > value_left:
            current = neighbor_right
            current_value = value_right
        elif value_left > current_value and value_left > value_right:
            current = neighbor_left
            current_value = value_left
        else:
         
            break
    
    return current


if __name__ == "__main__":
    
    start = random.uniform(0, 5)  
    step = 0.01 
    lower_bound = 0.0
    upper_bound = 5.0
    max_iterations = 1000

   
    result = hill_climbing(start, step, lower_bound, upper_bound, max_iterations)
    max_value = f(result)

    
print(f"Maximum found at x = {result:.4f}")
print(f"Maximum value is f(x) = {max_value:.4f}")
