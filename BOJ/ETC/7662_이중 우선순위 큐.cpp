#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm> 
#include <queue> 
#include <deque> 
#include <set> 
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int t; 
	cin >> t; 

	while(t--){
		multiset<int> ms; // 오름차순 정렬 
		
		int k; 
		cin >> k;
		
		for(int i = 0; i < k; i++){ // 최대 100만 
			char cmd;
			int num;
			cin >> cmd >> num;

			if(cmd == 'I'){ // 원소 삽입
				ms.insert(num);
			}else{ 
				if(!ms.empty() && num == -1){ 
					// 최솟값 삭제 
					ms.erase(ms.begin()); 
				}
				
				if(!ms.empty() && num == 1){
					// 최댓값 삭제 
					auto it = ms.end(); // 마지막 원소 바로 다음 위치 
					ms.erase(--it); 
				}
			}
		}

		if(!ms.empty()) {
			auto it = ms.end(); it--; 
			cout << *it << " " << *ms.begin() << endl; 
		}else{
			cout << "EMPTY\n"; 
		}
	}
	
	return 0;
}