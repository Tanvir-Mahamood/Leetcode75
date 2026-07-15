class Solution {
private:
    vector<string> keyboard = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    void helper(string &digits, int idx, string mother) {
        if(idx == digits.size()) {
            ans.push_back(mother);
            return;
        }

        int keyPressed = digits[idx] - '0';
        for(char ch: keyboard[keyPressed - 2]) {
            string curr = mother + ch;
            helper(digits, idx+1, curr);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        helper(digits, 0, "");
        return ans;
    }
};