## Kruskal's algorithm ##
Prior to Kruskal algorithm, a set A is a forest whose verteces are all thoes of given graph. With each step, it choice least weight edge (u,v) and suppose this edge connect two distinct tree C1, C2 in the graph, then this edge is qualified as a safe edge for C1, and by the previous theorem discussed, each step will develop the MST by a bit and eventually form one of MST in graph. 

Algorithm
    A = empty
    for each vertex v belong to G.V
        // Make each vertice as a set only contain one vertex
        Make-SET(v)
    sort the edges of G.E into non-decreasing order by weight w
    for each edge(u,v) belong G.E, taken in nondecreasing order by weight
        if FIND-SET(u) != FIND-SET（v） // Make sure that the edge connect two distinct tree, thus satisfy "safe edge"
            Add edge (u,v) to A
            UNION(u,v); // Merge two set
    // A set of edge can form a MST
    return A 


## Kruskal's algorithm analysis ##
