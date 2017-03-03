#include <stdio.h>
void swap(int x, int y);
void siftdown(int i);
void creat();
void heapsort();

int h[101]; // 用来存放堆的数组
int n; // 用来存储堆中元素的个数，也就是堆的大小

int main()
{
    int i, num;
    // 读入n个数
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
        scanf("%d", &h[i]);
    n = num;

    // 建堆
    creat();

    // 堆排序
    heapsort();

    // 输出
    for (i = 1; i <= num; i++)
        printf("%d ", h[i]);

    getchar();
    getchar();
    return 0;
}

// 交换函数，用来交换堆中的两个元素的值
void swap(int x, int y)
{
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;

    return ;
}

//向下调整函数
void siftdown(int i) // 传入一个需要向下调整的结点编号i，这里传入1，即从堆的顶点开始向下调整
{
    int t, flag = 0; // flag用来标记是否需要继续向下调整
    // 当i节点有儿子（其实是至少有左儿子）并且有需要继续调整的时候循环就执行
    while (i * 2 <= n && flag == 0)
    {
        // 首先判断它和左儿子的关系，并用t记录值较大的节点编号
        if (h[i] < h[i*2])
            t = i * 2;
        else
            t = i;
        // 古国它有右儿子，再对右儿子进行讨论
        if (i * 2 + 1 <= n)
        {
            // 如果右儿子的值更大，更新较小的结点编号
            if (h[t] < h[i*2+1])
                t = 2 * i + 1;
        }
        // 如果发现最大的结点编号不是自己，说明子节点中有比父结点更大的
        if (t != i)
        {
            swap(t, i);
            i = t; // 更新i为刚才与它交换的儿子结点的编号，便于接下来继续向下调整
        }
        else
            flag = 1;
    }

    return ;
}

// 建立堆的函数
void creat()
{
    int i;
    // 从最后一个非叶结点到第1个结点依次进行向上调整
    for (i = n / 2; i >= 1; i--)
    {
        siftdown(i);
    }

    return ;
}

// 堆排序
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

