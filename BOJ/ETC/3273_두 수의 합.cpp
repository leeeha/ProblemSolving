#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; 
	cin >> n; // 10만 

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i]; // 100만 
	}

	sort(v.begin(), v.end()); // 오름차순 정렬 

	int x;
	cin >> x; // 200만 

	// ai + aj = x를 만족시키는 쌍의 개수 
	int cnt = 0;
	int left = 0, right = n - 1;
	while(left < right){
		if(v[left] + v[right] > x) right--;
		else if(v[left] + v[right] < x) left++;
		else { cnt++; right--; }
	}

	cout << cnt << "\n";
	
	return 0;
}