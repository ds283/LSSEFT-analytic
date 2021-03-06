CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(LSSEFT-analytic)

SET(CMAKE_CXX_STANDARD 14)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)
INCLUDE(BuildGiNaC)
INCLUDE(CompilerFlags)

# detect toolchain and set compiler flags appropriately
SET_COMPILER_FLAGS()

# RESOLVE DEPENDENCIES

# find required Boost libraries
FIND_PACKAGE(Boost 1.56 REQUIRED COMPONENTS timer date_time program_options filesystem)

# find GiNaC libraries
IF(NOT FORCE_BUILD_GINAC)
  FIND_PACKAGE(GiNaC)
ENDIF()

# handle non-standard external dependencies
ADD_CUSTOM_TARGET(DEPS ALL)
SET(EXTERNAL_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/thirdparty/dist")

IF(NOT GINAC_FOUND)
  # GiNaC was not found, so attempt to build it from source
  BUILD_CLN(${CMAKE_BINARY_DIR}/thirdparty/CLN ${EXTERNAL_INSTALL_PREFIX})
  BUILD_GINAC(${CMAKE_BINARY_DIR}/thirdparty/GiNaC ${CMAKE_BINARY_DIR}/thirdparty/CLN ${CLN_INCLUDE_DIRS} ${CLN_LIBRARY_DIRS} ${CLN_LIBRARIES} ${EXTERNAL_INSTALL_PREFIX})
ENDIF()


# add LSSEFT_analytic executable

ADD_EXECUTABLE(LSSEFT_analytic
  main.cpp
  backends/LSSEFT.cpp
  instruments/timing_instrument.cpp
  lib/fourier_kernel.cpp
  lib/initial_value.cpp
  lib/loop_integral.cpp
  lib/vector.cpp
  lib/Pk_one_loop.cpp
  lib/Pk_rsd.cpp
  lib/one_loop_reduced_integral.cpp
  lib/detail/contractions.cpp
  lib/detail/legendre_utils.cpp
  lib/detail/Rayleigh_momenta.cpp
  lib/detail/relabel_product.cpp
  lib/detail/special_functions.cpp
  services/argument_cache.cpp
  services/service_locator.cpp
  services/symbol_factory.cpp
  shared/error.cpp
  shared/exceptions.cpp
  SPT/one_loop_kernels.cpp
  SPT/time_functions.cpp
  utilities/formatter.cpp
  utilities/GiNaC_utils.cpp
  )

ADD_DEPENDENCIES(LSSEFT_analytic DEPS)

TARGET_LINK_LIBRARIES(LSSEFT_analytic ${GINAC_LIBRARIES} ${Boost_LIBRARIES})

TARGET_INCLUDE_DIRECTORIES(LSSEFT_analytic PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${GINAC_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  )


# add dummy target for CLion

SET(BACKEND_FILES
  backends/LSSEFT.cpp
  backends/LSSEFT.h
  )

SET(INSTRUMENTS_FILES
  instruments/timing_instrument.cpp
  instruments/timing_instrument.h
  )

SET(LIBRARY_FILES
  lib/fourier_kernel.cpp
  lib/fourier_kernel.h
  lib/vector.cpp
  lib/vector.h
  lib/initial_value.cpp
  lib/initial_value.h
  lib/Pk_one_loop.cpp
  lib/Pk_one_loop.h
  lib/Pk_rsd.cpp
  lib/Pk_rsd.h
  lib/loop_integral.cpp
  lib/loop_integral.h
  lib/one_loop_reduced_integral.cpp
  lib/one_loop_reduced_integral.h
  )

SET(LIBRARY_DETAIL_FILES
  lib/detail/contractions.cpp
  lib/detail/contractions.h
  lib/detail/relabel_product.cpp
  lib/detail/relabel_product.h
  lib/detail/Rayleigh_momenta.cpp
  lib/detail/Rayleigh_momenta.h
  lib/detail/special_functions.cpp
  lib/detail/special_functions.h
  lib/detail/legendre_utils.cpp
  lib/detail/legendre_utils.h
  )

SET(LOCALIZATIONS_FILES
  localizations/en/messages_en.h
  localizations/messages.h
  )

SET(SERVICES_FILES
  services/argument_cache.cpp
  services/argument_cache.h
  services/service_locator.cpp
  services/service_locator.h
  services/switches.h
  services/symbol_factory.cpp
  services/symbol_factory.h
  )

SET(SHARED_FILES
  shared/ansi_colour_codes.h
  shared/exceptions.cpp
  shared/exceptions.h
  shared/defaults.h
  shared/error.cpp
  shared/error.h
  shared/ansi_colour_codes.h
  shared/common.h
  )

SET(SPT_FILES
  SPT/time_functions.cpp
  SPT/time_functions.h
  SPT/one_loop_kernels.cpp
  SPT/one_loop_kernels.h
  )

SET(UTILITIES_FILES
  utilities/formatter.cpp
  utilities/formatter.h
  utilities/GiNaC_utils.cpp
  utilities/GiNaC_utils.h
  utilities/hash_combine.h
  )

SET(TOP_LEVEL_FILES
  main.cpp
  )

ADD_EXECUTABLE(clion_dummy_target
  ${BACKEND_FILES}
  ${INSTRUMENTS_FILES}
  ${LIBRARY_FILES}
  ${LIBRARY_DETAIL_FILES}
  ${LOCALIZATIONS_FILES}
  ${SERVICES_FILES}
  ${SHARED_FILES}
  ${SPT_FILES}
  ${UTILITIES_FILES}
  ${TOP_LEVEL_FILES}
  )
