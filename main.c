//Sharing Knowledge is Power
//Sudipto Mondal->sudipto3331@gmail.com
#include<stdio.h>

struct student{
    char name[100];
    int marks;
    float CGPA;
};

int main()
{
    int numberOfStudent=5;
    struct student s[numberOfStudent];
    
    FILE *fp;
    char str[1000];
    char temp[100];
    int state=1,k=0;
    
    fp=fopen("students.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while(fgets(str, 1000, fp)!=NULL){
        for(int i=0,j=0;i<=strlen(str)-1;i++,j++){
            
            if(str[i]==' ' && state==1){
                s[k].name[j]='\0';
                state=2;
                j=-1;
            }else if(str[i]==' ' && state==2){
                temp[j]='\0';
                sscanf(temp, "%d", &s[k].marks);
                state=3;
                j=-1;
            }else if(str[i]=='\n' && state==3){
                temp[j]='\0';
                sscanf(temp, "%f", &s[k].CGPA);
                j=-1;
            }
            
            if(state==1){
                s[k].name[j]=str[i];
            }else if(state==2 && str[i]!=' '){
                temp[j]=str[i];
            }else if(state==3 && str[i]!=' '){
                temp[j]=str[i];
            }
        }
        k++;
        state=1;
        //printf("%d: %s",strlen(str),str);
    }
    fclose(fp);
    
    printf("Student's Name, Marks & CGPA are given below (NAME MARKS CGPA):\n");
    for(int i=0;i<numberOfStudent;i++){
        printf("%s ",s[i].name);
        printf("%d ",s[i].marks);
        printf("%.2f\n",s[i].CGPA);
    }
    
    return 0;
}
