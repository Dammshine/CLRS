
# Minimum Spanning tree #

Minimum spanning tree is target to a connected, undirected, weighted graph. It wishes to find a acylic graph(or just a graph since cycle garunteed to have more edge) that have total weight of edges minimise.

# The generic method of finding MST #
At first, any weighted connected graph have MST. Think as a collection of connected graph that do not have cycle, always pick the lowest weight. Secondly, if the weight of edge in graph is unique, then there exist an unique MST. 

The prim and and Kruskal both uses greedy approaches to this problem. 
The greedy approaches to this problem can have qeudocode form

> Geneic-MST(G, w)
>   A is empty
>
>   while A does not form a spanning tree
>
>       find an edge (u,v) that is safe for A
>
>       A += edge(u,v)
>
>   return A
>

Now, the problem is consider how to determine if an edge is **safe** for collection A, such that A is able to form MST with this edge. It must exist, since MST must exist and connected, A is the collection of vertice. Within while loop, there must exist at least one of such edge until A is connected. For this purpose we define

> A **cut** is an operation that partition vertex V belong to G, into (S, V - S). Then we define, if an edge **corsses** the cut if it connect two component. We define such edge **respect** A, if A do not have edge corsses the cut. An edge is called **light edge** if it is the minimum weight among all crosses.

### Theorem 23.1 ###
>Let graph G = (V, E) be a connected, undirected graph with eright function w defined on E. Let A be a subset of E that include some part of minimum spanning tree for G. Let any cut (S, V - S) respect A, and let (u,v) be a light edge acrossing (S, S - V). Then edge(u,v) is safe for A.

Let T be an arbitary MST that A belongs to. Then choice an arbitary cut (S, S-V) that respect A. Consider the following cases
1. If light edge (u, v) of cut, also belong to T. Then we are done.
2. If light edge (u, v) do not belong to T. Since any MST belongs to T is connected, then consider have the same cut (S, S - V). Since T don't have edge (u,v), it must only have another edge (x,y). If (x,y) and (u,v) both consider as safe edge, then we are done as the genertic algorithm did not specify the safe edge need to pick, and by picking one of the edge, the other safe edges will nullify. By cutting that edge, T partition into two unconnected part. By assumption, since (u,v) < (x,y), the tree T - (x,y) + (u,v) < T. Thus T is no longer consider as a MST. Hence contradiction. 

By theorem 23.1, we can prove the correctness of genric algorithhm. At any point of algorithm, A is always acylic, and G(V, A) will be a forest else the graph is connected, the algorithm should end. The cut of graph always exist if G(V, A) is not connected. Then, by always picking the light-edge of A for the cut, it is always safe that A can form MST. At the end of algorithm, A should form a MST. 


# Exercises #

### 23.1-1 ###
Suppose (u,v) be a minimum-weight edge in G. Then, let A be empty, and form a cut cross (u,v) and arbitary other edges. By Theorem 23.1 discussed before, (u,v) is the safe edge for A. And by proceed this algorithm, A forms a MST and (u,v) belong to A. Thus (u,v) belongs to some MST of G.


### 23.1-2 ###
Consider graph, that cut the graph into three connected part. Then, suppose A have edge (u,u'), (v, v'). Both edges are safe edge. At the paricular cut, one of which will be light edge, however since graph still not connected, the edge left would be another light edge.



