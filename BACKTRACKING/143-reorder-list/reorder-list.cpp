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
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        stack<ListNode*>st;

        while(curr){
            st.push(curr);
            curr=curr->next;
        }
        int mid=st.size()/2;
        curr=head;

        while(mid--){
            ListNode* topNode=st.top();
            st.pop();
            ListNode* temp=curr->next;
            curr->next=topNode;
            topNode->next=temp;
            curr=temp;
        }
        curr->next=NULL;
    }

};