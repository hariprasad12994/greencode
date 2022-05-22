add_executable(thread thread.cpp)
target_link_libraries(thread pthread)

add_executable(cv cv.cpp)
target_link_libraries(cv pthread)
