#include<stdio.h>
int main()
{
int a[6] = { 3, 6, -3, 1, 8, 3 };
int i = 3;
int j = 8;
int *p = a;
int *q;
int *r = &a[1];
 q=&i;
 i = *(p + 5);
 j = sizeof (a);
 j = a[a[a[0]]];
 r[2] = p[2] + a[1];
*q += *p * *r;
printf("The value in pointer p are %d\n",*p);
printf("The value in pointer r is %d\n",*r);
printf("The address of  pointer q are %p\n",q);
printf("The value in pointer p are %d\n",*p);
printf("The value i is %d\n",i);
printf("The value of j is %d\n",j);
return 0;
}
