/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    } 
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*>mp;
        Node* cur = head;

        Node* nhead = new Node(0);

        Node* ncur = nhead;

        cur = head;
        while(cur)
        {
            Node* nnode = new Node(cur->val);
            ncur->next = nnode;
            ncur = nnode;
            mp[cur] = nnode;
            cur = cur->next;
        }

        cur = head;
        ncur = nhead->next;

        while(cur)
        {
            ncur->random = mp[cur->random];
            cur= cur->next;
            ncur = ncur->next;
        }
        return nhead->next;

    }
};
