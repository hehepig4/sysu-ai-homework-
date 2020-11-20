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
//To do:用c实现类似于vector的动态数组&空间最优化(时间效率qtm)    以及定长数组方案

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _dynamicarr
{
	char* data;
	char capability;
	char (*add)(char);
	char (*isexist)(char);     //in fact it's bool
}dynamicarr;

dynamicarr* thisArr=NULL;     //"this" pointer

char addnum(char add)  //什么叫省空间啊.jpg
{
	if(thisArr->isexist(add))    
		return 0;
	char* newSpace=(char*)malloc(sizeof(char)*(thisArr->capability+1));
	if(newSpace==NULL)
	{
		puts("ERROR!");
		exit(0);
	}
	if(thisArr->capability)
	{
		memcpy(newSpace,thisArr->data,thisArr->capability*sizeof(char));
		free(thisArr->data);
	}
	newSpace[thisArr->capability]=add;
	++(thisArr->capability);
	thisArr->data=newSpace;
	return 1;
}

char searchfornum(char target)
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
	char input=0;
	for(int i=0;i<20;++i)
	{
		input=i;
		//scanf("%d",&input);
		//printf("%d\n",input);
		array->add(input);
	}
	for(int i=0;i<array->capability;++i)
		printf("%d ",array->data[i]);
}



