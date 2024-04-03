#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool height(vector<ll> v, ll mid, ll m)
{
    ll sum = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        if (mid < v[i])
        {
            sum += v[i] - mid;
        }
        if (sum >= m)
        {
            return true;
        }
    }
    return false;
}

ll bs(vector<ll> v, ll m)
{
    sort(v.begin(), v.end());
    ll s = 0;
    ll e = v[v.size() - 1];
    ll ans = -1;
    while (s <= e)
    {
        ll mid = s + (e - s) / 2;

        if (height(v, mid, m))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {

            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    cout << bs(v, m);
}



int calc(vector<int> &psum, vector<int> &arr, int x, int n){
	int idx = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
	int n_trees = n - idx;
	int conserve = n_trees*x;
	return(psum[n] - psum[idx] - conserve);
}

int solve(vector<int> &arr, int n, int x)
{
	vector<int> psum(n+1); int res = 0;

	psum[0] = 0;
	for(int i = 1; i <= n; ++i){
		psum[i] = psum[i-1] + arr[i-1];
	}

	int l = 0, r = arr[n-1];

	while(l <= r){
		int mid = l + (r-l)/2;
		int harvest = calc(psum, arr, mid, n);
		if(harvest == x){
			return mid;
		}

		if(harvest > x){
			res = mid;
			l = mid + 1; //we need to raise our saw.
		}

		if(harvest < x){

			r = mid - 1;
		}
	} 
	return(res);
}

int32_t main()
{
	int n, x; cin >> n >> x; 
	vector<int> forest(n);
	for(int i = 0; i < n; ++i){
		cin >> forest[i];
	}
	sort(forest.begin(), forest.end());
	cout << solve(forest, n, x);
}
