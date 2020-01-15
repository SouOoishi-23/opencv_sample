cmake_minimum_required(VERSION 3.15)
project(zemi_opencv)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    #    link_directories (${OpenCV_LIBS})
    message(STATUS "OpenCV version: ${OpenCV_VERSION}")
    message(STATUS "OpenCV libraries : ${OpenCV_LIBS}")
    message(STATUS "OpenCV directory : ${OpenCV_INCLUDE_DIRS}")
    link_libraries(${OpenCV_LIBS})
else()
    message(WARNING "Could not find OpenCV.")
endif()


add_executable(zemi_opencv main.cpp include.h)
target_link_libraries(zemi_opencv ${OpenCV_LIBS})
