//如果不需要字典序最小可以把pq换成vec
vec<char> vis(m + 1);
vec<priority_queue<aii, vec<aii>, greater<aii>>> g(501);
vec<int> ans;

auto dfs = [&](this auto &&dfs, int u) -> void
{
    while (!g[u].empty())
    {
        auto [v, i] = g[u].top();
        g[u].pop();
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(v);
        }
    }
    ans.pb(u);
};