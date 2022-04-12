## Dijkstra's algorithm ##
Dijkstra's algorithm solves the single-source shortest-paths problem on a weightest directed graph G = (V, E) for the case in which all edge weights are non-negative(It won't check negative loop). 

Dijkstra's algorithm maintain an array track shortest distance of each node, from a source, and an array maintain the predecessor of current node. At the end of execution, it will forms a tree. It repeatly select the minimum-shortest path vertex u, relaxes all edges leaving u and select next edge. 

Dijkstra(G, w, s) {
    INIALIZE-SINGLE-SOURCE(G,s);
    S = empty
    Q = G.V
    while Q is !empty
        u = extract-min(Q)
        S = S UNION {u}
        for each vertex v belong G.adj[u]
            RELAX(u, v, w)
}