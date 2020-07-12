// Subsets

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length;
        List<List<Integer>> ans = new LinkedList<>();
        
        for(int i = 0; i < (1 << n); i++) {
            List<Integer> curr = new LinkedList<Integer>();
            for(int j = 0; j < n; j++) {
                if((i&(1 << j)) != 0) {
                    curr.add(nums[j]);
                }
            }
            ans.add(curr);
        }
        
        return ans;
    }
}