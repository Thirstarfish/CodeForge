string s;
int n = s.size();
s = ' ' + s;
vector<int> pi(n + 1); // 最长相等真前后缀的长度
int cnt = 0;
for (int i = 2; i <= n; i++)
{
    char b = s[i];
    while (cnt && s[cnt + 1] != b)
        cnt = pi[cnt];
    if (s[cnt + 1] == b)
        cnt++;
    pi[i] = cnt;
}
