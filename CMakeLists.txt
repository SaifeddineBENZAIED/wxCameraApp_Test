cmake_minimum_required(VERSION 3.10)
project(wxAppTest)

set(CMAKE_CXX_STANDARD 17)

find_package(wxWidgets REQUIRED COMPONENTS core base)
find_package(OpenCV REQUIRED)

include(${wxWidgets_USE_FILE})

add_executable(wxAppTest
    CameraPanel.cpp
    ScreenshotManager.cpp
    TwitterFetcher.cpp
    wxAppTestMain.cpp
    wxAppTestApp.cpp)

target_include_directories(wxAppTest PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(wxAppTest ${wxWidgets_LIBRARIES} ${OpenCV_LIBS})
