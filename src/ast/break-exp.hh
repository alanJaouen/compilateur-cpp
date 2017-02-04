/**
 ** \file ast/break-exp.hh
 ** \brief Declaration of ast::BreakExp.
 */

#pragma once

#include <ast/exp.hh>

namespace ast
{

  /// BreakExp.
  class BreakExp : public Exp
  {
    // FIXME: Some code was deleted here.
  public:
    /** \name Ctor & dtor.
     ** \{ */
    /// Construct a BreakExp node.
    BreakExp(const Location& location, Exp* test, Exp* body);
    /// Destroy a BreakExp node.
    virtual ~BreakExp();
    /** \} */

    /// \name Visitors entry point.
    /// \{ */
    /// Accept a const visitor \a v.
    void accept(ConstVisitor& v) const override;
    /// Accept a non-const visitor \a v.
    void accept(Visitor& v) override;
    /// \}

  };

} // namespace ast

#include <ast/break-exp.hxx>

