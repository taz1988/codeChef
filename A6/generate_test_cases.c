/*
*
* Developer: Zoltán Kornél Török, taz19880922@gmail.com
*
* This code is generate test Cases for the A6 problem.
*
* gcc generate_test_cases.c  ../common/common.c utils.c 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../common/common.h"

#define BARRAY_LENGTH 1000000000

FILE* testCase;
unsigned short* BArray;

void generateTestCases(int testCaseNumbers) {
    int i;
    int length = calculareArrayLength(BARRAY_LENGTH);
    for (i = 0; i < testCaseNumbers; i++) {
        int startPos = rand() % length;
        //printf("startPos=%d\n", startPos);
        int endPos = startPos + (rand() % (length - startPos));
	//printf("  endPos=%d\n", endPos);
        int bitNumbers = (endPos - startPos) * 16;
        if (bitNumbers == 0) {
           bitNumbers = 8;
        }
	fprintf(testCase, "%d\n", bitNumbers);
        int j;
        for (j = startPos; j <= endPos; j++) {
            //char binary = byte_to_binary(BArray[j]);
            //pintf("%s", binary);
            //fprintf(testCase, "%s", &binary);
            byte_to_binary_file(testCase, BArray[j]);
        }
        fprintf(testCase, "\n");
    }
}

int main(int argc, char* arg[]) {

    if (argc == 1) {
        printf("You have to give one argument, the test cases number!\n");
        return 0;
     }
   
   printf("Start generating %s test cases.\n", arg[1]);
   startMeasureCPUTime("Start generating test cases...");
   srand(time(NULL));
   testCase = fopen("testCase","w");
   fprintf(testCase, "%s\n", arg[1]);
   BArray = generateB(BARRAY_LENGTH);
   generateTestCases(atoi(arg[1]));
   fclose(testCase);
   stopMeasureCPUTime("Stop generating test cases.");
   return 0;
}
