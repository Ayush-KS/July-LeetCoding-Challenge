// Binary Tree Level Order Traversal II

class Solution {
public:
    
    vector<vector<int>> order;
    
    void levelOrder(TreeNode* root, int depth) {
        if(!root)
            return;
        if(depth == order.size()) {
            order.push_back(vector<int>());
        }
        order[depth].push_back(root -> val);
        levelOrder(root -> left, depth + 1);
        levelOrder(root -> right, depth + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        levelOrder(root, 0);
        reverse(order.begin(), order.end());
        return order;
    }
};