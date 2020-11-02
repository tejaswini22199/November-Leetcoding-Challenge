//Question
/*Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1.
The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.*/

class Solution {
     int length=0;
public:
    int getDecimalValue(ListNode* head)
    {
        //int length=0;
        if(head->next==NULL)
            return 1;
        length+=getDecimalValue(head->next)*(head->val)*2;
        return length;
    }
};