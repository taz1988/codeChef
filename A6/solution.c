/*
* Developer: Zoltán Kornél Török, taz19880922@gmail.com
*
* This program developed for codechef A6 problem (http://www.codechef.com/problems/A6).
*
*/
#include <stdio.h>

//This struct contains the sequences in a linked list
typedef struct sequence{
       unsigned char bit;
       struct sequence* next;
} sequence;


//Global variables
sequence* b;
sequence* bLastElement;
char validSequence;

//this function calculate the next element of the b infinitive sequence
sequence* createInversSequence(sequence* firstElement){
       
       
       if(firstElement==NULL){
                return NULL;
       }
       
       
       sequence*  subSequenceFirstElement=malloc(sizeof(sequence));
       subSequenceFirstElement->bit=!(firstElement->bit==1);
       subSequenceFirstElement->next=NULL;
       
        sequence* actual=firstElement->next;
        
        sequence*  subSequenceLastElement;
        
        if(actual!=NULL){
                subSequenceFirstElement->next=malloc(sizeof(sequence));
                subSequenceLastElement=subSequenceFirstElement->next;
                subSequenceLastElement->bit=!(actual->bit==1);
                subSequenceLastElement->next=NULL;
                actual=actual->next;
        }
        
        while(actual!=NULL){
                subSequenceLastElement->next=malloc(sizeof(sequence));
                subSequenceLastElement=subSequenceLastElement->next;
                subSequenceLastElement->bit=!(actual->bit==1);
                subSequenceLastElement->next=NULL;
                actual=actual->next;
        }
        
        return subSequenceFirstElement;
              
}


//this function print the elements of a sequence to the standard output
void printASequence(sequence* head){        
        sequence* actual=head;
        while(actual!=NULL){
                printf("%d ",actual->bit);
                actual=actual->next;
        }
        printf("\n");
}

void extendsB(){
        bLastElement->next=createInversSequence(b);  
        while(bLastElement->next!=NULL){
              bLastElement=bLastElement->next;
         }  
}

void searchPrefix(int* prefix,int prefixLength){
        if(validSequence==0){
        //first we check the prefix contain invalid prefix part
        int i;
        for(i=0; i+2<prefixLength+1; i++){
                if((prefix[i]==prefix[i+1] && prefix[i+1]==prefix[i+2])){
                        validSequence=1;
                        printf("-1 ");
                        return;
                }
        }
        
        //start to search the prefix position
        int bIndex=-1;
        char match=1;
        
        sequence* start=b;
        sequence* tmp=b;
        
        while(match!=0){
                match=0;
                bIndex++;
                tmp=start;
                for(i=0; i<prefixLength+1; i++){
                        if(tmp->bit!=prefix[i]){
                                if(start->next==NULL){
                                      extendsB();  
                                }
                                start=start->next;
                                match=1;
                                break;
                        }else{
                              if(tmp->next==NULL){
                                      extendsB();  
                                }
                                tmp=tmp->next;   
                        }
                }
                
        }
        
                printf("%d ",bIndex);
        
        }else{
                printf("-1 ");
        }
}

int main(){
        
        //----------- initialization part ----------------
        
        //The b variable contain the first element of the b sequence
        b=malloc(sizeof(sequence));
        b->bit=0;
        b->next=malloc(sizeof(sequence));
        b->next->bit=1;
        b->next->next=NULL;
        
        //The lastB variable point to the last element of the b sequence
        bLastElement=b->next;
        
        int i,j;
        
        for(i=0; i<8; i++){
            extendsB();
        }
        
        int totalTestCaseNumber;
        int testCaseSequenceLength;
        
        
        scanf("%d",&totalTestCaseNumber);
        
        for(i=0; i<totalTestCaseNumber; i++){
        scanf("%d",&testCaseSequenceLength);
        validSequence=0;

        int testSequence[testCaseSequenceLength];
        for(j=0; j<testCaseSequenceLength; j++){
              scanf("%d",testSequence+j);   
        }
        for(j=0; j<testCaseSequenceLength; j++){
                searchPrefix(testSequence,j);
        }
        
        }
        
//        printASequence(b);
        
        return 0;
}
