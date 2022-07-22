#include <bits/stdc++.h>
using namespace std;
class Participant{
    private:
    int MM=0,SS=0;
    public:
    void time_taken(int m,int s){
        MM=m;
        SS=s;
    }
    Participant operator +(Participant &p){
        Participant temp;
        temp.MM = MM + p.MM;
        temp.SS = SS + p.SS;
        if(temp.SS>=60)
        {
            temp.SS-=60;
            temp.MM++;
        }
        return temp;
    }
    void dis()
    {
        cout<<"Total Time: "<<MM<<" Minutes "<<SS<<" Seconds"<<endl;
    }
};

int main(){
    Participant obj1,obj2,obj3,obj4,obj5;
    obj1.time_taken(2,56);
    obj2.time_taken(2,15);
    obj3.time_taken(2,43);
    obj4.time_taken(2,33);
    obj5 = obj5 + obj1;
    obj5 = obj5 + obj2;
    obj5 = obj5 + obj3;
    obj5 = obj5 + obj4;
    return 0;
}

