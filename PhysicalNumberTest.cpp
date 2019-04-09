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
    
    PhysicalNumber e(100, Unit::KM);
    PhysicalNumber f(999, Unit::M);
    PhysicalNumber g(5, Unit::HOUR);
    PhysicalNumber h(50, Unit::MIN);
    
    PhysicalNumber i(22, Unit::KM);
    PhysicalNumber j(395, Unit::M);
    PhysicalNumber k(16, Unit::HOUR);
    PhysicalNumber l(17, Unit::MIN);

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

    .setname("Compatible dimensions2.0")
    .CHECK_OUTPUT(j+i, "22395[m]")
    .CHECK_OUTPUT((i+=j), "22.395[km]")
    .CHECK_OUTPUT(i, "22.395[km]")
    .CHECK_OUTPUT(i+i, "44.79[km]")
    .CHECK_OUTPUT(j-j, "0[m]")
    .CHECK_OUTPUT(k, "16[hour]")
    .CHECK_OUTPUT(l, "17[min]")
    .CHECK_OUTPUT(l+k, "977[min]")

    .setname("Compatible dimensions3.0")
    .CHECK_OUTPUT(f+e, "100999[m]")
    .CHECK_OUTPUT((e+=f), "100.999[km]")
    .CHECK_OUTPUT(e, "100.999[km]")
    .CHECK_OUTPUT(e+e, "201.998[km]")
    .CHECK_OUTPUT(f-f, "0[m]")
    .CHECK_OUTPUT(g, "5[hour]")
    .CHECK_OUTPUT(h, "50[min]")
    .CHECK_OUTPUT(g-h, "-4.16667[hour]")

    .setname("Incompatible dimensions2.0")
    .CHECK_THROWS(f+g)
    .CHECK_THROWS(e+g)
    .CHECK_THROWS(e-h)
    .CHECK_THROWS(f+h)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")


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
