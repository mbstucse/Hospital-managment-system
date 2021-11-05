#include<stdio.h>
#include<string.h>
#define ll int
void Add_test();
void Add_patient();
void Add_doctor();
void Search_test();
void Search_patient();
void Search_doctor();
void Delete_patients();
void Delete_doctor();
void Delete_test();
void blood_bank();
void add_organd();
void delete_od();
void book_cabin();
void search_medicine();
void add_medicin();
void medicine();

struct patients
{
    ll serial,room;
    char name[20];
    char sex [6];
    char disease[10];
    char blood[4];
    char contact[12];
};

struct doctors
{
    ll serial,room;
    char name[20];
    char contact[16];
    char desig[30];
    char w_days[20];
    char w_hour[20];
};

struct test
{
    char name[20];
    ll coast;
};

struct blood
{
     char grp[11];
     char name[15];
     char contact[13];
};

struct organ
{
char organ_n[20];
char d_name[22];
int age;
char sex[4];
char contact[13];
};

struct medicine
{
   char name[55];
   int qnty;
   int cnt;
   char company[20];
   int price;

};
int Login(char Username[100],char Password[100])
{
    if(strcmp(Username,"admin")==0&&strcmp(Password,"123")==0)return 1;
    else return 0;
}
int main()
{
    char Username[200],Password[20];
    printf("______Welcome to Health & Heal Hospital______\n\n\n\n");
    printf(" Enter Username: ");
    gets(Username);
    printf(" Enter Password: ");
    gets(Password);
    int test=Login(Username,Password);
    if(test==1)
    printf("\nSuccessfully Login !!\n\n");
    else
    printf("Invalid Username or Password\n");
    if(test==1)
    {
        while(1)
        {
            printf("Please Choose option :\n\n\n");
            printf("1: Add patient\n");
            printf("2: Add Doctor\n");
            printf("3: Add Medicale_test\n");
            printf("4: Search patient\n");
            printf("5: Search doctors\n");
            printf("6: Search Test\n");
            printf("7: Delete Patients_record\n");
            printf("8: Delete Doctors_record\n");
            printf("9: Delete Test_record\n");
            printf("10: Blood_Bank:\n");
            printf("11: Organ_donation\n");
            printf("12: Medicine_store\n");
            printf("13: Exit\n\n");
            printf(" Enter your option: ");
            int c;
            scanf("%d",&c);
            if(c==1)
                Add_patient();
            else if(c==2)
                Add_doctor();
            else if(c==3)
                Add_test();
            else if(c==4)
                Search_patient();
            else if(c==5)
                Search_doctor();
            else if(c==6)
                Search_test();
            else if(c==7)
                Delete_patients();
            else if(c==8)
                Delete_doctor();
            else if(c==9)
                Delete_test();
            else if(c==10)
                blood_bank();
            else if(c==11)
                 Organ();
            else if(c==12){
              medicine();
            }
            else if(c!=13)
                printf("\n Please enter a valid number\n");
            else return 0;
        }
    }
}
void Add_patient()
{

     FILE *f1,*f2;

     struct patients p;
     f1=fopen("patients1.txt","ab");
     printf(" Enter number patients Serial number\n");
     fflush(stdin);
        scanf("%d",&p.serial);

        printf(" Enter number patients Room number\n");
        fflush(stdin);
        scanf("%d",&p.room);
        fflush(stdin);
        printf(" Enter number patients Name\n");
        scanf("%s",p.name);

        printf(" Enter number patients Sex\n");
        fflush(stdin);
        scanf("%s",p.sex);

        printf(" Enter number patients Disease\n");
        fflush(stdin);
        scanf("%s",p.disease);
        printf(" Enter number  patients Blood Group\n");
        fflush(stdin);
        scanf("%s",p.blood);
        printf(" Enter number  patients contact number\n");
        fflush(stdin);
        scanf("%s",p.contact);
        fwrite(&p,sizeof(p),1,f1);
        fclose(f1);
        printf("  patient added successfully\n");
        system("cls");

}

void Search_patient()
{

    FILE *f1;
    struct    patients p[2000];
    f1=fopen("patients1.txt","rb");
    if(f1==NULL)
    {
        printf("!The patients list is empty//!!\n");
        return ;
    }
    fread(p,sizeof(struct patients),2000,f1);
    printf(" Enter the serial number of patients: ");
    ll sr;
    scanf("%d",&sr);
    for(int i=0; i<2000; i++)
    {
        if(p[i].serial==sr)
        {
            printf("\n Serial number = %d\n",p[i].serial);
            printf(" Room number = %d\n",p[i].room);
            printf(" Name = %s\n",p[i].name);
            printf(" Sex = %s\n",p[i].sex);
            printf(" Disease = %s\n",p[i].disease);
            printf(" Contact number = %s\n",p[i].contact);
            fclose(f1);
            return ;
        }
    }
    printf(" The patient not found\n");
    fclose(f1);

}
void Delete_patients()
{
    FILE *f1;
    struct    patients p[2000];
    f1=fopen("patients1.txt","rb");
    if(f1==NULL)
    {
      printf("!The patients list is empty//!!\n");
      return ;
    }
    fread(p,sizeof(struct patients),2000,f1);
    fclose(f1);
    f1=fopen("patients1.txt","wb");
    printf("Enter the serial number of patients: ");
    ll sr;
    scanf("%d",&sr);
    for(int i=0; i<2000; i++)
    {
        if(p[i].serial==sr)
                   printf("  Successfully deleted patients records\n");
        else if(p[i].serial!=sr && p[i].serial>0)
        fwrite(&p[i],sizeof(p[i]),1,f1);
    }
    fclose(f1);
    system("cls");
}
void Add_doctor()
{
    FILE *f;
    struct doctors p;
    f=fopen("doctors1.txt","ab");

        printf(" Enter number doctor Serial number\n");
        fflush(stdin);
        scanf("%d",&p.serial);
        printf(" Enter number doctor Room number\n");
        fflush(stdin);
        scanf("%d",&p.room);
        printf(" Enter number doctor Name\n");
        fflush(stdin);
        scanf("%s",p.name);
        printf(" Enter number doctor contact number\n");
        fflush(stdin);
        scanf("%s",p.contact);
        printf(" Enter number doctor designation\n");
        fflush(stdin);
        scanf("%s",p.desig);

        printf(" Enter number doctor Working_days\n");
        fflush(stdin);
        scanf("%s",p.w_days);

        printf(" Enter number doctor working_hour\n");
        fflush(stdin);

        scanf("%s",p.w_hour);
        fwrite(&p,sizeof(p),1,f);
        fclose(f);
        system("cls");
}
void Search_doctor()
{
    FILE *f1;
    struct doctors p[2000];
    f1=fopen("doctors1.txt","rb");
    if(f1==NULL)
    {
        printf("!The doctors list is empty//!!\n");
        return ;
    }
    fread(p,sizeof(struct doctors),2000,f1);
    printf("Enter the Name of doctor: ");
    char sr[20];
    fflush(stdin);
    scanf("%s",sr);
    ll cnt=0;
    for(int i=0; i<2000; i++)
    {
        if(strcmp(p[i].name,sr)==0 && p[i].serial!=-1)
        {
            printf("\n Serial number = %d\n",p[i].serial);
            printf("   Room number = %d\n",p[i].room);
            printf("   Name = %s\n",p[i].name);
            printf("   Contact number = %s\n",p[i].contact);
            printf("   Designation = %s\n",p[i].desig);
            printf("   Working_days = %s\n",p[i].w_days);
            printf("   Working_hour = %s\n",p[i].w_hour);
            fclose(f1);
            return ;
        }
    }
    printf("The information doesnt exits !!!\n");
    fclose(f1);
}
void Delete_doctor()
{
    FILE *f1;
    struct   doctors p[2000];
    f1=fopen("doctors1.txt","rb");
    if(f1==NULL)
    {
      printf("!The patients list is empty//!!\n");
      return ;
    }
    fread(p,sizeof(struct doctors),2000,f1);
    fclose(f1);
    f1=fopen("doctors1.txt","wb");
    printf("Enter the serial number of patients: ");
    ll sr;
    scanf("%d",&sr);
    for(int i=0; i<2000; i++)
    {
        if(p[i].serial==sr)
                   printf("  Successfully deleted patients records\n");
        else if(p[i].serial!=sr && p[i].serial>0)
        fwrite(&p[i],sizeof(p[i]),1,f1);
    }
    fclose(f1);
    system("cls");

}
void Add_test()
{
    FILE *f;
    struct test p;
    f=fopen("test1.txt","ab");

        printf(" Enter number the Medicale_test Name\n");
        fflush(stdin);
        scanf("%s",p.name);
        printf(" Enter number  Medicale_test coast\n");
        fflush(stdin);
        scanf("%d",&p.coast);
        fwrite(&p,sizeof(p),1,f);
    fclose(f);
    system("cls");
}
void Search_test()
{
    FILE *f1;
    struct test p[200];
    f1=fopen("test1.txt","rb");
    if(f1==NULL)
    {
        printf(" The patients list is empty//!!\n");
        return ;
    }
    fread(p,sizeof(struct test),200,f1);
    printf(" Enter the name of test : ");
    char c[22];
    scanf("%s",c);
    fflush(stdin);
    ll cnt=0;
    for(int i=0 ;i<200; i++)
    {
        ll k=strcmp(p[i].name,c);
        if(k==0)
        {
            cnt=1;
            printf("\n Medicale_test Name = %s",p[i].name);
            printf("\n Test_Coast = %d\n",p[i].coast);
            break;
        }
    }
    if(cnt==0)
    printf("\n The information doesnt exits\n");
    fclose(f1);
}
void Delete_test()
{
    FILE *f1;
    f1=fopen("test1.txt","rb");
    struct test p[200];
    fread(p,sizeof(struct test),200,f1);
    fclose(f1);
    f1=fopen("test1.txt","wb");
    printf(" Enter the name of the test: ");
    char c[20];
    fflush(stdin);
    scanf("%s",c);
    fflush(stdin);
    for(int i=0; i<200; i++)
    {
        if(strcmp(p[i].name,c)==0)
        {
            printf(" Deletion completed!!\n");
        }
        else{
                fwrite(&p[i],sizeof(p[i]),1,f1);
        }
    }
    fclose(f1);
    system("cls");
}

void blood_bank()
{
    printf(" Press 1 for Add donor\n");
    printf(" Press 2 for Search donor\n");
    int t;
    scanf("%d",&t);

    if(t==1)
    {
        FILE *f1;
        struct blood p;
        f1=fopen("blood1.txt","ab");
        printf(" Blood group : ");
        fflush(stdin);
        scanf("%s",p.grp);
        fflush(stdin);
        printf(" Name : ");
        scanf("%s",p.name);
        printf(" Contact : ");
        fflush(stdin);
        scanf("%s",p.contact);
        fwrite(&p,sizeof(p),1,f1);
        fclose(f1);
        system("cls");

   }
    else{
        char c[5];
        printf(" Enter needed Blood group : ");
        scanf("%s",c);
        FILE *f;
        f=fopen("blood1.txt","rb");
        struct blood t[200];
        fread(t,sizeof(struct blood),200,f);
        for(int i=0;i<200;i++){
                    if(strcmp(t[i].grp,c)==0){
                    printf("Blood group: %s\nDonor Name: %s\nContact number: %s\n",t[i].grp,t[i].name,t[i].contact);
                    fclose(f);
                    return ;
            }
        }
        printf(" Sorry not found\n");
        fclose(f);
       }

}
void Organ()
{
    printf(" Press 1 for donating organ\n");
    printf(" press 2 for search organ donator\n");
    int t;
    scanf("%d",&t);
    if(t==1){

          FILE *f;
          struct organ p;
          f=fopen("organ1.txt","ab");
          printf(" Name of the organ\n");
          fflush(stdin);
          scanf("%s",p.organ_n);
          printf(" Name of the donor\n");
          fflush(stdin);
          scanf("%s",p.d_name);
          printf(" sex: \n");
          fflush(stdin);
          scanf("%s",p.sex);
          printf(" age: \n");
          fflush(stdin);
          scanf("%d",&p.age);
          printf(" contact: \n");
          fflush(stdin);
          scanf("%s",p.contact);
          fwrite(&p,sizeof(p),1,f);
          fclose(f);
          system("cls");
          return ;

    }
    else {
        char c[10];
        printf(" Enter needed Organ Name  : ");
        scanf("%s",c);
        FILE *f;
        f=fopen("organ1.txt","rb");
        struct organ t[200];
        fread(t,sizeof(struct organ),200,f);
        int ok=0;
        for(int i=0;i<200;i++){
                    if(strcmp(t[i].organ_n,c)==0){ok++;
         printf("Organ name:%s\nDonor name: %s\nContact number: %s\n Age: %d\nSex :%s\n",t[i].organ_n,t[i].d_name,t[i].contact,t[i].age,t[i].sex);
            }
        }
        if(ok==0)
        printf("  Sorry not found!!!\n");
        fclose(f);
       }
}
void medicine(){

    printf("press 1 for add medicine\n");
    printf("press 2 search medicine\n");
    int c;
    scanf("%d",&c);
    if(c==1){
          FILE *f;
          struct medicine p;
          f=fopen("Medicine1.txt","ab ");
          printf(" Name of the Medicine\n");
          fflush(stdin);
          scanf("%s",p.name);
          printf(" Quantityofelement\n");
          fflush(stdin);
          scanf("%d",&p.qnty);
          printf(" How many: \n");
          fflush(stdin);
          scanf("%d",&p.cnt);
          printf(" Company: \n");
          fflush(stdin);
          scanf("%s",p.company);
          fwrite(&p,sizeof(p),1,f);
          fclose(f);
          system("cls");
          return ;
    }
    else{
        char c[55];
        printf(" Enter needed Medicine Name  : ");
        scanf("%s",c);
        printf(" Enter weight : ");
        int w;
        scanf("%d",&w);
         FILE *f;
        f=fopen("Medicine1.txt","rb");
        struct medicine t[200];
        fread(t,sizeof(struct medicine),200,f);
        int ok=0;
        for(int i=0;i<200;i++){
                    if(strcmp(t[i].name,c)==0 &&w==t[i].qnty){ok++;
                    printf(" Name of medi: %s\n Quantyofelement: %d mg\n Count: %d\n Company: %s\n",t[i].name,t[i].qnty,t[i].cnt,t[i].company);
                    fclose(f);
                    return;
            }
        }
        printf(" Sorry not found!!!\n");
        fclose(f);

    }
}

