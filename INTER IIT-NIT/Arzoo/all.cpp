#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *links[26];
    bool flag;
    int c = 0;

    bool containskey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *getref(char ch)
    {
        return links[ch - 'a'];
    }

    bool getend()
    {
        return flag;
    }

    void setend()
    {
        flag = true;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root; // temp node
        for (int i = 0; i < word.size(); i++)
        {
            if (!(node->containskey(word[i])))
                node->put(word[i], new Node());

            node = node->getref(word[i]);
            node->c++;
        }
        node->setend();
    }

    int search(string pre)
    {
        Node *node = root; // temp node
        for (int i = 0; i < pre.size(); i++)
        {
            if (!node->containskey(pre[i]))
                return 0;
            node = node->getref(pre[i]);
        }
        return node->c;
    }
};

int main()
{
    int N = 5;
    vector<string> words = {"apk", "app", "apple", "arp", "array"};

    string pre = "ap";
    Trie T;

    for (int i = 0; i < N; i++)
    {
        T.insert(words[i]);
    }

    cout << T.search(pre);
}

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int pos;
    int l;
    int r;
    int val;
};

bool comp(node a, node b)
{
    if (a.val == b.val)
        return a.l > b.l;

    return a.val > b.val;
}

void update(int *BIT, int n, int idx)
{
    while (idx <= n)
    {
        BIT[idx]++;
        idx += idx & (-idx);
    }
}

int query(int *BIT, int idx)
{
    int ans = 0;
    while (idx)
    {
        ans += BIT[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

// Function to solve the queries offline

void solveQuery(int arr[], int n, int QueryL[], int QueryR[], int QueryK[], int q)
{
    node a[n + q + 1];

    for (int i = 1; i <= n; ++i)
    {
        a[i].val = arr[i - 1];
        a[i].pos = 0;
        a[i].l = 0;
        a[i].r = i;
    }

    for (int i = n + 1; i <= n + q; ++i)
    {
        a[i].pos = i - n;
        a[i].val = QueryK[i - n - 1];
        a[i].l = QueryL[i - n - 1];
        a[i].r = QueryR[i - n - 1];
    }

    sort(a + 1, a + n + q + 1, comp);

    int BIT[n + 1];

    memset(BIT, 0, sizeof(BIT));

    int ans[q + 1];

    for (int i = 1; i <= n + q; ++i)
    {
        if (a[i].pos != 0)
        {
            int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1);
            ans[a[i].pos] = cnt;
        }
        else
        {
            update(BIT, n, a[i].r);
        }
    }

    for (int i = 1; i <= q; ++i)
    {
        cout << ans[i] << endl;
    }
}

int main()
{

    int arr[] = {7, 3, 9, 13, 5, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    // 1-based indexing

    int QueryL[] = {1, 2};

    int QueryR[] = {4, 6};

    // k for each query

    int QueryK[] = {6, 8};

    // number of queries

    int q = sizeof(QueryL) / sizeof(QueryL[0]);

    // Function call to get

    solveQuery(arr, n, QueryL, QueryR, QueryK, q);

    return 0;
}

int ED(string s, string t, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= m; i++) // when n == 0 ret m
        dp[0][i] = i;
    for (int i = 0; i <= n; i++)  // when m==0 ret n
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
    }

    return dp[n][m];
}

int Solve(vector<int> const &A, int n, int k)
{
    vector<vector<int>> d(n + 1, vector<int>(k + 1));
    
    for (int i = 0; i <= n; ++i)
    {
        for (int k0 = 0; k0 <= k; ++k0)
        {
            int rmin = INT_MAX;

            for (int j = 0; j <= k0; ++j)
            {
                int r = 0;
                
                if (i - 1 - j < 0)
                    r = 0;
                
                else if (i >= n)
                    r = d[i - 1 - j][k0 - j];
                
                else
                {
                    int step = (abs(A[i] - A[i - 1 - j]) + j) / (j + 1);
                    int prev = d[i - 1 - j][k0 - j];
                    r = max(step, prev);
                }
                
                rmin = min(rmin, r);
            }

            d[i][k0] = rmin;
        }
    }
    return d[n][k];
}

#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> A, vector<array<int, 3>> Q)
{
    partial_sum(begin(A), end(A), begin(A));

    for (auto &[k, y, x] : Q)
    {
        int mask = 0;

        for (int i = 30; ~i; --i)
        {
            int cnt = 0;

            for (int j = k - 1; j < int(A.size()) && (x & 1 << i) == 0; ++j)
            {
                int sum = A[j] - (j < k ? 0 : A[j - k]);

                cnt += (sum & (mask | 1 << i)) == (mask | 1 << i);
            }

            if (cnt >= y)
            {
                mask |= 1 << i;
            }
        }
        cout << (mask | x) << ' ';
    }
}

#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

int tasty(int n,int m,vector<int> &size,vector<int> &taste)
{

    vector<pair<int,int>> V;

    priority_queue<int,vector<int>,greater<int>> Q;

    for(int i = 0;i<n;i++)
    {
        V.push_back({taste[i],size[i]});
    }

    sort(rbegin(V),rend(V));

    int sum = 0;
    int res = 0;

    for(auto &[t,s] : V)
    {
        Q.push(s);

        sum += s;

        if(Q.size() > m)
        {
            sum -= Q.top();
            Q.pop();
        }
        res = max(res,sum*t);
    }

    res = res % mod;

    return res;
}