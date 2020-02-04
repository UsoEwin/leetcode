class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k <= 1 || head->next == nullptr)
            return head;
        ListNode *curr = head, *prev = nullptr;
        while(true) {
            ListNode *last_of_curr_list = curr, *last_of_prev_list = prev, *next = nullptr;
            ListNode *detect = curr;
            for(int i = 0; i < k && curr != nullptr; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(last_of_prev_list == nullptr)
                head = prev;
            else
                last_of_prev_list->next = prev; //notice curr is in next list, prev is in curr list
            last_of_curr_list->next = curr;
            if(curr == nullptr)
                break;
            prev = last_of_curr_list;
        }
        return head;
    }
};