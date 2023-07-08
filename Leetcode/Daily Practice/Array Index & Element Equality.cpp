/*Given a sorted array arr of distinct integers, write a function indexEqualsValueSearch that returns the lowest index i for which arr[i] == i. Return -1 if there is no such index. Analyze the time and space complexities of your solution and explain its correctness.

Examples:

input: arr = [-8,0,2,5]
output: 2 # since arr[2] == 2

input: arr = [-1,0,3,6]
output: -1 # since no index in arr satisfies arr[i] == i;
  */

#include <iostream>
#include <vector>

using namespace std;

int indexEqualsValueSearch(const vector<int> &arr) 
{
  // your code goes here
  /*APPROACH 1 : BRUTE FORCE
  for(int i = 0 ; i < arr.size() ; i++)
  {
    if(arr[i] == i)
    {
      return i;
    }
  }
  
  return -1;*/
 //APPROACH 2 : USING BINARY SEARCH 
  int low = 0, high = arr.size()-1;
  int mid = 0;
  
  while(low <= high)
  {
    mid = low + (high - low)/2;
    if(arr[mid] == mid)
    {
      return mid;
    }
    else if(arr[mid] > mid)
    {
      high = mid-1;
    }
    else
    {
      low = mid+1;
    }
  }
  
  return -1;
  
}

int main() {
  return 0;
}
