// lanqiao-3226-sort
#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int a[N];
int main()
{
  // 请在此输入您的代码
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n; cin>>n;
  for(int i = 0; i < n; i++){
    cin>>a[i];
  }
  sort(a, a + n);
  for(int i = 0; i < n; i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
