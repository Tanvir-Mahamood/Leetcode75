class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word, ans = "";
        while(iss>>word)
        {
            if(ans.size() == 0) ans = word;
            else ans  = word + " " + ans;
        }
        return ans;
    }
};