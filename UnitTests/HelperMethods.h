#pragma once
#include "../NESEmulatorSDL/src/CoreHeaders.h"
#include "../NESEmulatorSDL/src/NESComponents.h"
#include "../NESEmulatorSDL/src/CPU.h"


#define TargetDataAddress_IME_MODE  0x0001
#define TargetDataAddress_ZABS_MODE  0x00F5
#define TargetDataAddress_ZINX_MODE  0x00C9
#define TargetDataAddress_ABS_MODE  0x621C 
#define TargetDataAddress_INX_X_MODE  0xB0AE
#define TargetDataAddress_INX_Y_MODE  0xB0AF
#define TargetDataAddress_PRII_MODE  0xF0
#define TargetDataAddress_POII_MODE  0xC0B1


CPU* CreateIME_Instruction(uint8_t InstructionOPcode, uint8_t ImmediateValue) {
	uint8_t** CPUMemory = CreateCPUMemory();
	CPU* aCPU = new CPU(NULL, CPUMemory, NULL);
	*CPUMemory[0x0000] = InstructionOPcode;
	*CPUMemory[0x0001] = ImmediateValue;
	aCPU->PC = 0x0000;

	return aCPU;
}
CPU* CreateZABS_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution) {
	uint8_t** CPUMemory = CreateCPUMemory();
	CPU* aCPU = new CPU(NULL, CPUMemory, NULL);
	*CPUMemory[0x0000] = InstructionOPcode;
	*CPUMemory[0x0001] = 0xF5;
	*CPUMemory[0x00F5] = ValueThatWillBeRetrievedOnExecution;
	aCPU->PC = 0x0000;
	return aCPU;
}
CPU* CreateZINX_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution) {
	uint8_t** CPUMemory = CreateCPUMemory();
	CPU* aCPU= new CPU(NULL, CPUMemory, NULL);
	*CPUMemory[0x0000] = InstructionOPcode;
	*CPUMemory[0x0001] = 0xC8;
	aCPU->X = 0x01;
	*CPUMemory[0x00C9] = ValueThatWillBeRetrievedOnExecution;
	aCPU->PC = 0x0000;
	return aCPU;
}
//ADDRESSING MODES TO GET OPERAND
CPU* CreateABS_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution) {
	uint8_t** CPUMemory = CreateCPUMemory();
	CPU* aCPU = new CPU(NULL, CPUMemory, NULL);
	*CPUMemory[0x0000] = InstructionOPcode;
	*CPUMemory[0x0001] = 0x1C;
	*CPUMemory[0x0002] = 0x62;
	*CPUMemory[0x621C] = ValueThatWillBeRetrievedOnExecution;
	aCPU->PC = 0x0000;
	return aCPU;
}
CPU* CreateINX_X_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution) {
	uint8_t** CPUMemory = CreateCPUMemory();
	CPU* aCPU = new CPU(NULL, CPUMemory, NULL);
	*CPUMemory[0x0000] = InstructionOPcode;
	*CPUMemory[0x0001] = 0xAD;
	*CPUMemory[0x0002] = 0xB0;
	aCPU->X = 0x01;
	*CPUMemory[0xB0AE] = ValueThatWillBeRetrievedOnExecution;
	aCPU->PC = 0x0000;
	return aCPU;
}
CPU* CreateINX_Y_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution) {
	uint8_t** CPUMemory = CreateCPUMemory();
	CPU* aCPU = new CPU(NULL, CPUMemory, NULL);
	*CPUMemory[0x0000] = InstructionOPcode;
	*CPUMemory[0x0001] = 0xAE;
	*CPUMemory[0x0002] = 0xB0;
	aCPU->Y = 0x01;
	*CPUMemory[0xB0AF] = ValueThatWillBeRetrievedOnExecution;
	aCPU->PC = 0x0000;
	return aCPU;
}
CPU* CreatePRII_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution) {
	uint8_t** CPUMemory = CreateCPUMemory();
	CPU* aCPU = new CPU(NULL, CPUMemory, NULL);
	*CPUMemory[0x0000] = InstructionOPcode;
	*CPUMemory[0x0001] = 0xA0;//instruction data
	aCPU->X = 0x01;
	*CPUMemory[0xA1] = 0xF0;
	*CPUMemory[0xF0] = ValueThatWillBeRetrievedOnExecution;
	aCPU->PC = 0x0000;
	return aCPU;
}
CPU* CreatePOII_Instruction(uint8_t InstructionOPcode, uint8_t ValueThatWillBeRetrievedOnExecution) {
	uint8_t** CPUMemory = CreateCPUMemory();
	CPU* aCPU = new CPU(NULL, CPUMemory, NULL);
	*CPUMemory[0x0000] = InstructionOPcode;
	*CPUMemory[0x0001] = 0xA0;

	*CPUMemory[0x00A0] = 0xB0;
	*CPUMemory[0x00A1] = 0xC0;
	aCPU->Y = 0x01;
	*CPUMemory[0xC0B1] = ValueThatWillBeRetrievedOnExecution;

	aCPU->PC = 0x0000;
	return aCPU;
}
CPU* CreateACC_Instruction(uint8_t InstructionOPcode) {
	uint8_t** CPUMemory = CreateCPUMemory();
	CPU* aCPU = new CPU(NULL, CPUMemory, NULL);
	*CPUMemory[0x0000] = InstructionOPcode;
	aCPU->PC = 0x0000;
	return aCPU;
}
//MISCELENIOUS
CPU* CreatBRANCH_FAMILY_Instruction(uint8_t InstructionOPcode, uint8_t DisplacementValue) {
	uint8_t** CPUMemory = CreateCPUMemory();
	CPU* aCPU = new CPU(NULL, CPUMemory, NULL);
	*CPUMemory[0x8000] = InstructionOPcode;
	*CPUMemory[0x8001] =DisplacementValue;
	aCPU->PC = 0x8000;
	return aCPU;
}

CPU* CreatIMPLIED_Instruction(uint8_t InstructionOPcode) {
	uint8_t** CPUMemory = CreateCPUMemory();
	CPU* aCPU = new CPU(NULL, CPUMemory, NULL);
	*CPUMemory[0x0000] = InstructionOPcode;
	aCPU->PC = 0x0000;
	return aCPU;
}