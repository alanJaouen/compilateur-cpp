/**
 ** \file desugar/desugar-visitor.cc
 ** \brief Implementation of desugar::DesugarVisitor.
 */

#include <misc/algorithm.hh>
#include <ast/all.hh>
#include <ast/libast.hh>
#include <parse/libparse.hh>
#include <parse/tweast.hh>
#include <desugar/desugar-visitor.hh>
#include <misc/symbol.hh>

namespace desugar
{

  DesugarVisitor::DesugarVisitor(bool desugar_for_p,
                                 bool desugar_string_cmp_p)
    : super_type()
    , desugar_for_p_(desugar_for_p)
    , desugar_string_cmp_p_(desugar_string_cmp_p)
  {}


  /*-----------------------------.
  | Desugar string comparisons.  |
  `-----------------------------*/
  void
  DesugarVisitor::operator()(const ast::OpExp& e)
  {
  // FIXME: Some code was deleted here.
    //const std::string str = "42";
    //parse::Tweast t = parse::Tweast(str);
    if (e.left_get().type_get() == &type::String::instance())
      result_ = parse::parse("strcmp(a, b ) "+ str(e.oper_get()) + " 0");    
  }


  /*----------------------.
  | Desugar `for' loops.  |
  `----------------------*/

  /*<<-
    Desugar `for' loops as `while' loops:

       for i := lo to hi do
         body

     is transformed as:

       let
         var _lo := lo
         var _hi := hi
         var i := _lo
       in
         if i <= _hi then
           while 1 do
             (
               body;
               if i = _hi then
                 break;
               i := i + 1
             )
       end

     Notice that:

     - a `_hi' variable is introduced so that `hi' is evaluated only
       once;

     - a `_lo' variable is introduced to prevent `i' from being in the
       scope of `_hi';

     - a first test is performed before entering the loop, so that the
       loop condition becomes `i < _hi' (instead of `i <= _hi'); this
       is done to prevent overflows on INT_MAX.
       ->>*/

  void
  DesugarVisitor::operator()(const ast::ForExp& e)
  {
  // FIXME: Some code was deleted here.
     
     //parse::tweast t = tweast("let ");
     //result_ = parse::parse(t);

  }


} // namespace desugar
