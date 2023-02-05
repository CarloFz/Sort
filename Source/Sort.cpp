#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "../Include/SortAlgorithm.h"
using namespace std;
using namespace Encore;

static void CreateData(int dataNum = 200)
{
    // 生成随机数种子
    srand((unsigned)time(NULL));

    ofstream ofs;
    ofs.open("SortData.txt", ios::out);
    for(int i = 0; i < dataNum; i++)
    {
        ofs << rand() << endl;
    }
    ofs.close();
}

static void GetSortData(vector<int>& array)
{
    array.clear();
    ifstream ifs;
    ifs.open("SortData.txt", ios::in);
    if(!ifs.good())
    {
        CreateData();
        ifs.open("SortData.txt", ios::in);
    }
    
    int num;
    while(ifs >> num)
    {
        array.push_back(num);
    }
    ifs.close();
}

static bool ComfirmOrderdData(vector<int> array)
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
    vector<int> array;
    GetSortData(array);

    // SortAlgorithm::BubbleSort(array);
    SortAlgorithm::SelectSort(array);

    if (ComfirmOrderdData(array)){
        cout << "Finish" << endl;
    }else{
        cout << "Error" << endl;
    }
}
