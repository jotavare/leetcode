class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int arraySize = nums.size();
        int zeros = 0;

        for (int i = 0; i < arraySize;) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                zeros++;
                arraySize--;
            } else
                i++;
        }

        for (int i = 0; i < zeros; i++)
            nums.push_back(0);
    }
};