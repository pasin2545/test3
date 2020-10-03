#include<stdio.h>
#include<windows.h>
#include<conio.h>

int i = 0, bullet[5];
int x = 0, y = 20;
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void del(int x, int y) {
	gotoxy(x, y);
	printf("        ");
}
void draw_ship(int x, int y) {
	x = max(x, 0);
	y = max(y, 0);
	x = min(x, 80);
	y = min(y, 25);
	gotoxy(x, y);
	printf("<-0->");
}
//1
void bullet1(int, int);
void delbullet1(int, int);
void bulletsh1(int, int);
//2
void bullet2(int, int);
void delbullet2(int, int);
void bulletsh2(int, int);
//3
void bullet3(int, int);
void delbullet3(int, int);
void bulletsh3(int, int);
//4
void bullet4(int, int);
void delbullet4(int, int);
void bulletsh4(int, int);
//5
void bullet5(int, int);
void delbullet5(int, int);
void bulletsh5(int, int);

int main()
{
	setcursor(0);
	char ch = ' ';
	char ch2 = ' ';
	char space = ' ';
	draw_ship(x, y);
	do {
		//ยิงเริ่มต้น
		if (_kbhit()) {
			space = _getch();
			if (space == ' ') {
				bullet[i] = 1;
				if (i == 0) {
					bulletsh1(x, y);
				}
				else if (i == 1) {
					bulletsh2(x, y);
				}
				else if (i == 2) {
					bulletsh3(x, y);
				}
				else if (i == 3) {
					bulletsh4(x, y);
				}
				else if (i == 4) {
					bulletsh5(x, y);
				}
				i++;
				if (i > 4) {
					i = 0;
				}
			}
		}
		//ยาน
		if (_kbhit()) {
			ch = _getch();
			//เดินซ้าย
			if (ch == 'a') {
				while (ch == 'a') {
					del(x, y);
					draw_ship(--x, y);
					//หยุดขยับซ้าย
					if (_kbhit()) {
						ch2 = _getch();
						if (ch2 == 'd') {
							break;
						}
					}
					//ยิงขยับซ้าย
					if (_kbhit()) {
						space = _getch();
						if (space == ' ') {
							bullet[i] = 1;
							if (i == 0) {
								bulletsh1(x, y);
							}
							else if (i == 1) {
								bulletsh2(x, y);
							}
							else if (i == 2) {
								bulletsh3(x, y);
							}
							else if (i == 3) {
								bulletsh4(x, y);
							}
							else if (i == 4) {
								bulletsh5(x, y);
							}
							i++;
							if (i >= 4) {
								i = 0;
							}
						}
					}
					if (x < 0) {
						x = 0;
					}
					if (x == 0) {
						break;
					}
					Sleep(100);
				}
			}
			//เดินขวา
			if (ch == 'd') {
				while (ch == 'd') {
					del(x, y);
					draw_ship(++x, y);
					//หยุดขวา
					if (_kbhit()) {
						ch2 = _getch();
						if (ch2 == 'a') {
							break;
						}
					}
					//ยิงขยับขวา
					if (_kbhit()) {
						space = _getch();
						if (space == ' ') {
							bullet[i] = 1;
							if (i == 0) {
								bulletsh1(x, y);
							}
							else if (i == 1) {
								bulletsh2(x, y);
							}
							else if (i == 2) {
								bulletsh3(x, y);
							}
							else if (i == 3) {
								bulletsh4(x, y);
							}
							else if (i == 4) {
								bulletsh5(x, y);
							}
							i++;
							if (i >= 4) {
								i = 0;
							}
						}
					}
					if (x > 80) {
						x = 80;
					}
					if (x == 80) {
						break;
					}
					Sleep(100);
				}
			}
			fflush(stdin);
		}
	} while (ch != 'x');
	return 0;
}
//bullet1
void bullet1(int x, int y) {
	x = max(x, 0);
	y = max(y, 0);
	x = min(x, 80);
	y = min(y, 25);
	gotoxy(x, y);
	printf("|");
}
void delbullet1(int x, int y) {
	gotoxy(x, y);
	printf(" ");
}
void bulletsh1(int x, int y) {
	if (bullet[0] == 1) {
		int a = y;
		int j;//ตัวเเทนi
		bullet1(x, --a);
		while (bullet[0] == 1) {
			delbullet1(x, a);
			bullet1(x, --a);
			if (a == 0) {
				bullet[0] = 0;
				break;
			}
			Sleep(100);
		}
		delbullet1(x, a);
	}
}
//bullet2
void bullet2(int x, int y) {
	x = max(x, 0);
	y = max(y, 0);
	x = min(x, 80);
	y = min(y, 25);
	gotoxy(x, y);
	printf("|");
}
void delbullet2(int x, int y) {
	gotoxy(x, y);
	printf(" ");
}
void bulletsh2(int x, int y) {
	if (bullet[1] == 1) {
		int a = y;
		int j;//ตัวเเทนi
		bullet1(x, --a);
		while (bullet[1] == 1) {
			delbullet2(x, a);
			bullet2(x, --a);
			if (a == 0) {
				bullet[1] = 0;
				break;
			}
			Sleep(100);
		}
		delbullet1(x, a);
	}
}
//bullet3
void bullet3(int x, int y) {
	x = max(x, 0);
	y = max(y, 0);
	x = min(x, 80);
	y = min(y, 25);
	gotoxy(x, y);
	printf("|");
}
void delbullet3(int x, int y) {
	gotoxy(x, y);
	printf(" ");
}
void bulletsh3(int x, int y) {
	if (bullet[2] == 1) {
		int a = y;
		int j;//ตัวเเทนi
		bullet1(x, --a);
		while (bullet[2] == 1) {
			delbullet3(x, a);
			bullet3(x, --a);
			if (a == 0) {
				bullet[2] = 0;
				break;
			}
			Sleep(100);
		}
		delbullet1(x, a);
	}
}
//bullet4
void bullet4(int x, int y) {
	x = max(x, 0);
	y = max(y, 0);
	x = min(x, 80);
	y = min(y, 25);
	gotoxy(x, y);
	printf("|");
}
void delbullet4(int x, int y) {
	gotoxy(x, y);
	printf(" ");
}
void bulletsh4(int x, int y) {
	if (bullet[3] == 1) {
		int a = y;
		int j;//ตัวเเทนi
		bullet1(x, --a);
		while (bullet[3] == 1) {
			delbullet4(x, a);
			bullet4(x, --a);
			if (a == 0) {
				bullet[3] = 0;
				break;
			}
			Sleep(100);
		}
		delbullet1(x, a);
	}
}
//bullet5
void bullet5(int x, int y) {
	x = max(x, 0);
	y = max(y, 0);
	x = min(x, 80);
	y = min(y, 25);
	gotoxy(x, y);
	printf("|");
}
void delbullet5(int x, int y) {
	gotoxy(x, y);
	printf(" ");
}
void bulletsh5(int x, int y) {
	if (bullet[4] == 1) {
		int a = y;
		int j;//ตัวเเทนi
		bullet1(x, --a);
		while (bullet[4] == 1) {
			delbullet5(x, a);
			bullet5(x, --a);
			if (a == 0) {
				bullet[4] = 0;
				break;
			}
			Sleep(100);
		}
		delbullet1(x, a);
	}
}