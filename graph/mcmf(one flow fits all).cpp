template <typename TF, typename TC>
struct mcmf
{
    struct Edge
    {
        int to;
        TF cap;
        TC cost;
    };

    vector<Edge> e;
    vector<vector<int>> g;
    vector<TC> h, dis;
    vector<int> pre;
    int n;

    const TC INF_COST = numeric_limits<TC>::max() / 2;
    const TF INF_FLOW = numeric_limits<TF>::max() / 2;

    mcmf(int _n)
    {
        n = _n;
        g.resize(n + 1);
    }

    void add(int u, int v, TF w, TC c)
    {
        g[u].push_back(e.size());
        e.push_back({v, w, c});
        g[v].push_back(e.size());
        e.push_back({u, 0, -c});
    }

    bool spfa(int s)
    {
        h.assign(n + 1, INF_COST);
        vector<char> inq(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        queue<int> q;
        TF eps_flow = 0;
        if constexpr (is_floating_point_v<TF>)
            eps_flow = 1e-9;
        TC eps_cost = 0;
        if constexpr (is_floating_point_v<TC>)
            eps_cost = 1e-9;
        h[s] = 0;
        q.push(s);
        inq[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i : g[u])
            {
                auto &[v, w, c] = e[i];
                if (w > eps_flow && h[v] > h[u] + c + eps_cost)
                {
                    h[v] = h[u] + c;
                    if (!inq[v])
                    {
                        q.push(v);
                        inq[v] = 1;
                        cnt[v]++;
                        if (cnt[v] >= n)
                            return 0; 
                    }
                }
            }
        }
        return 1;
    }

    bool dijkstra(int s, int t)
    {
        dis.assign(n + 1, INF_COST);
        pre.assign(n + 1, -1);
        using P = pair<TC, int>;
        priority_queue<P, vector<P>, greater<P>> q;
        TF eps_flow = 0;
        if constexpr (is_floating_point_v<TF>)
            eps_flow = 1e-9;
        TC eps_cost = 0;
        if constexpr (is_floating_point_v<TC>)
            eps_cost = 1e-9;
        dis[s] = 0;
        q.push({0, s});
        while (!q.empty())
        {
            auto [d, u] = q.top();
            q.pop();
            if (dis[u] < d - eps_cost)
                continue;
            for (int i : g[u])
            {
                auto &[v, w, c] = e[i];
                if (w > eps_flow && dis[v] > d + h[u] - h[v] + c + eps_cost)
                {
                    dis[v] = d + h[u] - h[v] + c;
                    pre[v] = i;
                    q.push({dis[v], v});
                }
            }
        }
        return dis[t] < INF_COST / 2;
    }

    pair<TF, TC> work(int s, int t)
    {
        if (!spfa(s))
            return {-1, -1};
        TF flow = 0;
        TC cost = 0;
        TF eps_flow = 0;
        if constexpr (is_floating_point_v<TF>)
            eps_flow = 1e-9;
        while (dijkstra(s, t))
        {
            for (int i = 1; i <= n; i++)
                if (dis[i] < INF_COST / 2)
                    h[i] += dis[i];
            TF aug = INF_FLOW;
            for (int i = t; i != s; i = e[pre[i] ^ 1].to)
                aug = min(aug, e[pre[i]].cap);
            if (aug <= eps_flow)
                break;
            for (int i = t; i != s; i = e[pre[i] ^ 1].to)
            {
                e[pre[i]].cap -= aug;
                e[pre[i] ^ 1].cap += aug;
            }
            flow += aug;
            cost += h[t] * aug;
        }
        return {flow, cost};
    }

    vector<tuple<int, int, TF, TF, TC>> edge() // from,to,flow,cap,cost
    {
        vector<tuple<int, int, TF, TF, TC>> ret;
        for (int i = 0; i < (int)e.size(); i += 2)
            ret.push_back({e[i ^ 1].to, e[i].to, e[i ^ 1].cap, e[i].cap + e[i ^ 1].cap, e[i].cost});
        return ret;
    }
};