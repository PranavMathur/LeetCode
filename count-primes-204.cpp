class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        bool sieve[n];
        for (int i = 0; i < n; i++) sieve[i] = true;
        sieve[0] = sieve[1] = false;
        int count = 0;
        for (int current = 2; current < n; current++) {
            if (!sieve[current]) continue;
            count++;
            for (int mult = current*2; mult < n; mult += current) {
                sieve[mult] = false;
            }
        }
        return count;
    }
};
