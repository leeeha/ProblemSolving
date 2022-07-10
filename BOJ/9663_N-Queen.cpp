#include <iostream>
using namespace std;

int n; 
int queen_col[15]; // ���� ���� ���� ��ġ�� ���� 
int cnt = 0; 

// �������� �Ǵ��ϴ� �Լ� 
bool promising(int row) { 
	// ���� ���� �밢�� �� ������ �� �ȴ�. 
	// �� ���� �밢���� ���̸� ��� ���� �Ÿ� ���̰� ����. 
	for(int i = 0; i < row; i++){
		if(queen_col[row] == queen_col[i] || 
			row - i == abs(queen_col[row] - queen_col[i])){ 
			return false;
		}
	}
	
	return true; 
}


// nqueen �˰��� ����
void nqueen(int row) {
	// n��° ����� n���� ���� ���� ����� ���� �ϳ� ã�Ҵٸ� 
	if(row == n){ 
		cnt++;  // ���� �����ϰ� 
		return; // ���� ���� ���� ��� ȣ�� ���� 
    }
   
    for(int col = 0; col < n; col++){
        // ���� �࿡�� ��� �� �˻� 
        queen_col[row] = col; // (row, col)�� ���� ���ƺ���. 
        
        // �����ϴٸ� ���� Ʈ���� �̵� 
        // �ƴϸ� ���̻� ��� ȣ������ �ʰ� �ٷ� ���� ���� ��Ʈ��ŷ (����ġ��)
        if(promising(row)){  // �����ϴٸ� 
            nqueen(row + 1); // �� ���� �࿡ ���� ���ƺ���. (��� ȣ��) 
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	nqueen(0); // 0��° ����� ����
	cout << cnt; 
	
	return 0;
}