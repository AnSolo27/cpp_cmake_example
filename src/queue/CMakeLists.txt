set(QUEUE_SRC
    queue.h
    queue.cpp
)

# Declare the library
add_library(QUEUE_LIB STATIC
    ${QUEUE_SRC}
)

# Specify here the include directories exported
# by this library
target_include_directories(QUEUE_LIB PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)