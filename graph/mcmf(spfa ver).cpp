struct mcmf
{
    vec<aiii> e; // to, cap, cost
    vec<vec<int>> g;
    vec<int> dis, pre;
    int n;
    mcmf(int _n)
    {
        n = _n;
        g.resize(n + 1);
        dis.resize(n + 1);
        pre.resize(n + 1);
    }

    void add(int u, int v, int w, int c)
    {
        g[u].pb(e.size());
        e.pb({v, w, c});
        g[v].pb(e.size());
        e.pb({u, 0, -c});
    }

    bool spfa(int s, int t)
    {
        dis.assign(n + 1, inf);
        pre.assign(n + 1, -1);
        vec<char> vis(n + 1, 0);
        queue<int> q;

        dis[s] = 0;
        q.push(s);
        vis[s] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = 0;

            for (auto i : g[u])
            {
                auto &[v, w, c] = e[i];
                if (w > 0 && dis[v] > dis[u] + c)
                {
                    dis[v] = dis[u] + c;
                    pre[v] = i;
                    if (!vis[v])
                    {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
        return dis[t] != inf;
    }

    aii work(int s, int t)
    {
        aii ret = {0, 0}; // flow, cost
        while (spfa(s, t))
        {
            int aug = inf;
            for (int i = t; i != s; i = e[pre[i] ^ 1][0])
                aug = min(aug, e[pre[i]][1]);
            for (int i = t; i != s; i = e[pre[i] ^ 1][0])
            {
                e[pre[i]][1] -= aug;
                e[pre[i] ^ 1][1] += aug;
            }
            ret[0] += aug;
            ret[1] += aug * dis[t];
        }
        return ret;
    }

    vec<a5i> edge() // u, v, f, cap, cost
    {
        vec<a5i> ret;
        for (int i = 0; i < e.size(); i += 2)
            ret.pb({e[i ^ 1][0], e[i][0], e[i ^ 1][1], e[i][1] + e[i ^ 1][1], e[i][2]});
        return ret;
    }
};