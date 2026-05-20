string s, t; // z: t 与 t 的每一个后缀的 LCP 长度  p: b 与 a 的每一个后缀的 LCP 长度数组
int n = t.size(), m = s.size();
vector<int> z(n);
int l = 0, r = 0;
z[0] = n;
for (int i = 1; i < n; i++)
{
    if (i < r)
        z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && t[z[i]] == t[i + z[i]])
        z[i]++;
    if (i + z[i] > r)
        l = i, r = i + z[i];
}
vector<int> p(m);
while (p[0] < n && p[0] < m && s[p[0]] == t[p[0]])
    p[0]++;
l = 0, r = p[0];
for (int i = 1; i < m; i++)
{
    if (i < r)
        p[i] = min(r - i, z[i - l]);
    while (i + p[i] < m && t[p[i]] == s[i + p[i]])
        p[i]++;
    if (i + p[i] > r)
        l = i, r = i + p[i];
}