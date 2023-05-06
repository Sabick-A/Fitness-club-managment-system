#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct digits{
	int m;
	int a;
	int e;
};

struct customer {
    int id;
    char name[50];
    char mobile_number[15];
    float BMI;
    char address[100];
    char date_of_joining[15];
    char package_details[50];
};


void add_record(struct customer c) {
    FILE *fp;
    fp = fopen("customer_records.txt", "a");
    if (fp == NULL) {
    	system("cls");
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(fp, "%d %s %s %f %s %s %s\n", c.id, c.name, c.mobile_number, c.BMI, c.address, c.date_of_joining, c.package_details);
    fclose(fp);
    system("cls");
    printf("Record added successfully!\n");
}


void delete_record(int id) {
    FILE *fp1, *fp2;
    int flag = 0;
    struct customer c;
    fp1 = fopen("customer_records.txt", "r");
    fp2 = fopen("temp.txt", "w");
    if (fp1 == NULL || fp2 == NULL) {
    	system("cls");
        printf("Error opening file!\n");
        exit(1);
    }
    while (fscanf(fp1, "%d %s %s %f %s %s %s\n", &c.id, c.name, c.mobile_number, &c.BMI, c.address, c.date_of_joining, c.package_details) != EOF) {
        if (c.id != id) {
            fprintf(fp2, "%d %s %s %f %s %s %s\n", c.id, c.name, c.mobile_number, c.BMI, c.address, c.date_of_joining, c.package_details);
        } else {
            flag = 1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("customer_records.txt");
    rename("temp.txt", "customer_records.txt");
    if (flag == 1) {
    	system("cls");
        printf("\n\t\tRecord deleted successfully!\n");                                                                                             
    } else {
    	system("cls");
        printf("Record not found!\n");
    }
}


void display_records() {
    FILE *fp;
    struct customer c;
    fp = fopen("customer_records.txt", "r");
    if (fp == NULL) {
    	system("cls");
        printf("Error opening file!\n");
        exit(1);
    }
    system("cls");
    printf("\n\n\t\tDisplaying All Records\n\n\n");
    printf("\n\nID\tName\tMobile Number\tBMI\t\tAddress\t\tDate of Joining\t\tPackage Details\n\n");
    while (fscanf(fp, "%d %s %s %f %s %s %s\n", &c.id, c.name, c.mobile_number, &c.BMI, c.address, c.date_of_joining, c.package_details) != EOF) {
        printf("%d\t%s\t%s\t%f\t%s\t%s\t\t%s\n\n\n", c.id, c.name, c.mobile_number, c.BMI, c.address, c.date_of_joining, c.package_details);
    }
    fclose(fp);
}


void search_by_mobile_numberandname(char mobile_number[],char name[]) {
    FILE *fp;
    int flag = 0;
    struct customer c;
    fp = fopen("customer_records.txt", "r");
    if (fp == NULL) {
    	system("cls");
        printf("Error opening file!\n");
        exit(1);
    }
    while (fscanf(fp, "%d %s %s %f %s %s %s\n", &c.id, c.name, c.mobile_number, &c.BMI, c.address, c.date_of_joining, c.package_details) != EOF) {
        if (strcmp(c.mobile_number, mobile_number) == 0 && strcmp(c.name, name) == 0) {
        	system("cls");
        	printf("\n\tThe Customers matching with name %s and mobile number %s --> ",name,mobile_number);
            printf("\n\nID\tName\tMobile Number\tBMI\t\tAddress\t\tDate of Joining\t\tPackage Details\n\n");
            printf("%d\t%s\t%s\t%f\t%s\t%s\t\t%s\n\n\n", c.id, c.name, c.mobile_number, c.BMI, c.address, c.date_of_joining, c.package_details);
            flag = 1;
            break;
        }
    }
    fclose(fp);
    if (flag == 0) {
    	system("cls");
        printf("Record not found!\n");
    }
}


void search_by_id(int id) {
    FILE *fp;
    int flag = 0;
    struct customer c;
    fp = fopen("customer_records.txt", "r");
    if (fp == NULL) {
    	system("cls");
        printf("Error opening file!\n");
        exit(1);
    }
    while (fscanf(fp, "%d %s %s %f %s %s %s\n", &c.id, c.name, c.mobile_number, &c.BMI, c.address, c.date_of_joining, c.package_details) != EOF) {
        if (c.id == id) {
        	system("cls");
        	printf("\n\tThe Customers matching with id %d --> ",id);
            printf("\n\nID\tName\tMobile Number\tBMI\t\tAddress\t\tDate of Joining\t\tPackage Details\n\n");
            printf("%d\t%s\t%s\t%f\t%s\t%s\t%s\n\n\n", c.id, c.name, c.mobile_number, c.BMI, c.address, c.date_of_joining, c.package_details);
            flag = 1;
            break;
        }
    }
    fclose(fp);
    if (flag == 0) {
    	system("cls");
        printf("\tRecord not found!\n\n\n");
    }
}

void morning_slot(){
	FILE *fp1, *fp2;
	fp2 = fopen("temp.txt", "w");
	struct digits a;
	fp1 = fopen("slot_records.txt", "r");
    fp2 = fopen("temp.txt", "w");
    fscanf(fp1, "%d %d %d\n",&a.m,&a.a,&a.e);
    if(a.m<50){
    	fprintf(fp2, "%d %d %d\n",(a.m +1),a.a,a.e);
    	fclose(fp1);
    	fclose(fp2);
    	remove("slot_records.txt");
    	rename("temp.txt", "slot_records.txt");
    	system("cls");
    	printf("\n\n\tSlot booked");
	}
	else{
		system("cls");
		printf("\n\n\tSlot not Available. Try Another Slot");
	}
	
}

void afternoon_slot(){
	FILE *fp1, *fp2;
	fp2 = fopen("temp.txt", "w");
	struct digits a;
	fp1 = fopen("slot_records.txt", "r");
    fp2 = fopen("temp.txt", "w");
    fscanf(fp1, "%d %d %d\n",&a.m,&a.a,&a.e);
    if(a.a<50){
    	fprintf(fp2, "%d %d %d\n",a.m,(a.a +1),a.e);
    	fclose(fp1);
    	fclose(fp2);
    	remove("slot_records.txt");
    	rename("temp.txt","slot_records.txt");
    	system("cls");
    	printf("\n\n\tSlot booked");
	}
	else{
		system("cls");
		printf("\n\n\tSlot not Available. Try Another Slot");
	}
	
}

void evening_slot(){
	FILE *fp1, *fp2;
	fp2 = fopen("temp.txt", "w");
	struct digits a;
	fp1 = fopen("slot_records.txt", "r");
    fp2 = fopen("temp.txt", "w");
    fscanf(fp1, "%d %d %d\n",&a.m,&a.a,&a.e);
    if(a.e<50){
    	fprintf(fp2, "%d %d %d\n",a.m,a.a,(a.e + 1));
    	fclose(fp1);
    	fclose(fp2);
    	remove("slot_records.txt");
    	rename("temp.txt", "slot_records.txt");
    	system("cls");
    	printf("\n\n\tSlot booked");
	}
	else{
		system("cls");
		printf("\n\n\tSlot not Available. Try Another Slot");
	}
	
}


void slot_booking(){
	FILE *fp;
	int flag=0;
	int id;
	struct customer c;
	int choi;

	while(flag==0){
	printf("\n\n\t Slot Booking Interface");
	printf("\n\n\tEnter your id: ");
	scanf("%d",&id);
	fp = fopen("customer_records.txt", "r");
	while (fscanf(fp, "%d %s %s %f %s %s %s\n", &c.id, c.name, c.mobile_number, &c.BMI, c.address, c.date_of_joining, c.package_details) != EOF) {
        if (c.id == id) {
            flag = 1;
        }
    }
    if (flag == 0) {
    	system("cls");
        printf("\n\n\n\tID not foound!\n\n\n");
    }
	fclose(fp);
	}
	printf("\n\n\tSelect From a option Below: ");
	printf("\n\n\t1. Morning Slot");
	printf("\n\n\t2. Afternoon Slot");
	printf("\n\n\t3. Evening Slot");
	printf("\n\n\tEnter your choice: ");
    scanf("%d", &choi);
    switch(choi){
    	case 1:
    		morning_slot();
    		break;
    	case 2:
    		afternoon_slot();
    		break;
    	case 3:
    		evening_slot();
    		break;
    	default:
    		printf("Invalid Choice");
	}
}

int main() {
    int choice;
    int id;
    char mobile_number[15];
    char name[50];
    struct customer c;
    while (1) {
        printf("\n\n\t\t\tFitness Club Management System\n\n\n\n");
        printf("\t1. Add record of customer to file\n");
        printf("\t2. Delete the record of customer\n");
        printf("\t3. Display record of all customer\n");
        printf("\t4. Search the record of customer by mobile number and name\n");
        printf("\t5. Search the record of customer by id\n");
        printf("\t6. Slot booking\n");
        printf("\t7. Exit\n");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            	system("cls");
            		printf("\n\n\t\tAdding Customer Record\n\n\n");
                printf(" \tEnter customer id: ");
                scanf("%d", &c.id);
                printf(" \tEnter customer name: ");
                scanf("%s", c.name);
                printf(" \tEnter customer mobile number: ");
                scanf("%s", c.mobile_number);
                printf(" \tEnter customer BMI: ");
                scanf("%f", &c.BMI);
                getchar();
                printf(" \tEnter customer address: ");
                scanf("%s", c.address);
                printf(" \tEnter customer date of joining: ");
                scanf("%s", c.date_of_joining);
                getchar();
                printf(" \tEnter customer package details: ");
                scanf("%s", c.package_details);
                add_record(c);
                break;
            case 2:
            	system("cls");
            	printf("\n\n\t\tDeleting Customer Record\n\n\n");
                printf(" \tEnter customer id: ");
                scanf("%d", &id);
                delete_record(id);
                break;
            case 3:
            	system("cls");
                display_records();
                break;
            case 4:
            	system("cls");
            	printf("\n\n\t\tSearching Customer Using Name and Mobile Number\n\n\n");
                printf(" \tEnter customer mobile number: ");
                scanf("%s", mobile_number);
                printf(" \tEnter customer name: ");
                scanf("%s", name);
                search_by_mobile_numberandname(mobile_number,name);
                break;
            case 5:
            	system("cls");
            	printf("\n\n\t\tSearching Customer Using ID\n\n\n");
                printf(" \tEnter customer id: ");
                scanf("%d", &id);
                search_by_id(id);
                break;
            case 6:
            	system("cls");
            	slot_booking();
            	break;
            	
            case 7:
            	system("cls");
            	printf("\n\n\n\t\t\tC Project On Fitness Management System\n\n\t\t By Sabick A\n\n\n\n");
                exit(0);
            default:
                printf(" \tInvalid choice!\n\n\n");
        }
    }
    return 0;
}
