#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char MAP[10][11] = {{'#','.','.','.','.','.','.','.','.','.','\n'},
					{'.','.','.','.','.','.','.','.','.','.','\n'},
					{'.','.','.','.','.','.','.','.','.','.','\n'},
					{'.','.','.','.','.','.','.','.','.','.','\n'},
					{'.','.','.','.','.','.','.','.','.','.','\n'},
					{'.','.','.','.','.','.','.','.','.','.','\n'},
					{'.','.','.','.','.','.','.','.','.','.','\n'},
					{'.','.','.','.','.','.','.','.','.','.','\n'},
					{'.','.','.','.','.','.','.','.','.','.','\n'},
					{'.','.','.','.','.','.','.','.','.','G','\n'}};

int locx = 0, locy = 0;

int monst1x = 0, monst1y = 0, monst2x = 0, monst2y = 0, goalx = 9, goaly = 9;;


void gotoxy(int x,int y){

	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void map(int x, int y){
	
	int tempx = locx, tempy = locy;


	if((x+locx)<0 || (x+locx)>9 || (y+locy)<0 || (y+locy)>9){
	 
		locx = locx;  
		locy = locy;
	} 	
	else{
		
		locx = locx + x;  
		locy = locy + y;
	}
	
	gotoxy(tempx,tempy);
	printf(".");
	gotoxy(locx,locy);
	printf("#");
	
	
	if(locx==monst1x && locy==monst1y){
		
		system("cls");
		puts("게임끝 실패");
		
		return ;
	}
	
	if(locx==monst2x && locy==monst2y){
		
		system("cls");
		puts("게임끝 실패");
		
		return ;
	}
	
	if(locx==goalx && locy==goaly){
		
		system("cls");
		puts("게임끝 성공");
		
		return ;
	}		
}

void locmon(){
	
	srand((unsigned)time(NULL));
	
	monst1x = rand()%8 + 1;
	monst1y = rand()%8 + 1;
	MAP[monst1y][monst1x] = 'M';
	
	monstnew:
		
	monst2x = rand()%8 + 1;
	monst2y = rand()%8 + 1;
	
	if(monst2x == monst1x && monst2y ==monst1y){
	
		goto monstnew;
	}
	else{
		
		MAP[monst2y][monst2x] = 'M';
	}
}


void cu(){
	
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


int main(){
	
	cu();
	locmon();
	
	printf("%s", MAP);
	puts("\n\n왼쪽 이동 : a, 오른쪽 이동 : d, 위쪽 이동 : w, 아래쪽 이동 : s");


	
	while(1){
		
		char curr;
		int x = 0, y = 0;
		
		curr = getch();
		
		if(curr == 'w'){
			
			x = 0;
			y = -1;
		}
		else if(curr == 'a'){
			
			x = -1;
			y = 0;
		}
		else if(curr == 'd'){
			
			x = 1;
			y = 0;
		}
		else if(curr == 's'){
			
			x = 0;
			y = 1;
		}

		map(x,y);
	}
}
