//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_BESSEL_FUNCTIONS_SIMD_COMMON_Y0_HPP_INCLUDED
#define NT2_TOOLBOX_BESSEL_FUNCTIONS_SIMD_COMMON_Y0_HPP_INCLUDED
#include <nt2/sdk/meta/as_floating.hpp>
#include <nt2/sdk/simd/meta/is_real_convertible.hpp>
#include <nt2/include/constants/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/log.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/j0.hpp>
#include <nt2/include/functions/sin.hpp>
#include <nt2/include/functions/bitwise_all.hpp>
#include <nt2/include/functions/select.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::y0_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))
                            )
  {

    typedef typename meta::as_floating<A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return nt2::y0(tofloat(a0));
    }
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is double
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::y0_, tag::cpu_
			      , (A0)(X)
			      , ((simd_<double_<A0>,X>))
			      )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL(1)
      {
	return map(functor<tag::y0_>(), a0);
      }
  };

  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is float
  /////////////////////////////////////////////////////////////////////////////
  NT2_FUNCTOR_IMPLEMENTATION(nt2::tag::y0_, tag::cpu_,
			     (A0)(X),
			     ((simd_<single_<A0>,X>))
			     )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL(1)
      {
	A0 x   =  nt2::abs(a0);
	A0 lt2 = lt(x, Two<A0>());
	if (bitwise_all(lt2))
	  return branch1(x);
	else
	  return select (lt2, branch1(x), branch2(x));
	// as branch1 is quick there is no need for an "else if" case
	// computing only branch2,  this probably due to the double pipeline
      }
  private:
    template < class AA0 > static inline AA0 branch1(const AA0 & a0)
    {
      typedef typename meta::scalar_of<AA0>::type sAA0; 
      AA0 z = sqr(a0); 
      AA0 p2 = (z-single_constant<AA0, 0x3edd4b3a> ())*
	horner< NT2_HORNER_COEFF_T(sAA0, 5,
				 (0x33cb0920, 
				  0xb71ded71, 
				  0x3a0c1a3e, 
				  0xbc81c8f4, 
				  0x3e2edb4f
				  ) ) > (z);
      return p2+single_constant<AA0, 0x3f22f983>()*log(a0)*j0(a0);
    }
    template < class AA0 > static inline AA0 branch2(const AA0 & a0)
    {
      typedef typename meta::scalar_of<AA0>::type sAA0; 
      AA0 q = rec(a0);
      AA0 w = sqrt(q); 
      AA0 p3 = w *
	horner< NT2_HORNER_COEFF_T(sAA0, 8,
				 (0xbd8c100e, 
				  0x3e3ef887, 
				  0xbe5ba616, 
				  0x3df54214, 
				  0xbb69539e, 
				  0xbd4b8bc1, 
				  0xb6612dc2, 
				  0x3f4c422a
				  ) ) > (q);
      w = sqr(q);
      AA0 xn =  q*
	horner< NT2_HORNER_COEFF_T(sAA0, 8,
				 (0x4201aee0, 
				  0xc2113945, 
				  0x418c7f6a, 
				  0xc09f3306, 
				  0x3f8040aa, 
				  0xbe46a57f, 
				  0x3d84ed6e, 
				  0xbdffff97
				  ) ) > (w)-Pio_4<AA0>();
      return sel(eq(a0, Inf<AA0>()), Zero<AA0>(), p3*nt2::sin(xn+a0)); 
    }
  };
} }

#endif
