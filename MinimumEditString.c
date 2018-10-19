#include<stdio.h>
#include<string.h>
int min(int i,int j,int k)
{
	if(i<=j && i<=k)
	{
		return i;
	}
	if(j<=k && j<=i)
	{
		return j;
	}
	if(k<=j && k<=i)
	{
		return k;
	}
}

int main()
{
	int i,j,mat[102][102] = {0};

	char str1[101],str2[101];
	
	scanf("%s",&str1);
	scanf("%s",&str2);
	
	
	for(i=0 ;i <= strlen(str1) ;i++)
	{ 
		mat[0][i] = i ;
			
	}
	for(i=0 ;i <= strlen(str2);i++)
	{ 
		mat[i][0] = i; 
		
	}
	
	
	for(i=1;i <= strlen(str2);i++)
	{
		for(j=1;j <= strlen(str1);j++)
		{
			if(str2[i-1]==str1[j-1])
			{
				mat[i][j] = mat[i-1][j-1];
			}
			else
			{
				mat[i][j] = min(mat[i-1][j-1],mat[i][j-1],mat[i-1][j]) + 1;
			}
			
		}
	
	}

	
	printf("%d",mat[strlen(str2)][strlen(str1)]);

		return 0;
}
