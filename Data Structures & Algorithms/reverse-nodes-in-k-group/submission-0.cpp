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
            // Start of a new group
            if(cnt == 0)
                start = cur;

            prevprev = prev;
            prev = cur;
            cur = cur->next;
            prev->next = prevprev;
            cnt++;

            if(cnt == k)
            {
                cnt = 0;

                // Connect reversed group
                prevstart->next = prev;

                // Original first node is now the tail
                prevstart = start;

                prev = nullptr;
            }
        }

        // Restore incomplete group
        cur = prev;
        prev = nullptr;

        while(cnt)
        {
            prevprev = prev;
            prev = cur;
            cur = cur->next;
            prev->next = prevprev;
            cnt--;
        }

        // Connect incomplete group
        prevstart->next = prev;

        return head->next;
    }
};