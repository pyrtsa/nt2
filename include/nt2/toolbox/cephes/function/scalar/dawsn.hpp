//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_DAWSN_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_DAWSN_HPP_INCLUDED

namespace nt2 { namespace functors
{
  extern "C"{
    extern float cephes_dawsnf ( float );
    extern double cephes_dawsn ( double );
  }
  template<class Info>
  struct validate<cephes::dawsn_,tag::scalar_(tag::arithmetic_),Info>
    {
      template<class Sig> struct result;
      template<class This,class A0>
      struct result<This(A0)> :
         meta::has_smaller_size<A0,long double>{};
    };
  /////////////////////////////////////////////////////////////////////////////
  // Compute dawsn(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<cephes::dawsn_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL_DISPATCH( 1, A0, (3, (float,double,arithmetic_)) )
    NT2_FUNCTOR_CALL_EVAL_IF(1,  float){ return cephes_dawsn(a0);}
    NT2_FUNCTOR_CALL_EVAL_IF(1,  double){ return cephes_dawsn(a0);}
    NT2_FUNCTOR_CALL_EVAL_IF(1, arithmetic_)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type;
      return nt2::cephes::dawsn(type(a0));
    }
  };
} }


      
#endif