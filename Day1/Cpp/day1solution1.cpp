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