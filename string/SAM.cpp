struct SAM
{
    static constexpr int sz = 26;
    struct node
    {
        int len;
        int link;
        array<int, sz> next;
        node() : len{}, link{}, next{} {}
    };
    vector<node> t;

    SAM() { init(); }

    void init()
    {
        t.assign(2, node());
        t[0].next.fill(1);
        t[0].len = -1;
    }

    int newnode()
    {
        t.emplace_back();
        return t.size() - 1;
    }

    int extend(int p, int c)
    {
        if (t[p].next[c])
        {
            int q = t[p].next[c];
            if (t[q].len == t[p].len + 1)
                return q;
            int r = newnode();
            t[r].len = t[p].len + 1;
            t[r].link = t[q].link;
            t[r].next = t[q].next;
            t[q].link = r;
            while (t[p].next[c] == q)
            {
                t[p].next[c] = r;
                p = t[p].link;
            }
            return r;
        }
        int cur = newnode();
        t[cur].len = t[p].len + 1;
        while (!t[p].next[c])
        {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        t[cur].link = extend(p, c);
        return cur;
    }

    int extend(int p, char c, char offset = 'a') { return extend(p, (int)c - offset); }
    int next(int p, int x) { return t[p].next[x]; }
    int next(int p, char c, char offset = 'a') { return next(p, (int)c - offset); }
    int link(int p) { return t[p].link; }
    int len(int p) { return t[p].len; }
    int size() { return t.size(); }
};