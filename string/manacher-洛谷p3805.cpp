int manacher(const string &S)
{
    s = "$#";
    for (auto &c : S)
    {
        s += c;
        s += '#';
    }
    int n = s.size() - 1;
    s += '^';
    vector<int> d(n + 1);
    int c = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i < r)
            d[i] = min(d[2 * c - i], r - i);
        while (s[i + d[i]] == s[i - d[i]])
            d[i]++;
        if (i + d[i] > r)
            c = i, r = i + d[i];
    }
    return ranges::max(d) - 1;
}
