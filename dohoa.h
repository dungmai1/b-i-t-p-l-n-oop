#include<iostream>
#include<windows.h>
#include <fstream>
#include <string>
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;
void gotoxy(short x,short y) 
{ 
    HANDLE hConsoleOutput; 
    COORD Cursor_an_Pos = { x,y}; 
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos); 
}
void textcolor(WORD color) 
{ 
    HANDLE hConsoleOutput; 
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info; 
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info); 

    WORD wAttributes = screen_buffer_info.wAttributes; 
    color &= 0x000f; 
    wAttributes &= 0xfff0; 
    wAttributes |= color; 

    SetConsoleTextAttribute(hConsoleOutput, wAttributes); 
}
void SetBGColor(WORD color) 
{ 
    HANDLE hConsoleOutput; 
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); 

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info; 
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info); 

    WORD wAttributes = screen_buffer_info.wAttributes; 
    color &= 0x000f; 
    color <<= 4; 
    wAttributes &= 0xff0f; 
    wAttributes |= color; 

    SetConsoleTextAttribute(hConsoleOutput, wAttributes); 
}
void loading(){
	textcolor(15);
	gotoxy(38,10);
	cout << "LOADING...";
	for( int i = 0 ; i <= 50 ; i++ ){
		textcolor(10);
		gotoxy(15 + i,11);cout << char(219);
		textcolor(15);
		gotoxy(40,12);cout << i * 2 << "%";
		Sleep(10);
	}
}
void animation(char q[100]){
	for ( int i =0 ; q[i]!='\0'; i++){
		for (double k=0; k<12000000; k++);
		cout<<q[i];
	}
}
void thanhviennhom(){
 	gotoxy(22,0); textcolor(12); animation("CHUONG TRINH QUAN LY SINH VIEN NHOM 9");
 	cout<<"\n                                                          ";
	textcolor(15); animation("\nThanh vien nhom:    Mai Danh Dung       6151071038 ");
 	cout<<"\n                                                          ";
	textcolor(15); animation("\n                    Nguyen Nhat Truong  6151071110 ");
 	cout<<"\n                                                          ";
 	textcolor(15); animation("\n                    Tran Hoang Trieu    6151071107 ");
	textcolor(12);
	cout<<endl<<endl;
}
void BangMenu( int Ox , int Oy){
	for(int x = 0 ; x < 65 ; x++ ){
		for( int y = 0 ; y < 37 ; y++ ){
			textcolor(12);
			if( y < 1 || y > 35 ){
				gotoxy(Ox + x, Oy + y);cout << char(177);
			}
			if( x < 2 || x > 62 ){
				gotoxy(Ox + x, Oy + y);cout << char(177);
			}
		}
	}
}
void duong_thang(){
	for(int i = 0 ; i <= 125 ; i++){
	cout << char(196);
	}
	cout<<endl;
}
void duong_thang1(){
	for(int i = 0 ; i <= 134 ; i++){
	cout << char(196);
	}
	cout<<endl;
}
void duong_thangdkhocphan(){
	for(int i = 0 ; i <= 161 ; i++){
	cout << char(196);
	}
	cout<<endl;
}
void theend(){
	textcolor(12);
	fstream filein;
	filein.open("theend.txt",ios_base::in);
	while(!filein.eof()){
	string s;
	getline(filein,s,'\n');
	cout<<s<<endl;
	Sleep(150);
	}
	filein.close();	
}
void intro(){
	thanhviennhom();
	system("pause");
	loading();
	system("cls");
}
