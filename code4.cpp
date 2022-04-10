#include<stdio.h>
void bubble_sort(int a[],int num)  //函数用于冒泡排序
{
	int i,j,swap;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap=a[j+1];
				a[j+1]=a[j];
				a[j]=swap;
			}
		}
	}
}
int main()
{
	int m,n,i,j,min;
	scanf("%d %d",&m,&n);
	int arr[n],ans[m];
	//整型数组arr用于存入n个学生的快递数，ans用于存入m台机器不断变化的扫码时间
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(i<m)
		{
			ans[i]=arr[i];  //数组ans先存入前m位学生的快递数
		}
	}
	for(j=m;j<=n;j++)
	{
		bubble_sort(ans,m);
	//每空出一台机器就进行冒泡排序，找出扫码时间最少的那台机器，以便下一位同学下一轮接上
		ans[0]=ans[0]+arr[j];
	}
	printf("%d",ans[m-1]);  //输出时间最长的机器所用的时间
	return 0;
}