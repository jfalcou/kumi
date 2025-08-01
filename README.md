<img src="https://jfalcou.github.io/kumi/logo.png" alt="KUMI Logo : s tack of triangles of variabel shades of purple" data-canonical-src="https://jfalcou.github.io/kumi/logo.png" align="left"  width="12%" height="12%" />

# KUMI - C++20 Compact Tuple Tools

## Summary

**KUMI** is a fancy C++20 implementation of a tuple-like class. It tries to be as close to
`std::tuple` as possible but also wants to compile faster, uses a better C++20 oriented interface,
and new features like:

  -  a fast to compile tuple implementation
  -  quality of life improvement over the standard tuple implementation
  -  algorithm on tuples

## A Short Example

[See it live on Compiler Explorer](https://godbolt.org/z/cWKd47sT9)

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <iostream>
#include <kumi/kumi.hpp>

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
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## Licence

This library is licensed under the [Boost Software License](https://opensource.org/licenses/BSL-1.0):

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ none
Copyright : KUMI Project Contributors

Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the
software and accompanying documentation covered by this license (the "Software") to use, reproduce,
display, distribute, execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to do so, all subject to the
following:

The copyright notices in the Software and this entire statement, including the above license grant,
this restriction and the following disclaimer, must be included in all copies of the Software, in
whole or in part, and all derivative works of the Software, unless such copies or derivative works
are solely in the form of machine-executable object code generated by a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND
NON-INFRINGEMENT. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE
BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
