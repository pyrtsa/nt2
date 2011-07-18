//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_SDK_SIMD_DETAILS_IMPL_COMMON_TRUE_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_DETAILS_IMPL_COMMON_TRUE_HPP_INCLUDED

#include <boost/simd/sdk/meta/from_bits.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/sdk/details/ignore_unused.hpp>

////////////////////////////////////////////////////////////////////////////////
// in SIMD, True is not !0 but ~0 whatever the type
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace dispatch
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::true_, tag::cpu_
                            , (A0)(X), ((target_< simd_< real_<A0> ,X> >))
                            )
  {
    typedef typename A0::type result_type;

    BOOST_DISPATCH_FUNCTOR_CALL(1)
    {
      // TODO : replace by bitwise_cast
      ignore_unused(a0);
      typedef typename meta::scalar_of<result_type>::type type;
      typedef typename meta::as_integer<type>::type       int_type;
      typename meta::from_bits<type>::type that = { ~int_type(0) };
      return splat<result_type>(that.value);
    }
  };
} }

namespace boost { namespace dispatch
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( tag::true_, tag::cpu_
                            , (A0)(X), ((target_< simd_< integer_<A0> ,X> >))
                            )
  {
    typedef typename A0::type result_type;

    BOOST_DISPATCH_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      typedef typename meta::scalar_of<result_type>::type type;
      return splat<result_type>(~type(0));
    }
  };
} }

#endif
