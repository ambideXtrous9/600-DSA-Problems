#include <bits/stdc++.h>

using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};


static bool comp1(Job a, Job b)
{
    return a.profit > b.profit;
}


vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comp1);
    vector<bool> vis(n, false);
    int jobcnt = 0, maxprofit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead - 1; j >= 0; j--)
        {
            if (vis[j])
                continue;
            else
            {
                vis[j] = true;
                maxprofit += arr[i].profit;
                jobcnt++;
                break;
            }
        }
    }
    return {jobcnt, maxprofit};
}

//------------------------------------------------------------------------//
//------------------------------------------------------------------------//

bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.first > b.first;
}

int solve(vector<int>& deadlines, vector<int>& credits) 
{
    vector<pair<int,int>> arr;
    int n =  deadlines.size();

    if(n==0) return 0;

    for(int i = 0;i < n;i++)
    {
        arr.push_back({credits[i],deadlines[i]});
    }

    sort(arr.begin(),arr.end(),comp); // sort by decreasing profit

    vector<bool> vis(n, false);
    
    int jobcnt = 0;
    int maxprofit = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n,arr[i].second); j >= 0; j--)
        {
            if (vis[j])
                continue;
            else
            {
                vis[j] = true;
                maxprofit += arr[i].first;
                //jobcnt++;
                break;
            }
        }
    }
    return  maxprofit;

}