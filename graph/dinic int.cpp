struct dinic
{
    int n;
    vec<vec<int>> g;
    vec<aii> e;
    vec<int> dis, cur;

    dinic(int _n)
    {
        n = _n;
        g.resize(n + 1);
    }

    void add(int u, int v, int w)
    {
        g[u].pb(e.size());
        e.pb({v, w});
        g[v].pb(e.size());
        e.pb({u, 0});
    }

    bool bfs(int s, int t)
    {
        dis.assign(n + 1, -1);
        queue<int> q;
        dis[s] = 0;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto i : g[u])
            {
                auto &[v, c] = e[i];
                if (c > 0 && dis[v] == -1)
                {
                    dis[v] = dis[u] + 1;
                    if (v == t)
                        return true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    int dfs(int u, int t, int f)
    {
        if (u == t)
            return f;
        int r = f;
        for (int &i = cur[u]; i < (int)(g[u].size()); i++)
        {
            int j = g[u][i];
            auto &[v, c] = e[j];
            if (c > 0 && dis[v] == dis[u] + 1)
            {
                int temp = dfs(v, t, min(r, c));
                e[j][1] -= temp;
                e[j ^ 1][1] += temp;
                r -= temp;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }

    int work(int s, int t)
    {
        int ans = 0;
        while (bfs(s, t))
        {
            cur.assign(n + 1, 0);
            ans += dfs(s, t, inf);
        }
        return ans;
    }

    vec<aiii> edge() // from/to/flow
    {
        vec<aiii> ret;
        for (int i = 0; i < e.size(); i += 2)
            ret.pb({e[i ^ 1][0], e[i][0], e[i ^ 1][1]});
        return ret;
    }
};