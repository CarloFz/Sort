#include <vector>
namespace Encore
{
    class SortAlgorithm
    {
    public:
        static void BubbleSort(std::vector<int>& array);
        static void SelectSort(std::vector<int>& array);
        static void InsertionSort(std::vector<int>& array);
        static void HeapSort(std::vector<int>& array);
        static void MergeSort(int array[], int len);
    private:
        static void Heapity(std::vector<int>& array, int heapSize, int index);
        static void HeapBuild(std::vector<int>& array);
        static int Min(int value1, int value2);
        static void Swap(int* &value1, int* &value2);
    };
}
