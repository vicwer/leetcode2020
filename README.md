# leetcode2020

> 解体思路记录

### 反转链表

> [leetcode24](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

#### 解题思路

局部反转，判断`head`是否空，空则返回，否则初始化两个局部变量`pre`和`cnt`，`cnt`指向当前`head`节点，`pre`指向前一个节点；`head`节点遍历链表，每次遍历都让`head`指向下一个节点，同时`cnt`的next指向`pre`节点，然后`pre`指向`cnt`，`cnt`指向当前`head`，遍历完之后再将最后一个节点的next指向`pre`.

### 二叉树中序遍历

> [leetcode94](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

#### 解题思路

递归遍历，左根右。
构造二叉树，使用队列，将当前根节点加入队列，循环遍历遍历队列，若队列非空，则取出当前根节点，当前根节点在队列中pop；判断当前根节点是否右子节点，当前根节点左孩子和右孩子分别赋值，若右子节点，将当前子节点push到队列。直到队列空之后，结束返回二叉树。

### 相同的树

> [leetcode100](https://leetcode-cn.com/problems/same-tree/)

#### 解题思路

若两根节点都空，返回true；否则若两节点都非空，则分别递归遍历左右子树，并判断当前节点是否相等；否则返回false。

### 对称树

> [leetcode101](https://leetcode-cn.com/problems/symmetric-tree/)

#### 解题思路

如果根节点都空，则对称；如果两树都非空，则递归判断两树子节点是否对称，若两树都对称且当前节点值相等，则对称；否则，不对称，返回false.

### 二叉树的最大深度

> [leetcode104](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

#### 解题思路

如果当前节点空，返回深度0；否则，返回当前节点子树的最大深度加1.
