//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II       
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI       
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_CONSTANTS_90_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_CONSTANTS_90_HPP_INCLUDED
/*!
 * \file
**/
#include <nt2/sdk/constant/constant.hpp>
/*!
 * \ingroup trigo_constant
 * \defgroup trigo_constant__90 _90
 *
 * \par Description
 * Constant _90 : 90.
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/_90.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class T,class A0>
 *     meta::call<tag::_90_(A0)>::type
 *     _90();
 * }
 * \endcode
 *
 * 
 * \param T template parameter of _90
 * 
 * \return type T value
 *  
 *  
**/
namespace nt2
{
  NT2_MAKE_STD_CONSTANT(_90    , 0x4056800000000000ll, 0x42b40000,  90)
}

#endif
