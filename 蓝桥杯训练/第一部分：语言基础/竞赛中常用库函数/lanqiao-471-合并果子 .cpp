//lanqiao-471-合并果子 
#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 请在此输入您的代码
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  priority_queue<int, vector<int>, greater<int>> pq;
  int type; cin>>type;
  for(int i = 0; i < type; i++){
    int x; cin>>x;
    pq.push(x);
  }

  int sum;
  int pair;
  while(pq.size()>=2){
    int p1 = pq.top();
    pq.pop();
    int p2 = pq.top();
    pq.pop();
    pair = p1 + p2;
    sum+=pair;
    pq.push(pair);
  }
  cout << sum;
  return 0;
}
