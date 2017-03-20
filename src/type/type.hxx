/**
 ** \file type/type.hxx
 ** \brief Inline methods for type::Type.
 */
#pragma once

#include <type/type.hh>
#include <misc/contract.hh>

namespace type
{
  inline bool
  operator==(const Type& lhs, const Type& rhs)
  {
  // FIXME: Some code was deleted here.
    return &lhs == &rhs;
  }

  inline bool
  operator!=(const Type& lhs, const Type& rhs)
  {
  // FIXME: Some code was deleted here.
    return &lhs != &rhs;
  }

} // namespace type