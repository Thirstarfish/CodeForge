// 在文本串 txt 中查找模式串 ptn，返回所有成功匹配的位置（ptn[0] 在 txt 中的下标）
vector<int> kmp(const string &txt, const string &ptn)
{
    int n = ptn.size();
    vector<int> pi(n);
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        char b = ptn[i];
        while (cnt && ptn[cnt] != b)
            cnt = pi[cnt - 1];
        if (ptn[cnt] == b)
            cnt++;
        pi[i] = cnt;
    }

    vector<int> pos;
    cnt = 0;
    for (int i = 0; i < txt.size(); i++)
    {
        char b = txt[i];
        while (cnt && ptn[cnt] != b)
            cnt = pi[cnt - 1];
        if (ptn[cnt] == b)
            cnt++;
        if (cnt == n)
        {
            pos.pb(i - n + 1);
            cnt = pi[cnt - 1];
        }
    }
    return pos;
}
