/** Binary Indexed Tree

int a[10];
bit b(a,10);

// i, j, k as in the original array a;
sum(k)   -> returns sum 1..k inclusive
sum(i,j) -> returns sum i..j inclusive
set(k,x) -> updates kth element to x

**/

#include<math.h>
#include<iostream>
#include<vector>
using namespace std;
class bit{
    vector<int> a;
    int logSizeOfTree;
    int sizeOfTree;
public:
    void getVector(int n)
    {
        logSizeOfTree = ceil(log2(n));
        if(logSizeOfTree == 0)
            logSizeOfTree++;
        logSizeOfTree++;
        sizeOfTree = (1<<logSizeOfTree);
        a.resize(sizeOfTree);
    }

    bit(int n)
    {
        getVector(n);
        cout<<a.size()<<endl;
    }

    bit(int b[], int n)
    {
        getVector(n);
        int i = 1<<(logSizeOfTree-1);
        for(int j = 0;j<n;j++,i++)
        {
            a[i]=b[j];
        }
        for(;i<sizeOfTree;i++)
        {
            a[i] = 0;
        }

        makeTree();
    }

    void makeTree()
    {
        int lastIndex = sizeOfTree - 1;
        for(int i = lastIndex/2; i>=1; i--)
        {
            a[i] = a[2*i] + a[2*i + 1];
        }
    }

    void set(int k, int x)
    {
        int indexInTree = (1<<logSizeOfTree-1) + k;
        a[indexInTree] = x;
        while(indexInTree > 1)
        {
            indexInTree /=2;
            a[indexInTree] = a[2*indexInTree] + a[2*indexInTree + 1];
        }
    }

    long long sum(int k) // 1 to kth
    {
        int indexInTree = (1<<logSizeOfTree-1) + k;

        long long sum = 0;
        while(1)
        {
            if(indexInTree == 1)
                return a[indexInTree];

            if(indexInTree & 1)
            {
                indexInTree /= 2;
            }
            else
            {
                sum += a[indexInTree];
                if(!(indexInTree & (indexInTree-1))) // index is power of 2 :: i.e has no left neighbour
                    return sum;

                indexInTree = (indexInTree - 1) / 2;
            }
        }
    }

    long long sum(int i, int j)
    {
        if(i == 0)
            return sum(j);

        return sum(j) - sum(i-1);
    }

    void dispTree()
    {
        for(int i=0; i < a.size(); i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
};
int main()
{
    int a[] = {8,-9,10,11,12,13,14,15};
    bit b(a,8);
    b.set(0,1);
    for(int i = 0; i < 8; i++)
        cout<<b.sum(i)<<endl;
    cout<<endl;
    cout<<b.sum(5,7)<<endl;
    b.set(6,15);
    b.dispTree();
    cout<<b.sum(5,7);
}
