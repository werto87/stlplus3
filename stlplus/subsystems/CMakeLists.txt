target_sources(stlplus PUBLIC
        cli_parser.cpp
        ini_manager.cpp
        library_manager.cpp
        message_handler.cpp
        timer.cpp
        )


install(FILES
        cli_parser.cpp
        cli_parser.hpp
        ini_manager.cpp
        ini_manager.hpp
        library_manager.cpp
        library_manager.hpp
        message_handler.cpp
        message_handler.hpp
        subsystems_fixes.hpp
        subsystems.hpp
        timer.cpp
        timer.hpp
        DESTINATION include/stlplus/stlplus/subsystems
)

install(TARGETS stlplus DESTINATION stlplus)












 
 
 
 
 
 
 
 
 
 
 
 
































