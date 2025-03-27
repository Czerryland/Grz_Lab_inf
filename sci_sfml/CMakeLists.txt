find_package( SFML
    COMPONENTS
        graphics
        system
        window
    REQUIRED
)

add_executable( sci_sfml )

target_include_directories( sci_sfml
    PUBLIC
        .
)

target_sources( sci_sfml
    PUBLIC
        ./main.cpp
)