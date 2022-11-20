#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FIR {
  char Name[20];
  char Father_s_Husband_s_Name[20];
  char Date_Of_Birth[20];
  char Address[50];
  char Aadhar_number[20];
  char Nationality[20];
  int IPC;
  char Date[10];
  char Day[10];
  char Time_Period[15];
  char Type_of_information[10];
  char Complainant_Informant[15];
  char Othes[200];


};

int main(){
  struct FIR lib;
  char ar_nm[30], bk_nm[30];
  int i, input, count;
  i = input = count = 0;
  FILE *fp;
  printf("\nWELCOME TO FIR DATABASE \n");
  printf("1. Register a FIR\n");
  printf("2. Display all FIR information\n");
  printf("3. List all FIR of given Aadhar_number\n");
  printf("4. List the count of FIR's in the FIR\n");
  printf("5. Exit\n");

 while (input != 5) {
  printf("\n\nEnter one of "
   "the above: ");
  scanf("%d", &input);
  switch (input) {
  case 1:
    fp=fopen("stu","ab");
    if(fp==NULL){
        printf("can't create file");
        break;
    }
    printf("Name = ");
    scanf("%s", lib.Name);
    printf("Enter Father's/Husband's Name = ");
    scanf("%s", &lib.Father_s_Husband_s_Name);
    printf("Enter Date Of Birth = ");
    scanf("%s", &lib.Date_Of_Birth);
    printf("Enter Address = ");
    scanf("%s", &lib.Address);
    printf("Enter Aadhar number = ");
    scanf("%s", lib.Aadhar_number);
    printf("Enter Nationality  = ");
    scanf("%s", lib.Nationality);
    printf("Enter IPC = ");
    scanf("%d", &lib.IPC);
    printf("Enter Date = ");
    scanf("%s", &lib.Date);
    printf("Enter Day = ");
    scanf("%s", &lib.Day);
    printf("Enter Time Period = ");
    scanf("%s", &lib.Time_Period);
    printf("Enter Type of information = ");
    scanf("%s", &lib.Time_Period);
    printf("Enter Complainant/Informant = ");
    scanf("%s", &lib.Complainant_Informant);
    printf("Enter Othes = ");
    scanf("%s", &lib.Othes);



    fwrite(&lib,sizeof(lib),1,fp);
    fclose(fp);

    break;
  case 2:
   printf("you have entered the following information\n");
   fp=fopen("stu","rb");
    if(fp==NULL){
      printf("can't read file");
    break;
    }
    while(fread(&lib,sizeof(lib),1,fp)==1){
    printf("Name = %s",lib.Name);
    printf("\t Father's/Husband's Name  = %s\n",lib.Father_s_Husband_s_Name);
    printf("\t Date_Of_Birth  = %s\n",lib.Date_Of_Birth);
    printf("Address = %s",lib.Address);
    printf("\t Aadhar_number = %s",lib.Aadhar_number);
    printf("\t Nationality = %s",lib.Nationality);
    printf("\t IPC = %d",lib.IPC);
    printf("\t Date = %s\n",lib.Date);
    printf("\t Day  = %s\n",lib.Day);
    printf("\t Time_Period   = %s\n",lib.Time_Period);
    printf("\t Complainant/Informant  = %s\n",lib.Complainant_Informant);
    printf("\t Othes  = %s\n",lib.Othes);


   }
   fclose(fp);
   break;
  case 5:
   exit(0);
  }
 }
 return 0;
}
