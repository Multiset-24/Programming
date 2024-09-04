import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import copy
import math
# Load the housing dataset
columns = [
    "CRIM",  # Per capita crime rate by town
    "ZN",    # Proportion of residential land zoned for lots over 25,000 sq. ft.
    "INDUS", # Proportion of non-retail business acres per town
    "CHAS",  # Charles River dummy variable (= 1 if tract bounds river; 0 otherwise)
    "NOX",   # Nitric oxides concentration (parts per 10 million)
    "RM",    # Average number of rooms per dwelling
    "AGE",   # Proportion of owner-occupied units built prior to 1940
    "DIS",   # Weighted distances to five Boston employment centers
    "RAD",   # Index of accessibility to radial highways
    "TAX",   # Full-value property tax rate per $10,000
    "PTRATIO", # Pupil-teacher ratio by town
    "B",     # 1000(Bk - 0.63)^2 where Bk is the proportion of Black people by town
    "LSTAT", # % lower status of the population
    "MEDV"   # Median value of owner-occupied homes in $1000s (target)
]

# Reading the data
housing_data = pd.read_csv('housing.csv', sep='\s+', names=columns)
print(housing_data)
# Normalize features using Min-Max scaling to range [0, 1]
def min_max_normalize_features(X):
    min_val = np.min(X, axis=0)
    max_val = np.max(X, axis=0)
    return (X - min_val) / (max_val - min_val)
# Extract features and normalize them
X = housing_data.iloc[:, :-1].values  # Features
X = min_max_normalize_features(X)
y = housing_data.iloc[:, -1].values   # Target
# Define the cost function
def compute_cost(X, y, w, b): 
    m = X.shape[0]
    cost = 0.0
    for i in range(m):                                
        f_wb_i = np.dot(X[i], w) + b
        cost += (f_wb_i - y[i]) ** 2
    cost /= (2 * m)                     
    return cost

# Define the gradient function
def compute_gradient(X, y, w, b): 
    m, n = X.shape
    dj_dw = np.zeros((n,))
    dj_db = 0.

    for i in range(m):                             
        err = (np.dot(X[i], w) + b) - y[i]
        for j in range(n):                         
            dj_dw[j] += err * X[i, j]    
        dj_db += err                        
    dj_dw /= m                                
    dj_db /= m                                
        
    return dj_db, dj_dw
# Define the gradient descent function
def gradient_descent(X, y, w_in, b_in, cost_function, gradient_function, alpha, num_iters): 
    J_history = []
    w = copy.deepcopy(w_in)  # avoid modifying global w within function
    b = b_in
    
    for i in range(num_iters):
        dj_db, dj_dw = gradient_function(X, y, w, b)

        w -= alpha * dj_dw
        b -= alpha * dj_db
      
        if i < 100000:      # prevent resource exhaustion 
            J_history.append(cost_function(X, y, w, b))

        if i % math.ceil(num_iters / 10) == 0:
            print(f"Iteration {i:4d}: Cost {J_history[-1]:8.2f}")
        
    return w, b, J_history

# Initialize parameters
w_init = np.zeros(X.shape[1])  # Initialize weights to zeros
b_init = 0.0                   # Initialize bias to zero
alpha = 0.001                  # Learning rate (smaller to prevent overflow)
num_iters = 1000               # Number of iterations
# Run gradient descent
w_final, b_final, J_history = gradient_descent(X, y, w_init, b_init, compute_cost, compute_gradient, alpha, num_iters)

# Output the final parameters
print("Final weights:", w_final)
print("Final bias:", b_final)