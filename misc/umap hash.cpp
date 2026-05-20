struct chash
{
    static uint64_t u64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t rg = chrono::steady_clock::now().time_since_epoch().count();
        return u64(x + rg);
    }

    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        static const uint64_t rg = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t h1 = u64(p.first + rg);
        uint64_t h2 = u64(p.second + rg);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15 + (h1 << 6) + (h1 >> 2));
    }

    template <typename Range>
    size_t operator()(const Range &arr) const
    {
        static const uint64_t rg = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t hash = 0;
        for (auto x : arr)
            hash ^= u64(x + rg) + 0x9e3779b97f4a7c15 + (hash << 6) + (hash >> 2);
        return hash;
    }
};
