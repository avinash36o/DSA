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
    ListNode* merge(ListNode* leftHead, ListNode* rightHead){
        ListNode* tempList=new ListNode(-1);
        ListNode* end=tempList;
        ListNode* left=leftHead;
        ListNode* right=rightHead;
        while(left !=NULL && right !=NULL){
            if(left->val <= right->val){
                end->next=left;
                end=end->next;
                left=left->next;
            }else{
                end->next=right;
                end=end->next;
                right=right->next;
            }
        }
        if(left !=NULL){
            end->next=left;
                end=end->next;
                left=left->next;
        }
        if(right !=NULL){
            end->next=right;
                end=end->next;
                right=right->next;
        }
        return tempList->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        ListNode* head=lists[0];
        for(int i=1; i<lists.size(); i++){
            head=merge(head,lists[i]);
        }
        return head;
    }
};