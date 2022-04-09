

## The Bellman-Ford algorithm ##
The Bellman-Ford algorithm solves single-source shortest-paths problem, when the weight of edge could be negative. It return false if there is negative weighted cycle, and return true, minimum single-sourse paths if otherwise. 

# Bellman-Ford algorithm
Initilize-single-sourse(G, s) {
    For i = 0 to |G.V| - 1
        for each edge(u,v) belong G.E connect to vertice i
            RELAX(u,v,w)
    For each edge (u,v) belong to G.E
        if v.d > u.d + w(u,v)
            return false
    return true
}


