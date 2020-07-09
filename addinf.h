#ifndef ADDINF_H
#define ADDINF_H
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string>
#include<conio.h>
#include"Newacid.h"
using namespace std;
//===================================
int add_infomation();
int edit_information();
int edit_information2();
void builarraykeepinformation(int); //will build array keep all information for rewrite file
void deleteinfnumber(); // delete array function before
void keepvalue(); //keep value in edit_info
int checkorder(int);
void highlightEdit(int);
void curserEdit();
void name();
void surname();
void id1();
void faculty();
void dpmnt();
void grade();
void save();

//===================================
class add_info
{
public:
	char std_id[12]; //Student ID
	char id[15]; //Indentification Number
	int grade;
	char dpmnt[30]; //department
	char name[30];
	char surname[30];
	char faculty[30]; //faculty
	int yes_no;
private:
	int again = 1;
	int btom = 0; //back to main

};

class edit_info
{
public:
	int order;
	int no;
	char std_id[12]; //Student ID
	char id[15]; //Indentification Number
	int grade;
	char dpmnt[30]; //department
	char name[30];
	char surname[30];
	char faculty[30]; //faculty
	int yes_no;
private:
	int again = 1;
	int btom = 0; //back to main

};


class count1
{
public:
	int select =0;
};

#endif // !ADDINF_H

