#include "CPU.h"

	void  CPU::ExecuteNextInstruction() {
		FinishedExecutingCurrentInsctruction = false;
		//LOG_INFO("Executing Instructions ...");
		uint8_t OPCode = *CPUMemory[PC];
		//IME Immediate
		//ABS Absolute
		//ZABS Zeropage Absolute
		//IMP implied
		//ACC Accumulator
		//INX Indexed
		//ZINX Zero Page Indexed X register only
		//ZINY Zero Page Indexed Y
		//IND Indirect applies only to Jump instruction
		//PRII Pre Indexed Indirect
		//POII Post Indexed Indirect
		//REL Relative // signed number added to PC
	
		switch (OPCode) {
			
		//case 0x00:  BRK(); break;
		//case 0x01:  ORA_PRII(); break;
		//
		//case 0x05:  ORA_ZABS(); break;
		case 0x06:  ASL_ZABS(); break;
		//
		//case 0x08:  PHP(); break;
		//case 0x09:  ORA_IME(); break;
		case 0x0A:  ASL_ACC(); break;
		//
		//case 0x0D:  ORA_ABS(); break;
		case 0x0E:  ASL_ABS(); break;
		//
		//case 0x10:  BPL(); break;
		//case 0x11:  ORA_POII(); break;
		//
		//case 0x15: ORA_ZINX (); break;
		case 0x16: ASL_ZINX (); break;
		//
		//case 0x18:  CLC_(); break;
		//case 0x19:  ORA_INX_Y(); break;
		//
		//case 0x1D:  ORA_INX_X(); break;
		case 0x1E:  ASL_INX_X(); break;
		//
		//case 0x20:  JSR(); break;
		case 0x21:  AND_PRII(); break;
		//
		//case 0x24:  BIT_ZABS(); break;
		case 0x25:  AND_ZABS(); break;
		//case 0x26:  ROL_ZABS(); break;
		//
		//case 0x28:  PLP(); break;
		case 0x29:  AND_IME(); break;
		//case 0x2A:  ROL_ACC(); break;
		//
		//case 0x2C:  BIT_ABS(); break;
		case 0x2D:  AND_ABS(); break;
		//case 0x2E:  ROL_ABS(); break;
		//
		//case 0x30:  BMI(); break;
		case 0x31:  AND_POII(); break;
		//
		case 0x35:  AND_ZINX(); break;
		//case 0x36:  ROL_ZINX(); break;
		//
		//case 0x38:  SEC(); break;
		case 0x39:  AND_INX_Y(); break;
		//
		case 0x3D:  AND_INX_X(); break;
		//case 0x3E:  ROL_INX_X(); break;
		//case 0x40:  RTI(); break;
		//case 0x41:  EOR_PRII(); break;
		//case 0x45:  EOR_ZABS(); break;
		//case 0x46:  LSR_ZABS(); break;
		//case 0x48:  PHA(); break;
		//case 0x49:  EOR_IME(); break;
		//case 0x4A:  LSR_ACC(); break;
		//case 0x4C:  JMP_ABS(); break;
		//case 0x4D:  EOR_ABS(); break;
		//case 0x4E:  LSR_ABS(); break;
		//case 0x50:  BVC(); break;
		//case 0x51:  EOR_POII(); break;
		//case 0x55:  EOR_ZINX(); break;
		//case 0x56:  LSR_ZINX(); break;
		//case 0x58:  CLI(); break;
		//case 0x59:  EOR_INX_Y(); break;
		//case 0x5D:  EOR_INX_X(); break;
		//case 0x5E:  LSR_INX_X(); break;
		//case 0x60:  RTS(); break;
		//case 0x61:  ADC_PRII(); break;
		//case 0x65:  ADC_ZABS(); break;
		//case 0x66:  ROR_ZABS(); break;
		//case 0x68:  PLA(); break;
		//
		//
		case 0x69:  ADC_IME(); break;
		//
		//
		//
		//case 0x6A:  ROR_ACC(); break;
		//case 0x6C:  JMP_IND(); break;
		//case 0x6D:  ADC_ABS(); break;
		//case 0x6E:  ROR_ABS(); break;
		//case 0x70:  BVS(); break;
		//case 0x71:  ADC_POII(); break;
		//case 0x75:  ADC_ZINX(); break;
		//case 0x76:  ROR_ZINX(); break;
		//case 0x78:  SEI(); break;
		//case 0x79:  ADC_INX_Y(); break;
		//case 0x7D:  ADC_INX_X(); break;
		//case 0x7E:  ROR_INX_X(); break;
		//case 0x81:  STA_PRII(); break;
		//case 0x84:  STY_ZABS(); break;
		//case 0x85:  STA_ZABS(); break;
		//case 0x86:  STX_ZABS(); break;
		//case 0x88:  DEY(); break;
		//case 0x8A:  TXA(); break;
		//case 0x8C:  STY_ABS(); break;
		//case 0x8D:  STA_ABS(); break;
		//case 0x8E:  STX_ABS(); break;
		//case 0x90:  BCC(); break;
		//case 0x91:  STA_POII(); break;
		//case 0x94:  STY_ZINX(); break;
		//case 0x95:  STA_ZINX(); break;
		//case 0x96:  STX_ZINY(); break;
		//case 0x98:  TYA(); break;
		//case 0x99:  STA_INX_Y(); break;
		//case 0x9A:  TXS(); break;
		//case 0x9D:  STA_INX_X(); break;
		//case 0xA0:  LDY_IME(); break;
		//case 0xA1:  LDA_PRII(); break;
		//case 0xA2:  LDX_IME(); break;
		//case 0xA4:  LDY_ZABS(); break;
		//case 0xA5:  LDA_ZABS(); break;
		//case 0xA6:  LDX_ZABS(); break;
		//case 0xA8:  TAY(); break;
		//case 0xA9:  LDA_IME(); break;
		//case 0xAA:  TAX(); break;
		//case 0xAC:  LDY_ABS(); break;
		//case 0xAD:  LDA_ABS(); break;
		//case 0xAE:  LDX_ABS(); break;
		//case 0xB0:  BCS(); break;
		//case 0xB1:  LDA_POII_Y(); break;
		//case 0xB4:  LDY_ZINX(); break;
		//case 0xB5:  LDA_ZINX(); break;
		//case 0xB6:  LDX_ZINY(); break;
		//case 0xB8:  CLV(); break;
		//case 0xB9:  LDA_INX_Y(); break;
		//case 0xBA:  TSX(); break;
		//case 0xBC:  LDY_INX_X(); break;
		//case 0xBD:  LDA_INX_X(); break;
		//case 0xBE:  LDX_INX_Y(); break;
		//case 0xC0:  CPY_IME(); break;
		//case 0xC1:  CMP_PRII(); break;
		//case 0xC4:  CPY_ZABS(); break;
		//case 0xC5:  CMP_ZABS(); break;
		//case 0xC6:  DEC_ZABS(); break;
		//case 0xC8:  INY(); break;
		//case 0xC9:  CMP_IME(); break;
		//case 0xCA:  DEX(); break;
		//case 0xCC:  CPY_ABS(); break;
		//case 0xCD:  CMP_ABS(); break;
		//case 0xD0:  BNE(); break;
		//case 0xD1:  CMP_POII(); break;
		//case 0xD5:  CMP_ZINX(); break;
		//case 0xD6:  DEC_ZINX(); break;
		//case 0xD8:  CLD(); break;
		//case 0xD9:  CMP_INX_Y(); break;
		//case 0xDD:  CMP_INX_X(); break;
		//case 0xDE:  DEC_INX_X(); break;
		//case 0xE0:  CPX_IME(); break;
		//case 0xE1:  SBC_PRII(); break;
		//case 0xE4:  CPX_ZABS(); break;
		//case 0xE5:  SBC_ZABS(); break;
		//case 0xE6:  INC_ZABS(); break;
		//case 0xE8:  INX(); break;
		//case 0xE9:  SBC_IME(); break;
		//case 0xEA:  NOP(); break;
		//case 0xEC:  CPX_ABS(); break;
		//case 0xED:  SBC_ABS(); break;
		//case 0xEE:  INC_ABS(); break;
		//case 0xF0:  BEQ(); break;
		//case 0xF1:  SBC_POII(); break;
		//case 0xF5:  SBC_ZINX(); break;
		//case 0xF6:  INC_ZINX(); break;
		//case 0xF8:  SED(); break;
		//case 0xF9:  SBC_INX_Y(); break;
		//case 0xFD:  SBC_INX_X(); break;
		//case 0xFE:  INC_INX_X(); break;
		//default:LOG_WARN("OPCode not supported"); break;
		}
		
	}

	int8_t CPU::InterruptRequestReset() {
		if (FinishedExecutingCurrentInsctruction) {
			PC = *CPUMemory[0xFFFD];
			PC = PC << 8;
			PC = PC | *CPUMemory[0xFFFC];
			return 0;
		}
		else {
			//LOG_ERROR("Calling Interrupt Methods Should only be called after Execute Method is Called");
			return -1;
		}
	}

	int8_t CPU::InterruptRequestMaskable() {
		if (FinishedExecutingCurrentInsctruction) {
			if ((P bitand 0b00000100) == 0) {
				*CPUMemory[0x0100 + SP] = PC & 0x0F;
				SP--;
				*CPUMemory[0x0100 + SP] = (PC & 0xF0) >> 8;
				SP--;
				*CPUMemory[0x0100 + SP] = P;
				SP--;
				P = P | 0b00000100;//set I Flag
				PC = *CPUMemory[0xFFFF];
				PC = PC << 8;
				PC = PC | *CPUMemory[0xFFFE];
			}
			else {
				//I flag set ignore the interrupt
			}
			

			return 0;
		}
		else {
			//LOG_ERROR("Calling Interrupt Methods Should only be called after Execute Method is Called");
			return -1;
		}
	}

	int8_t CPU::InterruptRequestNonMaskable() {
		if (FinishedExecutingCurrentInsctruction) {
			//only maskbale by PPU control register 1 if bit 7 is reset
			if ((*PPUControlRegister1 bitand 0b10000000) != 0) {
				*CPUMemory[0x0100 + SP] = PC & 0x0F;
				SP--;
				*CPUMemory[0x0100 + SP] = (PC & 0xF0) >> 8;
				SP--;
				*CPUMemory[0x0100 + SP] = P;
				SP--;
				P = P | 0b00000100;//set I Flag
				PC = *CPUMemory[0xFFFB];
				PC = PC << 8;
				PC = PC | *CPUMemory[0xFFFA];
			}
			else {
				//bit 7 of PPU Control register is reset ignore the interrupt
			}

			return 0;
		}
		else {
			//LOG_ERROR("Calling Interrupt Methods Should only be called after Execute Method is Called");
			return -1;
		}
	}
	
    void CPU::ADC_IME() {
		//2 bytes instruction
		  uint16_t sum = A + *CPUMemory[PC + 1];
		  if (GetCarry()) {
			  sum = sum + 1;
		  }

		bool ThereIsCarry = sum & 0b100000000;

		bool ThereIsOverflow = false;
		if ((A & 0b10000000) != (*CPUMemory[PC + 1] & 0b10000000))//operands have different sign there is a possibility of overflow
		{
			if ((A & 0b10000000) != (sum & 0b10000000)) //result sign not the same as operands sign means overflow
			{
				ThereIsOverflow = true;
			}
		}

		A = A + *CPUMemory[PC + 1] ;
		if (GetCarry()) {
			A = A + 1;
		}
		if (A == 0) { SetZero(); }
		else { ResetZero(); }

		//this wont work we are using unsigned unit8_t
		if (GetSignFromData(&A)) { SetSign(); }//set N(S) sign flag to 1 if negative
		else{  ResetSign(); }

		if (ThereIsCarry) { SetCarry(); }
		else { ResetCarry(); }

		if (ThereIsOverflow) { SetOverflow(); }
		else { ResetOverflow(); }

		PC = PC + 2;
	}
	/////////   AND_INSTRUCTIONS
	void CPU::BaseAND(uint8_t InstructionLength) {
		if (A == 0) { SetZero(); }
		else { ResetZero(); }

		if (GetSignFromData(&A)) { SetSign(); }
		else { ResetSign(); }

		PC = PC + InstructionLength;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::AND_IME() {
		//OPCOE 0x29 2BYTES LONG
		A = A & *GetPointerToDataInCPUMemoryUsing_IME_MODE();
		BaseAND(2);
	}
	void CPU::AND_ZABS() {
		//opcode 0x25 2bytes long
		A = A & *GetPointerToDataInCPUMemoryUsing_ZABS_MODE();
		BaseAND(2);
	}    
	void CPU::AND_ZINX() {
		//opcode 0x35 2bytes long
		A = A & *GetPointerToDataInCPUMemoryUsing_ZINX_MODE();
		BaseAND(2);
   }
	void CPU::AND_ABS() {
		//opcode 2D 3bytes long
		
		A = A & *GetPointerToDataInCPUMemoryUsing_ABS_MODE();
		BaseAND(3);
	}
	void CPU::AND_INX_X() {
		//opcode 3D 3bytes long
		A = A & *GetPointerToDataInCPUMemoryUsing_INX_X_MODE();
		BaseAND(3);
	}
	void CPU::AND_INX_Y() {
		//opcode 39 3bytes long
		A = A & *GetPointerToDataInCPUMemoryUsing_INX_Y_MODE();
		BaseAND(3);
	}
	void CPU::AND_PRII() {
		//opcode 21  2bytes long
		
		A = A & *GetPointerToDataInCPUMemoryUsing_PRII_MODE();
		BaseAND(2);
	}
	void CPU::AND_POII() {
		//opcode 31  2bytes long
		
		A = A & *GetPointerToDataInCPUMemoryUsing_POII_MODE();
		BaseAND(2);
	}
	////////////////  END    ///////////////

	/////////   ASL_INSTRUCTIONS
	void CPU::BaseASL(uint8_t InstructionLength,uint8_t* DataThaWillBeAltered) {
		if (GetSignFromData(DataThaWillBeAltered)) { SetCarry(); }
		else { ResetCarry(); }

		*DataThaWillBeAltered = *DataThaWillBeAltered << 1;

		if (*DataThaWillBeAltered == 0) { SetZero(); }
		else { ResetZero(); }
		if (GetSignFromData(DataThaWillBeAltered)) { SetSign(); }
		else { ResetSign(); }

		PC = PC + InstructionLength;
		FinishedExecutingCurrentInsctruction = true;
	}
	void CPU::ASL_ACC() {
		//opcode 0x0A 1byte long
		BaseASL(1, &A);
	}
	void CPU::ASL_ZABS() {
		//opcode 0x06 2bytes long
		BaseASL(2, GetPointerToDataInCPUMemoryUsing_ZABS_MODE());
	}
	void CPU::ASL_ZINX() {
		//opcode 0x16 2 bytes long
		BaseASL(2, GetPointerToDataInCPUMemoryUsing_ZINX_MODE());
	}
	void CPU::ASL_ABS() {
		//opcode 0x0E 3 bytes long
		BaseASL(3, GetPointerToDataInCPUMemoryUsing_ABS_MODE());
	}
	void CPU::ASL_INX_X() {
		//opcode 0x1E 3 bytes long
		BaseASL(3, GetPointerToDataInCPUMemoryUsing_INX_X_MODE());
	}

	////////////////  END    ///////////////