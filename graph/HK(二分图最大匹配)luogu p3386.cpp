#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vec vector
#define endl '\n'
#define fir first
#define sec second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ppc __builtin_popcount
#define ctz __builtin_ctzll // 去掉define int long long记得修改这里喵
#define clz __builtin_clzll // 还有这里喵
#define pcs(n) cout << fixed << setprecision(n)
#define rvs std::views::reverse
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef tuple<int, int, int, int> t4i;
typedef tuple<int, int, int, int, int> t5i;
typedef array<int, 2> aii;
typedef array<int, 3> aiii;
typedef array<int, 4> a4i;
typedef array<int, 5> a5i;
typedef unsigned long long ull;
typedef long double lld;
typedef __int128_t lll;
const int mod = 998244353; // 1000000000039ll
const int N = 1000005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const vec<aii> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-6;

struct HK
{
    int n, m;
    vec<vec<int>> g;
    vec<int> ti, rec;
    HK(int _n, int _m) : n(_n), m(_m)
    {
        g.resize(n + 1);
        ti.resize(n + 1);
        rec.resize(m + 1);
    }

    bool dfs(int u, int t)
    {
        if (ti[u] == t)
            return 0;
        ti[u] = t;
        for (auto v : g[u])
        {
            if (!rec[v] || dfs(rec[v], t))
            {
                rec[v] = u;
                return 1;
            }
        }
        return 0;
    }

    void add(int x, int y)
    {
        g[x].pb(y);
    }

    int work()
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += dfs(i, i);
        return ans;
    }
};

void cold_beans()
{
    int n, m, e;
    cin >> n >> m >> e;
    HK flow(n, m);
    for (int i = 1; i <= e; i++)
    {
        int x, y;
        cin >> x >> y;
        flow.add(x, y);
    }
    cout << flow.work() << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _; // 单测记得注释这里喵
    while (_--)
        cold_beans();
    return 0;
}

/*
騒がしい日々に笑えない君に
思い付く限り眩しい明日を
*/
