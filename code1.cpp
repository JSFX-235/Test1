#include<stdio.h>
#include<math.h>
int is_prime(long int num) //判断是否是素数的函数
{
	int i;
	if(num==1||(num!=2&&num%2==0))
	{
		return 0;
	}
	else
	{
		for(i=3;i<=sqrt(num);i++)
		{
			if(num%i==0)
			return 0;
		}
	}
	return 1;
}
int main()
{
	long int nums,j,k;
	scanf("%ld",&nums);
	if(nums%2==0||nums==5)  //先判断nums是否为偶数和奇数5
	{
	    for(j=2;j<nums;j++)
	    {
			if(is_prime(j))
			{
				if(is_prime(nums-j))
				{
					printf("%ld = %ld + %ld",nums,j,nums-j);
					break;
				}
			}
	    }
	}
	else  //其他情况下nums为大于5的奇数
	{
		for(k=2;k<nums;k++)
		{
			if(is_prime(k))
			{
				if(is_prime(nums-3-k))
				{
					if(k<3&&nums-k-3<3)
					{
						printf("%d = %d + %d + %d",nums,k,nums-k-3,3);
						break;
					}else if(k<3&&nums-k-3>=3)
					{
						printf("%d = %d + %d + %d",nums,k,3,nums-k-3);
						break;
					}else
					{
						printf("%d = %d + %d + %d",nums,3,k,nums-3-k);
						break;
					}
				}
			}
		}
	}
	return 0;
}