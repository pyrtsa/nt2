##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

SET( SOURCES
  allocator.cpp
  id.cpp
  index.cpp
  of_size.cpp
  size.cpp
# List of scalar test files for toolbox core.settings
   )

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set_property(SOURCE id.cpp PROPERTY COMPILE_FLAGS "-Wno-multichar")
endif()
nt2_module_add_tests(core.container.settings.unit ${SOURCES})
