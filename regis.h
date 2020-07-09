#ifndef REGIS_H
#define REGIS_H
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include"addinf.h"
#include <iomanip>
using namespace std;
//char std_id[12], char id[15], int grade, char dpmnt[30], char name[30], char surname[30], char faculty[30] ฝากไว้ ของฟังก์ชันแก้ไข
int registy();
void WriteRigisToFileNew(int , int );
//void setarray();

class abcd
{
public:
	int select1 = 0 ;
};

class registeration
{
	public:
		
		int  ordinal;  //order
		char subjects_code[8]; //รหัสวิชา
		char subjects_name[50]; //ชื่อวิชา
		int  credit; //หน่วยกิต
		char section[5];

		int choice1;
		; //รหัสนักศึกษา
};

class onestudent
{
public:
	int FourIDStd;
	int statusrigis = 0;
	registeration regis_student[10];
};
void WriteRigistoFile(int, int, onestudent*);
void KeepRigistoFile(onestudent *);
#endif // !REGIS_H

