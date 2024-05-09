cmake_minimum_required(VERSION 3.15.7)
if (NOT DEFINED CMAKE_CXX_STANDARD) # Only set the cxx_standard if it is not set by someone else
    set(CMAKE_CXX_STANDARD 20)
endif ()
project(
        myproject
        VERSION 0.0.1
        LANGUAGES CXX C)
include(cmake/PreventInSourceBuilds.cmake)
include(ProjectOptions.cmake)
myproject_setup_options()
myproject_local_options()
target_compile_features(myproject_options INTERFACE cxx_std_${CMAKE_CXX_STANDARD})
add_library(myproject::myproject_options ALIAS myproject_options)
add_library(myproject::myproject_warnings ALIAS myproject_warnings)
add_subdirectory(stlplus)
OPTION(BUILD_TESTS "enable tests" OFF)
IF (BUILD_TESTS)
    add_executable(bitset_test tests/bitset_test/bitset_test.cpp)
    add_executable(bool_vector_test tests/bool_vector_test/bool_vector_test.cpp)
    add_executable(callback_test tests/callback_test/callback_test.cpp)
    add_executable(cstring_test tests/cstring_test/cstring_test.cpp)
    add_executable(deque_test tests/deque_test/deque_test.cpp)
    add_executable(digraph_test tests/digraph_test/digraph_test.cpp)
    add_executable(edge_test tests/edge_test/edge_test.cpp)
    add_executable(edge_vector_test tests/edge_vector_test/edge_vector_test.cpp)
    add_executable(hash_test tests/hash_test/hash_test.cpp)
    add_executable(inf_test tests/inf_test/inf_test.cpp)
    add_executable(ini_manager_test tests/ini_manager_test/ini_manager_test.cpp)
    add_executable(interface_test tests/interface_test/interface_test.cpp)
    add_executable(list_test tests/list_test/list_test.cpp)
    add_executable(map_test tests/map_test/map_test.cpp)
    add_executable(matrix_test tests/matrix_test/matrix_test.cpp)
    add_executable(ntree_test tests/ntree_test/ntree_test.cpp)
    add_executable(point_test tests/point_test/point_test.cpp)
    add_executable(set_test tests/set_test/set_test.cpp)
    add_executable(shared_ptr_test tests/shared_ptr_test/shared_ptr_test.cpp)
    add_executable(simple_ptr_test tests/simple_ptr_test/simple_ptr_test.cpp)
    add_executable(smart_ptr_test tests/smart_ptr_test/smart_ptr_test.cpp)
    add_executable(string_test tests/string_test/string_test.cpp)
    add_executable(subprocess_test tests/subprocess_test/subprocess_test.cpp)
    add_executable(tcp_test tests/tcp_test/tcp_test.cpp)
    add_executable(traffic_light_test tests/traffic_light_test/traffic_light_test.cpp)
    add_executable(udp_test tests/udp_test/udp_test.cpp)
    target_link_libraries(bitset_test PRIVATE stlplus)
    target_link_libraries(bool_vector_test PRIVATE stlplus)
    target_link_libraries(callback_test PRIVATE stlplus)
    target_link_libraries(cstring_test PRIVATE stlplus)
    target_link_libraries(deque_test PRIVATE stlplus)
    target_link_libraries(digraph_test PRIVATE stlplus)
    target_link_libraries(edge_test PRIVATE stlplus)
    target_link_libraries(edge_vector_test PRIVATE stlplus)
    target_link_libraries(hash_test PRIVATE stlplus)
    target_link_libraries(inf_test PRIVATE stlplus)
    target_link_libraries(ini_manager_test PRIVATE stlplus)
    target_link_libraries(interface_test PRIVATE stlplus)
    target_link_libraries(list_test PRIVATE stlplus)
    target_link_libraries(map_test PRIVATE stlplus)
    target_link_libraries(matrix_test PRIVATE stlplus)
    target_link_libraries(ntree_test PRIVATE stlplus)
    target_link_libraries(point_test PRIVATE stlplus)
    target_link_libraries(set_test PRIVATE stlplus)
    target_link_libraries(shared_ptr_test PRIVATE stlplus)
    target_link_libraries(simple_ptr_test PRIVATE stlplus)
    target_link_libraries(smart_ptr_test PRIVATE stlplus)
    target_link_libraries(string_test PRIVATE stlplus)
    target_link_libraries(subprocess_test PRIVATE stlplus)
    target_link_libraries(tcp_test PRIVATE stlplus)
    target_link_libraries(traffic_light_test PRIVATE stlplus)
    target_link_libraries(udp_test PRIVATE stlplus)
ENDIF (BUILD_TESTS)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(copy_compile_commands_json ALL
                  DEPENDS ${CMAKE_SOURCE_DIR}/compile_commands.json)

add_custom_command(
  DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
  OUTPUT ${CMAKE_SOURCE_DIR}/compile_commands.json
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/compile_commands.json
          ${CMAKE_SOURCE_DIR}/compile_commands.json
  COMMENT
    "copy compile_commands.json build to compile_commands.json project root so tools can find it more easily"
)












































