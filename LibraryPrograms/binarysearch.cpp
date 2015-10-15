#include<iostream>//index_of(search_key,array_name,array_size)
using namespace std;
template<typename T>
int index_of(T search_key,T array[],int low,int high)
{
    if(low>high) return -1;
    int middle=(low+high+1)/2;
    if(array[middle]==search_key)
    return middle;
    else if(search_key<array[middle])
    index_of(search_key,array,low,middle-1);
    else if(search_key>array[middle])
    index_of(search_key,array,middle+1,high);
}
template<typename T>
int index_of(T s,T a[],int size)
{
    return index_of(s,a,0,size-1);
}
/*int main()
{
    int a[]={0,1,2,3,4,5,6,7,8,9,10};
    cout<<index_of(-2,a,0,10);
    return 0;
}*/
