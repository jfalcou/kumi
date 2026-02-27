/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <iostream>
#include <stdexcept>
#include <string>
#include <kumi/kumi.hpp>
 
kumi::tuple<double, char, std::string> get_student(int id)
{
    switch (id)
    {
        case 0: return {3.8, 'A', "Lisa Simpson"};
        case 1: return {2.9, 'C', "Milhouse Van Houten"};
        case 2: return {1.7, 'D', "Ralph Wiggum"};
        case 3: return {0.6, 'F', "Bart Simpson"};
    }
 
    throw std::invalid_argument("id");
}
 
int main()
{
    const auto student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: "    << kumi::get<0>(student0) << ", "
              << "grade: "  << kumi::get<1>(student0) << ", "
              << "name: "   << kumi::get<2>(student0) << '\n';
 
    const auto student1 = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: "    << kumi::get<double>(student1)      << ", "
              << "grade: "  << kumi::get<char>(student1)        << ", "
              << "name: "   << kumi::get<std::string>(student1) << '\n';
 
    double gpa2;
    char grade2;
    std::string name2;
    kumi::tie(gpa2, grade2, name2) = get_student(2);
    std::cout << "ID: 2, "
              << "GPA: "    << gpa2   << ", "
              << "grade: "  << grade2 << ", "
              << "name: "   << name2  << '\n';
 
    // C++17 structured binding:
    const auto [gpa3, grade3, name3] = get_student(3);
    std::cout << "ID: 3, "
              << "GPA: "    << gpa3   << ", "
              << "grade: "  << grade3 << ", "
              << "name: "   << name3  << '\n';
}
