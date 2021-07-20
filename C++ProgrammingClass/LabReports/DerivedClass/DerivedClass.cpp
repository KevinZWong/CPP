/*
Derived Class
Kevin Wong
7/17/2021
Version 1
*/
#include <iostream>
#include <cstring>
using namespace std;

////////////// Person class Definition /////////////////
class Person {
protected:  // A derived class can access protected data
    char Name[20];
public:
    Person (const char* n)
    {
        // choose the version of strcpy for your compiler
        // comment out the other version
//      strcpy_s(Name, n);  // for Microsoft
        strcpy  (Name, n);  // for everywhere except Microsoft
    }
    virtual void print() const
    {
        cout << "Person:  " << Name << endl;
    }
};

///////////// Student class Definition //////////////
class Student : public Person  {
private:
    int    units;
public:
    // Student constructor gets name from Person class
    Student (const char* n, int u) : Person ( n)
    {
        units = u;
    }
    virtual void print() const
    {
        cout << "Student: " << Name << "  Units: " << units << endl;
    }
};

//////////// Teacher class Definition /////////////////
class Teacher : public Person  {
	private:
		int    numberOfStudents;
		int	   numberOfClasses;
	public:
        // Teacher constructor gets 'name' from the Person class
		Teacher (const char* n, int s, int c) : Person ( n)
		{
			numberOfStudents = s;
			numberOfClasses = c;
		}
		virtual void print() const
		{
			cout << "Teacher: " << Name 
				<< "  Students: " << numberOfStudents 
				<< "  Classes: " << numberOfClasses << endl;
		}
};


class Employee: public Person{
	private:
        int  EmpNo;    // Employee number
        double Hours;
        double PayRate;

	public:
        // Teacher constructor gets 'name' from the Person class
		Employee (const char* n, int id, int h, int p) : Person ( n)
		{
            EmpNo = id;
			Hours = h;
			PayRate = p;
		}
		virtual void print() const
		{
            double pay = Hours * PayRate;
			cout << "Employee: " << Name 
            << "  ID: " << EmpNo  
			<< "  Pay: $" << pay << endl;
		}
};




/////////// main program ///////////////////////
int main(int argc, char* argv[])
{
    // create objects from several different types of classes
	Student s1("bob        ", 11);
	Student s2("bobby      ", 12);
	Student s3("bobber     ", 13);
	Student s4("bobbington ", 14);
	Teacher t1("bobinson   ", 15, 16);
	Teacher t3("bobingson  ", 17, 18);
    Teacher t4("bobbette   ", 19, 110);
    Employee e1("bobbie    ", 112345, 111, 122);
    Employee e2("bub       ", 154321, 122, 133);



	// Create an array of pointers to different people
	// NOTE: The array of pointers is not in the same order as the above list
	Person *List[] = { &t1, &s2, &s3, &s4, &s2, &t3, &t4, &e1, &e2};	
	int SizeOfList = sizeof(List)/sizeof(Person*);

	for (int i=0; i<SizeOfList; i++)
	{
		// call the appropriate virtual print routine based
		// on the type of object being pointed to
		List[i]->print();
	}
	return 0;
}
