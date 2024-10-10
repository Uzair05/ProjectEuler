######## A simple cmakelists.txt file for OpenCV() #############  
cmake_minimum_required(VERSION 3.2)                            
PROJECT(main_ LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)

FIND_PACKAGE( OpenCV REQUIRED )                              
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(./include)

ADD_EXECUTABLE(main_ main.cpp)
TARGET_LINK_LIBRARIES (main_ ${OpenCV_LIBS})         
########### end ####################################  