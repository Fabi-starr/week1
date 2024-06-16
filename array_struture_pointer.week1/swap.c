#include <stdio.h>
 void swapvalues(int*a,int*b)
{
int temp;
temp=*a; 
*a=*b;
*b=temp;
}
int main()
{
int value1=35;
int value2=-97;
printf("the value before swap value1:%d\n value2:%d\n",value1,value2);
swapvalues(&value1,&value2);
printf("the value after swap value1:%d\n value2:%d\n",value1,value2);

return  0;

}
