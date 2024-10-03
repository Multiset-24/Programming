->first construct a graph which can contain the pair in a set i.e i->(node ,weight ) for all i belonging from 0 to v
->now take input of the src and des from the user

->DS used -> priority_queue,pair,vectors,unordered_set

->Algorithm

1.initiate the following variable->key vector with initail value of INT_MAX(contains the distance of each node from the sources   node)
                                 ->via vector(contains the path basically)
                                 ->visited vector or unordered_set (contains the node which are visited)
                                 ->result vector(contains the miinimnum distance of every other node from the sources)
                                 ->priority_queue using min heap of pair (this basically contains the node and distance from the current node)
2.Distance of the src node from itself is 0 and vis[0]=0 

3.Push the src node into the queue and run the queue until it becomes empty again.

4.store the front element of queue and pop it from the queue and if the node is already visited continue the while loop

5.iterate through every neighbour of the curr element in the graph

6.Relaxation step if(node is not visited and key[neighbour]<key[curr node]+neighbour's distance from the curr) do the relaxation step i.e {
    via[neighbour]=curr node
    key[neighbour]=key[curr]+nieghbour's distance from the curr node 
    queue.push({neighbour ,key[curr]+ (nieghbour's distance from the curr node) });
}