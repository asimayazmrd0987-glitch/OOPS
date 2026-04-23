#include <iostream>
using namespace std;

int main()
{
    //   int grades;
    //   cout<<"How many grades :";cin>>grades;
    int n;
    int *grades = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Grades :" << i + 1 << endl;
        cin >> grades[i];
    }
    delete grades;
    grades = nullptr;
    return 0;
}
