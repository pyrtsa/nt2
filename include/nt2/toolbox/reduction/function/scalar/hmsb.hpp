//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_REDUCTION_FUNCTION_SCALAR_HMSB_HPP_INCLUDED
#define NT2_TOOLBOX_REDUCTION_FUNCTION_SCALAR_HMSB_HPP_INCLUDED
#include <nt2/sdk/constant/properties.hpp>

namespace nt2 { namespace functors
{

  /////////////////////////////////////////////////////////////////////////////
  // Compute hmsb(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<hmsb_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
      struct result<This(A0)> : meta::strip<A0>{}; 

    NT2_FUNCTOR_CALL(1) { return (a0&Signmask<A0>()) != 0; }
  };
} }
      
#endif