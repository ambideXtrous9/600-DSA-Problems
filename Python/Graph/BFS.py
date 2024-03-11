from typing import List

def bfsTraversal(n: int, adj: List[List[int]]):

    res = []
    visited = [False] * n

    Q = []

    Q.append(0)
    visited[0] = True

    while Q:

        u = Q.pop(0)

        res.append(u)

        for v in adj[u]:

            if not visited[v]:
                visited[v] = True
                Q.append(v)
    
    return res


    # write your code here
    pass