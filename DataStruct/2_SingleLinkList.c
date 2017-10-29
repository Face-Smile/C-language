# include<stdio.h>
# include<stdlib.h>

typedef int elemtype;
typedef struct node
{
	elemtype data;
	struct node* next;
}LinkList;


LinkList * Create_LinkListF();//��������
int Print_LinkList(LinkList * head);//�������
int LinkList_Length(LinkList *head);//������ĳ���
int GetData_LinkList(LinkList*head,int i);//����Ų��ҵ�����
int Search_LinkList(LinkList*head,elemtype key);//��ֵ���ҵ�����
void InsertAfter_LinkList(LinkList *p,LinkList *s);//��������
int InsertNo_LinkList(LinkList *head,LinkList *s,int i);//��ָ����Ų���
int DeleteAfter_LinkList(LinkList*p);//ɾ����̽��
int DeleteValue_LinkList(LinkList *head,int value);//ɾ��ָ��ֵλ�ý�� 
int DeleteNode_LinkList(LinkList*head,LinkList *p);//ɾ��ָ��λ�õĽ��
int DeleteNo_LinkList(LinkList*head,int i);//ɾ��ָ��λ�õĽ��
void Sort_LinkList(LinkList *head);//�ı����� 
LinkList* SetNull_LinkList(LinkList*head);//�ÿձ�
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
						printf("�����ɹ�!\n");
					break;
				}
			case 1:
				{
					if(Print_LinkList(head)==0)
						printf("����Ϊ�գ�\n");
					break;
				}
			case 2:
				{
					printf("������ĳ���Ϊ��%d\n",LinkList_Length(head));
					break;
				}
			case 3:
				{
					printf("�����������ţ�");
					scanf("%d",&i);
					value=GetData_LinkList(head,i);
					if(!value)
						printf("λ�÷Ƿ���\n");
					else
						printf("���ҵ�����Ϊ��%d\n",value);
					break;
				}
			case 4:
				{
					printf("������ҵ�ֵ��");
					scanf("%d",&key);
					value=Search_LinkList(head,key);
					if(value<1||value>LinkList_Length(head))
						printf("δ���ҵ�����ֵ��\n");
					else
						printf("���ҵ���ֵΪ��%d�����\n",value);
					break;
				}
			case 5:
				{
					printf("������������λ�ã�");
					scanf("%d",&i);
					printf("������������ֵ��");
					s=(LinkList *)malloc(sizeof(LinkList));
					scanf("%d",&s->data);
					s->next=NULL;
					value=InsertNo_LinkList(head,s,i);
					if(!value)
					{
						printf("����ʧ�ܻ���λ�÷Ƿ���\n");
					}
					else
						printf("����ɹ���\n"); 
					break;
				} 
			case 6:
				{
					printf("��������ɾ����ֵ��");
					scanf("%d",&i);
					value=DeleteValue_LinkList(head,i);
					if(!value)
					{
						printf("ɾ��ʧ�ܻ���λ�÷Ƿ���\n");
					}
					else
						printf("ɾ���ɹ���\n");
					break;
				}
			case 7:
			{
				printf("������ɾ������λ�ã�");
				scanf("%d",&i);
				value=DeleteNo_LinkList(head,i);
				if(!value)
					{
						printf("ɾ��ʧ�ܻ���û��������ݣ�\n");
					}
					else
						printf("ɾ���ɹ���\n");
					break;
			}
			case 8:
				{
					Sort_LinkList(head);
					printf("������Ϊ��\n");
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
	printf("0.����������\n");
	printf("1.���������\n");
	printf("2.��������\n");
	printf("3.����Ų��ҵ�����\n");
	printf("4.��ֵ���ҵ�����\n");
	printf("5.��ָ�����λ�ò���\n");
	printf("6.ɾ��ָ��ֵ�Ľ��\n");
	printf("7.ɾ��ָ��λ�õĽ��\n"); 
	printf("8.��������\n");
	printf("9.�ÿձ�\n"); 
	printf("10.�˳�\n"); 
	printf("_____________________\n");
	printf("��ѡ��"); 
}
LinkList * Create_LinkListF()//ͷ�巨��������
{
	elemtype ix;
	LinkList * head, *p,*tail;
	head=(LinkList *)malloc(sizeof(LinkList));
	if (head==NULL)
		return head;
	head->next=NULL;
	tail=head;
	printf("����������ֱ������0������\n");
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
int Print_LinkList(LinkList * head)//�������
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
int LinkList_Length(LinkList *head)//������ĳ���
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
int GetData_LinkList(LinkList*head,int i)//����Ų��ҵ�����
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
int Search_LinkList(LinkList*head,elemtype key)//��ֵ���ҵ�����
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
void InsertAfter_LinkList(LinkList *p,LinkList *s)//��������
{
	s->next=p->next;
	p->next=s;
}
int InsertNo_LinkList(LinkList *head,LinkList *s,int i)//��ָ�����λ�ò��� 
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
int DeleteAfter_LinkList(LinkList*p)//ɾ����̽�� 
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
int DeleteValue_LinkList(LinkList *head,int value)//ɾ��ָ��ֵ�Ľ�� 
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
int DeleteNo_LinkList(LinkList*head,int i)//ɾ��ָ��λ�õĽ��
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
void Sort_LinkList(LinkList *head)//�������� 
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

LinkList* SetNull_LinkList(LinkList*head)//�ÿձ�
{
	while(head->next)
		DeleteAfter_LinkList(head);
	return head;
}
