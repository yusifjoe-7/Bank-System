cmake_minimum_required(VERSION 3.20)

project(BankSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find all C++ source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

# Don't include files from the build directory
list(FILTER SOURCES EXCLUDE REGEX "${CMAKE_BINARY_DIR}/.*")


# =========================
# Libraries
# =========================

# SQLite3
find_package(SQLite3 REQUIRED)

# libuuid
find_library(UUID_LIBRARY uuid REQUIRED)

# libsodium
find_library(SODIUM_LIBRARY sodium REQUIRED)


# =========================
# Executable
# =========================

add_executable(bank ${SOURCES})


# =========================
# Include directories
# =========================

target_include_directories(bank PRIVATE
    ${CMAKE_SOURCE_DIR}
)


# =========================
# Link libraries
# =========================

target_link_libraries(bank PRIVATE
    SQLite::SQLite3
    ${UUID_LIBRARY}
    ${SODIUM_LIBRARY}
)