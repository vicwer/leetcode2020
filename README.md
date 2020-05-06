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

### 二叉树的层次遍历

> [leetcode102](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

用队列，先将根节点入队，然后遍历队列是否非空，非空则根据当前队列的size，遍历队列中节点，出队，然后判断左右子树是否存在，存在则入队，并将当前root->val存入vector。

### 二叉树的锯齿形层次遍历

> [leetcode103](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

#### 解题思路

用队列和栈，先进先出和先进后出的特性，每一层先入栈，栈再入队，然出队，栈内节点遍历出栈；对出栈的根节点，遍历其值，根据层数的奇偶，奇数层的话，先遍历左子树，再遍历右子树，偶数层的话，先遍历右子树，再遍历左子树。

### 二叉树的最小深度

> [leetcode111](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

#### 解题思路

如果当前节点空，返回深度0；否则，返回当前节点子树的最小深度加1.

### 路径总和

> [leetcode112](https://leetcode-cn.com/problems/path-sum/)

#### 解题思路

若根节点空，返回0；否则，若根节点的左右子树都空，则判断sum-当前val是否为0；递归判断当前根节点左子树或右子树是否满足上述条件。

### 路径总和2

> [leetcode113](https://leetcode-cn.com/problems/path-sum-ii/)

#### 解题思路

初始化两个变量res和cnt_res；如果根节点空，返回res；如果根节点没有左右子树，若当前sum减成0，则将当前val送入cnt_res，并将cnt_res放入res，然后当前val pop，返回res；否则，当前节点val放入cnt_res，递归当前节点左右子树，当前val pop，返回res。

### 二叉树展开为链表

> [leetcode104](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)

#### 解题思路

在还没操作节点右子树前，不能破坏该节点的右子树指向。所以采用后序遍历。先把右子树和左子树展开为链表，右子树赋上一次保存的最后的节点，左子树置空，最后保存的节点改为当前根节点。

### 从前序与中序遍历序列构造二叉树

> [leetcode105](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

#### 解题思路

前序中左起第一位1肯定是根结点，我们可以据此找到中序中根结点的位置rootin；
中序中根结点左边就是左子树结点，右边就是右子树结点，即[左子树结点，根结点，右子树结点]，我们就可以得出左子树结点个数为int left = rootin - leftin;；
前序中结点分布应该是：[根结点，左子树结点，右子树结点]；
根据前一步确定的左子树个数，可以确定前序中左子树结点和右子树结点的范围；
如果我们要前序遍历生成二叉树的话，下一层递归应该是：
左子树：root->left = pre_order(前序左子树范围，中序左子树范围，前序序列，中序序列);；
右子树：root->right = pre_order(前序右子树范围，中序右子树范围，前序序列，中序序列);。
每一层递归都要返回当前根结点root；

### 从中序与后序遍历序列构造二叉树

> [leetcode106](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

#### 解题思路

解题思路与题105相同。

### 二叉树的层次遍历II

> [leetcode107](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)

解题思路与题102相同。

### 平衡二叉树

> [leetcode110](https://leetcode-cn.com/problems/balanced-binary-tree/)

#### 解题思路

一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。所以，由定义，若根节点空，则是平衡二叉树，返回true；若根节点左右子树的深度差的绝对值大于1，则返回false，递归判断根节点的左右子树是不是都是平衡二叉树。关于求树的最大深度，若根节点空，则返回0，否则返回左右子树的最大深度+1.

### 填充每个节点的下一个右侧节点指针

> [leetcode116](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)

#### 解题思路

层次遍历，当遍历当前节点时，遍历完pop，如果队列中还有当前层的节点，则让当前节点的next指向队列中的当前节点。若当前节点有左右子树，则入队。
