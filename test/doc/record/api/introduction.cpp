/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <iostream>
#include <stdexcept>
#include <string>
#include <kumi/kumi.hpp>

using namespace kumi::literals;
auto get_student(int id)
{
  switch (id)
  {
    case 0: return kumi::record{"GPA"_id = 3.8, "grade"_id = 'A', "name"_id = std::string{"Lisa Simpson"}};
    case 1: return kumi::record{"GPA"_id = 2.9, "grade"_id = 'C', "name"_id = std::string{"Milhouse Van Houten"}};
    case 2: return kumi::record{"GPA"_id = 1.7, "grade"_id = 'D', "name"_id = std::string{"Ralph Wiggum"}};
    case 3: return kumi::record{"GPA"_id = 0.6, "grade"_id = 'F', "name"_id = std::string{"Bart Simpson"}};
  }

  throw std::invalid_argument("id");
}
 
int main()
{
    const auto student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: "    << kumi::get<"GPA">(student0)   << ", "
              << "grade: "  << kumi::get<"grade">(student0) << ", "
              << "name: "   << kumi::get<"name">(student0)  << '\n';
    
    const auto student1 = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: "    << kumi::get<double>(student1)      << ", "
              << "grade: "  << kumi::get<char>(student1)        << ", "
              << "name: "   << kumi::get<std::string>(student1) << '\n';
 
    double gpa2;
    char grade2;
    std::string name2;
    kumi::tie<"GPA"_id, "grade"_id, "name"_id>(gpa2, grade2, name2) = get_student(2);
    std::cout << "ID: 2, "
              << "GPA: "    << gpa2   << ", "
              << "grade: "  << grade2 << ", "
              << "name: "   << name2  << '\n';
 
    // C++17 structured binding:
    const auto [gpa3, grade3, name3] = get_student(3);
    std::cout << "ID: 3, "
              << gpa3     << ", "
              << grade3   << ", "
              << name3    << '\n';
}
