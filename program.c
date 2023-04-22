#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Constants
#define NumberOfCourses 10
#define NumberOfUsers 4
#define MaxCourses 12

// User Arrays
char usernames[NumberOfUsers][20] = {"Dela Cruz", "Garcia", "Quitoriano", "Tamano"};
char passwords[NumberOfUsers][20] = {"Katrina Reigne", "Carlo Jezer", "Carissa Lois", "Faisal Richard"};
char user_details[NumberOfUsers][8][20] =
{
    {"Dela Cruz", "Katrina Reigne", "Marfori", "BSCPE", "GCOE", "Manila", "123456789", "Manila"},
    {"Garcia", "Carlo Jezer", "Lacap", "BSCPE", "GCOE", "Manila", "987654321", "Manila"},
    {"Quitoriano", "Carissa Lois", "Legamia", "BSCPE", "GCOE", "Manila", "112233445", "Manila"},
    {"Tamano", "Faisal Richard Jr.", "Dianalan", "BSCPE", "GCOE", "Manila", "224466881", "Manila"}
}; // [user index][lastname, firstname, middlename, degree program, college, permanent address, permanent telephone no., present address]
char user_courses[NumberOfUsers][MaxCourses][10];
char user_courses_section[NumberOfUsers][MaxCourses][10];

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
    for (int i = 0; i < NumberOfUsers; i++)
    {
        if (strcmp(username, usernames[i]) == 0)
        {
            if (strcmp(password, passwords[i]) == 0)
            {
                return true;
            }
        }
    }
    return false;
}

// Display profile module
void display_student_profile(char *username)
{
    char lastname[20], firstname[20], middlename[20], degreeprogram[20], college[20], permAdd[20], permTel[20], presAdd[20];
    for (int i = 0; i < NumberOfUsers; i++)
    {
        if (strcmp(username, usernames[i]) == 0)
        {
            strcpy(lastname, user_details[i][0]);
            strcpy(firstname, user_details[i][1]);
            strcpy(middlename, user_details[i][2]);
            strcpy(degreeprogram, user_details[i][3]);
            strcpy(college, user_details[i][4]);
            strcpy(permAdd, user_details[i][5]);
            strcpy(permTel, user_details[i][6]);
            strcpy(presAdd, user_details[i][7]);
        }
    }
    printf("\n***************************\n");
    printf("Academic and Personal Info:\n\n");
    printf("Last Name: %s\n", lastname);
    printf("First Name: %s\n", firstname);
    printf("Middle Name: %s\n", middlename);
    printf("Degree Program: %s\n", degreeprogram);
    printf("College: %s\n", college);
    printf("Permanent Address: %s\n", permAdd);
    printf("Permanent Telephone No: %s\n", permTel);
    printf("Present Address: %s\n", presAdd);
}

// Course enrollment module
void course_enrollment(char *username)
{
    bool keepAsking = true;
    int userIndex;

    // Find the user index
    for (int i = 0; i < NumberOfUsers; i++)
    {
        if (strcmp(username, usernames[i]) == 0)
        {
            userIndex = i;
        }
    }

    // Display the list of courses and their corresponding section
    printf("\n************************************\n");
    printf("Available courses and their section:\n\n");
    for (int i = 0; i < NumberOfCourses; i++)
    {
        printf("%s - %s\n", courses[i], course_details[i][1]);
    }

    // Ask the user for courses to add
    int user_coursesIndex = 0;
    while (keepAsking == true)
    {
        int unitsSum = 0;
        char addCourse[10];
        char courseSection[11];
        
        // Compute for the sum of units
        for (int i = 0; i < MaxCourses; i++)
        {
            for (int j = 0; j < NumberOfCourses; j++)
            {
                if (strcmp(user_courses[userIndex][i], courses[j]) == 0 && strcmp(user_courses_section[userIndex][i], course_details[j][1]) == 0)
                {
                    unitsSum += course_units[j];
                }
            }
        }

        if (unitsSum >= 12)
        {
            printf("\nMaximum allowed number of courses reached\n");
            keepAsking = false;
            break;
        }

        // Add course
        printf("\nSelect a course to add using the course code: ");
        gets(addCourse);
        printf("From which section? ");
        gets(courseSection);
        for (int i = 0; i < NumberOfCourses; i++)
        {
            if (strcmp(addCourse, courses[i]) == 0 && strcmp(courseSection, course_details[i][1]) == 0) // If it is a valid course with a valid section
            {
                if ((unitsSum + course_units[i]) <= 12) // If adding the course would not exceed the maximum
                {
                    // if the schedules do not conflict
                    bool conflictingSchedule = false;

                    for (int j = 0; j < MaxCourses; j++)
                    {
                        char userCourseTime[11];
                        char userCourseDay[11];
                        for (int k = 0; k < NumberOfCourses; k++)
                        {
                            if (strcmp(user_courses[userIndex][j], courses[k]) == 0 && strcmp(user_courses_section[userIndex][j], course_details[k][1]) == 0)
                            {
                                strcpy(userCourseTime, course_details[k][2]);
                                strcpy(userCourseDay, course_details[k][3]);
                            }
                        }
                        if (strcmp(course_details[i][2], userCourseTime) == 0 && strcmp(course_details[i][3], userCourseDay) == 0)
                        {
                            conflictingSchedule = true;
                        }
                    }

                    if (conflictingSchedule == false)
                    {
                        strcpy(user_courses[userIndex][user_coursesIndex],  addCourse);
                        strcpy(user_courses_section[userIndex][user_coursesIndex],  courseSection);
                        user_coursesIndex += 1;
                        printf("+1 Course Added\n");
                    }
                }
            }
        }

        // Ask the user if they want to add more courses after passing the minimum
        if (unitsSum >= 6)  
        {
            char addMore[1];
            printf("Do you want to add more courses? [y/n]: ");
            gets(addMore);
            switch (strcmp(addMore, "n"))
            {
                case 0:
                    keepAsking = false;
                    break;
                default:
                    keepAsking = true;
            }
        }

    }
}

// Fees module
void fees(char *username)
{
    float totalFees = 0;
    int i, j, numUnits;
    bool found;

    printf("\n************\n");
    printf("Course Fees:\n");
    for (i = 0; i < NumberOfUsers; i++)
    {
        if (strcmp(usernames[i], username) == 0)
        {
            for (j = 0; j < MaxCourses; j++)
            {
                if (strlen(user_courses[i][j]) == 0)
                {
                    break;
                }
                found = false;
                for (int k = 0; k < NumberOfCourses; k++)
                {
                    if (strcmp(user_courses[i][j], courses[k]) == 0)
                    {
                        found = true;
                        if (strcmp(course_details[k][0], "LAB") == 0)
                        {
                            numUnits = course_units[k];
                            totalFees += numUnits * 2500.00;
                        }
                        else
                        {
                            numUnits = course_units[k];
                            totalFees += numUnits * 1500.50;
                        }
                        printf("%s - %.2f\n", user_courses[i][j], numUnits * ((strcmp(course_details[k][0], "LAB") == 0) ? 2500.00 : 1500.50));
                        break;
                    }
                }
                if (!found)
                {
                    printf("Invalid course: %s\n", user_courses[i][j]);
                }
            }
            break;
        }
    }

    // Add miscellaneous and ID validation fees
    printf("\nMiscellaneous - 813.00");
    totalFees += 813.00;
    printf("\nID Validation - 46.00");
    totalFees += 46.00;

    printf("\n\nTotal Fees: %.2f\n", totalFees);
}

// Main module
void main()
{
    char username[20], password[20];
    bool allowAccess = false;

    // Do not allow access to the program until the user inputs a valid username and password
    printf("Login\n");

    while (allowAccess != true)
    {
        printf("\nInput your username: ");
        gets(username);
        printf("Input your password: ");
        gets(password);
        allowAccess = login(username, password);
        if (allowAccess == false)
        {
            printf("\nerror: incorrect login details\n");
        }
    }

    // Display student profile
    display_student_profile(username);

    // Enroll the student
    course_enrollment(username);

    // Calculate the student fees
    fees(username);
}
