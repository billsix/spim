/* SPIM S20 MIPS simulator.
   This file describes the MIPS instructions, the assembler pseudo
   instructions, the assembler pseudo-ops, and the spim commands.

   Copyright (C) 1990-2004 by James Larus (larus@cs.wisc.edu).
   ALL RIGHTS RESERVED.

   SPIM is distributed under the following conditions:

     You may make copies of SPIM for your own use and modify those copies.

     All copies of SPIM must retain my name and copyright notice.

     You may not sell SPIM or distributed SPIM in conjunction with a
     commerical product or service without the expressed written consent of
     James Larus.

   THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
   IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
   PURPOSE. */


/* $Header: /Software/SPIM/src/op.h 29    3/04/04 7:16a Larus $
*/


/* Type of each entry: */

#define ASM_DIR			0
#define PSEUDO_OP		1

#define BC_TYPE_INST		10
#define B1_TYPE_INST		11
#define I1t_TYPE_INST		12
#define I2_TYPE_INST		13
#define B2_TYPE_INST		14
#define I2a_TYPE_INST		15

#define R1s_TYPE_INST		20
#define R1d_TYPE_INST		21
#define R2ts_TYPE_INST		22
#define R2st_TYPE_INST		23
#define R2ds_TYPE_INST		24
#define R2td_TYPE_INST		25
#define R2sh_TYPE_INST		26
#define R3_TYPE_INST		27
#define R3sh_TYPE_INST		28

#define FP_I2a_TYPE_INST	30
#define FP_R2ds_TYPE_INST	31
#define FP_CMP_TYPE_INST	32
#define FP_R3_TYPE_INST		33
#define FP_R4_TYPE_INST		34
#define FP_MOVC_TYPE_INST	35

#define J_TYPE_INST		40
#define NOARG_TYPE_INST		42


/* Information on each keyword token that can be read by spim.	Must be
   sorted in alphabetical order. */

OP(".alias",	Y_ALIAS_DIR,	ASM_DIR,		-1)
OP(".align",	Y_ALIGN_DIR,	ASM_DIR,		-1)
OP(".ascii",	Y_ASCII_DIR,	ASM_DIR,		-1)
OP(".asciiz",	Y_ASCIIZ_DIR,	ASM_DIR,		-1)
OP(".asm0",	Y_ASM0_DIR,	ASM_DIR,		-1)
OP(".bgnb",	Y_BGNB_DIR,	ASM_DIR,		-1)
OP(".byte",	Y_BYTE_DIR,	ASM_DIR,		-1)
OP(".comm",	Y_COMM_DIR,	ASM_DIR,		-1)
OP(".data",	Y_DATA_DIR,	ASM_DIR,		-1)
OP(".double",	Y_DOUBLE_DIR,	ASM_DIR,		-1)
OP(".end",	Y_END_DIR,	ASM_DIR,		-1)
OP(".endb",	Y_ENDB_DIR,	ASM_DIR,		-1)
OP(".endr",	Y_ENDR_DIR,	ASM_DIR,		-1)
OP(".ent",	Y_ENT_DIR,	ASM_DIR,		-1)
OP(".err",	Y_ERR_DIR,	ASM_DIR,		-1)
OP(".extern",	Y_EXTERN_DIR,	ASM_DIR,		-1)
OP(".file",	Y_FILE_DIR,	ASM_DIR,		-1)
OP(".float",	Y_FLOAT_DIR,	ASM_DIR,		-1)
OP(".fmask",	Y_FMASK_DIR,	ASM_DIR,		-1)
OP(".frame",	Y_FRAME_DIR,	ASM_DIR,		-1)
OP(".globl",	Y_GLOBAL_DIR,	ASM_DIR,		-1)
OP(".half",	Y_HALF_DIR,	ASM_DIR,		-1)
OP(".kdata",	Y_K_DATA_DIR,	ASM_DIR,		-1)
OP(".ktext",	Y_K_TEXT_DIR,	ASM_DIR,		-1)
OP(".lab",	Y_LABEL_DIR,	ASM_DIR,		-1)
OP(".lcomm",	Y_LCOMM_DIR,	ASM_DIR,		-1)
OP(".livereg",	Y_LIVEREG_DIR,	ASM_DIR,		-1)
OP(".loc",	Y_LOC_DIR,	ASM_DIR,		-1)
OP(".mask",	Y_MASK_DIR,	ASM_DIR,		-1)
OP(".noalias",	Y_NOALIAS_DIR,	ASM_DIR,		-1)
OP(".option",	Y_OPTIONS_DIR,	ASM_DIR,		-1)
OP(".rdata",	Y_RDATA_DIR,	ASM_DIR,		-1)
OP(".repeat",	Y_REPEAT_DIR,	ASM_DIR,		-1)
OP(".sdata",	Y_SDATA_DIR,	ASM_DIR,		-1)
OP(".set",	Y_SET_DIR,	ASM_DIR,		-1)
OP(".space",	Y_SPACE_DIR,	ASM_DIR,		-1)
OP(".struct",	Y_STRUCT_DIR,	ASM_DIR,		-1)
OP(".text",	Y_TEXT_DIR,	ASM_DIR,		-1)
OP(".verstamp",Y_VERSTAMP_DIR,	ASM_DIR,		-1)
OP(".vreg",	Y_VREG_DIR,	ASM_DIR,		-1)
OP(".word",	Y_WORD_DIR,	ASM_DIR,		-1)
OP("abs",	Y_ABS_POP,	PSEUDO_OP,		-1)
OP("abs.d",	Y_ABS_D_OP,	FP_R2ds_TYPE_INST,	0x46200005)
OP("abs.ps",	Y_ABS_PS_OP,	FP_R2ds_TYPE_INST,	0x46600005)	/* MIPS32 Rev 2 */
OP("abs.s",	Y_ABS_S_OP,	FP_R2ds_TYPE_INST,	0x46000005)
OP("add",	Y_ADD_OP,	R3_TYPE_INST,		0x00000020)
OP("add.d",	Y_ADD_D_OP,	FP_R3_TYPE_INST,	0x46200000)
OP("add.ps",	Y_ADD_PS_OP,	FP_R3_TYPE_INST,	0x46600000)	/* MIPS32 Rev 2 */
OP("add.s",	Y_ADD_S_OP,	FP_R3_TYPE_INST,	0x46000000)
OP("addi",	Y_ADDI_OP,	I2_TYPE_INST,		0x20000000)
OP("addiu",	Y_ADDIU_OP,	I2_TYPE_INST,		0x24000000)
OP("addu",	Y_ADDU_OP,	R3_TYPE_INST,		0x00000021)
OP("alnv.ps",	Y_ALNV_PS_OP,	FP_R4_TYPE_INST,	0x4c00001e)	/* MIPS32 Rev 2 */
OP("and",	Y_AND_OP,	R3_TYPE_INST,		0x00000024)
OP("andi",	Y_ANDI_OP,	I2_TYPE_INST,		0x30000000)
OP("b",		Y_B_POP,	PSEUDO_OP,		-1)
OP("bal",	Y_BAL_POP,	PSEUDO_OP,		-1)
OP("bc1f",	Y_BC1F_OP,	BC_TYPE_INST,		0x45000000)
OP("bc1fl",	Y_BC1FL_OP,	BC_TYPE_INST,		0x45020000)	/* MIPS32 */
OP("bc1t",	Y_BC1T_OP,	BC_TYPE_INST,		0x45010000)
OP("bc1tl",	Y_BC1TL_OP,	BC_TYPE_INST,		0x45030000)	/* MIPS32 */
OP("bc2f",	Y_BC2F_OP,	BC_TYPE_INST,		0x49000000)
OP("bc2fl",	Y_BC2FL_OP,	BC_TYPE_INST,		0x49020000)	/* MIPS32 */
OP("bc2t",	Y_BC2T_OP,	BC_TYPE_INST,		0x49010000)
OP("bc2tl",	Y_BC2TL_OP,	BC_TYPE_INST,		0x49030000)	/* MIPS32 */
OP("beq",	Y_BEQ_OP,	B2_TYPE_INST,		0x10000000)
OP("beql",	Y_BEQ_OP,	B2_TYPE_INST,		0x50000000)	/* MIPS32 */
OP("beqz",	Y_BEQZ_POP,	PSEUDO_OP,		-1)
OP("bge",	Y_BGE_POP,	PSEUDO_OP,		-1)
OP("bgeu",	Y_BGEU_POP,	PSEUDO_OP,		-1)
OP("bgez",	Y_BGEZ_OP,	B1_TYPE_INST,		0x04010000)
OP("bgezal",	Y_BGEZAL_OP,	B1_TYPE_INST,		0x04110000)
OP("bgezall",	Y_BGEZALL_OP,	B1_TYPE_INST,		0x04130000)	/* MIPS32 */
OP("bgezl",	Y_BGEZL_OP,	B1_TYPE_INST,		0x04030000)	/* MIPS32 */
OP("bgt",	Y_BGT_POP,	PSEUDO_OP,		-1)
OP("bgtu",	Y_BGTU_POP,	PSEUDO_OP,		-1)
OP("bgtz",	Y_BGTZ_OP,	B1_TYPE_INST,		0x1c000000)
OP("bgtzl",	Y_BGTZL_OP,	B1_TYPE_INST,		0x5c000000)	/* MIPS32 */
OP("ble",	Y_BLE_POP,	PSEUDO_OP,		-1)
OP("bleu",	Y_BLEU_POP,	PSEUDO_OP,		-1)
OP("blez",	Y_BLEZ_OP,	B1_TYPE_INST,		0x18000000)
OP("blezl",	Y_BLEZL_OP,	B1_TYPE_INST,		0x58000000)	/* MIPS32 */
OP("blt",	Y_BLT_POP,	PSEUDO_OP,		-1)
OP("bltu",	Y_BLTU_POP,	PSEUDO_OP,		-1)
OP("bltz",	Y_BLTZ_OP,	B1_TYPE_INST,		0x04000000)
OP("bltzal",	Y_BLTZAL_OP,	B1_TYPE_INST,		0x04100000)
OP("bltzall",	Y_BLTZALL_OP,	B1_TYPE_INST,		0x04120000)	/* MIPS32 */
OP("bltzl",	Y_BLTZL_OP,	B1_TYPE_INST,		0x04020000)	/* MIPS32 */
OP("bne",	Y_BNE_OP,	B2_TYPE_INST,		0x14000000)
OP("bnel",	Y_BNEL_OP,	B2_TYPE_INST,		0x44000000)	/* MIPS32 */
OP("bnez",	Y_BNEZ_POP,	PSEUDO_OP,		-1)
OP("break",	Y_BREAK_OP,	R1d_TYPE_INST,		0x0000000d)
OP("c.eq.d",	Y_C_EQ_D_OP,	FP_CMP_TYPE_INST,	0x46200032)
OP("c.eq.ps",	Y_C_EQ_PS_OP,	FP_CMP_TYPE_INST,	0x46600032)	/* MIPS32 Rev 2 */
OP("c.eq.s",	Y_C_EQ_S_OP,	FP_CMP_TYPE_INST,	0x46000032)
OP("c.f.d",	Y_C_F_D_OP,	FP_CMP_TYPE_INST,	0x46200030)
OP("c.f.ps",	Y_C_F_PS_OP,	FP_CMP_TYPE_INST,	0x46600030)	/* MIPS32 Rev 2 */
OP("c.f.s",	Y_C_F_S_OP,	FP_CMP_TYPE_INST,	0x46000030)
OP("c.le.d",	Y_C_LE_D_OP,	FP_CMP_TYPE_INST,	0x4620003e)
OP("c.le.ps",	Y_C_LE_PS_OP,	FP_CMP_TYPE_INST,	0x4660003e)	/* MIPS32 Rev 2 */
OP("c.le.s",	Y_C_LE_S_OP,	FP_CMP_TYPE_INST,	0x4600003e)
OP("c.lt.d",	Y_C_LT_D_OP,	FP_CMP_TYPE_INST,	0x4620003c)
OP("c.lt.ps",	Y_C_LT_PS_OP,	FP_CMP_TYPE_INST,	0x4660003c)	/* MIPS32 Rev 2 */
OP("c.lt.s",	Y_C_LT_S_OP,	FP_CMP_TYPE_INST,	0x4600003c)
OP("c.nge.d",	Y_C_NGE_D_OP,	FP_CMP_TYPE_INST,	0x4620003d)
OP("c.nge.ps",	Y_C_NGE_PS_OP,	FP_CMP_TYPE_INST,	0x4660003d)	/* MIPS32 Rev 2 */
OP("c.nge.s",	Y_C_NGE_S_OP,	FP_CMP_TYPE_INST,	0x4600003d)
OP("c.ngl.d",	Y_C_NGL_D_OP,	FP_CMP_TYPE_INST,	0x4620003b)
OP("c.ngl.ps",	Y_C_NGL_PS_OP,	FP_CMP_TYPE_INST,	0x4660003b)	/* MIPS32 Rev 2 */
OP("c.ngl.s",	Y_C_NGL_S_OP,	FP_CMP_TYPE_INST,	0x4600003b)
OP("c.ngle.d",	Y_C_NGLE_D_OP,	FP_CMP_TYPE_INST,	0x46200039)
OP("c.ngle.ps",Y_C_NGLE_PS_OP,	FP_CMP_TYPE_INST,	0x46600039)	/* MIPS32 Rev 2 */
OP("c.ngle.s",	Y_C_NGLE_S_OP,	FP_CMP_TYPE_INST,	0x46000039)
OP("c.ngt.d",	Y_C_NGT_D_OP,	FP_CMP_TYPE_INST,	0x4620003f)
OP("c.ngt.ps",	Y_C_NGT_PS_OP,	FP_CMP_TYPE_INST,	0x4660003f)	/* MIPS32 Rev 2 */
OP("c.ngt.s",	Y_C_NGT_S_OP,	FP_CMP_TYPE_INST,	0x4600003f)
OP("c.ole.d",	Y_C_OLE_D_OP,	FP_CMP_TYPE_INST,	0x46200036)
OP("c.ole.ps",	Y_C_OLE_PS_OP,	FP_CMP_TYPE_INST,	0x46600036)	/* MIPS32 Rev 2 */
OP("c.ole.s",	Y_C_OLE_S_OP,	FP_CMP_TYPE_INST,	0x46000036)
OP("c.olt.d",	Y_C_OLT_D_OP,	FP_CMP_TYPE_INST,	0x46200034)
OP("c.olt.ps",	Y_C_OLT_PS_OP,	FP_CMP_TYPE_INST,	0x46600034)	/* MIPS32 Rev 2 */
OP("c.olt.s",	Y_C_OLT_S_OP,	FP_CMP_TYPE_INST,	0x46000034)
OP("c.seq.d",	Y_C_SEQ_D_OP,	FP_CMP_TYPE_INST,	0x4620003a)
OP("c.seq.ps",	Y_C_SEQ_PS_OP,	FP_CMP_TYPE_INST,	0x4660003a)	/* MIPS32 Rev 2 */
OP("c.seq.s",	Y_C_SEQ_S_OP,	FP_CMP_TYPE_INST,	0x4600003a)
OP("c.sf.d",	Y_C_SF_D_OP,	FP_CMP_TYPE_INST,	0x46200038)
OP("c.sf.ps",	Y_C_SF_PS_OP,	FP_CMP_TYPE_INST,	0x46600038)	/* MIPS32 Rev 2 */
OP("c.sf.s",	Y_C_SF_S_OP,	FP_CMP_TYPE_INST,	0x46000038)
OP("c.ueq.d",	Y_C_UEQ_D_OP,	FP_CMP_TYPE_INST,	0x46200033)
OP("c.ueq.ps",	Y_C_UEQ_PS_OP,	FP_CMP_TYPE_INST,	0x46600033)	/* MIPS32 Rev 2 */
OP("c.ueq.s",	Y_C_UEQ_S_OP,	FP_CMP_TYPE_INST,	0x46000033)
OP("c.ule.d",	Y_C_ULE_D_OP,	FP_CMP_TYPE_INST,	0x46200037)
OP("c.ule.ps",	Y_C_ULE_PS_OP,	FP_CMP_TYPE_INST,	0x46600037)	/* MIPS32 Rev 2 */
OP("c.ule.s",	Y_C_ULE_S_OP,	FP_CMP_TYPE_INST,	0x46000037)
OP("c.ult.d",	Y_C_ULT_D_OP,	FP_CMP_TYPE_INST,	0x46200035)
OP("c.ult.ps",	Y_C_ULT_PS_OP,	FP_CMP_TYPE_INST,	0x46600035)	/* MIPS32 Rev 2 */
OP("c.ult.s",	Y_C_ULT_S_OP,	FP_CMP_TYPE_INST,	0x46000035)
OP("c.un.d",	Y_C_UN_D_OP,	FP_CMP_TYPE_INST,	0x46200031)
OP("c.un.ps",	Y_C_UN_PS_OP,	FP_CMP_TYPE_INST,	0x46600031)	/* MIPS32 Rev 2 */
OP("c.un.s",	Y_C_UN_S_OP,	FP_CMP_TYPE_INST,	0x46000031)
OP("cache",	Y_CACHE_OP,	I2_TYPE_INST,		0xbc000000)	/* MIPS32 */
OP("ceil.l.d",	Y_CEIL_L_D_OP,	FP_R2ds_TYPE_INST,	0x4620000a)	/* MIPS32 Rev 2 */
OP("ceil.l.s",	Y_CEIL_L_S_OP,	FP_R2ds_TYPE_INST,	0x4600000a)	/* MIPS32 Rev 2 */
OP("ceil.w.d",	Y_CEIL_W_D_OP,	FP_R2ds_TYPE_INST,	0x4620000e)	/* MIPS32 */
OP("ceil.w.s",	Y_CEIL_W_S_OP,	FP_R2ds_TYPE_INST,	0x4600000e)	/* MIPS32 */
OP("cfc0",	Y_CFC0_OP,	R2ts_TYPE_INST,		0x40400000)
OP("cfc1",	Y_CFC1_OP,	R2ts_TYPE_INST,		0x44400000)
OP("cfc2",	Y_CFC2_OP,	R2ts_TYPE_INST,		0x48400000)
OP("clo",	Y_CLO_OP,	R3_TYPE_INST,		0x70000021)
OP("clz",	Y_CLZ_OP,	R3_TYPE_INST,		0x70000020)
OP("cop0",	Y_COP0_OP,	J_TYPE_INST,		0x40200000)
OP("cop1",	Y_COP1_OP,	J_TYPE_INST,		0x44200000)
OP("cop2",	Y_COP2_OP,	J_TYPE_INST,		0x48200000)
OP("cop3",	Y_COP3_OP,	J_TYPE_INST,		0x4c200000)
OP("ctc0",	Y_CTC0_OP,	R2ts_TYPE_INST,		0x40c00000)
OP("ctc1",	Y_CTC1_OP,	R2ts_TYPE_INST,		0x44c00000)
OP("ctc2",	Y_CTC2_OP,	R2ts_TYPE_INST,		0x48c00000)
OP("cvt.d.l",	Y_CVT_D_L_OP,	FP_R2ds_TYPE_INST,	0x46b00021)	/* MIPS32 Rev 2 */
OP("cvt.d.s",	Y_CVT_D_S_OP,	FP_R2ds_TYPE_INST,	0x46000021)
OP("cvt.d.w",	Y_CVT_D_W_OP,	FP_R2ds_TYPE_INST,	0x46200021)
OP("cvt.l.d",	Y_CVT_L_D_OP,	FP_R2ds_TYPE_INST,	0x46200025)	/* MIPS32 Rev 2 */
OP("cvt.l.s",	Y_CVT_L_S_OP,	FP_R2ds_TYPE_INST,	0x46000025)	/* MIPS32 Rev 2 */
OP("cvt.ps.s",	Y_CVT_PS_S_OP,	FP_R2ds_TYPE_INST,	0x46000026)	/* MIPS32 Rev 2 */
OP("cvt.s.d",	Y_CVT_S_D_OP,	FP_R2ds_TYPE_INST,	0x46200020)
OP("cvt.s.l",	Y_CVT_S_L_OP,	FP_R2ds_TYPE_INST,	0x46b00020)	/* MIPS32 Rev 2 */
OP("cvt.s.pl",	Y_CVT_S_PL_OP,	FP_R2ds_TYPE_INST,	0x46c00024)	/* MIPS32 Rev 2 */
OP("cvt.s.pu",	Y_CVT_S_PU_OP,	FP_R2ds_TYPE_INST,	0x46c00020)	/* MIPS32 Rev 2 */
OP("cvt.s.w",	Y_CVT_S_W_OP,	FP_R2ds_TYPE_INST,	0x46800020)
OP("cvt.w.d",	Y_CVT_W_D_OP,	FP_R2ds_TYPE_INST,	0x46200024)
OP("cvt.w.s",	Y_CVT_W_S_OP,	FP_R2ds_TYPE_INST,	0x46000024)
OP("di",	Y_DI_OP,	I1t_TYPE_INST,		0x41606000)	/* MIPS32 Rev 2 */
OP("div",	Y_DIV_OP,	R2st_TYPE_INST,		0x0000001a)
OP("div.d",	Y_DIV_D_OP,	FP_R3_TYPE_INST,	0x46200003)
OP("div.s",	Y_DIV_S_OP,	FP_R3_TYPE_INST,	0x46000003)
OP("divu",	Y_DIVU_OP,	R2st_TYPE_INST,		0x0000001b)
OP("ehb",	Y_EHB_OP,	I1t_TYPE_INST,		0x000000c0)	/* MIPS32 Rev 2 */
OP("ei",	Y_EI_OP,	I1t_TYPE_INST,		0x41606020)	/* MIPS32 Rev 2 */
OP("ext",	Y_EXT_OP,	FP_R2ds_TYPE_INST,	0x7c000000)	/* MIPS32 Rev 2 */
OP("floor.l.d",	Y_FLOOR_L_D_OP,	FP_R2ds_TYPE_INST,	0x4620000b)	/* MIPS32 Rev 2 */
OP("floor.l.s",	Y_FLOOR_L_S_OP,	FP_R2ds_TYPE_INST,	0x4600000b)	/* MIPS32 Rev 2 */
OP("floor.w.d",	Y_FLOOR_W_D_OP,	FP_R2ds_TYPE_INST,	0x4620000f)	/* MIPS32 */
OP("floor.w.s",	Y_FLOOR_W_S_OP,	FP_R2ds_TYPE_INST,	0x4600000f)	/* MIPS32 */
OP("ins",	Y_INS_OP,	FP_R2ds_TYPE_INST,	0x7c000004)	/* MIPS32 Rev 2 */
OP("j",		Y_J_OP,		J_TYPE_INST,		0x08000000)
OP("jal",	Y_JAL_OP,	J_TYPE_INST,		0x0c000000)
OP("jalr",	Y_JALR_OP,	R2ds_TYPE_INST,		0x00000009)
OP("jalr.hb",	Y_JALR_HB_OP,	R2ds_TYPE_INST,		0x00000409)	/* MIPS32 Rev 2 */
OP("jr",	Y_JR_OP,	R1s_TYPE_INST,		0x00000008)
OP("jr.hb",	Y_JR_HB_OP,	R1s_TYPE_INST,		0x00000408)	/* MIPS32 Rev 2 */
OP("la",	Y_LA_POP,	PSEUDO_OP,		-1)
OP("lb",	Y_LB_OP,	I2a_TYPE_INST,		0x80000000)
OP("lbu",	Y_LBU_OP,	I2a_TYPE_INST,		0x90000000)
OP("ld",	Y_LD_POP,	PSEUDO_OP,		-1)
OP("ldc1",	Y_LDC1_OP,	FP_I2a_TYPE_INST,	0xd4000000)	/* MIPS32 */
OP("ldc2",	Y_LDC2_OP,	I2a_TYPE_INST,		0xd8000000)	/* MIPS32 */
OP("ldxc1",	Y_LDXC1_OP,	FP_R3_TYPE_INST,	0x4c000001)	/* MIPS32 Rev 2 */
OP("lh",	Y_LH_OP,	I2a_TYPE_INST,		0x84000000)
OP("lhu",	Y_LHU_OP,	I2a_TYPE_INST,		0x94000000)
OP("li",	Y_LI_POP,	PSEUDO_OP,		-1)
OP("li.d",	Y_LI_D_POP,	PSEUDO_OP,		-1)
OP("li.s",	Y_LI_S_POP,	PSEUDO_OP,		-1)
OP("ll",	Y_LL_OP,	I2a_TYPE_INST,		0xb0000000)	/* MIPS32 */
OP("lui",	Y_LUI_OP,	I1t_TYPE_INST,		0x3c000000)
OP("luxc1",	Y_LUXC1_OP,	FP_R3_TYPE_INST,	0x4c000005)	/* MIPS32 Rev 2 */
OP("lw",	Y_LW_OP,	I2a_TYPE_INST,		0x8c000000)
OP("lwc0",	Y_LWC0_OP,	I2a_TYPE_INST,		0xc0000000)
OP("lwc1",	Y_LWC1_OP,	FP_I2a_TYPE_INST,	0xc4000000)
OP("lwc2",	Y_LWC2_OP,	I2a_TYPE_INST,		0xc8000000)
OP("lwl",	Y_LWL_OP,	I2a_TYPE_INST,		0x88000000)
OP("lwr",	Y_LWR_OP,	I2a_TYPE_INST,		0x98000000)
OP("lwxc1",	Y_LWXC1_OP,	FP_R3_TYPE_INST,	0x4c000000)	/* MIPS32 Rev 2 */
OP("madd",	Y_MADD_OP,	R2st_TYPE_INST,		0x70000000)	/* MIPS32 */
OP("madd.d",	Y_MADD_D_OP,	FP_R4_TYPE_INST,	0x4c000001)	/* MIPS32 Rev 2 */
OP("madd.ps",	Y_MADD_PS_OP,	FP_R4_TYPE_INST,	0x4c000006)	/* MIPS32 Rev 2 */
OP("madd.s",	Y_MADD_S_OP,	FP_R4_TYPE_INST,	0x4c000000)	/* MIPS32 Rev 2 */
OP("maddu",	Y_MADDU_OP,	R2st_TYPE_INST,		0x70000001)	/* MIPS32 */
OP("mfc0",	Y_MFC0_OP,	R2td_TYPE_INST,		0x40000000)
OP("mfc1",	Y_MFC1_OP,	R2ts_TYPE_INST,		0x44000000)
OP("mfc1.d",	Y_MFC1_D_POP,	PSEUDO_OP,		-1)
OP("mfc2",	Y_MFC2_OP,	R2td_TYPE_INST,		0x48000000)
OP("mfhc1",	Y_MFHC1_OP,	R2ts_TYPE_INST,		0x44600000)	/* MIPS32 Rev 2 */
OP("mfhc2",	Y_MFHC2_OP,	R2td_TYPE_INST,		0x48600000)	/* MIPS32 Rev 2 */
OP("mfhi",	Y_MFHI_OP,	R1d_TYPE_INST,		0x00000010)
OP("mflo",	Y_MFLO_OP,	R1d_TYPE_INST,		0x00000012)
OP("mov.d",	Y_MOV_D_OP,	FP_R2ds_TYPE_INST,	0x46200006)
OP("mov.ps",	Y_MOV_PS_OP,	FP_R2ds_TYPE_INST,	0x46c00006)	/* MIPS32 Rev 2 */
OP("mov.s",	Y_MOV_S_OP,	FP_R2ds_TYPE_INST,	0x46000006)
OP("move",	Y_MOVE_POP,	PSEUDO_OP,		-1)
OP("movf",	Y_MOVF_OP,	FP_MOVC_TYPE_INST,	0x00000001)	/* MIPS32 */
OP("movf.d",	Y_MOVF_D_OP,	FP_MOVC_TYPE_INST,	0x46200011)	/* MIPS32 */
OP("movf.ps",	Y_MOVF_PS_OP,	FP_MOVC_TYPE_INST,	0x46c00011)	/* MIPS32 Rev 2 */
OP("movf.s",	Y_MOVF_S_OP,	FP_MOVC_TYPE_INST,	0x46000011)	/* MIPS32 */
OP("movn",	Y_MOVN_OP,	R3_TYPE_INST,		0x0000000b)	/* MIPS32 */
OP("movn.d",	Y_MOVN_D_OP,	FP_MOVC_TYPE_INST,	0x46200013)	/* MIPS32 */
OP("movn.ps",	Y_MOVN_PS_OP,	FP_MOVC_TYPE_INST,	0x46c00013)	/* MIPS32 Rev 2 */
OP("movn.s",	Y_MOVN_S_OP,	FP_MOVC_TYPE_INST,	0x46000013)	/* MIPS32 */
OP("movt",	Y_MOVT_OP,	FP_MOVC_TYPE_INST,	0x00010001)	/* MIPS32 */
OP("movt.d",	Y_MOVT_D_OP,	FP_MOVC_TYPE_INST,	0x46210011)	/* MIPS32 */
OP("movt.ps",	Y_MOVT_PS_OP,	FP_MOVC_TYPE_INST,	0x46c10011)	/* MIPS32 Rev 2 */
OP("movt.s",	Y_MOVT_S_OP,	FP_MOVC_TYPE_INST,	0x46010011)	/* MIPS32 */
OP("movz",	Y_MOVZ_OP,	R3_TYPE_INST,		0x0000000a)	/* MIPS32 */
OP("movz.d",	Y_MOVZ_D_OP,	FP_MOVC_TYPE_INST,	0x46200012)	/* MIPS32 */
OP("movz.ps",	Y_MOVZ_PS_OP,	FP_MOVC_TYPE_INST,	0x46c00012)	/* MIPS32 Rev 2 */
OP("movz.s",	Y_MOVZ_S_OP,	FP_MOVC_TYPE_INST,	0x46000012)	/* MIPS32 */
OP("msub",	Y_MSUB_OP,	R2st_TYPE_INST,		0x70000004)	/* MIPS32 */
OP("msub.d",	Y_MSUB_D_OP,	FP_R4_TYPE_INST,	0x4c000021)	/* MIPS32 Rev 2 */
OP("msub.ps",	Y_MSUB_PS_OP,	FP_R4_TYPE_INST,	0x4c000026)	/* MIPS32 Rev 2 */
OP("msub.s",	Y_MSUB_S_OP,	FP_R4_TYPE_INST,	0x4c000020)	/* MIPS32 Rev 2 */
OP("msubu",	Y_MSUBU_OP,	R2st_TYPE_INST,		0x70000005)	/* MIPS32 */
OP("mtc0",	Y_MTC0_OP,	R2td_TYPE_INST,		0x40800000)
OP("mtc1",	Y_MTC1_OP,	R2ts_TYPE_INST,		0x44800000)
OP("mtc1.d",	Y_MTC1_D_POP,	PSEUDO_OP,		-1)
OP("mtc2",	Y_MTC2_OP,	R2td_TYPE_INST,		0x48800000)
OP("mthc1",	Y_MTHC1_OP,	R2ts_TYPE_INST,		0x44e00000)	/* MIPS32 Rev 2 */
OP("mthc2",	Y_MTHC2_OP,	R2td_TYPE_INST,		0x48e00000)	/* MIPS32 Rev 2 */
OP("mthi",	Y_MTHI_OP,	R1s_TYPE_INST,		0x00000011)
OP("mtlo",	Y_MTLO_OP,	R1s_TYPE_INST,		0x00000013)
OP("mul",	Y_MUL_POP,	PSEUDO_OP,		-1)
OP("mul.d",	Y_MUL_D_OP,	FP_R3_TYPE_INST,	0x46200002)
OP("mul.ps",	Y_MUL_PS_OP,	FP_R3_TYPE_INST,	0x46c00002)	/* MIPS32 Rev 2 */
OP("mul.s",	Y_MUL_S_OP,	FP_R3_TYPE_INST,	0x46000002)
OP("mulo",	Y_MULO_POP,	PSEUDO_OP,		-1)
OP("mulou",	Y_MULOU_POP,	PSEUDO_OP,		-1)
OP("mult",	Y_MULT_OP,	R2st_TYPE_INST,		0x00000018)
OP("multu",	Y_MULTU_OP,	R2st_TYPE_INST,		0x00000019)
OP("neg",	Y_NEG_POP,	PSEUDO_OP,		-1)
OP("neg.d",	Y_NEG_D_OP,	FP_R2ds_TYPE_INST,	0x46200007)
OP("neg.ps",	Y_NEG_PS_OP,	FP_R2ds_TYPE_INST,	0x46c00007)	/* MIPS32 Rev 2 */
OP("neg.s",	Y_NEG_S_OP,	FP_R2ds_TYPE_INST,	0x46000007)
OP("negu",	Y_NEGU_POP,	PSEUDO_OP,		-1)
OP("nmadd.d",	Y_NMADD_D_OP,	FP_R4_TYPE_INST,	0x4c000031)	/* MIPS32 Rev 2 */
OP("nmadd.ps",	Y_NMADD_PS_OP,	FP_R4_TYPE_INST,	0x4c000036)	/* MIPS32 Rev 2 */
OP("nmadd.s",	Y_NMADD_S_OP,	FP_R4_TYPE_INST,	0x4c000030)	/* MIPS32 Rev 2 */
OP("nmsub.d",	Y_NMSUB_D_OP,	FP_R4_TYPE_INST,	0x4c000039)	/* MIPS32 Rev 2 */
OP("nmsub.ps",	Y_NMSUB_PS_OP,	FP_R4_TYPE_INST,	0x4c00003e)	/* MIPS32 Rev 2 */
OP("nmsub.s",	Y_NMSUB_S_OP,	FP_R4_TYPE_INST,	0x4c000038)	/* MIPS32 Rev 2 */
OP("nop",	Y_NOP_POP,	PSEUDO_OP,		-1)
OP("nor",	Y_NOR_OP,	R3_TYPE_INST,		0x00000027)
OP("not",	Y_NOT_POP,	PSEUDO_OP,		-1)
OP("or",	Y_OR_OP,	R3_TYPE_INST,		0x00000025)
OP("ori",	Y_ORI_OP,	I2_TYPE_INST,		0x34000000)
OP("pll.ps",	Y_PLL_PS_OP,	FP_R3_TYPE_INST,	0x46c0002c)	/* MIPS32 Rev 2 */
OP("plu.ps",	Y_PLU_PS_OP,	FP_R3_TYPE_INST,	0x46c0002d)	/* MIPS32 Rev 2 */
OP("pref",	Y_PREF_OP,	I2_TYPE_INST,		0xbb000000)	/* MIPS32 */
OP("prefx",	Y_PREFX_OP,	R2st_TYPE_INST,		0x4600000f)	/* MIPS32 Rev 2 */
OP("pul.ps",	Y_PUL_PS_OP,	FP_R3_TYPE_INST,	0x46c0002e)	/* MIPS32 Rev 2 */
OP("puu.ps",	Y_PUU_PS_OP,	FP_R3_TYPE_INST,	0x46c0002f)	/* MIPS32 Rev 2 */
OP("rdhwr",	Y_RDHWR_OP,	R3_TYPE_INST,		0x7c00003b)	/* MIPS32 Rev 2 */
OP("rdpgpr",	Y_RDPGPR_OP,	R2td_TYPE_INST,		0x41400000)	/* MIPS32 Rev 2 */
OP("recip.d",	Y_RECIP_D_OP,	FP_R2ds_TYPE_INST,	0x46200015)	/* MIPS32 Rev 2 */
OP("recip.s",	Y_RECIP_S_OP,	FP_R2ds_TYPE_INST,	0x46000015)	/* MIPS32 Rev 2 */
OP("rem",	Y_REM_POP,	PSEUDO_OP,		-1)
OP("remu",	Y_REMU_POP,	PSEUDO_OP,		-1)
OP("rfe",	Y_RFE_OP,	NOARG_TYPE_INST,	0x42000010)
OP("rol",	Y_ROL_POP,	PSEUDO_OP,		-1)
OP("ror",	Y_ROR_POP,	PSEUDO_OP,		-1)
OP("rotr",	Y_ROTR_OP,	R2sh_TYPE_INST,		0x00200002)	/* MIPS32 Rev 2 */
OP("rotrv",	Y_ROTRV_OP,	R2sh_TYPE_INST,		0x00200003)	/* MIPS32 Rev 2 */
OP("round.l.d",	Y_ROUND_L_D_OP,	FP_R2ds_TYPE_INST,	0x46200008)	/* MIPS32 Rev 2 */
OP("round.l.s",	Y_ROUND_L_S_OP,	FP_R2ds_TYPE_INST,	0x46000008)	/* MIPS32 Rev 2 */
OP("round.w.d",	Y_ROUND_W_D_OP,	FP_R2ds_TYPE_INST,	0x4620000b)	/* MIPS32 */
OP("round.w.s",	Y_ROUND_W_S_OP,	FP_R2ds_TYPE_INST,	0x4600000b)	/* MIPS32 */
OP("rsqrt.d",	Y_RSQRT_D_OP,	FP_R2ds_TYPE_INST,	0x46200016)	/* MIPS32 Rev 2 */
OP("rsqrt.s",	Y_RSQRT_S_OP,	FP_R2ds_TYPE_INST,	0x46000016)	/* MIPS32 Rev 2 */
OP("sb",	Y_SB_OP,	I2a_TYPE_INST,		0xa0000000)
OP("sc",	Y_SC_OP,	I2a_TYPE_INST,		0xe0000000)	/* MIPS32 */
OP("sd",	Y_SD_POP,	PSEUDO_OP,		-1)
OP("sdxc1",	Y_SDXC1_OP,	FP_R3_TYPE_INST,	0x46000009)	/* MIPS32 Rev 2 */
OP("seb",	Y_SEB_OP,	R2td_TYPE_INST,		0x7c000420)	/* MIPS32 Rev 2 */
OP("seh",	Y_SEH_OP,	R2td_TYPE_INST,		0x7c000620)	/* MIPS32 Rev 2 */
OP("seq",	Y_SEQ_POP,	PSEUDO_OP,		-1)
OP("sge",	Y_SGE_POP,	PSEUDO_OP,		-1)
OP("sgeu",	Y_SGEU_POP,	PSEUDO_OP,		-1)
OP("sgt",	Y_SGT_POP,	PSEUDO_OP,		-1)
OP("sgtu",	Y_SGTU_POP,	PSEUDO_OP,		-1)
OP("sh",	Y_SH_OP,	I2a_TYPE_INST,		0xa4000000)
OP("sle",	Y_SLE_POP,	PSEUDO_OP,		-1)
OP("sleu",	Y_SLEU_POP,	PSEUDO_OP,		-1)
OP("sll",	Y_SLL_OP,	R2sh_TYPE_INST,		0x00000000)
OP("sllv",	Y_SLLV_OP,	R3sh_TYPE_INST,		0x00000004)
OP("slt",	Y_SLT_OP,	R3_TYPE_INST,		0x0000002a)
OP("slti",	Y_SLTI_OP,	I2_TYPE_INST,		0x28000000)
OP("sltiu",	Y_SLTIU_OP,	I2_TYPE_INST,		0x2c000000)
OP("sltu",	Y_SLTU_OP,	R3_TYPE_INST,		0x0000002b)
OP("sne",	Y_SNE_POP,	PSEUDO_OP,		-1)
OP("sra",	Y_SRA_OP,	R2sh_TYPE_INST,		0x00000003)
OP("srav",	Y_SRAV_OP,	R3sh_TYPE_INST,		0x00000007)
OP("srl",	Y_SRL_OP,	R2sh_TYPE_INST,		0x00000002)
OP("srlv",	Y_SRLV_OP,	R3sh_TYPE_INST,		0x00000006)
OP("sub",	Y_SUB_OP,	R3_TYPE_INST,		0x00000022)
OP("sub.d",	Y_SUB_D_OP,	FP_R3_TYPE_INST,	0x46200001)
OP("sub.ps",	Y_SUB_PS_OP,	FP_R3_TYPE_INST,	0x46600001)	/* MIPS32 Rev 2 */
OP("sub.s",	Y_SUB_S_OP,	FP_R3_TYPE_INST,	0x46000001)
OP("subu",	Y_SUBU_OP,	R3_TYPE_INST,		0x00000023)
OP("suxc1",	Y_SUXC1_OP,	FP_R3_TYPE_INST,	0x4600000d)	/* MIPS32 Rev 2 */
OP("sw",	Y_SW_OP,	I2a_TYPE_INST,		0xac000000)
OP("swc0",	Y_SWC0_OP,	I2a_TYPE_INST,		0xe0000000)
OP("swc1",	Y_SWC1_OP,	FP_I2a_TYPE_INST,	0xe4000000)
OP("swc2",	Y_SWC2_OP,	I2a_TYPE_INST,		0xe8000000)
OP("swl",	Y_SWL_OP,	I2a_TYPE_INST,		0xa8000000)
OP("swr",	Y_SWR_OP,	I2a_TYPE_INST,		0xb8000000)
OP("swxc1",	Y_SWXC1_OP,	FP_R3_TYPE_INST,	0x46000008)	/* MIPS32 Rev 2 */
OP("synci",	Y_SYNCI_OP,	I2_TYPE_INST,		0x04140000)	/* MIPS32 Rev 2 */
OP("syscall",	Y_SYSCALL_OP,	NOARG_TYPE_INST,	0x0000000c)
OP("tlbp",	Y_TLBP_OP,	NOARG_TYPE_INST,	0x42000008)
OP("tlbr",	Y_TLBR_OP,	NOARG_TYPE_INST,	0x42000001)
OP("tlbwi",	Y_TLBWI_OP,	NOARG_TYPE_INST,	0x42000002)
OP("tlbwr",	Y_TLBWR_OP,	NOARG_TYPE_INST,	0x42000006)
OP("trunc.l.d",	Y_TRUNC_L_D_OP,	FP_R2ds_TYPE_INST,	0x46200009)	/* MIPS32 Rev 2 */
OP("trunc.l.s",	Y_TRUNC_L_S_OP,	FP_R2ds_TYPE_INST,	0x46000009)	/* MIPS32 Rev 2 */
OP("trunc.w.d",	Y_TRUNC_W_D_OP,	FP_R2ds_TYPE_INST,	0x4620000c)	/* MIPS32 */
OP("trunc.w.s",	Y_TRUNC_W_S_OP,	FP_R2ds_TYPE_INST,	0x4600000c)	/* MIPS32 */
OP("ulh",	Y_ULH_POP,	PSEUDO_OP,		-1)
OP("ulhu",	Y_ULHU_POP,	PSEUDO_OP,		-1)
OP("ulw",	Y_ULW_POP,	PSEUDO_OP,		-1)
OP("ush",	Y_USH_POP,	PSEUDO_OP,		-1)
OP("usw",	Y_USW_POP,	PSEUDO_OP,		-1)
OP("wrpgpr",	Y_WRPGPR_OP,	R2td_TYPE_INST,		0x41c00000)	/* MIPS32 Rev 2 */
OP("wsbh",	Y_WSBH_OP,	R2td_TYPE_INST,		0x7c0000a0)	/* MIPS32 Rev 2 */
OP("xor",	Y_XOR_OP,	R3_TYPE_INST,		0x00000026)
OP("xori",	Y_XORI_OP,	I2_TYPE_INST,		0x38000000)
