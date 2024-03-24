#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//find_by_order and order_of_key
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; //like set in ascending order
// typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; //for multiset in ascending order
// typedef tree<int,null_type,greater_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;//multiset in descending order
void solve(){
    pbds A;
    A.insert(1);
    A.insert(10);
    A.insert(2);
    A.insert(7);
    A.insert(2);
    for(auto i:A)
    cout<<i<<" ";
    cout<<endl;
    //to get element at ith index
     cout<<*A.find_by_order(0);
     cout<<endl;
     //to get number of elements smaller than x
     cout<<A.order_of_key(6);
     cout<<endl;
     //to get the first element that is >=x
     cout<<*A.lower_bound(2);
     cout<<endl;
     //to get the first element that is > x
     cout<<*A.upper_bound(2);
     cout<<endl;
     cout<<A.size();
     cout<<endl;
     //to remove elements
     A.erase(2);
}
 int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
 
  while (t--)
  {
    solve();
  }
}

//leetcode problem
https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/description/
