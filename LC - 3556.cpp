class Solution {
public:
    bool isPrime(long long n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (long long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        set<long long, greater<long long>> primes;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            long long num = 0;
            for (int j = i; j < n; ++j) {
                num = num * 10 + (s[j] - '0');
                if (isPrime(num)) {
                    primes.insert(num);
                }
            }
        }
        
        long long sum = 0;
        int count = 0;
        for (long long p : primes) {
            sum += p;
            if (++count == 3) break;
        }
        
        return sum;
    }
};
