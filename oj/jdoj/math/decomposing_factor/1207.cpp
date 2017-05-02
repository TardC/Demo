#include <stdio.h>

bool mark[100001];
int prime[100001];
int primeSize;

void init(void)
{
    primeSize = 0;

    for (int i = 2; i <= 100000; i++) {
        if (mark[i] == true)
            continue;

        prime[primeSize++] = i;

        if (i >= 1000)
            continue;

        for (int j = i*i; j <= 100000; j += i) {
            mark[j] = true;
        }
    }
} // ����ɸ��ɸѡ��2��100000�ڵ���������

int main(void)
{
    init();

    int n;
    while (scanf("%d", &n) != EOF) {
        int ansPrime[30]; // ��˳�򱣴�ֽ����������
        int ansSize = 0; // �ֽ���������ĸ���
        int ansNum[30]; // ����ֽ������������Ӧ����ָ��

        for (int i = 0; i < primeSize; i++) { // ���β���ÿһ������
            if (n % prime[i] == 0) {
                ansPrime[ansSize] = prime[i];
                ansNum[ansSize] = 0;

                while (n % prime[i] == 0) { //�ӱ��������н������ֽ��������ͳ������ָ��
                    ansNum[ansSize]++;
                    n /= prime[i];
                }

                ansSize++;

                if (n == 1) // ���ѱ��ֽ��1����ֽ���ǰ��ֹ
                    break;
            }
        }
        if (n != 1) { // ��������2��100000��������������n��δ���ֽ���1����ʣ�������һ����nһ������100000��������
            ansPrime[ansSize] = n; // ��¼
            ansNum[ansSize++] = 1; // ��ָ��ֻ��Ϊ1
        }

        int ans = 0;
        for (int i = 0; i <ansSize; i++) {
            ans += ansNum[i];
        }
        printf("%d\n", ans);
    }

    return 0;
}
