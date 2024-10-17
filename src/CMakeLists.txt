cmake_minimum_required(VERSION 3.5)
project(HelloWorldClient)

# C++11 표준 사용
set(CMAKE_CXX_STANDARD 11)

# pkg-config를 사용하여 vsomeip 헤더 및 라이브러리 경로 자동 검색
find_package(PkgConfig REQUIRED)
pkg_check_modules(VSOMEIP REQUIRED vsomeip3)

# vsomeip 헤더 파일 포함
include_directories(${VSOMEIP_INCLUDE_DIRS})

# HelloWorldClient.cpp 파일로 실행 파일 생성
add_executable(HelloWorldClient client.cpp)

# vsomeip 라이브러리와 pthread 라이브러리 링크
target_link_libraries(HelloWorldClient ${VSOMEIP_LIBRARIES} pthread)
