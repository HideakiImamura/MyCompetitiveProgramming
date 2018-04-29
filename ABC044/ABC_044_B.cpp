//
// Created by 今村秀明 on 2016/09/04.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s;
    int alphabet[26];
    int len, i;

    memset(alphabet, 0, (26 * sizeof(int)));
    s = (char *) malloc(100 * sizeof(char));
    scanf("%s", s);
    len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] == 'a') {
            alphabet[0]++;
        } else if (s[i] == 'b') {
            alphabet[1]++;
        } else if (s[i] == 'c') {
            alphabet[2]++;
        } else if (s[i] == 'd') {
            alphabet[3]++;
        } else if (s[i] == 'e') {
            alphabet[4]++;
        } else if (s[i] == 'f') {
            alphabet[5]++;
        } else if (s[i] == 'g') {
            alphabet[6]++;
        } else if (s[i] == 'h') {
            alphabet[7]++;
        } else if (s[i] == 'i') {
            alphabet[8]++;
        } else if (s[i] == 'j') {
            alphabet[9]++;
        } else if (s[i] == 'k') {
            alphabet[10]++;
        } else if (s[i] == 'l') {
            alphabet[11]++;
        } else if (s[i] == 'm') {
            alphabet[12]++;
        } else if (s[i] == 'n') {
            alphabet[13]++;
        } else if (s[i] == 'o') {
            alphabet[14]++;
        } else if (s[i] == 'p') {
            alphabet[15]++;
        } else if (s[i] == 'q') {
            alphabet[16]++;
        } else if (s[i] == 'r') {
            alphabet[17]++;
        } else if (s[i] == 's') {
            alphabet[18]++;
        } else if (s[i] == 't') {
            alphabet[19]++;
        } else if (s[i] == 'u') {
            alphabet[20]++;
        } else if (s[i] == 'v') {
            alphabet[21]++;
        } else if (s[i] == 'w') {
            alphabet[22]++;
        } else if (s[i] == 'x') {
            alphabet[23]++;
        } else if (s[i] == 'y') {
            alphabet[24]++;
        } else if (s[i] == 'z') {
            alphabet[25]++;
        }
    }
    i = 0;
    while (i < 26) {
        if (alphabet[i] % 2 == 1) break;
        i++;
    }
    if (i <= 25) {
        printf("No");
    } else {
        printf("Yes");
    }
    return 0;
}