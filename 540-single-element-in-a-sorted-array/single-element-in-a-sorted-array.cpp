class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp ;

        for(int i : nums) {
            mp[i]++;
        }
        for(auto const& [key,val] : mp) {
            if(val == 1) return key;
        }
        return -1;
    }
};