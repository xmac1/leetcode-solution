/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // 基本思想是，使用两个指针，两个指针开始迭代的时间不一样或者开始迭代的位置不一样
//  当第一个指针迭代到链表末尾时，第二个指针指向的就是将要移除的节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* it = head;
        ListNode* target = NULL;
        ListNode* preNode = NULL;
        int i = 0;
        while(it != NULL) {
            i++;

            if (target) {
                target = target -> next;
            }

            if (preNode) {
                preNode = preNode -> next;
            }

            if (i == n + 1) {
                preNode = head;
            }
            if (i == n) {
                target = head;
            }
            
            it = it -> next;
        }

        if (target == head) {
            return head -> next;
        }
        
        if (target -> next == NULL && head -> next == target) {
            head->next = NULL;
        } else {
            preNode->next = target->next;
        }
        
        return head;
    }
};