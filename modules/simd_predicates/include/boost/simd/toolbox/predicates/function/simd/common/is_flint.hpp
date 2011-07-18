//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_IS_FLINT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_IS_FLINT_HPP_INCLUDED
#include <boost/dispatch/meta/strip.hpp>
#include <boost/simd/include/functions/is_eqz.hpp>
#include <boost/simd/include/functions/trunc.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace dispatch
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::is_flint_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    BOOST_DISPATCH_FUNCTOR_CALL(1)
    {
       return is_eqz(a0-trunc(a0));
    }
  };
} }


#endif
