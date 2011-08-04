//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_SCALAR_TRUE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_SCALAR_TRUE_HPP_INCLUDED

#include <boost/dispatch/meta/strip.hpp>
#include <boost/simd/sdk/details/ignore_unused.hpp>
#include <boost/simd/include/functions/splat.hpp>

namespace boost { namespace simd
{
//  BOOST_SIMD_STD_CONSTANT_TAG(True)
//  BOOST_SIMD_STD_CONSTANT_DEF(True)
} }

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::True,tag::cpu_,(A0)
                            , (target_< scalar_< fundamental_<A0> > >)
                            )
  {
    typedef typename A0::type result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      return boost::simd::splat<result_type>(true);
    }
  };
} } }

#endif
