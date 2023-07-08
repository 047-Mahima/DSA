/*Given a package with a weight limit limit and an array arr of item weights, 
implement a function getIndicesOfItemWeights that finds two items whose sum of weights equals the weight limit limit. 
Your function should return a pair [i, j] of the indices of the item weights, ordered such that i > j. If such a pair doesn’t exist, return an empty array.

Analyze the time and space complexities of your solution.

Example:
input:  arr = [4, 6, 10, 15, 16],  lim = 21
output: [3, 1] #since these are the indices of the weights 6 and 15 whose sum equals to 21*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> getIndicesOfItemWeights( const vector<int>& arr, int limit)
{
  // your code goes here
  int n = arr.size();
  /* Approach 1 : BRUTE FORCE ( Doesn't take care of the duplicates )
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == limit) {
                return {j, i};  
            }
        }
    }
    return {};
    */
  //approach 2 : using extra space
  
  unordered_map<int, int> umap;
  
  for(int i = 0 ; i < n ; i++)
  {
    int reqNum = limit - arr[i];
    
    if(umap.find(reqNum) != umap.end())
    {
      return {i, umap[reqNum]};
    }
    
    umap[arr[i]] = i;
  }
  
  return {};
}

int main() {
  return 0;
}
