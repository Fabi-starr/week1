#include<stdio.h>
int main()
{
int x=20;
int *p;
int *d;
p=&x;
d=&x;
printf("The value of pointer p is %d\n",*p);
printf("The adress of x is %p\n",p);
*d=30;
printf("The new value of pointer p is %d\n",*p);

return 0;

}
