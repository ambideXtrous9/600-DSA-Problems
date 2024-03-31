from typing import List

def DFS(adj,u,visited,res):

    visited[u] = True
    
    res.append(u)

    for v in adj[u]:
        
        if not visited[v]:
        
            DFS(adj,v,visited,res)

def bfsTraversal(n: int, adj: List[List[int]]):

    res = []
    visited = [False] * n

    DFS(adj,0,visited,res)
    
    return res



class Solution:
    
    #Function to return a list containing the DFS traversal of the graph.
    
    def DFS(self, adj, u , visited,dfstrav):
        
        visited[u] = True
        
        dfstrav.append(u)
        
        for v in adj[u]:
            
            if not visited[v]:
            
                self.DFS(adj,v,visited,dfstrav)
            
    
    def dfsOfGraph(self, V, adj):
        # code here
        
        n = len(adj)
        
        visited = [False] * n
        
        dfstrav = []
        
        self.DFS(adj,0,visited,dfstrav)
                
        return dfstrav