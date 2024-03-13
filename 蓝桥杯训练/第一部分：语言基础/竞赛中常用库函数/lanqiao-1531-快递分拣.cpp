// lanqiao-1531-快递分拣
#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> m;
vector<string> citys;
int main()
{
  // 请在此输入您的代码
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N; cin>>N;
  for(int i = 0; i < N; i++){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    if(!m.count(s2)) citys.push_back(s2); 
    m[s2].push_back(s1);

  }
  for(const auto &city : citys){
    cout << city << ' ' << m[city].size() << '\n';
    for(const auto & it : m[city]) cout << it << '\n'; 
  }
  return 0;
} 
