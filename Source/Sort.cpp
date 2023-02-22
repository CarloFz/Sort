#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include "../Include/SortAlgorithm.h"
using namespace Encore;

static void CreateData(int dataNum = 100000)
{
    // 生成随机数种子
    srand((unsigned)time(NULL));

    std::ofstream ofs;
    ofs.open("../SortData.txt", std::ios::out);
    ofs << dataNum << std::endl;
    std::vector<int> array;
    for(int i = 0; i < dataNum; i++)
    {
        int value = rand();
        array.push_back(value);
        ofs << value << std::endl;
    }
    std::sort(array.begin(), array.end());
    for(int i = 0; i < dataNum; i++)
    {
        ofs << array[i] << std::endl;
    }
    ofs.close();
}

static int GetSortDataLen()
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
    ifs.close();
    return len;
}

static void GetSortData(int array[], int resultArray[], int len)
{
    std::ifstream ifs;
    ifs.open("../SortData.txt", std::ios::in);

    ifs >> len;
    for(int i = 0; i < len; i++)
        ifs >> array[i];

    for(int i = 0; i < len; i++)
        ifs >> resultArray[i];
    ifs.close();
}

static bool ConfirmOrderdData(int array[], int resultArray[], int len)
{
    for(int i = 0; i < len; i++)
    {
        if (array[i] != resultArray[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // CreateData();
    int len = GetSortDataLen();
    int array[len], resultArray[len];
    GetSortData(array, resultArray, len);

    clock_t start,end;
    start = clock();
    // SortAlgorithm::BubbleSort(array, len);
    // SortAlgorithm::SelectSort(array, len);
    // SortAlgorithm::InsertionSort(array, len); 
    // SortAlgorithm::HeapSort(array, len);
    // SortAlgorithm::MergeSort(array, len);
    // SortAlgorithm::MergeSort_Recursive(array, len);
    // SortAlgorithm::QuickSort(array, len);
    // SortAlgorithm::QuickSort_NonRecursive(array, len);
    SortAlgorithm::ShellSort(array, len);
    end = clock();

    if (ConfirmOrderdData(array, resultArray, len)){
        std::cout << "Finish in time: " << double(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
    }else{
        for(int i = 0; i < len; i++)
        {
            std::cout << array[i] << std::endl;
        }
        std::cout << "Error" << std::endl;
    }
}
