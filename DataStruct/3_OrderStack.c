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
SequenStack * Init_SequenStack();//Ë³ÐòÕ»³õÊ¼»¯
int SequenStack_Empty(SequenStack* S);//ÅÐ¶ÏÕ»¿Õ
int SequenStack_Full(SequenStack* S);//ÅÐ¶ÏÕ»Âú 
int SequenStack_Length(SequenStack* S);//ÇóË³ÐòÕ»µÄ³¤¶È
int Push_SequenStack(SequenStack *S,elemtype x);//ÈëÕ» 
int Pop_SequenStack(SequenStack *S,elemtype *x);//³öÕ» 
int GetTop_SequenStack(SequenStack *S,elemtype *x);//È¡Õ»¶¥Êý¾ÝÔªËØ 

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
					printf("Õ»¿Õ\n");
				}
				else if(SequenStack_Full(S))
				{
					printf("Õ»Âú\n");
				}
				else
				{
					printf("Õ»¼È²»¿Õ£¬Ò²²»Âú\n");
				}
				break;
			case 2:printf("Ë³ÐòÕ»µÄ³¤¶ÈÎª %d\n",SequenStack_Length(S)); break;
			case 3:
				{
					printf("ÇëÊäÈëÈëÕ»Öµ£º");
					scanf("%d",&x);
					temp=Push_SequenStack(S,x);
					if(temp)
					{
						printf("²åÈë³É¹¦!\n");
					}
					else
					{
						printf("²åÈëÊ§°Ü!\n");
					}
					break;
				}
			case 4:
				{
					temp=Pop_SequenStack(S,&value);
					if(temp)
					{
						printf("É¾³ý³É¹¦!\n");
					}
					else
					{
						printf("Õ»Îª¿Õ£¬É¾³ýÊ§°Ü!\n");
					}
					break;
				}
			case 5:
				{
					temp=GetTop_SequenStack(S,&value);
					if(temp)
					{
						printf("Õ»¶¥ÔªËØÎª£º%d\n",value);
					}
					else
					{
						printf("Õ»Îª¿Õ!\n");
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
	printf("1.ÅÐ¶ÏÕ»Îª¿Õ»òÂú\n");
	printf("2.Ë³ÐòÕ»µÄ³¤¶È\n");
	printf("3.ÈëÕ»\n");
	printf("4.³öÕ»\n");
	printf("5.È¡³öÕ»¶¥ÔªËØ\n");
	printf("6.ÍË³ö\n");
	printf("********************\n");
	printf("____________________\n");
	printf("ÇëÑ¡Ôñ£º");
}

SequenStack * Init_SequenStack()//Ë³ÐòÕ»³õÊ¼»¯ 
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
int SequenStack_Empty(SequenStack* S)//ÅÐ¶ÏÕ»¿Õ 
{
	if(S->top==-1)
	{
		return 1;
	}
	else
		return 0;
}
int SequenStack_Full(SequenStack* S)//ÅÐ¶ÏÕ»Âú 
{
	if (S->top+1==MAXSIZE)
		return 1;
	else
		return 0;
}
int SequenStack_Length(SequenStack* S)//ÇóË³ÐòÕ»µÄ³¤¶È
{
	return S->top+1;
} 
int Push_SequenStack(SequenStack *S,elemtype x)//ÈëÕ» 
{
	if(S->top>=MAXSIZE-1)
		return 0;
	S->top++;
	S->data[S->top]=x;
	return 1;
}
int Pop_SequenStack(SequenStack *S,elemtype *x)//³öÕ» 
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
int GetTop_SequenStack(SequenStack *S,elemtype *x)//È¡Õ»¶¥Êý¾ÝÔªËØ 
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
