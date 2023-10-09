set(STACK_SRC
    stack.h
    stack.cpp
)

# Declare the library
add_library(STACK_LIB STATIC
    ${STACK_SRC}
)

# Specify here the include directories exported
# by this library
target_include_directories(STACK_LIB PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)