#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
    int priority,position;
    node* next;
    };
struct CLL{
    node *first,*head;
    };
bool myfn(int i,int j)
{
    return i>j;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int temp_pr[n];
        for(int i=0;i<n;i++)
        scanf("%d",&temp_pr[i]);

        /*cout<<"****************************\n";
        for(int i=0;i<n;i++)
        cout<<temp_pr[i]<<"  ";
        cout<<endl;
        cout<<"****************************\n";*/
        CLL page;
        node* newnode;
        newnode=new node;
        newnode->priority=temp_pr[0];
        newnode->position=0;
        page.first=newnode;page.head=newnode;page.head->next=page.first;
        for(int i=1;i<n;i++)
        {
            node* newnode;
            newnode=new node;
            newnode->priority=temp_pr[i];
            newnode->position=i;
            page.head->next=newnode;
            page.head=page.head->next;
            page.head->next=page.first;
        }
        sort(temp_pr,temp_pr+n,myfn);
        page.head=page.first;
        int count=0,p=0,printed=m-1;
        /*cout<<"list.....................\n";
        node* dptr;
        cout<<page.first->priority<<"  "<<page.first->position<<endl;
        dptr=page.first->next;
        while(dptr!=page.first)
        {
            cout<<dptr->priority<<"  "<<dptr->position<<endl;
            dptr=dptr->next;
        }

        cout<<"...........................\n";*/
        while(printed!=m)
        {
            if(page.head->priority==temp_pr[p])
            {
                p++;count++;printed=page.head->position;
                //cout<<printed<<"**\n";
            }
            page.head=page.head->next;
        }
        cout<<count<<endl;
    }
}
