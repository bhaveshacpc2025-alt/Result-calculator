#include<stdio.h>
#include<string.h>

float spi(int credit[100],int marks[100],int num);
int Index(int marks);
void Grade(int m);
int max_marks;

struct student{
    float max_spi;
    int subject_count,passing_mark,topper_enroll,student_count,backlog,obtained_marks;  
};

int main()
{
        FILE *record;
            record=fopen("record.txt","a");
      //initialization of topper spi and Enrollment 
      struct student s1;
      s1.max_spi=0;
      s1.topper_enroll=0;
      
      char topper_name[200];
      
         printf("=====Result Calculator=====\n");
             printf("\t\tPlease enter the required information\n");
                printf("Enter total number of subjects: ");
                scanf("%d",&s1.subject_count);
                printf("Enter maximum marks for each subject: ");
                scanf("%d",&max_marks);
    
                do{
                    printf("Enter minimum passing marks: ");
                    scanf("%d",&s1.passing_mark);
                    if(s1.passing_mark<0 || s1.passing_mark>max_marks){printf("\t\t Enter a valid limit...\n");}
                    else{break;}
                }while(1);
                
                int spi_choice;
                do{
                    printf("wants to calculate SPI(yes=1;no=0):");
                    scanf("%d",&spi_choice);
                    if(spi_choice<=1 && spi_choice>=0){break;}
                    else{printf("invailid\n");}
                }while(1);
                
         int credit[s1.subject_count];       
         char sub[s1.subject_count][500];
                
                for(int i=0;i<s1.subject_count;i++){
                    printf("Enter name of %d subject: ",i+1);
                    getchar();
                    fgets(sub[i],500,stdin);
                    if(spi_choice==1){
                    printf("Enter credit: ");
                    scanf("%d",&credit[i]);}
                      
                }
                printf("\n🎯 Enter all marks between 0 to %d 🎯\n\n",max_marks);
      
      //Total number of students
      
                printf("👧Enter number of students👨: ");
                scanf("%d",&s1.student_count);
      
      //Entry of every students   
      for(int j=1;j<=s1.student_count;j++){
                s1.backlog=0;
                //input Enrollment number of student      
                int Enrollment;
                printf("Sr Number: %d",j);
                do{
                printf("\nEnter last two digits of enrollment number: ");
                scanf("%d",&Enrollment);
                if(1>Enrollment || Enrollment>s1.student_count){printf("\t❗❌❗❌Enter valid Enrollment between 01 to %d ❌❗ ❌❗\n",s1.student_count);}
                else{break;}
                }while(1); 
            
                getchar();
                char ch[200];
                printf("Enter name of student: ");
                fgets(ch,200,stdin);
                //input marks of student
                
                int a[s1.subject_count];
                for(int i=0;i<s1.subject_count;i++){
                    
                     printf("\nEnter marks of %s:",sub[i]);
                     
    
                do{
                    scanf("%d",&a[i]);
                if(0>a[i] || a[i]>max_marks){printf("\t❗❌Invalid marks! please enter between 0 to %d❌❗\n",max_marks);}
                else{break;}
                }while(1);  
                Grade(a[i]);

                if(a[i]<s1.passing_mark){
                    printf("\nYou have backlog in ");
                    puts(sub[i]);
                    s1.backlog=s1.backlog+1;
                }
                }
                
         //Calculation of Percentage of student(result section)  
         float total_marks=(max_marks*s1.subject_count);   
         printf("\n\n======Result======\n");
         printf("Enrollment number: 2501401070%.2d \n",Enrollment);
         printf("Student name: ");
         printf("%s",ch);
         s1.obtained_marks=0;
         for(int i=0;i<s1.subject_count;i++){
                s1.obtained_marks=s1.obtained_marks+a[i];
         }
                printf("\nTotal marks: %d/%.2f\n",s1.obtained_marks,total_marks);
         float percentage=(s1.obtained_marks*100.0)/total_marks;        
                printf("Percentage: %.2f \n",percentage);
                
      //print spi of student and detection of topper 
      float  result_spi=spi(credit,a,s1.subject_count);  
      if(spi_choice==1){       
       printf("Semester Performance Index: %.3f\n \n", result_spi);
       fprintf(record,"%s\t2501401070%.2d\t%.3f\t%f\n",ch,Enrollment, result_spi,percentage);
      }
      else{fprintf(record,"%s\t2501401070%.2d\t%f\n",ch,Enrollment,percentage);}

      if(result_spi>s1.max_spi){
            s1.max_spi=result_spi;
             s1.topper_enroll=Enrollment;
             strcpy(topper_name,ch);
        }
        
      if(s1.backlog==0){printf("🥳 Congratulations! You have passed all subjects 🥳 \n");}

      //detection of grade using Percentage 
        if(percentage>=90){printf("🥇 Grade is A1 🥇 \n");}
        else if(percentage>=80 && percentage<90){printf("🥈 Grade is A2 🥈 \n");}
        else if(percentage>=70 && percentage<80){printf("🥉 Grade is B1 🥉 \n");}
        else if(percentage>=60 && percentage<70){printf("🏆 Grade is B2 🏆\n");}
        else if(percentage>=50 && percentage<60){printf("🏆 Grade is C1 🏆\n");}
        else if(percentage>=40 && percentage<50){printf("🏆 Grade is C2 🏆\n");}
        else if(percentage>=30 && percentage<40){printf("🏆 Grade is D1 🏆\n");}
        else if(percentage>=23 && percentage<30){printf("🏆 Grade is D2 🏆\n");}
        else if(s1.backlog==s1.subject_count){printf("😞😞 You have Failed And Promotion To Next Semester is Not Allowed 😞😞");}
        else{printf("Total backlog: %d",s1.backlog);}  
        printf("\n===================\n");
    }
    //Class topper declaration
    printf("\n ===Class Topper=== \n");
    printf("Name: %s",topper_name);
    printf("Enrollment number: 2501401070%.2d \n", s1.topper_enroll);
    printf("SPI: %f",s1.max_spi);
    
    fclose(record);
        return 0;
}

//function which calculate spi
float spi(int credit[],int marks[],int num){
    int total=0;
    for(int i=0;i<num;i++){
        total=total+credit[i];
    }
    int total_index=0;
    for(int i=0;i<num;i++){
        total_index=total_index+(credit[i]*Index(marks[i]));
    }
    float spi=(float)total_index/total;
    return spi;
}

//function which returns index of each subject
int Index(int marks){
    if(marks>=(max_marks*0.9)) return 10;
    else if(marks>=(max_marks*0.8)) return 9;
    else if(marks>=(max_marks*0.7)) return 8;
    else if(marks>=(max_marks*0.6)) return 7;
    else if(marks>=(max_marks*0.5)) return 6;
    else if(marks>=(max_marks*0.4)) return 5;
    else if(marks>=(max_marks*0.3)) return 4;
    else return 0;
}

//function which decide grade of each subjects using marks
void Grade(int m){
    if(m>=(max_marks*0.9)) {printf("Grade: AA");}
    else if(m>=(max_marks*0.8)){printf("Grade: AB");}
    else if(m>=(max_marks*0.7)){printf("Grade: BB");}
    else if(m>=(max_marks*0.6)){printf("Grade: BC");}
    else if(m>=(max_marks*0.5)){printf("Grade: CC");}
    else if(m>=(max_marks*0.4)){printf("Grade: CD");}
    else if(m>=(max_marks*0.3)){printf("Grade: DD");}
    else{printf("Grade: FF");}
}