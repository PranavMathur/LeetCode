class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int count = 0;
        int length = nums.size();
        for (int pos = 0; pos < 30; pos++) {
            int ones = 0;
            for (int i = 0; i < length; i++) {
                ones += nums[i] & 1;
                nums[i] >>= 1;
            }
            count += ones * (length - ones);
        }
        return count;
    }
};
/44 ms (82.80%ile), 19.1 MB, (53.78%ile)
