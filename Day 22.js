// Binary Tree Zigzag Level Order Traversal

var zigzagLevelOrder = function(root) {
    var left2right = true;
    var queue = [root];
    var ans = [];
    
    if(root == null)
        return ans;
    
    while(queue.length != 0) {
        var len = queue.length;
        var currVal = [];
        
        for(var i = 0; i < len; i++) {
            var currNode = queue.shift();
            currVal.push(currNode.val);
            
            if(currNode.left != null) {
                queue.push(currNode.left);
            }
            if(currNode.right != null) {
                queue.push(currNode.right);
            }
        }
        if(left2right != true) {
            currVal.reverse();
            left2right = true;
        } else {
            left2right = false;
        }
        ans.push(currVal);
    }
    
    return ans;
};