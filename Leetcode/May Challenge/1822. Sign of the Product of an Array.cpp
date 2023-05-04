/*Method 1 :
class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int count_negSign = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] < 0)
            {
                count_negSign++;
            }
            if(nums[i] == 0)
            {
                return 0;
            }
        }

        if(count_negSign%2 == 0)
        {return 1;}
        return -1;
    }
};
*/

//Method 2:
class Solution {
public:
    int arraySign(vector<int>& nums) {
        
       int sign = 1;

       for(auto it : nums)
       {
           if(it == 0)
           {
               return 0;
           }
           if(it < 0)
           {
               sign = -sign;
           }
       }
       return sign;
    }
};
