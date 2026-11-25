#include <stdio.h>
int main(){
    FILE *fp;
    char city[11];
    float temp, highest;
    int i, cityNo;
    fp = fopen("temperature.txt", "wb");
    for (i = 1; i <= 5; i++){
        printf("Enter city name: ");
        scanf("%10s", city);
        printf("Enter temperature: ");
        scanf("%f", &temp);
        fprintf(fp, "%-10s %5.1f\n", city, temp);
    }
    fclose(fp);
    fp = fopen("temperature.txt", "rb+");
    printf("\nEnter city number (1-5): ");
    scanf("%d", &cityNo);
    if (cityNo >= 1 && cityNo <= 5){
        fseek(fp, (cityNo - 1) * 17, SEEK_SET);
        fscanf(fp, "%10s %f", city, &temp);
        printf("\nCity: %s", city);
        printf("\nTemperature: %.1f\n", temp);
    }
    printf("\nEnter city number to update: ");
    scanf("%d", &cityNo);
    if (cityNo >= 1 && cityNo <= 5){
        printf("Enter correct temperature: ");
        scanf("%f", &temp);
        fseek(fp, (cityNo - 1) * 17, SEEK_SET);
        fscanf(fp, "%10s", city);
        fseek(fp, (cityNo - 1) * 17, SEEK_SET);
        fprintf(fp, "%-10s %5.1f\n", city, temp);
        printf("Temperature updated!\n");
    }
    rewind(fp);
    highest = -1000;
    for (i = 1; i <= 5; i++){
        fscanf(fp, "%10s %f", city, &temp);
        if (temp > highest){
            highest = temp;
        }
    }
    printf("\nHighest Temperature = %.1f\n", highest);
    fclose(fp);
    return 0;
}