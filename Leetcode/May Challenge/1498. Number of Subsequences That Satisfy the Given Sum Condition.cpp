class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
         int res = 0, mod = 1000000007;
         int left = 0, right = nums.size() - 1;
        vector<int> previous = {1};
        for (auto i = 1; i <= nums.size(); ++i)
            previous.push_back((previous.back() << 1) % mod);   
                
        sort(begin(nums), end(nums));
        
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                res = (res + previous[right - left++]) % mod;
            }
        }

        return res;
    }
};
