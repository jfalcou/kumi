#error This file is for documentation only - DO NOT INCLUDE
/**

  @mainpage The C++20 Compact Tuple Tools

  <strong>KUMI</strong> is a fancy C++20 implementation of a tuple-like class. It tries to be as close to
  `std::tuple` as possible but also wants to compile faster, uses a better C++20 oriented interface,
  and new features like:

    -  A fast to compile tuple implementation
    -  Quality of life improvement over the standard tuple implementation
    -  A protocol to adapt user-defined type to act as tuples
    -  Algorithm on tuples
    -  Record type handling

  @section Examples

  @tab_begin

  @tab{Tuple}
    
    @code
    #include <iostream>
    #include <kumi/kumi.hpp>

    auto get_student(int id)
    {
            if (id == 0)  return kumi::make_tuple(3.8, 'A', "Lisa Simpson");
      else  if (id == 1)  return kumi::make_tuple(2.9, 'C', "Milhouse Van Houten");
      else  if (id == 2)  return kumi::make_tuple(1.7, 'D', "Ralph Wiggum");
      else                return kumi::make_tuple(0. , 'F', "Unknown");
    }

    int main()
    {
      auto student0 = get_student(0);

      std::cout << "ID: 0, "
                << "GPA:   " << kumi::get<0>(student0) << ", "
                << "grade: " << kumi::get<1>(student0) << ", "
                << "name:  " << kumi::get<2>(student0) << '\n';

      auto [ gpa1, grade1, name1 ] = get_student(1);
      std::cout << "ID: 1, "
                << "GPA: "   << gpa1   << ", "
                << "grade: " << grade1 << ", "
                << "name: "  << name1  << '\n';
      std::cout << "\n";

      auto all_students = kumi::make_tuple(get_student(0),get_student(1),get_student(2));

      kumi::for_each_index( [](auto i, auto const& m) {
                            std::cout << "Data #" << i << " : " << m << "\n";
                          }
                          , all_students
                          );
      std::cout << "\n";

      auto grades = kumi::get<0>(kumi::transpose(all_students));
      std::cout << grades << "\n";
    }
    @endcode

  @tab{Record}
  
    @code
    #include <iostream>
    #include <kumi/kumi.hpp>

    using namespace kumi::literals;
    auto get_student(int id)
    {
            if (id == 0)  return kumi::make_record("GPA"_id = 3.8, "grade"_id = 'A');
      else  if (id == 1)  return kumi::make_record("GPA"_id = 2.9, "grade"_id = 'C');
      else  if (id == 2)  return kumi::make_record("GPA"_id = 1.7, "grade"_id = 'D');
      else                return kumi::make_record("GPA"_id = 0. , "grade"_id = 'F');
    }

    int main()
    {
      auto student0 = get_student(0);

      std::cout << "ID: 0, "
                << "GPA:   "  << kumi::get<"GPA">(student0)   << ", "
                << "grade: "  << kumi::get<"grade">(student0) << '\n';

      auto [ gpa1, grade1 ] = get_student(1);
      std::cout << "ID: 1, "
                << gpa1   << ", "
                << grade1 << '\n';
      std::cout << "\n";

      auto all_students = kumi::make_record(
                          "Lisa Simpson"_id         = get_student(0),
                          "Milhouse Van Houten"_id  = get_student(1),
                          "Ralph Wiggum"_id         = get_student(2)
                          );

      kumi::for_each_field( [](auto name, auto const& m) {
                            std::cout << "Student: " << name << ", Data : " << m << "\n";
                          }
                          , all_students
                          );
      std::cout << "\n";
    }
    @endcode

  @tab_end

  # Licence

  This library is licensed under the [Boost Software License](https://opensource.org/licenses/BSL-1.0).
  The full license text is available on the @ref kumi_licence "Licence" page.

**/
