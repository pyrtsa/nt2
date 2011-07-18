//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_BITWISE_FUNCTION_SIMD_SSE_AVX_BITWISE_NOTAND_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_BITWISE_FUNCTION_SIMD_SSE_AVX_BITWISE_NOTAND_HPP_INCLUDED
#include <boost/dispatch/meta/strip.hpp>

#include <boost/simd/include/functions/details/simd/sse/sse4_1/bitwise_notand.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH(tag::bitwise_notand_, tag::cpu_,
                                 (A0),
                                 ((simd_<arithmetic_<A0>,tag::avx_>))
                                 ((simd_<arithmetic_<A0>,tag::avx_>))
                                );

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct call<tag::bitwise_notand_(tag::simd_<tag::arithmetic_, tag::avx_),
                                   tag::simd_<tag::arithmetic_, tag::avx_)),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : meta::strip<A0>{};//

    BOOST_DISPATCH_FUNCTOR_CALL(2)
    {
      typedef typename meta::double_<A0>::type dtype;
      return simd::native_cast<A0>(b_notand(simd::native_cast<simd::native<dtype, simd::avx_> >(a0),
                               simd::native_cast<simd::native<dtype, simd::avx_> >(a1)));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH(tag::bitwise_notand_, tag::cpu_,
                                 (A0),
                                 ((simd_<double_<A0>,tag::avx_>))
                                 ((simd_<double_<A0>,tag::avx_>))
                                );

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct call<tag::bitwise_notand_(tag::simd_<tag::double_, tag::avx_),
                                   tag::simd_<tag::double_, tag::avx_)),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : meta::strip<A0>{};//

    BOOST_DISPATCH_FUNCTOR_CALL(2)
    {
      A0 that;
      that = a1;
      that =  _mm256_andnot_pd(a0, that);
      return that;
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH(tag::bitwise_notand_, tag::cpu_,
                                 (A0),
                                 ((simd_<float_<A0>,tag::avx_>))
                                 ((simd_<float_<A0>,tag::avx_>))
                                );

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct call<tag::bitwise_notand_(tag::simd_<tag::float_, tag::avx_),
                                   tag::simd_<tag::float_, tag::avx_)),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : meta::strip<A0>{};//

    BOOST_DISPATCH_FUNCTOR_CALL(2)
    {
      A0 that;
      that = a1;
      that = _mm256_andnot_ps(a0,that);
      return that;
    }
  };
} }

#endif
