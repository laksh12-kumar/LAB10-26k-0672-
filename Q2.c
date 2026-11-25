#include <stdio.h>
int main(){
    FILE *fp;
    int roll, lectures, leave;
    char name[16];
    float percentage;
    fp = fopen("attendance.txt", "wb");
    fprintf(fp, "%-3d %-15s %3d\n", 1, "Ayesha", 18);
    fprintf(fp, "%-3d %-15s %3d\n", 2, "Bilal", 14);
    fprintf(fp, "%-3d %-15s %3d\n", 3, "Hamza", 20);
    fprintf(fp, "%-3d %-15s %3d\n", 4, "Sana", 12);
    fprintf(fp, "%-3d %-15s %3d\n", 5, "Zainab", 16);
    fclose(fp);
    fp = fopen("attendance.txt", "r+b");
    printf("Enter roll number(1-5): ");
    scanf("%d", &roll);
    fseek(fp, (roll - 1) * 24, SEEK_SET);
    fscanf(fp, "%d %s %d", &roll, name, &lectures);
    percentage = (lectures * 100) / 20;
    printf("\nName: %s", name);
    printf("\nAttendance: %.0f%%", percentage);
    if (percentage < 75)
        printf("\nShort Attendance");
    printf("\n\nEnter roll number(1-5): ");
    scanf("%d", &roll);
    printf("Enter leave lectures: ");
    scanf("%d", &leave);
    fseek(fp, (roll - 1) * 24, SEEK_SET);
    fscanf(fp, "%d %s %d", &roll, name, &lectures);
    lectures = lectures + leave;
    fseek(fp, (roll - 1) * 24, SEEK_SET);
    fprintf(fp, "%-3d %-15s %3d\n", roll, name, lectures);
    printf("\nAttendance updated!");
    fseek(fp, -24, SEEK_END);
    fscanf(fp, "%d %s %d", &roll, name, &lectures);
    printf("\n\nLast Student Record");
    printf("\nRoll Number: %d", roll);
    printf("\nName: %s", name);
    printf("\nLectures: %d\n", lectures);
    fclose(fp);
    return 0;
}