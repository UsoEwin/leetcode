class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k < 1)
            return head;
        ListNode *last_of_list = head;
        int list_len = 1;
        while(last_of_list->next)
            list_len++, last_of_list = last_of_list->next;
        k %= list_len;
        int skip_len = list_len-k;
        last_of_list->next = head;
        ListNode *curr = head;
        for(int i = 0; i < skip_len-1; ++i)
            curr = curr->next;
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};