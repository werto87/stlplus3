

##
## Copyright (c) 2024 Waldemar Schneider (w-schneider1987 at web dot de)
##
## Distributed under the Boost Software License, Version 1.0.
## (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


add_library(stlplus)

add_subdirectory(containers)
add_subdirectory(persistence)
add_subdirectory(portability)
add_subdirectory(strings)
add_subdirectory(subsystems)

target_include_directories(stlplus
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
)

target_compile_features(stlplus PUBLIC cxx_std_20)

set_target_properties(
        stlplus
        PROPERTIES VERSION ${PROJECT_VERSION}
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN YES
)

install(TARGETS stlplus DESTINATION lib)
