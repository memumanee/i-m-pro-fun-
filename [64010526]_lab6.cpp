#include<stdio.h>
#include<windows.h>
#include<conio.h>

bool kasun[5];
int kasun_x[5],kasun_y[5];
void gotoxy(int x,int y){
	COORD c = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void setcolor(int fg,int bg)
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, bg*16+fg);
}

draw_ship(int x,int y){
	gotoxy(x,y);
	setcolor (2,4);
	printf("<-0->");
} 
draw_kasun(int x,int y){
	gotoxy(x,y);
	setcolor (1,4);
	printf("|");
} 
erase_ship(int x,int y){
	gotoxy(x,y);
	setcolor(0,0);
	printf("     ");
} 
void setcursor(bool visible)
{
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO lpCursor;
lpCursor.bVisible = visible;
lpCursor.dwSize = 20;
SetConsoleCursorInfo(console,&lpCursor);
}
erase_kasun(int x,int y){
	gotoxy(x,y);
	setcolor(0,0);
	printf(" ");
} 
void shoot (int n)
{
	erase_kasun(kasun_x[n],kasun_y[n]);
	if(kasun_y[n]>1)
	{
		draw_kasun(kasun_x[n],--kasun_y[n]);	
	}	
	else
	{
		kasun[n]=false;
	}
}
int main(){
	int v=0;
	setcursor(0);
	char ch=' ';
	int x=38,y=20;
	draw_ship(x,y);
		do{
			if(_kbhit()){
				ch=_getch();
				if(ch==' '&&x>=1)
					for(int i=0;i<5;i++){
						if(!kasun[i])
						{
							kasun[i]=true;
							kasun_x[i]=x+2;
							kasun_y[i]=y-1;
							break;	
						}
					}
				if(ch == 'a') v=-1;
				if(ch == 'd') v=1;
				if(ch == 's') v=0;
				fflush(stdin);	
			}
			erase_ship(x,y);
			if(x+v>0&&x+v<80) x+=v;
			draw_ship(x,y);
			for(int i=0;i<5;i++){
				if(kasun[i])
				{
					shoot(i);
				}
			}
			
			Sleep(100);	
		}
		while (ch !='x');
		return 0;
}
