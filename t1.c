#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    //open file
    FILE *source, *destination;
    source = fopen("t1.txt", "rb");
    destination = fopen("t2_copy.txt", "wb");

    char buffer[1024];
    size_t bytesRead;

    //reading from source and writing to destination
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    //close files
    fclose(source);
    fclose(destination);
    return 0;
}