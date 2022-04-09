## ADT : Disjoint-set data structure ##
A disjoint-set data structure mainatains a collection of set {S1, S2, S3... Sk}, where we identify each set by a representative which is some member of that set. 

We wish to support following operation
1. MAKE-SET(x), creates a new set whose only element is x. (Since disjoint property, we require x do not belong to any set yet).
2. UNION(x,y), union two dynamic set whoes contains x and y, says Sx and Sy into S, the new representative can be any element from new set S. In maths sense, all element in Sx, and Sy will be destroyed and the new set S kept. In practice, we often absort the element from one and into other set. 
3. FIND-SET(x), returns a pointer() to the reprsentative of the (unique) set containing x. 

To analysis the performance of Disjoint-set structure, we define two number n, m. Let n be the number MAKE-SET() prior any other operation. And m, be the total number of MAKE-SET(), UNION() and FIND-SET(). Note that since UNION() <= MAKE-SET() - 1. And m >= n.

## An application of disjoint-set data structure ##
One of the many application is to determine connencted component in a undirected graph. The algorithm is follow

CONNECTED-COMPONENT(G) 
    for each vertex v belong G.V
        MAKE-SET(v)
    for each edge (u,v) belong G.E
        if FIND-SET(u) != FIND-SET(v)
            UNION(u,v)

SAME-COMPONENT(u,v) 
    if FIND-SET(u) == FIND-SET(v)
        UNION(u,v)

// Following is idea for dynamic case
ADD-VERTEX(G, v)
    MAKE-SET(v)

ADD-EDGE(G, (u,v))
    if FIND-SET(u) != FIND-SET(v)
        UNION(u,v)


When the graph is static, one can use DFS to determine connected component once for all. Which is much more efficient than Disjoint-set approach. However, if the graph will be dynamically added, and one wish to maintain a connnected component, the disjoint-set approch is more efficient.


## Exercise ##
21.1-1
Inspect Edge    {a} {b} {c} {d} {e} {f} {g} {h} {i} {j} {k}
(d, i)          {a} {b} {c} {d, i} {e} {f} {g} {h} {j} {k}
(f, k)          {a} {b} {c} {d, i} {e} {f, k} {g} {h} {j} 
(g, i)          {a} {b} {c} {g, d, i} {e} {f, k} {h} {j} 
(b, g)          {a} {c} {g, b, d, i} {e} {f, k} {h} {j} 
(a, h)          {a, h} {c} {g, b, d, i} {e} {f, k} {j} 
(i, j)          {a, h} {c} {g, b, d, i, J} {e} {f, k} 
(d, k)          {a, h} {c} {g, b, d, i, J ,f , k} {e}
(b, j)          {a, h} {c} {g, b, d, i, J ,f , k} {e}
(d, f)          {a, h} {c} {g, b, d, i, J ,f , k} {e}
(g, j)          {a, h} {c} {g, b, d, i, J ,f , k} {e}
(a, e)          {a, h, e} {c} {g, b, d, i, J ,f , k}



21.1-2
->. Suppose that two vertice are in the same connect component, denote v1,v2. Then, there exist a collection of edge (e1, e2...ek) that mark path v1->v2. And by reverseing the order of edge, we can get a path v2->v1. From the algorithm, it inspect all edges include (e1, e2...ek), and will do UNION among the verteces appear in this path. 
We want to proof, all vertices appear in this edges will be at same set at the end. 
First, we show any adjency vertices will be in the same set.
By pick arbitary edge (ej), suppose (vj, vj+1) is already on set. Then we are done. 
Suppose (vj, vj+1) not in same set, then by UNION, (vj, vj+1)  will be on the same set. 
Next, consider there exist a path between any vertices appear in the path. And by discussed before, all vertice are in the same set, hence any arbitary vertice appear in the path have to belong to the same set.

<-. Suppose that two vertices are in the same set. Proof by contrapositive.
Suppose the two vertices are not in same connected component, then they are not in same set. 
Let two connected set denote V and U, and there is no edge (u,v) such that u belong to U and v belong to V. Then, there is no UNION operation operate between U and V, thus arbitary element in U and arbitary element in V won't be in the same set. 



