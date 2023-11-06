cmake_minimum_required(VERSION 3.16)

set(This ZaneTesting) # set project name

set(Sources
    ZaneTesting.cpp
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