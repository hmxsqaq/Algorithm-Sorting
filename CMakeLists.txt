cmake_minimum_required(VERSION 3.28)
project(Algorithm_Sorting)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES
        "${CMAKE_SOURCE_DIR}/src/*.h"
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

set(DATA_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data)
set(DATA_DEST_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data)
add_custom_command(TARGET Algorithm_Sorting POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${DATA_SOURCE_DIR} ${DATA_DEST_DIR}
        COMMENT "Copying DATA directory to binary directory"
)
add_custom_target(copy_DATA ALL
        COMMAND ${CMAKE_COMMAND} -E echo "Copying DATA directory"
        DEPENDS Algorithm_Sorting
)
target_compile_definitions(Algorithm_Sorting PRIVATE
        DATA_PATH="${DATA_DEST_DIR}/"
)