cmake_minimum_required(VERSION 3.16)

set(This OrderTests) # set project name

set(Sources
    OrderTest.cpp
)

add_executable(${This} ${Sources}) # add executable - making program from sources

target_link_libraries(${This} PUBLIC
    gtest_main # provided by googletest
    UnitTesting
)

add_test(
    NAME ${This}
    COMMAND ${This}
) 