struct ahocorasick
{
    static constexpr int sz = 26;
    struct node
    {
        int len;
        int link;
        array<int, sz> next;
        node() : len{0}, link{0}, next{} {}
    };
    vec<node> t;

    void init()
    {
        t.assign(2, node());
        t[0].next.fill(1);
        t[0].len = -1;
    }

    ahocorasick() { init(); };

    int newnode()
    {
        t.emplace_back();
        return t.size() - 1;
    }

    void add(const string &a)
    {
        int p = 1;
        for (auto c : a)
        {
            int x = c - 'a';
            if (t[p].next[x] == 0)
            {
                t[p].next[x] = newnode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
    }

    void work()
    {
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < sz; i++)
            {
                if (t[x].next[i] == 0)
                    t[x].next[i] = t[t[x].link].next[i];
                else
                {
                    t[t[x].next[i]].link = t[t[x].link].next[i];
                    q.push(t[x].next[i]);
                }
            }
        }
    }

    int next(int p, int x) { return t[p].next[x]; }
    int link(int p) { return t[p].link; }
    int len(int p) { return t[p].len; }
    int size() { return t.size(); }
};