vector<int> kmp(string txt, string ptn)
{
    int n = ptn.size(), m = txt.size();
    txt = ' ' + txt;
    ptn = ' ' + ptn;
    vec<int> pi(n + 1);
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        char b = ptn[i];
        while (cnt && ptn[cnt + 1] != b)
            cnt = pi[cnt];
        if (ptn[cnt + 1] == b)
            cnt++;
        pi[i] = cnt;
    }
    vec<int> ans;
    cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        char b = txt[i];
        while (cnt && ptn[cnt + 1] != b)
            cnt = pi[cnt];
        if (ptn[cnt + 1] == b)
            cnt++;
        if (cnt == n)
        {
            cnt = pi[cnt];
            ans.pb(i - n + 1);
        }
    }
    return ans;
}