# include<stdio.h>
# include<stdlib.h>

typedef int elemtype;
typedef struct node
{
	elemtype data;
	struct node* next;
}LinkList;


LinkList * Create_LinkListF();//创建链表
int Print_LinkList(LinkList * head);//链表输出
int LinkList_Length(LinkList *head);//单链表的长度
int GetData_LinkList(LinkList*head,int i);//按序号查找单链表
int Search_LinkList(LinkList*head,elemtype key);//按值查找单链表
void InsertAfter_LinkList(LinkList *p,LinkList *s);//单链表后插
int InsertNo_LinkList(LinkList *head,LinkList *s,int i);//在指定序号插入
int DeleteAfter_LinkList(LinkList*p);//删除后继结点
int DeleteValue_LinkList(LinkList *head,int value);//删除指定值位置结点 
int DeleteNode_LinkList(LinkList*head,LinkList *p);//删除指定位置的结点
int DeleteNo_LinkList(LinkList*head,int i);//删除指定位置的结点
void Sort_LinkList(LinkList *head);//聊表排序 
LinkList* SetNull_LinkList(LinkList*head);//置空表
void menu();
 


int main()
{
	int d,i,key,value;
	LinkList *head=NULL,*s;
	
	while(1)
	{	menu();
		scanf("%d",&d);
		switch(d)
		{
			case 0:
				{
					head=Create_LinkListF();
					if(head!=NULL)
						printf("创建成功!\n");
					break;
				}
			case 1:
				{
					if(Print_LinkList(head)==0)
						printf("链表为空！\n");
					break;
				}
			case 2:
				{
					printf("单链表的长度为：%d\n",LinkList_Length(head));
					break;
				}
			case 3:
				{
					printf("请输入查找序号：");
					scanf("%d",&i);
					value=GetData_LinkList(head,i);
					if(!value)
						printf("位置非法！\n");
					else
						printf("查找的数据为：%d\n",value);
					break;
				}
			case 4:
				{
					printf("请输查找的值：");
					scanf("%d",&key);
					value=Search_LinkList(head,key);
					if(value<1||value>LinkList_Length(head))
						printf("未查找到该数值！\n");
					else
						printf("查找的数值为第%d个结点\n",value);
					break;
				}
			case 5:
				{
					printf("请输入你插入的位置；");
					scanf("%d",&i);
					printf("请输入你插入的值：");
					s=(LinkList *)malloc(sizeof(LinkList));
					scanf("%d",&s->data);
					s->next=NULL;
					value=InsertNo_LinkList(head,s,i);
					if(!value)
					{
						printf("插入失败或则位置非法！\n");
					}
					else
						printf("插入成功！\n"); 
					break;
				} 
			case 6:
				{
					printf("请输入你删除的值：");
					scanf("%d",&i);
					value=DeleteValue_LinkList(head,i);
					if(!value)
					{
						printf("删除失败或则位置非法！\n");
					}
					else
						printf("删除成功！\n");
					break;
				}
			case 7:
			{
				printf("请输入删除结点的位置：");
				scanf("%d",&i);
				value=DeleteNo_LinkList(head,i);
				if(!value)
					{
						printf("删除失败或则没有这个数据！\n");
					}
					else
						printf("删除成功！\n");
					break;
			}
			case 8:
				{
					Sort_LinkList(head);
					printf("排序结果为：\n");
					Print_LinkList(head);
					 
					break;
				}
			case 9:
				{
					SetNull_LinkList(head);
					break;
				}
			case 10:
				exit(0);
		}
		system("pause");
		system("cls");
	}
	return 0;
}
void menu()
{
	printf("0.创建单链表\n");
	printf("1.输出单链表\n");
	printf("2.单链表长度\n");
	printf("3.按序号查找单连表\n");
	printf("4.按值查找单链表\n");
	printf("5.在指定序号位置插入\n");
	printf("6.删除指定值的结点\n");
	printf("7.删除指定位置的结点\n"); 
	printf("8.链表排序\n");
	printf("9.置空表\n"); 
	printf("10.退出\n"); 
	printf("_____________________\n");
	printf("请选择："); 
}
LinkList * Create_LinkListF()//头插法创建链表
{
	elemtype ix;
	LinkList * head, *p,*tail;
	head=(LinkList *)malloc(sizeof(LinkList));
	if (head==NULL)
		return head;
	head->next=NULL;
	tail=head;
	printf("请输入数据直到输入0结束：\n");
	scanf("%d",&ix);
	while(ix!=0)
	{
		p=(LinkList *)malloc(sizeof(LinkList));
		if(p==NULL)
		{
			return head;
		}
		p->data=ix;
		tail->next=p;
		tail=p;
		tail->next=NULL;
		scanf("%d",&ix);
	}
	return head;
}
int Print_LinkList(LinkList * head)//链表输出
{
	LinkList *p=head;
	int t=1;
	if(p==NULL||p->next==NULL)
		return 0;
	p=p->next;
	while(p!=NULL)
	{
		printf("num%d: %d\n",t,p->data);
		p=p->next;
		t++;
	}
	return 1;
}
int LinkList_Length(LinkList *head)//单链表的长度
{
	LinkList *p=head;
	int j=0;
	while(p->next!=NULL)
	{
		p=p->next;
		j++;
	}
	return j;
}
int GetData_LinkList(LinkList*head,int i)//按序号查找单链表
{
	LinkList*p;
	int j=0;
	if(i<=0)
		return 0;
	p=head;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(i==j)
		return p->data;
	else
		return 0;
}
int Search_LinkList(LinkList*head,elemtype key)//按值查找单链表
{
	LinkList*p;
	int j=1;
	p=head->next;
	while(p!=NULL)
	{
		if(p->data!=key)
		{
			p=p->next;
			j++;
		}
		else
			break;
	}
	return j;
}
void InsertAfter_LinkList(LinkList *p,LinkList *s)//单链表后插
{
	s->next=p->next;
	p->next=s;
}
int InsertNo_LinkList(LinkList *head,LinkList *s,int i)//在指定序号位置插入 
{
	LinkList *p;
	if(i<=0)
		p=NULL;
	else
	{
		p=head;
		while(i!=1&&p!=NULL)
		{
			p=p->next;
			i--;
		}
	}
	if(p==NULL&&i!=1)
	{
		return 0;
	}
	else
	{
		InsertAfter_LinkList(p,s);
		return 1;
	}
}
int DeleteAfter_LinkList(LinkList*p)//删除后继结点 
{
	LinkList *r;
	if(!p)
		return 0;
	r=p->next;
	if(!r)
		return 0;
	p->next=r->next;
	free(r);
	return 1;
}
int DeleteValue_LinkList(LinkList *head,int value)//删除指定值的结点 
{
	LinkList *p=head;
	int temp;
	temp=Search_LinkList(p,value);
	if(temp)
	{
		DeleteNo_LinkList(head,temp);
		return 1;	
	}
	else
		return 0;	
} 
int DeleteNo_LinkList(LinkList*head,int i)//删除指定位置的结点
{
	LinkList*p,*r;
	if(i<=0)
		p=NULL;
	else
	{
		p=head;
		while(i!=1&&p!=NULL)
		{
			p=p->next;
			i--;
		}
	}
	if(p==NULL)
	{
		return 0;
	}
	else
	{
		r=p->next;
		if(r==NULL)
			return 0;
		p->next=r->next;
		free(r);
		return 1;
	}
}
void Sort_LinkList(LinkList *head)//链表排序 
{
	LinkList *tail,*end,*p;
	end=head->next;
	tail=end->next;
	while(tail)
	{
		
		end->next=tail->next;
		tail->next=NULL;
		if(tail->data<end->data)
		{
			p=head;
			while(p!=end->next)
			{
				if(tail->data<=p->next->data)
				{
					tail->next=p->next;
					p->next=tail;
					break;
				}
				p=p->next;
			}
		}
		else
		{
			tail->next=end->next;
			end->next=tail;
			end=tail;
		}
		tail=end->next;
	}
}

LinkList* SetNull_LinkList(LinkList*head)//置空表
{
	while(head->next)
		DeleteAfter_LinkList(head);
	return head;
}
