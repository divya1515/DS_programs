#include <bits/stdc++.h>
using namespace std;
int reverse(int n, int ans)
{
   if (n == 0)
      return ans;

   int rem = n % 10;
   ans = ans * 10 + rem;
   reverse(n / 10, ans);
}
int main()
{
   int n;
   cin >> n;
   int ans = 0;
   int a = reverse(n, ans);
   cout << a << "\n";
}
