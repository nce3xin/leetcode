class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res=[]
        self.inorder(root,res)
        return res

    def inorder(self,root,res):
        if not root:
            return
        self.inorder(root.left,res)
        res.append(root.val)
        self.inorder(root.right,res)