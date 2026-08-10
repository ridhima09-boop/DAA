#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade;
};

int main() {
    struct Student s[100];
    int n, i, j, topper = 0;
    float classTotal = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        s[i].total = 0;

        printf("Enter marks of 5 subjects: ");
        for (j = 0; j < 5; j++) {
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5;
        classTotal += s[i].percentage;

        if (s[i].percentage > s[topper].percentage)
            topper = i;

        if (s[i].percentage >= 90)
            s[i].grade = 'A';
        else if (s[i].percentage >= 75)
            s[i].grade = 'B';
        else if (s[i].percentage >= 60)
            s[i].grade = 'C';
        else if (s[i].percentage >= 50)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';
    }

    printf("\n--- STUDENT RESULTS ---\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %.2f", s[i].total);
        printf("\nPercentage: %.2f", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }

    printf("\nClass Topper: %s", s[topper].name);
    printf("\nClass Average: %.2f\n", classTotal / n);

    printf("\nStudents who failed:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < 5; j++) {
            if (s[i].marks[j] < 40) {
                printf("%s\n", s[i].name);
                break;
            }
        }
    }

    return 0;
}
