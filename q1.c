#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct employee {
	int code;
	char name[20];
	char date_of_joining[20];
};

void create_employee(struct employee emp[],char *emp_name, int emp_code, char emp_date[20], int index){
	strcpy((*(emp + index)).name , emp_name);
	(*(emp + index)).code = emp_code;
	strcpy((*(emp + index)).date_of_joining , emp_date);
	
}

void calculate_tenure(struct employee emp[]){
	int i = 0;
	char current_date[11];
	int tenure = 0;
	int count = 0;
	int curr_year = 0;
	printf("Enter Current Date in format: DD/MM/YYYY: ");
	scanf("%s", current_date);
	int curr_date_len = strlen(current_date);
	// Starting from start of year and ending on end of year
	// For current year
	for(i=curr_date_len - 4;i<curr_date_len;i++)
		curr_year =  (curr_year * 10) + (current_date[i] - 48);

	
	for(i=0;i < 4;i++) {
		tenure = strcmp(current_date, (emp + i)->date_of_joining);
		int date_len = strlen((emp + i)->date_of_joining);
		int year = 0;
		int j = 0;
		// Starting from start of year and ending on end of year
		// For year of employment
		for(j=date_len - 4;j<date_len;j++)
			year =  (year * 10) + (emp[i].date_of_joining[j] - 48);
		tenure = curr_year - year;
		if(tenure > 3) {
			count++;
			printf("Name: %s\n", (emp + i)->name);
			printf("code: %d\n", (emp + i)->code);
			printf("date of joining: %s\n\n", (emp + i)->date_of_joining);
		}
	}

	if (count > 0)
		printf("Number of Employees with tenure more than 3 years: %d\n", count);
	
}

int main(){
	int code;
	char date[11];
	char name[20];
	
	
	struct employee emp[4];
	int i=0;
	for(;i < 4; i++){
		printf("Enter employee name: ");
		scanf("%s", name);
		printf("Enter employee code: ");
		scanf("%d", &code);
		printf("Enter employee date of employement in format DD/MM/YYYY: ");
		scanf("%s", date);
		
		create_employee(emp, name, code, date, i);
	}
	
	/*struct employee emp[4] = {
        {101, "Alice Smith", "15/05/2020"},
        {102, "Bob Johnson", "12/03/2018"},
        {103, "Charlie Brown", "01/09/2022"},
        {104, "Diana Carter", "25/11/2019"}
    };*/

	calculate_tenure(emp);
	
	
	
	return 0;
}
