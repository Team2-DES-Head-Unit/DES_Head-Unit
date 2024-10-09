cmake_minimum_required(VERSION 3.5)

project(IC_TEST LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt5 COMPONENTS Core Gui OpenGL REQUIRED)

if(ANDROID)
    add_library(IC_TEST SHARED
      main.cpp
      qml.qrc
      Gauge.cpp
    )
else()
    add_executable(IC_TEST
      main.cpp
      qml.qrc
      Gauge.cpp

      DateClock.h
      receiver.h
      receiver.cpp
      Weather.h
      Gauge.h
      get_battery.h
      get_battery.cpp

    )
endif()

target_compile_definitions(IC_TEST
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(IC_TEST
  PRIVATE Qt5::Core Qt5::Quick)
