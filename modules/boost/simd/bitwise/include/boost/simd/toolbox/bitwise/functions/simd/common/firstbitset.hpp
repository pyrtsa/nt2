//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_SIMD_COMMON_FIRSTBITSET_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_SIMD_COMMON_FIRSTBITSET_HPP_INCLUDED
#include <boost/simd/include/constants/digits.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/strip.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::firstbitset_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))
                            )
  {

    typedef typename dispatch::meta::as_integer<A0,unsigned>::type result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      typedef typename  dispatch::meta::as_integer<A0,unsigned>::type int_type;
      return b_and((b_not(simd::native_cast<int_type>(a0))+One<int_type>()), a0);

    }
  };
} } }


#endif
