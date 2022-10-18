#include <iostream>
#include <kumi/tuple.hpp>

auto get_student(int id)
{
        if (id == 0)  return kumi::make_tuple(3.8, 'A', "Lisa Simpson");
  else  if (id == 1)  return kumi::make_tuple(2.9, 'C', "Milhouse Van Houten");
  else  if (id == 2)  return kumi::make_tuple(1.7, 'D', "Ralph Wiggum");
  else                return kumi::make_tuple(0., 'F', "Unknown");
}

int main()
{
  auto student0 = get_student(0);

  std::cout << "ID: 0, "
            << "GPA: "    << kumi::get<0>(student0) << ", "
            << "grade: "  << kumi::get<1>(student0) << ", "
            << "name: "   << kumi::get<2>(student0) << '\n';

  auto [ gpa1, grade1, name1 ] = get_student(1);
  std::cout << "ID: 1, "
            << "GPA: " << gpa1 << ", "
            << "grade: " << grade1 << ", "
            << "name: " << name1 << '\n';
  std::cout << "\n";

  auto all_students = kumi::make_tuple(get_student(0),get_student(1),get_student(2));

  kumi::for_each_index( [](auto i, auto const& m) { std::cout << "Data #" << i << " : " << m << "\n";}
                      , all_students
                      );
  std::cout << "\n";

  auto grades = kumi::get<0>(kumi::transpose(all_students));
  std::cout << grades << "\n";

  return 0;
}
