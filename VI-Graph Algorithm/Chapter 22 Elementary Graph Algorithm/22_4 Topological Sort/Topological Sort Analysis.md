## Cycle Detection ##
G has a cycle  <=>  G has a back edge

A topological sort of a directed acyclic graph (dag). 
For simplicity sake, I would define that a topological sort would only work for directed acylic graph. 
1. Directed is very intuitive, which is there do not exist edge (u,v) and (v,u) at the same time. 
2. Aryclic means graph do not have cycle. 
 "navigating through a sequence that can have a vertex passing through it more than twice" https://www.techopedia.com/definition/26/acyclic
 Intuitively, it just meant a circle, with any number of vertices, on this circle. This create paradox as no node in the cycle should be first for all other nodes in same cycle.

Topological sort works on (dag), it can get a sequence which by follow this sequence, any edge exist in the graph (u,v) will ensure that u appear before v. It is usefull for many real world situation such as courses pre-requriement, code dependency.

The following simple algorithm uses DFS 
    call DFS(G) to compute finishing time v.f for each vertex v as each vertex is finished, 
    insert it onto the front of a linked list return the linked list. 

Lemma 22.11 
A directed graph G is acyclic if and only if a depth-first search of G yields no back edge

Proof:
    LHS => RHS. Suppose directed graph is acyclic meant that the graph don't have cycle. Then consider for graph G, after DFS, there either exist back edge or do not exist back edge. Suppose there exist back edge, says (u,v) is a back edge, then u will be ancestor of v. By trace back, there will be a linear cycle v toward u, and edge (u,v) complete the cycle. 
    
    RHS => LHS. And prove by contraposition. Suppose the graph do have at least one cycle c. We show that DFS will generate at least one back edge. Picking two adjcent vertex in cycle c, denote u and v, and suppose there is edge (u,v), and suppose that v.d < u.d. Then, by white-path theorem, vertex u become descendant of v in the depth-first forest. And the edge (u,v) will become back edge.


