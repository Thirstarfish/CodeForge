vec<int> dis(n + 1, inf);
vec<char> vis(n + 1);
priority_queue<aii, vec<aii>, greater<aii>> q;
int s = 1;
q.push({0, s});
dis[s] = 0;
while (!q.empty())
{
    auto [w, v] = q.top();
    q.pop();
    if (vis[v])
        continue;
    vis[v] = 1;
    for (auto &[nv, nw] : g[v])
    {
        if (dis[nv] > dis[v] + nw)
        {
            dis[nv] = dis[v] + nw;
            q.push({dis[nv], nv});
        }
    }
}