//
// Copyright (C) 2004-2008 Maciej Sobczak, Stephen Hutton
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SOCI_POSTGRESQL_COMMON_H_INCLUDED
#define SOCI_POSTGRESQL_COMMON_H_INCLUDED

#include "soci-postgresql.h"

namespace soci
{

namespace details
{

namespace postgresql
{

// helper function for integer conversions
template <typename T>
void check_integer_conversion(char const * buf, char * end, T & val)
{
    if (end == buf)
    {
        if (std::tolower(*buf) == 't')
        {
            val = static_cast<T>(1);
        }
        else if (std::tolower(*buf) == 'f')
        {
            val = static_cast<T>(0);
        }
        else
        {
            throw soci_error("Cannot convert data.");
        }
    }
}

// helper function for parsing datetime values
void parse_std_tm(char const * buf, std::tm & t);

// helper for vector operations
template <typename T>
std::size_t get_vector_size(void * p)
{
    std::vector<T> * v = static_cast<std::vector<T> *>(p);
    return v->size();
}

} // namespace postgresql

} // namespace details

} // namespace soci

#endif // SOCI_POSTGRESQL_COMMON_H_INCLUDED
