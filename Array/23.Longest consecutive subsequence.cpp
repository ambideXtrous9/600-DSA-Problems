#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int> &nums)
{

    unordered_map<int, int> M;

    for (auto x : nums)
        M[x] = 1; // intialize all number and freq = 1

    for (auto x : nums)
    {
        if (M.find(x - 1) != M.end()) // if its prev number exist then it cant be start of sequence
        {
            M[x] = 0; // so make them 0
        }
    }

    int longest = 0;

    for (auto x : M)
    {
        if (x.second == 1) // when 1 -> possible candidate for start
        {
            int len = 1;

            while (M.find(x.first + len) != M.end()) // goes on counting consecutives
            {
                len++;
            }

            longest = max(longest, len); // when breaks upadte the max len of the consecutive seq
        }
    }

    return longest; // return the longest
}

// union-find

int parent[100001];
int Rank[100001];

int findPar(int node)
{
    if (node == parent[node])
        return node;

    return parent[node] = findPar(parent[node]);
}

void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if (u == v)
        return;

    if (Rank[v] < Rank[u]) // updation of rank
    {
        parent[v] = u;
        Rank[u] += Rank[v];
    }
    else // when Rank[v]>Rank[u] && Rank[v]==Rank[u]
    {
        parent[u] = v;
        Rank[v] += Rank[u];
    }
}
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        Rank[i] = 1;
    }

    unordered_map<int, int> M;

    for (int i = 0; i < n; i++)
    {
        if (M.find(nums[i]) != M.end()) // if already present skip
            continue;

        if (M.find(nums[i] - 1) != M.end()) // if previous exist perform union
        {
            Union(M[nums[i] - 1], i);
        }

        if (M.find(nums[i] + 1) != M.end()) // if next exist perform union
        {
            Union(M[nums[i] + 1], i);
        }

        M[nums[i]] = i; // push the index to the map
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, Rank[i]); // max rank is the ans
    }

    return ans;
}

int findLongestConseqSubseq(int arr[], int N)
{
    int ans = 0;
    unordered_set<int> S;
    for (int i = 0; i < N; i++)
        S.insert(arr[i]);

    for (int i = 0; i < N; i++)
    {
        if (S.find(arr[i] - 1) == S.end())  // possible candidate for satrt of sequence
        {
            int num = arr[i];
            int count = 0;
            while (S.find(num) != S.end())
            {
                num++;
                count++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
    // Your code here
}