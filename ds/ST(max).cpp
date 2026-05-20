struct ST
{
    int n, k;
    vector<int> in;
    vector<vector<int>> mx;

    ST(vector<int> IN)
    {
        n = IN.size() - 1, k = __lg(n), in = IN;
        mx.resize(k + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++)
            mx[0][i] = in[i];
        for (int i = 0, t = 1; i < k; i++, t <<= 1)
        {
            const int T = n - (t << 1) + 1;
            for (int j = 1; j <= T; j++)
                mx[i + 1][j] = max(mx[i][j], mx[i][j + t]);
        }
    }

    int ask(int l, int r)
    {
        int k = __lg(r - l + 1);
        return max(mx[k][l], mx[k][r - (1 << k) + 1]);
    }
};