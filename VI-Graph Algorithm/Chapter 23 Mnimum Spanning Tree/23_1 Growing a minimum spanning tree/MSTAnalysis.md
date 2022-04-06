
# Minimum Spanning tree #

Minimum spanning tree is target to a connected, undirected, weighted graph. It wishes to find a acylic graph(or just a graph since cycle garunteed to have more edge) that have total weight of edges minimise.

# The generic method of finding MST #
At first, any weighted connected graph have MST. Think as a collection of connected graph that do not have cycle, always pick the lowest weight. Secondly, if the weight of edge in graph is unique, then there exist an unique MST. 

The prim and and Kruskal both uses greedy approaches to this problem. 
The greedy approaches to this problem can have qeudocode form

> Geneic-MST(G, w)
>   A is empty
>   while A does not form a spanning tree
>       find an edge (u,v) that is safe for A
>       A += edge(u,v)
>   return A
>

Now, the problem is consider how to determine if an edge is **safe** for collection A, such that A is able to form MST with this edge. It must exist, since MST must exist and connected, A is the collection of vertice. Within while loop, there must exist at least one of such edge until A is connected. For this purpose we define

> A **cut** is an operation that partition vertex V belong to G, into (S, V - S). Then we define, if an edge **corsses** the cut if it connect two component. We define such edge **respect** A, if A do not have edge corsses the cut. An edge is called **light edge** if it is the minimum weight among all crosses.

### Theorem 23.1 ###
>Let graph G = (V, E) be a connected, undirected graph with eright function w defined on E. Let A be a subset of E that include some part of minimum spanning tree for G. Let any cut (S, V - S) respect A, and let (u,v) be a light edge acrossing (S, S - V). Then edge(u,v) is safe for A.
