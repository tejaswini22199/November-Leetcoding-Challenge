//Question
/*Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.*/

class Solution {
public:
    int maxPower(string s) {
        int n=s.length();
        int maxpower=0;
        if(n==1 || n==0)
            return n;
        for(int i=0;i<n-1;i++)
        {
            int temp_count=0;
            while(s[i]==s[i+1])
            {
                i++;
                temp_count++;
            }
            maxpower=max(maxpower,temp_count+1);          
        }
        return maxpower;
    }
};