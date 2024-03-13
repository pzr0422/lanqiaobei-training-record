// х╚ееапящй╬
#include <bits/stdc++.h>
using namespace std;
int main(void){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> nums = {1, 2, 3};
    cout << "Initial permutation: ";
    for(auto num : nums){
		cout << num << ' ';
    }
    cout << '\n';
    
    while(next_permutation(nums.begin(), nums.end())){
        cout << "Next permutation: ";
        for(auto num : nums){
			cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
} 
