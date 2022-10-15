#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Gate
{
    protected:
    int type;
    public:
    virtual int Gate_type()
    {
        return type;
    }
    virtual void gate_info()=0;
    virtual int return_info()=0;
};
class Business_Gate:public Gate
{
public:
int good_money;
int good_number;
 int Gate_type()
    {
        return 1;
    }
void gate_info()
{
cin>>good_money;
cin>>good_number;
}
int return_info()
{
return good_money*good_number;
}
};
class Academic_Gate:public Gate
{
public:
int iq_question;
int Gate_type()
    {
        return 2;
    }
void gate_info()
{
cin>>iq_question;
}
int return_info()
{
return iq_question;
}
};
class Power_gate:public Gate
{
public:
int Power_lost;
int Gate_type()
    {
        return 3;
    }
void gate_info()
{
cin>>Power_lost;
}
int return_info()
{
return Power_lost;
}
};
int main() 
{
    int n,money,power,knowledge;
    cin>>n;
   Gate *G[100];
    for(int i=0;i<n;i++)
    {
         int type;
        cin>>type;
        if(type==1) 
            G[i]=new Business_Gate;   
        if(type==2)
            G[i]=new Academic_Gate;      
        if(type==3)
            G[i]=new Power_gate;
        G[i]->gate_info();
    }
    cin>>money>>knowledge>>power;
    int i=0;
    while(money>=0&&knowledge>=0&&power>=0&& i<n)
    {
        if (G[i]->Gate_type() == 1)
        {
            money -= G[i]->return_info();
            if (money < 0)
            {
                cout << "-1";
                break;
            }
        }
        if (G[i]->Gate_type() == 2)
        {
            if (knowledge < G[i]->return_info())
            {
                cout << "-1";
                break;
            }
        }
        if (G[i]->Gate_type() == 3)
        {
            power -= G[i]->return_info();
            if (power < 0)
            {
                cout << "-1";
                break;
            }
        }
        if(i==n-1)
        {
            cout << money << " " << knowledge << " " << power;
            break;
        }
        i++;     
    }
    
    return 0;
}
