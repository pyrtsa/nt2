//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_TOOLBOX_BOOLEAN_FUNCTIONS_IF_NAN_ELSE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_BOOLEAN_FUNCTIONS_IF_NAN_ELSE_HPP_INCLUDED
/*!
 * \file
**/
#include <boost/simd/include/simd.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_boolean
 * \defgroup boost_simd_boolean_if_nan_else if_nan_else
 *
 * \par Description
 * If a0 is true returns nan else returns a1
 * \par
 * The first operand must be a boolean type according to
 * the SIMD architecture compatible to the  other one.
 * the result type is the same as the second parameter one.
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/if_nan_else.hpp>
 * \endcode
 * 
 * \par Alias 
 * \arg ifnanelse
 * \arg ifnot_else_nan
 * \arg ifnotelsenan
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0,class A1>
 *     meta::call<tag::if_nan_else_(A0,A1)>::type
 *     if_nan_else(const A0 & a0,const A1 & a1);
 * }
 * \endcode
 *
 * \param a0 the first parameter of if_nan_else
 * \param a1 the second parameter of if_nan_else
 * 
 * \return a value of the type of the second parameter
 *  
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *  
**/



namespace boost { namespace simd { namespace tag
  {         
    /*!
     * \brief Define the tag if_nan_else_ of functor if_nan_else 
     *        in namespace boost::simd::tag for toolbox boost.simd.boolean
    **/
     struct if_nan_else_ {};
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::if_nan_else_, if_nan_else, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::if_nan_else_, ifnanelse, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::if_nan_else_, ifnot_else_nan, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::if_nan_else_, ifnotelsenan, 2)
} }
 
#endif


