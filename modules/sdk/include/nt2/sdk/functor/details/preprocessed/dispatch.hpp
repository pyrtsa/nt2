//==============================================================================
// Local macro to generate the fall-through dispatch overload
// What the fuck with adl_helper ? Well, as pointed out by Johannes Schaub
// it is mandated by the standard so ADL kicks in on resolving calls to
// dispatching without having to order them BEFORE the actual dispatch_call
// class definitions. Without it, the whole system brittles.
//==============================================================================
//==============================================================================
// Actual dispatching mechanism implementation
//==============================================================================
namespace nt2 { namespace meta
{
  struct adl_helper {};
  //============================================================================
  // Default dispatch overload set for catching calls to unsupported functor
  // overload or unregistered types.
  //============================================================================
  template<class Tag, class Site, class A0> NT2_FORCE_INLINE nt2::meta::implement<Tag(tag::unknown_),Site,tag::error_with(typename meta::hierarchy_of<A0>::type)> dispatching ( Tag const&, meta::unknown_<Site> const&, meta::unknown_<A0> const& , adl_helper = adl_helper() ) { nt2::meta::implement< Tag(tag::unknown_),Site , tag::error_with(typename meta::hierarchy_of<A0>::type) > that; return that; } template<class Tag, class Site, class A0 , class A1> NT2_FORCE_INLINE nt2::meta::implement<Tag(tag::unknown_),Site,tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type)> dispatching ( Tag const&, meta::unknown_<Site> const&, meta::unknown_<A0> const& , meta::unknown_<A1> const& , adl_helper = adl_helper() ) { nt2::meta::implement< Tag(tag::unknown_),Site , tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type) > that; return that; } template<class Tag, class Site, class A0 , class A1 , class A2> NT2_FORCE_INLINE nt2::meta::implement<Tag(tag::unknown_),Site,tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type)> dispatching ( Tag const&, meta::unknown_<Site> const&, meta::unknown_<A0> const& , meta::unknown_<A1> const& , meta::unknown_<A2> const& , adl_helper = adl_helper() ) { nt2::meta::implement< Tag(tag::unknown_),Site , tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type) > that; return that; } template<class Tag, class Site, class A0 , class A1 , class A2 , class A3> NT2_FORCE_INLINE nt2::meta::implement<Tag(tag::unknown_),Site,tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type , typename meta::hierarchy_of<A3>::type)> dispatching ( Tag const&, meta::unknown_<Site> const&, meta::unknown_<A0> const& , meta::unknown_<A1> const& , meta::unknown_<A2> const& , meta::unknown_<A3> const& , adl_helper = adl_helper() ) { nt2::meta::implement< Tag(tag::unknown_),Site , tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type , typename meta::hierarchy_of<A3>::type) > that; return that; } template<class Tag, class Site, class A0 , class A1 , class A2 , class A3 , class A4> NT2_FORCE_INLINE nt2::meta::implement<Tag(tag::unknown_),Site,tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type , typename meta::hierarchy_of<A3>::type , typename meta::hierarchy_of<A4>::type)> dispatching ( Tag const&, meta::unknown_<Site> const&, meta::unknown_<A0> const& , meta::unknown_<A1> const& , meta::unknown_<A2> const& , meta::unknown_<A3> const& , meta::unknown_<A4> const& , adl_helper = adl_helper() ) { nt2::meta::implement< Tag(tag::unknown_),Site , tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type , typename meta::hierarchy_of<A3>::type , typename meta::hierarchy_of<A4>::type) > that; return that; }
} }
//==============================================================================
// Local macro to generate the dispatch selector
//==============================================================================
/**/
namespace nt2 { namespace meta
{
  //==============================================================================
  // dispatch_call finds the proper call overload for evaluating a given
  // functor over a set of types on a given site
  //==============================================================================
  template<class Sig, class Site> struct dispatch_call; 
  template<class Tag, class A0, class Site> struct dispatch_call<Tag(A0), Site> { NT2_DECLTYPE ( dispatching ( Tag(), Site(), typename meta::hierarchy_of<A0>::type(), adl_helper() ) , type ); }; template<class Tag, class A0, class Site> NT2_FORCE_INLINE typename boost::mpl:: identity< typename dispatch_call< Tag(A0) , Site >::type >::type dispatch( Tag const&, Site const& , BOOST_PP_ENUM_BINARY_PARAMS( 1,const A, & a) ) { typename dispatch_call<Tag(A0), Site>::type that; return that; } template<class Tag, class A0 , class A1, class Site> struct dispatch_call<Tag(A0 , A1), Site> { NT2_DECLTYPE ( dispatching ( Tag(), Site(), typename meta::hierarchy_of<A0>::type() , typename meta::hierarchy_of<A1>::type(), adl_helper() ) , type ); }; template<class Tag, class A0 , class A1, class Site> NT2_FORCE_INLINE typename boost::mpl:: identity< typename dispatch_call< Tag(A0 , A1) , Site >::type >::type dispatch( Tag const&, Site const& , BOOST_PP_ENUM_BINARY_PARAMS( 2,const A, & a) ) { typename dispatch_call<Tag(A0 , A1), Site>::type that; return that; } template<class Tag, class A0 , class A1 , class A2, class Site> struct dispatch_call<Tag(A0 , A1 , A2), Site> { NT2_DECLTYPE ( dispatching ( Tag(), Site(), typename meta::hierarchy_of<A0>::type() , typename meta::hierarchy_of<A1>::type() , typename meta::hierarchy_of<A2>::type(), adl_helper() ) , type ); }; template<class Tag, class A0 , class A1 , class A2, class Site> NT2_FORCE_INLINE typename boost::mpl:: identity< typename dispatch_call< Tag(A0 , A1 , A2) , Site >::type >::type dispatch( Tag const&, Site const& , BOOST_PP_ENUM_BINARY_PARAMS( 3,const A, & a) ) { typename dispatch_call<Tag(A0 , A1 , A2), Site>::type that; return that; } template<class Tag, class A0 , class A1 , class A2 , class A3, class Site> struct dispatch_call<Tag(A0 , A1 , A2 , A3), Site> { NT2_DECLTYPE ( dispatching ( Tag(), Site(), typename meta::hierarchy_of<A0>::type() , typename meta::hierarchy_of<A1>::type() , typename meta::hierarchy_of<A2>::type() , typename meta::hierarchy_of<A3>::type(), adl_helper() ) , type ); }; template<class Tag, class A0 , class A1 , class A2 , class A3, class Site> NT2_FORCE_INLINE typename boost::mpl:: identity< typename dispatch_call< Tag(A0 , A1 , A2 , A3) , Site >::type >::type dispatch( Tag const&, Site const& , BOOST_PP_ENUM_BINARY_PARAMS( 4,const A, & a) ) { typename dispatch_call<Tag(A0 , A1 , A2 , A3), Site>::type that; return that; } template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4, class Site> struct dispatch_call<Tag(A0 , A1 , A2 , A3 , A4), Site> { NT2_DECLTYPE ( dispatching ( Tag(), Site(), typename meta::hierarchy_of<A0>::type() , typename meta::hierarchy_of<A1>::type() , typename meta::hierarchy_of<A2>::type() , typename meta::hierarchy_of<A3>::type() , typename meta::hierarchy_of<A4>::type(), adl_helper() ) , type ); }; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4, class Site> NT2_FORCE_INLINE typename boost::mpl:: identity< typename dispatch_call< Tag(A0 , A1 , A2 , A3 , A4) , Site >::type >::type dispatch( Tag const&, Site const& , BOOST_PP_ENUM_BINARY_PARAMS( 5,const A, & a) ) { typename dispatch_call<Tag(A0 , A1 , A2 , A3 , A4), Site>::type that; return that; }
} }
