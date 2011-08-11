//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_REDUCTION_FUNCTION_SIMD_SSE_AVX_NBTRUE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_REDUCTION_FUNCTION_SIMD_SSE_AVX_NBTRUE_HPP_INCLUDED
#include <boost/dispatch/meta/as_real.hpp>
#include <boost/dispatch/meta/strip.hpp>
#include <boost/simd/include/functions/details/simd/sse/sse4_1/nbtrue.hpp>
#include <boost/simd/include/functions/is_nez.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::nbtrue_, tag::cpu_,
                         (A0),
                         ((simd_<arithmetic_<A0>,boost::simd::tag::avx_>))
                        )
  {
    typedef int32_t result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(1)
    {
      typedef typename meta::scalar_of<A0>::type sctype;
      typedef typename simd::native<sctype, boost::simd::tag::sse_ >  svtype;
      svtype a00 = { _mm256_extractf128_si256(a0, 0)};
      svtype a01 = { _mm256_extractf128_si256(a0, 1)};
      return nbtrue(a00)+nbtrue(a01);
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////


  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::nbtrue_, tag::cpu_,
                         (A0),
                         ((simd_<double_<A0>,boost::simd::tag::avx_>))
                        )
  {
    typedef int32_t result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(1)
    {
      int32_t  r = _mm256_movemask_pd(isnez(a0));
      return   (r&1)+(r>>1&1)+((r>>2)&1)+(r>>3);
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////


  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::nbtrue_, tag::cpu_,
                         (A0),
                         ((simd_<float_<A0>,boost::simd::tag::avx_>))
                        )
  {
    typedef int32_t result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(1)
    {
      typedef typename dispatch::meta::as_real<A0>::type type;
      int32_t  r = _mm256_movemask_ps(isnez(a0));
      return   (r&1)+((r>>1)&1)+((r>>2)&1)+(r>>3&1)+((r>>4)&1)+((r>>5)&1)+(r>>6&1)+(r>>7);
      //      return __builtin_popcount(_mm_movemask_ps(isnez(cast<type>(a0))));
    }
  };
} } }
#endif