from __future__ import annotations
from typing import Optional

class TreeNode:
  def __init__(self, val, left=None, right=None) -> None:
    self.val = val
    self.left = left
    self.right = right

def insertTree(tree: Optional[TreeNode], val) -> TreeNode:
  while tree is not None:
    if val < tree.val:
      if tree.left == None:
        tree.left = TreeNode(val)
        return tree.left
      else:
        tree = tree.left
    elif val > tree.val:
      if tree.right == None:
        tree.right = TreeNode(val)
        return tree.right
      else:
        tree = tree.right
    else:
      return tree
  return TreeNode(val)

def makeTree(lst: list) -> Optional[TreeNode]:
  if lst == []:
    return None
  root = insertTree(None, lst[0])
  for i in range(1, len(lst)):
    insertTree(root, lst[i])
  return root

def printTree_recurse(prefix: str, tree: Optional[TreeNode], isLeft: bool) -> None:
  if tree:
    print(prefix + ('|--' if isLeft else '`--'), tree.val, sep='')
    printTree_recurse(prefix + ('|  ' if isLeft else '   '), tree.left, True)
    printTree_recurse(prefix + ('|  ' if isLeft else '   '), tree.right, False)
  else:
    print(prefix + ('|--' if isLeft else '`--'), '.', sep='')

def printTree(tree: TreeNode):
  printTree_recurse('', tree, False)


