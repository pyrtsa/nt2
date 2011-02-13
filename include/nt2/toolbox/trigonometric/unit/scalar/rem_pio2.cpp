//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 trigonometric toolbox - rem_pio2/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of trigonometric components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by $author$ the $date$
/// modified by $author$ the $date$
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/toolbox/trigonometric/include/rem_pio2.hpp>
// specific includes for arity 1 tests
#include <nt2/toolbox/trigonometric/include/constants.hpp>
#include <nt2/toolbox/crlibm/include/rem_pio2.hpp>

NT2_TEST_CASE_TPL ( rem_pio2_real__1,  NT2_REAL_TYPES)
{
  using nt2::rem_pio2;
  using nt2::tag::rem_pio2_;
  typedef typename nt2::meta::call<rem_pio2_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  rem_pio2(-nt2::Pi<T>()), nt2::Zero<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  rem_pio2(-nt2::Pi<T>()/2), nt2::Mone<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  rem_pio2(-nt2::Pi<T>()/4), nt2::Sqrt_2o_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  rem_pio2(nt2::Inf<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  rem_pio2(nt2::Minf<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  rem_pio2(nt2::Nan<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  rem_pio2(nt2::Pi<T>()), nt2::Zero<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  rem_pio2(nt2::Pi<T>()/2), nt2::One<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  rem_pio2(nt2::Pi<T>()/4), nt2::Sqrt_2o_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  rem_pio2(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
  // random verifications
  static const uint32_t NR = 10000;
  {
    NT2_CREATE_BUFFER(a0,T, NR, -20*nt2::Pi<T>(), 20*nt2::Pi<T>());
    double ulp0 = 0.0;
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::rem_pio2(a0),nt2::crlibm::rem_pio2<nt2::rn>(a0),0);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for real_

NT2_TEST_CASE_TPL ( rem_pio2_unsigned_int__1,  NT2_UNSIGNED_TYPES)
{
  using nt2::rem_pio2;
  using nt2::tag::rem_pio2_;
  typedef typename nt2::meta::call<rem_pio2_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  rem_pio2(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( rem_pio2_signed_int__1,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::rem_pio2;
  using nt2::tag::rem_pio2_;
  typedef typename nt2::meta::call<rem_pio2_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  rem_pio2(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
} // end of test for signed_int_