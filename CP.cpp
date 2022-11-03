#include <bits/stdc++.h>

using namespace std;

// making life easy!
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for (int i = (b)-1; i >= (a); --i)

#define all(x) (x).begin(), (x).end()

// subtle... but powerful
#define deb(x) cout << #x << " " << x << '\n'

// can't help... need them
template <class T>
bool ckmin(T &a, T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, T &b) { return a < b ? a = b, 1 : 0; }
template <class T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// every keystroke counts!
const char nl = '\n';

// debugging
template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    return os << "(" << p.first << ": " << p.second << ")";
}
template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    bool first = true;
    os << "[";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        if (!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}
template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::set<T> &v)
{
    bool first = true;
    os << "{";
    for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "}";
}
template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::map<T1, T2> &v)
{
    bool first = true;
    os << "{";
    for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "}";
}
template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &v)
{
    return os << std::set<T>(v.begin(), v.end());
}
template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::unordered_map<T1, T2> &v)
{
    return os << std::map<T1, T2>(v.begin(), v.end());
}

void solution()
{
    // write your code here
}

int main()
{
    // fast i/o
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solution();
    }
    return 0;
}
