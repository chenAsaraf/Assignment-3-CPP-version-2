/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    //Student arguments for tests:
    //Length:
    PhysicalNumber cm1(1, Unit::CM);
    PhysicalNumber metere0_1(0.1, Unit::M);
    PhysicalNumber km100(100, Unit::KM);
    //Time:
    PhysicalNumber sec2(2, Unit::SEC);
    PhysicalNumber min50(50, Unit::MIN);
    PhysicalNumber min60(60, Unit::MIN);
    PhysicalNumber hour50(50, Unit::HOUR);
    PhysicalNumber hour1(1, Unit::HOUR);
    //Weight:
    PhysicalNumber gram999(999, Unit::G);
    PhysicalNumber kg19(19, Unit::KG);
    PhysicalNumber ton40(40, Unit::TON);
    
    
    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    
    //Student tests:
    /* += , -= Operators */
    .CHECK_OUTPUT((gram999 += kg19), "19999[g]")
    .CHECK_OUTPUT((kg19 += gram999), "38.999[kg]")
    .CHECK_OUTPUT((min50 -= hour50) , "-2950[min]")
    .CHECK_OUTPUT(min50 , "-2950[min]")
    .CHECK_OUTPUT((hour50 -= min50) , "99.1667[hour]") 
    .CHECK_OUTPUT((hour50 -= sec2) , "99.1661[hour]")
    /* - , + Unary operators */
    .CHECK_OUTPUT((+gram999), "19999[g]")
    .CHECK_OUTPUT((-kg19), "-38.999[kg]")
    .CHECK_OUTPUT((-kg19), "38.999[kg]")
    /* Equals, greater, smaller operators */
    .CHECK_EQUAL((min50++ == min50), false)//min50 now is -2949[min]
    .CHECK_EQUAL((min50==hour50), false) 
    .CHECK_EQUAL((kg19==kg19), true) 
    .CHECK_EQUAL((min60==hour1), true)

    .CHECK_EQUAL((kg19 < kg19), false)
    .CHECK_EQUAL((min60 < hour1), false)
    .CHECK_EQUAL((++ton40 > ton40), false) //ton40 now is 41[ton]
    .CHECK_EQUAL((ton40 > gram999), true) 

    .CHECK_EQUAL((kg19 <= kg19), true)
    .CHECK_EQUAL((-min50 >= hour50), false)
    .CHECK_EQUAL((gram999++ >= kg19), false)

    .CHECK_EQUAL((gram999 != kg19), true)
    .CHECK_EQUAL((min60 != hour1), false)

    /* Increament and decreament operators */
    .CHECK_OUTPUT(++min60 , "61[min]") 
    .CHECK_OUTPUT(min60 , "61[min]")
    .CHECK_OUTPUT(min60++ , "61[min]") //min60 now is 62[min]
    .CHECK_EQUAL(min60 , PhysicalNumber(62, Unit::MIN))
    .CHECK_EQUAL((min60-- == min60) , false) //min60 now is 61[min]
    .CHECK_EQUAL((--min60 == min60) , true) //min60 now is 60[min]

     /* Add, subtract operators in match dimensions */
     .CHECK_OUTPUT((min60-hour1), "0[min]")
     .CHECK_OUTPUT((hour1+min60), "2[hour]")
     .CHECK_OUTPUT((hour1+PhysicalNumber(66, Unit::MIN)), "2.1[hour]")

     .CHECK_OUTPUT((min60-=hour1), "0[min]")
     .CHECK_OUTPUT((hour1-min60), "1[hour]")
     .CHECK_OUTPUT((gram999 + ton40), "4.102e+07[g]")
     .CHECK_OUTPUT((ton40  + gram999), "41.02[ton]")
     .CHECK_OUTPUT((metere0_1  + km100), "100000.1[m]")
     .CHECK_OUTPUT((km100 - cm1), "100[km]")
     .CHECK_OUTPUT((cm1 += km100), "1e+07[cm]")
     .CHECK_OUTPUT((km100 - cm1), "-1e-05[km]")

     /* Unmatch dimensions */
    .CHECK_THROWS(min60 + gram999)
    .CHECK_THROWS(gram999 - min60)
    .CHECK_THROWS(km100 += gram999)
    .CHECK_THROWS(km100 -= hour1)
    .CHECK_THROWS(hour1 != cm1)
    .CHECK_THROWS(hour1 < cm1)
    .CHECK_THROWS(hour1 > (PhysicalNumber(66, Unit::KM)))
    .CHECK_THROWS(cm1 >= gram999)
    .CHECK_THROWS(cm1 <= gram999)
    .CHECK_THROWS(min60 == gram999)

     /* Input / output */
    .CHECK_OK(istringstream("400[ton]") >> a)
    .CHECK_OK(istringstream("0.1[km]") >> a)
    .CHECK_OK(istringstream("1000[cm]") >> a)

      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
} 
