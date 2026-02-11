vector<int> eulerSieve(int n)
{
    vector<char> isPrime(n + 1, 1); // 标记数组，初始全部设为true
    vector<int> primes;             // 存储筛选出的质数

    isPrime[0] = isPrime[1] = 0; // 0和1不是质数

    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i); // i是质数，加入质数列表
        }

        // 用当前已得到的质数去筛i的倍数
        for (int j = 0; j < primes.size() && i * primes[j] <= n; ++j)
        {
            isPrime[i * primes[j]] = 0; // 标记i*primes[j]为非质数

            // 关键步骤：保证每个合数只被它的最小质因数筛掉
            if (i % primes[j] == 0)
            {
                break;
            }
        }
    }

    return primes;
}



// 线性处理所有数字的最小质因子
template <typename T>
vector<T> preprocess_min_prime(T n)
{
    vector<T> min_prime(n + 1); // 存储最小质因子
    vector<T> primes;           // 存储所有质数

    // 初始化，所有数的最小质因子设为自身
    for (T i = 0; i <= n; i++)
    {
        min_prime[i] = i;
    }

    // 线性筛法
    for (T i = 2; i <= n; i++)
    {
        if (min_prime[i] == i)
        { // i 是质数
            primes.push_back(i);
        }

        // 用当前质数 primes[j] 去筛合数
        for (size_t j = 0; j < primes.size(); j++)
        {
            T p = primes[j];
            if (p * i > n)
                break; // 超过范围，退出

            min_prime[p * i] = p; // 标记合数 p*i 的最小质因子为 p

            if (i % p == 0)
            { // 保证每个合数只被最小质因子筛一次
                break;
            }
        }
    }

    return min_prime;
}