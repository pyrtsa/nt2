//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_AVERAGE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_AVERAGE_HPP_INCLUDED
#include <boost/simd/include/constants/real.hpp>
#include <boost/dispatch/meta/strip.hpp>
#include <boost/simd/include/functions/shrai.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace dispatch
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::average_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))((simd_<arithmetic_<A0>,X>))
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
      return (a0&a1)+shrai(a0^a1,1);
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace dispatch
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::average_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<real_<A0>,X>))((simd_<real_<A0>,X>))
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    BOOST_DISPATCH_FUNCTOR_CALL_REPEAT(2)
    {
       return (a0+a1)*Half<A0>();
    }
  };
} }


#endif
