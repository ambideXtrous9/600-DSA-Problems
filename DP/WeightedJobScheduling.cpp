#include <bits/stdc++.h>

using namespace std;

// LC : 1235. Maximum Profit in Job Scheduling

int dp[10001];
static bool comparator(vector<int> &s1, vector<int> &s2)
{
    return (s1[1] < s2[1]);
}

int latestNonConflict(vector<vector<int>> &arr, int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[j][1] <= arr[i - 1][0])
            return j;
    }
    return -1;
}

// -----------------------Memoization-----------------------------------------

int findMaxProfitRec(vector<vector<int>> &arr, int n)
{
    // Base case
    if (n == 1)
        return arr[n - 1][2];

    if (dp[n] != -1)
        return dp[n];

    // Find profit when current job is excluded
    int exclProf = findMaxProfitRec(arr, n - 1);

    int i = latestNonConflict(arr, n);

    int inclProf = arr[n - 1][2];
    if (i != -1)
        inclProf += findMaxProfitRec(arr, i + 1);

    return dp[n] = max(inclProf, exclProf);
}

int solve(vector<vector<int>> &arr)
{

    int n = arr.size();

    memset(dp, -1, sizeof(dp));

    cout << endl;

    sort(arr.begin(), arr.end(), comparator);

    return findMaxProfitRec(arr, n);
}

//--------------Tabulation------------------------

int solve(vector<vector<int>> &arr)
{

    int n = arr.size();

    sort(arr.begin(), arr.end(), comparator); // sort based on finish time

    vector<int> table(n + 1, 0); // 1D DP

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            table[i] = arr[0][2];
        }
        else
        {
            int exclProfit = table[i - 1]; // skip the current

            int inclProf = arr[i - 1][2]; // include the current

            int l = latestNonConflict(arr, i); // search the next job to be include based on end < cur.start

            if (l != -1) // == -1 when no other job can be scheduled
                inclProf += table[l + 1];

            table[i] = max(inclProf, exclProfit); // take max b/w take n not take
        }
    }
    return table[n];
}

//--------------------------------------------------------------

struct Job
{
    int start, finish, profit;
};

bool jobComparator(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

int latestNonConflict(Job arr[], int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[j].finish <= arr[i - 1].start)
            return j;
    }
    return -1;
}

int binarySearch(Job jobs[], int index)
{
    // Initialize 'lo' and 'hi' for Binary Search
    int lo = 0, hi = index - 1;

    // Perform binary Search iteratively
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }

    return -1;
}

int findMaxProfitRec(Job arr[], int n)
{
    // Base case
    if (n == 1)
        return arr[n - 1].profit;

    // Find profit when current job is excluded
    int exclProf = findMaxProfitRec(arr, n - 1);

    int i = latestNonConflict(arr, n);

    int inclProf = arr[n - 1].profit;
    if (i != -1)
        inclProf += findMaxProfitRec(arr, i + 1);

    return max(inclProf, exclProf);
}

int findMaxProfit(Job arr[], int n)
{
    sort(arr, arr + n, jobComparator);

    return findMaxProfitRec(arr, n);
}

int findMaxProfit(Job arr[], int n)
{
    sort(arr, arr + n, jobComparator);

    int *table = new int[n + 1];
    table[0] = arr[0].profit;

    for (int i = 1; i <= n; i++)
    {
        int exclProfit = table[i - 1];
        int inclProf = arr[i - 1].profit;
        int l = latestNonConflict(arr, i);
        if (l != -1)
            inclProf += table[l + 1];

        table[i] = max(inclProf, exclProfit);
    }
    int result = table[n];
    delete[] table;

    return result;
}