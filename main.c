#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int binaryToDecimal(char* input) {
    int ans = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '1') {
            ans = ans * 2 + 1;
        } else if (input[i] == '0') {
            ans = ans * 2;
        } else {
            continue;
        }
    } 
    return ans;
}

int octalToDecimal(char* input) {
    int len = strlen(input)-1;
    int ans = 0;

    int add = 0;
    for (int i = len; i >= 0; i--) {
        add = (input[i] - '0') * pow(8, len-i);
        ans = ans + add;
    }
    return ans;
}

int* decimalToBinary(char* input) {
    int num = atoi(input);
    int i = 0;
    int* ans = (int*)malloc(50 * sizeof(int));
    while (num > 0) {
        ans[i] = num % 2;
        i++;
        num /= 2;
    }

    return ans;
}


int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error\n");
    } 

    // ./new -inputFlag *input* -outputFlag
    char* inputFlag = argv[1];
    char* input = argv[2];
    char* outputFlag = argv[3];

    int outputDecimal = 0;
    switch(inputFlag[1]) {
        case 'd':
            outputDecimal = atoi(input);
            break;
        case 'b':
            outputDecimal = binaryToDecimal(input);
            break;
        case 'o':
            outputDecimal = octalToDecimal(input);
            break;
        case 'x':
            outputDecimal = (int)strtol(input, NULL, 16);
            break;
        default:
            printf("Error: Invalid Input Flag\n");
            break;
    }

    printf("%d\n", outputDecimal);

    switch(outputFlag[1]) {
        case 'd':
            printf("%d\n", outputDecimal);
            break;
        case 'b':
            int i = 0, ans[50];
            while (outputDecimal > 0) {
                ans[i] = outputDecimal % 2;
                i++;
                outputDecimal = outputDecimal / 2;
            }
            for (int j = i - 1; j >= 0; j--) {
                printf("%d", ans[j]);
            }
            printf("\n");
            break;
        case 'o':
            printf("%o\n", outputDecimal);
            break;
        case 'x':
            printf("%x\n", outputDecimal);
            break;
        default:
            printf("Error: Invalid Output Flag \n");
            break;
    }

    return 0;
}