//Question
/*Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1.
The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.*/

class Solution {
     int length=0;
public:
   int getlength(ListNode* head)
    {
        //int length=0;
        ListNode* temp;
        temp=head;
        while(temp)
        {
            temp=temp->next;
            length++;
        }
        return length;
    }
    int getDecimalValue(ListNode* head) {
        getlength(head);
        int decimal_value=0;
        ListNode* temp;
        temp=head;
        int i=1;
        while(temp)
        {
            decimal_value+=pow(2,length-i)*(temp->val);
            temp=temp->next;
            i++;
        }
        return decimal_value;
    }
};