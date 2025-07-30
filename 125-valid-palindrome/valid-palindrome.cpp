class Solution {
public:
    bool isPalindrome(string s) {
        int a = 0;
        int n = s.length();
        int b = n-1;
        while(a <=b) {
            while(a <b && isalnum(s[a])== 0) a++;
            while(a<b && isalnum(s[b]) == 0)b--;
            if(tolower(s[a]) != tolower(s[b])) 
            {
                return false;
            }
            a++;
            b--;
        }
        return true;
    }
};