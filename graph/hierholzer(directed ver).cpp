    vec<int> ans;//有向图，倒序输出ans得到路径。如果需要字典序最小的路径,把g中的vec改pq，back改top,ppb改pop

    auto dfs = [&](this auto &&dfs, int u) -> void
    {
        while (!g[u].empty())
        {
            int v = g[u].back();
            g[u].ppb();
            dfs(v);
        }
        ans.pb(u);
    };