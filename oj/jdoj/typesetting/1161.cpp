#include<iostream>
#include <vector>
#include <stdio.h>
using namespace std;
 
int main()
{
    //freopen("D:\\input.txt","r",stdin);
    vector<vector<char> > V;
    vector<vector<char> > V1;
    vector<vector<char> > V2;
    char c;
    int n;  //n是模板的大小
    int m;
    while(cin>>n)
    {
        if(n==0)break;
        V.clear();
        V1.clear();
        V2.clear();
        V.resize(n,vector<char>(n,' '));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;)
            {
                c = getchar();
                if(c=='\n')continue;
                V[i][j++] = c;
            }
        }
        cin>>m;
 
        V1.assign(V.begin(),V.end());
        for(int i=1;i<m;i++)
        {
            int h = n*V1.size();
            V2.clear(); //clear 以后就清除了
            V2.resize(h,vector<char>(h,' '));   //如果resize之后的大小大于原先大小，那么会用第二个参数的字符填充
            for(int j=0;j<n;j++)    //遍历模板
            {
                for(int k=0;k<n;k++)
                {
                    if(V[j][k]==' ')
                    {
                        continue;
                    }
                    else
                    {
                        int s_x = j*V1.size();
                        int s_y = k*V1.size();
                        for(int a=0;a<V1.size();a++)
                        {
                            for(int b=0;b<V1.size();b++)
                            {
                                V2[s_x+a][s_y+b] = V1[a][b];
                            }
                        }
                    }
                }
            }
            V1.assign(V2.begin(),V2.end());
        }
        for(int i=0;i<V1.size();i++)
        {
            for(int j=0;j<V1.size();j++)
            {
                cout<<V1[i][j];
            }
            cout<<endl;
        }
 
 
    }
 
    return 0;
 
}
 
/*
int main()
{
    vector<vector <char> > V;
    vector<vector <char> > V2;
    V.resize(5,vector<char>(5,' '));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            V[i][j] = 'a'+i;
        }
    }
    V2.assign(V.begin(),V.end());
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<V2[i][j] <<',';
        }
        cout<<endl;
    }
}*/
 
 
 
/**************************************************************
    Problem: 1161
    User: ardent_HB
    Language: C++
    Result: Accepted
    Time:130 ms
    Memory:3684 kb
****************************************************************/
