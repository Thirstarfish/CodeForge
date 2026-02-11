template <typename T>
struct seg
{
    struct node
    {
        int l, r;
        T w;
        node operator+(const node &other) const
        {
            node res;
            res.l = l;
            res.r = other.r;
            res.w = w + other.w;
            return res;
        }
    };

    vector<T> w;
    vector<node> t;

    inline int ls(int k) { return k << 1; }
    inline int rs(int k) { return k << 1 | 1; }

    seg(int n)
    {
        w.resize(n + 1);
        t.resize((n << 2) + 1);
        build(1, n);
    }

    seg(vector<T> in)
    {
        int n = in.size() - 1;
        w.resize(n + 1);
        for (int i = 1; i <= n; i++)
            w[i] = in[i];
        t.resize((n << 2) + 1);
        build(1, n);
    }

    inline void pushup(int k)
    {
        t[k] = t[ls(k)] + t[rs(k)];
    }

    inline void update(int k, T v)
    {
        t[k].w += v;
    }

    void build(int l, int r, int k = 1)
    {
        if (l == r)
        {
            t[k] = {l, r, w[l]};
            return;
        }
        t[k] = {l, r};
        int mid = l + r >> 1;
        build(l, mid, ls(k));
        build(mid + 1, r, rs(k));
        pushup(k);
    }

    void modify(int pos, T v, int k = 1)
    {
        if (t[k].l == t[k].r)
        {
            update(k, v);
            return;
        }
        int mid = (t[k].l + t[k].r) >> 1;
        if (pos <= mid)
            modify(pos, v, ls(k));
        else
            modify(pos, v, rs(k));
        pushup(k);
    }

    node queryNode(int l, int r, int k = 1)
    {
        if (l <= t[k].l && r >= t[k].r)
            return t[k];
        int mid = (t[k].l + t[k].r) >> 1;
        if (r <= mid)
            return queryNode(l, r, ls(k));
        if (l > mid)
            return queryNode(l, r, rs(k));
        return queryNode(l, r, ls(k)) + queryNode(l, r, rs(k));
    }

    T query(int l, int r, int k = 1)
    {
        return queryNode(l, r, k).w;
    }
};