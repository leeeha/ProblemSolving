// 10989��. �� ����3 (��� ����)
// ��� ��� �ʰ� ���� �߻�,,,,
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int count[10'000] = { 0 };

    int tmp;
    for (int i = 0; i < n; i++) {
        // �Է�: 10,000���� �۰ų� ���� �ڿ��� -> ī���� �迭�� �ε���
        scanf("%d", &tmp);

        // �Է°� ��ü�� index�� �ϰ� (����: 1 ~ 10000)
        // ���� ������ value���� �ϴ� count �迭
        count[tmp]++;
    }

    // �� ���ڰ� �Էµ� Ƚ����ŭ ����ϱ�
    for (int val = 1; val <= 10'000; val++) {
        for (int j = 0; j < count[val]; j++)
            printf("%d\n", val);
    }

    return 0;
}