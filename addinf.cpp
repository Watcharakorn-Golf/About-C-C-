#include "addinf.h"
//==================================
add_info student1;
//int ordinal = 0;
count1 a;
//==================================
int add_infomation()
{
	system("cls");
	system("COLOR F1");
again:cout << "\t\t === Fill Student Information ===";
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 3);
	cout << "Student ID :\t";
	gotoxy(30, 3);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 5);
	cout << "Name :\t";
	gotoxy(30, 5);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 7);
	cout << "Surname :";
	gotoxy(30, 7);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 9);
	cout << "Identification Number :";
	gotoxy(30, 9);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 11);
	cout << "Faculty:";
	gotoxy(30, 11);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 13);
	cout << "Dapartment:";
	gotoxy(30, 13);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 15);
	cout << "Grade:";
	gotoxy(30, 15);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_CYAN);
	gotoxy(30, 3);
	cin >> student1.std_id;

	gotoxy(30, 5);
	cin >> student1.name;

	gotoxy(30, 7);
	cin >> student1.surname;

	gotoxy(30, 9);
	cin >> student1.id;

	gotoxy(30, 11);
	cin >> student1.faculty;

	gotoxy(30, 13);
	cin >> student1.dpmnt;

	gotoxy(30, 15);
	cin >> student1.grade;
	resetcolor();
	textcolor(COLOR_BLUE, COLOR_WHITE);
	cout << "\n\n Successful !!! \n";
	cout << " Would you want to do more? Yes(1) / No(0) to SAVE to main menu  \n";
	cin >> student1.yes_no;
	switch(student1.yes_no)
	{
	case 1:
	{
		WriteToFile(CountOfStudent(), student1.std_id, student1.name, student1.surname, student1.id, student1.faculty, student1.dpmnt, student1.grade);
		WriteCountAndID(CountOfStudent(), changeIDStudentCharToInt(student1.std_id[7] - '0', student1.std_id[8] - '0', student1.std_id[9] - '0', student1.std_id[10] - '0'));
		WriteRigisToFileNew(changeIDStudentCharToInt(student1.std_id[7] - '0', student1.std_id[8] - '0', student1.std_id[9] - '0', student1.std_id[10] - '0'), 0);
		system("cls");
		goto again;
	}
	break; 
	case 0:
	{
		WriteToFile(CountOfStudent(), student1.std_id, student1.name, student1.surname, student1.id, student1.faculty, student1.dpmnt, student1.grade);
		WriteCountAndID(CountOfStudent(), changeIDStudentCharToInt(student1.std_id[7] - '0', student1.std_id[8] - '0', student1.std_id[9] - '0', student1.std_id[10] - '0'));
		WriteRigisToFileNew(changeIDStudentCharToInt(student1.std_id[7] - '0', student1.std_id[8] - '0', student1.std_id[9] - '0', student1.std_id[10] - '0'), 0);
		menu();
	}
	break;
	}
	
	
	return 0;
}
//======================================================
//=                  edit information                  =
//======================================================
edit_info *infnumber;
void save() 
{
	FILE *fpStudent;
	fpStudent = fopen("information student.txt", "w");
	for (int i = 0; i < CountOfStudent(); i++)
	{
		fprintf(fpStudent, "%d.\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", infnumber[i].no, infnumber[i].std_id, infnumber[i].name, infnumber[i].surname, infnumber[i].id, infnumber[i].faculty, infnumber[i].dpmnt, infnumber[i].grade);
	}
	fclose(fpStudent);
	menu();
}
void builarraykeepinformation(int countarray)
{
	infnumber = new edit_info[countarray];
}
void deleteinfnumber()
{
	delete[] infnumber;
}
void keepvalue()
{
	FILE *fpStudent;
	fpStudent = fopen("information student.txt", "r");
	
	FILE *fpFourLastID; // keep last 4 ID of student
	fpFourLastID = fopen("FourLastIDOfstudentInformation.txt", "r");

	for (int i = 0; i < CountOfStudent(); i++)
	{
		fscanf(fpStudent, "%d.\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", &infnumber[i].no, infnumber[i].std_id, infnumber[i].name, infnumber[i].surname, infnumber[i].id, infnumber[i].faculty, infnumber[i].dpmnt, &infnumber[i].grade);
		fscanf(fpFourLastID, "%d\n", &infnumber[i].order);
	}
	fclose(fpStudent);
	fclose(fpFourLastID);
}
//======================================================
int edit_information()
{
	builarraykeepinformation(CountOfStudent());
	keepvalue();
	//==============================
	system("cls");
	system("COLOR F1");
again:cout << "\t\t === Fill Student Information ===";
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 3);
	cout << "Enter your ID you want to edit :\t";
	gotoxy(40, 3);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << "";
	//==============================
	//textcolor(COLOR_BLUE, COLOR_WHITE);
	//gotoxy(5, 5);
	//cout << "Name :\t";
	//gotoxy(30, 5);
	//textcolor(COLOR_BLUE, COLOR_CYAN);
	//cout << setw(20) << "";
	////==============================
	//textcolor(COLOR_BLUE, COLOR_WHITE);
	//gotoxy(5, 7);
	//cout << "Surname :";
	//gotoxy(30, 7);
	//textcolor(COLOR_BLUE, COLOR_CYAN);
	//cout << setw(20) << "";
	////==============================
	//textcolor(COLOR_BLUE, COLOR_WHITE);
	//gotoxy(5, 9);
	//cout << "Identification Number :";
	//gotoxy(30, 9);
	//textcolor(COLOR_BLUE, COLOR_CYAN);
	//cout << setw(20) << "";
	////==============================
	//textcolor(COLOR_BLUE, COLOR_WHITE);
	//gotoxy(5, 11);
	//cout << "Faculty:";
	//gotoxy(30, 11);
	//textcolor(COLOR_BLUE, COLOR_CYAN);
	//cout << setw(20) << "";
	////==============================
	//textcolor(COLOR_BLUE, COLOR_WHITE);
	//gotoxy(5, 13);
	//cout << "Dapartment:";
	//gotoxy(30, 13);
	//textcolor(COLOR_BLUE, COLOR_CYAN);
	//cout << setw(20) << "";
	////==============================
	//textcolor(COLOR_BLUE, COLOR_WHITE);
	//gotoxy(5, 15);
	//cout << "Grade 
	//gotoxy(30, 15);
	//textcolor(COLOR_BLUE, COLOR_CYAN);
	//cout << setw(20) << "";
	////==============================
	//textcolor(COLOR_BLACK, COLOR_GREEN);
	//gotoxy(40, 20);
	//cout << "SAVE";
	//textcolor(COLOR_BLUE, COLOR_CYAN);
	
	gotoxy(40, 3);
	cin >> student1.std_id;
	
	for (int i = 0; i < CountOfStudent(); i++)
	{
		if (infnumber[i].order == changeIDStudentCharToInt(student1.std_id[7] - '0', student1.std_id[8] - '0', student1.std_id[9] - '0', student1.std_id[10] - '0'))
		{
			a.select = i;
		}
	}
	
	
	////////////////////////////////////////////////////////////////////////////////////////////////
	curserEdit();

	return 0;
}
//=================================================================
int edit_information2()
{
	system("cls");
	system("COLOR F1");
	cout << "\t\t === Fill Student Information ===";
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 3);
	cout << "Enter your ID you want to edit :\t";
	gotoxy(40, 3);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << infnumber[a.select].std_id;
	//===============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 5);
	cout << "Name :\t";
	gotoxy(30, 5);
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	cout << setw(20) << left << infnumber[a.select].name;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 7);
	cout << "Surname :";
	gotoxy(30, 7);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].surname;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 9);
	cout << "Identification Number :";
	gotoxy(30, 9);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].id;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 11);
	cout << "Faculty:";
	gotoxy(30, 11);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].faculty;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 13);
	cout << "Dapartment:";
	gotoxy(30, 13);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].dpmnt;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 15);
	cout << "Grade:";
	gotoxy(30, 15);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].grade;
	//=================================================
	textcolor(COLOR_BLACK, COLOR_GREEN);
	gotoxy(40, 20);
	cout << "SAVE";
	gotoxy(60, 20);
	cout << "CANCEL";
	//===========================================

	////////////////////////////////////////////////////////////////////////////////////////////////
	curserEdit();


	return 0;
}
//==================================================================
	void curserEdit() // arrow up and down on key board
	{
		
		int no = 8;
		int count = 1;
		char ch = '0';
		//gotoxy(30, 23);
		while (1)
		{
			switch (ch)
			{
			case 80://arrow down
				count++;
				if (count == no + 1) count = 1;
				break;
			case 72://arrow up
				count--;
				if (count == 0) count = no;
				break;
			}
			highlightEdit(count);
			ch = _getch();
			if (ch == '\r')
			{
					if (count == 1) name();
					else if (count == 2) surname();
					else if (count == 3) id1();
					else if (count == 4) faculty();
					else if (count == 5) dpmnt();
					else if (count == 6) grade();
					else if (count == 7) save();
					else   menu();  //cancel                                     // goto other function and manu
			}
		}
	}
//========================================
void highlightEdit(int CountEdit)
{
	
	/*cout << "\t\t === Fill Student Information ===";
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 3);
	cout << "Enter your ID you want to edit :\t";
	gotoxy(40, 3);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << infnumber[a.select].std_id;*/
	//=====================================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 5);
	cout << "Name :\t";
	gotoxy(30, 5);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].name;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 7);
	cout << "Surname :";
	gotoxy(30, 7);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].surname;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 9);
	cout << "Identification Number :";
	gotoxy(30, 9);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].id;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 11);
	cout << "Faculty:";
	gotoxy(30, 11);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].faculty;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 13);
	cout << "Dapartment:";
	gotoxy(30, 13);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].dpmnt;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 15);
	cout << "Grade:";
	gotoxy(30, 15);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].grade;
	//==============================
	textcolor(COLOR_BLACK, COLOR_GREEN);
	gotoxy(40, 20);
	cout << "SAVE";
	gotoxy(60, 20);
	cout << "CANCEL";
	//==============================
	//textcolor(COLOR_BLUE, COLOR_CYAN);
	switch (CountEdit)
	{
	case 1:
	{
		textcolor(COLOR_BLUE, COLOR_WHITE);
		gotoxy(5, 5);
		cout << "Name :\t";
		gotoxy(30, 5);
		textcolor(COLOR_BLUE, COLOR_YELLOW);
		cout << setw(20) << left << infnumber[a.select].name;
	}
	break;
	//==============================
	case 2:
	{
		textcolor(COLOR_BLUE, COLOR_WHITE);
		gotoxy(5, 7);
		cout << "Surname :";
		gotoxy(30, 7);
		textcolor(COLOR_BLUE, COLOR_YELLOW);
		cout << setw(20) << left << infnumber[a.select].surname;
	}
	break;
	//==============================
	case 3:
	{
		textcolor(COLOR_BLUE, COLOR_WHITE);
		gotoxy(5, 9);
		cout << "Identification Number :";
		gotoxy(30, 9);
		textcolor(COLOR_BLUE, COLOR_YELLOW);
		cout << setw(20) << left << infnumber[a.select].id;
	}
	break;
	//==============================
	case 4:
	{
		textcolor(COLOR_BLUE, COLOR_WHITE);
		gotoxy(5, 11);
		cout << "Faculty:";
		gotoxy(30, 11);
		textcolor(COLOR_BLUE, COLOR_YELLOW);
		cout << setw(20) << left << infnumber[a.select].faculty;
	}
	break;
	//==============================
	case 5:
	{
		textcolor(COLOR_BLUE, COLOR_WHITE);
		gotoxy(5, 13);
		cout << "Dapartment:";
		gotoxy(30, 13);
		textcolor(COLOR_BLUE, COLOR_YELLOW);
		cout << setw(20) << left << infnumber[a.select].dpmnt;
	}
	break;
	//==============================
	case 6:
	{
		textcolor(COLOR_BLUE, COLOR_WHITE);
		gotoxy(5, 15);
		cout << "Grade:";
		gotoxy(30, 15);
		textcolor(COLOR_BLUE, COLOR_YELLOW);
		cout << setw(20) << left << infnumber[a.select].grade;
	}
	break;
	//==============================
	case 7:
		textcolor(COLOR_RED, COLOR_YELLOW);
		gotoxy(40, 20);
		cout << "SAVE";
		break;
	default:
		textcolor(COLOR_RED, COLOR_YELLOW);
		gotoxy(60, 20);
		cout << "CANCEL";
		break;
	//textcolor(COLOR_BLUE, COLOR_CYAN);
	}
}
//===================================================
void name()
{
	system("cls");
	system("COLOR F1");
	cout << "\t\t === Fill Student Information ===";
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 3);
	cout << "Enter your ID you want to edit :\t";
	gotoxy(40, 3);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << infnumber[a.select].std_id;
	//===============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 5);
	cout << "Name :\t";
	gotoxy(30, 5);
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 7);
	cout << "Surname :";
	gotoxy(30, 7);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].surname;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 9);
	cout << "Identification Number :";
	gotoxy(30, 9);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].id;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 11);
	cout << "Faculty:";
	gotoxy(30, 11);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].faculty;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 13);
	cout << "Dapartment:";
	gotoxy(30, 13);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].dpmnt;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 15);
	cout << "Grade:";
	gotoxy(30, 15);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].grade;
	//=================================================
	textcolor(COLOR_BLACK, COLOR_GREEN);
	gotoxy(40, 20);
	cout << "SAVE";
	gotoxy(60, 20);
	cout << "CANCEL";
	//===========================================
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	gotoxy(30, 5);
	cin >> infnumber[a.select].name;
	//============================================
	edit_information2();
}
void surname()
{
	system("cls");
	system("COLOR F1");
	cout << "\t\t === Fill Student Information ===";
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 3);
	cout << "Enter your ID you want to edit :\t";
	gotoxy(40, 3);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << infnumber[a.select].std_id;
	//===============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 5);
	cout << "Name :\t";
	gotoxy(30, 5);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].name;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 7);
	cout << "Surname :";
	gotoxy(30, 7);
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 9);
	cout << "Identification Number :";
	gotoxy(30, 9);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].id;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 11);
	cout << "Faculty:";
	gotoxy(30, 11);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].faculty;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 13);
	cout << "Dapartment:";
	gotoxy(30, 13);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].dpmnt;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 15);
	cout << "Grade:";
	gotoxy(30, 15);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].grade;
	//=================================================
	textcolor(COLOR_BLACK, COLOR_GREEN);
	gotoxy(40, 20);
	cout << "SAVE";
	gotoxy(60, 20);
	cout << "CANCEL";
	//===========================================
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	gotoxy(30, 7);
	cin >> infnumber[a.select].surname;
	//============================================
	edit_information2();
}
void id1()
{
	system("cls");
	system("COLOR F1");
	cout << "\t\t === Fill Student Information ===";
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 3);
	cout << "Enter your ID you want to edit :\t";
	gotoxy(40, 3);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << infnumber[a.select].std_id;
	//===============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 5);
	cout << "Name :\t";
	gotoxy(30, 5);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].name;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 7);
	cout << "Surname :";
	gotoxy(30, 7);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].surname;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 9);
	cout << "Identification Number :";
	gotoxy(30, 9);
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 11);
	cout << "Faculty:";
	gotoxy(30, 11);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].faculty;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 13);
	cout << "Dapartment:";
	gotoxy(30, 13);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].dpmnt;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 15);
	cout << "Grade:";
	gotoxy(30, 15);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].grade;
	//=================================================
	textcolor(COLOR_BLACK, COLOR_GREEN);
	gotoxy(40, 20);
	cout << "SAVE";
	gotoxy(60, 20);
	cout << "CANCEL";
	//===========================================
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	gotoxy(30, 9);
	cin >> infnumber[a.select].id;
	//============================================
	edit_information2();
}
void faculty()
{
	system("cls");
	system("COLOR F1");
	cout << "\t\t === Fill Student Information ===";
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 3);
	cout << "Enter your ID you want to edit :\t";
	gotoxy(40, 3);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << infnumber[a.select].std_id;
	//===============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 5);
	cout << "Name :\t";
	gotoxy(30, 5);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].name;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 7);
	cout << "Surname :";
	gotoxy(30, 7);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].surname;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 9);
	cout << "Identification Number :";
	gotoxy(30, 9);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].id;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 11);
	cout << "Faculty:";
	gotoxy(30, 11);
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 13);
	cout << "Dapartment:";
	gotoxy(30, 13);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].dpmnt;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 15);
	cout << "Grade:";
	gotoxy(30, 15);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].grade;
	//=================================================
	textcolor(COLOR_BLACK, COLOR_GREEN);
	gotoxy(40, 20);
	cout << "SAVE";
	gotoxy(60, 20);
	cout << "CANCEL";
	//===========================================
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	gotoxy(30, 11);
	cin >> infnumber[a.select].faculty;
	//============================================
	edit_information2();
}
void dpmnt()
{
	system("cls");
	system("COLOR F1");
	cout << "\t\t === Fill Student Information ===";
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 3);
	cout << "Enter your ID you want to edit :\t";
	gotoxy(40, 3);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << infnumber[a.select].std_id;
	//===============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 5);
	cout << "Name :\t";
	gotoxy(30, 5);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].name;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 7);
	cout << "Surname :";
	gotoxy(30, 7);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].surname;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 9);
	cout << "Identification Number :";
	gotoxy(30, 9);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].id;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 11);
	cout << "Faculty:";
	gotoxy(30, 11);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].faculty;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 13);
	cout << "Dapartment:";
	gotoxy(30, 13);
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	cout << setw(20) << "";
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 15);
	cout << "Grade:";
	gotoxy(30, 15);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].grade;
	//=================================================
	textcolor(COLOR_BLACK, COLOR_GREEN);
	gotoxy(40, 20);
	cout << "SAVE";
	gotoxy(60, 20);
	cout << "CANCEL";
	//===========================================
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	gotoxy(30, 13);
	cin >> infnumber[a.select].dpmnt;
	//============================================
	edit_information2();
}
void grade()
{
	system("cls");
	system("COLOR F1");
	cout << "\t\t === Fill Student Information ===";
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 3);
	cout << "Enter your ID you want to edit :\t";
	gotoxy(40, 3);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << infnumber[a.select].std_id;
	//===============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 5);
	cout << "Name :\t";
	gotoxy(30, 5);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].name;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 7);
	cout << "Surname :";
	gotoxy(30, 7);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].surname;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 9);
	cout << "Identification Number :";
	gotoxy(30, 9);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].id;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 11);
	cout << "Faculty:";
	gotoxy(30, 11);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].faculty;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 13);
	cout << "Dapartment:";
	gotoxy(30, 13);
	textcolor(COLOR_BLUE, COLOR_CYAN);
	cout << setw(20) << left << infnumber[a.select].dpmnt;
	//==============================
	textcolor(COLOR_BLUE, COLOR_WHITE);
	gotoxy(5, 15);
	cout << "Grade:";
	gotoxy(30, 15);
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	cout << setw(20) << "";
	//=================================================
	textcolor(COLOR_BLACK, COLOR_GREEN);
	gotoxy(40, 20);
	cout << "SAVE";
	gotoxy(60, 20);
	cout << "CANCEL";
	//===========================================
	textcolor(COLOR_BLUE, COLOR_YELLOW);
	gotoxy(30, 15);
	cin >> infnumber[a.select].grade;
	//============================================
	edit_information2();
}
//int checkorder(int ID)
//{
//	int j = 1;
//	for (int i = 0; i < CountOfStudent(); i++)
//	{
//		if()
//	}
//}