# Ceres cost function
add_library(quadraticcostfunction SHARED quadraticcostfunction.cpp)

# Ceres iteration
QT4_WRAP_CPP(iteratorviewer_moc   iteratorviewer.h)
add_library(iteratorviewer SHARED iteratorviewer.cpp ${iteratorviewer_moc})
target_link_libraries(iteratorviewer ${QT_LIBRARIES} ceres)

# Worker
QT4_WRAP_CPP(worker_moc   worker.h)
add_library(worker SHARED worker.cpp ${worker_moc})
target_link_libraries(worker ${QT_LIBRARIES} ceres iteratorviewer quadraticcostfunction)

# Main widget
QT4_WRAP_CPP(quadraticsolver_moc quadraticsolver.h)
QT4_WRAP_UI(quadraticsolver_ui quadraticsolver.ui)
add_library(quadraticsolver SHARED quadraticsolver.cpp ${quadraticsolver_moc} ${quadraticsolver_ui})
target_link_libraries(quadraticsolver ${QT_LIBRARIES} worker)

# App
add_executable(main main.cpp)
target_link_libraries(main ${QT_LIBRARIES} quadraticsolver)
