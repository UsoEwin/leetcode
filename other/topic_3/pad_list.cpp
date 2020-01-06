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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        ListNode *ptr1 = head, *rev_head = slow, *ptr2 = reverseList(slow);
        while(ptr1 && ptr2) {
            if(ptr1->val != ptr2->val)
                break;
            ptr1 = ptr1->next, ptr2 = ptr2->next;
        }
        reverseList(rev_head);
        if(!ptr1 || !ptr2)
            return true;
        return false;
    }
private:
    ListNode *reverseList(ListNode *head) {
        if(!head || !head->next)
            return head;
        ListNode *curr = head, *prev = nullptr, *next = nullptr;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};