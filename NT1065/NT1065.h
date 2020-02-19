//
// Created by Sudhanshu Sharma on 12-02-2020.
//

#ifndef UNTITLED_NT1066_H
#define UNTITLED_NT1065_H

struct {
    unsigned long R0_VAL;
    unsigned long R1_VAL;
    unsigned long R2_VAL;
    unsigned long R3_VAL;
    unsigned long R4_VAL;
    unsigned long R5_VAL;
    unsigned long R6_VAL;
    unsigned long R7_VAL;
    unsigned long R8_VAL;
    unsigned long R9_VAL;
    unsigned long R10_VAL;
}NT_REG_STRUCT;

typedef enum {
    R0_ADDR = 0,
    R1_ADDR ,
    R2_ADDR ,
    R3_ADDR ,
    R4_ADDR ,
    R5_ADDR ,
    R6_ADDR ,
    R7_ADDR ,
    R8_ADDR ,
    R9_ADDR ,
    R10_ADDR ,
}NT_ADDR_STRUCT;

struct {
    unsigned short defaultval;
    unsigned short val;
}r0;

struct {
    unsigned short defaultval;
    unsigned short val;
}r1;


typedef enum{
	standby =0,
	pll_a_only,
	plla_only,
	pll_active,
}IC_mode;
struct{
	IC_mode icMODE;
	unsigned short defaultval;
	unsigned short val;
}r2;

typedef enum{
	freq1 = 0,
	freq2 ,
}TCXO_sel;
typedef enum{
	pll_allch = 0,
	pll_a12b34 ,
}LO_source;
struct{
	TCXO_sel tcxo_Sel;
	LO_source lo_SOURCE;
	unsigned short defaultval;
	unsigned short val;
}r3;

typedef enum{
	error = 0,
	success ,
}LPF_ACS_S;
typedef enum{
	finish = 0,
	start ,
}LPF_EXE;
struct{
	LPF_ACS_S lpf_acs_s;
	LPF_EXE lpf_exe;
	unsigned short defaultval;
	unsigned short val;
}r4;

typedef enum{
	ch1 = 0,
	ch2 ,
	ch3 ,
	ch4 ,
}CH_StNumSel;
typedef enum{
	single = 0,
	continuous ,
}TS_MD;
typedef enum{
	finish1 = 0,
	start1 ,
}TS_EXE;
struct{
	CH_StNumSel chanSel;
	TS_MD tempMode;
	TS_EXE tempSystem;
	unsigned short defaultval;
	unsigned short unused;
	unsigned short val;
}r5;

typedef enum{
	forbid1=0,
	permit1 ,
}LPF_ACS_AOK;
typedef enum{
	forbid2=0,
	permit2 ,
}PLL_LI_AOK ;
typedef enum{
	forbid3=0,
	permit3 ,
}PLL_VCO_AOK;
typedef enum{
	forbid4=0,
	permit4 ,
}RF_AGC_AOK ;
typedef enum{
	forbid5=0,
	permit5 ,
}StdBy_AOK;
struct{
	LPF_ACS_AOK lpf_Cali;
	PLL_LI_AOK plla_b;
	PLL_VCO_AOK pll_vco;
	RF_AGC_AOK rf_agc;
	StdBy_AOK standby;
	unsigned short defaultval;
	unsigned short val;
}r6;

typedef enum{
	fail=0,
	valid ,
}AOK ;
typedef enum{
// I don't know how to assign 
}TS_code;
struct{
	AOK status_Indicator
	unsigned short defaultval;
	unsigned short unused;
	unsigned short val;
}r7;

// r8 is same as r7
//r9 has status bits
//r10 also has status bits

typedef enum{
	ratio1 = 01000,
	ratio2 = 11111,
}CDIV_R;
struct{
	CDIV_R clckratio;
	unsigned short defaultval;
	unsigned short val;
}r11;

typedef enum{
	plla=0,
	pllb ,
}CLK_Source;
typedef enum{
	Cmos =0,
	Lvds ,
}CLK_TP;
typedef enum{
	Amp1=0,
	Amp2 ,
	Amp3 ,
	Amp4,
}CLK_CC ;
typedef enum{
	type1=0,
	type2 ,
	type3 ,
	type4,
}CLK_OL;
struct{
	CLK_Source clk_freqSource;
	CLK_TP clk_type;
	CLK_CC clk_amp;
	CLK_OL clk_type;
	unsigned short defaultval;
	unsigned short val;
}r12;

typedef enum{
	usb = 0,
	lsb,
}CH_LSB ;
typedef enum{
	dis = 0,
	enb ,
}CH_EN;
struct{
	CH_LSB chLSB;
	CH_EN chEN;
	unsigned short defaultval;
	unsigned short val;
}r13;
#endif //UNTITLED_NT1065_H
