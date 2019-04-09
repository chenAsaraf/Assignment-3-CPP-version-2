#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "PhysicalNumber.h"

using namespace std::cout, std::string;
using ariel::Unit, ariel::PhysicalNumber, ariel::conversion;

//Checks what type of unit the number is 
const int PhysicalNumber::which_unit(){
      int ans = 0;
      switch(u){
          case CM: {
              ans = 1;
              break;
          }
          case M: {
              ans = 2;
              break;
          }
          case KM: {
              ans = 3;
              break;
          }
          case SEC: {
              ans = 4;
              break;
          }
          case MIN: {
              ans = 5;
              break;
          }
          case HOUR: {
              ans = 6;
              break;
          }
          case G: {
              ans = 7;
              break;
          }
          case KG: {
              ans = 8;
              break;
          }
          case TON: {
              ans = 9;
              break;
          }
      }//end switch
      return ans;
  }
 
//  //Checks whether the dimensions match 
// friend bool Unit::equals(const Unit& a ,const Unit& b){
//      int dimension_a = a.which_unit();
//      int dimension_b = b.which_unit();
//      if((dimension_a/3) != (dimension_b/3)) return false;
//      else return true;
//  }
        
// Constructor:
PhysicalNumber::PhysicalNumber(float amount, Unit some_unit){
    _unit = some_unit;
    _amount = amount;
}

//Auxiliary function for converting units     
const float PhysicalNumber::convert(){
        float convertUnit = 0;
        switch(_unit) {
            case CM: {
                convertUnit = 1;
                break;
            }
            case M: {
                convertUnit = 100;
                break;
            }
            case KM: {
                convertUnit = 100000;
                break;
            }
            case SEC: {
                convertUnit = 1;
                break;
            }
            case MIN: {
                convertUnit = 60;
                break;
            }
            case HOUR: {
                convertUnit = 3600;
                break;
            }
            case G: {
                convertUnit = 1;
                break;
            }
            case KG: {
                convertUnit = 100;
                break;
            }
            case TON: {
                convertUnit = 1000000;
                break;
            }
        return convertUnit;
    }



//Addition operator:
friend PhysicalNumber ariel::operator+ (const PhysicalNumber& a, const PhysicalNumber& b) {
    if(!equals(a._unit, b._unit)){
        cout << "exception cout" << endl;
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    } else{
        float aUnit = a.convert();
        float aInBasic = aUnit * a._amount;
        float bInBasic = b.convert() * b._amount;
        float newAmount = (aInBasic + bInBasic)/ aUnit;
        return PhysicalNumber(newAmount, a._unit);
    }
}

//Subtraction operator:
friend PhysicalNumber ariel::operator- (const PhysicalNumber& a, const PhysicalNumber& b) {
    if(!equals(a._unit, b._unit)){
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    } else{
        float aUnit = a.convert();
        float aInBasic = aUnit * a._amount;
        float bInBasic = b.convert() * b._amount;
        float newAmount = (aInBasic - bInBasic)/ aUnit;
        return PhysicalNumber(newAmount, a._unit);
    }
}

//Shortcut function to add
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other){
    if(!equals(this->_unit, other._unit)){
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    } else{
        float thisUnit = this->convert();
        float thisInBasic = thisUnit * this->_amount;
        float otherInBasic = other.convert() * other._amount;
        this->_amount = (thisInBasic + thisInBasic)/ thisUnit;
        return *this;
    }
}

//Shortcut function to subtraction
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other){
    if(!equals(this->_unit, other._unit)){
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    } else{
        float thisUnit = this->convert();
        float thisInBasic = thisUnit * this->_amount;
        float otherInBasic = other.convert() * other._amount;
        this->_amount = (thisInBasic - thisInBasic)/ thisUnit;
        return *this;
    }
}

//Overloaded minus (-) operator
PhysicalNumber& PhysicalNumber::operator- (){
    _amount = -1 * _amount;
    return *this;
}

//Overloaded plus (+) operator
PhysicalNumber& PhysicalNumber::operator+ (){
    return *this;
}

//Equals operator:    
bool PhysicalNumber::operator== (const PhysicalNumber& other){
    if(!equals(this->_unit, other._unit)){
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    } else{
        float thisUnit = this->convert();
        float thisInBasic = thisUnit * this->_amount;
        float otherInBasic = other.convert() * other._amount;
        return (thisInBasic == otherInBasic);
    }
}

//Greater operator:    
bool PhysicalNumber::operator> (const PhysicalNumber& other){
    if(!equals(this->_unit, other._unit)){
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    } else{
        float thisUnit = this->convert();
        float thisInBasic = thisUnit * this->_amount;
        float otherInBasic = other.convert() * other._amount;
        return (thisInBasic > otherInBasic);
    }  
}

//Smaller then oerator:
bool PhysicalNumber::operator< (const PhysicalNumber& b){
    if(!equals(this->_unit, other._unit)){
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    } else{
        float thisUnit = this->convert();
        float thisInBasic = thisUnit * this->_amount;
        float otherInBasic = other.convert() * other._amount;
        return (thisInBasic < otherInBasic);
    }
}

//Greater then or equals operator: 
bool PhysicalNumber::operator>= (const PhysicalNumber& other){
   if(!equals(this->_unit, other._unit)){
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    } else{
        float thisUnit = this->convert();
        float thisInBasic = thisUnit * this->_amount;
        float otherInBasic = other.convert() * other._amount;
        return (thisInBasic >= otherInBasic);
    } 
}

//Smaller then or equals operator: 
bool PhysicalNumber::operator<= (const PhysicalNumber& b){
   if(!equals(this->_unit, other._unit)){
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    } else{
        float thisUnit = this->convert();
        float thisInBasic = thisUnit * this->_amount;
        float otherInBasic = other.convert() * other._amount;
        return (thisInBasic <= otherInBasic);
    } 
}

//Not equals operator:
bool PhysicalNumber::operator!= (const PhysicalNumber& other){
   if(!equals(this->_unit, other._unit)){
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    } else{
        float thisUnit = this->convert();
        float thisInBasic = thisUnit * this->_amount;
        float otherInBasic = other.convert() * other._amount;
        return (thisInBasic != otherInBasic);
    } 
}
 
//Output operator
ostream& ariel::operator<<(ostream& os, const PhysicalNumber& num) {
    string type[9] = {"[cm]","[m]","[km]","[sec]","[min]","[hour]","[g]","[kg]","[ton]"};
    // string printUnit;
    // switch(num._unit){
    //     case Unit::KM: { printUnit = "[km]"; break;}
    //     case Unit::M: { printUnit = "[m]"; break}
    //     case Unit::CM: { printUnit = "[cm]"; break;}
    //     case Unit::SEC: { printUnit = "[sec]"; break; }
    //     case Unit::HOUR: { printUnit = "[hour]"; break; }
    //     case Unit::G: { printUnit = "[g]"; break; }
    //     case Unit::KG: { printUnit = "[kg]"; break; }
    //     case Unit::TON: { printUnit = "[ton]"; break; }
    // } return os << num.amount << '[' << printUnit << ']';
    return os<<num._amount<<type[int(num._unit)];
}


//Input operator, example: istringstream input("700[kg]"); input >> a;
istream& ariel::operator>> (istream& is, PhysicalNumber& num){
   string helper;
   string type[9] = {"[cm]","[m]","[km]","[sec]","[min]","[hour]","[g]","[kg]","[ton]"};
   if (!(is>>num._amount)) throw std::runtime_error("the input is not valid");
   else is>>helper;
   int i = 0;
   bool b = false;
   while (i<9) {
       i++;
       if(helper.compare(type[i])==0)
       {
           num._unit=Unit(i);
           i = 9;
           b = true;
       }
   }
   if(!b) throw runtime_error("the input is not valid");
   return is;
}


//Postfix increment operator: 
PhysicalNumber PhysicalNumber::operator++(int){
    PhysicalNumber a(_amount , _unit);
    _amount= _amount+1;
    return a;
}

//Postfix decrement operator:
PhysicalNumber PhysicalNumber::operator--(int){
    PhysicalNumber a(_amount , _unit);
    _amount= _amount-1;
    return a;
}

//Prefix increment operator: 
PhysicalNumber& PhysicalNumber::operator++(){
    _amount = _amount + 1;
    return *this;
}

//Prefix decrement operator:
PhysicalNumber& PhysicalNumber::operator--(){
   _amount = _amount - 1;
    return *this;
}
