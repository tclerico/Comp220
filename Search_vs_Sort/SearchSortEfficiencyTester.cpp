//
// Created by Tim on 10/4/2017.
//

#include <iostream>
#include "ArrayLib.h"
#include <cstdlib>


void findCount(){
    std::cout<<"Array Size"<< "\t" << "Find" << std::endl;
    for(int i=1;i<=100;i++){
        int time = 0;
        int trash = 0;

        int* testarray = genRandArray(i,0,i,trash);

        int findTest = find(testarray,i,i+1,time);

        std::cout<< i << "\t" << time << std::endl;
        delete [] testarray;
    }

}

void sortTime(){
    std::cout<<"Array Size"<<"\t"<<"Sort"<<std::endl;
    for(int i=1;i<=100;i++){
        int time1 = 0;
        int trash = 0;

        int* testarray = genRandArray(i,0,i,trash);

        sort(testarray,i,time1);

        std::cout<< i << "\t" << time1 << std::endl;
        delete [] testarray;
    }

}

void binaryTime(){
    std::cout<<"Array Size"<<"\t"<<"Bin Search"<<std::endl;
    for(int i=1;i<=100;i++){
        int time2 = 0;
        int trash = 0;

        int* testarray = genRandArray(i,0,i,trash);
        sort(testarray,i,trash);

        int bintest = binFind(testarray,i,i+1,time2);

        std::cout<< i << "\t" << time2 << std::endl;
        delete [] testarray;
    }
}


void linearVsBinary(){
    std::cout<<"Array Size"<<"\t"<<"Linear(bubble)"<<"\t"<<"Binary"<<std::endl;
    int trash =0;
    int time = 0;
    int timeSort = 0;
    int time2 = 0;
    int size = 2000;

    int* test1arr = genRandArray(size,0,size,trash);
    int* test2arr = copyArray(test1arr,size,trash);
    sort(test2arr,size,timeSort);

    for(int i=0;i<5000;i++){
        int numtofind = genRandInt(0,size,trash);
        int findtest = find(test1arr,size,numtofind,time);
        int bintest = binFind(test2arr,size,numtofind,time2);
        std::cout<<i<<"\t"<<time<<"\t"<<time2+timeSort<<std::endl;
    }

    delete [] test1arr;
    delete [] test2arr;
    test1arr = nullptr;
    test2arr = nullptr;
}

void sortVsMerge(){
    std::cout<<"Array Size"<<"\t"<<"Bubble Sort"<<"\t"<<"Merge Sort"<<std::endl;
    int trash = 0;
    int time1=0;
    int time2=0;

    for(int x=0;x<1000;x++) {
        int *testArr1 = genRandArray(x, 0, x, trash);
        int *testArr2 = copyArray(testArr1, x, trash);

        sort(testArr1,x,time1);
        int* merge = mergeSort(testArr2,x,time2);

        std::cout<<x<<"\t"<<time1<<"\t"<<time2<<std::endl;
        delete [] testArr1;
        delete [] testArr2;
        delete [] merge;
    }


}

int main(){
    srand(time(NULL));
    //findCount();
    //sortTime();
    //binaryTime();
    //linearVsBinary();
    sortVsMerge();
}