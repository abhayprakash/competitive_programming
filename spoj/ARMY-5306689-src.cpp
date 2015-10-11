#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int ng,nm;
        scanf("%d%d",&ng,&nm);
        int g_monst[ng+1],m_monst[nm+1];
        for(int i=0;i<ng;i++)
        scanf("%d",&g_monst[i]);
        for(int i=0;i<nm;i++)
        scanf("%d",&m_monst[i]);
        sort(g_monst,g_monst+ng);
        sort(m_monst,m_monst+nm);
        int g_i=0,m_i=0;
        while(g_i<ng&&m_i<nm)
        {
            if(g_monst[g_i]<m_monst[m_i])
            g_i++;
            else if(g_monst[g_i]>m_monst[m_i])
            m_i++;
            else
            m_i++;
        }
        if(g_i==ng)
        printf("MechaGodzilla\n");
        else if(m_i==nm)
        printf("Godzilla\n");
        else
        printf("uncertain\n");
    }
    return 0;
}
