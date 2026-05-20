string s;
int n = s.size();
s += s;
int i = 0, j = 1;
while (i < n && j < n)
{
    int k = 0;
    while (k < n && s[i + k] == s[j + k])
        k++;
    if (k == n)
        break;
    if (s[i + k] > s[j + k])
        i += k + 1;
    else
        j += k + 1;
    if (i == j)
        j++;
}

// 答案：s.substr(min(i, j), n)