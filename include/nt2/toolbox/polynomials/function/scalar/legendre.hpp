//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_POLYNOMIALS_FUNCTION_SCALAR_LEGENDRE_HPP_INCLUDED
#define NT2_TOOLBOX_POLYNOMIALS_FUNCTION_SCALAR_LEGENDRE_HPP_INCLUDED
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/constant/real.hpp>


namespace nt2 { namespace functors
{

  template<class Info>
  struct validate<legendre_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :boost::is_integral<A0>{};
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute legendre(const A0& a0, const A1& a1)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<legendre_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL_DISPATCH(
      2,
      A0,
      (2, (real_,arithmetic_))
    )
    NT2_FUNCTOR_CALL_EVAL_IF(2,       real_)
    {
      if(abs(a1) > 1) return Nan<A0>(); 
      A0 p0, p1;
      p0 = One<A0>();
      p1 = a1;
      if(a0 == 0)  return p0;
      uint32_t n = 1;
      
      while(n < a0)
	{
	  std::swap(p0, p1);
	  p1 = legendre_next(n, a1, p0, p1);
	  ++n;
	}
      return p1;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,       arithmetic_)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type;
      return legendre(type(a0));
    }
    template <class T>
    static inline T 
    legendre_next(uint32_t  l, T x, T Pl, T Plm1)
    {
      return ((2 * l + 1) * x * Pl - l * Plm1) / (l + 1);
    }
  };
} }


      
#endif