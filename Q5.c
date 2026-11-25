#include <stdio.h>
int main(){
    FILE *fp;
    char category[13];
    float amount, total = 0;
    int entry, i;
    fp = fopen("expenses.txt", "ab");
    printf("Enter category: ");
    scanf("%12s", category);
    printf("Enter amount: ");
    scanf("%f", &amount);
    fprintf(fp, "%-12s %9.2f\n", category, amount);
    fclose(fp);
    fp = fopen("expenses.txt", "rb+");
    fseek(fp, -2 * 23, SEEK_END);
    printf("\nLatest Two Expenses:\n");
    for (i = 0; i < 2; i++){
        fscanf(fp, "%12s %f", category, &amount);

        printf("%s  %.2f\n", category, amount);
    }
    printf("\nEnter entry number to update: ");
    scanf("%d", &entry);
    printf("Enter correct amount: ");
    scanf("%f", &amount);
    fseek(fp, (entry - 1) * 23, SEEK_SET);
    fscanf(fp, "%12s", category);
    fseek(fp, (entry - 1) * 23, SEEK_SET);
    fprintf(fp, "%-12s %9.2f\n", category, amount);
    printf("Expense updated!\n");
    rewind(fp);
    total = 0;
    printf("\nAll Expenses:\n");
    for (i = 0; i < 5; i++){
        fscanf(fp, "%12s %f", category, &amount);
        printf("%s  %.2f\n", category, amount);
        total = total + amount;
    }
    printf("\nTotal Expenses = %.2f\n", total);
    fclose(fp);
    return 0;
}