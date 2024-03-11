
from collections import defaultdict

def CreateGraphDict(edges,V):
    
    adj = defaultdict(list)
    
    for edge in edges:
        
        u,v = edge
        
        adj[u].append(v)
        adj[v].append(u)
        
    return adj

def CreateGraphList(edges,V):
    
    adj = [[i] for i in range(V)]
    
    for edge in edges:
        
        u,v = edge
        
        adj[u].append(v)
        adj[v].append(u)
        
    return adj


def PrintGraphDict(adj):
    
    for u in adj.keys():
        print (f"{u} -> {adj[u]}")
        

def PrintGraphList(adj):
    
    for i,u in enumerate(adj):
        print (f"{u[0]} -> {u[1:]}")


        
if __name__ == '__main__':
    
    edges = [(2,1), (2,0)]
    
    
    print("Using Dictionary")
    
    adj = CreateGraphDict(edges,V=3)
    PrintGraphDict(adj=adj)
    
    print("Using List of List")

    
    adj = CreateGraphList(edges,V=6)
    PrintGraphList(adj=adj)
    
    