#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char ch[10][130] = {"Manglore Express", "Karwar Express", "Airavat Express", "SeaBird Express", "Newport Express", "VRL Express"};
char name[32][100] = {'\0'};
char number[32][2] = {'\0'};
int num1[32] = {0};
int trno;

void bus(); //for list of bus
void name_number(int booking, char numstr[100]);
void booking(); //for booking the tickets
int read_number(int trno); //for reading the number from the file
void read_name(int trno); //for reading the name from the file
void status(); //for printing the status by user input
void status_1(int trno); //for printing the status while booking ticket
void cancel();
void register_user(); // new function to register a user
void login(); // login function
void reset_password(); // function to reset password

int main()
{
    login();
    int num, i;
    do {
        system("cls");
        printf("\n\n\n");
        printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
        printf("\t\t\t\t\t[1]=> View Bus List\n");
        printf("\n");
        printf("\t\t\t\t\t[2]=> Book Tickets\n");
        printf("\n");
        printf("\t\t\t\t\t[3]=> Cancel Booking\n");
        printf("\n");
        printf("\t\t\t\t\t[4]=> Bus Status Board\n");
        printf("\n");
        printf("\t\t\t\t\t[5]=> Exit\n\n");
        printf("===============================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%d", &num);
        switch (num) {
        case 1:
            bus();
            break;
        case 2:
            booking();
            break;
        case 3:
            cancel();
            break;
        case 4:
            status();
            break;
        }
        getch();
    } while (num != 5);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    getch();
    return 0;
}

void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n", ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n", ch[1]);
    printf("\n");
    printf("\t\t\t\t\t[3]  =>  %s\n", ch[2]);
    printf("\n");
    printf("\t\t\t\t\t[4]  =>  %s\n", ch[3]);
    printf("\n");
    printf("\t\t\t\t\t[5]  =>  %s\n", ch[4]);
}

void booking()
{
    int i = 0;
    char numstr[100];
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    bus();
    printf("Enter the Bus number:--->");
    scanf("%d", &trno);
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("Your Bus Number is %d ********** %s", trno, ch[trno - 1]);
    status_1(trno);
    FILE *f1, *fopen();
    char str1[80] = "32", str2[4], str3[4];
    int seat1, seat2, booking = 0;
    if (trno == 1) {
        f1 = fopen("tr1.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    } else if (trno == 2) {
        f1 = fopen("tr2.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    } else if (trno == 3) {
        f1 = fopen("tr3.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    } else if (trno == 4) {
        f1 = fopen("tr4.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    } else if (trno == 5) {
        f1 = fopen("tr5.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    seat1 = atoi(str1);
    if (seat1 <= 0) {
        printf("There is no blank seat in this bus ");
    } else {
        printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n", seat1);
        printf("\n\t\t\t\tNumber of Tickets:----->");
        scanf("%d", &booking);
        printf("\n");

        seat1 = seat1 - booking;
        itoa(trno, numstr, 10);
        name_number(booking, numstr);
        printf("\n\t\t\t\tThe Total booking amount is %d", 200 * booking);
        itoa(seat1, str1, 10);
        if (trno == 1) {
            f1 = fopen("tr1.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        } else if (trno == 2) {
            f1 = fopen("tr2.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        } else if (trno == 3) {
            f1 = fopen("tr3.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        } else if (trno == 4) {
            f1 = fopen("tr4.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        } else if (trno == 5) {
            f1 = fopen("tr5.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
    }
    generate_ticket(trno, booking);
}

void name_number(int booking, char numstr[100])
{
    char tempstr[100], tempstr1[12] = "status", tempstr2[12] = "number";
    int number;
    FILE *a, *b;
    int i = 0;
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    a = fopen(tempstr1, "a"); //for open the file to write the name in the file
    b = fopen(tempstr2, "a"); //for open the file for writing the number in the file
    for (i = 0; i < booking; i++) //for entering the person name and seat number in the file
    {
        printf("============================Enter the details for ticket no %d============================\n\n\n", i + 1);
        printf("\t\t\t\tEnter the seat number:--->");
        scanf("%d", &number);
        printf("\t\t\t\tEnter the name of person:--->");
        scanf("%s", name[number - 1]);
        printf("\n======================================================================================================\n\n");
        printf("\n");
        itoa(number, tempstr, 10);
        fprintf(a, "%s ", name[number - 1]);
        fprintf(b, "%s ", tempstr);
    }
    fclose(a);
    fclose(b);
}

int read_number(int trno) //for putting the numeric value in the array
{
    char tempstr[100], tempstr2[12] = "number";
    FILE *a, *b;
    char numstr[100];
    int i = 0, j = 0, k;
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr2, numstr);
    a = fopen(tempstr2, "a+"); //for open the file to write the name in the file
    while (!feof(a)) {
        number[i][j] = fgetc(a);

        if (number[i][j] == ' ') {
            j = 0;
            i++;

        } else {
            j++;
        }
    }
    k = i;
    for (i = 0; i < k; i++) {
        num1[i] = atoi(number[i]);
    }
    fclose(a);
    return k;
}

void read_name(int trno) //for putting the numeric value in the array
{
    char tempstr1[12] = "status";
    FILE *b;
    char numstr[100];
    int i = 0, j = 0, k = 0;
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    b = fopen(tempstr1, "a+"); //for open the file to write the name in the file
    while (!feof(b)) {
        name[i][j] = fgetc(b);
        if (name[i][j] == ' ') {
            j = 0;
            i++;
        } else {
            j++;
        }
    }
    name[i][j] = '\0';
    k = i;
    fclose(b);
}

void status()
{
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i, trno, index = 0, j;
    printf("\t\tEnter the number of bus:---->");
    scanf("%d", &trno);
    j = read_number(trno);
    read_name(trno);
    printf("\n\t\t______________________________________________________________________________________________________\n");
    printf("\t\t\t\tBus.no-->%d---->%s                                                            \n", trno, ch[trno - 1]);
    printf("\t\t______________________________________________________________________________________________________\n");
    char tempname[33][30];
    for (i = 0; i < 33; i++)
    {
        strcpy(tempname[i], "Empty");
    }
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[num1[i]], name[i]);
    }
    printf("\n\t\t\t\t\tFront of the Bus\n\n");
    printf("\t\tWindow\t\tAisle\t\t\t\tAisle\t\tWindow\n");
    printf("\t\t------------------------------------------------------------------------\n");
    for (i = 0; i < 8; i++)
    {
        printf("\t\t%d. %s\t", i + 1, tempname[i + 1]);
        printf("%d. %s\t\t\t", i + 9, tempname[i + 9]);
        printf("%d. %s\t", i + 17, tempname[i + 17]);
        printf("%d. %s\n", i + 25, tempname[i + 25]);
    }
    printf("\n\n\t\t\t\t\tBack of the Bus\n");
}

void status_1(int trno)
{
    printf("Your Bus Number is %d ********** %s", trno, ch[trno - 1]);
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i, index = 0, j;
    j = read_number(trno);
    read_name(trno);
    char tempname[33][30];
    for (i = 0; i < 33; i++)
    {
        strcpy(tempname[i], "Empty");
    }
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[num1[i]], name[i]);
    }
    printf("\n\n\t\t\t\t\tFront of the Bus\n\n");
    printf("\t\tWindow\t\tAisle\t\t\t\tAisle\t\tWindow\n");
    printf("\t\t--------------------------------------------------------------------------\n");
    for (i = 0; i < 8; i++)
    {
        printf("\t\t%d. %s\t", i + 1, tempname[i + 1]);
        printf("%d. %s\t\t\t", i + 9, tempname[i + 9]);
        printf("%d. %s\t", i + 17, tempname[i + 17]);
        printf("%d. %s\n", i + 25, tempname[i + 25]);
    }
    printf("\n\n\t\t\t\t\tBack of the Bus\n");
}

void cancel()
{
    int seat_no, i, j;
    char numstr[100], tempstr2[15] = "number", tempstr1[15] = "status";
    printf("Enter the bus number:--->");
    scanf("%d", &trno);
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    read_number(trno);
    read_name(trno);
    printf("Enter the seat number:--->");
    scanf("%d", &seat_no);
    FILE *a, *b;
    a = fopen(tempstr1, "w+");
    b = fopen(tempstr2, "w+");
    for (i = 0; i < 32; i++) {
        if (num1[i] == seat_no) {
            for (j = i; j < 31; j++) {
                num1[j] = num1[j + 1];
                strcpy(name[j], name[j + 1]);
            }
            break;
        }
    }
    for (i = 0; i < 31; i++) {
        fprintf(a, "%s ", name[i]);
        fprintf(b, "%d ", num1[i]);
    }
    fclose(a);
    fclose(b);
    printf("\n\n");
    printf("======================================================================================================\n");
    printf("\t\t\t\tYour 200 rupees has been Returned\t\t\t\n");
    printf("======================================================================================================\n");
}

void register_user()
{
    char username[50], password[50];
    FILE *fp;
    fp = fopen("users.txt", "a+");
    if (fp == NULL) {
        printf("Error opening file");
        exit(1);
    }
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);
    printf("Registration successful!\n");
}

void login()
{
    char username[50], password[50], uname[50], pass[50];
    int login_success = 0;
    FILE *fp;
    int choice;
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]=> Register\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> Login\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> Reset Password\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> Exit\n\n");
    printf("===============================================================================================================\n\n");
    printf("\t\t\tEnter Your Choice:: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            register_user();
            login();
            break;
        case 2:
            fp = fopen("users.txt", "r");
            if (fp == NULL) {
                printf("Error opening file");
                exit(1);
            }
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            while (fscanf(fp, "%s %s", uname, pass) != EOF) {
                if (strcmp(username, uname) == 0 && strcmp(password, pass) == 0) {
                    login_success = 1;
                    break;
                }
            }
            fclose(fp);
            if (login_success) {
                printf("Login successful!\n");
            } else {
                printf("Invalid username or password.\n");
                exit(1);
            }
            break;
        case 3:
            reset_password();
            login();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
            login();
    }
}

void reset_password()
{
    char username[50], new_password[50], uname[50], pass[50];
    int found = 0;
    FILE *fp, *temp;
    fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");
        exit(1);
    }
    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error opening file");
        exit(1);
    }
    printf("Enter username: ");
    scanf("%s", username);
    while (fscanf(fp, "%s %s", uname, pass) != EOF) {
        if (strcmp(username, uname) == 0) {
            found = 1;
            printf("Enter new password: ");
            scanf("%s", new_password);
            fprintf(temp, "%s %s\n", uname, new_password);
        } else {
            fprintf(temp, "%s %s\n", uname, pass);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt", "users.txt");
    if (found) {
        printf("Password reset successful!\n");
    } else {
        printf("Username not found.\n");
    }
}

void read_number_from_file(int trno, int num1[], int *size) {
    char numstr[100], tempstr2[12] = "number";
    FILE *a;
    int i = 0, j = 0;
    *size = 0;
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr2, numstr);
    a = fopen(tempstr2, "r");
    if (a == NULL) {
        printf("Error opening file for reading seat numbers.\n");
        exit(1);
    }
    while (fscanf(a, "%d", &num1[i]) != EOF) {
        i++;
    }
    *size = i;
    fclose(a);
}

void read_name_from_file(int trno, char name[][100], int size) {
    char numstr[100], tempstr1[12] = "status";
    FILE *b;
    int i = 0, j = 0;
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    b = fopen(tempstr1, "r");
    if (b == NULL) {
        printf("Error opening file for reading passenger names.\n");
        exit(1);
    }
    while (fscanf(b, "%s", name[i]) != EOF && i < size) {
        i++;
    }
    fclose(b);
}
#include <time.h>

void generate_ticket(int trno, int booking) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int num1[32];
    char name[32][100];
    int size;

    read_number_from_file(trno, num1, &size);
    read_name_from_file(trno, name, size);

    printf("\n\n");
    printf("************************************ TICKET ************************************\n");
    printf("* Bus Number: %-65d*\n", trno);
    printf("* Bus Name: %-67s*\n", ch[trno - 1]);
    printf("* Ticket booked on: %02d-%02d-%d  %02d:%02d:%02d                                       *\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("* Number of Tickets: %d                                                         *\n", booking);
    printf("* Passenger Details:                                                           *\n");
    for (int i = 0; i < booking; i++) {
        int seat_number = num1[i]; // Retrieve seat number from num1 array
        char* passenger_name = name[i]; // Retrieve passenger name from name array
        printf("* Seat Number: %d, Passenger Name: %s                                       *\n", seat_number, passenger_name);
    }
    printf("********************************************************************************\n");
}
