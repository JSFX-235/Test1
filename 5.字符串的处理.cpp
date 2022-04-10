#include<stdio.h>
int main()
{
	int n,i,j;
	int count=1,nums[n]={0},character[n]={0};
	char ch[9][80],final[800];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
	    getchar();	
		for(j=0;j<80;j++)
		{
			scanf("%c",&ch[i][j]);
			if(ch[i][0]=='.'||(ch[i][j]=='\n'&&ch[i][j-1]!='.'))
			{
				i=i-1;
				n=n-1;
				break;
			}else if(/*ch[i][j]=='.'||*/ch[i][j]=='\n')
			{
				break;
			}else if(ch[i][j]>='0'&&ch[i][j]<='9')
			{
				nums[i]=nums[i]+1;
			}else if((ch[i][j]>='A'&&ch[i][j]<='Z')||(ch[i][j]>='a'&&ch[i][j]<='z'))
			{
				character[i]=character[i]+1;
			}
		}
	}
	final[0]=n;
    for(i=0;i<=n;i++)
	{
		for(j=0;j<2;j++)
		{
			if(nums[i]==1)
			{
				final[count]='0';
				count=count+1;
				final[count]=ch[i][0];
				count++;
				break;
			}else
			{
				final[count]=ch[i][j];
				count=count+1;
			}
		}
		if(character[i]<10)
			{
				final[count]='0';
				count=count+1;
				final[count]=character[i];
			}else
			{
				final[count]=character[i];
				count=count+2;
			}
    }
	for(i=0;i<n;i++)
	{
		for(j=0;j<80;j++)
		{
			if(ch[i][j]=='.')
			{
				count--;
				break;
			}else if((ch[i][j]>='A'&&ch[i][j]<='Z')||(ch[i][j]>='a'&&ch[i][j]<='z'))
			{
				if(ch[i][j]>='A'&&ch[i][j]<='Y')
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
	}
	for(i=0;i<=count;i++)
	{
		printf("%c",final[i]);
	}																															
	return 0;
}
