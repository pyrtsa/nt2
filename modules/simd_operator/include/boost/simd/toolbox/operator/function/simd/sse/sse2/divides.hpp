//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_SSE_SSE2_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_SSE_SSE2_DIVIDES_HPP_INCLUDED

#include <boost/simd/include/functions/map.hpp>
#include <boost/simd/include/functions/bitwise_and.hpp>
#include <boost/simd/include/functions/bitwise_or.hpp>
#include <boost/simd/include/functions/plus.hpp>
#include <boost/simd/include/functions/minus.hpp>
#include <boost/simd/include/functions/is_equal.hpp>
#include <boost/simd/include/constants/digits.hpp>

namespace boost { namespace dispatch
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::divides_, tag::cpu_
                            , (A0)
                            , ((simd_<double_<A0>,tag::sse_>))
                              ((simd_<double_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;

    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      A0  that = { _mm_div_pd(a0,a1) };
      return b_or(b_and(eq(a0, Zero<A0>()), eq(a1, Zero<A0>())),that);
    }
  };

  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::divides_, tag::cpu_
                            , (A0)
                            , ((simd_<float_<A0>,tag::sse_>))
                              ((simd_<float_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;

    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      A0  that = { _mm_div_ps(a0,a1) };
      return  b_or(b_and(eq(a0, Zero<A0>()), eq(a1, Zero<A0>())),that);
    }
  };

  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::divides_, tag::cpu_
                            , (A0)
                            , ((simd_<integer_<A0>,tag::sse_>))
                              ((simd_<integer_<A0>,tag::sse_>))
                            )
  {
    typedef A0 result_type;

    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      const A0 iseqza1 = eq(a1, Zero<A0>());
      return map( typename make_functor<tag::divides_,A0>::type()
                , (a0-b_and(iseqza1, a0))
                , (a1+b_and(iseqza1, One<A0>()))
                );
    }
  };
} }

#endif
