#include <stdio.h>
#include <string.h>
int countRepeat(char s[], int i){
    if (s[i] == '\0' || s[i] != s[0])
        return 0;
    return 1 + countRepeat(s, i + 1);
}
void compress(char s[], int i, char out[], int j){
    if (s[i] == '\0'){
        out[j] = '\0';
        return;
    }
    int count = 1;
    while (s[i] == s[i + count])
        count++;
    out[j] = s[i];
    out[j + 1] = count + '0';
    compress(s, i + count, out, j + 2);
}
void expand(char in[], int i, char out[], int j){
    if (in[i] == '\0'){
        out[j] = '\0';
        return;
    }
    int count = in[i + 1] - '0';
    for (int k = 0; k < count; k++){
        out[j] = in[i];
        j++;
    }
    expand(in, i + 2, out, j);
}
int main(){
    char s[100];
    char compressed[200];
    char expanded[200];
    printf("Enter a string: ");
    scanf("%99s", s);
    compress(s, 0, compressed, 0);
    expand(compressed, 0, expanded, 0);
    printf("\nOriginal: %s", s);
    printf("\nCompressed: %s", compressed);
    printf("\nExpanded: %s", expanded);
    if (strcmp(s, expanded) == 0)
        printf("\nMatch: Yes");
    else
        printf("\nMatch: No");
    return 0;
}