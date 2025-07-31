class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        

        unordered_set<int> result_ors;
        unordered_set<int> current_ors;

        for(int x : arr) {
            unordered_set<int> next_ors;
            next_ors.insert(x);
            for(int y : current_ors) {
                next_ors.insert(x | y);
            }

            current_ors = next_ors;
            result_ors.insert(next_ors.begin(),next_ors.end());
        }
        
        return result_ors.size();
    }
};