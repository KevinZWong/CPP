#include <stdio.h>
#include "Student.h"
#include <iostream>

// define an array of students
Student CIS054[] = {
    { "joe Williams", 12345, 4.0, "Computer Science" },
    { "Sally Washington", 55458, 3.7,"Math" },
    { "Fred MacIntosh", 66587, 2.9 , "English"},
    { "Jose De La Cruz", 67892, 3.5, "Computer Science"},
    { "777 Dan McElroy", 77777, 4.0, "Marine Biology"},
    { "Thinh Nguyen", 73657, 3.6, "Math"}
};

int main(int argc, char* argv[])
{
    cout << "  ID #    NAME                MAJOR" <<endl;
    cout << "  ============================================" <<endl;

    int NumberOfStudents = sizeof(CIS054)/sizeof(Student);
    // Display the header line
     // List all the students in the course
    for (int i=0; i<NumberOfStudents; i++) {
        int error2 = 0;
        if (CIS054[i].IdNumber == 0){
            cout << " bad id  ";
            error2 = 1;
        }
        if (error2 != 1) 
            printf ("  %5d  %-18s %-10s\n", CIS054[i].IdNumber, CIS054[i].name.c_str(), CIS054[i].major.c_str());
        else
            printf ("%-18s %-10s\n", CIS054[i].name.c_str(), CIS054[i].major.c_str());
    }
    printf ("\n");   // blank line after displaying the student names

    // compute the average gpa of all the students
    double total=0;
    int error1 = 0;

    for (int i=0; i<NumberOfStudents; i++){
        if ( CIS054[i].gpa == 0){
            printf("Illegal gpa values are present");
            error1 = 1;
        }
        total += CIS054[i].gpa;
    }
        
    double average = total / NumberOfStudents;
    if (error1 != 1)
        printf ("  The average GPA of all the students is %lf\n\n", average);


	return 0;
}