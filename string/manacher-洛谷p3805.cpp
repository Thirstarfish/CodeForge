int manacher(const string &S)
{
    string s = " ^#";
    for (auto c : S)
    {
        s += c;
        s += '#';
    }
    s += '$';
    int n = s.size() - 1;
    vec<int> d(n + 1, 1);
    int c = 0, r = 0, ans = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        if (i < r)
            d[i] = min(d[c * 2 - i], r - i);
        while (s[i - d[i]] == s[i + d[i]])
            d[i]++;
        if (i + d[i] > r)
            c = i, r = i + d[i];
        ans = max(ans, d[i] - 1);
    }
    return ans;
}
