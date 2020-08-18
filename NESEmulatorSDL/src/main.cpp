#include <memory>
//#include <SFML/Graphics.hpp>
//#include <spdlog/spdlog.h>
//#include "spdlog/sinks/stdout_color_sinks.h"
#include <iostream>
#include "main.h"


uint8_t** CreateMainMemory() {
    uint8_t** OriginalMainMemory = new uint8_t * [0x10000];
                                        //max address     foldbackregion1     foldbackregion2 = 0xC808
                                        //    ^                  ^                   ^
    uint8_t* TimmedMemoryMap = new uint8_t[0x10000 - (0x2000 - 0x0800) - (0x4000 - 0x2008)];//size is 0xC808

    for (int i = 0x0000; i < 0x2000; i = i + 0x800) {
        for (int j = 0; j < 0x0800; j++) {
            OriginalMainMemory[i + j] = &TimmedMemoryMap[0x0000 + j];
        }
    }


    for (int i = 0x2000; i < 0x4000; i = i + 8) {
        for (int j = 0; j < 8; j++) {
            OriginalMainMemory[i + j] = &TimmedMemoryMap[0x0800 + j];

        }
    }


    for (int i = 0x4000; i < 0x10000; i++) {
        OriginalMainMemory[i] = &TimmedMemoryMap[0x0808 + (i - 0x4000)];

    }

    return OriginalMainMemory;
   
}
uint8_t** CreatePPUMemory() {
    uint8_t** OriginalPPUMemory = new uint8_t * [0x10000];
    uint8_t* TrimmedPPUMemory = new uint8_t[0x3020];
    //you would propably need the memory map illustration NESDoc.pdf page 17 to understand this code
    //the first section of memory is folded two more times to fill the address space 0x0000-0x3FFF and 0x4000-0x7FFF and 0x8000-0x10000
    //section one has sub section fold from 0x3000-0x3EFF mapping to 0x2000-2EFF this also is reflected on the two other major sections
    for (int i = 0x0000; i < 0x3000; i++) {
        
        OriginalPPUMemory[i] = &TrimmedPPUMemory[i];
       
        if (i >= 0x2000 && i<0x2F00) {
            OriginalPPUMemory[i + 0x1000] = &TrimmedPPUMemory[i];
        }
      
    }
    for (int j = 0; j < 8; j++) {

        for (int i = 0x3F00; i < 0x3F20; i++) {

            OriginalPPUMemory[i+j*0x20] = &TrimmedPPUMemory[i-0x0F00];
         
        }
    }

    for (int i = 0x0000; i < 0x4000; i++) {
        OriginalPPUMemory[i + 0x4000] = OriginalPPUMemory[i];
    }
    for (int i = 0x0000; i < 0x4000; i++) {
        OriginalPPUMemory[i + 0x8000] = OriginalPPUMemory[i];
    }
    
    return OriginalPPUMemory;
   
}
/*

void InitLog() {
    std::shared_ptr<spdlog::logger> Logger;
    spdlog::set_pattern("%^[%T] %n: %v%$");
    Logger = spdlog::stdout_color_mt("NESEmulator");
    Logger->set_level(spdlog::level::trace);
    Logger->info("Log successfully initialized");

    //folding
    //note that std::cout doesnt display unit8_t it must be excplicitly casted to int
    uint8_t** OriginalPrgMemory=new uint8_t*[0xFFFF];
    uint8_t TrimmedPrgMemory[2];
    TrimmedPrgMemory[0] = 8;
    TrimmedPrgMemory[1] = 9;
    
    OriginalPrgMemory[0] = &TrimmedPrgMemory[0];
    OriginalPrgMemory[1] = &TrimmedPrgMemory[0];

    OriginalPrgMemory[2] = &TrimmedPrgMemory[1];
    OriginalPrgMemory[3] = &TrimmedPrgMemory[1];
   

}

void InitSFML(){
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

}*/
int main()
{
   // InitLog();
    //InitSFML();
   CreatePPUMemory();
   
    return 0;
}
