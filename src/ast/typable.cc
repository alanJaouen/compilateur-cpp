/**
 ** \file ast/typable.cc
 ** \brief Implementation of ast::Typable.
 */

#include <ast/visitor.hh>
#include <ast/typable.hh>

namespace ast
{

  // FIXED by forest_b
  Typable::Typable(const type::Type* type)
    : type_(type) 
  {
  }

  Typable::~Typable()
  {
    if (type_ != nullptr)
      delete type_;
  }
  
} // namespace ast

