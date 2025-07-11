class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i =0;i<n;i++) {
            int rest = target - nums[i];
            if(mp.count(rest)){
                return {mp[rest],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};