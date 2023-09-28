#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct information
{
	char roll[25];
	char name[25];
	char father[25];
	char clas[10];
	char sect[5];
	char gender[10];
	char address[50];
	char contact[20];
	char email[30];
} info;

FILE *file;
int i;

int countstu();

void addstu();
void display();
void search();
void edit();
void deleterec();
void exitprog();
void df();

int main()
{
	system("cls");
	system("color F1");
	int count = 0;
	char line[1000];

	int choice, c;
	printf("\n\n\t\t\t\t\t\tWELCOME!");
	printf("\n\t\t\t\t\t\t-------");
	printf("\n\n\t\t\t\t\tPlease select accordingly\n");
	printf("\n\n\t\t1. Add Student(s)\n\n\t\t2. Display Students.\n\n\t\t3. Search Record\n\n\t\t4. Modify Record\n\n\t\t5. Delete Record\n\n\t\t6. Count Students\n\n\t\t7. Delete File\\Clear Records\n\n\t\t8. Exit");
	printf("\n\n\t\tChoice: ");
	scanf("%d", &choice);
	fflush(stdin);

	switch (choice)
	{
	case 1:
		addstu();
		break;

	case 2:
		display();
		break;

	case 3:
		search();
		break;

	case 4:
		edit();
		break;

	case 5:
		deleterec();
		break;

	case 6:
		printf("\n\n\t\t\tThere are %d Student(s) in the Record.", countstu());
		break;

	case 7:
		df();
		break;

	case 8:
		exitprog();
		break;

	default:
		printf("\n\n\t\tInvalid Choice! Press any key to continue");
		getch();
		main();
	}

	printf("\n\n\n\t\t\tPress any key to continue!");
	getch();
	system("cls");

	for (i = 0; i < 1; i++)
	{
		printf("\n\n\n\t\t1. Return to Main Menu\n\t\t2. Exit\n");
		printf("\n\t\tEnter Choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			main();
			break;

		case 2:
			exitprog();
			break;

		default:
			system("cls");
			printf("\n\t\tInvalid Choice! Please enter again");
			i--;
		}
	}
}

void addstu()
{
	system("cls");
	int n;
	info *stu;
	printf("\n\n\n\n\t\t\tEnter Number of Student's for Record: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		stu = (info *)malloc(sizeof(info));

		if (stu == NULL)
		{
			printf("\nMemory Is Not Created.\n");
			exit(0);
		}

		file = fopen("Student's Record.txt", "a+");
		if (file == NULL)
		{
			printf("File is not created.\n");
			exit(0);
		}
		system("cls");

		printf("\n\n\t\t\tStudent's Details of Student %d\n", i + 1);
		printf("\t\t\t_______________________________\n");

		printf("\n\tEnter Roll Number: ");
		fflush(stdin);
		gets(stu->roll);
		fprintf(file, "\tRoll Number: %s", stu->roll);

		printf("\n\tEnter Student Name: ");
		fflush(stdin);
		gets(stu->name);
		fprintf(file, "\n\tStudent Name: %s", stu->name);

		printf("\n\tEnter Father's Name: ");
		fflush(stdin);
		gets(stu->father);
		fprintf(file, "\n\tFather's Name: %s", stu->father);

		printf("\n\tClass: ");
		fflush(stdin);
		gets(stu->clas);
		fprintf(file, "\n\tClass: %s", stu->clas);

		printf("\n\tSection: ");
		fflush(stdin);
		gets(stu->sect);
		fprintf(file, "\n\tSection: %s", stu->sect);

		printf("\n\tGender: ");
		fflush(stdin);
		gets(stu->gender);
		fprintf(file, "\n\tGender: %s", stu->gender);

		printf("\n\tEnter Student's Address: ");
		fflush(stdin);
		gets(stu->address);
		fprintf(file, "\n\tStudent's Addrress: %s", stu->address);

		printf("\n\tEnter Student's Contact Number: ");
		fflush(stdin);
		gets(stu->contact);
		fprintf(file, "\n\tEnter Student's Contact Number: %s", stu->contact);

		printf("\n\tEnter Student's Email Address: ");
		fflush(stdin);
		gets(stu->email);
		fprintf(file, "\n\tEnter Student's Email Address: %s", stu->email);
		fprintf(file, "\n\n\t______________________________________________________________\n\n");

		fclose(file);
	}
}

void display()
{
	system("cls");
	printf("\n\t\t\t\t   RECORD\n");
	printf("\t\t\t\t   ------\n");
	printf("\n\t______________________________________________________________\n\n");
	char c;
	file = fopen("Student's Record.txt", "r");
	if (file == NULL)
	{
		printf("\t\t\t\tFile not found");
	}
	while (1)
	{
		c = fgetc(file);
		if (c == EOF)
		{
			break;
		}
		else
		{
			printf("%c", c);
		}
	}
	fclose(file);
}

void search()
{
	int choice;
	char roll[20];
	system("cls");
	printf("\n\n\n\n\t\t\tEnter the roll number to search: ");
	fflush(stdin);
	gets(roll);

	char cat[] = "Roll Number: ";
	strcat(cat, roll);

	file = fopen("Student's Record.txt", "r");
	if (file == NULL)
	{
		printf("Error Opening file.");
		exit(0);
	}

	char line[100];
	int flag, flag1 = 0;

	printf("\n");
	while (fgets(line, sizeof(line), file) != NULL)
	{

		if (strstr(line, cat) != NULL)
		{
			flag = 1;
		}
		if (flag == 1)
		{
			puts(line);
			flag1 = 1;
		}
		if (strstr(line, "Email") != NULL)
		{
			flag = 0;
		}
	}
	if (flag1 == 0)
	{
		printf("\n\t\tStudent with Roll number %s not found", roll);

		for (i = 0; i < 1; i++)
		{
			printf("\n\n\t\t1. Return to Main Menu\n\t\t2. Search Again");
			printf("\n\t\tChoice: ");
			scanf("%d", &choice);

			switch (choice)
			{
			case 1:
				main();
				break;

			case 2:
				search();
				break;
			default:
				system("cls");
				printf("\n\t\tInvalid Choice! Please enter again");
				i--;
			}
		}
	}
	fclose(file);
}

void edit()
{
	FILE *ft;
	info stu;
	int choice;
	char roll[20];
	system("cls");
	printf("\n\n\n\n\t\t\tEnter the roll number to Modify: ");
	fflush(stdin);
	gets(roll);
	char cat[] = "Roll Number: ";
	strcat(cat, roll);

	file = fopen("Student's Record.txt", "r");
	if (file == NULL)
	{
		printf("Error Opening file.");
		exit(0);
	}

	ft = fopen("temp.txt", "w");
	if (ft == NULL)
	{
		printf("Error Opening file.");
		exit(0);
	}

	char line[100];
	int flag = 0, flag1 = 0, flag2 = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (flag1 == 0)
		{
			if (strstr(line, cat) != NULL)
			{
				flag = 1;
				flag2 = 1;
			}
			if (flag == 0)
			{
				fprintf(ft, "%s", line);
			}
			if (flag == 1)
			{
				printf("\n\tEnter Roll Number: ");
				fflush(stdin);
				gets(stu.roll);
				fprintf(ft, "\tRoll Number: %s", stu.roll);

				printf("\n\tEnter Student Name: ");
				fflush(stdin);
				gets(stu.name);
				fprintf(ft, "\n\tStudent Name: %s", stu.name);

				printf("\n\tEnter Father's Name: ");
				fflush(stdin);
				gets(stu.father);
				fprintf(ft, "\n\tFather's Name: %s", stu.father);

				printf("\n\tClass: ");
				fflush(stdin);
				gets(stu.clas);
				fprintf(ft, "\n\tClass: %s", stu.clas);

				printf("\n\tSection: ");
				fflush(stdin);
				gets(stu.sect);
				fprintf(ft, "\n\tSection: %s", stu.sect);

				printf("\n\tGender: ");
				fflush(stdin);
				gets(stu.gender);
				fprintf(ft, "\n\tGender: %s", stu.gender);

				printf("\n\tEnter Student's Address: ");
				fflush(stdin);
				gets(stu.address);
				fprintf(ft, "\n\tStudent's Addrress: %s", stu.address);

				printf("\n\tEnter Student's Contact Number: ");
				fflush(stdin);
				gets(stu.contact);
				fprintf(ft, "\n\tEnter Student's Contact Number: %s", stu.contact);

				printf("\n\tEnter Student's Email Address: ");
				fflush(stdin);
				gets(stu.email);
				fprintf(ft, "\n\tEnter Student's Email Address: %s\n", stu.email);
				flag = 3;
			}
			if (flag == 3)
			{
				if (strstr(line, "Email") != NULL)
				{
					flag1 = 1;
				}
			}
		}
		else
		{
			fprintf(ft, "%s", line);
		}
	}
	if (flag2 == 0)
	{
		printf("\n\t\tStudent with Roll number %s not found", roll);
	}
	else
	{
		printf("\n\n\t\t\tRecord Modified Successfully");
	}
	fclose(file);
	fclose(ft);

	remove("Student's Record.txt");
	rename("temp.txt", "Student's Record.txt");
}

void deleterec()
{
	FILE *ft;
	int choice;
	char roll[20];
	system("cls");
	printf("\n\n\n\n\t\t\tEnter the roll number to delete: ");
	fflush(stdin);
	gets(roll);
	char cat[] = "Roll Number: ";
	strcat(cat, roll);

	file = fopen("Student's Record.txt", "r");
	if (file == NULL)
	{
		printf("Error Opening file.");
		exit(0);
	}

	ft = fopen("temp.txt", "w");
	if (ft == NULL)
	{
		printf("Error Opening file.");
		exit(0);
	}
	char line[100];
	int flag = 0, flag1 = 0, flag2 = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (flag1 == 0)
		{
			if (strstr(line, cat) != NULL)
			{
				flag = 1;
				flag2 = 1;
			}
			if (flag == 0)
			{
				fprintf(ft, "%s", line);
			}
			if (flag == 1)
			{
				if (strstr(line, "______________________________________________________________") != NULL)
				{
					flag1 = 1;
				}
			}
		}
		else
		{
			fprintf(ft, "%s", line);
		}
	}
	if (flag2 == 0)
	{
		printf("\n\t\tStudent with Roll number %s not found", roll);
	}
	else
	{
		printf("\n\n\t\t\tRecord Deleted Successfully");
	}
	fclose(file);
	fclose(ft);

	remove("Student's Record.txt");
	rename("temp.txt", "Student's Record.txt");
}

int countstu()
{
	system("cls");
	int count = 0;
	char line[100];

	file = fopen("Student's Record.txt", "r");
	if (file == NULL)
	{
		printf("Error Opening file.");
		exit(0);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (strstr(line, "Email") != NULL)
		{
			count++;
		}
	}

	fclose(file);
	return count;
}

void exitprog()
{
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tThank You for using our student management system!\n\n\n\n\n\t\t\t\t\t\tProgrammed by:\n\n\t\t\t\t\t\tSajeel Tariq (CTAI-029)\n\t\t\t\t\t\tFaraz Ahmed (CTAI-028)\n\t\t\t\t\t\tAbdullah Tariq (CTAI-040)\n\n\n\n\n\n");
	exit(0);
}

void df()
{
	system("cls");
	char c;
	printf("\n\n\t\t\tAre you sure you want to delete file? YES(y/Y)   NO(n/N): ");
	scanf("%c", &c);
	if (c == 'Y' || c == 'y')
	{
		remove("Student's Record.txt");
		printf("\n\n\t\t\t\tFILE DELETED SUCCESSFULLY");
	}
	else
	{
		main();
	}
}
