/**
        Segment Tree : actual tree formed instead of using array
------------------------------------------------------------------------------------
Example:
int myFn()
{
    return required;
}
int main()
{
    segTree T;
}

Interface:--------------------------------------------------------------------------
1. T.make(arrayName, arraySize, myFn); // myFn describes what to store from children
   - min, max, sum or anything else.
2. T.update(index, value);
3. T.query(indexI, indexJ);

Note: Be cautious while updating a value, a[] is originally used to build tree
      But be sure to use T.update(index, value), after making a[index] = value;

Limitation: -1 is taken as senitel value at place, so -ve values can't be stored in tree.
**/

#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

class segTree{
    struct node{
        int value; // may be sum, min or max : as reqd.
        node *left, *right;
    };
    node * root;
    int size;

    int (*qFunc)(int, int);

public:
    node* buildTree(int arr[], int i, int j)
    {
        node* subTreeRoot = new node;
        if(i==j)
        {
            subTreeRoot->left = NULL;
            subTreeRoot->right = NULL;
            subTreeRoot->value = arr[i];
            return subTreeRoot;
        }

        int mid = (i + j)/2;
        subTreeRoot->left = buildTree(arr,i,mid);
        subTreeRoot->right = buildTree(arr,mid+1,j);
        subTreeRoot->value = qFunc(subTreeRoot->left->value, subTreeRoot->right->value);

        return subTreeRoot;
    }

    void make(int arr[], int arrSize, int (*fnToUse)(int, int))
    {
        qFunc = fnToUse;
        size = arrSize;
        root = buildTree(arr, 0,arrSize-1);
    }

    int queryHelper(node* subTreeRoot, int i, int j, int rmin, int rmax)
    {
        if(j < rmin || i > rmax)
            return -1;
        if(i<=rmin && rmax<=j)
            return subTreeRoot->value;

        int midOfRange = (rmin + rmax) / 2;

        int leftVal = queryHelper(subTreeRoot->left, i, j, rmin, midOfRange );
        int rightVal = queryHelper(subTreeRoot->right, i,j, midOfRange+1, rmax);

        if(leftVal == -1 && rightVal == -1)
            return -1;
        else if (leftVal == -1)
            return rightVal;
        else if(rightVal == -1)
            return leftVal;
        else
            return qFunc(rightVal, leftVal);
    }

    int query(int i, int j) // assuming valid case will be sent
    {
        int toret = queryHelper(root, i, j, 0, size-1);
        if(toret == -1)
        {
            cout<<"Not found or some error";
        }
        return toret;
    }

    void updateHelper(int i, node* subTreeRoot, int rmin, int rmax, int value)
    {
        if(rmin==i && rmax==i)
        {
            subTreeRoot->value = value;
            return;
        }
        if(i>=rmin && i<=rmax)
        {
            int mid = (rmin + rmax)/2;
            updateHelper(i, subTreeRoot->left, rmin, mid, value);
            updateHelper(i, subTreeRoot->right, mid+1, rmax, value);
            subTreeRoot->value = qFunc(subTreeRoot->left->value, subTreeRoot->right->value);
        }
    }

    void update(int i, int value)
    {
        updateHelper(i, root, 0, size-1, value);
    }

    int test()
    {
        return root->value;
    }
};

int myFn(int a, int b)
{
    return a+b;
}

bool testTheCode(int a[],int n)
{
    int fromCode;
    int fromBrute;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            segTree T;
            T.make(a, n, myFn);
            int index = rand()%n;
            int value = rand() % 100;
            cout<<index<<" : "<<value<<endl;
            a[index] = value;
            T.update(index,value);
            fromCode = T.query(i,j);
            /*------------------------*/
            fromBrute = 0; // for testing sum -> make it 0, min -> make it LARGE, max -> make it SMALL
            for(int ii=i; ii<=j; ii++)
            {
                fromBrute = myFn(fromBrute, a[ii]);
            }
            /*------------------------*/
            if(fromBrute != fromCode)
            {
                cout<<"Not matched: ";
                cout<<i<<" "<<j<<" "<<fromBrute<<" "<<fromCode<<endl;
                return false;
            }
            else
            {
                cout<<"Matched: ";
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    return true;
}

int main()
{
    int a[] = {1,3,5,2,9,11,45,21,14,42,32};
    /*
    segTree T;
    T.make(a,sizeof(a)/sizeof(a[0]), myFn);
    T.update(7,100);
    //*/
    if(testTheCode(a,sizeof(a)/sizeof(a[0])))
        cout<<"All cases correct\n";
    else
        cout<<"Not matched\n";
    //*/
}
