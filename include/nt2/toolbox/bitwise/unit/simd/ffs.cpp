//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 bitwise toolbox - ffs/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of bitwise components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by $author$ the $date$
/// modified by $author$ the $date$
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/toolbox/bitwise/include/ffs.hpp>

NT2_TEST_CASE_TPL ( ffs_real_convert__1,  NT2_REAL_CONVERTIBLE_TYPES)
{
  using nt2::ffs;
  using nt2::tag::ffs_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<ffs_(vT)>::type r_t;

  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_SIMD_BUFFER(a0,T, NR, T(-10000), T(10000));
    double ulp0 = 0.0, ulpd = 0.0;
    for(int j = 0; j < NR/cardinal_of<n_t>::value; j++)
      {
        vT a0 = load<n_t>(&tab_a0[0],j);
        r_t v = ffs(a0);
        for(int i = 0; i< cardinal_of<n_t>::value; i++)
        {
          int k = i+j*cardinal_of<n_t>::value;
          NT2_TEST_ULP_EQUAL( v[i],nt2::ffs(tab_a0[k]),1.5);
          ulp0 = nt2::max(ulpd,ulp0);
        }
      }
    std::cout << "max ulp found is: " << ulp0 << std::endl; 
  }
} // end of test for real_convert_