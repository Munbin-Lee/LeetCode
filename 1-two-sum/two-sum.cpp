class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> sortedNums(n);

        for (int i = 0; i < n; i++) {
            sortedNums[i] = {nums[i], i};
        }

        sort(sortedNums.begin(), sortedNums.end());

        int lo = 0;
        int hi = n - 1;

        while (true) {
            int sum = sortedNums[lo].first + sortedNums[hi].first;
            if (sum == target) {
                return {sortedNums[lo].second, sortedNums[hi].second};
            }

            (sum < target) ? lo++ : hi--;
        }
    }
};