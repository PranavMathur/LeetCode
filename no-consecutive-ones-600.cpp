class Solution {
public:
    int findIntegers(int n) {
        int fib_len = log2(n) + 2;
        int fibs[fib_len];
        fibs[0] = 1;
        fibs[1] = 2;
        int a = 1;
        int b = 2;
        for (int i = 2; i < fib_len; i++) {
            int c = a + b;
            a = b;
            b = c;
            fibs[i] = b;
        }
        int count = 0;
        while (n >= 0) {
            if (n <= 1) {
                count += n + 1;
                break;
            }
            if (n == 3) {
                count += 3;
                break;
            }
            int mag = (int)log2(n);
            count += fibs[mag];
            if (n & (int)pow(2, mag - 1)) {
                count += fibs[mag - 1];
                break;
            }
            else {
                n -= pow(2, mag);
            }
        }
        return count;
    }
};
//0 ms (100%ile), 5.9 MB (69%ile)
