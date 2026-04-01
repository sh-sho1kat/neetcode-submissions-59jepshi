/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while(cur1 and cur2)
        {
            ListNode* tmp = new ListNode();
            if(cur1->val <=cur2->val)
            {
                tmp->val = cur1->val;
                cur1 = cur1->next;
            }
            else
            {
                tmp->val = cur2->val;
                cur2 = cur2->next;
            }
            cur->next = tmp;
            cur = tmp;
        }
        while(cur1)
        {
            ListNode* tmp = new ListNode();
            tmp->val = cur1->val;
            cur1 = cur1->next;
            cur->next = tmp;
            cur = tmp;
        }
        while(cur2)
        {
            ListNode* tmp = new ListNode();
            tmp->val = cur2->val;
            cur2 = cur2->next;
            cur->next = tmp;
            cur = tmp;
        }
        return head->next;
    }
};
