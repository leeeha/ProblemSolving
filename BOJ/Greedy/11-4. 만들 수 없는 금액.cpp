#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> v;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int target = 1;
    for (int i = 0; i < n; i++) {
        // Ÿ�ٺ��� ū ȭ�� ������ �־�����, ���� �� ���� �ݾ����� �Ǵ�
        if (target < v[i]) 
            break; 

        // Ÿ�Ϻ��� ���� ȭ�� ������ ���, �ش� ȭ�� ������ ���� ������ Ÿ�� �ݾ� ����
        target += v[i];
    }

    // ���� �� ���� �ݾ� ���
    cout << target << '\n';
}