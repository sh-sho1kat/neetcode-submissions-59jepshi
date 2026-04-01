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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;

        int carry = 0;
        while(l1 and l2)
        {
            int d1 = l1->val;
            int d2 = l2->val;
            int sum = d1+d2+carry;
            if(sum>=10)
            {
                sum%=10;
                carry=1;
            }
            else
                carry = 0;
            ListNode* tmp = new ListNode(sum);
            cur->next = tmp;
            cur =tmp;
            l1 = l1->next;
            l2 = l2->next;

        }
        while(l1)
        {
            int d1 = l1->val;
            int d2 = 0;
            int sum = d1+d2+carry;
            if(sum>=10)
            {
                sum%=10;
                carry=1;
            }
            else
                carry = 0;
            ListNode* tmp = new ListNode(sum);
            cur->next = tmp;
            cur =tmp;
            l1 = l1->next;

        }
        while(l2)
        {
            int d1 = 0;
            int d2 = l2->val;
            int sum = d1+d2+carry;
            if(sum>=10)
            {
                sum%=10;
                carry=1;
            }
            else
                carry = 0;
            ListNode* tmp = new ListNode(sum);
            cur->next = tmp;
            cur =tmp;
            l2 = l2->next;

        }
        if(carry)
        {
            ListNode* tmp = new ListNode(carry);
            cur->next = tmp;
        }
        return head->next;
    }
};
