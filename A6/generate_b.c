/*
* Developer: Zoltán Kornél Török, taz19880922@gmail.com
*
* This program developed for codechef A6 problem (http://www.codechef.com/problems/A6).
*
* gcc generate_b.c ../common/common.c utils.c
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "../common/common.h"





int main(){
    int length = 1000000000;
    startMeasureCPUTime("generateB()");
    unsigned short* BArray = generateB(length);
    stopMeasureCPUTime("generateB()");
    int i;
    //for (i = 0; i < calculareArrayLength(length); i++) {
    //    printf("%s", byte_to_binary(BArray[i]));
    //}
    printf("\n");
}
