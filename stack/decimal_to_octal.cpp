#include<bits/stdc++.h>
using namespace std;
void decimaltoOct(stack<int>s,int n)
{int rem;
	while(n!=0)
	{
		rem=n%8;
		s.push(rem);
		n=n/8;
	}
    while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
}
  int main()
  {
	stack<int>s;
	int n;
	cin>>n;
	decimaltoOct(s,n);
  }
