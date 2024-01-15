# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:
    def __init__(self, root: Optional[TreeNode]):
        self.d = {}
        def dfs(root,x):
            if not root:
                return
            root.val = x
            self.d[x] = 1
            if root.left :
                dfs(root.left , 2*x + 1)
            if root.right :
                dfs(root.right , 2*x + 2)
        dfs(root,0)        

    def find(self, target: int) -> bool:
        return target in self.d;


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)