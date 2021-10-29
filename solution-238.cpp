class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length, 1);
        int left[length];
        int right[length];
        for (int i = 0; i < length; i++) {
            left[i] = right[i] = 1;
        }
        int i, j;
        for (i = 1, j = length - 2; i < length; i++, j--) {
            left[i] = left[i-1] * nums[i-1];
            right[j] = right[j+1] * nums[j+1];
        }
        for (int i = 0; i < length; i++) {
            result[i] = left[i] * right[i];
        }
        return result;
    }
};

/*
24 ms (68.16%ile), 24.4MB (50.17%ile)
*/