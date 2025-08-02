class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp ;
        int n = nums.size();
        for(int num : nums) {
            mp[num]++;
        }
        int maxi = INT_MIN;
        for(auto num : mp) {
            if(num.second > n/2) {
                maxi = num.first;
            }
        }
        return maxi;
    }
};