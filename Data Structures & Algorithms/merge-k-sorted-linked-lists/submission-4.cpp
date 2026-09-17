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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        int interval = 1;
        while (interval < lists.size()) {
            for (int i = 0; i + interval < lists.size(); i += interval * 2) {
                lists[i] = merge(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }
};