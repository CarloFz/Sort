#include <iostream>
#include <fstream>
using namespace std;

static void CreateData(int dataNum = 200)
{
    ofstream ofs;
    ofs.open("SortData.txt", ios::out);
    for(int i = 0; i < dataNum; i++)
    {
        ofs << i << endl;
    }
    ofs.close();
    
    ifstream ifs;
    ifs.open("SortData.txt", ios::in);
    
    int d;
    while(ifs >> d)
    {
        cout << d << endl;
    }
    ifs.close();
}

int main(int argc, const char * argv[]) {
    CreateData();
}
