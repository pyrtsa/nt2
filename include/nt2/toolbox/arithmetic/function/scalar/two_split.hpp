//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_TWO_SPLIT_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_TWO_SPLIT_HPP_INCLUDED
#include <nt2/sdk/constant/properties.hpp>
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <boost/fusion/tuple.hpp>


namespace nt2 { namespace functors
{

  template<class Info>
  struct validate<two_split_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct  result<This(A0)>
          : meta::is_floating_point<A0>{};
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute two_split(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<two_split_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    {
      typedef typename boost::fusion::tuple<A0,A0> type;
    };

    NT2_FUNCTOR_CALL(1)
    {
      typename NT2_CALL_RETURN_TYPE(1)::type res;
      eval(a0,boost::fusion::at_c<0>(res),boost::fusion::at_c<1>(res));
      return res;
    }

    private:
    template<class A0,class R0,class R1> inline void
    eval(A0 const& a,R0& r0, R1& r1)const
    {
      // TODO: make local constant ?
      static const int N = (Nbmantissabits<A0>()-(Nbmantissabits<A0>()>>1))+1;
      static const A0 fac = (1<<N)+1;
      A0 c = fac*a;
      r0 =  c-(c-a);
      r1 = a-r0;
    }
  };
} }


      
#endif