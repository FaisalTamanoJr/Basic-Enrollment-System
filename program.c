#include <stdio.h>
#include <stdbool.h>

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
void display_student_profile(char *username, char *lastname, char *firstname, char *middlename, char *degreeprogram, char *college, char *permanentaddress, int *permanenettelephone, char *presentaddress)
{
    printf("Academic and Personal Info:");
    printf("Last Name: %s\n", lastname);
    printf("First Name: %s\n", firstname);
    printf("Middle Name: %s\n", middlename);
    printf("Degree Program: %s\n", degreeprogram);
    printf("College: %s\n", college);
    printf("Permanent Address: %s\n", permanentaddress);
    printf("Permanent Telephone No: %d\n", permanenttelephone);
    printf("Present Address: %s\n", presentaddress);   
    
}

// Course enrollment module
void course_enrollment(char *username)
{
}

// Fees module
void fees(char *username)
{
    float totalFees = 0;
    int i, j, numUnits;
    bool found;

    printf("\n\nCourse Fees:\n");
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
                numUnits = 0;
                for (int k = 0; k < NumberOfCourses; k++)
                {
                    if (strcmp(user_courses[i][j], courses[k]) == 0)
                    {
                        found = true;
                        if (strcmp(course_details[k][0], "LAB") == 0)
                        {
                            numUnits += 2;
                            totalFees += 2500.00;
                        }
                        else
                        {
                            numUnits += 3;
                            totalFees += 1500.50;
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

    printf("\n\nTotal Fees: %.2f", totalFees);
}

// Main module
void main()
{
    char username[20], password[20];
    bool allowAccess = false;

    // Do not allow access to the program until the user inputs a valid username and password
    printf("Login\n");

    while (allowAccess = false)
    {
        printf("Input your username: ");
        gets(username);
        printf("Input your password: ");
        gets(password);
        allowAccess = login(username, password);
        if (allowAccess == false)
        {
            printf("error: incorrect login details\n");
        }
    }

    // Display student profile
    display_student_profile(username);

    // Enroll the student
    course_enrollment(username);

    // Calculate the student fees
    fees(username);
}
