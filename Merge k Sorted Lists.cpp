//
// Created by xmac on 18-10-20.
//

#include <cstdlib>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() <= 0) {
            return NULL;
        }

        if (lists.size() == 1 ) {
            return mergeTwoLists(lists[0], NULL);
        }

        if (lists.size() == 2) {
            return mergeTwoLists(lists[0], lists[1]);
        }

        int mid = lists.size() / 2;
        vector<ListNode*> left(lists.begin(), lists.begin() + mid);
        ListNode* l = mergeKLists(left);
        vector<ListNode*> right(lists.begin() + mid, lists.end());
        ListNode* r = mergeKLists(right);

        return mergeTwoLists(l, r);
    }

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