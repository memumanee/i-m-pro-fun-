#include <stdio.h>
#include <windows.h>
#include <time.h>
#define screen_x 80
#define screen_y 25
#include <time.h>
#define scount 80

HANDLE wHnd;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD characterPos = { 0,0 };
COORD bufferSize = { screen_x,screen_y };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
COORD star[scount];
int posx,posy;
int life = 10;

HANDLE rHnd;
DWORD fdwMode;
int color=7;
//color
void setcolor(int fg,int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg*16+fg);
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console,&lpCursor);
}
//draw ship in Buffer
draw_ship(int x,int y){
	consoleBuffer[(x-2) + screen_x * y].Char.AsciiChar = '<';
	consoleBuffer[(x-2) + screen_x * y].Attributes = color;
	consoleBuffer[(x-1) + screen_x * y].Char.AsciiChar = '-';
	consoleBuffer[(x-1) + screen_x * y].Attributes = color;
	consoleBuffer[x + screen_x * y].Char.AsciiChar = '^';
	consoleBuffer[x + screen_x * y].Attributes = color;
	consoleBuffer[(x+1) + screen_x * y].Char.AsciiChar = '-';
	consoleBuffer[(x+1) + screen_x * y].Attributes = color;
	consoleBuffer[(x+2) + screen_x * y].Char.AsciiChar = '>';
	consoleBuffer[(x+2) + screen_x * y].Attributes = color;

}
int setConsole(int x, int y)
{

	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}
//clear buffer with' ' 
void clear_buffer()
{
	for (int y = 0; y < screen_y; ++y) {
	for (int x = 0; x < screen_x; ++x) {
		consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
		consoleBuffer[x + screen_x * y].Attributes = 7;
	}
}
}

void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
}
//random position {x,y} of star[]*
void init_star(){
	for(int i=0;i<scount;i++){
		star[i].X = 1+rand()%78;
		star[i].Y = 1+rand()%23;
	}

}
void star_fall()
{
	int i;
	for (i = 0; i < scount; i++)
		{
		if (star[i].Y >= screen_y-1) {
			star[i] = { (rand() % screen_x),1 };
		}
		else if(star[i].Y == posy && (star[i].X >= posx-2 &&star[i].X <= posx+2))
		{
			life -= 1;
			star[i] = { (rand() % screen_x),1 };
		}
		else
		{
			star[i] = { star[i].X,star[i].Y+1 };
		}
	}
}
//fill * to Buffer
void fill_star_to_buffer(){
	for(int i=0;i<80;i++){
	consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
	consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;

	}
}
int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
	ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}
int main()
{
	//draw_ship(5,0);
	//int clor=7;
	bool play = true;
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;
    setConsole(screen_x, screen_y);
    setMode();
    init_star();
    while (play)
    {
	 	clear_buffer();
	 	star_fall();
	 	fill_star_to_buffer();
	 	if(life <= 0)
	 	{
	 		play = false;
		}
	 	
	 	GetNumberOfConsoleInputEvents(rHnd, &numEvents);
	 	if (numEvents != 0)
        {
	 		INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
	 		ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
	 		for (DWORD i = 0; i < numEventsRead; ++i)
	 		{
	 			if (eventBuffer[i].EventType == KEY_EVENT&&eventBuffer[i].Event.KeyEvent.bKeyDown == true ) //keybordCheck
					{
		 			if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
		 				play = false;//ifESC
			 		if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c')
		 				color = 1+rand()%15;
					}
		 		else if (eventBuffer[i].EventType == MOUSE_EVENT)
		 		{
					posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;

		 			if (eventBuffer[i].Event.MouseEvent.dwButtonState&FROM_LEFT_1ST_BUTTON_PRESSED)
                        color = 1+rand()%15;
                }
            }
            delete[] eventBuffer;
        }
    if(posx>77)
        posx=77;
    else if(posx<3)
        posx=3;
    draw_ship(posx,posy);
    fill_buffer_to_console();
	Sleep(100);
 }
 return 0;
}
