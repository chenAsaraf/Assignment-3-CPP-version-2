#pragma once
#include <iostream>

namespace ariel{
    enum Unit: int{
        //Length
        CM, //Kilometer=0 By deafult
        M, //Meter=1
        KM, //=2
        //Time
        SEC, //=3
        MIN, //=4
        HOUR, //=5
        //Weight
        G, //=6
        KG, //=7
        TON //=8
    }; //end Unit
    
 //Checks whether the dimensions match 
bool equals(const Unit& a ,const Unit& b);
    
} //end namespace ariel
