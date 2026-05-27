class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> f1(26, 0), f2(26, 0);
        if(word1.size() != word2.size()) return false;

        for(int i=0; i<word1.size(); i++) {
            char ch1 = word1[i];
            char ch2 = word2[i];
            f1[ch1-'a']++;
            f2[ch2-'a']++;
        }

        for(int i=0; i<26; i++) {
            if(f1[i] == 0 && f2[i] != 0) return false;
            if(f2[i] == 0 && f1[i] != 0) return false;
        }

        unordered_map<int, int> mp1, mp2;
        for(int i=0; i<26; i++) {
            mp1[f1[i]]++;
            mp2[f2[i]]++;
        }

        if(mp1 == mp2) return true;
        else return false;
    }
};