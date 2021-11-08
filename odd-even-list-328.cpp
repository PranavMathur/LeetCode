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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *evenHead = head->next;
        if (evenHead == nullptr || evenHead->next == nullptr) return head;
        ListNode *prev1 = head;
        ListNode *prev2 = evenHead;
        ListNode *current = evenHead->next;
        while (current != nullptr) {
            prev1->next = current;
            prev2->next = current->next;
            prev1 = current;
            prev2 = current->next;
            if (current->next != nullptr) current = current->next->next;
            else break;
        }
        prev1->next = evenHead;
        return head;
    }
};

/*
12 ms (65.98%ile), 10.4 MB (96.02%ile)
*/