##==================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##==================================================================================================
include(GNUInstallDirs)
set(MAIN_DEST     "${CMAKE_INSTALL_LIBDIR}/kumi-${PROJECT_VERSION}")
set(INSTALL_DEST  "${CMAKE_INSTALL_INCLUDEDIR}/kumi-${PROJECT_VERSION}")
set(DOC_DEST      "${CMAKE_INSTALL_DOCDIR}-${PROJECT_VERSION}")

## =================================================================================================
## Exporting target for external use
## =================================================================================================
add_library(kumi_lib INTERFACE)
target_include_directories( kumi_lib INTERFACE
                            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                            $<INSTALL_INTERFACE:${INSTALL_DEST}>
                          )
target_compile_features(kumi_lib INTERFACE cxx_std_20)
set_target_properties(kumi_lib PROPERTIES EXPORT_NAME kumi)
add_library(kumi::kumi ALIAS kumi_lib)

## =================================================================================================
## Install target with versioned folder
## =================================================================================================
install(TARGETS   kumi_lib EXPORT kumi-targets DESTINATION "${MAIN_DEST}")
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/kumi               DESTINATION "${INSTALL_DEST}" )
install(FILES     ${PROJECT_SOURCE_DIR}/cmake/kumi-config.cmake    DESTINATION "${MAIN_DEST}"    )
install(FILES     ${PROJECT_SOURCE_DIR}/LICENSE.md                DESTINATION "${DOC_DEST}"     )
install(EXPORT    kumi-targets NAMESPACE "kumi::" DESTINATION "${MAIN_DEST}")
