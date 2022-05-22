#error DO NOT INCLUDE - DOCUMENTATION PURPOSE ONLY

//==================================================================================================
//! \mainpage The C++20 Compact Tuple Tools
//!
//! **KUMI** is a fancy C++20 implementation of a tuple-like class. It tries to be as close to
//! `std::tuple` as possible but also wants to compile faster, uses a better C++20 oriented interface,
//! and new features like:
//!
//!   -  a fast to compile tuple implementation
//!   -  quality of life improvement over the standard tuple implementation
//!   -  a protocol to adapt user-defined type to act as tuples
//!   -  algorithm on tuples
//!
//! # A Short Example
//!
//! @code
//! #include <iostream>
//! #include <kumi/tuple.hpp>
//!
//! auto get_student(int id)
//! {
//!         if (id == 0)  return kumi::make_tuple(3.8, 'A', "Lisa Simpson");
//!   else  if (id == 1)  return kumi::make_tuple(2.9, 'C', "Milhouse Van Houten");
//!   else  if (id == 2)  return kumi::make_tuple(1.7, 'D', "Ralph Wiggum");
//!   else                return kumi::make_tuple(0., 'F', "Unknown");
//! }
//!
//! int main()
//! {
//!   auto student0 = get_student(0);
//!
//!   std::cout << "ID: 0, "
//!             << "GPA: "    << kumi::get<0>(student0) << ", "
//!             << "grade: "  << kumi::get<1>(student0) << ", "
//!             << "name: "   << kumi::get<2>(student0) << '\n';
//!
//!   auto [ gpa1, grade1, name1 ] = get_student(1);
//!   std::cout << "ID: 1, "
//!             << "GPA: " << gpa1 << ", "
//!             << "grade: " << grade1 << ", "
//!             << "name: " << name1 << '\n';
//!   std::cout << "\n";
//!
//!   auto all_students = kumi::make_tuple(get_student(0),get_student(1),get_student(2));
//!
//!   kumi::for_each_index( [](auto i, auto const& m) { std::cout << "Data #" << i << " : " << m << "\n";}
//!                       , all_students
//!                       );
//!   std::cout << "\n";
//!
//!   auto grades = kumi::get<0>(kumi::transpose(all_students));
//!   std::cout << grades << "\n";
//! }
//! @endcode
//!
//! # Licence
//!
//! This library is licensed under the [MIT License](http://opensource.org/licenses/MIT):
//!
//! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ none
//! Copyright : KUMI Contributors & Maintainers
//!
//! Permission is hereby granted, free of charge, to any person obtaining a copy of this software
//! and associated documentation files (the “Software”), to deal in the Software without restriction,
//! including without limitation the rights to use, copy, modify, merge, publish, distribute,
//! sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
//! furnished to do so, subject to the following conditions:
//!
//! The above copyright notice and this permission notice shall be included in all copies or substantial
//! portions of the Software.
//!
//! THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
//! NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//! IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//! LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//! CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//!
//==================================================================================================
