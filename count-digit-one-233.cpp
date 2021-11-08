#include <cmath>

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        while (n > 0) {
            int mag = log10(n);
            int tens = pow(10, mag);
            int first = n/tens;
            int rest = n - first*tens;
            count += first * (mag * pow(10, mag-1));
            if (first != 1) {
                count += pow(10, mag);
            }
            else {
                count += rest + 1;
            }
            n = rest;
        }
        return count;
    }
};
