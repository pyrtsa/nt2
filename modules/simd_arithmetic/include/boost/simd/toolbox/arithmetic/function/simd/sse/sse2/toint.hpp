//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_SSE2_TOINT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_SSE2_TOINT_HPP_INCLUDED
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/strip.hpp>
#include <boost/simd/include/functions/select.hpp>
#include <boost/simd/include/functions/bitwise_andnot.hpp>
#include <boost/simd/include/functions/make.hpp>

namespace boost { namespace dispatch
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION(tag::toint_, tag::cpu_, (A0)
                            , ((simd_<arithmetic_<A0>,tag::sse_>))
                            )
  {
    typedef typename meta::as_integer<A0>::type result_type;
    BOOST_DISPATCH_FUNCTOR_CALL(1) { return a0; }
  };

  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::toint_, tag::cpu_ , (A0)
                            , ((simd_<double_<A0>,tag::sse_>))
                            )
  {
    typedef typename meta::as_integer<A0>::type result_type;
    BOOST_DISPATCH_FUNCTOR_CALL(1)
    {
      typedef typename meta::scalar_of<result_type>::type stype;
      A0 aa0 = b_andnot(a0, is_nan(a0)); 
      const result_type v = make<result_type> ( static_cast<stype>(aa0[0])
                                              , static_cast<stype>(aa0[1])
                                              );
      return  sel(eq(aa0, Inf<A0>()), Inf<result_type>(), v);
    }
  };

  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::toint_, tag::cpu_ , (A0)
                            , ((simd_<float_<A0>,tag::sse_>))
                            )
  {
    typedef typename meta::as_integer<A0>::type result_type;
    BOOST_DISPATCH_FUNCTOR_CALL(1)
    {
      A0 aa0 = b_andnot(a0, is_nan(a0)); 
      result_type that = {_mm_cvttps_epi32(aa0)};
      return  sel(eq(aa0, Inf<A0>()), Inf<result_type>(), that);
    }
  };
} }

#endif
