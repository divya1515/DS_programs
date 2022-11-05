#include <bits/stdc++.h>
using namespace std;
void sortedStack(stack<int> s1)
{
  stack<int> s2;
  int num = s1.top();
  int y, t;
  s1.pop();
  s2.push(num);
  while (!s1.empty())
  {
    num = s1.top();
    s1.pop();
    while (!s2.empty() && num < s2.top())
    {
      y = s2.top();
      s2.pop();
      s1.push(y);
    }
    s2.push(num);
  }
  while (!s2.empty())
  {
    t = s2.top();
    s2.pop();
    cout << t << " ";
  }
}
int main()
{
  int n;
  cin >> n;
  stack<int> s1;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    s1.push(x);
  }
  sortedStack(s1);
}
