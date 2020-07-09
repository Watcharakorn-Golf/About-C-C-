#include "regis.h"
char sid_1[12];
abcd c;

int registy()
{
	int k = 7;
	onestudent *student2;
	student2 = new onestudent[CountOfStudent()];
	system("cls");
	KeepRigistoFile(student2);
	int maxA = 11;
	gotoxy(40, 1);
	cout << "Registeration Student!!\n\n";
	cout << " Student ID:";
	cin  >> sid_1;
	FILE *fpFourLastID; // keep last 4 ID of student
	fpFourLastID = fopen("FourLastIDOfstudentInformation.txt", "r");
	//=============================================================
	edit_info *infnumber;
	infnumber = new edit_info[CountOfStudent()];
	//=============================================================
	for (int i = 0; i < CountOfStudent(); i++)
	{
		fscanf(fpFourLastID, "%d\n", &infnumber[i].order);
	}
	fclose(fpFourLastID);
	for (int i = 0; i < CountOfStudent(); i++)
	{
		if (infnumber[i].order == changeIDStudentCharToInt(sid_1[7] - '0', sid_1[8] - '0', sid_1[9] - '0', sid_1[10] - '0'))
		{
			c.select1 = i;
		}
	}
	//=============================================================
	student2[c.select1].statusrigis = student2[c.select1].regis_student[0].ordinal;
loop_table:if (c.select1< maxA)
{
		cout << " SubjectsCode:";
		cin >> student2[c.select1].regis_student[student2[c.select1].statusrigis].subjects_code;
		cout << " SubjectsName:";
		cin >> student2[c.select1].regis_student[student2[c.select1].statusrigis].subjects_name;
		cout << " Credit:";
		cin >> student2[c.select1].regis_student[student2[c.select1].statusrigis].credit;
		cout << " Section:";
		cin >> student2[c.select1].regis_student[student2[c.select1].statusrigis].section;

		student2[c.select1].regis_student[0].ordinal = student2[c.select1].statusrigis+1;
	
		for (int i = 1; i < 10; i++)
		{
			student2[c.select1].regis_student[i].ordinal = student2[c.select1].regis_student[0].ordinal;
		}
		//student2[c.select1].regis_student[student2[c.select1].statusrigis+1].ordinal= student2[c.select1].statusrigis+1;
		student2[c.select1].statusrigis++;
		system("cls");
		//=========================================================================
		student2[c.select1].FourIDStd = changeIDStudentCharToInt(sid_1[7] - '0', sid_1[8] - '0', sid_1[9] - '0', sid_1[10] - '0');
		WriteRigistoFile(changeIDStudentCharToInt(sid_1[7] - '0', sid_1[8] - '0', sid_1[9] - '0', sid_1[10] - '0'), student2[c.select1].statusrigis, student2);

		//=========================================================================
		system("cls");
		gotoxy(40, 1);
		cout << "Registeration Student!!\n";
		gotoxy(3, 3);
		cout << "Student ID : "<< sid_1 ;
		gotoxy(5, 5);
		cout << "Ordinal";
		gotoxy(20, 5);
		cout << "SubjectsCode";
		gotoxy(40, 5);
		cout << "SubjectsName";
		gotoxy(60, 5);
		cout << "Credit";
		gotoxy(73, 5);
		cout << "Section";
		k = 7;
		for (int j = 0; j < student2[c.select1].regis_student[0].ordinal&& j<10; j++)
		{
			gotoxy(5, k); cout << setw(7) <<  j + 1;
			gotoxy(20, k); cout << setw(12) << student2[c.select1].regis_student[j].subjects_code;
			gotoxy(40, k); cout << setw(12) << student2[c.select1].regis_student[j].subjects_name ;
			gotoxy(60, k); cout << setw(6) << student2[c.select1].regis_student[j].credit ;
			gotoxy(73, k); cout << setw(7) << student2[c.select1].regis_student[j].section<< endl;
			k+=2;
		}
		cout << "\n\n Successful !!! \n";
	}
	cout << " Would you want to do more? Yes(1) / No(0) to back to main menu  \n";
	cin >> student2[c.select1].regis_student[0].choice1;
	switch (student2[c.select1].regis_student[0].choice1)
	{
	case 1:
		system("cls");
		gotoxy(40, 1);
		cout << "Registeration Student!!\n";
		gotoxy(3, 3);
		cout << "Student ID : " << sid_1;
		gotoxy(5, 5);
		cout << "Ordinal";
		gotoxy(20, 5);
		cout << "SubjectsCode";
		gotoxy(40, 5);
		cout << "SubjectsName";
		gotoxy(60, 5);
		cout << "Credit";
		gotoxy(73, 5);
		cout << "Section";
		k = 7;
		for (int j = 0; j < student2[c.select1].regis_student[0].ordinal && j<10; j++)
		{
			gotoxy(5, k); cout << setw(7) << j + 1;
			gotoxy(20, k); cout << setw(12) << student2[c.select1].regis_student[j].subjects_code;
			gotoxy(40, k); cout << setw(12) << student2[c.select1].regis_student[j].subjects_name;
			gotoxy(60, k); cout << setw(6) << student2[c.select1].regis_student[j].credit;
			gotoxy(73, k); cout << setw(7) << student2[c.select1].regis_student[j].section << endl;
			k += 2;
		}
		goto loop_table;
		break;
	case 0:
		system("cls");
		menu();
		break;
	}
    //==================================
    delete[] infnumber;
	//==================================
	return 0;
}                    //     4ตัวท้าย            จำนวนวิชา status
void WriteRigistoFile(int fourlastIDstd,int numregis, onestudent *student2)
{

		//////////////////////////////////////// for write new regis/////////////////////////////////////////
	FILE *fpFourLastIDandRegis;
		fpFourLastIDandRegis = fopen("FourLastIDOfstudentRegisteration.txt", "w");
		for (int i = 0; i < CountOfStudent(); i++)
		{
			for (int j = 0; j < 10; j++)
			{                                //1   2   3   4   5   6       //รหัส 4 ตัวท้ายยย 1                ลำดับวิชา  2                                          รหัสวิชา     3                                       ชื่อวิชา  4                                        หน่วยกิต  5                     sec 6
				fprintf(fpFourLastIDandRegis, "%d\t%d\t%s\t%s\t%d\t%s\n", student2[i].FourIDStd, student2[i].regis_student[j].ordinal, student2[i].regis_student[j].subjects_code, student2[i].regis_student[j].subjects_name, student2[i].regis_student[j].credit, student2[i].regis_student[j].section);

			}
		}
		fclose(fpFourLastIDandRegis);

	
}
void KeepRigistoFile(onestudent *student2)
{


	FILE *fpFourLastIDandRegis; // keep last 4 ID of student
	fpFourLastIDandRegis = fopen("FourLastIDOfstudentRegisteration.txt", "r");
	for (int i = 0; i < CountOfStudent(); i++)
	{
		for (int j = 0; j < 10; j++)
		{                                //1   2   3   4   5   6       //รหัส 4 ตัวท้ายยย 1                ลำดับวิชา  2                                          รหัสวิชา     3                                       ชื่อวิชา  4                               หน่วยกิต  5                     sec 6
			fscanf(fpFourLastIDandRegis, "%d\t%d\t%s\t%s\t%d\t%s\n", &student2[i].FourIDStd, &student2[i].regis_student[j].ordinal, student2[i].regis_student[j].subjects_code, student2[i].regis_student[j].subjects_name, &student2[i].regis_student[j].credit, student2[i].regis_student[j].section);

		}
	}
	fclose(fpFourLastIDandRegis);
}
void WriteRigisToFileNew(int fourlastIDstd, int numregis)
{
	FILE *fpFourLastIDandRegis; // keep last 4 ID of student
	fpFourLastIDandRegis = fopen("FourLastIDOfstudentRegisteration.txt", "a+");
	for (int i = 0; i < 10; i++)
	{
		fprintf(fpFourLastIDandRegis, "%d\t%d\t0\t0\t0\t0\n", fourlastIDstd, numregis);
	}
	fclose(fpFourLastIDandRegis);
}