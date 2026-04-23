int l = 1, r = 1e9, ans = inf;
while (r - l > 3)
{
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    if (calc(m1, i) >= calc(m2, i))
        l = m1;
    else
        r = m2;
}
for (int j = l; j <= r; j++)
    ans = min(ans, calc(j, i));