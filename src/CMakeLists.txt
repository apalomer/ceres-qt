set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Ceres cost function
add_library(quadraticcostfunction SHARED quadraticcostfunction.cpp)

# Ceres iteration
add_library(iteratorviewer SHARED iteratorviewer.cpp iteratorviewer.h)
target_link_libraries(iteratorviewer Qt5::Core Qt5::Widgets ceres)

# Worker
add_library(worker SHARED worker.cpp worker.h)
target_link_libraries(worker Qt5::Core Qt5::Widgets ceres iteratorviewer quadraticcostfunction)

# Main widget
add_library(quadraticsolver SHARED quadraticsolver.cpp quadraticsolver.h quadraticsolver.ui)
target_link_libraries(quadraticsolver Qt5::Core Qt5::Widgets worker)

# App
add_executable(main main.cpp)
target_link_libraries(main Qt5::Core Qt5::Widgets quadraticsolver)
