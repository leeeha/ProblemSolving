// Sol1. 이분탐색 
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n; // 최대 50만 

	vector<int> arr; 
	for(int i = 0; i < n; i++){
		int val; 
		cin >> val; 
		arr.push_back(val);
	}

	// 이진탐색은 정렬된 배열에서만 사용 가능 
	sort(arr.begin(), arr.end()); 

	int m; 
	cin >> m; 

    // O(MlogN) 
	for(int i = 0; i < m; i++){
		int key;  
		cin >> key; 

		int start = 0, end = arr.size() - 1; 
		bool searched = false; 
		
		while(start <= end){
			int mid = (start + end)/ 2; 
			if(arr[mid] == key){
				searched = true; 
				break; 
			}else if(arr[mid] < key){ 
				start = mid + 1; 
			}else{ 
				end = mid - 1; 
			}
		}

		if(searched) cout << "1 ";
		else cout << "0 "; 
	}

    return 0;
}

// Sol2. set::find 
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set> 
using namespace std;

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n; // 최대 50만 

	set<int> myset; 
	for(int i = 0; i < n; i++){
		int val; 
		cin >> val; 
		myset.insert(val); 
	}

	int m; 
	cin >> m; 

	for(int i = 0; i < m; i++){
		int x; 
		cin >> x; 
		
		if(myset.find(x) != myset.end()){
			cout << "1 "; 
		}else { 
			cout << "0 "; 
		}
	}

    return 0;
}