//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_META_IS_COMPOSITE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_META_IS_COMPOSITE_HPP_INCLUDED

#include <boost/mpl/bool.hpp>

////////////////////////////////////////////////////////////////////////////////
// Check if a given type is composite or not
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  template<class Type> struct is_composite : boost::mpl::false_ {};
} }

#endif
