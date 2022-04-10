#include<stdio.h>
int main()
{
	int i=0,count=0,j;  //count用于记录将正整数n化为1的步骤数
	unsigned int n;
	char ch[100];  //字符数组ch用于存入进行每步操作使用的字符
	scanf("%u",&n);
	do{
		if(n%2==1)  //为奇数的情况
		{
			ch[i]='-';
			i++;
			n=n-1;
			count++;
		}
		else  //其他为偶数的情况
		{
			ch[i]='^';
			i++;
			n=n/2;
			count++;
		}
	}while(n>1);
	printf("%d\n",count);
	for(j=0;j<count;j++)
	{
		printf("%c",ch[j]);
	}
	return 0;
}