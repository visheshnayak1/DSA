// class Solution {
// public:
// typedef long long ll;
//     long long minCost(vector<int>& basket1, vector<int>& basket2) {
//         int n = basket1.size();
//         int s1 = accumulate(basket1.begin(),basket1.end(),0);
//         int s2 = accumulate(basket2.begin(),basket2.end(),0);

//         int diff;
//         if(s1>s2) diff = s1 -s2;
//         else diff = s2 - s1;

//         int tar = diff /2;
//         if(tar < 1) {
//             return -1;
//         }
        
//         for(int i  = 0; i< n ;i ++) {
//             for(int j = 0 ; j < n ;j++) {
//                 if(abs(basket1[i]-basket2[i]) == tar) {
//                     return 1ll * min(basket1[i],basket2[i]);
//                 }
//             }
//         }
//         return 1ll * 0;
//     }
// };
class Solution {
public:
typedef long long ll;
    long long minCost(vector<int>& basket1 , vector<int>& basket2){
        unordered_map<int,int> total_count;
        for(int fruit : basket1) total_count[fruit]++;
        for(int fruit : basket2) total_count[fruit]++;

        ll min_val = LLONG_MAX;
        for(auto const&[fruit, count] : total_count) {
            if(count % 2 != 0) return -1;
            min_val = min(min_val, (ll) fruit);
        }
        vector<ll> fruits_to_swap;
        unordered_map<int,int> count1;
        for(int fruit : basket1) count1[fruit]++;

        for(auto const& [fruit ,total_count] :  total_count) {
            int diff = count1[fruit] - (total_count / 2);
            for(int i = 0; i < abs(diff); ++i) {
                fruits_to_swap.push_back(fruit);
            }
        }

        sort(fruits_to_swap.begin(),fruits_to_swap.end());

        ll total_cost = 0;
        int swaps_to_make = fruits_to_swap.size() /2;
        for(int i =0 ; i < swaps_to_make ; ++i) {
            total_cost += min(fruits_to_swap[i],2 * min_val);
        }

        return total_cost;
    }
};