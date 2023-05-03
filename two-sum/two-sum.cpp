class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            int n = nums.size();
            vector<pair<int, int>> sortedNums(n); // num, idx

            for (int i = 0; i < n; i++)
            {
                sortedNums[i] = { nums[i], i };
            }
            sort(sortedNums.begin(), sortedNums.end());

            vector<int> res(2);
            int lo = 0;
            int hi = n - 1;

            while (true)
            {
                int sum = sortedNums[lo].first + sortedNums[hi].first;
                if (sum == target)
                {
                    res[0] = sortedNums[lo].second;
                    res[1] = sortedNums[hi].second;
                    return res;
                }
                (sum < target) ? lo++ : hi--;
            }
        }
};