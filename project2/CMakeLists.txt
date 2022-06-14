cmake_minimum_required(VERSION 3.14)
project(project2)

set(CMAKE_CXX_STANDARD 17)

add_executable(project2 main.cpp JSONParser.cpp JSONParser.hpp JSONToken.cpp JSONToken.hpp JSONTokenizer.cpp JSONTokenizer.hpp Pair.cpp Pair.hpp Entity.cpp Entity.hpp EntityInstance.cpp EntityInstance.hpp )