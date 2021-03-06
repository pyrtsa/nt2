/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_CONFIG_SOFTWARE_HPP_INCLUDED
#define NT2_SDK_CONFIG_SOFTWARE_HPP_INCLUDED

#include <limits.h>
#include <boost/preprocessor/stringize.hpp>

namespace nt2 { namespace config
{
  //////////////////////////////////////////////////////////////////////////////
  // Status header reporter - Head for the reporter list
  //////////////////////////////////////////////////////////////////////////////
  inline void syslib()
  {
    #if defined(__GNU_LIBRARY__)
    puts(" libc version            : " BOOST_PP_STRINGIZE(__GNU_LIBRARY__) );
    #elif defined(__GLIBC__)
    puts(" libc version            : " BOOST_PP_STRINGIZE(__GLIBC__) );
    #endif

    #if defined(__CPPLIB_VER)
    puts(" Dinkumware STD version  : " BOOST_PP_STRINGIZE(__CPPLIB_VER) );
    #elif defined(__INTEL_CXXLIB_ICC)
    puts(" Intel STD version       : " BOOST_PP_STRINGIZE(__INTEL_CXXLIB_ICC) );
    #elif defined(__GLIBCXX__)
    puts(" GNU STD version         : " BOOST_PP_STRINGIZE(__GLIBCXX__) );
    #endif

    puts(" Boost libraries version : " BOOST_LIB_VERSION  "\n");
  }

  NT2_REGISTER_STATUS(syslib);
} }
#endif
