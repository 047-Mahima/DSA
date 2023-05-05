/*class Solution {
public:
    int maxVowels(string s, int k) {
        
        int num = 0, maxNum = 0;
        for(int i = 0 ; i <= s.size()-k ; i++)
        {
            num = 0;
            for(int j = i ; j < i+k ; j++)
            {
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o'|| s[j] == 'u' )
                {
                    num += 1;
                    maxNum = max(maxNum, num);
                }
            }
        }
        return maxNum;
    }
};
TC : O(n-k+1)*k
SC : O(1)

*/

class Solution {
public:
    int maxVowels(string s, int k) {
        
        int j = 0, maxNum = 0;
        unordered_set<char> uset;
        uset = {'a', 'e', 'i', 'o', 'u'};

        for(int i = 0 , LocalMaxNum = 0; i < s.size() ; i++)
        {
            LocalMaxNum += uset.count(s[i]);

            if(i - k >= 0) LocalMaxNum -= uset.count(s[i-k]);

            maxNum = max(maxNum, LocalMaxNum);   
        }
       return maxNum;
    }
};
