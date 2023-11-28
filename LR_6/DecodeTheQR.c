#include <string.h>
#include <stdlib.h>

int binaryToDecimal(char *str) {
    int num = atoi(str);
    int decimalValue = 0, base = 1, remainder;
    while (num > 0) {
        remainder = num % 10;
        decimalValue = decimalValue + remainder * base;
        num = num / 10;
        base = base * 2;
    }
    return decimalValue;
}


const char *scanner(int qrCode[21][21]) {
    int i, x, y = 0;
    char decodedString[500] = "";
    for(i=20; i >= 1;){
        if(i == 6){
            i = 5;
        }
        //printf("%s\n", decodedString);
        if(y < 0){
            for(y=0; y<=20; y++){
                for(x=i; x>=(i-1);x--) {
                    if (y <= 8 && x <= 8) {
                        continue;
                    }
                    if (y <= 8 && x >= 13) {
                        continue;
                    }
                    if (y >= 13 && x <= 8) {
                        continue;
                    }
                    if (x == 6) {
                        continue;
                    }
                    // Check if mask
                    if ((x+y)%2==0) {
                        if (qrCode[y][x]==1) {
                            strcat(decodedString, "0");
                        }
                        else {
                            strcat(decodedString, "1");
                        }
                    }
                    else {
                        if (qrCode[y][x]== 0) {
                            strcat(decodedString, "0");
                        } else {
                            strcat(decodedString, "1");
                        }
                    }
                }
            }
        }
        else{
            for(y=20; y>=0; y--){
                for(x=i; x>=(i-1); x--){
                    if (y <= 8 && x <= 8) {
                        continue;
                    }
                    if (y <= 8 && x >= 13) {
                        continue;
                    }
                    if (y >= 13 && x <= 8) {
                        continue;
                    }
                    if (x == 6) {
                        continue;
                    }
                    // Check if mask
                    if ((x+y)%2==0) {
                        if (qrCode[y][x]==1) {
                            strcat(decodedString, "0");
                        }
                        else {
                            strcat(decodedString, "1");
                        }
                    }
                    else {
                        if (qrCode[y][x]== 0) {
                            strcat(decodedString, "0");
                        } else {
                            strcat(decodedString, "1");
                        }
                    }
                }
            }
        }
        i-=2;
    }
    int c = 0;
    char length[10]="";
    i = 3;
    while (i < 12) {
        length[c]=decodedString[i];
        c++;
        i++;
    }
    length[c] = '\0';
    int length2 = binaryToDecimal(length);
    c = 0;
    int cc = 0;
    char buffer[10]="";
    static char result[10]="";
    for (int i = 12; i < 12+(length2*8); i++) {
        if (strlen(buffer) == 8) {
            int val = binaryToDecimal(buffer);
            result[c]=val;
            c++;
            memset(buffer, '\0', 10);
            cc = 0;
        }
        buffer[cc] = decodedString[i];
        buffer[cc+1] = '\0';
        cc++;
    }
    int val = binaryToDecimal(buffer);
    result[c]=val;
    result[c+1] = '\0';
    return result;
}