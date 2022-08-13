add_executable(custom_deleter custom_deleter.cpp)
add_executable(ctor_exception ctor_exception.cpp)
add_executable(inheritance inheritance.cpp)

add_executable(thread thread.cpp)
target_link_libraries(thread pthread)

add_executable(cv cv.cpp)
target_link_libraries(cv pthread)

