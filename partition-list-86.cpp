/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        ListNode *lessHead = nullptr, *lessTail = nullptr;
        ListNode *moreHead = nullptr, *moreTail = nullptr;
        ListNode *current = head;
        while (current != nullptr) {
            int val = current->val;
            if (val < x) {
                if (lessTail == nullptr) {
                    lessHead = lessTail = current;
                }
                else {
                    lessTail->next = current;
                    lessTail = current;
                }
            }
            else {
                if (moreTail == nullptr) {
                    moreHead = moreTail = current;
                }
                else {
                    moreTail->next = current;
                    moreTail = current;
                }
            }
            ListNode *next = current->next;
            current->next = nullptr;
            current = next;
        }
        head = moreHead;
        if (lessHead != nullptr) {
            lessTail->next = head;
            head = lessHead;
        }
        return head;
    }
};

/* 4 ms (88.76%ile), 10.3 MB (26.91%ile) */