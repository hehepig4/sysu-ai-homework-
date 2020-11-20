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
	return 0;
}


/*------------------------------------------------------------------------------------*/

//动态数组方案（其实是在手搓class），有兴趣可以看看，人可能犯傻，欢迎指正
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _dynamicarr
{
	int* data;
	int capability;
	int (*add)(int);
	int (*isexist)(int);     //in fact it's bool
}dynamicarr;

dynamicarr* thisArr=NULL;     //"this" pointer

int addnum(int add)  //什么叫省空间啊.jpg
{
	if(thisArr->isexist(add))    
		return 0;
	int* newSpace=(int*)malloc(sizeof(int)*(thisArr->capability+1));
	if(newSpace==NULL)
	{
		puts("ERROR!");
		exit(0);
	}
	if(thisArr->capability)
	{
		memcpy(newSpace,thisArr->data,thisArr->capability*sizeof(int));
		free(thisArr->data);
	}
	*(newSpace+thisArr->capability)=add;
	++(thisArr->capability);
	thisArr->data=newSpace;
	return 1;
}

int searchfornum(int target)
{
	for(int i=0;i<thisArr->capability;++i)
		if(thisArr->data[i]==target)
			return 1;
	return 0;
}

dynamicarr* newArr()     //constructor
{
	thisArr=(dynamicarr*)malloc(sizeof(dynamicarr));
	if(thisArr==NULL)
	{
		puts("ERROR!");
		exit(0);
	}
	thisArr->data=NULL,thisArr->capability=0;
	thisArr->add=addnum,thisArr->isexist=searchfornum;
	return thisArr;
}

int main()
{
	dynamicarr*  array=newArr();
	int input=0;
	for(int i=0;i<20;++i)
	{
		scanf("%d",&input);
		printf("%d\n",input);
		array->add(input);
	}
	for(int i=0;i<array->capability;++i)
		printf("%d ",array->data[i]);
	getchar();
}
*/


/*--------------------------------------------------------*/


//原方案     注意c编译器无法编译
/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;//可变数组 书上说visualc++用不了书上的可变数组 确实用不了 所以不用了
int x;
bool fx = false;
int main() {
	scanf("%d", &x);
	a.push_back(x);
	for (int i = 0; i < 19; i++) {
		scanf("%d", &x);
		for (vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter) { //遍历数组，可以自行实现�
			if (*iter == x) {
				fx = true;
				break;
			}
		}
		if (!fx) a.push_back(x);
		fx = false;
	}
	for (vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter) printf("%d ", *iter); //遍历数组，可以自行实现�
}*/



