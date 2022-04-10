#include<stdio.h>
int main()
{
	int n,i,j,k,sum;
	char ch[9][80],final[800];
	//二维字符数组ch用于遍历数据，一维字符数组final用于存入转换后的信息
	scanf("%d",&n);  //输入总条数n,且n(0,10)
	int count=1,nums[n]={0},character[n]={0};
	/*count用于记录字符数组final中的元素个数，整型数组nums用于统计每行数据的编号位数
	（为一位数还是二位数），整型数组character用于记录每行的字母个数*/
	sum=n;  //sum记录有效数据个数
	getchar();
	for(i=0;i<n;i++)
	{
		j=0;
		do{
			scanf("%c",&ch[i][j]);  //数组遍历
			j++;
		}while(ch[i][j-1]!='\n');
	}
    for(i=0;i<n;i++)
	//统计有效数据个数，记录每行数据编号的位数，记录每行有效数据长度
	{
		j=0;
		do{
			if(ch[i][0]=='.'||(ch[i][j]=='\n'&&ch[i][j-1]!='.'))
			{
				sum=sum-1;  //统计有效数据个数
				ch[i][0]='0';  //标记无效的数据
				break;
			}else if(ch[i][j]>='0'&&ch[i][j]<='9')
			{
				nums[i]=nums[i]+1;  //记录每行数据编号的位数（一位数还是两位数）
			}else if((ch[i][j]>='A'&&ch[i][j]<='Z')||(ch[i][j]>='a'&&ch[i][j]<='z'))
			{
				character[i]=character[i]+1;  //记录每行有效数据长度
			}
			j++;
		}while(ch[i][j]!='.');
    }
    if(sum==0)  //有效数据为0的情况
    {
    	printf("数据无效！");
	}else
	{
		final[0]=sum+48;  //将有效数据条数转换为ASCII码存入字符数组
		for(i=0;i<n;i++)  //每条数据的索引信息（每条四个字符）
		{
			for(j=0;j<2;j++)  //每条数据的编号的处理
			{
				if(ch[i][0]=='0')  //排除无效数据
				{
					break;
				}
				else if(nums[i]==1)  //数据编号为一位数的情况
				{
					final[count]=48;
					count=count+1;
					final[count]=ch[i][j];
					count++;
					break;
				}else  //数据编号为两位数的情况
				{
					final[count]=ch[i][j];
					count=count+1;
				}                       
		    }
		    for(k=0;k<1;k++)  //每条有效数据的长度处理
		    {
		    	if(ch[i][0]=='0')
				{
					break;
				}else if(character[i]<10)  //有效数据长度小于10的情况
			    {
					final[count]='0';
					count=count+1;
					final[count]=character[i]+48;
					count++;
					break;
				}else if(character[i]>=10)  //有效数据长度大于等于10的情况
				{
					final[count]=character[i]/10+48;
					count=count+1;
					final[count]=character[i]%10+48;
					count++;
					break;
				} 
			}
		}
		for(i=0;i<n;i++)  //对每行的有效数据进行数据加密		
		{
		    for(j=0;j<80;j++)
			{
				if(ch[i][0]=='0'||ch[i][j]=='.')
				//排除无效数据，以及'.'在中间排除'.'之后的数据
				{
					break;
				}else if(ch[i][j]>='A'&&ch[i][j]<='Y')
				{
					final[count]=ch[i][j]+33;
					count++;
				}else if(ch[i][j]=='Z')
				{
					final[count]='a';
				}else if(ch[i][j]>='a'&&ch[i][j]<='x')
				{
					final[count]=ch[i][j]-30;
					count++;
				}else if(ch[i][j]=='y'||ch[i][j]=='z')
				{
					final[count]=ch[i][j]-56;
					count++;
				}
			}
		}
		final[count+1]='.';  
		for(i=0;i<=count+1;i++)  //输出破译后的数据
		{
			printf("%c",final[i]);
		}
	}
	return 0;
}
