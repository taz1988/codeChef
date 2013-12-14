#include <stdlib.h>
#include <stdio.h>

unsigned int calculareArrayLength(int lengthOfB) {
    int length = lengthOfB / 16;
    if (lengthOfB % 16 > 0) {
        length += 1;
    }
    return length;
}

unsigned short* generateB (int lengthOfB) {

    int length = calculareArrayLength(lengthOfB);
    
    unsigned short* BArray = malloc(length*sizeof(unsigned short));
    int i = 0;
    int j = 1;
    int border = 1;
    BArray[0] = 27030;
    for (i = 2; i <= length; i = i*2) {
        for ( j = border; j < i; j++) {
            BArray[j] = ~BArray[j-border];
        }
        border = i;
    }
    if (border < length) {
        for ( j = border; j < length; j++) {
            BArray[j] = ~BArray[j-border];
        }
    }
    return BArray;
}


//this is for just printing
char* byte_to_binary(int x)
{
    //static char b[16];
    char* b = malloc(16 * sizeof(char));
    b[0] = '\0';

    int z;
    for (z = 32768; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

void byte_to_binary_file(FILE* file, int x){
    int z;
    for (z = 32768; z > 0; z >>= 1)
    {
        ((x & z) == z) ? fprintf(file, "1") : fprintf(file, "0");
    }
}
//printf("%s\n", byte_to_binary(baseArray[0]));
