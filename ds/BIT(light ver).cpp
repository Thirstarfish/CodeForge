struct BIT
{
    int n, lg;
    vector<int> w;

    BIT(int _n)
    {
        n = _n;
        w.resize(n + 1);
        lg = __lg(n);
    }

    void add(int x, int k)
    {
        for (; x <= n; x += x & -x)
            w[x] += k;
    }

    int ask(int x)
    {
        if (x == 0)
            return 0;
        int ans = 0;
        for (; x; x -= x & -x)
            ans += w[x];
        return ans;
    }

    int ask(int x, int y)
    {
        if (x == 1)
            return ask(y);
        return ask(y) - ask(x - 1);
    }

    int kth(int k)
    {
        int pos = 0;
        for (int i = 1 << lg; i; i >>= 1)
        {
            int nxt = pos + i;
            if (nxt <= n && w[nxt] < k)
            {
                k -= w[nxt];
                pos = nxt;
            }
        }
        return pos + 1;
    }
};