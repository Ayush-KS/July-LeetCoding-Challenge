// Hamming Distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int ans = 0;
        while(x) {
            ans++;
            x &= (x - 1);
        }
        return ans;
    }
};