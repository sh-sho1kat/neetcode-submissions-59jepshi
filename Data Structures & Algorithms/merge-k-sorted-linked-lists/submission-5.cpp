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
    ListNode* merge(ListNode* h1, ListNode* h2) {
        if (h1 == nullptr) return h2;
        
        ListNode* prev = nullptr;
        ListNode* head = h1;
        
        while(h1 != nullptr && h2 != nullptr) {
            int p = h1->val;
            int q = h2->val;
            
            if(p <= q) {
                prev = h1;
                h1 = h1->next;
            } else {
                ListNode* node = new ListNode(q);
                if (prev == nullptr) {
                    head = node;
                } else {
                    prev->next = node;
                }
                node->next = h1;
                prev = node;
                h2 = h2->next;
            }
        }
        if(h2 != nullptr) {
            if (prev != nullptr) {
                prev->next = h2;
            } else {
                head = h2;
            }
        }
        return head;
    }

    ListNode* divide(int l, int r, vector<ListNode*>& lists)
    {
        ListNode* head;
        if(l==r)
            return lists[l];
        int mid = (l+r)/2;
        ListNode* node1 =  divide(l, mid,lists);
        ListNode* node2 =  divide(mid+1, r,lists);
        head = merge(node1,node2);
        return head;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;
        return divide(0, lists.size()-1, lists);
    }
};
