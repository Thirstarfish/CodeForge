template <typename T>
struct seg
{
    struct node
    {
        int l, r;
        T w;
        struct lazytag
        {
            T mul, add; // x -> x * mul + add
            lazytag(T _mul = 1, T _add = 0) : mul(_mul), add(_add) {}
            lazytag operator+(const lazytag &other) const { return lazytag(mul * other.mul, add * other.mul + other.add); }
        } lazy;

        node operator+(const node &other) const { return {l, other.r, w + other.w, lazytag()}; }
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

    seg(const vector<T> &in)
    {
        int n = in.size() - 1;
        w = in;
        t.resize((n << 2) + 1);
        build(1, n);
    }

    inline void update(int k, const typename node::lazytag &lz)
    {
        t[k].w = t[k].w * lz.mul + (t[k].r - t[k].l + 1) * lz.add;
        t[k].lazy = t[k].lazy + lz;
    }

    inline void pushdown(int k)
    {
        if (t[k].lazy.mul == 1 && t[k].lazy.add == 0)
            return;
        update(ls(k), t[k].lazy);
        update(rs(k), t[k].lazy);
        t[k].lazy = typename node::lazytag();
    }

    void build(int l, int r, int k = 1)
    {
        if (l == r)
        {
            t[k] = {l, r, w[l], typename node::lazytag()};
            return;
        }
        int mid = (l + r) >> 1;
        t[k] = {l, r, 0, typename node::lazytag()};
        build(l, mid, ls(k));
        build(mid + 1, r, rs(k));
        pushup(k);
    }

    void modify(int l, int r, const typename node::lazytag &lz, int k = 1)
    {
        if (l <= t[k].l && t[k].r <= r)
        {
            update(k, lz);
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) >> 1;
        if (l <= mid)
            modify(l, r, lz, ls(k));
        if (r > mid)
            modify(l, r, lz, rs(k));
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

using lz = seg<int>::node::lazytag; // 套别的数据类型时需要修改