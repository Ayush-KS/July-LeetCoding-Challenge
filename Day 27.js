// Construct Binary Tree from Inorder and Postorder Traversal

var buildTree = function(inorder, postorder) {
    
    function helps(ino, posto, is, ie, ps, pe) {
        if(is > ie)
            return null;

        const root = new TreeNode(posto[pe], null, null);
        var ri = is;
        
        while(ino[ri] != root.val)
            ri++;

        var lis = is;
        var lie = ri - 1;
        var ris = ri + 1;
        var rie = ie;

        var lps = ps;
        var lpe = lps + (lie - lis);
        var rps = lpe + 1;
        var rpe = rps + (rie - ris);

        root.left = helps(ino, posto, lis, lie, lps, lpe);
        root.right = helps(ino, posto, ris, rie, rps, rpe);

        return root;
    }
    
    return helps(inorder, postorder, 0, inorder.length - 1, 0, postorder.length - 1);
};