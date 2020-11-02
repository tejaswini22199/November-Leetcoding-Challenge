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