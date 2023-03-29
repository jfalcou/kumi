##==================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##==================================================================================================

##==================================================================================================
## Add Doxygen building target
##==================================================================================================
find_package(Doxygen QUIET)

if (DOXYGEN_FOUND)
  message( STATUS "[kumi] Doxygen available")
else (DOXYGEN_FOUND)
  message( STATUS "[kumi] Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)


if (DOXYGEN_FOUND)
  set(DOXYGEN_CONFIG ${PROJECT_SOURCE_DIR}/doc/Doxyfile)
  add_custom_target ( doxygen
                      COMMAND KUMI_DOXYGEN_OUPUT=${PROJECT_BINARY_DIR}/docs ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIG}
                      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/doc
                      COMMENT "[kumi] Generating API documentation with Doxygen - Local version"
                      VERBATIM
                    )
endif (DOXYGEN_FOUND)
