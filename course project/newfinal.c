#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FIR {
  char Name[20];
  char Father_s_Husband_s_Name[20];
  char Date_Of_Birth[20];
  char Address[50];
  int Aadhar_number;
  char Nationality[20];
  int IPC;
  char Date[10];
  char Day[10];
  char Time_Period[15];
  char Type_of_information[10];
  char Complainant_Informant[15];
  char Othes[200];


};
void assign(struct FIR * f ,int first,int last){
  Type_of_information
}
void printstr(struct FIR lib){
  printf("Name = %s\n",lib.Name);
  printf("Father's/Husband's Name  = %s\n",lib.Father_s_Husband_s_Name);
  printf("Date_Of_Birth  = %s\n",lib.Date_Of_Birth);
  printf("Address = %s\n",lib.Address);
  printf("Aadhar_number = %d\n",lib.Aadhar_number);
  printf("Nationality = %s\n",lib.Nationality);
  printf("IPC = %d\n",lib.IPC);
  printf("Date = %s\n",lib.Date);
  printf("Day  = %s\n",lib.Day);
  printf("Time_Period   = %s\n",lib.Time_Period);
  printf("Complainant/Informant  = %s\n",lib.Complainant_Informant);
  printf("Othes  = %s\n\n",lib.Othes);
}
struct FIR addfir(){
  struct FIR lib;
  printf("Name = ");
  scanf("%s", lib.Name);
  printf("Enter Father's/Husband's Name = ");
  scanf("%s", &lib.Father_s_Husband_s_Name);
  printf("Enter Date Of Birth = ");
  scanf("%s", &lib.Date_Of_Birth);
  printf("Enter Address = ");
  scanf("%s", &lib.Address);
  printf("Enter Aadhar number = ");
  scanf("%d", &lib.Aadhar_number);
  printf("Enter Nationality  = ");
  scanf("%s", &lib.Nationality);
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
  return lib;
}
void bsort(){
  FILE *fp;
  int i, j, s = 0;
  struct FIR lib;
  fp=fopen("stu","rb");
  while(fread(&lib,sizeof(lib),1,fp)==1){
    s+=1;
  }
  // printf("%d",s);
  fclose(fp);
  struct FIR array[s];
  i=0;
  fp=fopen("stu","rb");
  while(fread(&lib,sizeof(lib),1,fp)==1){
    array[i]=lib;
    i++;
  }
  fclose(fp);
  for (i = 0; i < s - 1; i++){
      for (j = 0; j < (s - 1-i); j++){
          if (array[j].Aadhar_number > array[j + 1].Aadhar_number){
              // printf("%d  %d",j,i);
              lib = array[j];
              array[j] = array[j + 1];
              array[j + 1] = lib;
          }
      }
  }
  fp = fopen("stu","wb");
  for( i = 0; i < s; i++){
    lib = array[i];
    fwrite(&lib,sizeof(lib),1,fp);
  }
  fclose(fp);
}
int main(){
  struct FIR lib;
  char ar_nm[30], bk_nm[30];
  int i, input, count;
  i = input = count = 0;
  FILE *fp;
  printf("\nWELCOME TO FIR DATABASE \n");
  printf("1. Register a FIR\n");
  printf("2. Display all FIR information\n");
  printf("3. List all FIR of given details\n");
  printf("4. List the count of FIR's in the FIR\n");
  printf("5. Sort all FIR's on the bases of aadhar number \n");
  printf("6. Exit\n");

 while(input != 6) {
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
      lib = addfir();
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
          printstr(lib);
      }
      fclose(fp);
      break;
    case 3:
      int num;
      char data[20];
      printf("what detail do you want to search for \n 1:Name \n 2: Aadhar number \n 3: Date \n");
      scanf("%d",&num);
      switch(num){
        case 1:
          printf("enter the name ");
          scanf("%s",&data);
          fp=fopen("stu","rb");
          if(fp==NULL){
            printf("can't read file");
            break;
          }
          while(fread(&lib,sizeof(lib),1,fp)==1){
            if (strcmp(data,lib.Name)==0){
              printstr(lib);
            }
          }
          fclose(fp);
          break;
        case 2:
          int t;
          printf("enter the Aadhar number");
          scanf("%d",&t);
          fp=fopen("stu","rb");
          if(fp==NULL){
            printf("can't read file");
            break;
          }
          while(fread(&lib,sizeof(lib),1,fp)==1){
            if (data==lib.Aadhar_number){
              printstr(lib);
            }
          }
          fclose(fp);
          break;
        case 3:
          printf("enter the date \n");
          scanf("%s",&data);
          fp=fopen("stu","rb");
          if(fp==NULL){
            printf("can't read file");
            break;
          }
          while(fread(&lib,sizeof(lib),1,fp)==1){
            if (strcmp(data,lib.Date)==0){
              printstr(lib);
            }
          }
          fclose(fp);
          break;
      }
    case 5:
      bsort();
      break;
    case 6:
      break;
    }
 }
 return 0;
}
