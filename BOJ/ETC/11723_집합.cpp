#include <iostream>
#include <string> 
using namespace std;

// 1~20������ ���ڰ� ���տ� ���ԵǾ� �ִ��� ǥ�� 
int arr[21]; // 0���� �ʱ�ȭ 

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int m;
	cin >> m;

	string str;
	int x;
	while(m--){
		cin >> str;

		if(str == "add"){
			cin >> x;
			if(arr[x] == 0){
				arr[x] = 1; 
			}
		}else if(str == "remove"){
			cin >> x;
			if(arr[x] == 1){ 
				arr[x] = 0; 
			}
		}else if(str == "check"){
			cin >> x;
			if(arr[x] == 0){ 
				cout << "0\n"; 
			}else{ 
				cout << "1\n"; 
			}
		}else if(str == "toggle"){
			cin >> x;
			if(arr[x] == 0){ 
				arr[x] = 1;
			}else{ 
				arr[x] = 0; 
			}
		}else if(str == "all"){
			for(int i = 1; i <= 20; i++){
				arr[i] = 1;
			}
		}else if(str == "empty"){
			for(int i = 1; i <= 20; i++){
				arr[i] = 0; 
			}
		}
	}
	
	return 0;
}