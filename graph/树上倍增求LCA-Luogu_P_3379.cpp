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

void cold_beans()
{
    int n, m, s;
    cin >> n >> m >> s;
    vec<vec<int>> g(n + 1), st(20, vec<int>(n + 1));
    vec<int> dep(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    auto dfs = [&](this auto &&dfs, int u, int fa, int d) -> void
    {
        st[0][u] = fa;
        dep[u] = d;
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            dfs(v, u, d + 1);
        }
    };
    dfs(s, 0, 1);
    for (int i = 1; i < 20; i++)
        for (int j = 1; j <= n; j++)
            st[i][j] = st[i - 1][st[i - 1][j]];
    auto lca = [&](int a, int b) -> int
    {
        if (dep[a] < dep[b])
            swap(a, b);
        int wt = dep[a] - dep[b];
        for (int i = 0; i < 20; i++)
            if (wt & 1 << i)
                a = st[i][a];
        if (a == b)
            return a;
        for (int i = 19; i >= 0; i--)
        {
            if (dep[a] > 1 << i && st[i][a] != st[i][b])
                a = st[i][a], b = st[i][b];
        }
        return st[0][a];
    };
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
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
