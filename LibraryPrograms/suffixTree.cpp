#include<iostream>
#include<queue>

struct node{
    char c;
    node* next[26];
};

node* createSuffixTree()
{
    node* root = new node;
    root->c = NULL;
    return root;
}

void append(node* root, char c)
{
    while()
}

void make(node* root, string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        append(root, s[i]);
    }
}

/*-------------------------------------------------------*/

void dfs(node* root)
{
    cout<<root->c<<endl;
    for(int i = 0; i < 26; i++)
    {
        if(root->next[i])
            dfs(root->next[i]);
    }
}

void printLevelBy(node* root)
{
    queue<node*> *q1, *q2;
    q1 = new queue<node*>;
    q2 = new queue<node*>;

    q1->push(root);
    while(!q1->empty())
    {
        while(!q1->empty())
        {
            node* current = q1->front();
            cout<<current->c<<" ";
            q1->pop();
            for(int i = 0; i < 26; i++)
            if(current->next[i])
                q2->push(current->next[i]);
        }
        cout<<endl;
        queue<node*> *temp;
        temp = q1;
        q1 = q2;
        q2 = temp;
    }
}

int main()
{
    node* root = create();
    make(root, "abac");
    printLevelBy(root);

    cout<<"Dfs:\n";
    dfs(root);
}
