//
// Created by xmac on 18-10-20.
//

#include "solution.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }

        ListNode tmp(0);
        ListNode* begin = &tmp;
        ListNode* after = head->next;

        begin->next = head;

        while(after != NULL) {
            begin->next = after;
            head->next = after->next;
            after->next = head;

            begin = head;

            head = begin->next;
            if (head == NULL) {
                break;
            }
            after = head->next;
        }

        return tmp.next;
    }
};