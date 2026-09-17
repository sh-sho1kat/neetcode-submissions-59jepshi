class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev, *cur, *start, *prevprev, *prevstart;

        int cnt = 0;

        cur = head;
        prev = nullptr;

        start = new ListNode(0);
        head = start;

        prevstart = head;
        prevprev = nullptr;

        while(cur != nullptr)
        {
            if(cnt == 0)
                start = cur;
            prevprev = prev;
            prev = cur;
            cur = cur->next;
            prev->next = prevprev;
            cnt++;

            if(cnt==k) 
            { 
                cnt = 0; 
                prevstart->next = prev; 
                // start = prevstart; 
                prevstart = start; 
                prev = nullptr; 
            }
        }

        cur = prev;
        prev = nullptr;

        bool flag = false;
        while(cnt)
        {
            flag = true;
            prevprev = prev;
            prev = cur;
            cur = cur->next;
            prev->next = prevprev;
            cnt--;
        }

        if(flag)
            prevstart->next = prev;
        else 
            prevstart->next = nullptr;

        return head->next;
    }
};