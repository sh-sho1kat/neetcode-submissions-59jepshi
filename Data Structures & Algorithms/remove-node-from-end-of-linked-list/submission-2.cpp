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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* cur = head;

        while(cur)
        {
            cnt++;
            cur = cur->next;
        }
        if(cnt==n)
            return head->next;
        int p = cnt-n;
        cur = head;
        for(int i =0;i<p-1;i++)
            cur = cur->next;
        if(cur->next)
            cur->next = cur->next->next;
        else
            cur->next = nullptr;
        return head;
    }

};
 