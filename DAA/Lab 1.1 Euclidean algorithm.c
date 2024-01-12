#include<stdio.h>
#include<conio.h>
int main()
{
    int a,b;
    printf("Enter the two numbers\n");
    scanf("%d %d",&a,&b);
    GCD(a,b);
    printf("GCD: %d",GCD(a,b));
}
int GCD(int a,int b)
{
    if (b==0)
    {
        return a;
    }
    else
    {
        return GCD(b,a%b);
    }

}

