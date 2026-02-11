ll fpow(ll a, ll b)
{
    ll ans = 1;
    a %= mod; 
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

ll inv(int b) { return fpow(b, mod - 2) % mod; }

vector<ll> jc(N), ijc(N);

void initc(int n)
{
    jc[0] = 1;
    for (int i = 1; i < n; i++)
        jc[i] = jc[i - 1] * i % mod;
    ijc[n - 1] = inv(jc[n - 1]); // 使用您的inv函数求逆元
    for (int i = n - 2; i >= 0; i--)
        ijc[i] = ijc[i + 1] * (i + 1) % mod;
}

// 查询组合数C(n, k)
ll C(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return jc[n] * ijc[k] % mod * ijc[n - k] % mod;
}

ll P(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return jc[n] * ijc[n - k] % mod;
}