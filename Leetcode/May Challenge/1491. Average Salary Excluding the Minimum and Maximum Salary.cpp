/*Method 1 :
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());

        double sum = 0.0, avg = 0.0;
        int size = salary.size()-2;

        for(int i = 1 ; i < salary.size()-1 ; i++)
        {
            sum += salary[i];
        }

        avg = sum/size;

        return avg;

    }
};

//Time Complexity : O(nlogn)
//Space Complexity : O(1)
*/

//Method 2:

class Solution {
public:
    double average(vector<int>& salary) {
        
        int n = salary.size();
        int mini, maxi ;
        double sum, avg;

        for(int i = 0; i < n ; i++)
        {
            sum += salary[i];
        }

        if(salary[0] > salary[1])
        {
            mini = salary[1];
            maxi = salary[0];
        }
        else
        {
            mini = salary[0];
            maxi = salary[1];
        }

        for(int i = 2 ; i < salary.size() ; i++)
        {
            if(salary[i] > maxi)
            {
                maxi = salary[i];
            }
            if(salary[i] < mini)
            {
                mini = salary[i];
            }
        }

        sum = (sum - mini - maxi);

        avg = sum/(n-2);

        return avg;
    }
};

//Time Complexity : O(2n)
//Space Complexity : O(1)
