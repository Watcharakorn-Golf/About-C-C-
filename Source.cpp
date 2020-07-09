#include"Newacid.h"
countstudent writeIDfile;

//======================================
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
} 
//======================================
void close() //when you close program
{
	cout<<"\n\n\n\nPROGRAM NEWACIS KMUTT";
}
//======================================
void fordelay(int j)//delay time
{
	int i, k;
	for (i = 0; i<j; i++)
		k = i;
}
//======================================
void window(int a, int b, int c, int d)//windowe manu table
{
	int i;
	system("cls");
	gotoxy(18, 10);
	//textcolor(1);
	for (i = 1; i <= 10; i++)
		printf("-");
	printf("---Welcome to---");
	for (i = 1; i <= 10; i++)
		printf("-");
	printf("\n\n");
	gotoxy(30, 11);
	printf("NewAcid KMUTT");
	//textcolor(4);
	for (i = a; i <= b; i++)
	{
		gotoxy(i, 17);
		printf("\xcd");
		gotoxy(i, 19);
		printf("\xcd");
		gotoxy(i, c);
		printf("\xcd");
		gotoxy(i, d);
		printf("\xcd");
	}

	gotoxy(a, 17);
	printf("\xc9");
	gotoxy(a, 18);
	printf("\xba");
	gotoxy(a, 19);
	printf("\xc8");
	gotoxy(b, 17);
	printf("\xbb");
	gotoxy(b, 18);
	printf("\xba");
	gotoxy(b, 19);
	printf("\xbc");
	//textcolor(4);
	for (i = c; i <= d; i++)
	{
		gotoxy(a, i);
		printf("\xba");
		gotoxy(b, i);
		printf("\xba");
	}
	gotoxy(a, c);
	printf("\xc9");
	gotoxy(a, d);
	printf("\xc8");
	gotoxy(b, c);
	printf("\xbb");
	gotoxy(b, d);
	printf("\xbc");
	//textbackground(11);
	//textcolor(0);
}
//====================================
void curser(int no) // arrow up and down on key board
{
	int count = 1;
	char ch = '0';
	gotoxy(30, 23);
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
		highlight(no, count);
		ch = _getch();
		if (ch == '\r')
		{
			if (no == 6)
			{
				if (count == 1) add_infomation();
				else if (count == 2) edit_information();
				else if (count == 3) registy();
				else if (count == 4) contact();
				else if (count == 5) list();
				else   exit(0);                                      // goto other function and manu
			}
			
		}
	}
}
//=====================================
void highlight(int no, int count)//when you push arrow up and down
{

	if (no == 6)
	{
		//textbackground(11);
		//textcolor(0);
		gotoxy(30, 23);
		printf("   ADD INFORMATION");
		gotoxy(30, 24);
		printf("   EDIT INFORMATION");
		gotoxy(30, 25);
		printf("   REGISTERATION");
		gotoxy(30, 26);
		printf("   CONTACT");
		gotoxy(30, 27);
		printf("   SEE LIST");
		gotoxy(30, 28);
		printf("   EXIT ");
		
		
		//textcolor(0);
		//textbackground(2);
		switch (count)
		{
		case 1:
			gotoxy(30, 23);
			printf("-> ADD INFORMATION");
			break;
		case 2:
			gotoxy(30, 24);
			printf("-> EDIT INFORMATION");
			break;
		case 3:
			gotoxy(30, 25);
			printf("-> REGISTERATION");
			break;
		case 4:
			gotoxy(30, 26);
			printf("-> CONTACT");
			break;
		case 5:
			gotoxy(30, 27);
			printf("-> SEE LIST");
			break;
		case 6:
			gotoxy(30, 28);
			printf("-> EXIT");
			break;
		}
	}
}
//=====================================

void menu()
{
	deleteinfnumber();
	system("cls");
	system("COLOR 17"); ///////////////change color
	int i;
	char ch;
	const char *menu[] = { "   ADD INFORMATION","   EDIT INFORMATION","   REGISTERATION","   CONTACT ", "   SEE LIST","   EXIT" }; //head topic
	system("cls");
	window(25, 50, 20, 32); // buile table
	gotoxy(33, 18);
	printf("MAIN MENU");
	for (i = 0; i < 6; i++) //print topic manu
	{
		gotoxy(30, 22 + i + 1);
		printf("%s\n\n\n", menu[i]);
	}
	curser(6); //curser arrow up and down
}
//======================================
void WriteToFile(int no,char* std_id, char *name, char *surname,char* id, char *faculty, char *dpmnt, int grade) 
{
	no++;
	FILE *fpStudent;
	fpStudent = fopen("information student.txt", "a");
	fprintf(fpStudent, "%d.\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", no, std_id, name, surname, id, faculty, dpmnt, grade);
	fclose(fpStudent);
}
//======================================
int changeIDStudentCharToInt(int thousands, int hundreds, int tens, int unit) //(thousands,hundreds,tens,unit)
{
	int sum;
	thousands = thousands * 1000;
	hundreds = hundreds * 100;
	tens = tens * 10;
	sum = thousands + hundreds + tens + unit;
	return sum;
}
//======================================
int CountOfStudent()  //check old number of student from file 
{
	int countpeople = 0;
	FILE *fpCountStudent; // keep cout of student
	fpCountStudent = fopen("CountOfStudentInformation.txt", "a+");
	fscanf(fpCountStudent, "%d", &countpeople);
	fclose(fpCountStudent);
	return countpeople;
}
//======================================
void WriteCountAndID(int countpeople, int fourlastID) //write count and id into file
{
	FILE *fpCountStudent; // keep cout of student
	fpCountStudent = fopen("CountOfStudentInformation.txt", "w");
	countpeople++;
	fprintf(fpCountStudent, "%d", countpeople);
	fclose(fpCountStudent);

	FILE *fpFourLastID; // keep last 4 ID of student
	fpFourLastID = fopen("FourLastIDOfstudentInformation.txt", "a");
	fprintf(fpFourLastID, "%d\n", fourlastID);
	fclose(fpFourLastID);
}
//======================================
//======================================
//==       class security             ==
//======================================
//======================================
void security::EnterPassword()
{
	printf("\n\n\n\n\t\t\t\t===================================================");
	printf("\n\n\t\t\t\t KING MONGKUT'S UNIVERSITY OF TECHNOLOGY THONBURI");
	printf("\n\n\n\t\t\t\t===================================================");
	printf("\n\n\n\n\t\t\t\t\t    Enter the password to login:\n\n\t\t\t\t\t\t\t");
	scanf("%s", pass);

	
}
void security::CheckPassword()
{
	if (strcmp(pass, password) == 0) ///////////////////// password correct ////////////////////
	{
		printf("\n\n\t\t\t\t\t\t  Password Match!\n\n\n\t\t\t\t\t\t  LOADING");
		for (int i = 0; i <= 6; i++)
		{
			fordelay(100000000);
			printf(".");
		}
		system("cls");
		menu();///////////////////goto manu
	}
	else                            ///////////////////// password incorrect ////////////////////
	{
	
		printf("\n\n\t\t\t\t\t\t  Wrong password!!\a\a\a");
		printf("\n\n\t\t\t\t\t=======================================");
	login_try: ////////////////////////////////////try agin
		printf("\n\n\t\t\t\t\t  Enter 1 to try again and 0 to exit:\n\n\t\t\t\t\t\t\t");
		scanf("%d", &main_exit);
		if (main_exit == 1)
		{

			system("cls");
			main();
		}

		else if (main_exit == 0)
		{
			system("cls");
			close();
		}
		else
		{
			printf("\n\n\t\t\t\t\t\t  Invalid!");
			fordelay(1000000000);
			system("cls");
			goto login_try;  ///////////////////////////////////try again
		}

	}
}
//==============================================================
//=                 contact                                    =
//==============================================================
void contact()
{
	system("cls");
	FILE *infp;
	char inch;
	infp = fopen("contact.txt", "r");
		if (infp != NULL)
		{
			while (fscanf(infp, "%c", &inch) != EOF)
				printf("%c", inch);
			fclose(infp);

		}
		else
		{
			printf("Cannot open file. \n");
			fclose(infp);
		}
		gotoxy(40, 20);
		cout << "Press any key to";
		gotoxy(42, 21);
		cout <<"===>BACK<===\n\n\n\n ";
		resetcolor();
		system("pause");
	menu();
}
void list()
{
	system("cls");
	edit_info *SeeList;
	SeeList = new edit_info[CountOfStudent()];
	FILE *fpStudent;
	fpStudent = fopen("information student.txt", "r");

	FILE *fpFourLastID; // keep last 4 ID of student
	fpFourLastID = fopen("FourLastIDOfstudentInformation.txt", "r");

	for (int i = 0; i < CountOfStudent(); i++)
	{
		fscanf(fpStudent, "%d.\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", &SeeList[i].no, SeeList[i].std_id, SeeList[i].name, SeeList[i].surname, SeeList[i].id, SeeList[i].faculty, SeeList[i].dpmnt, &SeeList[i].grade);
		fscanf(fpFourLastID, "%d\n", &SeeList[i].order);
	}
	fclose(fpStudent);
	fclose(fpFourLastID);

	edit_info MIN;
	int m_i_n;
	for (int i = 0; i < CountOfStudent(); i++)
	{
		for (int j = 0; j <CountOfStudent() - 1; j++)
		{
			if (SeeList[j].order> SeeList[j+1].order)
			{
				MIN = SeeList[j+1];
				SeeList[j + 1] = SeeList[j];
				SeeList[j] = MIN;
			}
		}
	}
	for (int i = 0; i < CountOfStudent(); i++) //Edit order NO.
	{
		SeeList[i].no = i + 1;
	}
	printf(" NO.\tSTUDENT ID\tNAME\t\t\tSURNAME  \t    ID NUMBER\t        FACULTY\t   DEPARTMENT  GRADE\n\n");
	for (int i = 0; i < CountOfStudent(); i++)
	{
		printf("  %d.\t%11s\t%-17s\t%-17s   %13s\t%-15s\t%-5s\t%d\n", SeeList[i].no, SeeList[i].std_id, SeeList[i].name, SeeList[i].surname, SeeList[i].id, SeeList[i].faculty, SeeList[i].dpmnt, SeeList[i].grade);
	}

	cout << "\n\n                                                  Press any key to\n";
	cout << "                                                   ===>BACK<===\n\n\n\n ";
	
	
	
	fpStudent = fopen("information student.txt", "w");
	fpFourLastID = fopen("FourLastIDOfstudentInformation.txt", "w");

	for (int i = 0; i < CountOfStudent(); i++)
	{
		fprintf(fpStudent, "%d.\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", SeeList[i].no, SeeList[i].std_id, SeeList[i].name, SeeList[i].surname, SeeList[i].id, SeeList[i].faculty, SeeList[i].dpmnt, SeeList[i].grade);
		fprintf(fpFourLastID, "%d\n", SeeList[i].order);
	}
	fclose(fpStudent);
	fclose(fpFourLastID);

	system("pause");
	menu();
}
