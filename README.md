# leetcode2020

> 解体思路记录

### 反转链表

> [leetcode24](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

#### 解题思路

局部反转，判断`head`是否空，空则返回，否则初始化两个局部变量`pre`和`cnt`，`cnt`指向当前`head`节点，`pre`指向前一个节点；`head`节点遍历链表，每次遍历都让`head`指向下一个节点，同时`cnt`的next指向`pre`节点，然后`pre`指向`cnt`，`cnt`指向当前`head`，遍历完之后再将最后一个节点的next指向`pre`.
