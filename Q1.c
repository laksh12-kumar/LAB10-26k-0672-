#include <stdio.h>
int main(){
    FILE *fp;
    int itemNo, qty, stock;
    char name[20];
    float price, bill = 0;
    fp = fopen("items.txt", "wb");
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 1, "Rice", 250.00, 40);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 2, "Sugar", 160.00, 25);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 3, "Milk", 220.00, 30);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 4, "CookingOil", 560.00, 12);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 5, "Tea", 450.00, 18);
    fclose(fp);
    fp = fopen("items.txt", "r+b");
    while (1){
        printf("\nEnter item number (0 to stop): ");
        scanf("%d", &itemNo);
        if (itemNo == 0)
            break;
        printf("Enter quantity: ");
        scanf("%d", &qty);
        fseek(fp, (itemNo - 1) * 42, SEEK_SET);
        fscanf(fp, "%d %s %f %d",&itemNo, name, &price, &stock);
        if (stock >= qty){
            stock = stock - qty;
            bill = bill + (price * qty);
            fseek(fp, (itemNo - 1) * 42, SEEK_SET);
            fprintf(fp, "%-4d %-20s %9.2f %5d\n",
                    itemNo, name, price, stock);
            printf("Item added successfully!\n");
        }
        else{
            printf("Not enough stock!\n");
        }
    }
    printf("\nTotal Bill = %.2f\n", bill);
    fclose(fp);
    return 0;
}