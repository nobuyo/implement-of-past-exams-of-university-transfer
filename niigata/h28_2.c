#include <stdio.h>

int ijk(int n)
{
    int temp = n;
    while(temp%5==0)
        temp = temp/5;
    while(temp%3==0)
        temp = temp/3;
    while(temp%2==0)
        temp = temp/2;

    if(temp == 1) return 1;
    else return 0;
}

int main(void)
{
    int i,count=0;
    for(i=1;count<100;i++)
    {
        if(ijk(i)==1)
        {
            printf("%d\n",i);
            count++;
        }
    }
    return 0;
}