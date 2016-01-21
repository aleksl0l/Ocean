#include "victims.h"

int& Victims::GetCountTime()
{
    return CountTime;
}

bool Victims::operator==(const Victims& v)
{
    if(GetX()==v.GetX() && GetY()==v.GetY())
        return true;
    return false;
}

//int Victims::find(Victims& v)
//{
//    int vic;
//    for(vic=0; vic<victims.size(); vic++)
//    {
//        victims[vic] == Victims(cord.x, cord.y);
//    }
//    return vic;
//}

Victims::~Victims()
{

}

