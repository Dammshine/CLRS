Situation:                  Algorithm to use            Time
unweighted (w = 1)           BFS                    O(V + E)
non-nagative edge weight     Dijkstra               O(V * lgv + E)
general                      Bellman-Ford           O(V * E)
Acyclic (DAG)                DP, toplogical sort
                            1 round of DFS

All-pairs shortest path
Given a G(V, E, w), find shortest path for all u,v. (When u == v, weight is 0). 

Situation:                  Algorithm to use            Time
Unweighted                  M * DFS                 O(VE)
Positive edge               Dijkstra                O(V^2 * lgV + VE)
General                     Bellman-Ford            O(V^2 * E)
                            Johnson's               O(V^2 * lgV + VE)

In dense graph situation, we can best acheive O(V^3). 

## Dynamic programming ##
1. Subproblems
2. Guessing
3. Recurrence relates subproblem
4. We can resolve sub-problem in sequence that is valid (Acyclic, do not trap into loops)
5. Original Problem

1. I want to find what is the weight of "shortest path from u->v. Using most m edges, for a given m. "
2. What's the last edge (x, v). (Try them all)
3. Duv(m) = min(d(m-1) ux + w(x, v) ) for x belong V/
   Duv(0) = {infinity, 0 if u = v}
4. for m = 0, 1, 0, 0 M - 1
        for u, v in V;
5. The original problem reduce to "shortest path from u->v. Using most m edges, for a given n. " If there is no neg-weight cycle. There is no-neg entry. 