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
namespace boost { namespace dispatch { namespace meta
{
  struct adl_helper {};
  //============================================================================
  // Default dispatch overload set for catching calls to unsupported functor
  // overload or unregistered types.
  //============================================================================
  template<class Tag, class Site, class A0> BOOST_FORCEINLINE boost::dispatch::meta:: implement<Tag(tag::unknown_),Site,tag::error_with(typename meta::hierarchy_of<A0>::type)> dispatching ( Tag, meta::unknown_<Site>, meta::unknown_<A0> , adl_helper = adl_helper() ) { boost::dispatch::meta::implement< Tag(tag::unknown_),Site , tag::error_with(typename meta::hierarchy_of<A0>::type) > that; return that; } template<class Tag, class Site, class A0 , class A1> BOOST_FORCEINLINE boost::dispatch::meta:: implement<Tag(tag::unknown_),Site,tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type)> dispatching ( Tag, meta::unknown_<Site>, meta::unknown_<A0> , meta::unknown_<A1> , adl_helper = adl_helper() ) { boost::dispatch::meta::implement< Tag(tag::unknown_),Site , tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type) > that; return that; } template<class Tag, class Site, class A0 , class A1 , class A2> BOOST_FORCEINLINE boost::dispatch::meta:: implement<Tag(tag::unknown_),Site,tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type)> dispatching ( Tag, meta::unknown_<Site>, meta::unknown_<A0> , meta::unknown_<A1> , meta::unknown_<A2> , adl_helper = adl_helper() ) { boost::dispatch::meta::implement< Tag(tag::unknown_),Site , tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type) > that; return that; } template<class Tag, class Site, class A0 , class A1 , class A2 , class A3> BOOST_FORCEINLINE boost::dispatch::meta:: implement<Tag(tag::unknown_),Site,tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type , typename meta::hierarchy_of<A3>::type)> dispatching ( Tag, meta::unknown_<Site>, meta::unknown_<A0> , meta::unknown_<A1> , meta::unknown_<A2> , meta::unknown_<A3> , adl_helper = adl_helper() ) { boost::dispatch::meta::implement< Tag(tag::unknown_),Site , tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type , typename meta::hierarchy_of<A3>::type) > that; return that; } template<class Tag, class Site, class A0 , class A1 , class A2 , class A3 , class A4> BOOST_FORCEINLINE boost::dispatch::meta:: implement<Tag(tag::unknown_),Site,tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type , typename meta::hierarchy_of<A3>::type , typename meta::hierarchy_of<A4>::type)> dispatching ( Tag, meta::unknown_<Site>, meta::unknown_<A0> , meta::unknown_<A1> , meta::unknown_<A2> , meta::unknown_<A3> , meta::unknown_<A4> , adl_helper = adl_helper() ) { boost::dispatch::meta::implement< Tag(tag::unknown_),Site , tag::error_with(typename meta::hierarchy_of<A0>::type , typename meta::hierarchy_of<A1>::type , typename meta::hierarchy_of<A2>::type , typename meta::hierarchy_of<A3>::type , typename meta::hierarchy_of<A4>::type) > that; return that; }
} } }
//==============================================================================
// Local macro to generate the dispatch selector
//==============================================================================
/**/
namespace boost { namespace dispatch { namespace meta
{
  //==============================================================================
  // dispatch_call finds the proper call overload for evaluating a given
  // functor over a set of types on a given site
  //==============================================================================
  template<class Sig, class Site> struct dispatch_call; 
  template<class Tag, class A0, class Site> struct dispatch_call<Tag(A0), Site> { BOOST_DISPATCH_DECLTYPE ( dispatching ( Tag(), Site(), (typename meta::hierarchy_of<A0>::type()), adl_helper() ) , type ); }; template<class Tag, class A0, class Site> BOOST_FORCEINLINE typename boost::mpl:: identity< typename dispatch_call< Tag(A0) , Site >::type >::type dispatch( Tag, Site , const A0 & ) { typename dispatch_call<Tag(A0), Site>::type that; return that; } template<class Tag, class A0 , class A1, class Site> struct dispatch_call<Tag(A0 , A1), Site> { BOOST_DISPATCH_DECLTYPE ( dispatching ( Tag(), Site(), (typename meta::hierarchy_of<A0>::type()) , (typename meta::hierarchy_of<A1>::type()), adl_helper() ) , type ); }; template<class Tag, class A0 , class A1, class Site> BOOST_FORCEINLINE typename boost::mpl:: identity< typename dispatch_call< Tag(A0 , A1) , Site >::type >::type dispatch( Tag, Site , const A0 & , const A1 & ) { typename dispatch_call<Tag(A0 , A1), Site>::type that; return that; } template<class Tag, class A0 , class A1 , class A2, class Site> struct dispatch_call<Tag(A0 , A1 , A2), Site> { BOOST_DISPATCH_DECLTYPE ( dispatching ( Tag(), Site(), (typename meta::hierarchy_of<A0>::type()) , (typename meta::hierarchy_of<A1>::type()) , (typename meta::hierarchy_of<A2>::type()), adl_helper() ) , type ); }; template<class Tag, class A0 , class A1 , class A2, class Site> BOOST_FORCEINLINE typename boost::mpl:: identity< typename dispatch_call< Tag(A0 , A1 , A2) , Site >::type >::type dispatch( Tag, Site , const A0 & , const A1 & , const A2 & ) { typename dispatch_call<Tag(A0 , A1 , A2), Site>::type that; return that; } template<class Tag, class A0 , class A1 , class A2 , class A3, class Site> struct dispatch_call<Tag(A0 , A1 , A2 , A3), Site> { BOOST_DISPATCH_DECLTYPE ( dispatching ( Tag(), Site(), (typename meta::hierarchy_of<A0>::type()) , (typename meta::hierarchy_of<A1>::type()) , (typename meta::hierarchy_of<A2>::type()) , (typename meta::hierarchy_of<A3>::type()), adl_helper() ) , type ); }; template<class Tag, class A0 , class A1 , class A2 , class A3, class Site> BOOST_FORCEINLINE typename boost::mpl:: identity< typename dispatch_call< Tag(A0 , A1 , A2 , A3) , Site >::type >::type dispatch( Tag, Site , const A0 & , const A1 & , const A2 & , const A3 & ) { typename dispatch_call<Tag(A0 , A1 , A2 , A3), Site>::type that; return that; } template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4, class Site> struct dispatch_call<Tag(A0 , A1 , A2 , A3 , A4), Site> { BOOST_DISPATCH_DECLTYPE ( dispatching ( Tag(), Site(), (typename meta::hierarchy_of<A0>::type()) , (typename meta::hierarchy_of<A1>::type()) , (typename meta::hierarchy_of<A2>::type()) , (typename meta::hierarchy_of<A3>::type()) , (typename meta::hierarchy_of<A4>::type()), adl_helper() ) , type ); }; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4, class Site> BOOST_FORCEINLINE typename boost::mpl:: identity< typename dispatch_call< Tag(A0 , A1 , A2 , A3 , A4) , Site >::type >::type dispatch( Tag, Site , const A0 & , const A1 & , const A2 & , const A3 & , const A4 & ) { typename dispatch_call<Tag(A0 , A1 , A2 , A3 , A4), Site>::type that; return that; }
} } }
