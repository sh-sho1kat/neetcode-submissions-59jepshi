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
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        int cnt =0;
        while(cur)
        {
            cur = cur->next;
            cnt++;
        }
        cout<<cnt<<endl;

        ListNode* nhead;

        ListNode* prev = nullptr;
        cur = head;
        while(cur)
        {
            ListNode* node = new ListNode(cur->val);
            node->next = prev;
            prev = node;
            cur = cur->next;

        }
        nhead = prev;

        cur = nhead;

        while(cur)
        {
            cout<<cur->val<<" ";
            cur = cur->next;
        }


        int n = cnt/2;
        ListNode* c1 = head;
        ListNode* c2 = nhead;
        ListNode* finalhead = new ListNode();
        cur = finalhead;
        for(int i = 1;i<=n;i++)
        {
            ListNode* tmp;
            tmp = new ListNode(c1->val);
            cur->next = tmp;
            cur = tmp;

            tmp = new ListNode(c2->val);
            cur->next = tmp;
            cur = tmp;

            c1 = c1->next;
            c2 = c2->next;
            
        }
        if(cnt&1)
        {
            ListNode* tmp = new ListNode(c1->val);
            cur->next = tmp;
        }
        ListNode* p1 = head;
        ListNode* p2 = finalhead->next;

        while (p1 && p2)
        {
            p1->val = p2->val;
            p1 = p1->next;
            p2 = p2->next;
        }


    }
};

