//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II       
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI       
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_EXPONENTIAL_CONSTANTS_INVLOG_10_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_CONSTANTS_INVLOG_10_HPP_INCLUDED
/*!
 * \file
**/
#include <nt2/sdk/constant/constant.hpp>
/*!
 * \ingroup expon_constant
 * \defgroup expon_constant_Invlog_10 Invlog_10
 *
 * \par Description
 * Constant Invlog_10 : \f$\frac1{\log(10)}\f$ constant.
 * \par
 * The value of this constant is type dependant. This means that for different
 * types it does not represent the same mathematical number.
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/Invlog_10.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class T,class A0>
 *     meta::call<tag::Invlog_10_(A0)>::type
 *     Invlog_10();
 * }
 * \endcode
 *
 * 
 * \param T template parameter of Invlog_10
 * 
 * \return type T value
 *  
 *  
**/

namespace nt2
{
  NT2_MAKE_STD_CONSTANT(Invlog_10    ,0x3fdbcb7b1526e50dLL,0x3ede5bd9, 0)
}

#endif
