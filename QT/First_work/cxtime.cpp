#include "cxtime.h"

CXTime::CXTime(QObject *parent) : QObject(parent)
{

}


double CXTime::Value(){
    return this->Num;
}
