//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DUAL_FUNCTION_SCALAR_SPLAT_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_FUNCTION_SCALAR_SPLAT_HPP_INCLUDED
#include <nt2/toolbox/dual/specific/interface.hpp>
#include <nt2/toolbox/dual/specific/dual_types.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::splat_, tag::cpu_,
                      (A0)(A1),
                      (dual_<real_<A0> > )
                      (target_< dual_<real_<A1> > >)
                     ); 

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call < tag::splat_(tag::dual_ <tag::real_>
              , tag::target_< tag::dual_ <tag::real_> >
              ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;

    template<class This,class A0, class Target>
    struct result<This(A0,Target)> : meta::strip<Target>::type {};

    NT2_FUNCTOR_CALL(2)
    {
      return a0; 
    }
  };
} }

#endif
