class Solution {
private:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        else return false;
    }
public:
    int maxVowels(string s, int k) {
        int numVowel = 0, maxNumVowel;
        for(int i=0; i<k; i++) {
            if(isVowel(s[i])) {
                numVowel++;
            }
        }
        maxNumVowel = numVowel;
        for(int i=k; i<s.size(); i++) {
            char removing = s[i-k]; // character to be removed from the window
            char adding = s[i]; // character to be added to the window
            if(isVowel(removing)) numVowel--;
            if(isVowel(adding)) numVowel++;

            maxNumVowel = max(maxNumVowel, numVowel);
        }
        return maxNumVowel;
    }
};