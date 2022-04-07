# Shortest-path problem #
Shortest-path problem is when we given a weighted-directed path G = (V, E), and we wish to find a set of vertices V = (v0, v1, ... vk). And wish the weight sum of this path consist of lowest weight among all possibility.

We define the shortest-path weight s(u,v) from u to v definded by

s(u,v) = { min(w(p): u->v)   if there exist a path from u and v
         { infinity          otherwise

This also can be viewed as a single-starting point problem.


## Variation ##

> Single-destination shortest path problem : Find a shortest path to a given destination from each vertex v.
> Single-pair shortest path problem : Find a shortest path from u to v. 
> All-pair shortest-paths problems: Find a shortest path from u to v. 

## Optimal substrcuture of a shortest path ##
*Lemma 24.1 (Subpaths of shortest paths are shortest path)*
Given a weighted, directed graph G = (V, E) with weigh function w : E -> R, let p = <v0, v1,...,vk> be the shortest path from vertex v_0 to vertex v_k. Then any substructure of shortest path is also the shortest path.

Proof. Suppose there exist another shortest path from v_a to v_b denote p', then simply replace p = <v0,v1...va ... vb ... vk> with <v0,v1...p' ... vk>. Which will be the shortest path. Thus contradiction. The theorem is correct. 

## Negative-weight edges case ##
The graph of MST is well defined at negative-weight case, however path isn't. Suppose there exist negative weigh cycle in graph, then the minimum weight path is defined as -infinity (or could be undefined for some algorithm precondition).

Some shortest-paths algorithms, such as Dijkstra's algorithm assume all weight are non-negative. 
Bellman-Ford algorithm, will allow negative weight and produce correct answer as long as no-negative weight cycle. 


## Cycle ##
The shortest-path can not include any cycle. If the total weight of cycle is negative, then as seen above, it's defined as -infinity(undefined). If the total weight of cycle is positive, then as definition of cycle, doing a cycle means doing nothing. 

If the cycle have total weight of 0. We can remove it as the total weight is still the same. And the final result would be cycle-less. By this discusiion, we can assume at a graph G = (V, E). The shortest path will consist of |V| - 1 edges. 

## Representing shortest oaths ##
We often wish to also compute the shortest-path when computing shortest-path weight. The genral approch is to store a graph, where each vertice store it's predecessir. Then, by trace back and print it in reversed order, we get the shortest-path. 

However, this graph won't be correct at midest of execution for thoes who have predecessor.  

## Relaxation ##
The algorithm in this chapter use the technique of relaxation. In the step of finding shortest-paths, we will store the upper-bound of the path. And once a better path been found, we modify this upper-bound and also the predecessor. This step takes O(1). 

Relaxation means relaxation from the previous constraint. In this case, relaxed from previous predecessor. 

The algorithm present in this chapter differ by how many edges they relax. Dijkstra's algorithm relax one edge per time, Bellman-ford algorithm relax each edge |V| -1 times. 

## Properties of shortest paths and relaxation ##
1. Triangle inequality: For any edge (u,v) we have s(s, v) <= s(s, u) + s(u, v). 


#### The following 5 properties only work for single-source shortest path and algorithm only uses Relaxation step ####
2. Upper-bound property: We always have v.d >= s(s,v). 
3. No-path property : If there is no path from s to u, then u.d = infinity.
4. Convergence property : If s-> u ->v is the shortest path, and if u.d = s(s,u) at any time prior to relaxing edge (u,v), then v.d = s(s,v) at all times afterward.
5. Path-relaxation property: Speak for itself. By relax a sequence of edges from a shortest path, end edges will have smallest weight value. 
6. Precessor-subgraph property: Once v.d = s(s,d), the predessor subgraph is a shortest-paths.










