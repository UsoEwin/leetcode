class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int p, int q) {
        if(p == q)
            return head;
        ListNode *curr = head, *prev = nullptr;
        for(int i = 0; i < p-1 && curr != nullptr; ++i) {
            prev = curr;
            curr = curr->next;
        }
        ListNode *last_of_first_part = prev, *last_of_sublist = curr;
        ListNode *next = nullptr;
        //reverse
        for(int i = 0; i < q-p+1 && curr != nullptr; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //check if m == 1
        if(last_of_first_part != nullptr)
            last_of_first_part->next = prev;
        else
            head = prev;
        last_of_sublist->next = curr;
        return head;
    }
};