//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_SDK_SIMD_DETAILS_NATIVE_META_AS_INTEGER_HPP_INCLUDED
#define NT2_SDK_SIMD_DETAILS_NATIVE_META_AS_INTEGER_HPP_INCLUDED

#include <nt2/sdk/simd/category.hpp>
#include <boost/mpl/placeholders.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/make_integer.hpp>

namespace nt2 { namespace details
{
  template<class T, class H, class X, class Sign>
  struct  as_integer<T,Sign, meta::simd_<H,X> >
        : T::template cast< typename meta::
                            make_integer< sizeof(typename T::value_type)
                                        , Sign
                                        >::type
                          >
  {};
} }

#endif
