#include <stdio.h>
void swap(int x, int y);
void siftdown(int i);
void creat();
int deletemax();

int h[101]; // ������Ŷѵ�����
int n; // �����洢����Ԫ�صĸ�����Ҳ���ǶѵĴ�С

int main()
{
    int i, num;
    // ����Ҫ��������ֵĸ�����
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
        scanf("%d", &h[i]);
    n = num;

    // ����
    creat();

    // ɾ������Ԫ�أ�����ɾ��n�Σ���ʵҲ���ǴӴ�С���������
    for (i = 1; i <= num; i++)
        printf("%d ", deletemax());

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

// ���µ�������
void siftdown(int i) // ����һ����Ҫ���µ����Ľ����i�����ﴫ��1�����ӶѵĶ��㿪ʼ���µ���
{
    int t, flag = 0; // flag��������Ƿ���Ҫ�������µ���
    // ��i�ڵ��ж��ӣ���ʵ������������ӣ���������Ҫ����������ʱ��ѭ����ִ��
    while (i * 2 <= n && flag == 0)
    {
        // �����ж���������ӵĹ�ϵ������t��¼ֵ��С�Ľڵ���
        if (h[i] > h[i*2])
            t = i * 2;
        else
            t = i;
        // �Ź������Ҷ��ӣ��ٶ��Ҷ��ӽ�������
        if (i * 2 + 1 <= n)
        {
            // ����Ҷ��ӵ�ֵ��С�����½�С�Ľ����
            if (h[t] > h[i*2+1])
                t = 2 * i + 1;
        }
        // ���������С�Ľ���Ų����Լ���˵���ӽڵ����бȸ�����С��
        if (t != i)
        {
            swap(t, i);
            i = t;
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
    // �����һ����Ҷ��㵽��1��������ν������µ���
    for (i = n / 2; i >= 1; i--)
    {
        siftdown(i);
    }

    return ;
}

// ɾ������Ԫ��
int deletemax()
{
    int t;
    t = h[1]; // ��һ����ʱ������¼�Ѷ����ֵ
    h[1] = h[n]; // ���ѵ����һ���㸳ֵ���Ѷ�
    n--; //�ѵ�Ԫ�ؼ���1
    siftdown(1); // ���µ���

    return t; //����ֵ����¼�ĶѵĶ�������ֵ
}
