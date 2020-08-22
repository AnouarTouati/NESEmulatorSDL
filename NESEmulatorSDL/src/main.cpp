#include "CoreHeaders.h"
#include "NESComponents.h"
#include "CPU.h"
#include "IOCore.h"


    std::shared_ptr<spdlog::logger> Logger;
    std::vector<uint8_t>* Rom= new std::vector<uint8_t>();;
    uint8_t** CPUMemory;
    uint8_t** PPUMemory;
   
    void InitLogger() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        Logger = spdlog::stdout_color_mt("NESEmulator");
        LOG_INFO("Log Initialized");
    }
    void LoadAppropriatePRGROMstoCPUMemory() {
       // *CPUMemory[0x8000]=PRG-ROM1 16KB
        //*CPUMemory[0xC000]= PRG-ROM2 16KB
    }
    int main(int argc, char* argv[])
    {
        InitLogger();
        CPUMemory = CreateCPUMemory();
        PPUMemory= CreatePPUMemory();
        LoadRom(Logger, Rom);
        IOCore IOCore(Logger);
        IOCore.Init();
        CPU CPU(Logger, CPUMemory, PPUMemory);
        CPU.InterruptRequestReset();
        while (true) {

            CPU.ExecuteNextInstruction();
            IOCore.HandleEvents();
            IOCore.RefreshDisplay();
        }
        return 0;
    }




