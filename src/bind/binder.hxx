/**
 ** \file bind/binder.hxx
 ** \brief Inline methods of bind::Binder.
 **/

#pragma once

#include <bind/binder.hh>

namespace bind
{

  /*-----------------.
  | Error handling.  |
  `-----------------*/

  // FIXME: Some code was deleted here (Error reporting).

  /*-------------------.
  | Definition sites.  |
  `-------------------*/

  // FIXME: Some code was deleted here.

  /*------------------.
  | Visiting /Decs/.  |
  `------------------*/

  template <class D>
  void
  Binder::decs_visit(ast::AnyDecs<D>& e)
  {
    // Shorthand.
    //using decs_type = ast::AnyDecs<D>;
    for (auto& i : e.decs_get())
    {
      visit_dec_header(*i);
      visit_dec_body(*i);
    }
    
  }

  /* These specializations are in bind/binder.hxx, so that derived
     visitors can use them (otherwise, they wouldn't see them).  */


  template <>
  inline 
  void Binder::visit_dec_header<ast::TypeDec>(ast::TypeDec& e)
  {
    type_scope_.put(e.name_get(), &e);
    e.ty_get().accept(*this);
    
  }

  template <>
  inline 
  void Binder::visit_dec_header<ast::FunctionDec>(ast::FunctionDec& e)
  {
    function_scope_.put(e.name_get(), &e);
    decs_visit(e.formals_get());
    if (e.result_get())
      e.result_get()->accept(*this);
  }

  template <>
  inline 
  void Binder::visit_dec_header<ast::VarDec>(ast::VarDec& e)
  {
    Var_scope_.put(e.name_get(), &e);
  }
  
  template <>
  inline 
  void Binder::visit_dec_body<ast::TypeDec>(ast::TypeDec& e)
  {
    e.accept(*this);
  }

  template <>
  inline 
  void Binder::visit_dec_body<ast::FunctionDec>(ast::FunctionDec& e)
  {
    e.accept(*this);
  }

  template <>
  inline 
  void Binder::visit_dec_body<ast::VarDec>(ast::VarDec& e)
  {
    e.accept(*this);
  }
  

  

} // namespace bind
