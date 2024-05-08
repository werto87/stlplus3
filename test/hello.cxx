#include "stlplus/containers/containers.hpp"
#include "stlplus/containers/ntree.hpp"
#include <catch2/catch.hpp>

TEST_CASE ("hello", "[hello]") { 
        // 
        stlplus::ntree<int>{};
    REQUIRE (true); 
    }