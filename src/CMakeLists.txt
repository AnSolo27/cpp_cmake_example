
# Sources

add_executable (main main.cpp)

# Add header directories (AFTER add_executable !!)

# Compiler and linker options
target_compile_options(main PRIVATE
    ${CPU_PARAMETERS}
    -Wall
    -Wextra
    -Wpedantic
    -Wno-unused-parameter
    $<$<COMPILE_LANGUAGE:CXX>:
        -Wno-volatile
        -Wold-style-cast
        -Wuseless-cast
        -Wsuggest-override>
    $<$<CONFIG:Debug>:-Og -g3 -ggdb>
    $<$<CONFIG:Release>:-Os -g0>)

target_link_options(main PRIVATE)

add_subdirectory(linked_list)
add_subdirectory(stack)
add_subdirectory(queue)

target_link_libraries (main STACK_LIB LL_LIB QUEUE_LIB)
