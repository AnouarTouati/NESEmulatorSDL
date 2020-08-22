#pragma once
#include "CoreHeaders.h"


	class CPU {
	public:
		CPU() =delete;
		CPU(std::shared_ptr<spdlog::logger> Logger, uint8_t** CPUMemory,uint8_t** PPUMemory)
			:Logger(Logger) ,CPUMemory(CPUMemory),PPUMemory(PPUMemory){

		}
		int8_t InterruptRequestReset();//retruns 0 success //1 failed 
		int8_t InterruptRequestMaskable();//retruns 0 success //1 failed 
		int8_t InterruptRequestNonMaskable();//retruns 0 success //1 failed 

		 void ExecuteNextInstruction();

        //private :   
		uint8_t** CPUMemory;
		uint8_t** PPUMemory;

		uint16_t PC=0x0000;
		uint8_t SP=0xFF;//STACK IS AT MEMORY 0x01FF downto 0x0100
		uint8_t A;//Accumulator
		uint8_t X;//Index Register X
		uint8_t Y;//Index Register Y
		uint8_t P=0b00100000;//Status Register
		uint8_t* PPUControlRegister1 = CPUMemory[0x2000];
		uint8_t* PPUControlRegister2 = CPUMemory[0x2001];
		std::shared_ptr<spdlog::logger> Logger;
		bool FinishedExecutingCurrentInsctruction = true;

		uint8_t* GetPointerToDataInCPUMemoryUsing_IME_MODE() {
			return  CPUMemory[PC + 1];
		}

		uint8_t* GetPointerToDataInCPUMemoryUsing_ZABS_MODE() {
			return CPUMemory[*CPUMemory[PC + 1]];
		}
		uint8_t* GetPointerToDataInCPUMemoryUsing_ZINX_MODE() {
			return CPUMemory[*CPUMemory[PC + 1] + X];
		}
		uint8_t* GetPointerToDataInCPUMemoryUsing_ABS_MODE() {
			return CPUMemory[Get16BitAddressFromMemoryLocation(PC + 1)];
		}
		uint8_t* GetPointerToDataInCPUMemoryUsing_INX_X_MODE() {
			return CPUMemory[Get16BitAddressFromMemoryLocation(PC + 1) + X];
		}
		uint8_t* GetPointerToDataInCPUMemoryUsing_INX_Y_MODE() {
			return CPUMemory[Get16BitAddressFromMemoryLocation(PC + 1) + Y];
		}
		uint8_t* GetPointerToDataInCPUMemoryUsing_PRII_MODE() {
			uint8_t ActualAddress = *CPUMemory[*CPUMemory[PC + 1] + X];
			return CPUMemory[ActualAddress];
		}
		uint8_t* GetPointerToDataInCPUMemoryUsing_POII_MODE() {
			uint16_t ActualAddress = Get16BitAddressFromMemoryLocation(*CPUMemory[PC + 1]) + Y;
			return CPUMemory[ActualAddress];
		}

		uint16_t Get16BitAddressFromMemoryLocation(uint16_t StartingAddress) {
			uint8_t Lower = *CPUMemory[StartingAddress];
			uint8_t Upper = *CPUMemory[StartingAddress+1];
			uint16_t ActualAddress = Upper;
			ActualAddress=ActualAddress << 8;
			ActualAddress = ActualAddress | Lower;
			return ActualAddress;
		}
		bool GetSignFromData(const uint8_t* TargetData) {
			if (*TargetData & 0b10000000) {
				return true;
			}
			else {
				return false;
			}
		}

		bool GetCarry() {
			if (P & 0b00000001) {
				return true;
			}
			else {
				return false;
			}
		}
		void SetCarry() {
			P = P | 0b00000001;
		}
		void ResetCarry() {
			P = P & 0b11111110;
		}

		bool GetZero() {
			if (P & 0b00000010) {
				return true;
			}
			else {
				return false;
			}
		}
		void SetZero() {
			P = P | 0b00000010;
		}
		void ResetZero() {
			P = P & 0b11111101;
		}

		bool GetInterruptDisable() {
			if (P & 0b00000100) {
				return true;
			}
			else {
				return false;
			}
		}
		void SetInterruptDisbale() {
			P = P | 0b00000100;
		}
		void ResetInterruptDisable() {
			P = P & 0b11111011;
		}

		bool GetDecimalMode() {
			if (P & 0b00001000) {
				return true;
			}
			else {
				return false;
			}
		}
		void SetDecimalMode() {
			P = P | 0b00001000;
		}
		void ResetDecimalMode() {
			P = P & 0b11110111;
		}

		bool GetBreak() {
			if (P & 0b00010000) {
				return true;
			}
			else {
				return false;
			}
		}
		void SetBreak() {
			P = P | 0b00010000;
		}
		void ResetBreak() {
			P = P & 0b11101111;
		}
		///R flag is always 1 no need for it
		/// 
		bool GetOverflow() {
			if (P & 0b01000000) {
				return true;
			}
			else {
				return false;
			}
		}
		void SetOverflow() {
			P = P | 0b01000000;
		}
		void ResetOverflow() {
			P = P & 0b10111111;
		}

		bool GetSign() {
			if (P & 0b10000000) {
				return true;
			}
			else {
				return false;
			}
		}
		void SetSign() {
			P = P | 0b10000000;
		}
		void ResetSign() {
			P = P & 0b01111111;
		}

		

		void BaseAND(uint8_t InstructionLength);
		void BaseASL(uint8_t InstructionLength,uint8_t* DataThaWillBeAltered);
		struct BaseBranchReturnType {
			bool Sign;
			uint8_t UnSignedOperand;
		};
		BaseBranchReturnType BaseBranch();
		

		
		// void BRK(); 
		// void  ORA_PRII(); 
		// void  ORA_ZABS(); 
		 void   ASL_ZABS();
		// void   PHP();
		// void   ORA_IME();
		 void  ASL_ACC();
		// void  ORA_ABS();
		 void  ASL_ABS();
		 void  BPL();
		// void  ORA_POII();
		// void ORA_ZINX();
		 void ASL_ZINX();
		// void  CLC_();
		// void  ORA_INX_Y();
		// void  ORA_INX_X();
		 void  ASL_INX_X();
		// void  JSR();
		 void  AND_PRII();
		// void  BIT_ZABS();
		 void  AND_ZABS();
		// void  ROL_ZABS();
		// void  PLP();
		 void  AND_IME();
		// void  ROL_ACC();
		// void  BIT_ABS();
		 void  AND_ABS();
		// void  ROL_ABS();
		 void  BMI();
		 void  AND_POII();
		 void  AND_ZINX();
		// void  ROL_ZINX();
		// void  SEC();
		 void  AND_INX_Y();
		 void  AND_INX_X();
		// void  ROL_INX_X();
		// void  RTI();
		// void  EOR_PRII();
		// void  EOR_ZABS();
		// void  LSR_ZABS(); 
		// void  PHA(); 
		// void  EOR_IME(); 
		// void  LSR_ACC(); 
		// void  JMP_ABS(); 
		// void  EOR_ABS(); 
		// void  LSR_ABS(); 
		 void  BVC(); 
		// void  EOR_POII(); 
		// void  EOR_ZINX(); 
		// void  LSR_ZINX(); 
		// void  CLI(); 
		// void  EOR_INX_Y(); 
		// void  EOR_INX_X(); 
		// void  LSR_INX_X(); 
		// void  RTS(); 
		// void  ADC_PRII(); 
		// void  ADC_ZABS(); 
		// void  ROR_ZABS(); 
		// void  PLA(); 
		//
		//
		//
		 void ADC_IME(); 
		//
		//
		//
		// void  ROR_ACC();
		// void  JMP_IND(); 
		// void  ADC_ABS(); 
		// void  ROR_ABS(); 
		 void  BVS(); 
		// void  ADC_POII(); 
		// void  ADC_ZINX(); 
		// void  ROR_ZINX(); 
		// void  SEI(); 
		// void  ADC_INX_Y(); 
		// void  ADC_INX_X(); 
		// void  ROR_INX_X(); 
		// void  STA_PRII(); 
		// void  STY_ZABS(); 
		// void  STA_ZABS(); 
		// void  STX_ZABS(); 
		// void  DEY(); 
		// void  TXA(); 
		// void  STY_ABS(); 
		// void  STA_ABS(); 
		// void  STX_ABS(); 
		 void  BCC(); 
		// void  STA_POII(); 
		// void  STY_ZINX(); 
		// void  STA_ZINX(); 
		// void  STX_ZINY(); 
		// void  TYA(); 
		// void  STA_INX_Y(); 
		// void  TXS(); 
		// void  STA_INX_X(); 
		// void  LDY_IME(); 
		// void  LDA_PRII(); 
		// void  LDX_IME(); 
		// void  LDY_ZABS(); 
		// void  LDA_ZABS(); 
		// void  LDX_ZABS(); 
		// void  TAY(); 
		// void  LDA_IME(); 
		// void  TAX(); 
		// void  LDY_ABS(); 
		// void  LDA_ABS(); 
		// void  LDX_ABS(); 
		 void  BCS(); 
		// void  LDA_POII_Y(); 
		// void  LDY_ZINX(); 
		// void  LDA_ZINX(); 
		// void  LDX_ZINY(); 
		// void  CLV(); 
		// void  LDA_INX_Y(); 
		// void  TSX(); 
		// void  LDY_INX_X(); 
		// void  LDA_INX_X(); 
		// void  LDX_INX_Y(); 
		// void  CPY_IME(); 
		// void  CMP_PRII(); 
		// void  CPY_ZABS(); 
		// void  CMP_ZABS(); 
		// void  DEC_ZABS(); 
		// void  INY(); 
		// void  CMP_IME(); 
		// void  DEX(); 
		// void  CPY_ABS(); 
		// void  CMP_ABS(); 
		 void  BNE(); 
		// void  CMP_POII(); 
		// void  CMP_ZINX(); 
		// void  DEC_ZINX(); 
		// void  CLD(); 
		// void  CMP_INX_Y(); 
		// void  CMP_INX_X(); 
		// void  DEC_INX_X(); 
		// void  CPX_IME(); 
		// void  SBC_PRII(); 
		// void  CPX_ZABS(); 
		// void  SBC_ZABS(); 
		// void  INC_ZABS(); 
		// void  INX(); 
		// void  SBC_IME(); 
		// void  NOP(); 
		// void  CPX_ABS(); 
		// void  SBC_ABS(); 
		// void  INC_ABS(); 
		 void  BEQ(); 
		// void  SBC_POII(); 
		// void  SBC_ZINX(); 
		// void  INC_ZINX(); 
		// void  SED(); 
		// void  SBC_INX_Y(); 
		// void  SBC_INX_X(); 
		// void  INC_INX_X(); 
	};
