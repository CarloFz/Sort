#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "../Include/SortAlgorithm.h"
using namespace Encore;

static void CreateData(int dataNum = 200)
{
    // 生成随机数种子
    srand((unsigned)time(NULL));

    std::ofstream ofs;
    ofs.open("SortData.txt", std::ios::out);
    for(int i = 0; i < dataNum; i++)
    {
        ofs << rand() << std::endl;
    }
    ofs.close();
}

static void GetSortData(std::vector<int>& array)
{
    array.clear();
    std::ifstream ifs;
    ifs.open("SortData.txt", std::ios::in);
    if(!ifs.good())
    {
        CreateData();
        ifs.open("SortData.txt", std::ios::in);
    }
    
    int num;
    while(ifs >> num)
    {
        array.push_back(num);
    }
    ifs.close();
}

static bool ComfirmOrderdData(std::vector<int> array)
{
    for(int i = 0; i < array.size() - 1; i++)
    {
        if (array[i + 1] < array[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::vector<int> array;
    GetSortData(array);

    // SortAlgorithm::BubbleSort(array);
    // SortAlgorithm::SelectSort(array);
    SortAlgorithm::InsertionSort(array);

    if (ComfirmOrderdData(array)){
        std::cout << "Finish" << std::endl;
    }else{
        std::cout << "Error" << std::endl;
    }
}
