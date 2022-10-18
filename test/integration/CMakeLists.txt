##==================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##==================================================================================================

# Extract HEAD from git
find_package(Git REQUIRED)
execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
    OUTPUT_VARIABLE kumi_git_head
    RESULT_VARIABLE _git_error
    OUTPUT_STRIP_TRAILING_WHITESPACE)

if(NOT _git_error STREQUAL "0")
    message(SEND_ERROR
        "Failed to extract KUMI's current git commit for integration tests: ${_git_error}")
    return()
endif()


# Builds and tests a separate project as an KUMI test
function(kumi_build_and_ctest project_name)
  string(REPLACE "-test" "" test_name "integration.${project_name}.exe")

  add_test(
    NAME ${test_name}
    COMMAND
    "${CMAKE_CTEST_COMMAND}"
    --verbose
    --output-on-failure
    --build-generator "${CMAKE_GENERATOR}"
    --build-and-test
      "${CMAKE_CURRENT_SOURCE_DIR}/${project_name}"
      "${CMAKE_CURRENT_BINARY_DIR}/${project_name}"
    --build-options ${ARGN}
    --test-command "${CMAKE_CTEST_COMMAND}")
endfunction()


##==================================================================================================
## Create Integration Tests
##==================================================================================================

## ===== CPM =====
kumi_build_and_ctest(cpm-test
    "-Dkumi_git_head=${kumi_git_head}"
    "-Dkumi_SOURCE_DIR=${kumi_SOURCE_DIR}"
    # cpm-test internally sets KUMI_* configure options
)

## ===== Fetch =====
kumi_build_and_ctest(fetch-test
    "-Dkumi_git_head=${kumi_git_head}"
    "-Dkumi_SOURCE_DIR=${kumi_SOURCE_DIR}"
    "-DKUMI_BUILD_TEST=OFF"
    "-DKUMI_BUILD_DOCUMENTATION=OFF"
)

## ===== Install =====
# install kumi as its own test and for 'install-test' to find
set(kumi_ROOT "${PROJECT_BINARY_DIR}/test/integration/install")
add_test(
  NAME integration.install-kumi.exe
  COMMAND
  "${CMAKE_COMMAND}"
  --install "${PROJECT_BINARY_DIR}"
  --verbose
  --prefix  "${kumi_ROOT}")

kumi_build_and_ctest(install-test "-Dkumi_ROOT=${kumi_ROOT}")
set_tests_properties(integration.install.exe PROPERTIES DEPENDS integration.install-kumi.exe)

## ==== Aggregated ====
add_custom_target(integration
  COMMAND
  "${CMAKE_CTEST_COMMAND}"
  --test-dir "${PROJECT_BINARY_DIR}"
  --output-on-failure
  -R integration\.[a-z-]+\.exe)
