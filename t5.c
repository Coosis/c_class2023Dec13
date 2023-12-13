#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//element of key-value pair
struct KeyValuePair {
    char key[50];
    char value[50];
};

int main(void){
    struct KeyValuePair kvps[101];
    int cnt = 0;
    //open and read file
    FILE *fp;
    fp = fopen("t5.txt", "r");

    //read key-value pairs from file
    while (fscanf(fp, "%49[^=]=%49[^\n]", kvps[cnt].key, kvps[cnt].value) == 2) {
        cnt++;
        fgetc(fp);
    }

    //prompt user for input
    char inputKey[50];
    printf("Enter a key: ");
    scanf("%s", inputKey);

    //search for the input key and output the corresponding value
    int i;
    for (i = 0; i < cnt; i++) {
        if (strcmp(kvps[i].key, inputKey) == 0) {
            printf("Value: %s\n", kvps[i].value);
            break;
        }
    }

    fclose(fp);
    return 0;
}