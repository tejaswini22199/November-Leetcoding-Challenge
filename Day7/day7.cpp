/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 */
class Solution {
    ListNode* head;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       stack<int> list1;
       stack<int> list2;
       ListNode* head1;
        head1=l1;
        ListNode* head2;
        head2=l2;
        int x,y,carry,sum;
        carry=0;
        while(head1)
        {
            list1.push(head1->val);
            head1=head1->next;
        }
        while(head2)
        {
            list2.push(head2->val);
            head2=head2->next;
        }
        carry=0;
        ListNode* head=NULL;
        while(!list1.empty() || !list2.empty())
        {
            sum=0;
            if(!list1.empty())
            sum+=list1.top();
            if(!list2.empty())
            sum+=list2.top();
            if(!list1.empty())
            list1.pop();
              if(!list2.empty())
            list2.pop();
            sum=sum+carry;
            ListNode* temp=new ListNode(sum%10);
            temp->next=head;
            head=temp;
            carry=sum/10;
        } 
         if(carry!=0)
            {
             ListNode* temp=new ListNode(1);
             temp->next=head;
             return temp;
            }
        return head;
    }
};