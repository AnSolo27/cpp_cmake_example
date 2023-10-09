set(LL_SRC
    linked_list.h
    linked_list.cpp
)

# Declare the library
add_library(LL_LIB STATIC
    ${LL_SRC}
)

# Specify here the include directories exported
# by this library
target_include_directories(LL_LIB PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)