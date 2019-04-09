#include <iostream>
#include <stdexcept>
#include <string>
#include "PhysicalNumber.h"

using std::cout, std::string;
using ariel::Unit, ariel::PhysicalNumber;

/*~Implamentation of PhysicalNumber class:~*/

//Constructor: input- the amount and the unit's amount
PhysicalNumber::PhysicalNumber(long double amount, Unit some_unit){
    _unit = some_unit;
    _amount = amount;
}


/*~Auxulary Methods:~*/

//Checks what type of unit the number is 
int PhysicalNumber::which_unit() const{
      int ans = 0;
      switch(_unit){
          case CM:  ans = 0; break;
          case M:   ans = 1; break;
          case KM:  ans = 2; break;
          case SEC: ans = 3; break;
          case MIN: ans = 4; break;
          case HOUR:ans = 5; break;
          case G:   ans = 6; break;
          case KG:  ans = 7; break;
          case TON: ans = 8; break;
      }//end switch
    return ans;
  }

//Checks whether the dimensions match 
bool ariel::equalsDimension(const PhysicalNumber& a ,const PhysicalNumber& b){
     int dimension_a = a.which_unit();
     int dimension_b = b.which_unit();
     if((dimension_a/3) != (dimension_b/3)){
 return false;
}
     else return true;
 }


//Auxiliary function for converting units     
long double PhysicalNumber::convert() const{
        long double convertUnit = 0;
        switch(_unit) {
            case CM:  convertUnit = 1.0; break;
            case M:   convertUnit = 100.0; break;
            case KM:  convertUnit = 100000.0; break;
            case SEC: convertUnit = 1.0; break;
            case MIN: convertUnit = 60.0; break;
            case HOUR:convertUnit = 3600.0; break;
            case G:   convertUnit = 1.0; break;
            case KG:  convertUnit = 1000.0; break;
            case TON: convertUnit = 1000000.0; break;
        }
    return convertUnit;
}


 /*~Overloading operators:~*/

//Addition operator:
PhysicalNumber ariel::operator+ (const PhysicalNumber& a, const PhysicalNumber& b) {
    if(!ariel::equalsDimension(a, b)){
        throw std::invalid_argument("error, the dimension is not equals.");
    } else{
        long double aUnit = a.convert();
        long double bInBasic = (b.convert() * b._amount);
	    long double bInAUnit = bInBasic/aUnit;
        long double newAmount = a._amount + bInAUnit;
        return PhysicalNumber(newAmount, a._unit);
    }
}

//Subtraction operator:
PhysicalNumber ariel::operator- (const PhysicalNumber& a, const PhysicalNumber& b) {
    if(!ariel::equalsDimension(a, b)){
        throw std::invalid_argument("error, the dimension is not equals");
    } else{
        long double aUnit = a.convert();
        long double bInBasic = (b.convert() * b._amount);
	    long double bInAUnit = bInBasic/aUnit;
        long double newAmount = a._amount - bInAUnit;
        return PhysicalNumber(newAmount, a._unit);
    }
}

//Shortcut function to add
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other){
    if(!ariel::equalsDimension(*this, other)){
        throw std::invalid_argument("error, the dimension is not equals.");
    } else{
        long double thisUnit = this->convert();
        long double otherInBasic = (other.convert() * other._amount);
	    long double otherInThisUnit = otherInBasic/thisUnit;
        this->_amount = _amount + otherInThisUnit;
        return *this;
    }
}

//Shortcut function to subtraction
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other){
    if(!ariel::equalsDimension(*this, other)){
        throw std::invalid_argument("error, the dimension is not equals.");
    } else{
        long double thisUnit = this->convert();
        long double otherInBasic = (other.convert() * other._amount);
	    long double otherInThisUnit = otherInBasic/thisUnit;
        this->_amount = _amount - otherInThisUnit;
        return *this;
    }
}

//Overloaded minus (-) operator
PhysicalNumber PhysicalNumber::operator- (){
    return PhysicalNumber((-1 * _amount) , _unit);
}

//Overloaded plus (+) operator
PhysicalNumber& PhysicalNumber::operator+ (){
    return *this;
}

//Equals operator:    
bool PhysicalNumber::operator== (const PhysicalNumber& other){
    if(!ariel::equalsDimension(*this, other)){
        throw std::invalid_argument("error, the dimension is not equals.");
    } else{
        long double thisUnit = this->convert();
        long double otherInBasic = other.convert() * other._amount;
	long double otherInThisUnit = otherInBasic/thisUnit;
        return (_amount == otherInThisUnit);
    }
}

//Greater operator:    
bool PhysicalNumber::operator> (const PhysicalNumber& other){
    if(!ariel::equalsDimension(*this, other)){
        throw std::invalid_argument("error, the dimension is not equals.");
    } else{
        long double thisUnit = this->convert();
        long double otherInBasic = other.convert() * other._amount;
	long double otherInThisUnit = otherInBasic/thisUnit;
        return (_amount > otherInThisUnit);
    }  
}

//Smaller then oerator:
bool PhysicalNumber::operator< (const PhysicalNumber& other){
    if(!ariel::equalsDimension(*this, other)){
        throw std::invalid_argument("error, the dimension is not equals and you're fired.");
    } else{
        long double thisUnit = this->convert();
        long double otherInBasic = other.convert() * other._amount;
	long double otherInThisUnit = otherInBasic/thisUnit;
        return (_amount < otherInThisUnit);
    }
}

//Greater then or equals operator: 
bool PhysicalNumber::operator>= (const PhysicalNumber& other){
   if(!ariel::equalsDimension(*this, other)){
        throw std::invalid_argument("error, the dimension is not equals.");
    } else{
        long double thisUnit = this->convert();
        long double otherInBasic = other.convert() * other._amount;
	long double otherInThisUnit = otherInBasic/thisUnit;
        return (_amount >= otherInThisUnit);
    } 
}

//Smaller then or equals operator: 
bool PhysicalNumber::operator<= (const PhysicalNumber& other){
   if(!ariel::equalsDimension(*this, other)){
        throw std::invalid_argument("error, the dimension is not equals.");
    } else{
        long double thisUnit = this->convert();
        long double otherInBasic = other.convert() * other._amount;
	long double otherInThisUnit = otherInBasic/thisUnit;
        return (_amount <= otherInThisUnit);
    } 
}

//Not equals operator:
bool PhysicalNumber::operator!= (const PhysicalNumber& other){
   if(!ariel::equalsDimension(*this, other)){
        throw std::invalid_argument("error, the dimension is not equals.");
    } else{
        long double thisUnit = this->convert();
        long double otherInBasic = other.convert() * other._amount;
	long double otherInThisUnit = otherInBasic/thisUnit;
        return (_amount != otherInThisUnit);
    } 
}
 
//Output operator
ostream& ariel::operator<<(ostream& os, const PhysicalNumber& num) {
    string type[9] = {"[cm]","[m]","[km]","[sec]","[min]","[hour]","[g]","[kg]","[ton]"};
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
