cmake_minimum_required(VERSION 3.29)
project(FinalProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(FinalProject main.cpp
        StudentManagementSystem.cpp
        Student.cpp
        Course.cpp
        DataRepository.cpp
        Grade.cpp
        AttendanceRecord.cpp
        GradeComponent.cpp
        GradeFactory.cpp
        SimpleGradeCalculationStrategy.cpp
        Graph.cpp)
