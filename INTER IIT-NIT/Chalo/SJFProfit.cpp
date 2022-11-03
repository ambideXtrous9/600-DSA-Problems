#include <bits/stdc++.h>

using namespace std;

vector<int> findMoney(vector<vector<int>> &orders, int n, int K, int W)
{
    int waitingTime = 0;
    
    vector<int> output(n, 0);

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    int ind = 0;

    while (ind < n)
    {
        if (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            output[curr[2]] = max(0, ((K * curr[0]) - (waitingTime - curr[1]) * W));
            
            waitingTime += curr[0];
        }
        else
        {
            if (orders[ind][0] >= waitingTime)
            {
                output[ind] = K * orders[ind][1];
                
                waitingTime = orders[ind][0] + orders[ind][1];
                
                ind += 1;
            }
            else
            {
                while (ind < n && orders[ind][0] <= waitingTime)
                {
                    pq.push({orders[ind][1], orders[ind][0], ind});
                    
                    ind += 1;
                }
            }
        }
    }
    
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        
        output[curr[2]] = max(0, ((K * curr[0]) - (waitingTime - curr[1]) * W));
    }

    return output;
}
int main()
{

    int n = 3;
    int k = 5;
    int w = 1;
    vector<vector<int>> orders{{1, 8}, {2, 9}, {3, 5}};
    
    vector<int> ans = findMoney(orders, n, k, w);
    
    for (auto it : ans)
        cout << it << " ";
    
    return 0;
}