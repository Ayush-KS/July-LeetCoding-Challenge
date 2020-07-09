// 3Sum

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        
        Arrays.sort(nums);
        
        for(int i = 0; i < nums.length; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int toSum = -nums[i];
            
            HashMap<Integer, Boolean> map = new HashMap<>();
            HashMap<Integer, Boolean> cantHave = new HashMap<>();
            
            for(int j = i + 1; j < nums.length; j++) {
                if(map.containsKey(toSum - nums[j]) && !cantHave.containsKey(toSum - nums[j])) {
                    List<Integer> toAdd = Arrays.asList(-toSum, toSum - nums[j], nums[j]);
                    ans.add(toAdd);
                    cantHave.put(toSum - nums[j], true);
                } else {
                    map.put(nums[j], true);
                }
            }
        }
        return ans;
    }
}