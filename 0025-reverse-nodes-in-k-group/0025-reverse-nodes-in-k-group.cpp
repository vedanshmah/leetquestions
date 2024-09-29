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
    ListNode* reversell(ListNode* head, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != end) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        for (int i = 0; i <= k-1; i++) {
            if (temp == nullptr) {
                return head;
            }
            temp = temp->next;
        }
        ListNode* newHead = reversell(head, temp);
        head->next = reverseKGroup(temp, k);
        return newHead;
    }
};


