/*Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

 */
class Solution {
public:
    bool getVal(vector<int>& nums,int threshold,int mid)
    {
        int n=nums.size();
        int result=0;
        for(int i=0;i<n;i++)
        {
            result+=ceil((float)nums[i]/mid);
        }
        //cout<<mid<<"-> "<<result<<endl;
        if(result<=threshold)
            return true;
        else
            return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<high)
        {
            int mid=(low+(high-low)/2);
            if(getVal(nums,threshold,mid))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};