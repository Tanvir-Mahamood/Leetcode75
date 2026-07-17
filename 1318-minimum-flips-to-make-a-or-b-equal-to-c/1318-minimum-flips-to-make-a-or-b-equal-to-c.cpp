class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a || b || c) {
            int a_bit = a & 1;
            int b_bit = b & 1;
            int c_bit = c & 1;
            int or_bit = a_bit | b_bit;
            int xor_bit = a_bit ^ b_bit;
            if(or_bit == 0 && c_bit == 1) cnt += 1;
            else if(or_bit == 1 && c_bit == 0 && xor_bit == 0) cnt += 2;
            else if(or_bit == 1 && c_bit == 0 && xor_bit == 1) cnt += 1;

            a = (a>>1);
            b = (b>>1);
            c = (c>>1);
        }
        return cnt;
    }
};