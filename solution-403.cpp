class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        int length = stones.size();
        bool cross[length];
        for (int i = 0; i < length; i++) cross[i] = false;
        cross[0] = true;
        cross[1] = true;
        unordered_set<int> jumps[length];
        jumps[0].insert(1);
        jumps[1].insert(1);
        jumps[1].insert(2);
        
        for (int i = 2; i < length; i++) {
            int target = stones[i];
            for (int j = i - 1; j >= 0; j--) {
                int previous = stones[j];
                if (cross[j]) {
                    int distance = target - previous;
                    if (jumps[j].find(distance) != jumps[j].end()) {
                        cross[i] = true;
                        jumps[i].insert(distance - 1);
                        jumps[i].insert(distance);
                        jumps[i].insert(distance + 1);
                    }
                }
            }
        }
        
        return cross[length - 1];
    }
};
