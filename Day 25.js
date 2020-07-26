// Find Minimum in Rotated Sorted Array II

var findMin = function(nums) {
    var si = 0;
    var ei = nums.length - 1;
    
    while(si < ei) {
        var mid = Math.floor(si + (ei - si) / 2);
        if(nums[mid] < nums[ei]) {
            ei = mid;
        } else if(nums[mid] > nums[ei]) {
            si = mid + 1;
        } else {
            ei--;
        }
    }
    
    return nums[si];
};