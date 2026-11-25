#include <stdio.h>
void buildScores(int change[], int score[], int i, int n, int current){
    if (i == n)
        return;
    current = current + change[i];
    score[i] = current;
    buildScores(change, score, i + 1, n, current);
}
int countLow(int score[], int n){
    if (n == 0)
        return 0;
    if (score[n - 1] < 50)
        return 1 + countLow(score, n - 1);
    return countLow(score, n - 1);
}
void reverse(int arr[], int left, int right){
    if (left >= right)
        return;
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    reverse(arr, left + 1, right - 1);
}
int main(){
    int change[10];
    int score[10];
    int start, i, low;
    printf("Enter starting score: ");
    scanf("%d", &start);
    for (i = 0; i < 10; i++){
        printf("Enter daily change: ");
        scanf("%d", &change[i]);
    }
    buildScores(change, score, 0, 10, start);
    printf("\nDaily Scores: ");
    for (i = 0; i < 10; i++){
        printf("%d ", score[i]);
    }
    low = countLow(score, 10);
    printf("\nDays below 50: %d", low);
    reverse(score, 0, 9);
    printf("\nLatest First: ");
    for (i = 0; i < 10; i++){
        printf("%d ", score[i]);
    }
    return 0;
}