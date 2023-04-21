#include <stdio.h>

// Constants
#define NumberOfCourses 10
#define NumberOfUsers 4
#define MaxCourses 12

// User Arrays
char usernames[NumberOfUsers][20] = {};
char passwords[NumberOfUsers][20] = {};
char user_details[NumberOfUsers][8][20] = {};
char user_courses[NumberOfUsers][MaxCourses][10];

// Course Arrays
char courses[NumberOfCourses][10] = {};
char course_details[NumberOfCourses][5][10] = {}; // [course index][type, section, time, day, room]
int course_units[NumberOfCourses] = {};

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

