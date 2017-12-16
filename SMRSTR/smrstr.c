/*
* Developer: Zoltan Kornel Torok, taz19880922@gmail.com
*
* This program developed for codechef SMRSTR problem (http://www.codechef.com/problems/SMRSTR).
*
*/
#include <stdio.h>
#include <math.h>

int main(){
        short numberOfTestCase;
        scanf("%hu",&numberOfTestCase);

        while (numberOfTestCase != 0) {
            unsigned int sizeOfArray = 0;
            unsigned int numberOfQueries = 0;
            unsigned long sumOfArray = 1;
            scanf("%u",&sizeOfArray);
            scanf("%u",&numberOfQueries);
            unsigned int i = 0;
            unsigned long tmp;
            while (sizeOfArray != 0) {
                scanf("%lu",&tmp);
                sumOfArray = sumOfArray * tmp;
                sizeOfArray--;
            }
            while (numberOfQueries != 0) {
                scanf("%lu",&tmp);
                //printf("%d", tmp );
                printf("%d ", tmp / sumOfArray);
                numberOfQueries--;
            }
            printf("\n");
            numberOfTestCase--;
        }

        return 0;
}
