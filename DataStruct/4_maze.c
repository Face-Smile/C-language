# include<stdio.h>
# include<windows.h>
# include<stdlib.h>
# define SIZE 10
# define MAXSIZE 100
typedef struct sequenStack
{
	int data[MAXSIZE][3];
	int top;
}SequenStack;
int maze[SIZE][SIZE]={
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,0,0,1,1,0,0,1},
		{1,0,1,1,1,0,0,0,0,1},
		{1,0,0,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,0,1},
		{1,0,1,1,1,0,1,1,0,1},
		{1,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
};
typedef struct
{
	int x;
	int y;
}Direction;
Direction move[5]={{0,0},{0,1},{1,0},{0,-1},{-1,0}};
typedef struct
{
	int row;
	int col;
	int direction;
}Path;

int find(SequenStack *S,Path start,Path end);//²éÕÒ³ö¿Ú 
SequenStack * Init_SequenStack();//Ë³ÐòÕ»³õÊ¼»¯
int SequenStack_Empty(SequenStack* S);//ÅÐ¶ÏÕ»Âú 
int Push_SequenStack(SequenStack *S,Path x);//ÈëÕ» 
int Pop_SequenStack(SequenStack *S,Path *x);//³öÕ» 
int GetTop_SequenStack(SequenStack *S,Path *x);//È¡Õ»¶¥Êý¾ÝÔªËØ 
int alterTop_SequenStack(SequenStack *S,Path x);//ÐÞ¸ÄÕ»¶¥ÔªËØ 
SequenStack *sortStack(SequenStack *S);//ÄæÐò 
void graphy_maze(SequenStack*S);//´òÓ¡ÃÔ¹¬ 

int main()
{
	system("mode con cols=120 lines=30");
	Path start,end,t;
	start.col=1;
	start.row=1;
	start.direction=1;
	end.col=8;
	end.row=8;
	SequenStack *S;
	S=Init_SequenStack();
	Push_SequenStack(S,start);
	graphy_maze(S);
	//graphy_maze(S);
	if(find(S,start,end)==0)
		printf("\nÎ´ÕÒµ½¿ÉÐÐÂ·¾¶£¡\n");
	else
	{
		S=sortStack(S);
		printf("\n");
		while(S->top!=-1)
		{
			Pop_SequenStack(S,&t);
			printf("Path:%d %d\n",t.col,t.row);
		}
	}
	//graphy_maze();
	return 0; 
}
int find(SequenStack *S,Path start,Path end)
{
	Path temp,trypath;
	int x,y,i,j;
	maze[start.col][start.row]==-1;
	while(!SequenStack_Empty(S))
	{
		GetTop_SequenStack(S,&temp);
		x=temp.col;
		y=temp.row;
		//printf("top:%d %d %d\n",x,y,temp.direction);
		//system("pause");
		while(temp.direction<=4)
		{
			
			i=x+move[temp.direction].x;
			j=y+move[temp.direction].y;
			temp.direction++;
			alterTop_SequenStack(S,temp);
			GetTop_SequenStack(S,&trypath);
			//printf("toppresent:%d %d %d\n",x,y,trypath.direction);
			//system("pause");
			trypath.direction=1;
			trypath.col=i;
			trypath.row=j;
			if(i==end.col&&j==end.row)
			{
				Push_SequenStack(S,trypath);
				graphy_maze(S);
				return 1;
			}
			else if(maze[i][j]==1||maze[i][j]==-1)
				continue;	
			else if(maze[i][j]==0)
			{
				Push_SequenStack(S,trypath);
				graphy_maze(S);
				GetTop_SequenStack(S,&temp);
				maze[i][j]=-1;
				break;
			}
		}
		if(temp.direction>4)
		{
			Pop_SequenStack(S,&temp);
			graphy_maze(S);
		}	
	}
	return 0; 
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
int SequenStack_Empty(SequenStack* S)//ÅÐ¶ÏÕ»Âú 
{
	if (S->top==-1)
		return 1;
	else
		return 0;
}

int Push_SequenStack(SequenStack *S,Path x)//ÈëÕ» 
{
	if(S->top>=MAXSIZE-1)
		return 0;
	S->top++;
	S->data[S->top][0]=x.col;
	S->data[S->top][1]=x.row;
	S->data[S->top][2]=x.direction;
	//printf("Push:%d %d %d\n",x.col,x.row,x.direction);
	return 1;
}
int Pop_SequenStack(SequenStack *S,Path *x)//³öÕ» 
{
	if(S->top==-1)
		return 0;
	else
	{
		S->top--;
		x->col=S->data[S->top+1][0];
		x->row=S->data[S->top+1][1];
		x->direction=S->data[S->top+1][2];
		//printf("Pop:%d %d %d\n",x->col,x->row,x->direction);
		return 1;
	}
}
int GetTop_SequenStack(SequenStack *S,Path *x)//È¡Õ»¶¥Êý¾ÝÔªËØ 
{
	if(S->top==-1)
	{
		return 0;
	}
	else
	{
		x->col=S->data[S->top][0];
		x->row=S->data[S->top][1];
		x->direction=S->data[S->top][2];
		return 1;
	}

}
int alterTop_SequenStack(SequenStack *S,Path x)//ÐÞ¸ÄÕ»¶¥ÔªËØ 
{
	if(S->top==-1)
	{
		return 0;
	}
	S->data[S->top][0]=x.col;
	S->data[S->top][1]=x.row;
	S->data[S->top][2]=x.direction;
	return 1;
}
SequenStack *sortStack(SequenStack *S)//ÄæÐòÕ» 
{
	SequenStack *Q;
	Path t;
	Q=Init_SequenStack();
	while(S->top!=-1)
	{
		Pop_SequenStack(S,&t);
		Push_SequenStack(Q,t);
	}
	return Q;
}
/*void sortStack(SequenStack *S)//ÄæÐò 
{
	int i,j,temp;
	if(S->top%2==0)
		j=S->top/2-1;
	else
		j=S->top/2;
	for(i=0;i<=j;i++)
	{
		temp=S->data[i][0];
		S->data[i][0]=S->data[S->top-i][0];
		S->data[S->top-i][0]=temp;
		temp=S->data[i][1];
		S->data[i][1]=S->data[S->top-i][1];
		S->data[S->top-i][1]=temp;
		temp=S->data[i][2];
		S->data[i][2]=S->data[S->top-i][2];
		S->data[S->top-i][2]=temp;
	}
}
*/

void graphy_maze(SequenStack*S)
{
	int i,j;
	Path temp;
	COORD coord;
	HANDLE hOutput;
	hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X=80;
	coord.Y=15;
	SetConsoleCursorPosition(hOutput,coord);
	printf("ESC £ºÍË³ö.space£ºÔÝÍ£.");
	GetTop_SequenStack(S,&temp);
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			coord.X=4*j+30;
			coord.Y=2*i+5;
 			SetConsoleCursorPosition(hOutput,coord);
			if(i==temp.col&&j==temp.row)
			{
 				printf("¡ï¡ï");
 				coord.Y++;
 				SetConsoleCursorPosition(hOutput,coord);
 				printf("¡ï¡ï");
			}
			else if(maze[i][j]==1)
			{
				printf("¡ö¡ö");
				coord.Y++;
 				SetConsoleCursorPosition(hOutput,coord);
				printf("¡ö¡ö");
			}
			else
			{
				printf("    ");
				coord.Y++;
 				SetConsoleCursorPosition(hOutput,coord);
				printf("    ");
			}
		}
	}
 	Sleep(350);
 	if(GetAsyncKeyState(VK_SPACE))
 	while(1)
 	{
 		Sleep(300);
 		if(GetAsyncKeyState(VK_SPACE))
 		{
	 		break;
	 	}
 	}
 	else if(GetAsyncKeyState(VK_ESCAPE))
 		exit(0); 
}
