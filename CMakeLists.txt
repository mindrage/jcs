cmake_minimum_required(VERSION 3.7)


project("jcs")

include_directories(
        include/
)

set(JCS_FILES
    src/jcs.c
)

add_executable(jcs_tests ${JCS_FILES})