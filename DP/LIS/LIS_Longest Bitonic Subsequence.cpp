#include <bits/stdc++.h>

using namespace std;

/*
1. find the LIS of nums.
2. find the LIS of reverse of nums. -> LRS
3. now reverse the LRS array.

4. now find max(LIS[i]+LRS[i]-1)


*/

vector<int> LIS(vector<int> &nums)
{
	int n = nums.size();

	vector<int> V;
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++)
	{
		if (V.size() == 0 || nums[i] > V.back())
		{
			V.push_back(nums[i]);
			dp[i] = V.size();
		}
		else
		{
			int idx = lower_bound(V.begin(), V.end(), nums[i]) - V.begin();

			V[idx] = nums[i];
			dp[i] = (idx + 1);
		}
	}

	return dp;
}

int LongestBitonicSequence(vector<int> nums)
{

	vector<int> lis = LIS(nums);

	reverse(nums.begin(), nums.end());

	vector<int> lrs = LIS(nums);

	reverse(lrs.begin(), lrs.end());

	int res = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		res = max(res, lis[i] + lrs[i] - 1);
	}
	return res;
}