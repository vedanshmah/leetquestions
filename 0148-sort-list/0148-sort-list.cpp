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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                curr->next=left;
                left=left->next;
            }else{
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
        if (left != NULL)
            curr->next = left;

        if (right != NULL)
            curr->next = right;
        return dummy->next;
    }
    ListNode* sortlist(ListNode* head){
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* s=head;
        ListNode*f=head->next;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        ListNode* second=s->next;
        s->next=NULL;

        ListNode* left = sortlist(head);
        ListNode* right = sortlist(second);

        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return sortlist(head);
    }
};