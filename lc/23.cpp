//lc 23
class Solution {
    struct comp{
        bool operator () (const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }  
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *,vector<ListNode *>,comp> min_heap;
        for(auto x:lists) {
            if(x != nullptr)
                min_heap.push(x);
        }
        ListNode *head = nullptr, *tail = nullptr;
        
        while(!min_heap.empty()) {
            ListNode *curr = min_heap.top();
            min_heap.pop();
            if(head == nullptr) {
                head = curr;
                tail = curr;
            }
            else {
                tail->next = curr;
                tail = tail->next;
            }
            if(curr->next != nullptr)
                min_heap.push(curr->next);
        }
        return head;
    }
};