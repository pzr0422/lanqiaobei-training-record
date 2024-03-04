#include <bits/stdc++.h>
using namespace std;
bool cmp(const int &u, const int &v){
	return u > v;
}
int main(void){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> v = {5, 1, 3, 9, 11};
    sort(v.begin(), v.end(), cmp);
    for(auto i : v){
		cout << i << ' ' ;
    }
}
