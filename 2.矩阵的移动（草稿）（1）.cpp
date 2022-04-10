#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
int main()
{
	 unsigned int m,n,recordtemp,swaptemp,matrix[7][7];
	 int leftuprow,leftupcol,rightdownrow,rightdowncol;
	 srand(time(NULL));
	 m=rand()%5+3;
	 n=rand()%5+3;
	 printf("%u %u\n原矩阵为：\n",m,n);
	 for(int i=0;i<m;i++)
	 {
		  for(int j=0;j<n;j++)
		  {
			   matrix[i][j]=rand()%10;
			   printf("%u ",matrix[i][j]);
		  }
		  printf("\n");
	 }
	
	 leftuprow=0;
	 leftupcol=0;
	 rightdownrow=m-1;
	 rightdowncol=n-1;
	 recordtemp=matrix[0][0];
	 
	 while(leftuprow<=rightdownrow&&leftupcol<=rightdowncol)
	 {
		  for(int j=leftupcol;j<=rightdowncol;j++)
		  {
		   swaptemp=recordtemp;
		   recordtemp=matrix[leftuprow][j];
		   matrix[leftuprow][j]=swaptemp;
		  }
		  for(int i=leftuprow+1;i<=rightdownrow;i++)
		  {
		   swaptemp=recordtemp;
		   recordtemp=matrix[i][rightdowncol];
		   matrix[i][rightdowncol]=swaptemp;
		  }
		  if(leftuprow==rightdownrow||leftupcol==rightdowncol)
		  {
		   break;
		  }
		  for(int j=rightdowncol-1;j>=leftupcol;j--)
		  {
		   swaptemp=recordtemp;
		   recordtemp=matrix[rightdownrow][j];
		   matrix[rightdownrow][j]=swaptemp;
		  }
		  for(int i=rightdownrow-1;i>leftuprow;i--)
		  {
		   swaptemp=recordtemp;
		   recordtemp=matrix[i][leftupcol];
		   matrix[i][leftupcol]=swaptemp;
		  }
		  leftuprow++;
		  leftupcol++;
		  rightdownrow--;
		  rightdowncol--;
	 }
	 matrix[0][0]=recordtemp;
	 
	 printf("变化后矩阵为：\n");
	 for(int i=0;i<m;i++)
	 {
	  for(int j=0;j<n;j++)
	  {
	   printf("%u ",matrix[i][j]);
	  }
	  printf("\n");
	 }
	 
	 return 0;
}