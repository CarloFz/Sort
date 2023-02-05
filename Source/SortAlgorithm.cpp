#include <vector>
#include "../Include/SortAlgorithm.h"
using namespace std;
namespace Encore
{
    void SortAlgorithm::BubbleSort(vector<int>& array)
    {
        int size = array.size();
        for(int i = 0; i < size - 1; i++){ // loop n-1 times
            for(int j = 0; j < size - i - 1; j++){ // compare elements(top i elements are ordered)
                if(array[j] > array[j + 1]){
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
}