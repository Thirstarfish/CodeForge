uint64_t hqr()
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    seed ^= std::random_device{}();
    static thread_local std::mt19937_64 generator(seed);
    return generator();
}

random_device rd;
mt19937 g(rd());
shuffle(a.begin() + 1, a.end(), g); // 随机打乱数组