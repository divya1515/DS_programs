#include <bits/stdc++.h>
using namespace std;
int match(char x, char y)
{
  if (x == '(' && y == ')')
    return 1;
  if (x == '{' && y == '}')
    return 1;
  if (x == '[' && y == ']')
    return 1;
  return 0;
}
void validityOfBracketed(string str)
{
  stack<char> s;
  char x;
  int i = 0, flag = 0;
  while (i < str.length())
  {
    if (str[i] == '(' || str[i] == '{' || str[i] == '[')
    {
      s.push(str[i]);
    }
    else
    {
      if (s.empty())
      {
        flag = 1;
        break;
      }
      else
      {
        if (match(s.top(), str[i]))
        {
          s.pop();
        }
        else
        {
          flag = 1;
          break;
        }
      }
    }
    i++;
  }
  if (flag == 0)
  {
    if (!s.empty())
    {
      cout << "INVALID";
    }
    else
      cout << "Valid";
  }
  else
    cout << "Invalid";
}
int main()
{
  string str;
  cin >> str;
  validityOfBracketed(str);
}
