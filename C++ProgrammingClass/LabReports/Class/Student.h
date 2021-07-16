#include <string>
using namespace std;

class Student
{
public:
    string name;
    int IdNumber;
    double gpa;
    string major;
public:
    // constructors
    Student();  // default constructor
    Student(string n, int id, double g, string m);

    //mutators and accessors
    void setName(string n);
    string getName();
    void setIdNumber(int id);
    int  getIdNumber();
    void setGpa(double g);
    double getGpa();
    void setMajor(string m);
    string getMajor();
};