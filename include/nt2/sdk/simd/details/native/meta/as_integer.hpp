 /*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_SIMD_DETAILS_NATIVE_AS_INTEGER_HPP_INCLUDED
#define NT2_SDK_SIMD_DETAILS_NATIVE_AS_INTEGER_HPP_INCLUDED

#include <nt2/sdk/simd/category.hpp>
#include <boost/mpl/placeholders.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/make_integer.hpp>

namespace nt2 { namespace details
{
  template<class Type, class C, class X, class Sign>
  struct  as_integer<Type,Sign,tag::simd_(C,X) >
        : meta::make_integer< sizeof(typename meta::scalar_of<Type>::type)
                            , Sign
                            , simd::native<boost::mpl::_,X>
                            >
  {};
} }

#endif