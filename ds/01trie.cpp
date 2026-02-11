struct trie
{
    struct node
    {
        aii cnt, pts;
        node()
        {
            cnt[0] = cnt[1] = 0;
            pts[0] = pts[1] = 0;
        }
    };
    vec<node> tr;
    int cur;
    trie()
    {
        tr.resize(2);
        cur = 1;
    }

    void insert(int x)
    {
        int pt = 1;
        for (int j = 30; j >= 0; j--)
        {
            int bit = (x >> j) & 1;
            if (!tr[pt].pts[bit])
            {
                cur++;
                if (cur >= tr.size())
                    tr.resize(cur + 1);
                tr[pt].pts[bit] = cur;
            }
            tr[pt].cnt[bit]++;
            pt = tr[pt].pts[bit];
        }
    }

    int query(int x, int k)
    {
        int pt = 1, ans = 0;
        for (int j = 30; j >= 0; j--)
        {
            int bit = (x >> j) & 1;
            if (tr[pt].cnt[bit] < k)
            {
                k -= tr[pt].cnt[bit];
                bit ^= 1;
                ans |= (1 << j);
            }
            pt = tr[pt].pts[bit];
        }
        return ans;
    }
};