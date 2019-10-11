class TreeNode:
    def __init__(self, x):
        self.val=x
        self.left=None
        self.right=None

class Solution:
    def isValidBST(self,root):
        prev=[]
        return self.validInorder(root,prev)
    def validInorder(self,root,prev):
        if not root:
            return True
        if not self.validInorder(root.left,prev):
            return False
        if not prev:
            prev.append(root.val)
        elif prev[0]>=root.val:
            return False
        prev[0]=root.val
        if not self.validInorder(root.right,prev):
            return False
        return True

if __name__=='__main__':
    root=TreeNode(1)
    root.left=TreeNode(1)
    root.right=None

    sln=Solution()
    res=sln.isValidBST(root)
    print(res)