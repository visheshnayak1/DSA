class Solution {
public:
    void createSubset(vector<int>&nums , int index, vector<vector<int>>& ans, vector<int>& subset) {
        if(index == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        createSubset(nums,index+1,ans , subset);

        subset.pop_back();
        createSubset(nums,index+1,ans ,subset);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        createSubset(nums, 0 , ans, subset);
        return ans;
        
    }
};