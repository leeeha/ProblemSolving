#include<iostream>
#include<string>
using namespace std;

int main() {
	int h;
	cin >> h;

	int count = 0;
	for(int i = 0; i < h + 1; i++){
		for(int j = 0; j < 60; j++){
			for(int k = 0; k < 60; k++){
				// �� �ð� �ȿ� '3'�� ���ԵǾ� ������ ī��Ʈ ����
				string time = to_string(i) + to_string(j) + to_string(k);
				if(time.find('3') != -1){
					count++;
				}
			}
		}
	}

	cout << count << '\n';

    return 0;
}