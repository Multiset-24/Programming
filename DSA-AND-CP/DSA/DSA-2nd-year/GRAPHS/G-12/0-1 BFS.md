This algorithm is used for finding the shortest path in a graph where edge weights are either 0 or 1 or having only two values like one high and one low.

Initialize a deque (double-ended queue) and a distance array. The distance array should be filled with infinity (Infinity in JavaScript, INT_MAX in C++), except for the source node, which should have a distance of 0.

Add the source node to the deque.

While the deque is not empty, repeat the following steps:

a. Pop the node from the front of the deque. Let's call this node u.

b. For each neighbor v of u, check if you can relax the edge (u, v) (i.e., if distance[u] + weight(u, v) < distance[v]).

c. If you can relax the edge and the weight of the edge (u, v) is 0, push v to the front of the deque, and update distance[v] = distance[u].

d. If you can relax the edge and the weight of the edge (u, v) is 1, push v to the back of the deque, and update distance[v] = distance[u] + 1.

After the while loop ends, the shortest distances from the source node to all other nodes will be stored in the distance array.