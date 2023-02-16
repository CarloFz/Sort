#include <vector>
namespace Encore
{
    class SortAlgorithm
    {
    public:
        static void BubbleSort(std::vector<int>& array);
        static void SelectSort(std::vector<int>& array);
        static void InsertionSort(std::vector<int>& array);
    };
}
