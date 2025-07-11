#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int MOD = 1'000'000'007;
public:
    int countPartitions(vector<int>& nums, int k) {

        vector<int> doranisvek = nums;               

        int n = nums.size();
        vector<int> dp(n + 1), pref(n + 1);
        dp[0] = pref[0] = 1;                         

        deque<int> dqMin, dqMax;                    
        int L = 0;                                   

        for (int R = 0; R < n; ++R) {
            while (!dqMin.empty() && nums[dqMin.back()] >= nums[R]) dqMin.pop_back();
            while (!dqMax.empty() && nums[dqMax.back()] <= nums[R]) dqMax.pop_back();
            dqMin.push_back(R);
            dqMax.push_back(R);

            while (!dqMin.empty() && !dqMax.empty()
                   && nums[dqMax.front()] - nums[dqMin.front()] > k) {
                if (dqMin.front() == L) dqMin.pop_front();
                if (dqMax.front() == L) dqMax.pop_front();
                ++L;
            }

            long long val = pref[R] - (L ? pref[L-1] : 0);
            if (val < 0) val += MOD;
            dp[R+1] = (int)val;
            pref[R+1] = (pref[R] + dp[R+1]) % MOD;
        }
        return dp[n];
    }
};