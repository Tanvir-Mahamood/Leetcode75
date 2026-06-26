/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1 ,high = n;
        while(low <= high) {
            int midd = low + (high - low) / 2;

            if(guess(midd) == 0) return midd;
            else if(guess(midd) == -1) high = midd - 1;
            else low = midd + 1;
        }
        return -1;
    }
};