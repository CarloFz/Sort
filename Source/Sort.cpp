#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "../Include/SortAlgorithm.h"
using namespace Encore;

static void CreateData(int dataNum = 100000)
{
    // 生成随机数种子
    srand((unsigned)time(NULL));

    std::ofstream ofs;
    ofs.open("../SortData.txt", std::ios::out);
    ofs << dataNum << std::endl;
    for(int i = 0; i < dataNum; i++)
    {
        ofs << rand() << std::endl;
    }
    ofs.close();
}

static int GetSortData(int* &array)
{
    std::ifstream ifs;
    ifs.open("../SortData.txt", std::ios::in);
    if(!ifs.good())
    {
        CreateData();
        ifs.open("../SortData.txt", std::ios::in);
    }

    int len;
    ifs >> len;
    array = new int[len];
    for(int i = 0; i < len; i++)
        ifs >> array[i];

    ifs.close();
    return len;
}

static bool ComfirmOrderdData(int array[], int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        if (array[i + 1] < array[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // CreateData();
    int* array;
    int len = GetSortData(array);

    clock_t start,end;
    start = clock();
    // SortAlgorithm::BubbleSort(array, len);
    // SortAlgorithm::SelectSort(array, len);
    // SortAlgorithm::InsertionSort(array, len); 
    // SortAlgorithm::HeapSort(array, len);
    // SortAlgorithm::MergeSort(array, len);
    // SortAlgorithm::MergeSort_Recursive(array, len);
    // SortAlgorithm::QuickSort(array, len);
    SortAlgorithm::QuickSort_NonRecursive(array, len);
    end = clock();

    if (ComfirmOrderdData(array, len)){
        std::cout << "Finish in time: " << double(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
    }else{
        for(int i = 0; i < len; i++)
        {
            std::cout << array[i] << std::endl;
        }
        std::cout << "Error" << std::endl;
    }

    delete[] array;
}
