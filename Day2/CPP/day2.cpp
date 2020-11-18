//Question
/*Insertion sort List
Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode();
        ListNode* prev;
        ListNode* curr;
        ListNode* nextNode;
        curr=head; 
        while(curr)
        {
            int x=curr->val;
            nextNode=dummy->next;
            prev=dummy;
            while(nextNode)
            {
                if(x<nextNode->val)
                break;
                else
                {
                    prev=nextNode;
                    nextNode=nextNode->next;
                }
            }
            ListNode* temp=curr->next;
            curr->next=nextNode;
            prev->next=curr;
            curr=temp;
        }
        return dummy->next;
    }
};