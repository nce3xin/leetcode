## 题意
反转链表。例子：Input: 1->2->3->4->5->NULL Output: 5->4->3->2->1->NULL。
## 思路
这个就是常规操作了，使用一个变量记录前驱pre，一个变量记录后继next。
不断更新`current.next = pre `就好了。
## 关键点
* 链表的基本操作（交换）。
* 虚拟节点dummy 简化操作。
* 注意更新current和pre的位置， 否则有可能出现溢出。