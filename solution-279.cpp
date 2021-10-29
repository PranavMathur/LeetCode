class Solution {
public:
    int cache[10000];
    int numSquares(int n) {
        cache[0] = 1;
        int currentRoot = 2;
        int currentSquare = 4;
        for (int i = 2; i <= n; i++) {
            if (i == currentSquare) {
                cache[i-1] = 1;
                currentSquare += 2*currentRoot + 1;
                currentRoot += 1;
            }
            else {
                int least = i+1;
                /*int low, high;
                for (low = 1, high = i-1; low <= high; low++, high--) {
                    int attempt = cache[low-1] + cache[high-1];
                    if (attempt < least) {
                        least = attempt;
                    }
                    if (attempt == 2) {
                        least = 2;
                        break;
                    }
                }*/
                for (int j = 1; j < currentRoot; j++) {
                    int a = j*j;
                    int b = i-a;
                    int attempt = cache[a-1] + cache[b-1];
                    if (attempt < least) {
                        least = attempt;
                    }
                }
                cache[i-1] = least;
            }
        }
        return cache[n-1];
    }
};

/*
Solution 1: 1873ms, 5.8MB (5.01%ile, 99.79%ile)
Solution 2: 59ms, 5.9MB (84.60%ile, 90.50%ile)
*/