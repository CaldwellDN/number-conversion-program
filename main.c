#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


char * getInput() {
    char* buffer = malloc(sizeof(char) * 256);
    printf("Input: ");
    scanf("%s", buffer);
    return buffer;
}

void decimalToBinary(char* input) {
    int num = atoi(input);
    
    int i = 0, ans[50];
    while (num > 0) {
        ans[i] = num % 2;
        i++;
        num /= 2;
    }

    printf("Output: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", ans[j]);
    }
    printf("\n");

}

void binaryToDecimal(char* input) {

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

    printf("%d\n", ans);
}

void decimalToOctal(char* input) {
    int num = atoi(input);
    int mod, i = 0;
    char ans[50];
    while (num != 0) {
        mod = num % 8;
        num /= 8;
        ans[i] = mod + '0';
        i++;
    }

    for (int j = strlen(ans)-1; j >= 0; j--) {
        printf("%c", ans[j]);
    }
    printf("\n");
}

void octalToDecimal(char* input) {
    int len = strlen(input)-1;
    int ans = 0;

    int add = 0;
    for (int i = len; i >= 0; i--) {
        add = (input[i] - '0') * pow(8, len-i);
        ans = ans + add;
    }

    printf("%d\n", ans);

}

void hexToBinary(char* input) {
    long decimal = strtol(input, NULL, 16);

    int i = 0, ans[50];
    while (decimal > 0) {
        ans[i] = decimal % 2;
        i++;
        decimal /= 2;
    }

    printf("Output: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", ans[j]);
    }
    printf("\n");
}

void binaryToHex(char* input) {
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

    printf("%x\n", ans);
}

int main() {
    printf("Number Converter:\n");
    printf("(1) Decimal to Binary\n");
    printf("(2) Binary to Decimal\n");
    printf("(3) Decimal to Octal\n");
    printf("(4) Octal to Decimal\n");
    printf("(5) Hexadecimal to Binary\n");
    printf("(6) Binary to Hexadecimal\n\n");

    int choice;
    printf("Choice: ");
    scanf("%d", &choice);

    char* input = getInput();
    switch(choice) {
        case 1:
            decimalToBinary(input);
            break;
        case 2:
            binaryToDecimal(input);
            break;
        case 3:
            decimalToOctal(input);
            break;
        case 4:
            octalToDecimal(input);
            break;
        case 5:
            hexToBinary(input);
            break;
        case 6:
            binaryToHex(input);
            break;
        default:
            printf("Error: Invalid Choice\n");
            break;
    }

    free(input);
    return 0;
}

