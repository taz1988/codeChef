/*
* Developer: Zoltán Kornél Török, taz19880922@gmail.com
*
* This program developed for codechef A6 problem (http://www.codechef.com/problems/A6).
*
*/
#include <stdio.h>
#include <stdlib.h>


//this is for just printing
const char *byte_to_binary(int x)
{
    static char b[16];
    b[0] = '\0';

    int z;
    for (z = 32768; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

//This function job to create a base array, which is contain all possible 
// sequence part
unsigned short* createBaseArray(){
        char newBits[16];
        newBits[0]=1;
        newBits[1]=0;
        newBits[2]=0;
        newBits[3]=1;
        unsigned short* baseArray = malloc(33*sizeof(unsigned short));
        int i = 0;
        baseArray[0] = 27030;
        for(i = 4; i < 16; i=i+4){
                newBits[i]=newBits[i-4]==1?0:1;
                newBits[i+1]=newBits[i-3]==1?0:1;
                newBits[i+2]=newBits[i-2]==1?0:1;
                newBits[i+3]=newBits[i-1]==1?0:1;
        }
        //printf("%s\n", byte_to_binary(baseArray[0]));
        for(i = 1; i < 16; i++){
                baseArray[i] = (baseArray[i-1] << 1)+newBits[i-1];
              //  printf("%s\n", byte_to_binary(baseArray[i]));
        }
        
        for(i = 16; i < 33; i++){
                baseArray[i] = ~baseArray[i-16];
              //  printf("%s\n", byte_to_binary(baseArray[i]));
        }
        
        return baseArray;
}

// This function masking and shifting binary numbers
//we have to handle, when we have only a part of the sequence
unsigned short createShiftedValue(int baseValue, int prefixValue, int prefixLength){
        int submask = 0;
        int i;
        int newValue;
        for(i=0; i< (16-prefixLength); i++){
                submask = (submask << 1) + 1;
        }
        newValue = baseValue & submask;
        newValue += (prefixValue & ~submask);
        return newValue;
}

//This function search the index for a sequence part
char searchBaseValue(unsigned short* baseArray, unsigned short prefix, unsigned short prefixLength){
        char index = -1;
        int i;
        if(!prefixLength){
                for(i = 0; i < 33; i++){
                        if(prefix == baseArray[i]){
                                index = i;
                                break;
                        }
                }
        }else{
                for(i = 0; i < 33; i++){
                        if(createShiftedValue(baseArray[i] ,prefix, prefixLength) == baseArray[i]){
                                index = i;
                                break;
                        }
                }
        }
        return index;
}



int main(){

        //contains all possible sequence
        unsigned short* baseArray = createBaseArray();
        //index variables
        int i,j;
        
        //contain how many test case we have
        int totalTestCaseNumber;
        //contain a test case how many number contain
        int testCaseSequenceLength;
        
        //for reading and contain data
        unsigned short* prefixArray;
        int tmp;
        
        //other necesarry variables
        char prefixLength;
        char actualPrefixNotFullPartLength;
        char prefixLongerThanOneWord;
        char index=-1;
        char negal;
        
        scanf("%d",&totalTestCaseNumber);
        
        for(i=0; i<totalTestCaseNumber; i++){
               
               //################# reading part ####################
                scanf("%d",&testCaseSequenceLength);
                prefixArray = malloc((testCaseSequenceLength/16)*sizeof(unsigned short));
                for(j=0; j<testCaseSequenceLength; j++){
                         scanf("%d",&tmp);
                         prefixArray[(j/16)] = (prefixArray[(j/16)] << 1) + (tmp ? 1 : 0);
                }

                //if we have a part bit sequnce, than we shift the values the short number left part.
                if(testCaseSequenceLength%16){
                        prefixArray[(testCaseSequenceLength/16)] = prefixArray[(testCaseSequenceLength/16)] << 16-(testCaseSequenceLength%16);
                }
                
                index=0;
                //############## calculating index for all passible prefix#################
                for(prefixLength=0; prefixLength<testCaseSequenceLength; prefixLength++){
                        
                        if(index!=-1){
                                //there are more element the array, or only one?
                                prefixLongerThanOneWord = (prefixLength/16) < 1;
                                actualPrefixNotFullPartLength = ((prefixLength+1)%16);
                        
                                //if we have only 16 or less bit
                                index = searchBaseValue(baseArray, prefixArray[0], actualPrefixNotFullPartLength);
                       
                                //if we have more than 16 bit
                                if(!prefixLongerThanOneWord && index>-1){
                                                negal = 1;
						                        //check inner elements
                                                for(j=1; j<(prefixLength/16)-1 && index!=-1; j++){
                                                        if(negal){
                                                        	if((!baseArray[index])!=prefixArray[j]){
									                            index=-1;
								                            }
								                            negal=0;
							                            }else{
								                                if(baseArray[index]!=prefixArray[j]){
                                                                        index=-1;
                                                                }
                                                                negal=1;
							                               }
                                                }
                                                //check last element
                                                if(index>-1){   
                                                        if(negal){
                                                        	if((!createShiftedValue(baseArray[index] ,prefixArray[j], actualPrefixNotFullPartLength))!=prefixArray[j]){
									                            index=-1;
								                            }
								                            negal=0;
							                            }else{
								                                if(createShiftedValue(baseArray[index] ,prefixArray[j], actualPrefixNotFullPartLength)!=prefixArray[j]){
                                                                        index=-1;
                                                                }
                                                                negal=1;
							                               }
                                                }
                                }
                         }
                
                        //write tha answer
                        printf("%d ",index);
                }
                
                free(prefixArray);
        }
        
       free(baseArray);
        
        return 0;
}
