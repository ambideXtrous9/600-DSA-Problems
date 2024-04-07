

// kadane's Algorithm

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
    
        int buyAtPrice = INT_MAX;
    
        int maxProfit = 0;
    
        for(int i=0; i<n; i++)
        {
            buyAtPrice = min(buyAtPrice, prices[i]);
        
            maxProfit = max(maxProfit, prices[i] - buyAtPrice); 
        }
        
        return maxProfit;
    }
};


// DP Solution

class Solution {
public:
    
    
    int dp[100001][2][3];
    
    int stock(vector<int>& prices,int i,int n,bool buy,int k)
    {
        if(i==n || k<=0) return 0;
        
        if(dp[i][k][buy]!=-1) return dp[i][k][buy];
        
        int cost = stock(prices,i+1,n,buy,k);
            
        if(buy && k)
        {
            cost = max(cost, -prices[i] + stock(prices,i+1,n,!buy,k));
        }
        if(!buy)
        {
            cost = max(cost, prices[i] + stock(prices,i+1,n,!buy,k-1));
        }
        
        return dp[i][k][buy] = cost;
        
    }
    
    
    int maxProfit(vector<int>& prices) 
    {
        
        int n = prices.size();
        
        memset(dp,-1,sizeof(dp));
        
        int k = 1;
        
        return stock(prices,0,n,1,k);
        
    }
    
    
};