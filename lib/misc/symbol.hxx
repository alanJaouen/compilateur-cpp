/**
 ** \file misc/symbol.hxx
 ** \brief Inline implementation of misc::symbol.
 */

#pragma once

#include <misc/symbol.hh>

namespace misc
{
  inline symbol&
  symbol::operator=(const symbol& rhs)
  {
    if (this != &rhs)
      obj_ = rhs.obj_;// FIXME: Some code was deleted here.
    return *this;
  }

  inline bool
  symbol::operator==(const symbol& rhs) const
  {
    return obj_ == rhs.obj_;// FIXME: Some code was deleted here.
  }

  inline bool
  symbol::operator!=(const symbol& rhs) const
  {
    return !operator==(rhs);// FIXME: Some code was deleted here.
  }

  inline std::ostream&
  operator<<(std::ostream& ostr, const symbol& the)
  {
    return ostr << the.get();// FIXME: Some code was deleted here.
  }
}
