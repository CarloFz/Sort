namespace Encore
{
    class SortAlgorithm
    {
    public:
        static void BubbleSort(int array[], int len);
        static void SelectSort(int array[], int len);
        static void InsertionSort(int array[], int len);
        static void HeapSort(int array[], int len);
        static void MergeSort(int array[], int len);
    private:
        static void Heapity(int array[], int heapSize, int index);
        static void HeapBuild(int array[], int len);
        static int Min(int value1, int value2);
        static void Swap(int* &value1, int* &value2);
        static void Swap(int &value1, int &value2);
    };
}
