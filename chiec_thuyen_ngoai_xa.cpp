#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Boat
{
public:
    string name;
    int mem_number;
    virtual void In()
    {
        cin >> name;
        cin >> mem_number;
    }
    virtual void Out() = 0;
};
class Ghe : public Boat
{
    int check;
    void In()
    {
        Boat::In();
        cin >> check;
    }
    void Out()
    {
        if (check == 1)cout << name << " - Ghe - " << mem_number<<" thuyen vien" << " - Co Dong Co" << endl;
        if (check == 0)cout << name << " - Ghe - " << mem_number<<" thuyen vien" << endl;
    }
};
class Normal :public Boat
{
public:
    string Brand;
    void In()
    {
        Boat::In();
        cin >> Brand;
    }
    void Out()
    {
        cout << name << " - Thuyen thuong - " << mem_number<<" thuyen vien" << " - " << Brand << endl;
    }
};
class Big :public Boat
{
public:
    string brand;
    int range;
    void In()
    {
        Boat::In();
        cin >> brand;
        cin >> range;
    }

    void Out()
    {
        cout << name << " - Thuyen lon - " << mem_number <<" thuyen vien"<< " - " << brand << " - " << range <<"m" << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    Boat* B[100];
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)B[i] = new Ghe;
        if (type == 2)B[i] = new Normal;
        if (type == 3)B[i] = new Big;
        B[i]->In();
    }
    for (int i = 0; i < n; i++)
    {
        B[i]->Out();
    }
    return 0;
}
