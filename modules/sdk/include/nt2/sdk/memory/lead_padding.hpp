/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_MEMORY_LEAD_PADDING_HPP_INCLUDED
#define NT2_SDK_MEMORY_LEAD_PADDING_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Padding strategies for memory allocation
////////////////////////////////////////////////////////////////////////////////
#include <boost/mpl/pair.hpp>
#include <nt2/sdk/memory/padding.hpp>
#include <boost/simd/sdk/memory/parameters.hpp>

////////////////////////////////////////////////////////////////////////////////
// Various pre-made padding strategies
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace memory
{
  //////////////////////////////////////////////////////////////////////////////
  // Lead padding: leading size is aligned_on
  //////////////////////////////////////////////////////////////////////////////
  struct lead_padding
  {
    lead_padding( std::size_t v = BOOST_SIMD_CONFIG_ALIGNMENT ) : value_(v) {}
    
    std::size_t value() const { return value_; }    
    std::size_t value_;
  };
} }

#include <nt2/sdk/memory/details/lead_padding.hpp>

#endif
