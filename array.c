#include<stdio.h>
int main()
{
int a[5]={12,30,40,50,60};
int *p=&a[4];
while(p>=a){
printf("the Value is:%d\n",*p);
p--;
}
return 0;
}
