#include <bits/stdc++.h>

using namespace std;


// class -> 1. variables 2. member functions

class Hero
{
    public:
        int y;
        char* name;
    
    Hero()
    {
        name = new char[100]; 
    }

    void setName(char name[])
    {
        strcpy(this->name,name);
    }

    void getName()
    {
        cout<<"name : "<<this->name<<endl;
    }

    void setY(int y)
    {
        this->y = y;
    }
    void showy()
    {
        cout<<"Value = "<<this->y<<endl;
    }
};

class M : public Hero 
{
    public:
        void setY(int val)
        {
            this->y = val;
        }

        void getY()
        {
            cout<<this->y<<endl;
        } 
};

// void Hero::makeZero() // defined outside class using scope resolution operator
// {
//     this->x = 0;
// }


int main()
{
    Hero alom;
    
    M m1;

    m1.y = 15;

    alom.setY(10);

    //m1.setY(5);
    m1.getY();

    
    alom.showy();

    // Hero hiralal;
    // Hero alom;

    // hiralal.x = 5;
    // alom.x = 8;

    // // alom.y = 7; private 

    // cout<<hiralal.x<<endl;
    // cout<<alom.x<<endl;
    // cout<<hiralal.x<<endl;

    // hiralal.putval(12);
    // hiralal.showx();
    // alom.putval(15);
    // alom.showx();
    // hiralal.showx();
    // hiralal.makeZero();
    // hiralal.showx();


    return 0;
}