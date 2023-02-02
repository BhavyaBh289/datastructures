#include<stdio.h>
#define min(a,b) a<b?a:b
int main()
{
    int n,x,i,a,b,c,offset;
    printf("\n  ENTER NO. OF ELEMENTS -  ");
    scanf("%d", &n);
    int array[n];
    printf("\n  ENTER THE ELEMENTS - ");
    for(i=0;i<n;i++){
        scanf("%d", &x);
        array[i]=x;
        printf("%d",x);
    }
    for(i=0;i<n;i++){
        printf("%d ", &array[i]);
    }
    printf("    ENTER ELEMENT TO SEARCH - ");
    scanf("%d", &x);
    a=0;
    b=1;
    c=a+b;
    while(c<n)
    {
        a=b;
        b=c;
        c=a+b;
    }
    offset = -1;
    while(c>1)
    {
        i=min(offset+a, n-1);
        if (array[i] <x)
        {
            c=b;
            b=a;
            a=c-b;
            offset = i;
        }
        else if (array[i]>x)
        {
            c=a;
            b=b-a;
            a=c-b;
        }
        else
        {
            printf("  \n  ELEMENT %d IS FOUND AT INDEX %d", x, i);
            return 0;
        }
    }
    if(b && array[offset+1]==x)
    {
        printf("  \n  ELEMENT %d IS FOUND AT INDEX %d", x, offset);
        return 0;
    }
    printf("  \n  ELEMENT NOT FOUND");

}
