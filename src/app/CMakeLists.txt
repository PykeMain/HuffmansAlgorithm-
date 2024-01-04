add_executable(
    app
)

target_link_libraries(
    app
    PUBLIC
    algorithms
    structures
    fileManager
)

target_sources(
    app
    PUBLIC
    main.cpp
)