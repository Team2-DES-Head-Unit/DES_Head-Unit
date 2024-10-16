cmake_minimum_required(VERSION 3.5)
project(HelloWorldClient)

# C++11 표준 사용
set(CMAKE_CXX_STANDARD 11)

# vsomeip 헤더 파일 포함
include_directories("/usr/local/include/vsomeip")

# HelloWorldClient.cpp 파일로 실행 파일 생성
add_executable(HelloWorldClient HelloWorldClient.cpp)

# vsomeip 라이브러리와 pthread 라이브러리 링크
target_link_libraries(HelloWorldClient /usr/local/lib/libvsomeip3.so pthread)

