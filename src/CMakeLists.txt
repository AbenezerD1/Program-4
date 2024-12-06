add_executable(${PROJECT_NAME} driver.cpp)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

configure_file(${CMAKE_SOURCE_DIR}/src/datafiles/data4movies.txt ${CMAKE_BINARY_DIR}/src/datafiles/data4movies.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/src/datafiles/data4customers.txt ${CMAKE_BINARY_DIR}/src/datafiles/data4customers.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/src/datafiles/data4commands.txt ${CMAKE_BINARY_DIR}/src/datafiles/data4commands.txt COPYONLY)

FILE(GLOB ProblemSource *.cpp) # problem 2 template files don't need to be compiled here
add_library(program4_functions STATIC ${ProblemSource})

target_link_libraries(${PROJECT_NAME} program4_functions)

add_test(
        NAME
        main
        COMMAND
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}
)