#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "Unit.h"

using namespace std;

namespace ariel{
    
    
    
    
    class PhysicalNumber{

       public:
       
       //for now public- later should be getters & setters
        Unit _unit;
        float _amount;
        
        // Constructor:
        PhysicalNumber(float amount, Unit some_unit);
        
        //Auxiliary functions
        const int which_unit();
        const float convert();


        //Operators
        PhysicalNumber& operator+=(const PhysicalNumber& other);
        PhysicalNumber& operator-=(const PhysicalNumber& other);
        PhysicalNumber& operator- ();
        PhysicalNumber& operator+ ();
        bool operator== (const PhysicalNumber& other);
        bool operator> (const PhysicalNumber& other);
        bool operator< (const PhysicalNumber& other);
        bool operator>= (const PhysicalNumber& other);
        bool operator<= (const PhysicalNumber& other);
        PhysicalNumber PhysicalNumber::operator++(int);
        PhysicalNumber PhysicalNumber::operator--(int);
        PhysicalNumber& PhysicalNumber::operator++();
        PhysicalNumber& PhysicalNumber::operator--();
        
        friend bool equals(const Unit& a ,const Unit& b);
        friend ostream& operator<< (ostream& os, const PhysicalNumber& num);
        friend istream& operator>> (istream& is, PhysicalNumber& num);
        friend PhysicalNumber operator+ (const PhysicalNumber& a, const PhysicalNumber& b);
        friend PhysicalNumber operator-(const PhysicalNumber& a, const PhysicalNumber& b);
        
    }; //end of PhysicalNumber
    
    //Friend operators
    bool equals(const Unit& a ,const Unit& b);
    ostream& operator<< (ostream& os, const PhysicalNumber& num);
    istream& operator>> (istream& is, PhysicalNumber& num);    
    PhysicalNumber operator+ (const PhysicalNumber& a, const PhysicalNumber& b);
    PhysicalNumber operator-(const PhysicalNumber& a, const PhysicalNumber& b);
    

}//end of namespace ariel
