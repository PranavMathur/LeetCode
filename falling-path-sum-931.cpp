#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c) (MIN(MIN((a), (b)), (c)))

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];
        int row[n];
        int tmp[n];
        for (int i = 0; i < n; i++) {
            row[i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j] = matrix[i][j];
            }
            tmp[0] = MIN(tmp[0]+row[0], tmp[0]+row[1]);
            tmp[n-1] = MIN(tmp[n-1]+row[n-2], tmp[n-1]+row[n-1]);
            for (int j = 1; j < n-1; j++) {
                int jv = tmp[j];
                tmp[j] = MIN3(jv+row[j-1], jv+row[j], jv+row[j+1]);
            }
            for (int j = 0; j < n; j++) {
                row[j] = tmp[j];
            }
        }
        int res = row[0];
        for (int i = 1; i < n; i++) {
            res = MIN(res, row[i]);
        }
        return res;
    }
};

/* 8 ms (96.66%ile), 9.4 MB (91.72%ile) */