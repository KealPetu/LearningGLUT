cmake_minimum_required(VERSION 4.2)
project(LearningGlut LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ─── FetchContent ─────────────────────────────────────────────────────────────
include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

# ── freeglut ──────────────────────────────────────────────────────────────────────
FetchContent_Declare(
        freeglut_static
        GIT_REPOSITORY https://github.com/freeglut/freeglut.git
        GIT_TAG        v3.8.0
        GIT_SHALLOW    TRUE
)
set(FREEGLUT_BUILD_DEMOS  OFF CACHE BOOL "" FORCE)
set(FREEGLUT_BUILD_SHARED_LIBS  OFF  CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(freeglut_static)

# Platform-specific libs collected into variables
set(PLATFORM_LIBS "")

if(WIN32)
    list(APPEND PLATFORM_LIBS opengl32 glu32 gdi32)
endif()

if(UNIX AND NOT APPLE)
    find_package(OpenGL REQUIRED)
    list(APPEND PLATFORM_LIBS OpenGL::GL ${CMAKE_DL_LIBS})
endif()

if(APPLE)
    find_library(OPENGL_FRAMEWORK OpenGL REQUIRED)
    list(APPEND PLATFORM_LIBS ${OPENGL_FRAMEWORK})
endif()

# Common target that other executables will link to
add_library(learning_common INTERFACE)
target_include_directories(learning_common INTERFACE ${freeglut_SOURCE_DIR}/include)
# propagate freeglut and platform libs to consumers
target_link_libraries(learning_common INTERFACE
        freeglut_static
        ${PLATFORM_LIBS}
)
# common compile options
target_compile_options(learning_common INTERFACE
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra>
)

# Helper function to create executables with common settings
function(add_learning_executable targetName)
    # remaining args are source files
    cmake_parse_arguments(_ARG "" "" "SOURCES" ${ARGN})
    if(_ARG_SOURCES)
        add_executable(${targetName} ${_ARG_SOURCES})
    else()
        message(FATAL_ERROR "add_learning_executable: no SOURCES provided for '${targetName}'")
    endif()
    target_link_libraries(${targetName} PRIVATE learning_common)
endfunction()

# Example usages: add as many executables as you want
# (Adjust source paths as necessary.)
add_learning_executable(Wolf                SOURCES ${PROJECT_SOURCE_DIR}/examples/FormaLobo.cpp)
add_learning_executable(test_app            SOURCES ${PROJECT_SOURCE_DIR}/examples/main.cpp)
add_learning_executable(Estrella_Triangulo  SOURCES ${PROJECT_SOURCE_DIR}/examples/Estella_Triangulo_PeñafielKevin.cpp)
add_learning_executable(Ortho_Perspective   SOURCES ${PROJECT_SOURCE_DIR}/examples/Ortho_Perspective_PeñafielKevin.cpp)
add_learning_executable(Points              SOURCES ${PROJECT_SOURCE_DIR}/examples/points.cpp)
add_learning_executable(Polygon             SOURCES ${PROJECT_SOURCE_DIR}/examples/polygon.cpp)
add_learning_executable(Test                SOURCES ${PROJECT_SOURCE_DIR}/examples/test.cpp)
add_learning_executable(Triangle            SOURCES ${PROJECT_SOURCE_DIR}/examples/traingle.cpp)
add_learning_executable(Vertices            SOURCES ${PROJECT_SOURCE_DIR}/examples/vertices.cpp)

