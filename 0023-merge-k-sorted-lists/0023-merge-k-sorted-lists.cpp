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
    ListNode* merge(ListNode* first,ListNode* second){
        ListNode* temp=new ListNode(0);
        ListNode* curr=temp;
        while(first!=NULL && second!=NULL){
            if(first->val <= second->val){
                curr->next=first;
                first=first->next;
            }else{
                curr->next=second;
                second=second->next;
            }
            curr=curr->next;
        }
        if(first!=NULL){
            curr->next=first;
        }else if(second!=NULL){
            curr->next=second;
        }
        return temp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        queue<ListNode*> q;
        for(int i=0;i<lists.size();i++){
            q.push(lists[i]);
        }
        while(q.size()!=1){
            ListNode* first=q.front();
            q.pop();
            ListNode* second=q.front();
            q.pop();
            q.push(merge(first,second));
        }
        ListNode* ans=q.front();
        return ans;
    }
};