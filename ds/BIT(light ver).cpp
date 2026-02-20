struct BIT
{
    int n;
    vector<int> w;

    BIT(int _n)
    {
        n = _n;
        w.resize(n + 1);
    }

    void add(int x, int k)
    {
        for (; x <= n; x += x & -x)
            w[x] += k;
    }
    
    int ask(int x)
    {
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
};