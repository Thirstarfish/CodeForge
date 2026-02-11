struct mcmf
{
    vec<aiii> e; // to,cap,cost
    vec<vec<int>> g;
    vec<int> h, dis, pre;
    int n;
    mcmf(int _n)
    {
        n = _n;
        g.resize(n + 1);
        h.resize(n + 1);
    }

    void add(int u, int v, int w, int c)
    {
        g[u].pb(e.size());
        e.pb({v, w, c});
        g[v].pb(e.size());
        e.pb({u, 0, -c});
    }

    bool dijkstra(int s, int t)
    {
        dis.assign(n + 1, inf);
        pre.assign(n + 1, -1);
        priority_queue<aii, vec<aii>, greater<aii>> q;
        dis[s] = 0;
        q.push({0, s});
        while (!q.empty())
        {
            auto [d, u] = q.top();
            q.pop();
            if (dis[u] != d)
                continue;
            for (auto i : g[u])
            {
                auto &[v, w, c] = e[i];
                if (w > 0 && dis[v] > d + h[u] - h[v] + c)
                {
                    dis[v] = d + h[u] - h[v] + c;
                    pre[v] = i;
                    q.push({dis[v], v});
                }
            }
        }
        return dis[t] != inf;
    }

    aii work(int s, int t)
    {
        aii ret = {0, 0}; // flow,cost
        while (dijkstra(s, t))
        {
            for (int i = 1; i <= n; i++)
                h[i] += dis[i];
            int aug = inf;
            for (int i = t; i != s; i = e[pre[i] ^ 1][0])
                aug = min(aug, e[pre[i]][1]);
            for (int i = t; i != s; i = e[pre[i] ^ 1][0])
            {
                e[pre[i]][1] -= aug;
                e[pre[i] ^ 1][1] += aug;
            }
            ret[0] += aug;
            ret[1] += aug * h[t];
        }
        return ret;
    }
};

