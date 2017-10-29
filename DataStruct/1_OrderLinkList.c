# include<stdio.h>
# include<stdlib.h>
# define MAXSIZE 1024
typedef int elemtype;
typedef struct sequlist
{
	elemtype data[MAXSIZE];
	int last;
}SequenList;
void menu();
SequenList * Init_SequenList();
int SequenList_Length(SequenList*L);
int Insert_SequenList(SequenList*L,elemtype x,int i);
int Delete_SequenList(SequenList*L,int i);
elemtype GetData_SequenList(SequenList*L,int i);
int Search_SequenList(SequenList*L,elemtype key);
void Print_SequenList(SequenList*L);
/*
void Union_SequenList(SequenList*LA,SequenList*LB);
int InsertData_SequenList(SequenList*L,elemtype x);
void Merge_SequenList(SequenList *A,SequenList *B,SequenList*C);
*/



int main()
{
	 int d,x,i,key;
	 SequenList*L;
	 L=Init_SequenList();
	 while(1)
	 {
		 menu();
		 scanf("%d",&d);
		 switch(d)
		 {
			case 1: printf("顺序表长度：%d\n",SequenList_Length(L));break;
			case 2: 
				 {
					printf("请输入插入的数据和插入的位置：\n");
					scanf("%d%d",&x,&i);
					if(Insert_SequenList(L,x,i)==0)
						break;
					else
						printf("插入成功！");
						break;
				 }
			case 3:
				{
					printf("请输入删除节点的位置：");
					scanf("%d",&i);
					if(Delete_SequenList(L,i)!=0)
						printf("删除成功！");
					break;
				}
			case 4:
				{
					printf("请输入结点位置：");
					scanf("%d",&i);
					if(GetData_SequenList(L,i))
						printf("查找的数据为：%d\n",GetData_SequenList(L,i));
					break;
				}
			case 5:
				{
					printf("请输入查找的元素：");
					scanf("%d",&key);
					if(Search_SequenList(L,key))
						printf("顺序表中位置为：%d\n",Search_SequenList(L,key));
					else
						printf("查找失败！\n");
					break;
				}
			case 6:
				{
					printf("顺序表为：\n");
					Print_SequenList(L);
					break;
				}
			case 7:
				exit(0);
			default:break;
		 }
		 system("pause");
		 system("cls");
	 }
	 return 0;
}

void menu()
{
	
	printf("1.顺序表长度\n");
	printf("2.插入数据\n");
	printf("3.删除数据\n");
	printf("4.取出数据元素\n");
	printf("5.顺序表查找元素\n");
	printf("6.顺序表遍历\n");
	printf("7.退出系统\n");
	/*
	printf("7.求集合A U B\n");
	printf("8.插入数据且递增排列特性不变\n");
	*/
	printf("________________________________\n");

}
int SequenList_Length(SequenList*L)
{
	return (L->last+1);
}
SequenList * Init_SequenList()
{
	SequenList*L;
	L=(SequenList *)malloc(sizeof(SequenList));
	L->last=-1;
	return L;
}
int Insert_SequenList(SequenList*L,elemtype x,int i)
{
	int j;
	if(L->last>=MAXSIZE-1)
	{
		printf("表满！数据溢出\n");
		return 0;
	}
	if(i<1||i>L->last+2)
	{
		printf("非法位置！\n");
		return 0;
	}
	for(j=L->last;j>=i-1;j--)
	{
		L->data[j+1]=L->data[j];
	}
	L->data[i-1]=x;
	L->last=L->last+1;
	return (1);
}
int Delete_SequenList(SequenList*L,int i)
{
	int j;
	if(i<1||i>L->last+1)
	{
		printf("非法位置！\n");
		return 0;
	}
	else
	{
		for(j=i;j<=L->last;j++)
			L->data[j-1]=L->data[j];
		L->last--;
	}
	return 1;
}
elemtype GetData_SequenList(SequenList*L,int i)
{
	if(i<1||i>L->last+1)
	{
		printf("非法位置！\n");
		return 0;
	}
	else
	{
		return (L->data[i-1]);
	}
}
int Search_SequenList(SequenList*L,elemtype key)
{
	int i;
	for(i=0;i<=L->last;i++)
		if(L->data[i]==key)
			return (i+1);
	return (0);
}
void Print_SequenList(SequenList*L)
{
	int i;
	for(i=0;i<=L->last;i++)
	{
		printf("a[%2d]=%4d\t",i+1,L->data[i]);
		if((i+1)%5==0)
			printf("\n");
	}
}
/*
void Union_SequenList(SequenList*LA,SequenList*LB)
{
	int i,len_la,k;
	elemtype x;
	len_la=SequenList_Length(LA);
	for(i=0;i<=LB->last;i++)
	{
		x=GetData_SequenList(LB,i);
		k=Search_SequenList(LA,x);
		if(k==0)
		{
			Insert_SequenList(LA,x,len_la+1);
			len_la=SequenList_Length(LA);
		}
	}
}
int InsertData_SequenList(SequenList*L,elemtype x)
{
	int i;
	i=L->last;
	if(i>MAXSIZE-1)
	{
		printf("overflow!\n");
	}
	while(i>0&&L->data[i]>x)
	{
		L->data[i+1]=L->data[i];
		i--;
	}
	L->data[i+1]=x;
	L->last++;
	return (1);
}
void Merge_SequenList(SequenList *A,SequenList *B,SequenList*C)
{
	int ia,ib,ic;
	ia=0,ib=0,ic=0;
	while(ia<=A->last&&ib<=B->last)
		if(A->data[ia]<B->data[ib])
			C->data[ic++]=A->data[ia++];
		else
			C->data[ic++]=B->data[ib++];
	while(ia<=A->last)
		C->data[ic++]=A->data[ia++];
	while(ib<=B->last)
		C->data[ic++]=B->data[ib++];
	C->last=ic-1;
}
*/
