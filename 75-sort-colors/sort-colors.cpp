class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n; i++) {
            cout<<nums[i];
        }
    }
};