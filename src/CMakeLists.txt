cmake_minimum_required(VERSION 3.5)
project(HelloWorldClient)

# C++11 표준 사용
set(CMAKE_CXX_STANDARD 11)

# vsomeip 라이브러리와 Boost 라이브러리 찾기
find_package(vsomeip REQUIRED)
find_package(Threads REQUIRED)

# vsomeip 헤더 파일 포함
include_directories(${vsomeip_INCLUDE_DIRS})

# HelloWorldClient.cpp 파일로 실행 파일 생성
add_executable(HelloWorldClient HelloWorldClient.cpp)

# vsomeip 라이브러리와 pthread 라이브러리 링크
target_link_libraries(HelloWorldClient ${vsomeip_LIBRARIES} Threads::Threads)
