#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Chai
{
    public:
    float Dien_tich_chai;
    float H20;
    virtual float Dien_tich()
    {
        Dien_tich_chai=0;
        return Dien_tich_chai;
    }
    virtual float H20_mat_dat()
    {
        H20=0;
        return H20;
    }
    virtual void Nhap()
    {
        cout<<"o";
    }
    
};
class Hinh_hop:public Chai
{
public:
float chieu_cao_2;
float chieu_rong;
float chieu_dai;

float Dien_tich()
{
Dien_tich_chai=2*chieu_cao_2*(chieu_rong+chieu_dai)+2*chieu_dai*chieu_rong;
return Dien_tich_chai;
}
float H20_mat_dat()
{
H20=float(10)/100*chieu_cao_2*chieu_dai*chieu_rong;
return H20;
}
void Nhap()
{
cin>> chieu_cao_2;
cin>> chieu_dai;
cin>> chieu_rong;
}
};
class Hinh_tru:public Chai
{
public:
float chieu_cao;
float bk_day;

float Dien_tich()
{
Dien_tich_chai=2*3.14*chieu_cao*bk_day;
return Dien_tich_chai;
}
float H20_mat_dat()
{
H20=float(10)/100*3.14*bk_day*bk_day*chieu_cao;
return H20;
}
void Nhap()
{
cin>> chieu_cao;
cin>>bk_day;
}
};
class Hinh_lp:public Chai
{
public:
float canh;

float Dien_tich()
{
Dien_tich_chai=6*canh*canh;
return Dien_tich_chai;
}
float H20_mat_dat()
{
H20=float(10)/100*canh*canh*canh;
return H20;
}
void Nhap()
{
cin>>canh;
}
};

int main() {
    float DTChai=0;
    float TTChai=0;
    int n;
    cin >> n;
    Chai* Chaicp[100];
    for (int i = 0; i < n; i++) {
        int loai;
        cin >> loai;
        if (loai == 1) 
        {
            Chaicp[i] = new Hinh_tru;
        }
        if (loai == 2) 
        {
            Chaicp[i] = new Hinh_hop;
        }
        if(loai==3)
        {
            Chaicp[i] = new Hinh_lp;
        }
        Chaicp[i]->Nhap();
    }
    for (int i = 0; i < n; i++) 
    {
        DTChai+=Chaicp[i]->Dien_tich();
        TTChai+=Chaicp[i]->H20_mat_dat();
    }
     
        cout<<"Dien tich chai vo: "<<DTChai<<endl;
        cout<<"Luong nuoc tren mat dat: "<<TTChai;
    return 0;
}
