/*Bracket Match
A string of brackets is considered correctly matched if every opening bracket in the string can be paired up with a later closing bracket, and vice versa. 
For instance, “(())()” is correctly matched, whereas “)(“ and “((” aren’t. For instance, “((” could become correctly matched by adding two closing brackets 
at the end, so you’d return 2.
Given a string that consists of brackets, write a function bracketMatch that takes a bracket string as an input and returns the minimum number of brackets 
you’d need to add to the input in order to make it correctly matched.

Examples:

input:  text = “(()”
output: 1

input:  text = “(())”
output: 0

input:  text = “())(”
output: 2
*/

#include <iostream>
#include <string>
#include<stack>

using namespace std;

int bracketMatch( const string& text ) 
{
  // your code goes here
  /*using extra space :
  stack<int> st;
  int count = 0;
  
  for(int i = 0 ; i < text.size() ; i++)
  {
    if(text[i] == '(')
    {
      st.push(text[i]);
    }
    else
    {
      if(st.size() == 0)
      {
        count+=1;
      }
      else
      {
        st.pop();
      }
    }
  }
  
  if(st.size() != 0)
  {
    count+= st.size();
  }
  
  return count;
  
  TC : O(n)
  SC : O(n)
  */
  
  /*second approach
  
  TC : O(n)
  SC : O(1)
  */
  int difference = 0, ans = 0;
  if(text.size() == 1) return 1;
  
  for(int i = 0 ; i < text.size() ; i++)
  {
    if(text[i] == '(') difference += 1;
    
    else if(text[i] == ')') difference -= 1;
    
    if(difference < 0 )
    {
      difference += 1;
      ans += 1;
    }
  }
  
  return ans + difference;
  
 
  
}

int main() {
  return 0;
}
