#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  stack<int> s1;
  stack<int> s2;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    s1.push(x);
  }
  int y = s1.top();
  s2.push(y);
  while (!s1.empty())
  {
    if (s2.top() > s1.top())
    {
      s2.pop();
      s2.push(s1.top());
      s1.pop();
    }
    else
    {
      s1.pop();
    }
  }
  cout << s2.top();
}
