struct DSU
{
    int n;
    vector<int> fa, size;
    DSU(int a = 0) { init(a); }
    void init(int a)
    {
        n = a;
        fa.assign(n + 1, 0);
        size.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }

    int find(int x)
    {
        if (x != fa[x])
            fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return 0;
        if (size[x] < size[y])
            swap(x, y);
        size[x] += size[y];
        fa[y] = x;
        return 1;
    }

    bool same(int a, int b) { return find(a) == find(b); }

    int sz(int a) { return size[find(a)]; }

    friend ostream &operator<<(ostream &os, DSU &dsu)
    {
        os << "DSU[";
        for (int i = 1; i <= dsu.n; i++)
        {
            os << '(' << i << ',' << dsu.find(i) << ')' << ' ';
        }
        os << ']';
        return os;
    }
};