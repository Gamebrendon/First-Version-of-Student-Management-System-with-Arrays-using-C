#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numOfStudents = 0;
int studentSubjects = 8;
char studentSubjectsNames[8][50] = {"Fundamentals of Programming", "Introduction to Computing", "Information Management", "Mathematics in the Modern World", "Purposive Communication", "Understanding the Self", "Physical Education", "National Service Training Program"};

struct INFORMATION {
    int studNumbers;
    int grades[8];
    char firstName[26];
    char lastName[26];
    char birthDate[26];
    char email[51];
    char cpNum[12];
};

struct INFORMATION student[100];

int addStud() {
    if (numOfStudents < 100) {
        printf("-------------------------------\n");
        printf("| \tStudent Details       |\n");       
        printf("-------------------------------\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Student Number: ");
        scanf("%d", &student[numOfStudents].studNumbers);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("First name: ");
        scanf("%s", &student[numOfStudents].firstName);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Last name: ");
        scanf("%s", &student[numOfStudents].lastName);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Date of Birth: ");
        scanf(" %[^\n]", &student[numOfStudents].birthDate);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Email Address: ");
        scanf("%s", &student[numOfStudents].email);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Cellphone Number: ");
        scanf("%s", &student[numOfStudents].cpNum);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        numOfStudents++;

        printf("\n| THE STUDENT IS ADDED SUCCESSFULLY | \n");    
        
    } else {
        printf("The maximum students are reached, cannot add more students.\n");
    }
    
    return 0;
}

int updateStud() {
    int studNum;
    printf("------------------------------------------\n");
    printf("| \t  Update Student Details           |\n");
    printf("------------------------------------------\n");

    printf("Enter the Student Number to update: ");
    scanf("%d", &studNum);
    for (int i = 0; i < numOfStudents; i++) {
        if (student[i].studNumbers == studNum) {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("New First name: ");
            scanf("%s", &student[i].firstName);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("New Last name: ");
            scanf("%s", &student[i].lastName);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("New Date of Birth: ");
            scanf(" %[^\n]", &student[i].birthDate);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("New Email Address: ");
            scanf("%s", &student[i].email);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("New Cellphone Number: ");
            scanf("%s", &student[i].cpNum);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("| STUDENT %d UPDATED SUCCESSFULLY |\n", studNum);
            return 1;
        } 
    }  
        printf("Student %d not found. \n", studNum);
        return 0;
}

int deleteStud() {
    int studNum;
    char decision;
    printf("----------------------------------\n");
    printf("| \tDelete a Student         |\n");
    printf("----------------------------------\n");

    printf("Enter Student ID to delete: ");
    scanf("%d", &studNum);

    printf("Are you sure you want to delete this student? (y/n): ");
    scanf(" %c", &decision);

    if (decision == 'y' || decision == 'Y'){ 
        for (int i = 0; i < numOfStudents; i++) {
            if (student[i].studNumbers == studNum) {
                for (int j = i; j < numOfStudents - 1; j++) {
                    student[j].studNumbers = student[j + 1].studNumbers;
                    strcpy(student[j].cpNum, student[j + 1].cpNum);
                    strcpy(student[j].firstName, student[j + 1].firstName);
                    strcpy(student[j].lastName, student[j + 1].lastName);
                    strcpy(student[j].birthDate, student[j + 1].birthDate);
                    strcpy(student[j].email, student[j + 1].email);
                }
                numOfStudents--;
                printf("Student %d deleted successfully.\n", studNum);
                return 1;
                } 
            } 
            printf("Student %d not found.\n", studNum);
            return 0;
    } else {
        for (int i = 0; i < numOfStudents; i++) {
            if (student[i].studNumbers == studNum) {
                printf("Student %d not deleted. \n", studNum);
                return 0;
            }
        }
        printf("Student %d not found. \n", studNum);
        return 0;
    }
} 

float getAverage(int grades[], int subjects) {
    int total = 0;
    for (int i = 0; i < subjects; i++) {
        total += grades[i];
    }
    return (float)total / subjects;
}

int displayStud() {
    if (numOfStudents == 0) {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("No students available.\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    } else {
        printf("----------------------------\n");
        printf("\tStudent List\n");
        printf("----------------------------\n");
        for (int i = 0; i < numOfStudents; i++) {
            printf("Student Number: %d\n", student[i].studNumbers);
            printf("Student: %s %s\n", student[i].firstName, student[i].lastName);
            printf("Contact Number: %s\n", student[i].cpNum);
            printf("Email: %s\n\n", student[i].email);
            }
        }
    }

int inputGrades() {
    int studNum;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter Student Number to input grades: ");
    scanf("%d", &studNum);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for (int i = 0; i < numOfStudents; i++) {
        if (student[i].studNumbers == studNum) {
            for (int j = 0; j < studentSubjects; j++) {
                    printf("%s Grade: ", studentSubjectsNames[j]);
                    if (scanf("%d", &student[i].grades[j]) != 1) {
                        printf("Invalid Input. Enter a number properly.\n");
                        while (getchar() != '\n');
                        j--;
                    }
            }
            printf("\nStudent %d grades entered successfully.\n", studNum);
            return 1;
        }
    }
        printf("Student %d not found. \n", studNum);   
        return 0;
}

int searchStudents() {
    int studNum;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter Student Number to search: ");
    scanf("%d", &studNum);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for (int i = 0; i < numOfStudents; i++) {
        if (student[i].studNumbers == studNum) {
            for (int j = i; j < numOfStudents; j++) {
                printf("Student %d is found.\n\n", studNum);
                    printf("Student: %s %s\n", student[j].firstName, student[j].lastName);
                    printf("Contact Number: %s\n", student[j].cpNum);
                    printf("Email: %s\n", student[j].email);
                    return 1;
            }
        }
    }
        printf("Student %d not found. \n", studNum);   
        return 0;   
}

int viewGrades() {
    int studNum;

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter the Student Number to view grades: ");
    scanf("%d", &studNum);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    for (int i = 0; i < numOfStudents; i++) {
        if (student[i].studNumbers == studNum) {
            printf("Student Number: %d\n", studNum);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Student: %s %s\n", student[i].firstName, student[i].lastName);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            float average = getAverage(student[i].grades, studentSubjects);
            for (int j = 0; j < studentSubjects; j++) {
                printf("%s: %d\n", studentSubjectsNames[j], student[i].grades[j]);
            }
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Average Grade: %.2f\n", average);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                if (average >= 75) {
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("Result: Passed!\n");
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    return 1;
                } else {
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("Result: Failed!\n");
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    return 1;
            }   
        } 
    }
        printf("Student %d not found. \n", studNum);   
        return 0;   
}

void aboutUs() {
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|\t Welcome to Student Management System! A student management system keeps track of and stores a student's grades, records, and personal     |\n| data, among other things.                                                                                                                         |\n");
    printf("|                                                                                                                                                   |\n");
    printf("|\t This system was developed by Bachelor Science in Computer Science first-year students at City College of Angeles.                          |\n|");
    printf("                                                                                                                                                   |\n");
    printf("|   Panlaqui Brendon   |   David Nikko Miguel  |   Manalo Warren   |   Naguit Sean Warren   |   Wiyangco Edcel Carlos   |   Zamora Kristine Angela  |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
}


void welcome() {
    printf("-----------------------------------------------------\n");
    printf("|\tWelcome to Student Management System        | \n");
    printf("-----------------------------------------------------\n\n");

    printf("1. Add Student\n2. Update Student\n3. Delete Student\n4. Search Student\n5. Display Students\n6. Input Grades\n7. View Grades\n8. About Us\n9. Exit\n\n");
    int option;
    printf("Choose an option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            addStud();
            break;
        case 2:
            updateStud();
            break;
        case 3:
            deleteStud();
            break;
        case 4:
            searchStudents();
            break;
        case 5:
            displayStud();
            break;
        case 6:
            inputGrades();
            break;
        case 7:
            viewGrades();
            break;
        case 8:
            aboutUs();
            break;
        case 9:
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("THANK YOU FOR USING OUR FINAL PROJECT:)) \n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            exit(1);
        default:
            printf("Invalid Option. Please enter a valid one.\n");
    }
}

int main () {
    char repeat;
    do {
        welcome();
            printf("\nWould you like to choose another option? (y/n): ");
            scanf("%s", &repeat);
            if (repeat == 'n' || repeat == 'N') {
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("THANK YOU FOR USING OUR FINAL PROJECT:)) \n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
    } while (repeat != 'n' && repeat != 'N');
    
    return 0;
}