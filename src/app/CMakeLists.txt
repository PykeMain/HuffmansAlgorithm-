add_executable(
    app
)

target_link_libraries(
    app
    PUBLIC
    IO
    algorithms
    structures
    fileManager
)

target_sources(
    app
    PUBLIC
    main.cpp
)