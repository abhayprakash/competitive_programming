#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        int ans = 0;
        while(n!=1)
        {
            n>>=1;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
