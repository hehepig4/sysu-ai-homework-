//定长数组方案

#include<stdio.h>

int main()
{
	int input[20]={0};
	int temp=0,count=0,existed=0;
	for(int i=0;i<20;++i)
	{
		existed=0;
		scanf("%d",&temp);
		for(int j=0;j<count;++j)
		{
			if(temp==input[j])
			{
				existed=1;
				break;
			}
		}
		if(!existed)
		{
			input[count]=temp;
			++count;
		}
	}
	for(int i=0;i<count;++i)
		printf("%d ",input[i]);
	getchar();
	getchar();
	return 0;
}


/*------------------------------------------------------------------------------------*/

