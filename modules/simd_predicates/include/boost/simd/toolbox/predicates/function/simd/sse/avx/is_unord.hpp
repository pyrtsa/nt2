//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_AVX_IS_UNORD_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_AVX_IS_UNORD_HPP_INCLUDED
#include <boost/simd/include/functions/boolean.hpp>
#include <boost/simd/sdk/details/ignore_unused.hpp>
#include <boost/dispatch/meta/strip.hpp>
#include <boost/simd/include/functions/details/simd/sse/sse4_1/is_unord.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace dispatch
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION(tag::is_unord_, tag::cpu_,
                           (A0),
                           ((simd_<arithmetic_<A0>,tag::avx_>))
                           ((simd_<arithmetic_<A0>,tag::avx_>))
                          )
  {
    typedef A0 result_type;
    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      ignore_unused(a0);
      ignore_unused(a1);
      return False<A0>();
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////


  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION(tag::is_unord_, tag::cpu_,
                           (A0),
                           ((simd_<double_<A0>,tag::avx_>))
                           ((simd_<double_<A0>,tag::avx_>))
                          )
  {
    typedef A0 result_type;
    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = {_mm256_cmp_pd(a0,a1, _CMP_UNORD_Q)};
      return that;
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////


  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION(tag::is_unord_, tag::cpu_,
                           (A0),
                           ((simd_<float_<A0>,tag::avx_>))
                           ((simd_<float_<A0>,tag::avx_>))
                          )
  {
    typedef A0 result_type;
    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = {_mm256_cmp_ps(a0,a1, _CMP_UNORD_Q)};
      return that;
    }
  };
} }
#endif
