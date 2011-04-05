//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_REDUCTION_FUNCTION_SCALAR_POSMAX_HPP_INCLUDED
#define NT2_TOOLBOX_REDUCTION_FUNCTION_SCALAR_POSMAX_HPP_INCLUDED

#include <nt2/sdk/details/ignore_unused.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is fundamental_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::posmax_, tag::cpu_,
                        (A0),
                        (fundamental_<A0>)
                       )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::posmax_(tag::fundamental_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    {
      typedef typename meta::as_integer<A0, signed>::type type;
    };

    NT2_FUNCTOR_CALL(1)
    {
      details::ignore_unused(a0);
      return 0;
    }

  };
} }

#endif
// modified by jt the 26/12/2010