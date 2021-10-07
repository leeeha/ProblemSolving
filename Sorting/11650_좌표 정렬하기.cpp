// 11650��. ��ǥ �����ϱ�
// ���� ���� N: 10���� ����, ��ǥ ����: -100,000 �� xi, yi �� 100,000

// �� ������ ���� �ʴٸ�, Point ����ü�� x,y ��ǥ�� ��� ������ ���� ������ �� ������
// �� ������ ���� ������ 10������ �Ǳ� ������ std::pair�� ����.

#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <algorithm> // std::sort
using namespace std;

int main()
{
    int n; // ���� ����
    cin >> n;
    vector<pair<int, int>> v;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }

    // x��ǥ �������� ����, x��ǥ�� ������ y��ǥ �������� ����
    sort(v.begin(), v.end());

    vector<pair<int, int>>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        printf("%d %d\n", it->first, it->second);
    }

    return 0;
}
