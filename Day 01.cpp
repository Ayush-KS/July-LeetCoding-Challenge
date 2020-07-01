// Arranging Coins

class Solution {
public:
    int arrangeCoins(int n) {
        int lo = 1;
        int hi = n;
        while(lo <= hi) {
            long long int mid = lo + (hi - lo) / 2;
            if(((mid)*(mid+1))/2 > n) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }
};