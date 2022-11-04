#include <bits/stdc++.h>
using namespace std;
void decimaltoAnyBase(stack<char> s, int n, int base)
{
	int rem;
	while (n != 0)
	{
		char x;
		if ((n % base) >= 10)
		{
			x = (n % base) + 55;
		}
		else
			x = (n % base) + 48;
		s.push(x);
		n = n / base;
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}
int main()
{
	stack<char> s;
	int n, base;
	cin >> n;
	cin >> base;
	decimaltoAnyBase(s, n, base);
}
