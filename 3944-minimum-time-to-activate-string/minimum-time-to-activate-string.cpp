// class Solution {
// public:
//     int counter(int n) {
//         return ((n*(n+1))/2);
//     }
//     int minTime(string s, vector<int>& order, int k) {
//         int l = s.length();
//         int n = order.size();
//         if((l*(l+1))/2 < k) return -1;

//         int totalSubString = counter(l);

//         int t = 0 ; 
//         for(char c : s) {
//             int k = order[t];
//             string temp;
//             char1 = '*';
//             temp = char1;
//             char1 = c;
//             c = temp;
//             // swap(s(k),'*');

//             int continousCharCount = 0;
//             for(char c:s) {
//                 if(c != '*'){
//                     continousCharCount++;
//                 }else if(c == "*") {
//                     continousCharCount == 0;
//                 }
//             }
//             int invalidSubString = counter(continoutsCharCount);
            
//         }

//         return toatlSubString - invalidSubString;
        
//     }
// };
class Solution {
public:
    long long counter(long long n) {
        return (n * (n + 1)) / 2;
    }

    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        long long totalSubstrings = counter(n);
        long long invalidSubstrings = totalSubstrings;

        set<int> starPositions;
        string nostevanik = s;  

        starPositions.insert(-1);  
        starPositions.insert(n);

        for (int t = 0; t < n; t++) {
            int pos = order[t];
            starPositions.insert(pos);

           
            auto it = starPositions.find(pos);
            int prevStar = *prev(it);
            int nextStar = *next(it);

            
            long long oldLen = nextStar - prevStar - 1;
            long long leftLen = pos - prevStar - 1;
            long long rightLen = nextStar - pos - 1;

            invalidSubstrings -= counter(oldLen);
            invalidSubstrings += counter(leftLen);
            invalidSubstrings += counter(rightLen);

            long long validSubstrings = totalSubstrings - invalidSubstrings;

            if (validSubstrings >= k) {
                return t;
            }
        }

        return -1;
    }
};

