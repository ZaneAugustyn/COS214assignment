cmake_minimum_required(VERSION 3.16)

set(This <put name>) # set project name

set(Sources
    <put name>
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