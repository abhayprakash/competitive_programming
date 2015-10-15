#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct node{
    char value;
    bool isEndOfWord;
    int num_PrefixOf;
    node* child[26];
};

node* createTrie()
{
    node* root = new node;
    root->value = '\0';
    root->isEndOfWord = false;
    root->num_PrefixOf = 0;

    return root;
}

bool isPresent(node* trie, string s)
{
    node* current = trie;
    int i = 0;
    while(i < s.length())
    {
        if(current->child[s[i]-'a'])
            current = current->child[s[i]-'a'];
        else
            return false;
        i++;
    }
    return current->isEndOfWord;;
}

void insert(node* trie, string s)
{
    if(isPresent(trie, s))
        return;

    node* current = trie;
    int i = 0;
    while(current->child[s[i]-'a'] != NULL && i < s.length())
    {
        current = current->child[s[i]-'a'];
        current->num_PrefixOf++;
        i++;
    }

    while(i < s.length())
    {
        if(!current->child[s[i] - 'a'])
            current->child[s[i] - 'a'] = createTrie();
        current = current->child[s[i] - 'a'];
        current->num_PrefixOf++;
        current->value = s[i];
        i++;
    }

    current->isEndOfWord = true;
}

void destroy(node* root)
{
    for(int i=0;i<26;i++)
    {
        if(root->child[i])
        {
            destroy(root->child[i]);
            break;
        }
    }
    delete(root);
}

void remove(node* trie, string s)
{
    if(isPresent(trie, s) == false)
    {
        cout<<"NOT PRESENT " << s << endl;
        return;
    }

    node* current = trie;
    int i = 0;
    while(i < s.length())
    {
        (current->child[s[i]-'a'])->num_PrefixOf--;
        if((current->child[s[i]-'a'])->num_PrefixOf == 0)
        {
            node* todel = current->child[s[i]-'a'];
            current->child[s[i]-'a'] = NULL;
            destroy(todel);
            return;
        }
        current = current->child[s[i]-'a'];
        i++;
    }
    current->isEndOfWord = false;
}

void print(string s, vector<char> buff)
{
    cout<<s;
    for(int i = 0; i < buff.size(); i++)
        cout<<buff[i];
    cout<<endl;
}

void printAll(string s, node* root, vector<char> buff)
{
    if(root->isEndOfWord)
        print(s,buff);
    vector<char> buf;
    for(int i = 0; i < 26; i++)
    {
        if(root->child[i])
        {
            buf = buff;
            buf.push_back((char)((int)'a' + i));
            printAll(s,root->child[i], buf);
        }
    }
}

void suggestAhead(node* trie, string s)
{
    node* current = trie;
    int i = 0;
    while(i < s.length())
    {
        if(current->child[s[i]-'a'])
        {
            current = current->child[s[i]-'a'];
        }
        else
        {
            cout<<"No suggestions\n";
            return;
        }
        i++;
    }
    vector<char> buff;
    printAll(s, current, buff);
}

int number_prefixOf(node* trie, string s)
{
    if(s=="")
    {
        int toret=0;
        for(int i = 0; i < 26; i++)
        {
            if(trie->child[i])
                toret += trie->child[i]->num_PrefixOf;
        }
        return toret;
    }

    node* current = trie;
    int i = 0;
    while(i < s.length())
    {
        if(current->child[s[i]-'a'])
            current = current->child[s[i]-'a'];
        else
            return 0;
        i++;
    }
    return current->num_PrefixOf;
}

int main()
{
    node* trie = createTrie();
    insert(trie, "b");
    insert(trie, "boy");
    insert(trie, "boys");
    insert(trie, "abhay");
    insert(trie, "another");
    insert(trie, "ann");
    insert(trie, "anot");
    //remove(trie, "abhay");
    //cout<<isPresent(trie,"abhay");
    //cout<<isPresent(trie,"aabhayp");
    //cout<<isPresent(trie,"abha");
    //suggestAhead(trie, "bo");
    //remove(trie, "boy");
    //cout<<isPresent(trie, "boy");
    //suggestAhead(trie, "bo");
    cout<<number_prefixOf(trie, "boys");
}
