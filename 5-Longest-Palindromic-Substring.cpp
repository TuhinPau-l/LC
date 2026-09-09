class Solution {
public:
    string longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<int> prev(m + 1, 0);
        vector<int> cur(m + 1, 0);

        int ans = 0;
        int endIndex = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(str1[i-1] == str2[j-1]) {
                    cur[j] = 1 + prev[j-1];

                    // Check whether this common substring
                    // corresponds to the same position in s
                    if(cur[j] > ans && i - cur[j] == n - j) {
                        ans = cur[j];
                        endIndex = i;
                    }
                }
                else {
                    cur[j] = 0;
                }
            }

            prev = cur;
        }

        return str1.substr(endIndex - ans, ans);
    }

    string longestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        return longestCommonSubstr(s, t);
    }
};