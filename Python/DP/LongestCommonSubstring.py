class Solution:
    
    def LCSTR(self,S1,S2,i,j,dp,ans):
        
        take = 0
        nt1 = 0
        nt2 = 0
        
        if(i<0 or j<0): 
            return 0;
        if(dp[i][j]!=-1): 
            return dp[i][j];
        
        if(S1[i] == S2[j]):
            
            take = 1 + self.LCSTR(S1,S2,i-1,j-1,dp,ans);
        
        nt1 = self.LCSTR(S1,S2,i-1,j,dp,ans);
        
        nt2 = self.LCSTR(S1,S2,i,j-1,dp,ans);
        
        ans = max(ans,take)
        
        dp[i][j] = take
        
        return take
    
    def longestCommonSubstr(self, S1, S2, n, m):
        
        ans = 0
        
        dp = [[-1 for i in range(n+1)] for j in range(m+1)]
        
        self.LCSTR(S1,S2,n-1,m-1,dp,ans)
        
        return ans
        
            
        
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        n,m = input().strip().split(" ")
        n,m = int(n), int(m)
        S1 = input().strip()
        S2 = input().strip()
        
        
        ob=Solution()
        print(ob.longestCommonSubstr(S1, S2, n, m))