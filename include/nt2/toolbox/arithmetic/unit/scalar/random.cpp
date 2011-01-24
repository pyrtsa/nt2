//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - random/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
=======
/// created by jt the 01/12/2010
/// modified by jt the 17/01/2011
>>>>>>> functor2
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/toolbox/arithmetic/include/random.hpp>

NT2_TEST_CASE_TPL ( random_real__2,  NT2_REAL_TYPES)
{
  using nt2::random;
<<<<<<< HEAD
  using nt2::functors::random_;
=======
  using nt2::tag::random_;
>>>>>>> functor2
  typedef typename nt2::meta::call<random_(T,T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::arithmetic(T,T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
<<<<<<< HEAD
=======
  double ulpd;
>>>>>>> functor2

} // end of test for real_

NT2_TEST_CASE_TPL ( random_unsigned_int__2,  NT2_UNSIGNED_TYPES)
{
  using nt2::random;
<<<<<<< HEAD
  using nt2::functors::random_;
=======
  using nt2::tag::random_;
>>>>>>> functor2
  typedef typename nt2::meta::call<random_(T,T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::arithmetic(T,T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
<<<<<<< HEAD
=======
  double ulpd;
>>>>>>> functor2

} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( random_signed_int__2,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::random;
<<<<<<< HEAD
  using nt2::functors::random_;
=======
  using nt2::tag::random_;
>>>>>>> functor2
  typedef typename nt2::meta::call<random_(T,T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::arithmetic(T,T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
<<<<<<< HEAD
=======
  double ulpd;
>>>>>>> functor2

} // end of test for signed_int_