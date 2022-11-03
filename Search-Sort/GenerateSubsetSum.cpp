#include <bits/stdc++.h>
using namespace std;

void func(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset)
{
    if (ind == N)
    {
        if(sum==0) return;
        sumSubset.push_back(sum);
        return;
    }

    // pick the element
    func(ind + 1, sum + arr[ind], arr, N, sumSubset);

    // Do-not pick the element
    func(ind + 1, sum, arr, N, sumSubset);
}

vector<int> subsetSums(vector<int> arr)
{
    vector<int> sumSubset;
    int N = arr.size();
    func(0, 0, arr, N, sumSubset);
    sort(sumSubset.begin(), sumSubset.end());
    return sumSubset;
}

void PrintV(vector<int> V)
{
    for (int i = 0; i < V.size(); i++)
    {
        cout<<V[i]<<" ";
    }
    cout<<endl;
    
}

int main()
{

    vector<int> V = {1,5,3};
    V = subsetSums(V);
    PrintV(V);
    // your code goes here
    return 0;
}
