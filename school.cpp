#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_studant 100
#define max_subject 20
#define max_student_name_len 20
#define max_subject_name_len 20

void clear();
void display();
int ask(char msg[20],char d);
int com_il(int a, int b);
int input_sd();
int main(){
	int total_student, total_subject, i, j, tmp;
	int rol[max_studant], per[max_studant], total[max_studant], marks[max_studant][max_subject];
	char name[max_studant][max_student_name_len], subject_name[max_subject][max_student_name_len];

	// show range or info
	printf("Maximum entry of student is %d",max_studant);
	printf("Maximum entry of subject is %d",max_subject);
	printf("Maximum entry of student name lenth is %d",max_student_name_len);
	printf("Maximum entry of subject name lenth is %d",max_subject_name_len);
	if (ask("Can you continue?",'Y') == 1)
	{
		goto tqexit;
	}

	printf("Enter the number of total student: ");
	scanf("%d",&total_student);

	printf("Enter the number of total subject: ");
	scanf("%d",&total_student);

	if (ask("you all sujtect exam marks are sem? ",'y')==0)
	{
		
	}
	else{

	}
	


	tqexit:
		printf("Thankyou for using this application.");
		goto exit;
	exit:
		return 0;
}