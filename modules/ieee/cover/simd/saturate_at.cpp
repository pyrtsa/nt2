//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 ieee toolbox - saturate_at/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of ieee components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 20/03/2011
/// 
#include <nt2/toolbox/ieee/include/saturate_at.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/include/functions/max.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <nt2/sdk/meta/floating.hpp>
#include <nt2/sdk/meta/arithmetic.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/include/functions/load.hpp>


NT2_TEST_CASE_TPL ( saturate_at_real__1_0,  NT2_SIMD_REAL_TYPES)
{
  using nt2::saturate_at;
  using nt2::tag::saturate_at_;
  using nt2::load; 
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<saturate_at_<nt2::tag::Pi>(vT)>::type r_t;
  typedef typename nt2::meta::call<saturate_at_<nt2::tag::Pi>(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, -nt2::Ten<T>(), nt2::Ten<T>());
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(nt2::uint32_t j = 0; j < NR/cardinal_of<n_t>::value; j++)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        r_t v = saturate_at<nt2::tag::Pi>(a0);
	std::cout << " a0 " << a0 << std::endl; 
	std::cout << " v " << v << std::endl; 
        for(int i = 0; i< cardinal_of<n_t>::value; i++)
        {
          int k = i+j*cardinal_of<n_t>::value;
          NT2_TEST_ULP_EQUAL( v[i],ssr_t(nt2::saturate_at<nt2::tag::Pi> (tab_a0[k])), 2.5);
	  std::cout << "tab_a0[k] " << tab_a0[k] << std::endl; 
	  std::cout << " v[" << i << "] = " << v[i] << " sv " << ssr_t(nt2::saturate_at<nt2::tag::Pi>(tab_a0[k])) << std::endl; 

          ulp0 = nt2::max(ulpd,ulp0);
        }
      }
    std::cout << "max ulp found is: " << ulp0 << std::endl;
  }
} // end of test for real_