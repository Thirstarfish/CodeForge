#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vec vector
#define fir first
#define sec second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mxe max_element
#define mne min_element
#define ptq priority_queue
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
typedef __int128_t lll;
const int mod = 998244353; // 1000000000039ll
const int N = 1000005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int bs = 433;
const vec<vec<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-6;

struct DSU
{
    vector<int> fa, p;

    DSU(int n)
    {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        p.resize(n + 1, 1);
    }
    
    int get(int x)
    {
        while (x != fa[x])
            x = fa[x] = fa[fa[x]];
        return x;
    }
    
    bool merge(int from, int to)
    {
        from = get(from), to = get(to);
        if (from == to) return false;
        fa[from] = to;
        p[to] += p[from];
        return true;
    }
    
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    
    int size(int x)
    {
        return p[get(x)];
    }
};

void cold_beans()
{
    int n, m, s;
    cin >> n >> m >> s;
    vec<vec<int>> g(n + 1);
    vec<int> ans(m + 1);
    vec<char> vis(n + 1);
    vec<vec<aii>> q(n + 1);
    DSU dsu(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        q[a].pb({b, i});
        q[b].pb({a, i});
    }
    auto dfs = [&](this auto &&dfs, int u, int fa) -> void
    {
        vis[u] = 1;
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            dfs(v, u);
            dsu.merge(v, u);
        }
        for (auto &[v, num] : q[u])
            if (vis[v])
                ans[num] = dsu.get(v);
    };
    dfs(s, 0);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
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
