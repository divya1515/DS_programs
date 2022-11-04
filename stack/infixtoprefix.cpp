#include <bits/stdc++.h>
using namespace std;
int precd(char a, char b)
{
  if (a == '(' || b == '(')
    return 0;
  if (a != '(' && b == ')')
    return 1;
  else if (a == '(' && b == ')')
    return 0;
  else if (a == '^' || a == '*' || a == '%' || a == '/')
  {
    if (b == '^')
      return 0;
    else
      return 1;
  }
  else
  {
    if (b == '+' || b == '-')
      return 1;
    else
      return 0;
  }
}
void infixtoprefix(string infix, stack<int> s)
{
  int i = 0;
  int p = 0;
  char x, y;
  char symbol;
  string prefixexp;
  while (infix[i] != '\0')
  {
    symbol = infix[i];
    if (symbol >= 'a' && symbol <= 'z')
    {
      prefixexp +=symbol;
    }
    else
    {
      while (!s.empty() && !precd(symbol, s.top()))
      {
        x = s.top();
        s.pop();
        prefixexp +=x;
      }
      s.push(symbol);
    }
    i++;
  }
  while (!s.empty())
  {
    y = s.top();
    s.pop();
    prefixexp += y;
  }
  reverse(prefixexp.begin(), prefixexp.end());

  cout << prefixexp;
}
int main()
{
  string str;
  cin >> str;
  reverse(str.begin(), str.end());
  stack<int> s;
  infixtoprefix(str, s);
}
