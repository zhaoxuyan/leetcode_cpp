cmake_minimum_required(VERSION 3.17)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 14)
include_directories(
        ./
        ./utils/
)
#add_executable(leetcode_cpp main.cpp)
# 遍历项目根目录下所有的 .cpp 文件
file (GLOB_RECURSE files *.cpp)

foreach (file ${files})
    include_directories(${PROJECT_SOURCE_DIR}/test/)
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()