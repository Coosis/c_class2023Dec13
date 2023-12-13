#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    //open and read file
    FILE *fp;
    fp = fopen("t3.txt", "r");

    char buffer[100];
    fgets(buffer, sizeof(buffer), fp);

    //calculating the offset
    double x, y;
    int cnt = 0;
    double offset = 0.0;
    while (fscanf(fp, "%lf %lf", &x, &y) == 2) {
        offset += (x-y);
        cnt++;
    }
    offset /= cnt;

    //output the average offset
    printf("%lf\n", offset);

    fclose(fp);
    return 0;
}