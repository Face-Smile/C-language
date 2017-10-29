# include<stdio.h>
# include<stdlib.h>
# define MAXSIZE 10
typedef int elemtype;
typedef struct SequenStack
{
	elemtype data[MAXSIZE];
	int top;
}SequenStack;
void menu();
SequenStack * Init_SequenStack();//˳��ջ��ʼ��
int SequenStack_Empty(SequenStack* S);//�ж�ջ��
int SequenStack_Full(SequenStack* S);//�ж�ջ�� 
int SequenStack_Length(SequenStack* S);//��˳��ջ�ĳ���
int Push_SequenStack(SequenStack *S,elemtype x);//��ջ 
int Pop_SequenStack(SequenStack *S,elemtype *x);//��ջ 
int GetTop_SequenStack(SequenStack *S,elemtype *x);//ȡջ������Ԫ�� 

int main()
{
	int d,x,temp,value;
	SequenStack *S;
	S=Init_SequenStack();
	if(S==NULL)
	{
		return 0;
	}
	while(1)
	{
		menu();
		scanf("%d",&d);
		switch(d)
		{
			case 1:
				if(SequenStack_Empty(S))
				{
					printf("ջ��\n");
				}
				else if(SequenStack_Full(S))
				{
					printf("ջ��\n");
				}
				else
				{
					printf("ջ�Ȳ��գ�Ҳ����\n");
				}
				break;
			case 2:printf("˳��ջ�ĳ���Ϊ %d\n",SequenStack_Length(S)); break;
			case 3:
				{
					printf("��������ջֵ��");
					scanf("%d",&x);
					temp=Push_SequenStack(S,x);
					if(temp)
					{
						printf("����ɹ�!\n");
					}
					else
					{
						printf("����ʧ��!\n");
					}
					break;
				}
			case 4:
				{
					temp=Pop_SequenStack(S,&value);
					if(temp)
					{
						printf("ɾ���ɹ�!\n");
					}
					else
					{
						printf("ջΪ�գ�ɾ��ʧ��!\n");
					}
					break;
				}
			case 5:
				{
					temp=GetTop_SequenStack(S,&value);
					if(temp)
					{
						printf("ջ��Ԫ��Ϊ��%d\n",value);
					}
					else
					{
						printf("ջΪ��!\n");
					}
					break;	
				}
			case 6:
				exit(0);
		}
		system("pause");
		system("cls");
	}
	return 0;
}

void menu()
{
	printf("1.�ж�ջΪ�ջ���\n");
	printf("2.˳��ջ�ĳ���\n");
	printf("3.��ջ\n");
	printf("4.��ջ\n");
	printf("5.ȡ��ջ��Ԫ��\n");
	printf("6.�˳�\n");
	printf("********************\n");
	printf("____________________\n");
	printf("��ѡ��");
}

SequenStack * Init_SequenStack()//˳��ջ��ʼ�� 
{
	SequenStack *S;
	S=(SequenStack *)malloc (sizeof(SequenStack));
	if(S==NULL)
	{
		return S;
	}
	S->top=-1;
	return S;
}
int SequenStack_Empty(SequenStack* S)//�ж�ջ�� 
{
	if(S->top==-1)
	{
		return 1;
	}
	else
		return 0;
}
int SequenStack_Full(SequenStack* S)//�ж�ջ�� 
{
	if (S->top+1==MAXSIZE)
		return 1;
	else
		return 0;
}
int SequenStack_Length(SequenStack* S)//��˳��ջ�ĳ���
{
	return S->top+1;
} 
int Push_SequenStack(SequenStack *S,elemtype x)//��ջ 
{
	if(S->top>=MAXSIZE-1)
		return 0;
	S->top++;
	S->data[S->top]=x;
	return 1;
}
int Pop_SequenStack(SequenStack *S,elemtype *x)//��ջ 
{
	if(S->top==-1)
		return 0;
	else
	{
		S->top--;
		*x=S->data[S->top+1];
		return 1;
	}
}
int GetTop_SequenStack(SequenStack *S,elemtype *x)//ȡջ������Ԫ�� 
{
	if(S->top==-1)
	{
		return 0;
	}
	else
	{
		*x=S->data[S->top];
		return 1;
	}
}
