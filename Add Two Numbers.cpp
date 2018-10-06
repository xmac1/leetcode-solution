/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 // 使用 new 分配新的结点，防止在函数返回时局部变量被回收
 // while 循环知道两个输入链表都为NULL时停止，在循环体内部处理某个链表到达末尾时 的情况
 // 使用三元表达式简介的处理 NULL 结点的情况
class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* begin = new ListNode(0);
		ListNode* sumNode = begin;
        ListNode* preNode;

		int addNum = 0;
		while (l1 != NULL || l2 != NULL) {
            int n1 = (l1 != NULL)?l1->val:0;
            int n2 = (l2 != NULL)?l2->val:0;
			int tmp = n1 + n2 + addNum;
			addNum = tmp / 10;
			sumNode->val = tmp % 10;
			ListNode* node = new ListNode(0);
			sumNode->next = node;
            preNode = sumNode;
			sumNode = sumNode->next;
			l1 = (l1 != NULL)?l1->next:NULL; 
			l2 = (l2 != NULL)?l2->next:NULL;
		}


		if (addNum) {
			sumNode->val = addNum;
		}
		else {
			preNode->next = NULL;
		}

		return begin;
	}
};