### Strongly connected components in directed graphs

- u and v are strongly connected if there is a path between them in both directions

- **Condensation graph**: Consider each SCC as one vertex. There is an edge ($C_i$ ,$C_j$) if and only if $ \exists\ u \in C_i, v \in C_j : (u, v) \in E$ .
- Condensation graph is a DAG

#### Kosaraju's Algorithm

- Define $tout[C] = max\{ tout[v] \forall v \in C\}$
- Theorem: Let $C$ and $C'$ are two different SCC and there is an edge $(C, C')$  in a condensation graph. Then $tout[C] > tout[C']$. If we transpose $G$, $G^T$ have the same SCCs as $G$. Moreover, the condensation graph will also get transposed, there will be no edges from $C$ to $C'$.

- **Algorithm**:
  - Run DFS on G and compute $tout[v]$
  - Reverse the edges of G
  - Run DFS on G in decreasing order of $tout[v]$
  - Each tree in the DFS forest is a SCC
- It generates components - vertices of condensation graph in topological sorted order.


