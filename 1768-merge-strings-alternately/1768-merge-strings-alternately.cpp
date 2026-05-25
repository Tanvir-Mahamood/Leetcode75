class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i;
        for(i=0; i<min(word1.size(), word2.size()); i++) {
            ans += word1[i];
            ans += word2[i];
        }
        if(i <= word1.size()) {
            for(; i<word1.size(); i++) {
                ans += word1[i];
            }
        }
        if(i <= word2.size()) {
            for(; i<word2.size(); i++) {
                ans += word2[i];
            }
        }
        return ans;
    }
};