//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_IS_EQUAL_TO_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_IS_EQUAL_TO_HPP_INCLUDED

#include <boost/simd/sdk/simd/native_cast.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_equal_, tag::cpu_, (A0)
                            , ((simd_<arithmetic_<A0>,boost::simd::tag::altivec_>))
                              ((simd_<arithmetic_<A0>,boost::simd::tag::altivec_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = { simd::native_cast<A0>( vec_cmpeq(a0(),a1()) ) };
      return that;
    }
  };
} } }

#endif