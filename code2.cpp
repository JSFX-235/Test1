#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	unsigned int m,n,recordtemp,swaptemp,matrix[7][7];
	//recordtemp为记录的临时数，swap为交换的临时数，无符号整型二维数组matrix存入随机生成的矩阵  
	int i,j,leftuprow,leftupcol,rightdownrow,rightdowncol;
	//leftuprow为上行数，leftupcol为左列数，rightdownrow为下行数，rightdowncol为右列数
	srand(time(NULL));
	m=rand()%5+3;  //生成随机数作为行
	n=rand()%5+3;  //生成随机数作为列
	printf("%-4u%-4u\n",m,n);
	printf("原矩阵为:\n");
	for(i=0;i<m;i++)  //输出原矩阵
	{
		for(j=0;j<n;j++)
		{
			matrix[i][j]=rand()%10;  //生成矩阵中的随机数[0，10)
			printf("%-4u",matrix[i][j]);
		}
		printf("\n");
	}
	
	leftuprow=0;
	leftupcol=0;
	rightdownrow=m-1;
	rightdowncol=n-1;
	recordtemp=matrix[0][0];
	while(leftuprow<=rightdownrow&&leftupcol<=rightdowncol)
	//当上行数小于下行数且左列数小于右列数时，满足循环
	{
		for(i=leftupcol;i<=rightdowncol;i++)
		//从左到右的行向后移动一位
		{
			swaptemp=recordtemp;
			recordtemp=matrix[leftuprow][i];
			matrix[leftuprow][i]=swaptemp;
		}
		for(j=leftuprow+1;j<=rightdownrow;j++)
		//从上到下的列向下移动一位
		{
			swaptemp=recordtemp;
			recordtemp=matrix[j][rightdowncol];
			matrix[j][rightdowncol]=swaptemp;
		}
		if(leftuprow==rightdownrow||leftupcol==rightdowncol)
		//如果上行数与下行数相等后左列数与右列数相等，不再进行下面的移位操作
		{
			break;
		}
		for(i=rightdowncol-1;i>=leftupcol;i--)  //从右到左的行向左移动一位
		{
			swaptemp=recordtemp;
			recordtemp=matrix[rightdownrow][i];
			matrix[rightdownrow][i]=swaptemp;
		}
		for(j=rightdownrow-1;j>leftuprow;j--)  //从下到上的列向上移动一位
		{
			swaptemp=recordtemp;
			recordtemp=matrix[j][leftupcol];
			matrix[j][leftupcol]=swaptemp;
		}
		leftuprow++;
		leftupcol++;
		rightdownrow--;
		rightdowncol--;
	}
	matrix[0][0]=recordtemp;  //将最后的一个数赋给matrix[0][0]
	printf("移动后矩阵为:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%-4u",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}