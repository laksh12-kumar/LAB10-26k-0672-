#include <stdio.h>
int finalBalance(int trans[], int n, int balance){
    if (n == 0)
        return balance;
    balance = balance + trans[n - 1];
    return finalBalance(trans, n - 1, balance);
}
int totalDeposits(int trans[], int n){
    if (n == 0)
        return 0;
    if (trans[n - 1] > 0)
        return trans[n - 1] + totalDeposits(trans, n - 1);
    return totalDeposits(trans, n - 1);
}
int copyLarge(int trans[], int i, int n, int large[], int k){
    if (i == n)
        return k;
    if (trans[i] <= -10000){
        large[k] = trans[i];
        return copyLarge(trans, i + 1, n, large, k + 1);
    }
    return copyLarge(trans, i + 1, n, large, k);
}
int main(){
    int trans[7];
    int large[7];
    int balance, i, deposits, final, count;
    printf("Enter starting balance: ");
    scanf("%d", &balance);
    for (i = 0; i < 7; i++){
        printf("Enter transaction: ");
        scanf("%d", &trans[i]);
    }
    final = finalBalance(trans, 7, balance);
    deposits = totalDeposits(trans, 7);
    count = copyLarge(trans, 0, 7, large, 0);
    printf("\nFinal Balance = %d\n", final);
    printf("Total Deposits = %d\n", deposits);
    printf("\nLarge Withdrawals:\n");
    for (i = 0; i < count; i++){
        printf("%d\n", large[i]);
    }
    return 0;
}