from Colors import *
from PrettyPrint import *
from Tree import *
from List import *

if __name__ == '__main__':
  tree = makeTree([
                       TreeNode(0),
          TreeNode(1),                  TreeNode(2),
      TreeNode(3), None,          TreeNode(4),     None,
      None, None, None, None, TreeNode(5), None, None, None,
    ]
  )
  printTree(tree)

