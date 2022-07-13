#include <iostream>
#include <string> 
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int m;
	cin >> m;

	int s = 0; // 32��Ʈ�� 0���� �ʱ�ȭ 

	string str;
	int x;
	while(m--){
		cin >> str;

		if(str == "add"){
			cin >> x;
			s |= (1 << x); // bit setting 
		}else if(str == "remove"){
			cin >> x;
			s &= ~(1 << x); // bit masking 
		}else if(str == "check"){
			cin >> x;
			if(s & (1 << x)){ // exist 
				cout << "1\n";
			}else {
				cout << "0\n";
			}
		}else if(str == "toggle"){
			cin >> x;
			if(s & (1 << x)){ // exist 
				s &= ~(1 << x); // remove 
			}else {
				s |= (1 << x); // add
			}
		}else if(str == "all"){
			s = (1 << 21) - 1; // 1���� 20��° ��Ʈ ��� 1�� ǥ�� 
		}else if(str == "empty"){
			s = 0;
		}
	}
	
	return 0;
}