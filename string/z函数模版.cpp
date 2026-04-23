    string a, b;
    int n = b.size(), m = a.size();
    vector<int> z(n), p(m);  //z:b与b的每一个后缀的LCP长度   p:b与a的每一个后缀的LCP长度
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && b[z[i]] == b[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    while (p[0] < m && p[0] < n && a[p[0]] == b[p[0]])
        p[0]++;
    for (int i = 1, l = 0, r = 0; i < m; i++)
    {
        if (i <= r)
            p[i] = min(z[i - l], r - i + 1);
        while (i + p[i] < m && p[i] < n && b[p[i]] == a[i + p[i]])
            p[i]++;
        if (i + p[i] - 1 > r)
        {
            l = i;
            r = i + p[i] - 1;
        }
    }