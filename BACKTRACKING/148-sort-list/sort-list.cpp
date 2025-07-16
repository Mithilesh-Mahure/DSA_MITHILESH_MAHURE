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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* mid=slow->next;
        slow->next=NULL;

        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
        return merge(left,right);
    }
    ListNode* merge(ListNode* left,ListNode* right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }

        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;

        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next=left;
                temp=left;
                left=left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while(left!=NULL){
                temp->next=left;
                temp=left;
                left=left->next;
        } 
        while(right!=NULL){
                temp->next = right;
                temp = right;
                right = right->next;
        }
        return dummy->next;

        
    }
};