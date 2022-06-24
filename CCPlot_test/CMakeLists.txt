cmake_minimum_required(VERSION 3.5)

project(CCPlot_test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets PrintSupport REQUIRED)

find_package(Matlab REQUIRED COMPONENTS MAT_LIBRARY ENG_LIBRARY MEX_COMPILER)

SET(QCustomPlot_Include_Dir D:/Dev/qcustomplot)
SET(QCustomPlot_SOURCE D:/Dev/qcustomplot/qcustomplot.cpp)
SET(Eigen3_Include_Dir D:/Dev/eigen)
SET(ccplot_lib D:/Code/CCplot/lib/libccplot.lib)

SET(QMatlab_include_dir D:/Code/QMatlab/include)
SET(QMatlab_lib D:/Code/QMatlab/lib/LibQMatlab.lib)

include_directories(
    ${Matlab_INCLUDE_DIRS}
                    D:/Code/CCplot/source/base
                    D:/Code/CCplot/source/dialog
                    D:/Code/CCplot/source/prop
                    ${QCustomPlot_Include_Dir}
                    ${QMatlab_include_dir}
                    ${QMatlab_include_dir}
                    ${Eigen3_Include_Dir}
                    )



set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
        ${ccplot_header}
        D:/Code/CCplot/source/resource.qrc
)

file(GLOB_RECURSE PROJECT_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/source/*.*
    ${ccplot_header}
    D:/Code/CCplot/source/resource.qrc)



link_directories(${ccplot_lib})
link_directories(${QMatlab_lib})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CCPlot_test
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CCPlot_test APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CCPlot_test SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CCPlot_test
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(CCPlot_test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    ${ccplot_lib}
    ${QMatlab_lib}
    ${Matlab_MAT_LIBRARY}
    ${Matlab_MEX_LIBRARY}
    ${Matlab_MX_LIBRARY}
    ${Matlab_ENG_LIBRARY}
    Qt${QT_VERSION_MAJOR}::PrintSupport)

set_target_properties(CCPlot_test PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CCPlot_test)
endif()
