//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 ieee toolbox - sbits/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of ieee components in scalar mode
//////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
=======
/// created by jt the 04/12/2010
/// modified by jt the 17/01/2011
>>>>>>> functor2
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/toolbox/ieee/include/sbits.hpp>
<<<<<<< HEAD

NT2_TEST_CASE_TPL ( sbits_real__1,  NT2_REAL_TYPES)
{
  using nt2::sbits;
  using nt2::functors::sbits_;
  typedef typename nt2::meta::call<sbits_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_integer<T, signed>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 


=======

NT2_TEST_CASE_TPL ( sbits_real__1,  NT2_REAL_TYPES)
{
  using nt2::sbits;
  using nt2::tag::sbits_;
  typedef typename nt2::meta::call<sbits_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_integer<T, signed>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


>>>>>>> functor2
  // specific values tests
  NT2_TEST_ULP_EQUAL(  sbits(nt2::Nan<T>()), nt2::Mone<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(  sbits(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for real_

NT2_TEST_CASE_TPL ( sbits_unsigned_int__1,  NT2_UNSIGNED_TYPES)
{
  using nt2::sbits;
<<<<<<< HEAD
  using nt2::functors::sbits_;
=======
  using nt2::tag::sbits_;
>>>>>>> functor2
  typedef typename nt2::meta::call<sbits_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_integer<T, signed>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
<<<<<<< HEAD
=======
  double ulpd;
>>>>>>> functor2


  // specific values tests
  NT2_TEST_ULP_EQUAL(  sbits(nt2::One<T>()), nt2::One<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(  sbits(nt2::Valmax<T>()), nt2::Mone<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(  sbits(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( sbits_signed_int__1,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::sbits;
<<<<<<< HEAD
  using nt2::functors::sbits_;
=======
  using nt2::tag::sbits_;
>>>>>>> functor2
  typedef typename nt2::meta::call<sbits_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_integer<T, signed>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
<<<<<<< HEAD
=======
  double ulpd;
>>>>>>> functor2


  // specific values tests
  NT2_TEST_ULP_EQUAL(  sbits(nt2::Mone<T>()), nt2::Mone<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(  sbits(nt2::One<T>()), nt2::One<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(  sbits(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for signed_int_