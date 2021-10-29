class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 1;
        int coef = 2;
        int residue = 1;
        while (residue < n) {
            if ((n - residue) % coef == 0) {
                count += 1;
            }
            residue += coef;
            coef++;
        }
        return count;
    }
};
/* 4 ms (80%ile), 5.8 MB (72%ile) */