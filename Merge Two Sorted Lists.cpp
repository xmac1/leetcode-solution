/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 常规列表的合并操作
//  注意其中一个列表为NULl时的特殊情况
// 需要注意如何初始化类的指针
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* it = &head;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                it -> next = l2;
                return (&head)->next;
            } else if (l2 == NULL) {
                it -> next = l1;
                return (&head) -> next;
            } else {
                it -> next = (l1->val < l2->val)?l1:l2;
                if (l1->val < l2->val) {
                    l1 = l1 -> next;
                } else {
                    l2 = l2 -> next;
                }
            }
            it = it -> next;
        }
        return (&head)->next;
    }
};