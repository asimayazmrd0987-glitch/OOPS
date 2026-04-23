#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void printSet(const string &name, const set<int> &S)
{
    cout << name << " = { ";
    for (int x : S)
        cout << x << " ";
    cout << "}\n";
}

int main()
{
    set<int> U, A, B;
    int n, x;
    cout << "Enter size of Universal set U: like 3, 4,5...";
    cin >> n;
    cout << "Enter elements of U: like 1  2  3  4  6\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        U.insert(x);
    }
    cout << "Enter size of set A: ";
    cin >> n;
    cout << "Enter elements of A:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        A.insert(x);
    }
    cout << "Enter size of set B: ";
    cin >> n;
    cout << "Enter elements of B:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        B.insert(x);
    }

    set<int> uni, inter, diffAB, diffBA, compA;

    set_union(A.begin(), A.end(), B.begin(), B.end(), // here is A ∪ B
              inserter(uni, uni.begin()));

    set_intersection(A.begin(), A.end(), B.begin(), B.end(), // her is A ∩ B
                     inserter(inter, inter.begin()));

    set_difference(A.begin(), A.end(), B.begin(), B.end(), // here is A - B
                   inserter(diffAB, diffAB.begin()));

    set_difference(B.begin(), B.end(), A.begin(), A.end(), // here is B - A
                   inserter(diffBA, diffBA.begin()));

    set_difference(U.begin(), U.end(), A.begin(), A.end(), // here is Complement of A (with respect to U): U - A
                    inserter(compA, compA.begin()));

    cout << "\n--- Results ---\n";
    printSet("A ∪ B", uni);
    printSet("A ∩ B", inter);
    printSet("A - B", diffAB);
    printSet("B - A", diffBA);
    printSet("A' (complement of A)", compA);

    return 0;
}