cmake_minimum_required(VERSION 3.16)

project(IC_TEST VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick) #qt5로 변경

qt_standard_project_setup(REQUIRES 6.5) #qt5로 변경

qt_add_executable(appIC_TEST
    main.cpp
)

qt_add_qml_module(appIC_TEST
    URI IC_TEST
    VERSION 1.0
    QML_FILES
        Main.qml
        RESOURCES qml_t.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appIC_TEST PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appIC_TEST
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appIC_TEST #qt5로 변
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appIC_TEST
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
