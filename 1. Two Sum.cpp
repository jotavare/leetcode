class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int arraySize = nums.size();

        for (int i = 0; i < arraySize - 1; i++) {
            for (int j = i + 1; j < arraySize; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};