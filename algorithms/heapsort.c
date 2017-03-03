#include <stdio.h>
void swap(int x, int y);
void siftdown(int i);
void creat();
void heapsort();

int h[101]; // ������Ŷѵ�����
int n; // �����洢����Ԫ�صĸ�����Ҳ���ǶѵĴ�С

int main()
{
    int i, num;
    // ����n����
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
        scanf("%d", &h[i]);
    n = num;

    // ����
    creat();

    // ������
    heapsort();

    // ���
    for (i = 1; i <= num; i++)
        printf("%d ", h[i]);

    getchar();
    getchar();
    return 0;
}

// ���������������������е�����Ԫ�ص�ֵ
void swap(int x, int y)
{
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;

    return ;
}

//���µ�������
void siftdown(int i) // ����һ����Ҫ���µ����Ľ����i�����ﴫ��1�����ӶѵĶ��㿪ʼ���µ���
{
    int t, flag = 0; // flag��������Ƿ���Ҫ�������µ���
    // ��i�ڵ��ж��ӣ���ʵ������������ӣ���������Ҫ����������ʱ��ѭ����ִ��
    while (i * 2 <= n && flag == 0)
    {
        // �����ж���������ӵĹ�ϵ������t��¼ֵ�ϴ�Ľڵ���
        if (h[i] < h[i*2])
            t = i * 2;
        else
            t = i;
        // �Ź������Ҷ��ӣ��ٶ��Ҷ��ӽ�������
        if (i * 2 + 1 <= n)
        {
            // ����Ҷ��ӵ�ֵ���󣬸��½�С�Ľ����
            if (h[t] < h[i*2+1])
                t = 2 * i + 1;
        }
        // ����������Ľ���Ų����Լ���˵���ӽڵ����бȸ��������
        if (t != i)
        {
            swap(t, i);
            i = t; // ����iΪ�ղ����������Ķ��ӽ��ı�ţ����ڽ������������µ���
        }
        else
            flag = 1;
    }

    return ;
}

// �����ѵĺ���
void creat()
{
    int i;
    // �����һ����Ҷ��㵽��1��������ν������ϵ���
    for (i = n / 2; i >= 1; i--)
    {
        siftdown(i);
    }

    return ;
}

// ������
void heapsort()
{
    while (n > 1)
    {
        swap(1, n);
        n--;
        siftdown(1);
    }

    return ;
}

