#pragma once
//i chose not to include the logical operation in the defintion so the code stays clear

#define MaskToSetCarryFlag  0b00000001;
#define MaskToGetCarryFlagBoolean  0b00000001;
#define MaskToResetCarryFlag  0b11111110;

#define MaskToSetZeroFlag  0b00000010;
#define MaskToGetZeroFlagBoolean  0b00000010;
#define MaskToResetZeroFlag  0b11111101;

#define MaskToSetInterruptDisbaleFlag  0b00000100;
#define MaskToGetInterruptDisbaleFlagBoolean  0b00000100;
#define MaskToResetInterruptDisbaleFlag   0b11111011;

#define MaskToSetDecimalModeFlag  0b00001000;
#define MaskToGetDecimalModeFlagBoolean  0b00001000;
#define MaskToResetDecimalModeFlag   0b11110111;

#define MaskToSetBreakFlag  0b00010000;
#define MaskToGetBreakFlagBoolean  0b00010000;
#define MaskToResetBreakFlag   0b11101111;

//R FLAG is not used although is must be always set 1

#define MaskToSetOverflowFlag  0b01000000;
#define MaskToGetOverflowFlagBoolean  0b01000000;
#define MaskToResetOverflowFlag  0b10111111;

#define MaskToSetSignFlag  0b10000000;
#define MaskToGetSignFlagBoolean  0b10000000;
#define MaskToResetSignFlag  0b01111111;



