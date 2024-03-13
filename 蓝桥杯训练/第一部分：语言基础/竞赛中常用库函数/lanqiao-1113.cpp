#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 请在此输入您的代码
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int m; cin>>m;
  queue<string> v;
  queue<string> n;
  for(int i = 0; i < m; i++){
    string order;
    cin>>order;
    if(order == "IN"){
      string name, type;
      cin>>name>>type;
      if(type == "N") n.push(name);
      else v.push(name);
    }
    else{
      string type;
      cin>>type;
      if(type == "N") n.pop();
      else v.pop();
    }
  }
  while(v.size()){
    cout << v.front() << '\n';
    v.pop();
  }
  while(n.size()){
    cout << n.front() << '\n';
    n.pop();
  }
  return 0;
}
