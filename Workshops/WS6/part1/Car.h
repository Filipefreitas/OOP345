/*
---------------------------------------------------------
Workshop 6 part 1
Filename: Car.h
Author:	Yuhuan Zhou
Student ID: 149528192
------------------------------------------------------------
Date 2020-11-03
 I have done all the coding by myself and only copied the
 code that my professor provided to complete my workshops
 and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include "Vehicle.h"

namespace sdds{
    class Car : public Vehicle {
        std::string _maker{};
        char _condition{};
        double _topSpeed{};
    public:
        Car() = default;
        explicit Car(std::istream& fin);
        [[nodiscard]] std::string condition() const override;
        [[nodiscard]] double topSpeed() const override;
        void display(std::ostream& out) const override;
        ~Car() override = default;
    };
}


#endif