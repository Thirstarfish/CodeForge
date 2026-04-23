vector<int> eulerSieve(int n)
{
    vector<char> isPrime(n + 1, 1);
    vector<int> primes;            
    isPrime[0] = isPrime[1] = 0; 
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] <= n; ++j)
        {
            isPrime[i * primes[j]] = 0; 
            if (i % primes[j] == 0)
                break;
        }
    }
    return primes;
}

template <typename T>
vector<T> preprocess_min_prime(T n)
{
    vector<T> min_prime(n + 1); 
    vector<T> primes;          
    for (T i = 0; i <= n; i++)
        min_prime[i] = i;
    for (T i = 2; i <= n; i++)
    {
        if (min_prime[i] == i)
            primes.push_back(i);
        for (size_t j = 0; j < primes.size(); j++)
        {
            T p = primes[j];
            if (p * i > n)
                break; 
            min_prime[p * i] = p; 
            if (i % p == 0)
                break;
        }
    }
    return min_prime;
}