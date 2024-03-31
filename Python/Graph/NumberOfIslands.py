class Solution:
    
    def isValid(self,i,j,n,m):
        if i < 0 or j < 0 or i >=n or j >= m:
            return False
        else:
            return True

    def BFS(self,grid,r,c,n,m,visited):

        Q = []

        Q.append((r,c))

        visited[r][c] = True

        while Q:

            u,v = Q.pop(0)

            for i in range(-1,2,1):
                for j in range(-1,2,1):
                    
                    if(self.isValid(u+i,v+j,n,m) and i!=j and abs(i-j) <= 1):
                    
                        if(grid[u+i][v+j] == '1' and not visited[u+i][v+j]):
                    
                            visited[u+i][v+j] = True
                            Q.append((u+i,v+j))

    
    
    def numIslands(self, grid: List[List[str]]):

        n = len(grid)
        m = len(grid[0])

        visited = [[False for i in range(m)] for j in range(n)]

        count = 0

        for i in range(n):
            for j in range(m):
                if(visited[i][j] == False and grid[i][j] == '1'):

                    count += 1
                    self.BFS(grid,i,j,n,m,visited)

        
        return count
