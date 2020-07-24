// Single Number III

var singleNumber = function(nums) {
    var xor = 0;
    nums.forEach(function(value) {
        xor ^= value;
    });
    
    var part = xor&(~(xor - 1));
    
    var ans = Array(2).fill(0);
    
    nums.forEach(function(value) {
        if(value & part) {
            ans[0] ^= value;
        } else {
            ans[1] ^= value;
        }
    })
    
    return ans;
};