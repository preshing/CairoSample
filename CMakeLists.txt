cmake_minimum_required(VERSION 3.1)
project(CairoSample)

# Find Cairo
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
find_package(Cairo REQUIRED)

# Define executable target
add_executable(CairoSample Main.cpp)
target_include_directories(CairoSample PRIVATE ${Cairo_INCLUDE_DIRS})
target_link_libraries(CairoSample PRIVATE ${Cairo_LIBS})

# Copy Cairo DLL to output folder on Windows
if(WIN32)
    foreach(DLL ${Cairo_DLLS})
        add_custom_command(TARGET CairoSample POST_BUILD COMMAND
            ${CMAKE_COMMAND} -E copy_if_different ${DLL} $<TARGET_FILE_DIR:CairoSample>)
    endforeach()
endif()
