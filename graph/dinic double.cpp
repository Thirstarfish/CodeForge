using pid = pair<int, double>;

struct dinic
{
    int n;
    vec<vec<int>> g;
    vec<pid> e;
    vec<int> dis, cur;

    dinic(int _n)
    {
        n = _n;
        g.resize(n + 1);
    }

    void add(int u, int v, double w)
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

    int dfs(int u, int t, double f)
    {
        if (u == t)
            return f;
        double r = f;
        double res = 0;
        for (int &i = cur[u]; i < (int)(g[u].size()); i++)
        {
            int j = g[u][i];
            auto &[v, c] = e[j];
            if (c > 0 && dis[v] == dis[u] + 1)
            {
                double temp = dfs(v, t, min(r, c));
                res += temp;
                e[j].sec -= temp;
                e[j ^ 1].sec += temp;
                r -= temp;
                if (r == 0)
                    return f;
            }
        }
        return res;
    }

    double work(int s, int t)
    {
        int ans = 0;
        while (bfs(s, t))
        {
            cur.assign(n + 1, 0);
            ans += dfs(s, t, 1e100);
        }
        return ans;
    }
};