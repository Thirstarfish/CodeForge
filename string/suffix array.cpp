// 板子内有idx调整，酌情修改
tuple<vec<int>, vec<int>, vec<int>> SA(string &s)
{
    int n = s.size(), m = 127, p = 0;
    s = ' ' + s;
    vec<int> sa(n * 2 + 5), rk(n * 2 + 5), height(n + 1), oldrk(n * 2 + 5), oldsa(n * 2 + 5), cnt(m + 1);

    for (int i = 1; i <= n; i++)
        cnt[rk[i] = s[i]]++;
    for (int i = 1; i <= m; i++)
        cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--)
        sa[cnt[rk[i]]--] = i;
    oldrk = rk;
    for (int i = 1; i <= n; i++)
        if (oldrk[sa[i]] == oldrk[sa[i - 1]])
            rk[sa[i]] = p;
        else
            rk[sa[i]] = ++p;

    for (int w = 1;; w <<= 1, m = p)
    {
        int cur = 0;
        for (int i = n - w + 1; i <= n; i++)
            oldsa[++cur] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > w)
                oldsa[++cur] = sa[i] - w;
        cnt.assign(max(130ll, m + 1), 0);
        for (int i = 1; i <= n; i++)
            cnt[rk[oldsa[i]]]++;
        for (int i = 1; i <= m; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--)
            sa[cnt[rk[oldsa[i]]]--] = oldsa[i];

        oldrk = rk;
        p = 0;
        for (int i = 1; i <= n; i++)
            if (oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
                rk[sa[i]] = p;
            else
                rk[sa[i]] = ++p;
        if (p == n)
            break;
    }
    
    for (int i = 1, k = 0; i <= n; i++)
    {
        if (rk[i] == 0)
            continue;
        if (k)
            --k;
        while (s[i + k] == s[sa[rk[i] - 1] + k])
            ++k;
        height[rk[i]] = k;
    }

    return {sa, rk, height};
}