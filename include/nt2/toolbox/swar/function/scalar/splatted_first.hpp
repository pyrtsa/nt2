//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_SWAR_FUNCTION_SCALAR_SPLATTED_FIRST_HPP_INCLUDED
#define NT2_TOOLBOX_SWAR_FUNCTION_SCALAR_SPLATTED_FIRST_HPP_INCLUDED



/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is fundamental_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::splatted_first_, tag::cpu_,
                                (A0),
                                (fundamental_<A0>)
                               )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::splatted_first_(tag::fundamental_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> {typedef A0 type; };

    NT2_FUNCTOR_CALL(1)
    {
      return a0;
    }

  };
} }

#endif
// modified by jt the 26/12/2010