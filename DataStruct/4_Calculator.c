# include<stdio.h>
# include<stdlib.h>
# include<string.h>

typedef int elemtype;
typedef struct LinkedStackNode
{
	elemtype data;
	struct LinkedStackNode * next;
}LinkedStackNode,* LinkedStack;
typedef struct OperandType
{
	int data;
	char operator;
	int type;
	struct OperandType *next;
}OperandType,* LinkedList;

LinkedStack Init_LinkedStack();//初始化栈 
LinkedList Transfer_ExpressList();//生成后缀表达式
char judge(char a,char b);//判断优先级 
int judge_string(char t);
int LinkedStack_Empty(LinkedStack top);//
int Push_LinkedStack(LinkedStack top,elemtype x);//入栈 
int Pop_LinkedStack(LinkedStack top,elemtype *x);//出栈 
int GetTop_LinkedStack(LinkedStack top,elemtype *x);//取栈顶元素 

void evaluatePostfixExpression(LinkedList expressLink, int * result);//计算后缀表达式 
void calculate(LinkedStack S, char operator);//四级运算 
int arithmeticalOperate(int operand1,int operand2,char operator);

int print_LinkedList(LinkedList head);//

int main()
{
	int result;
	LinkedList expressLink;
	expressLink=Transfer_ExpressList();
	print_LinkedList(expressLink);
	evaluatePostfixExpression(expressLink, &result);
	printf("计算结果为：%d\n",result);
	return 0;
}
int print_LinkedList(LinkedList head)
{
	LinkedList p=head->next;
	printf("\n");
	if(p->next==NULL)
		return 0;
	while(p)
	{
		if(p->type==0)
			printf("%d ",p->data);
		else
			printf("%c ",p->operator);
		p=p->next;
	}
	return 1;
} 
LinkedList Transfer_ExpressList()
{
	char c,d;
	int num,x,temp=0,top;
	LinkedList head,tail,node;
	LinkedStack P;
	P=Init_LinkedStack();
	head=(OperandType *)malloc(sizeof(OperandType));
	head->next=NULL;
	tail=head;
	if(head==NULL)
		return NULL;
	printf("请输入要计算的表达式：");
	c=getchar();
	while(c!=10)
	{
		printf("input:%c\n",c);
		if(c>=48&&c<=57)
		{
			num=(int)c-'0';
			if(temp==1)
			{
				tail->data=tail->data*10+num;
			}
			else
			{
				node=(OperandType *)malloc(sizeof(OperandType));
				node->data=num;
				node->type=0;
				node->next=tail->next;
				tail->next=node;
				tail=node;
				temp=1;
			}
			c=getchar();
		}
		else
		{
			temp=0;
			
			if(!LinkedStack_Empty(P))
			{
				GetTop_LinkedStack(P,&x);
				//printf("feikong\n");
				d=(char)x;
				printf("youxianji:%c\n",judge(d,c));
				switch(judge(d,c))
				{
					case '<': {
						x=(int)c;
						Push_LinkedStack(P,x);
						c=getchar();
						break;
					} 
					case '>':{
						Pop_LinkedStack(P,&x);
						node=(OperandType *)malloc(sizeof(OperandType));
						node->operator=(char)x;
						node->type=1;
						node->next=tail->next;
						tail->next=node;
						tail=node;
						break;
					}
					case '=':{
						Pop_LinkedStack(P,&x);
						c=getchar();
						break;
					} 
				}
			}
			else
			{
				x=(int)c;
				//printf("kong%d\n",x);
				Push_LinkedStack(P,x);
				c=getchar(); 
			}
		}
		//system("pause");	
	}
	while(!LinkedStack_Empty(P))
	{
		node=(OperandType *)malloc(sizeof(OperandType));
		Pop_LinkedStack(P,&x);
		node->operator=(char)x;
		node->type=1;
		node->next=tail->next;
		tail->next=node;
		tail=node;
	}
	return head;
}

char judge(char a,char b)//判断优先级
{
	char def[6][6]={{'>','>','<','<','<','>'},
					{'>','>','<','<','<','>'},
					{'>','>','>','>','<','>'},
					{'>','>','>','>','<','>'},
					{'<','<','<','<','<','='},
					{'>','>','>','>',' ','>'}};
	return def[judge_string(a)][judge_string(b)];
	
} 
int judge_string(char t)//
{
	switch(t)
	{
		case '+':return 0;
		case '-':return 1;
		case '*':return 2;
		case '/':return 3;
		case '(':return 4;
		case ')':return 5;
		default: return -1;
	}
}



LinkedStack Init_LinkedStack()
{
	LinkedStack top=(LinkedStackNode *)malloc (sizeof (LinkedStackNode));
	if(top!=NULL)
	{
		top->next=NULL;
	}
	return top;
}
int LinkedStack_Empty(LinkedStack top)
{
	if(top->next==NULL)
		return 1;
	else
		return 0;
}
int Push_LinkedStack(LinkedStack top,elemtype x)
{
	LinkedStackNode *node;
	node=(LinkedStackNode *)malloc (sizeof(LinkedStackNode));
	if(node==NULL)
	{
		return 0;
	}
	else
	{
		node->data=x;
		node->next=top->next;
		top->next=node;
		return 1;
	}
}
int Pop_LinkedStack(LinkedStack top,elemtype *x)
{
	LinkedStackNode * node;
	if(top->next==NULL)
		return 0;
	else
	{
		node=top->next;
		*x=node->data;
		top->next=node->next;
		free(node);
		return 1;
	}
}
int GetTop_LinkedStack(LinkedStack top, elemtype *x)
{
	if(top->next==NULL)
		return  0;
	else
	{
		*x=top->next->data;
		return 1;
	}
}

void evaluatePostfixExpression(LinkedList expressList, int * result)
{
	OperandType * operand;
	LinkedStack S;
	operand=expressList->next;
	S=Init_LinkedStack();
	while(operand!=NULL)
	{
		if(operand->type==0)
		{
			Push_LinkedStack(S,operand->data);
		}
		else
		{
			calculate(S,operand->operator);
		}
		operand=operand->next;
	}
	Pop_LinkedStack(S,result);
}
void calculate(LinkedStack S, char operator)
{
	int operand1,operand2;
	int result;
	Pop_LinkedStack(S,&operand2);
	Pop_LinkedStack(S,&operand1);
	result=arithmeticalOperate(operand1,operand2,operator);
	Push_LinkedStack(S,result);
	printf("oprand1:%d oprand:%d operator:%c result:%d",operand1,operand2,operator,result);
}
int arithmeticalOperate(int operand1,int operand2,char operator)
{
	int result;
	switch(operator)
	{
		case '+':result=operand1+operand2;break;
		case '-':result=operand1-operand2;break;
		case '*':result=operand1*operand2;break;
		case '/':result=operand1/operand2;break;
	}
	return result;
}

