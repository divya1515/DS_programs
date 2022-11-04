#include <bits/stdc++.h>
using namespace std;
void decimaltoHex(stack<char> s, int n)
{
	int rem;
	while (n != 0)
	{
		char x;
		if ((n % 16) >= 10)
		{
			x = (n % 16) + 55;
		}
		else
			x = (n % 16) + 48;
		s.push(x);
		n = n / 16;
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
	int n;
	cin >> n;
	decimaltoHex(s, n);
}
