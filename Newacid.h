#ifndef NEWACID_H
#define NEWACID_H
#define _CRT_SECURE_NO_WARNINGS
#include"addinf.h"
#include "color.h"
#include"regis.h"
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<iomanip>

using namespace std;
//==============================
//=      normal function       =
//==============================

void gotoxy(int x, int y);
void close();
void menu();
void contact();
void fordelay(int);
void main();
void list();
void window(int, int, int, int);
void curser(int);
void highlight(int,int);
void WriteToFile(int, char*, char*, char *, char*, char *, char *, int);
void WriteCountAndID(int,int); //write count and id into file (int countpeople, int fourlastID)
int CountOfStudent(); //check number of student from file . It will return count come back.
int changeIDStudentCharToInt(int,int,int,int); //(thousands,hundreds,tens,unit)
//=============================
class countstudent
{
public:
	int count_student;  //count of student
	int fourlastid;   // 4 last Id Ex 2431
};
//=============================
class security
{
		
public:
	void EnterPassword();
	void CheckPassword();
	int sid;
	char name[30];
	char surname[30];
	int edit_information();
	int registeation();
	int contact();
	void schedule();
	void list();
private:
	char pass[10], password[10] = "a";
	int main_exit;
};
//============================





#endif
