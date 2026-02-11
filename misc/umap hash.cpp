struct chash
{
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 2);
    }
};

struct chash
{
    std::size_t operator()(const std::array<int, 2> &arr) const
    {
        return std::hash<int>{}(arr[0]) ^ (std::hash<int>{}(arr[1]) << 2);
    }
};