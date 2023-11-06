cmake_minimum_required(VERSION 3.22.1)

set(This WaiterTests) # set project name

set(Sources
    WaiterTest.cpp
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