template <typename T>
struct seg
{
    struct node
    {
        int l, r;
        T w, lazy;
        node operator+(const node &other) const
        {
            node res;
            res.l = l;
            res.r = other.r;
            res.w = w + other.w;
            res.lazy = 0;
            return res; // lazy不参与合并，重置为0
        }
    };
    vector<T> w;
    vector<node> t;

    inline int ls(int k) { return k << 1; }
    inline int rs(int k) { return k << 1 | 1; }
    inline void pushup(int k) { t[k] = t[ls(k)] + t[rs(k)]; }

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

    inline void update(int k, T lazy)
    {
        t[k].w += (t[k].r - t[k].l + 1) * lazy;
        t[k].lazy += lazy;
    }

    inline void pushdown(int k)
    {
        if (t[k].lazy == 0)
            return;
        update(ls(k), t[k].lazy);
        update(rs(k), t[k].lazy);
        t[k].lazy = 0;
    }

    void build(int l, int r, int k = 1)
    {
        if (l == r)
        {
            t[k] = {l, r, w[l], 0};
            return;
        }
        t[k] = {l, r};
        int mid = l + r >> 1;
        build(l, mid, ls(k));
        build(mid + 1, r, rs(k));
        pushup(k);
    }

    void modify(int l, int r, T v, int k = 1)
    {
        if (l <= t[k].l && r >= t[k].r)
        {
            update(k, v);
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) >> 1;
        if (l <= mid)
            modify(l, r, v, ls(k));
        if (r > mid)
            modify(l, r, v, rs(k));
        pushup(k);
    }

    int queryL(int k, int x, T ax)
    {
        int mid = t[k].l + t[k].r >> 1;
        if (t[k].w < ax)
            return t[k].r + 1;
        if (t[k].l == t[k].r)
            return t[k].l;
        pushdown(k);
        if (mid < x)
            return queryL(rs(k), x, ax);
        int ans = queryL(ls(k), x, ax);
        if (ans == mid + 1)
            ans = queryL(rs(k), x, ax);
        return ans;
    }

    int queryR(int k, int x, T ax)
    {
        if (t[k].w < ax)
            return t[k].l - 1;
        if (t[k].l == t[k].r)
            return t[k].r;
        pushdown(k);
        int mid = (t[k].l + t[k].r) >> 1;
        if (x <= mid)
            return queryR(ls(k), x, ax);
        int ans = queryR(rs(k), x, ax);
        if (ans == mid)
            ans = queryR(ls(k), x, ax);
        return ans;
    }

    node queryNode(int l, int r, int k = 1)
    {
        if (l <= t[k].l && r >= t[k].r)
            return t[k];
        pushdown(k);
        int mid = (t[k].l + t[k].r) >> 1;
        if (r <= mid)
            return queryNode(l, r, ls(k));
        if (l > mid)
            return queryNode(l, r, rs(k));
        return queryNode(l, r, ls(k)) + queryNode(l, r, rs(k));
    }

    T query(int l, int r, int k = 1) { return queryNode(l, r, k).w; }
};