class Solution {
public:
    int tribonacci(int n) {
        int a0 = 0, a1 = 1, a2 = 1, s;
        if(n == 0) return a0;
        else if(n < 3) return a1;
        for(int i=3; i<=n; i++) {
            s = a0 + a1 + a2;
            a0 = a1;
            a1 = a2;
            a2 = s;
        }
        return s;
    }
};