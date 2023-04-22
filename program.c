#include <stdio.h>
#include <stdbool.h>

// Constants
#define NumberOfCourses 10
#define NumberOfUsers 4
#define MaxCourses 12

// User Arrays
char usernames[NumberOfUsers][20] = {"Dela Cruz", "Garcia", "Quitoriano", "Tamano"};
char passwords[NumberOfUsers][20] = {"Katrina Reigne", "Carlo Jezer", "Carissa Lois", "Faisal Richard"};
char user_details[NumberOfUsers][8][20] = {
    {"Dela Cruz", "Katrina Reigne", "Marfori", "BSCPE", "GCOE", "Manila", "123456789", "Manila"},
    {"Garcia", "Carlo Jezer", "Lacap", "BSCPE", "GCOE", "Manila", "987654321", "Manila"},
    {"Quitoriano", "Carissa Lois", "Legamia", "BSCPE", "GCOE", "Manila", "112233445", "Manila"},
    {"Tamano", "Faisal Richard Jr.", "Dianalan", "BSCPE", "GCOE", "Manila", "224466881", "Manila"}
}; // [user index][lastname, firstname, middlename, degree program, college, permanent address, permanent telephone no., present address]
char user_courses[NumberOfUsers][MaxCourses][10];

// Course Arrays
char courses[NumberOfCourses][10] = {"GEMATMW", "GERIZAL", "GESTSOC", "COEDISC", "CALENG1", "PROLOGI", "LBYCPA1", "LBYCPA1", "LBOEC2A", "LBOEC2A"};
char course_details[NumberOfCourses][5][11] = 
{
    {"LEC", "EQ1", "07:30-09:00", "Mon, Thu", "AG1702"}, 
    {"LEC", "EQ1", "09:15-10:45", "Mon, Thu", "AG1702"},
    {"LEC", "EQ1", "11:00-12:30", "Mon, Thu", "AG1702"},
    {"LEC", "EQ1", "13:15-14:15", "Mon, Thu", "AG1702"},
    {"LEC", "EQ1", "14:30-16:00", "Mon, Thu", "AG1702"},
    {"LEC", "EQ1", "16:15-17:15", "Mon, Thu", "AG1702"},
    {"LAB", "EQ1", "07:30-10:30", "Tue, Fri", "VL103"},
    {"LAB", "EQ2", "07:30-10:30", "Tue, Fri", "GK404B"},
    {"LAB", "EQ1", "11:00-14:00", "Tue, Fri", "ONLINE"},
    {"LAB", "EQ2", "11:00-14:00", "Tue, Fri", "ONLINE"}
}; // [course index][type, section, time, day, room]
int course_units[NumberOfCourses] = {3, 3, 3, 1, 3, 2, 2, 2, 2, 2};

// Login module
bool login(char *username, char *password)
{
}

// Display profile module
void display_student_profile(char *username)
{
}

// Course enrollment module
void course_enrollment()
{
}

// Fees module
void fees()
{
}

// Main module
void main()
{
}

