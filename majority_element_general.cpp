#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cout << "n: ";
	cin >> n;
	cout << "k: ";
	cin >> k;

	vector<int> arr(n);
	cout << "arr: ";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	vector<int> nums(k-1, INT_MIN), cnt(k-1, 0);

	for(int i = 0; i < n; i++){
		bool flag = false;
		for(int j = 0; j < k-1; j++){
			if(arr[i] == nums[j]){
				cnt[j]++;
				flag = true;
				break;
			}
		}

		if(!flag){
			for(int j = 0; j < k-1; j++){
				if(cnt[j] == 0){
					nums[j] = arr[i];
					cnt[j]++;
					flag = true;
					break;
				}
			}

			if(!flag){
				for(int j = 0; j < k-1; j++){
					cnt[j]--;
				}
			}
		}
	}	

	vector<int> ans;
	for(int i = 0; i < k-1; i++){
		if(nums[i] != INT_MIN and count(arr.begin(), arr.end(), nums[i]) > floor(n/k))
			ans.push_back(nums[i]);
	}

	for(auto &x:ans) cout << x << " ";
	return 0;
}