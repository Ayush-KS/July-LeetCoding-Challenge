// Maximum Width of Binary Tree

class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if(root == null)
            return 0;
        Queue<Pair<TreeNode, Integer>> q = new LinkedList<>(); 
        q.add(new Pair(root, 0));
        int ans = 0;
        
        while(!q.isEmpty()) {
            int size = q.size();
            int left = Integer.MAX_VALUE;
            int right = Integer.MIN_VALUE;
            
            for(int i = 0; i < size; i++) {
                Pair<TreeNode, Integer> curr = q.poll();
                left = Math.min(left, curr.getValue());
                right = Math.max(right, curr.getValue());
                
                TreeNode leftChild = curr.getKey().left;
                TreeNode rightChild = curr.getKey().right;
                
                if(leftChild != null)
                    q.add(new Pair(leftChild, 2*curr.getValue()));
                if(rightChild != null)
                    q.add(new Pair(rightChild, 2*curr.getValue() + 1));
                
            }
            ans = Math.max(ans, right - left + 1);
        }
        
        return ans;
    }
}