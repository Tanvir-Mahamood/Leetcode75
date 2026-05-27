class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0, maxAltitude = -101;
        for(int g: gain) {
            altitude += g;
            maxAltitude = max(maxAltitude, altitude);
        }
        return max(maxAltitude, 0);
    }
};