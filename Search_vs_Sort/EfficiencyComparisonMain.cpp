#include <iostream>
#include "ArrayLib.h"
#include <cstdlib>

void compareFindAndFindLast(){
    //TODO
    std::cout<<"Array Size" << "\t" << "Find" << "\t" << "FindLast" << std::endl;
    for(int x=1;x<50;x++){
        int time1=0;
        int time2=0;
        int garb=0;
        int *teetyArray = genRandArray(x,0,x,&garb);

        int findTest = find(teetyArray,x,1,&time1);
        int findLastTest = findLast(teetyArray,x,1,&time2);

        std::cout << x << "\t" << time1 << "\t" << time2 << std::endl;

    }


}

void compareFindMaxIndexAndSort(){
    //TODO
    std::cout<<"Array Size" << "\t" << "FindMax" << "\t" << "Sort" << "\t" << std::endl;
    for(int x=1;x<50;x++){
        int time1=0;
        int time2=0;
        int garb=0;

        int* tittyArray = genRandArray(x,0,x,&garb);

        int findMaxTest = findMaxIndex(tittyArray,x,&time1);
        sort(tittyArray,x,&time2);

        std::cout<< x <<"\t"<< time1 << "\t" << time2 << std::endl;
    }


}


void compareGenRandArrayAndGenShuffledArray(){
    //TODO: the numbers in the for loop might need adjustment to make a nice graph
    std::cout << "Array Size" << "\t" << "RandArray" << "\t" << "ShuffArray" << std::endl;
    for (int i=1; i< 50; i+=2){
        int timer1 = 0;
        int timer2 = 0;

        int* testArray = genRandArray(i, 0, i, &timer1);
        int* testArray2 = genShuffledArray(i, &timer2);
        std::cout << i << "\t" << timer1 << "\t" << timer2 << std::endl;

        //TODO: ensure there are no memory leaks or dangling pointers.
    }
}
int main() {
    srand(time(NULL));
    compareGenRandArrayAndGenShuffledArray();
    compareFindAndFindLast();
    compareFindMaxIndexAndSort();
}
