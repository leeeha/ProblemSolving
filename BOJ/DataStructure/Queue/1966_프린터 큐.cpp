#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

	while(t--){
        int n, m;
        cin >> n >> m;
        
        // �ε����� m�� ������ ���°�� �μ�Ǿ����� ī�����ϴ� ����
        int cnt = 0;

        queue<pair<int, int>> q;
        priority_queue<int> pq; // �⺻������ �ִ� �� 

        for (int i = 0; i < n; i++){
			int x; 
			cin >> x; 
			
            q.push({ i, x }); // �ε����� �߿䵵 
            pq.push(x); // �߿䵵�� ���� ������ 
        }

        while (!q.empty()){
            // ť�� front ���Ҹ� ������
            int idx = q.front().first;
            int priority = q.front().second;
            q.pop();

            // �켱���� ť�� top�� �߿䵵�� ��ġ�ϸ�
            if (pq.top() == priority){
                pq.pop();
                cnt++; // ���� �ϳ� �μ��� ������ ����

                // ���� ������ �ε����� m�� ���
                if (idx == m){
                    // ���°�� �μ�Ǿ����� ���
                    cout << cnt << '\n'; 
                    break; // �� ���� �׽�Ʈ ���̽��� �Ѿ��
                }
            }
            else { 
				// �߿䵵�� ���� ������ ť�� rear�� �ٽ� push
                q.push({ idx, priority });
            }
        }

        // �� �׽�Ʈ ���̽����� q, pq�� ���� �����ϱ� ������ 
        // �����̳� �ʱ�ȭ�� �ʿ����� �ʴ�.  
    }

    return 0;
}