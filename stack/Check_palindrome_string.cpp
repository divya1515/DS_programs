#include <bits/stdc++.h>
using namespace std;
void Palindrome(string str)
{
  stack<char> s;
  int i = 0;
  char x;
  int flag = 0;
  while (i < str.length())
  {
    s.push(str[i]);
    i++;
  }
  int j = 0;
  while (!s.empty())
  {
    x = s.top();
    if (x != str[j])
    {
      flag = 1;
      break;
    }
    s.pop();
    j++;
  }
  if (flag)
    cout << "Not a palindrome";
  else
    cout << "Palindrome";
}
int main()
{
  string str;
  cin >> str;
  Palindrome(str);
}
