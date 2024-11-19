#include<stdio.h>
void main()
{
    int temp;
    int m,n;
    printf("Enter m and n\n");
    scanf("%d%d",&m,&n);
    while(n>0)
    {
        if(n>m)
        {
            temp=m;
            m=n;
            n=temp;
        }
        m=m-n;
    }
    printf("gcd = %d\n",m);
}