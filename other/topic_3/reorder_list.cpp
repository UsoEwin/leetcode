/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        //find the middle
        ListNode *fast = head, *slow = head;
        while(fast && fast->next)
            fast = fast->next->next, slow = slow ->next;
        ListNode *ptr1 = head, *ptr2 = reverseList(slow);
        while(ptr1 && ptr2) {
            ListNode *next1 = ptr1->next, *next2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = next1;
            ptr1 = next1;
            ptr2 = next2;
        }
        if(ptr1 != nullptr)
            ptr1->next = nullptr;
        return;
    }
private:
    ListNode *reverseList(ListNode *head) {
        if(!head || !head->next)
            return head;
        ListNode *curr = head, *next = nullptr, *prev = nullptr;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};