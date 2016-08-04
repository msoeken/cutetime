// == cutetime ========
// A happy time display
// --------------------

// The MIT License (MIT)
// Copyright (c) 2016 Mathias Soeken

// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:

// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#include <array>
#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

enum animals {
  timmy, monkey, bear, panda, dog, bunny, koala, mouse, pig, cow
};

std::array<std::string, 5> get_digit( unsigned digit, const std::string& c )
{
  switch ( digit )
  {
  case 0:
    return {c + " " + c + " " + c, c + "   " + c, c + "   " + c, c + "   " + c, c + " " + c + " " + c};
  case 1:
    return {" " + c + " ", " " + c + " ", " " + c + " ", " " + c + " ", " " + c + " "};
  case 2:
    return {c + " " + c + " " + c, "    " + c, c + " " + c + " " + c, c + "    ", c + " " + c + " " + c};
  case 3:
    return {c + " " + c + " " + c, "    " + c, c + " " + c + " " + c, "    " + c, c + " " + c + " " + c};
  case 4:
    return {c + "   " + c, c + "   " + c, c + " " + c + " " + c, "    " + c, "    " + c};
  case 5:
    return {c + " " + c + " " + c, c + "    ", c + " " + c + " " + c, "    " + c, c + " " + c + " " + c};
  case 6:
    return {c + " " + c + " " + c, c + "    ", c + " " + c + " " + c, c + "   " + c, c + " " + c + " " + c};
  case 7:
    return {c + " " + c + " " + c, "    " + c, "    " + c, "    " + c, "    " + c};
  case 8:
    return {c + " " + c + " " + c, c + "   " + c, c + " " + c + " " + c, c + "   " + c, c + " " + c + " " + c};
  case 9:
    return {c + " " + c + " " + c, c + "   " + c, c + " " + c + " " + c, "    " + c, c + " " + c + " " + c};
  }

  assert( false );
}

std::array<std::string, 5> get_colon()
{
  std::string c = "☃";

  return {"   ", " " + c + " ", "   ", " " + c + " ", "   "};
}

int main( int argc, char ** argv )
{
  std::vector<std::string> symbols({"🐥", "🐵", "🐻", "🐼", "🐶", "🐰", "🐨", "🐭", "🐷", "🐮"});

  const auto now = std::chrono::system_clock::now();
  const auto tt  = std::chrono::system_clock::to_time_t( now );

  tm local_tm = *localtime( &tt );

  const auto h = local_tm.tm_hour;
  const auto m = local_tm.tm_min;
  const auto s = local_tm.tm_sec;

  std::vector<std::array<std::string, 5>> fmt;

  fmt.push_back( get_digit( h / 10, symbols[h / 10] ) );
  fmt.push_back( get_digit( h % 10, symbols[h % 10] ) );
  fmt.push_back( get_colon() );
  fmt.push_back( get_digit( m / 10, symbols[m / 10] ) );
  fmt.push_back( get_digit( m % 10, symbols[m % 10] ) );
  fmt.push_back( get_colon() );
  fmt.push_back( get_digit( s / 10, symbols[s / 10] ) );
  fmt.push_back( get_digit( s % 10, symbols[s % 10] ) );

  const auto sep = std::string( "    " );

  for ( auto i = 0; i < 5; ++i )
  {
    for ( const auto& d : fmt )
    {
      std::cout << d[i] << sep;
    }
    std::cout << std::endl;
  }

  return 0;
}

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End:
