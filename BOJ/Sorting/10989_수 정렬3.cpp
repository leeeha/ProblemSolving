// 10989번. 수 정렬3 (계수 정렬)
// 계속 출력 초과 오류 발생,,,,
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int count[10'000] = { 0 };

    int tmp;
    for (int i = 0; i < n; i++) {
        // 입력: 10,000보다 작거나 같은 자연수 -> 카운팅 배열의 인덱스
        scanf("%d", &tmp);

        // 입력값 자체를 index로 하고 (범위: 1 ~ 10000)
        // 값의 개수를 value으로 하는 count 배열
        count[tmp]++;
    }

    // 각 숫자가 입력된 횟수만큼 출력하기
    for (int val = 1; val <= 10'000; val++) {
        for (int j = 0; j < count[val]; j++)
            printf("%d\n", val);
    }

    return 0;
}