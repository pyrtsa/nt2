//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_IDIVFIX_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_IDIVFIX_HPP_INCLUDED

#include <boost/simd/include/functions/trunc.hpp>
#include <boost/simd/include/functions/rdivide.hpp>
#include <boost/simd/include/functions/toint.hpp>

namespace boost { namespace dispatch
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::idivfix_, tag::cpu_, (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))
                              ((simd_<arithmetic_<A0>,X>))
                            )
  {
    typedef A0 result_type;
    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2) { return boost::simd::rdivide(a0, a1); }
  };

  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::idivfix_, tag::cpu_, (A0)(X)
                            , ((simd_<real_<A0>,X>))((simd_<real_<A0>,X>))
                            )
  {
    typedef typename meta::as_integer < A0 > ::type result_type;
    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2) { return boost::simd::toint(boost::simd::trunc(a0/a1)); }
  };
} }

#endif
