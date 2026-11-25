#include <stdio.h>
void grow(int heights[], int n){
    if (n == 0)
        return;
    heights[n - 1] = heights[n - 1] +(int)(heights[n - 1] * 0.10);
    grow(heights, n - 1);
}
int tallest(int heights[], int n){
    if (n == 1)
        return 0;
    int pos = tallest(heights, n - 1);
    if (heights[n - 1] > heights[pos])
        return n - 1;
    return pos;
}
int search(int heights[], int n, int target){
    if (n == 0)
        return -1;
    if (heights[n - 1] == target)
        return n - 1;
    return search(heights, n - 1, target);
}
int main(){
    int ids[6], heights[6];
    int i, pos, target;
    for (i = 0; i < 6; i++){
        printf("Enter tower ID: ");
        scanf("%d", &ids[i]);
        printf("Enter tower height: ");
        scanf("%d", &heights[i]);
    }
    grow(heights, 6);
    printf("\nNew Tower Heights:\n");
    for (i = 0; i < 6; i++){
        printf("Tower %d = %d meters\n",ids[i], heights[i]);
    }
    pos = tallest(heights, 6);
    printf("\nTallest Tower: %d", ids[pos]);
    printf("\nHeight: %d meters\n", heights[pos]);
    printf("\nEnter height to search: ");
    scanf("%d", &target);
    pos = search(heights, 6, target);
    if (pos != -1)
        printf("Tower found: %d\n", ids[pos]);
    else
        printf("Tower not found!\n");
    return 0;
}