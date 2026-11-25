#include <stdio.h>
#include <string.h>
int main(){
    FILE *fp;
    int i, room, nights, rooms[10];
    int oldRoom, oldNights;
    char status, name[21], guest[21];
    char guests[10][21];
    float rate, bill;
    fp = fopen("hotel.txt", "wb");
    for (i = 0; i < 10; i++){
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n",101 + i, 'F', "-", 0, 8000.00);
    }
    fclose(fp);
    fp = fopen("hotel.txt", "rb+");
    printf("Enter room number: ");
    scanf("%d", &room);
    printf("Enter guest name: ");
    scanf("%20s", name);
    printf("Enter nights: ");
    scanf("%d", &nights);
    fseek(fp, (room - 101) * 39, SEEK_SET);
    fscanf(fp, "%d %c %20s %d %f",&oldRoom, &status, guest, &oldNights, &rate);
    if (status == 'F'){
        fseek(fp, (room - 101) * 39, SEEK_SET);
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n",room, 'B', name, nights, 8000.00);
        printf("\nRoom booked successfully!\n");
    }
    else{
        printf("\nRoom already booked!\n");
    }
    rewind(fp);
    for (i = 0; i < 10; i++){
        fscanf(fp, "%d %c %20s %d %f",&rooms[i], &status, guests[i], &oldNights, &rate);
        if (status == 'F')
            strcpy(guests[i], "");
    }
    printf("\nEnter guest name to search: ");
    scanf("%20s", name);
    for (i = 0; i < 10; i++){
        if (strcmp(name, guests[i]) == 0){
            printf("Guest found in room %d\n", rooms[i]);
            break;
        }
    }
    if (i == 10)
        printf("Guest not found!\n");
    printf("\nEnter room number for checkout: ");
    scanf("%d", &room);
    fseek(fp, (room - 101) * 39, SEEK_SET);
    fscanf(fp, "%d %c %20s %d %f",&oldRoom, &status, guest, &oldNights, &rate);
    if (status == 'B'){
        bill = oldNights * rate;
        printf("\nGuest: %s", guest);
        printf("\nTotal Bill: %.2f\n", bill);
        fseek(fp, (room - 101) * 39, SEEK_SET);
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n",room, 'F', "-", 0, 8000.00);
        printf("Checkout successful!\n");
    }
    else{
        printf("Room is already free!\n");
    }
    fclose(fp);
    return 0;
}