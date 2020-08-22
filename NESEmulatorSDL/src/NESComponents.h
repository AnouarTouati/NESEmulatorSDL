#pragma once
#include "CoreHeaders.h"

void LoadRom(std::shared_ptr<spdlog::logger> Logger, std::vector<uint8_t>* Rom) {
    LOG_INFO("Loading rom started");
    std::ifstream file;
    file.open("SuperMarioBros.nes", std::ios::binary);

    if (!file) {
        LOG_ERROR("Rom not found");
        return;
    }
   
    *Rom= std::vector<uint8_t>(std::istreambuf_iterator<char>(file), {});


    char nes[4];
    nes[0] = Rom->at(0);
    nes[1] = Rom->at(1);
    nes[2] = Rom->at(2);
    nes[3] = 0;
    char str[500];
    sprintf_s(str, "rom type %s", nes);
   LOG_INFO(str);

    if (Rom->at(3) == 0x1A) {
        LOG_INFO("rom format is iNES");
    }
    else {
        LOG_INFO("rom format is unknown");
    }

    sprintf_s(str, "number of 16KB PRG-ROM banks is %d", Rom->at(4));
    LOG_INFO(str);

    sprintf_s(str, "number of 8KB CHR-ROM banks is %d", Rom->at(5));

    LOG_INFO(str);

    LOG_INFO("Loading rom ended ");
}

uint8_t** CreateCPUMemory() {
    uint8_t** OriginalCPUMemory = new uint8_t * [0x10000];
    //max address     foldbackregion1     foldbackregion2 = 0xC808
    //    ^                  ^                   ^
    uint8_t* TimmedCPUMemory = new uint8_t[0x10000 - (0x2000 - 0x0800) - (0x4000 - 0x2008)];//size is 0xC808

    for (int i = 0x0000; i < 0x2000; i = i + 0x800) {
        for (int j = 0; j < 0x0800; j++) {
            OriginalCPUMemory[i + j] = &TimmedCPUMemory[0x0000 + j];
        }
    }


    for (int i = 0x2000; i < 0x4000; i = i + 8) {
        for (int j = 0; j < 8; j++) {
            OriginalCPUMemory[i + j] = &TimmedCPUMemory[0x0800 + j];

        }
    }


    for (int i = 0x4000; i < 0x10000; i++) {
        OriginalCPUMemory[i] = &TimmedCPUMemory[0x0808 + (i - 0x4000)];

    }

    return OriginalCPUMemory;

}

uint8_t** CreatePPUMemory() {
    uint8_t** OriginalPPUMemory = new uint8_t * [0x10000];
    uint8_t* TrimmedPPUMemory = new uint8_t[0x3020];
    //you would propably need the memory map illustration NESDoc.pdf page 17 to understand this code
    //the first section of memory is folded two more times to fill the address space 0x0000-0x3FFF and 0x4000-0x7FFF and 0x8000-0x10000
    //section one has sub section fold from 0x3000-0x3EFF mapping to 0x2000-2EFF this also is reflected on the two other major sections
    for (int i = 0x0000; i < 0x3000; i++) {

        OriginalPPUMemory[i] = &TrimmedPPUMemory[i];

        if (i >= 0x2000 && i < 0x2F00) {
            OriginalPPUMemory[i + 0x1000] = &TrimmedPPUMemory[i];
        }

    }
    for (int j = 0; j < 8; j++) {

        for (int i = 0x3F00; i < 0x3F20; i++) {

            OriginalPPUMemory[i + j * 0x20] = &TrimmedPPUMemory[i - 0x0F00];

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

