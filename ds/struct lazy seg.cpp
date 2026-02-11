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
            lazytag operator+(const lazytag &other) const
            {
                return lazytag(mul * other.mul, add * other.mul + other.add);
            }
        } lazy;

        node operator+(const node &other) const
        {
            return {l, other.r, w + other.w, lazytag()};
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

    seg(const vector<T> &in)
    {
        int n = in.size() - 1;
        w = in;
        t.resize((n << 2) + 1);
        build(1, n);
    }

    inline void apply(int k, const typename node::lazytag &lz)
    {
        t[k].w = t[k].w * lz.mul + (t[k].r - t[k].l + 1) * lz.add;
        t[k].lazy = t[k].lazy + lz;
    }

    inline void pushup(int k)
    {
        t[k] = t[ls(k)] + t[rs(k)];
    }

    inline void pushdown(int k)
    {
        if (t[k].lazy.mul == 1 && t[k].lazy.add == 0)
            return;
        apply(ls(k), t[k].lazy);
        apply(rs(k), t[k].lazy);
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
            apply(k, lz);
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

    T query(int l, int r, int k = 1)
    {
        return queryNode(l, r, k).w;
    }
};

using lz = seg<int>::node::lazytag;   //套别的数据类型时需要修改