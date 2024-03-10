==========ELF Information==========
Type: ELF64
Encoding: Little Endian
ISA: RISC-V(0xf3)
Number of Sections: 15
ID	Name		Address	Size
[0]	            	0x0	0
[1]	.text       	0x100e8	8392
[2]	.rodata     	0x121b0	15
[3]	.eh_frame   	0x13000	4
[4]	.init_array 	0x13008	16
[5]	.fini_array 	0x13018	8
[6]	.data       	0x13020	2432
[7]	.sdata      	0x139a0	32
[8]	.sbss       	0x139c0	56
[9]	.bss        	0x139f8	1416
[10]	.comment    	0x0	45
[11]	.riscv.attributes	0x0	28
[12]	.symtab     	0x0	4632
[13]	.strtab     	0x0	1478
[14]	.shstrtab   	0x0	126
Number of Segments: 3
ID	Flags	Address	FSize	MSize
[0]	0x4	0x0	28	0
[1]	0x5	0x10000	8639	8639
[2]	0x6	0x13000	2496	3968
===================================
Memory Pages: 
0x0-0x400000:
  0x10000-0x11000
  0x11000-0x12000
  0x12000-0x13000
  0x13000-0x14000
Fetched instruction 0x00003197 at address 0x1012c
Decode: Bubble
Execute: 0 Bubble
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10130
00:         0 	ra:         0 	sp:  80000000 	gp:         0 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:         0 	a2:         0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x6f418193 at address 0x10130
Decoded 0x0 instruction 0x00003197 as auipc gp,3
Execute: 0 Bubble
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10134
00:         0 	ra:         0 	sp:  80000000 	gp:         0 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:         0 	a2:         0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x1a018513 at address 0x10134
Decoded 0x1012c instruction 0x6f418193 as addi gp,gp,1780
Execute: 0,  auipc
  Forward Data gp to Decode op1
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10138
00:         0 	ra:         0 	sp:  80000000 	gp:         0 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:         0 	a2:         0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x76018613 at address 0x10138
Decoded 0x10130 instruction 0x1a018513 as addi a0,gp,416
Execute: 1012c,  addi
  Forward Data gp to Decode op1
Memory Access: 0,  auipc
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x1013c
00:         0 	ra:         0 	sp:  80000000 	gp:         0 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:         0 	a2:         0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x40a60633 at address 0x1013c
Decoded 0x10134 instruction 0x76018613 as addi a2,gp,1888
Execute: 10130,  addi
Memory Access: 1012c,  addi
  Forward Data gp to Decode op1
WriteBack: 1012c auipc
-------------------------- CPU STATE -------------------------
PC: 0x10140
00:         0 	ra:         0 	sp:  80000000 	gp:     1312c 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:         0 	a2:         0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000593 at address 0x10140
Decoded 0x10138 instruction 0x40a60633 as sub a2,a2,a0
Execute: 10134,  addi
  Forward Data a2 to Decode op1
Memory Access: 10130,  addi
  Forward Data a0 to Decode op2
WriteBack: 10130 addi
-------------------------- CPU STATE -------------------------
PC: 0x10144
00:         0 	ra:         0 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:         0 	a2:         0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x269000ef at address 0x10144
Decoded 0x1013c instruction 0x00000593 as addi a1,00,0
Execute: 10138,  sub
Memory Access: 10134,  addi
WriteBack: 10134 addi
-------------------------- CPU STATE -------------------------
PC: 0x10148
00:         0 	ra:         0 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00001517 at address 0x10148
Decoded 0x10140 instruction 0x269000ef as jal ra,2664
Execute: 1013c,  addi
Memory Access: 10138,  sub
WriteBack: 10138 addi
-------------------------- CPU STATE -------------------------
PC: 0x1014c
00:         0 	ra:         0 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:     13f80 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xc7c50513 at address 0x1014c
Decoded 0x10144 instruction 0x00001517 as auipc a0,1
Execute: 10140,  jal
Memory Access: 1013c,  addi
WriteBack: 1013c sub
-------------------------- CPU STATE -------------------------
PC: 0x10bac
00:         0 	ra:         0 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00f00313 at address 0x10bac
Decode: Bubble
Execute: 10148 Bubble
Memory Access: 10140,  jal
WriteBack: 10140 addi
-------------------------- CPU STATE -------------------------
PC: 0x10bb0
00:         0 	ra:         0 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00050713 at address 0x10bb0
Decoded 0x0 instruction 0x00f00313 as addi t1,00,15
Execute: 0 Bubble
Memory Access: 10bac,  Bubble
WriteBack: 10bac jal
-------------------------- CPU STATE -------------------------
PC: 0x10bb4
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x02c37a63 at address 0x10bb4
Decoded 0x10bac instruction 0x00050713 as addi a4,a0,0
Execute: 0,  addi
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10bb8
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00f77793 at address 0x10bb8
rs1 = 0
rs2 = 5c0
Decoded 0x10bb0 instruction 0x02c37a63 as bgeu t1,a2,52
Execute: 10bac,  addi
Memory Access: 0,  addi
  Forward Data t1 to Decode op1
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10bbc
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         0 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x0a079063 at address 0x10bbc
Decoded 0x10bb4 instruction 0x00f77793 as andi a5,a4,15
Execute: 10bb0,  bgeu
Memory Access: 10bac,  addi
  Forward Data a4 to Decode op1
WriteBack: 10bac addi
-------------------------- CPU STATE -------------------------
PC: 0x10bc0
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:         0 	a4:         0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x06059e63 at address 0x10bc0
rs1 = 0
rs2 = 0
Decoded 0x10bb8 instruction 0x0a079063 as bne a5,00,160
Execute: 10bb4,  andi
  Forward Data a5 to Decode op1
Memory Access: 10bb0,  bgeu
WriteBack: 10bb0 addi
-------------------------- CPU STATE -------------------------
PC: 0x10bc4
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:         0 	a4:     139c0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xff067693 at address 0x10bc4
rs1 = 0
rs2 = 0
Decoded 0x10bbc instruction 0x06059e63 as bne a1,00,124
Execute: 10bb8,  bne
Memory Access: 10bb4,  andi
WriteBack: 10bb4 bgeu
-------------------------- CPU STATE -------------------------
PC: 0x10bc8
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:         0 	a4:     139c0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00f67613 at address 0x10bc8
Decoded 0x10bc0 instruction 0xff067693 as andi a3,a2,-16
Execute: 10bbc,  bne
Memory Access: 10bb8,  bne
WriteBack: 10bb8 andi
-------------------------- CPU STATE -------------------------
PC: 0x10bcc
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:         0 	a4:     139c0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00e686b3 at address 0x10bcc
Decoded 0x10bc4 instruction 0x00f67613 as andi a2,a2,15
Execute: 10bc0,  andi
Memory Access: 10bbc,  bne
WriteBack: 10bbc bne
-------------------------- CPU STATE -------------------------
PC: 0x10bd0
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:         0 	a4:     139c0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00b73023 at address 0x10bd0
Decoded 0x10bc8 instruction 0x00e686b3 as add a3,a3,a4
Execute: 10bc4,  andi
Memory Access: 10bc0,  andi
  Forward Data a3 to Decode op1
WriteBack: 10bc0 bne
-------------------------- CPU STATE -------------------------
PC: 0x10bd4
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:         0 	a4:     139c0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00b73423 at address 0x10bd4
Decoded 0x10bcc instruction 0x00b73023 as sd a1,0(a4)
Execute: 10bc8,  add
Memory Access: 10bc4,  andi
WriteBack: 10bc4 andi
-------------------------- CPU STATE -------------------------
PC: 0x10bd8
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:       5c0 	a3:       5c0 	a4:     139c0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01070713 at address 0x10bd8
Decoded 0x10bd0 instruction 0x00b73423 as sd a1,8(a4)
Execute: 10bcc,  sd
Memory Access: 10bc8,  add
WriteBack: 10bc8 andi
-------------------------- CPU STATE -------------------------
PC: 0x10bdc
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:       5c0 	a4:     139c0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xfed76ae3 at address 0x10bdc
Decoded 0x10bd4 instruction 0x01070713 as addi a4,a4,16
Execute: 10bd0,  sd
Memory Access: 10bcc,  sd
WriteBack: 10bcc add
-------------------------- CPU STATE -------------------------
PC: 0x10be0
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     13f80 	a4:     139c0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00061463 at address 0x10be0
rs1 = 139c0
rs2 = 13f80
Decoded 0x10bd8 instruction 0xfed76ae3 as bltu a4,a3,-12
Execute: 10bd4,  addi
  Forward Data a4 to Decode op1
Memory Access: 10bd0,  sd
WriteBack: 10bd0 sd
-------------------------- CPU STATE -------------------------
PC: 0x10be4
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     13f80 	a4:     139c0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00008067 at address 0x10be4
rs1 = 0
rs2 = 0
Decoded 0x10bdc instruction 0x00061463 as bne a2,00,8
Execute: 10bd8,  bltu
Memory Access: 10bd4,  addi
WriteBack: 10bd4 sd
-------------------------- CPU STATE -------------------------
PC: 0x10be8
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     13f80 	a4:     139c0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x40c306b3 at address 0x10be8
Decode: Bubble
Execute: 10be0 Bubble
Memory Access: 10bd8,  bltu
WriteBack: 10bd8 addi
-------------------------- CPU STATE -------------------------
PC: 0x10bec
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     13f80 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00269693 at address 0x10bec
Decoded 0x0 instruction 0x40c306b3 as sub a3,t1,a2
Execute: 0 Bubble
Memory Access: 10bd0,  Bubble
WriteBack: 10bd0 bltu
-------------------------- CPU STATE -------------------------
PC: 0x10bf0
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     13f80 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000297 at address 0x10bf0
Decoded 0x10be8 instruction 0x00269693 as slli a3,a3,2
Execute: 0,  sub
  Forward Data a3 to Decode op1
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10bf4
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     13f80 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x005686b3 at address 0x10bf4
Decoded 0x10bec instruction 0x00000297 as auipc t0,0
Execute: 10be8,  slli
Memory Access: 0,  sub
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10bf8
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     13f80 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00c68067 at address 0x10bf8
Decoded 0x10bf0 instruction 0x005686b3 as add a3,a3,t0
Execute: 10bec,  auipc
  Forward Data t0 to Decode op2
Memory Access: 10be8,  slli
  Forward Data a3 to Decode op1
WriteBack: 10be8 sub
-------------------------- CPU STATE -------------------------
PC: 0x10bfc
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:         f 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00b70723 at address 0x10bfc
Decoded 0x10bf4 instruction 0x00c68067 as jalr 00,a3,12
Execute: 10bf0,  add
  Forward Data a3 to Decode op1
Memory Access: 10bec,  auipc
WriteBack: 10bec slli
-------------------------- CPU STATE -------------------------
PC: 0x10c00
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:         0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:        3c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00b706a3 at address 0x10c00
Decoded 0x10bf8 instruction 0x00b70723 as sb a1,14(a4)
Execute: 10bf4,  jalr
Memory Access: 10bf0,  add
WriteBack: 10bf0 auipc
-------------------------- CPU STATE -------------------------
PC: 0x10c38
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:        3c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00008067 at address 0x10c38
Decode: Bubble
Execute: 10bfc Bubble
Memory Access: 10bf4,  jalr
WriteBack: 10bf4 add
-------------------------- CPU STATE -------------------------
PC: 0x10c3c
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x0ff5f593 at address 0x10c3c
Decoded 0x0 instruction 0x00008067 as jalr 00,ra,0
Execute: 0 Bubble
Memory Access: 10c38,  Bubble
WriteBack: 10c38 jalr
-------------------------- CPU STATE -------------------------
PC: 0x10c40
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00859693 at address 0x10c40
Decoded 0x10c38 instruction 0x0ff5f593 as andi a1,a1,255
Execute: 0,  jalr
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10148
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00001517 at address 0x10148
Decode: Bubble
Execute: 10c3c Bubble
Memory Access: 0,  jalr
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x1014c
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xc7c50513 at address 0x1014c
Decoded 0x0 instruction 0x00001517 as auipc a0,1
Execute: 0 Bubble
Memory Access: 10148,  Bubble
WriteBack: 10148 jalr
-------------------------- CPU STATE -------------------------
PC: 0x10150
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00050863 at address 0x10150
Decoded 0x10148 instruction 0xc7c50513 as addi a0,a0,-900
Execute: 0,  auipc
  Forward Data a0 to Decode op1
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10154
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00002517 at address 0x10154
rs1 = 139c0
rs2 = 0
Decoded 0x1014c instruction 0x00050863 as beq a0,00,16
Execute: 10148,  addi
  Forward Data a0 to Decode op1
Memory Access: 0,  auipc
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10158
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     139c0 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xd9850513 at address 0x10158
Decoded 0x10150 instruction 0x00002517 as auipc a0,2
Execute: 1014c,  beq
Memory Access: 10148,  addi
WriteBack: 10148 auipc
-------------------------- CPU STATE -------------------------
PC: 0x1015c
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     11148 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x469000ef at address 0x1015c
Decoded 0x10154 instruction 0xd9850513 as addi a0,a0,-616
Execute: 10150,  auipc
  Forward Data a0 to Decode op1
Memory Access: 1014c,  beq
WriteBack: 1014c addi
-------------------------- CPU STATE -------------------------
PC: 0x10160
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     10dc4 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x1b1000ef at address 0x10160
Decoded 0x10158 instruction 0x469000ef as jal ra,3176
Execute: 10154,  addi
Memory Access: 10150,  auipc
WriteBack: 10150 beq
-------------------------- CPU STATE -------------------------
PC: 0x10164
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     10dc4 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00012503 at address 0x10164
Decoded 0x1015c instruction 0x1b1000ef as jal ra,2480
Execute: 10158,  jal
Memory Access: 10154,  addi
WriteBack: 10154 auipc
-------------------------- CPU STATE -------------------------
PC: 0x10dc4
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     12154 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00050593 at address 0x10dc4
Decode: Bubble
Execute: 10160 Bubble
Memory Access: 10158,  jal
WriteBack: 10158 addi
-------------------------- CPU STATE -------------------------
PC: 0x10dc8
00:         0 	ra:     10148 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     11eec 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000693 at address 0x10dc8
Decoded 0x0 instruction 0x00050593 as addi a1,a0,0
Execute: 0 Bubble
Memory Access: 10dc4,  Bubble
WriteBack: 10dc4 jal
-------------------------- CPU STATE -------------------------
PC: 0x10dcc
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     11eec 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000613 at address 0x10dcc
Decoded 0x10dc4 instruction 0x00000693 as addi a3,00,0
Execute: 0,  addi
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10dd0
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     11eec 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000513 at address 0x10dd0
Decoded 0x10dc8 instruction 0x00000613 as addi a2,00,0
Execute: 10dc4,  addi
Memory Access: 0,  addi
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10dd4
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     11eec 	a1:         0 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x1740106f at address 0x10dd4
Decoded 0x10dcc instruction 0x00000513 as addi a0,00,0
Execute: 10dc8,  addi
Memory Access: 10dc4,  addi
WriteBack: 10dc4 addi
-------------------------- CPU STATE -------------------------
PC: 0x10dd8
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     11eec 	a1:     11eec 	a2:         0 	a3:     10c2c 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xfd010113 at address 0x10dd8
Decoded 0x10dd0 instruction 0x1740106f as jal 00,4468
Execute: 10dcc,  addi
Memory Access: 10dc8,  addi
WriteBack: 10dc8 addi
-------------------------- CPU STATE -------------------------
PC: 0x10ddc
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     11eec 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01313423 at address 0x10ddc
Decoded 0x10dd4 instruction 0xfd010113 as addi sp,sp,-48
Execute: 10dd0,  jal
Memory Access: 10dcc,  addi
WriteBack: 10dcc addi
-------------------------- CPU STATE -------------------------
PC: 0x11f48
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:     11eec 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x1b01b783 at address 0x11f48
Decode: Bubble
Execute: 10dd8 Bubble
Memory Access: 10dd0,  jal
WriteBack: 10dd0 addi
-------------------------- CPU STATE -------------------------
PC: 0x11f4c
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x06078063 at address 0x11f4c
Decoded 0x0 instruction 0x1b01b783 as ld a5,432(gp)
Execute: 0 Bubble
Memory Access: 11f48,  Bubble
WriteBack: 11f48 jal
-------------------------- CPU STATE -------------------------
PC: 0x11f50
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x0087a703 at address 0x11f50
rs1 = 0
rs2 = 0
Decoded 0x11f48 instruction 0x06078063 as beq a5,00,96
Execute: 0,  ld
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x11f54
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01f00813 at address 0x11f54
Decode: Stall
Execute: 11f4c Stall
Memory Access: 0,  ld
  Forward Data a5 to Decode op2
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x11f54
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01f00813 at address 0x11f54
Decode: Stall
Execute: 11f4c Stall
Memory Access: 11f48,  Bubble
WriteBack: 11f48 ld
-------------------------- CPU STATE -------------------------
PC: 0x11f54
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01f00813 at address 0x11f54
Decoded 0x11f4c instruction 0x0087a703 as lw a4,8(a5)
Execute: 0,  beq
BEQMemory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x11fac
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x44818813 at address 0x11fac
Decode: Bubble
Execute: 11f50 Bubble
Memory Access: 0,  beq
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x11fb0
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x1b01b823 at address 0x11fb0
Decoded 0x0 instruction 0x44818813 as addi a6,gp,1096
Execute: 0 Bubble
Memory Access: 11fac,  Bubble
WriteBack: 11fac beq
-------------------------- CPU STATE -------------------------
PC: 0x11fb4
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x44818793 at address 0x11fb4
Decoded 0x11fac instruction 0x1b01b823 as sd a6,432(gp)
Execute: 0,  addi
  Forward Data a6 to Decode op2
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x11fb8
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xf99ff06f at address 0x11fb8
Decoded 0x11fb0 instruction 0x44818793 as addi a5,gp,1096
Execute: 11fac,  sd
Memory Access: 0,  addi
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x11fbc
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:         0 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x3147a683 at address 0x11fbc
Decoded 0x11fb4 instruction 0xf99ff06f as jal 00,-104
Execute: 11fb0,  addi
Memory Access: 11fac,  sd
WriteBack: 11fac addi
-------------------------- CPU STATE -------------------------
PC: 0x11fc0
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:     13c68 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000513 at address 0x11fc0
Decoded 0x11fb8 instruction 0x3147a683 as lw a3,788(a5)
Execute: 11fb4,  jal
Memory Access: 11fb0,  addi
  Forward Data a5 to Decode op1
WriteBack: 11fb0 sd
-------------------------- CPU STATE -------------------------
PC: 0x11f50
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:         0 	a6:     13c68 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x0087a703 at address 0x11f50
Decode: Bubble
Execute: 11fbc Bubble
Memory Access: 11fb4,  jal
WriteBack: 11fb4 addi
-------------------------- CPU STATE -------------------------
PC: 0x11f54
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:     13c68 	a6:     13c68 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01f00813 at address 0x11f54
Decoded 0x0 instruction 0x0087a703 as lw a4,8(a5)
Execute: 0 Bubble
Memory Access: 11f50,  Bubble
WriteBack: 11f50 jal
-------------------------- CPU STATE -------------------------
PC: 0x11f58
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:     13c68 	a6:     13c68 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x08e84863 at address 0x11f58
Decoded 0x11f50 instruction 0x01f00813 as addi a6,00,31
Execute: 0,  lw
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x11f5c
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:     13c68 	a6:     13c68 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x02050863 at address 0x11f5c
rs1 = 13c68
rs2 = 139d0
Decoded 0x11f54 instruction 0x08e84863 as blt a6,a4,144
Execute: 11f50,  addi
  Forward Data a6 to Decode op1
Memory Access: 0,  lw
  Forward Data a4 to Decode op2
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x11f60
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:     139d0 	
a5:     13c68 	a6:     13c68 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00371813 at address 0x11f60
rs1 = 0
rs2 = 0
Decoded 0x11f58 instruction 0x02050863 as beq a0,00,48
Execute: 11f54,  blt
Memory Access: 11f50,  addi
WriteBack: 11f50 lw
-------------------------- CPU STATE -------------------------
PC: 0x11f64
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:         0 	
a5:     13c68 	a6:     13c68 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01078833 at address 0x11f64
Decoded 0x11f5c instruction 0x00371813 as slli a6,a4,3
Execute: 11f58,  beq
BEQMemory Access: 11f54,  blt
WriteBack: 11f54 addi
-------------------------- CPU STATE -------------------------
PC: 0x11f8c
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:         0 	
a5:     13c68 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00270693 at address 0x11f8c
Decode: Bubble
Execute: 11f60 Bubble
Memory Access: 11f58,  beq
WriteBack: 11f58 blt
-------------------------- CPU STATE -------------------------
PC: 0x11f90
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:         0 	
a5:     13c68 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00369693 at address 0x11f90
Decoded 0x0 instruction 0x00270693 as addi a3,a4,2
Execute: 0 Bubble
Memory Access: 11f8c,  Bubble
WriteBack: 11f8c beq
-------------------------- CPU STATE -------------------------
PC: 0x11f94
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:         0 	
a5:     13c68 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x0017071b at address 0x11f94
Decoded 0x11f8c instruction 0x00369693 as slli a3,a3,3
Execute: 0,  addi
  Forward Data a3 to Decode op1
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x11f98
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:         0 	
a5:     13c68 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00e7a423 at address 0x11f98
Decoded 0x11f90 instruction 0x0017071b as addiw a4,a4,1
Execute: 11f8c,  slli
Memory Access: 0,  addi
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x11f9c
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         0 	a4:         0 	
a5:     13c68 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00d787b3 at address 0x11f9c
Decoded 0x11f94 instruction 0x00e7a423 as sw a4,8(a5)
Execute: 11f90,  addiw
  Forward Data a4 to Decode op2
Memory Access: 11f8c,  slli
WriteBack: 11f8c addi
-------------------------- CPU STATE -------------------------
PC: 0x11fa0
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:         2 	a4:         0 	
a5:     13c68 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00b7b023 at address 0x11fa0
Decoded 0x11f98 instruction 0x00d787b3 as add a5,a5,a3
Execute: 11f94,  sw
Memory Access: 11f90,  addiw
WriteBack: 11f90 slli
  Forward Data a3 to Decode op2
-------------------------- CPU STATE -------------------------
PC: 0x11fa4
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         0 	
a5:     13c68 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000513 at address 0x11fa4
Decoded 0x11f9c instruction 0x00b7b023 as sd a1,0(a5)
Execute: 11f98,  add
  Forward Data a5 to Decode op1
Memory Access: 11f94,  sw
WriteBack: 11f94 addiw
-------------------------- CPU STATE -------------------------
PC: 0x11fa8
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c68 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00008067 at address 0x11fa8
Decoded 0x11fa0 instruction 0x00000513 as addi a0,00,0
Execute: 11f9c,  sd
Memory Access: 11f98,  add
WriteBack: 11f98 sw
-------------------------- CPU STATE -------------------------
PC: 0x11fac
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c68 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x44818813 at address 0x11fac
Decoded 0x11fa4 instruction 0x00008067 as jalr 00,ra,0
Execute: 11fa0,  addi
Memory Access: 11f9c,  sd
WriteBack: 11f9c add
-------------------------- CPU STATE -------------------------
PC: 0x11fb0
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c78 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x1b01b823 at address 0x11fb0
Decoded 0x11fa8 instruction 0x44818813 as addi a6,gp,1096
Execute: 11fa4,  jalr
Memory Access: 11fa0,  addi
WriteBack: 11fa0 sd
-------------------------- CPU STATE -------------------------
PC: 0x10160
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c78 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x1b1000ef at address 0x10160
Decode: Bubble
Execute: 11fac Bubble
Memory Access: 11fa4,  jalr
WriteBack: 11fa4 addi
-------------------------- CPU STATE -------------------------
PC: 0x10164
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c78 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00012503 at address 0x10164
Decoded 0x0 instruction 0x1b1000ef as jal ra,2480
Execute: 0 Bubble
Memory Access: 10160,  Bubble
WriteBack: 10160 jalr
-------------------------- CPU STATE -------------------------
PC: 0x10168
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c78 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00810593 at address 0x10168
Decoded 0x10160 instruction 0x00012503 as lw a0,0(sp)
Execute: 0,  jal
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b10
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c78 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xfe010113 at address 0x10b10
Decode: Bubble
Execute: 10164 Bubble
Memory Access: 0,  jal
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b14
00:         0 	ra:     10160 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c78 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00813823 at address 0x10b14
Decoded 0x0 instruction 0xfe010113 as addi sp,sp,-32
Execute: 0 Bubble
Memory Access: 10b10,  Bubble
WriteBack: 10b10 jal
-------------------------- CPU STATE -------------------------
PC: 0x10b18
00:         0 	ra:     10164 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c78 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x000137b7 at address 0x10b18
Decoded 0x10b10 instruction 0x00813823 as sd s0,16(sp)
Execute: 0,  addi
  Forward Data sp to Decode op1
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b1c
00:         0 	ra:     10164 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c78 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00013437 at address 0x10b1c
Decoded 0x10b14 instruction 0x000137b7 as lui a5,19
Execute: 10b10,  sd
Memory Access: 0,  addi
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b20
00:         0 	ra:     10164 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c78 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01213023 at address 0x10b20
Decoded 0x10b18 instruction 0x00013437 as lui s0,19
Execute: 10b14,  lui
Memory Access: 10b10,  sd
WriteBack: 10b10 addi
-------------------------- CPU STATE -------------------------
PC: 0x10b24
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c78 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00478793 at address 0x10b24
Decoded 0x10b1c instruction 0x01213023 as sd s2,0(sp)
Execute: 10b18,  lui
Memory Access: 10b14,  lui
WriteBack: 10b14 sd
-------------------------- CPU STATE -------------------------
PC: 0x10b28
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13c78 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00440713 at address 0x10b28
Decoded 0x10b20 instruction 0x00478793 as addi a5,a5,4
Execute: 10b1c,  sd
Memory Access: 10b18,  lui
WriteBack: 10b18 lui
  Forward Data a5 to Decode op1
-------------------------- CPU STATE -------------------------
PC: 0x10b2c
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00113c23 at address 0x10b2c
Decoded 0x10b24 instruction 0x00440713 as addi a4,s0,4
Execute: 10b20,  addi
Memory Access: 10b1c,  sd
WriteBack: 10b1c lui
  Forward Data s0 to Decode op1
-------------------------- CPU STATE -------------------------
PC: 0x10b30
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00913423 at address 0x10b30
Decoded 0x10b28 instruction 0x00113c23 as sd ra,24(sp)
Execute: 10b24,  addi
Memory Access: 10b20,  addi
WriteBack: 10b20 sd
-------------------------- CPU STATE -------------------------
PC: 0x10b34
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x40e78933 at address 0x10b34
Decoded 0x10b2c instruction 0x00913423 as sd s1,8(sp)
Execute: 10b28,  sd
Memory Access: 10b24,  addi
WriteBack: 10b24 addi
-------------------------- CPU STATE -------------------------
PC: 0x10b38
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:         1 	
a5:     13004 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x02e78263 at address 0x10b38
Decoded 0x10b30 instruction 0x40e78933 as sub s2,a5,a4
Execute: 10b2c,  sd
Memory Access: 10b28,  sd
WriteBack: 10b28 addi
  Forward Data a4 to Decode op2
-------------------------- CPU STATE -------------------------
PC: 0x10b3c
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13004 	
a5:     13004 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x40395913 at address 0x10b3c
rs1 = 13004
rs2 = 13004
Decoded 0x10b34 instruction 0x02e78263 as beq a5,a4,36
Execute: 10b30,  sub
Memory Access: 10b2c,  sd
WriteBack: 10b2c sd
-------------------------- CPU STATE -------------------------
PC: 0x10b40
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13004 	
a5:     13004 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00440413 at address 0x10b40
Decoded 0x10b38 instruction 0x40395913 as srai s2,s2,3
Execute: 10b34,  beq
BEQMemory Access: 10b30,  sub
  Forward Data s2 to Decode op1
WriteBack: 10b30 sd
-------------------------- CPU STATE -------------------------
PC: 0x10b5c
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13004 	
a5:     13004 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00013437 at address 0x10b5c
Decode: Bubble
Execute: 10b3c Bubble
Memory Access: 10b34,  beq
WriteBack: 10b34 sub
-------------------------- CPU STATE -------------------------
PC: 0x10b60
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13004 	
a5:     13004 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x000137b7 at address 0x10b60
Decoded 0x0 instruction 0x00013437 as lui s0,19
Execute: 0 Bubble
Memory Access: 10b5c,  Bubble
WriteBack: 10b5c beq
-------------------------- CPU STATE -------------------------
PC: 0x10b64
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13004 	
a5:     13004 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01878793 at address 0x10b64
Decoded 0x10b5c instruction 0x000137b7 as lui a5,19
Execute: 0,  lui
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b68
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13004 	
a5:     13004 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00840713 at address 0x10b68
Decoded 0x10b60 instruction 0x01878793 as addi a5,a5,24
Execute: 10b5c,  lui
  Forward Data a5 to Decode op1
Memory Access: 0,  lui
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b6c
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13004 	
a5:     13004 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x40e78933 at address 0x10b6c
Decoded 0x10b64 instruction 0x00840713 as addi a4,s0,8
Execute: 10b60,  addi
Memory Access: 10b5c,  lui
WriteBack: 10b5c lui
  Forward Data s0 to Decode op1
-------------------------- CPU STATE -------------------------
PC: 0x10b70
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13004 	
a5:     13004 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x40395913 at address 0x10b70
Decoded 0x10b68 instruction 0x40e78933 as sub s2,a5,a4
Execute: 10b64,  addi
  Forward Data a4 to Decode op2
Memory Access: 10b60,  addi
  Forward Data a5 to Decode op1
WriteBack: 10b60 lui
-------------------------- CPU STATE -------------------------
PC: 0x10b74
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13004 	
a5:     13000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x02e78063 at address 0x10b74
Decoded 0x10b6c instruction 0x40395913 as srai s2,s2,3
Execute: 10b68,  sub
  Forward Data s2 to Decode op1
Memory Access: 10b64,  addi
WriteBack: 10b64 addi
-------------------------- CPU STATE -------------------------
PC: 0x10b78
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13004 	
a5:     13018 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00840413 at address 0x10b78
rs1 = 13018
rs2 = 13004
Decoded 0x10b70 instruction 0x02e78063 as beq a5,a4,32
Execute: 10b6c,  srai
Memory Access: 10b68,  sub
WriteBack: 10b68 addi
  Forward Data a4 to Decode op2
-------------------------- CPU STATE -------------------------
PC: 0x10b7c
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     13018 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000493 at address 0x10b7c
Decoded 0x10b74 instruction 0x00840413 as addi s0,s0,8
Execute: 10b70,  beq
Memory Access: 10b6c,  srai
WriteBack: 10b6c sub
-------------------------- CPU STATE -------------------------
PC: 0x10b80
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     13018 	a6:        1f 	a7:         0 	s2:        10 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00043783 at address 0x10b80
Decoded 0x10b78 instruction 0x00000493 as addi s1,00,0
Execute: 10b74,  addi
Memory Access: 10b70,  beq
WriteBack: 10b70 srai
-------------------------- CPU STATE -------------------------
PC: 0x10b84
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     13018 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00148493 at address 0x10b84
Decoded 0x10b7c instruction 0x00043783 as ld a5,0(s0)
Execute: 10b78,  addi
Memory Access: 10b74,  addi
  Forward Data s0 to Decode op1
WriteBack: 10b74 beq
-------------------------- CPU STATE -------------------------
PC: 0x10b88
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13000 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     13018 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00840413 at address 0x10b88
Decoded 0x10b80 instruction 0x00148493 as addi s1,s1,1
Execute: 10b7c,  ld
Memory Access: 10b78,  addi
  Forward Data s1 to Decode op1
WriteBack: 10b78 addi
-------------------------- CPU STATE -------------------------
PC: 0x10b8c
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13008 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     13018 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x000780e7 at address 0x10b8c
Decoded 0x10b84 instruction 0x00840413 as addi s0,s0,8
Execute: 10b80,  addi
Memory Access: 10b7c,  ld
WriteBack: 10b7c addi
-------------------------- CPU STATE -------------------------
PC: 0x10b90
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13008 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     13018 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xff24e8e3 at address 0x10b90
Decoded 0x10b88 instruction 0x000780e7 as jalr ra,a5,0
Execute: 10b84,  addi
Memory Access: 10b80,  addi
WriteBack: 10b80 ld
  Forward Data a5 to Decode op1
-------------------------- CPU STATE -------------------------
PC: 0x10b94
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13008 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     10114 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01813083 at address 0x10b94
rs1 = 0
rs2 = 2
Decoded 0x10b8c instruction 0xff24e8e3 as bltu s1,s2,-16
Execute: 10b88,  jalr
Memory Access: 10b84,  addi
WriteBack: 10b84 addi
  Forward Data s1 to Decode op1
-------------------------- CPU STATE -------------------------
PC: 0x10114
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13008 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     10114 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000793 at address 0x10114
Decode: Bubble
Execute: 10b90 Bubble
Memory Access: 10b88,  jalr
WriteBack: 10b88 addi
-------------------------- CPU STATE -------------------------
PC: 0x10118
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     10114 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00078863 at address 0x10118
Decoded 0x0 instruction 0x00000793 as addi a5,00,0
Execute: 0 Bubble
Memory Access: 10114,  Bubble
WriteBack: 10114 jalr
-------------------------- CPU STATE -------------------------
PC: 0x1011c
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     10114 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00012537 at address 0x1011c
rs1 = 10114
rs2 = 0
Decoded 0x10114 instruction 0x00078863 as beq a5,00,16
Execute: 0,  addi
  Forward Data a5 to Decode op1
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10120
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     10114 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xeec50513 at address 0x10120
Decoded 0x10118 instruction 0x00012537 as lui a0,18
Execute: 10114,  beq
BEQMemory Access: 0,  addi
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10128
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     10114 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00008067 at address 0x10128
Decode: Bubble
Execute: 1011c Bubble
Memory Access: 10114,  beq
WriteBack: 10114 addi
-------------------------- CPU STATE -------------------------
PC: 0x1012c
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00003197 at address 0x1012c
Decoded 0x0 instruction 0x00008067 as jalr 00,ra,0
Execute: 0 Bubble
Memory Access: 10128,  Bubble
WriteBack: 10128 beq
-------------------------- CPU STATE -------------------------
PC: 0x10130
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x6f418193 at address 0x10130
Decoded 0x10128 instruction 0x00003197 as auipc gp,3
Execute: 0,  jalr
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b90
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xff24e8e3 at address 0x10b90
Decode: Bubble
Execute: 1012c Bubble
Memory Access: 0,  jalr
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b94
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01813083 at address 0x10b94
rs1 = 1
rs2 = 2
Decoded 0x0 instruction 0xff24e8e3 as bltu s1,s2,-16
Execute: 0 Bubble
Memory Access: 10b90,  Bubble
WriteBack: 10b90 jalr
-------------------------- CPU STATE -------------------------
PC: 0x10b98
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01013403 at address 0x10b98
Decoded 0x10b90 instruction 0x01813083 as ld ra,24(sp)
Execute: 0,  bltu
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b80
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00043783 at address 0x10b80
Decode: Bubble
Execute: 10b94 Bubble
Memory Access: 0,  bltu
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b84
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00148493 at address 0x10b84
Decoded 0x0 instruction 0x00043783 as ld a5,0(s0)
Execute: 0 Bubble
Memory Access: 10b80,  Bubble
WriteBack: 10b80 bltu
-------------------------- CPU STATE -------------------------
PC: 0x10b88
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00840413 at address 0x10b88
Decoded 0x10b80 instruction 0x00148493 as addi s1,s1,1
Execute: 0,  ld
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b8c
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x000780e7 at address 0x10b8c
Decoded 0x10b84 instruction 0x00840413 as addi s0,s0,8
Execute: 10b80,  addi
Memory Access: 0,  ld
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b90
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xff24e8e3 at address 0x10b90
Decoded 0x10b88 instruction 0x000780e7 as jalr ra,a5,0
Execute: 10b84,  addi
Memory Access: 10b80,  addi
WriteBack: 10b80 ld
  Forward Data a5 to Decode op1
-------------------------- CPU STATE -------------------------
PC: 0x10b94
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         1 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     101bc 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01813083 at address 0x10b94
rs1 = 1
rs2 = 2
Decoded 0x10b8c instruction 0xff24e8e3 as bltu s1,s2,-16
Execute: 10b88,  jalr
Memory Access: 10b84,  addi
WriteBack: 10b84 addi
  Forward Data s1 to Decode op1
-------------------------- CPU STATE -------------------------
PC: 0x101bc
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13010 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     101bc 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000793 at address 0x101bc
Decode: Bubble
Execute: 10b90 Bubble
Memory Access: 10b88,  jalr
WriteBack: 10b88 addi
-------------------------- CPU STATE -------------------------
PC: 0x101c0
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     101bc 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00078c63 at address 0x101c0
Decoded 0x0 instruction 0x00000793 as addi a5,00,0
Execute: 0 Bubble
Memory Access: 101bc,  Bubble
WriteBack: 101bc jalr
-------------------------- CPU STATE -------------------------
PC: 0x101c4
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     101bc 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00013537 at address 0x101c4
rs1 = 101bc
rs2 = 0
Decoded 0x101bc instruction 0x00078c63 as beq a5,00,24
Execute: 0,  addi
  Forward Data a5 to Decode op1
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x101c8
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     101bc 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x1e018593 at address 0x101c8
Decoded 0x101c0 instruction 0x00013537 as lui a0,19
Execute: 101bc,  beq
BEQMemory Access: 0,  addi
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x101d8
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:     101bc 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00008067 at address 0x101d8
Decode: Bubble
Execute: 101c4 Bubble
Memory Access: 101bc,  beq
WriteBack: 101bc addi
-------------------------- CPU STATE -------------------------
PC: 0x101dc
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xff010113 at address 0x101dc
Decoded 0x0 instruction 0x00008067 as jalr 00,ra,0
Execute: 0 Bubble
Memory Access: 101d8,  Bubble
WriteBack: 101d8 beq
-------------------------- CPU STATE -------------------------
PC: 0x101e0
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00113423 at address 0x101e0
Decoded 0x101d8 instruction 0xff010113 as addi sp,sp,-16
Execute: 0,  jalr
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b90
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xff24e8e3 at address 0x10b90
Decode: Bubble
Execute: 101dc Bubble
Memory Access: 0,  jalr
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b94
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01813083 at address 0x10b94
rs1 = 2
rs2 = 2
Decoded 0x0 instruction 0xff24e8e3 as bltu s1,s2,-16
Execute: 0 Bubble
Memory Access: 10b90,  Bubble
WriteBack: 10b90 jalr
-------------------------- CPU STATE -------------------------
PC: 0x10b98
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01013403 at address 0x10b98
Decoded 0x10b90 instruction 0x01813083 as ld ra,24(sp)
Execute: 0,  bltu
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10b9c
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00813483 at address 0x10b9c
Decoded 0x10b94 instruction 0x01013403 as ld s0,16(sp)
Execute: 10b90,  ld
Memory Access: 0,  bltu
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10ba0
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00013903 at address 0x10ba0
Decoded 0x10b98 instruction 0x00813483 as ld s1,8(sp)
Execute: 10b94,  ld
Memory Access: 10b90,  ld
WriteBack: 10b90 bltu
-------------------------- CPU STATE -------------------------
PC: 0x10ba4
00:         0 	ra:     10b90 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x02010113 at address 0x10ba4
Decoded 0x10b9c instruction 0x00013903 as ld s2,0(sp)
Execute: 10b98,  ld
Memory Access: 10b94,  ld
WriteBack: 10b94 ld
-------------------------- CPU STATE -------------------------
PC: 0x10ba8
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:     13018 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00008067 at address 0x10ba8
Decoded 0x10ba0 instruction 0x02010113 as addi sp,sp,32
Execute: 10b9c,  ld
Memory Access: 10b98,  ld
WriteBack: 10b98 ld
-------------------------- CPU STATE -------------------------
PC: 0x10bac
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         2 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00f00313 at address 0x10bac
Decoded 0x10ba4 instruction 0x00008067 as jalr 00,ra,0
Execute: 10ba0,  addi
Memory Access: 10b9c,  ld
WriteBack: 10b9c ld
-------------------------- CPU STATE -------------------------
PC: 0x10bb0
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         2 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00050713 at address 0x10bb0
Decoded 0x10ba8 instruction 0x00f00313 as addi t1,00,15
Execute: 10ba4,  jalr
Memory Access: 10ba0,  addi
WriteBack: 10ba0 ld
-------------------------- CPU STATE -------------------------
PC: 0x10164
00:         0 	ra:     10164 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00012503 at address 0x10164
Decode: Bubble
Execute: 10bac Bubble
Memory Access: 10ba4,  jalr
WriteBack: 10ba4 addi
-------------------------- CPU STATE -------------------------
PC: 0x10168
00:         0 	ra:     10164 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00810593 at address 0x10168
Decoded 0x0 instruction 0x00012503 as lw a0,0(sp)
Execute: 0 Bubble
Memory Access: 10164,  Bubble
WriteBack: 10164 jalr
-------------------------- CPU STATE -------------------------
PC: 0x1016c
00:         0 	ra:     10164 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000613 at address 0x1016c
Decoded 0x10164 instruction 0x00810593 as addi a1,sp,8
Execute: 0,  lw
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10170
00:         0 	ra:     10164 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x06c000ef at address 0x10170
Decoded 0x10168 instruction 0x00000613 as addi a2,00,0
Execute: 10164,  addi
Memory Access: 0,  lw
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10174
00:         0 	ra:     10164 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xf75ff06f at address 0x10174
Decoded 0x1016c instruction 0x06c000ef as jal ra,108
Execute: 10168,  addi
Memory Access: 10164,  addi
WriteBack: 10164 lw
-------------------------- CPU STATE -------------------------
PC: 0x10178
00:         0 	ra:     10164 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:     11eec 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xff010113 at address 0x10178
Decoded 0x10170 instruction 0xf75ff06f as jal 00,-140
Execute: 1016c,  jal
Memory Access: 10168,  addi
WriteBack: 10168 addi
-------------------------- CPU STATE -------------------------
PC: 0x101dc
00:         0 	ra:     10164 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xff010113 at address 0x101dc
Decode: Bubble
Execute: 10174 Bubble
Memory Access: 1016c,  jal
WriteBack: 1016c addi
-------------------------- CPU STATE -------------------------
PC: 0x101e0
00:         0 	ra:     10164 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00113423 at address 0x101e0
Decoded 0x0 instruction 0xff010113 as addi sp,sp,-16
Execute: 0 Bubble
Memory Access: 101dc,  Bubble
WriteBack: 101dc jal
-------------------------- CPU STATE -------------------------
PC: 0x101e4
00:         0 	ra:     10174 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00813023 at address 0x101e4
Decoded 0x101dc instruction 0x00113423 as sd ra,8(sp)
Execute: 0,  addi
  Forward Data sp to Decode op1
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x101e8
00:         0 	ra:     10174 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01010413 at address 0x101e8
Decoded 0x101e0 instruction 0x00813023 as sd s0,0(sp)
Execute: 101dc,  sd
Memory Access: 0,  addi
  Forward Data sp to Decode op1
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x101ec
00:         0 	ra:     10174 	sp:  80000000 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x000127b7 at address 0x101ec
Decoded 0x101e4 instruction 0x01010413 as addi s0,sp,16
Execute: 101e0,  sd
Memory Access: 101dc,  sd
WriteBack: 101dc addi
  Forward Data sp to Decode op1
-------------------------- CPU STATE -------------------------
PC: 0x101f0
00:         0 	ra:     10174 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x1b078513 at address 0x101f0
Decoded 0x101e8 instruction 0x000127b7 as lui a5,18
Execute: 101e4,  addi
Memory Access: 101e0,  sd
WriteBack: 101e0 sd
-------------------------- CPU STATE -------------------------
PC: 0x101f4
00:         0 	ra:     10174 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x04c000ef at address 0x101f4
Decoded 0x101ec instruction 0x1b078513 as addi a0,a5,432
Execute: 101e8,  lui
  Forward Data a5 to Decode op1
Memory Access: 101e4,  addi
WriteBack: 101e4 sd
-------------------------- CPU STATE -------------------------
PC: 0x101f8
00:         0 	ra:     10174 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:         0 	s1:         0 	
a0:         0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x09c000ef at address 0x101f8
Decoded 0x101f0 instruction 0x04c000ef as jal ra,76
Execute: 101ec,  addi
Memory Access: 101e8,  lui
WriteBack: 101e8 addi
-------------------------- CPU STATE -------------------------
PC: 0x101fc
00:         0 	ra:     10174 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:         0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:         0 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000793 at address 0x101fc
Decoded 0x101f4 instruction 0x09c000ef as jal ra,156
Execute: 101f0,  jal
Memory Access: 101ec,  addi
WriteBack: 101ec lui
-------------------------- CPU STATE -------------------------
PC: 0x10240
00:         0 	ra:     10174 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:         0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xfe010113 at address 0x10240
Decode: Bubble
Execute: 101f8 Bubble
Memory Access: 101f0,  jal
WriteBack: 101f0 addi
-------------------------- CPU STATE -------------------------
PC: 0x10244
00:         0 	ra:     10174 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00813c23 at address 0x10244
Decoded 0x0 instruction 0xfe010113 as addi sp,sp,-32
Execute: 0 Bubble
Memory Access: 10240,  Bubble
WriteBack: 10240 jal
-------------------------- CPU STATE -------------------------
PC: 0x10248
00:         0 	ra:     101f8 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x02010413 at address 0x10248
Decoded 0x10240 instruction 0x00813c23 as sd s0,24(sp)
Execute: 0,  addi
  Forward Data sp to Decode op1
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x1024c
00:         0 	ra:     101f8 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xfea43423 at address 0x1024c
Decoded 0x10244 instruction 0x02010413 as addi s0,sp,32
Execute: 10240,  sd
Memory Access: 0,  addi
  Forward Data sp to Decode op1
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10250
00:         0 	ra:     101f8 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000893 at address 0x10250
Decoded 0x10248 instruction 0xfea43423 as sd a0,-24(s0)
Execute: 10244,  addi
  Forward Data s0 to Decode op1
Memory Access: 10240,  sd
WriteBack: 10240 addi
-------------------------- CPU STATE -------------------------
PC: 0x10254
00:         0 	ra:     101f8 	sp:  7fffffd0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000073 at address 0x10254
Decoded 0x1024c instruction 0x00000893 as addi a7,00,0
Execute: 10248,  sd
Memory Access: 10244,  addi
WriteBack: 10244 sd
-------------------------- CPU STATE -------------------------
PC: 0x10258
00:         0 	ra:     101f8 	sp:  7fffffd0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000013 at address 0x10258
Decoded 0x10250 instruction 0x00000073 as ecall
Execute: 1024c,  addi
  Forward Data a7 to Decode op2
Memory Access: 10248,  sd
WriteBack: 10248 addi
-------------------------- CPU STATE -------------------------
PC: 0x1025c
00:         0 	ra:     101f8 	sp:  7fffffd0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  7ffffff0 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01813403 at address 0x1025c
Decoded 0x10254 instruction 0x00000013 as addi 00,00,0
Execute: 10250,  ecall
Hello, World!
Memory Access: 1024c,  addi
WriteBack: 1024c sd
-------------------------- CPU STATE -------------------------
PC: 0x10260
00:         0 	ra:     101f8 	sp:  7fffffd0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  7ffffff0 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x02010113 at address 0x10260
Decoded 0x10258 instruction 0x01813403 as ld s0,24(sp)
Execute: 10254,  addi
Memory Access: 10250,  ecall
WriteBack: 10250 addi
-------------------------- CPU STATE -------------------------
PC: 0x10264
00:         0 	ra:     101f8 	sp:  7fffffd0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  7ffffff0 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00008067 at address 0x10264
Decoded 0x1025c instruction 0x02010113 as addi sp,sp,32
Execute: 10258,  ld
Memory Access: 10254,  addi
WriteBack: 10254 ecall
-------------------------- CPU STATE -------------------------
PC: 0x10268
00:         0 	ra:     101f8 	sp:  7fffffd0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  7ffffff0 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xfe010113 at address 0x10268
Decoded 0x10260 instruction 0x00008067 as jalr 00,ra,0
Execute: 1025c,  addi
Memory Access: 10258,  ld
WriteBack: 10258 addi
-------------------------- CPU STATE -------------------------
PC: 0x1026c
00:         0 	ra:     101f8 	sp:  7fffffd0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  7ffffff0 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00813c23 at address 0x1026c
Decoded 0x10264 instruction 0xfe010113 as addi sp,sp,-32
Execute: 10260,  jalr
Memory Access: 1025c,  addi
  Forward Data sp to Decode op1
WriteBack: 1025c ld
-------------------------- CPU STATE -------------------------
PC: 0x101f8
00:         0 	ra:     101f8 	sp:  7fffffd0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x09c000ef at address 0x101f8
Decode: Bubble
Execute: 10268 Bubble
Memory Access: 10260,  jalr
WriteBack: 10260 addi
-------------------------- CPU STATE -------------------------
PC: 0x101fc
00:         0 	ra:     101f8 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000793 at address 0x101fc
Decoded 0x0 instruction 0x09c000ef as jal ra,156
Execute: 0 Bubble
Memory Access: 101f8,  Bubble
WriteBack: 101f8 jalr
-------------------------- CPU STATE -------------------------
PC: 0x10200
00:         0 	ra:     101f8 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00078513 at address 0x10200
Decoded 0x101f8 instruction 0x00000793 as addi a5,00,0
Execute: 0,  jal
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10294
00:         0 	ra:     101f8 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0xff010113 at address 0x10294
Decode: Bubble
Execute: 101fc Bubble
Memory Access: 0,  jal
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x10298
00:         0 	ra:     101f8 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00813423 at address 0x10298
Decoded 0x0 instruction 0xff010113 as addi sp,sp,-16
Execute: 0 Bubble
Memory Access: 10294,  Bubble
WriteBack: 10294 jal
-------------------------- CPU STATE -------------------------
PC: 0x1029c
00:         0 	ra:     101fc 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x01010413 at address 0x1029c
Decoded 0x10294 instruction 0x00813423 as sd s0,8(sp)
Execute: 0,  addi
  Forward Data sp to Decode op1
Memory Access: 0,  Bubble
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x102a0
00:         0 	ra:     101fc 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00300893 at address 0x102a0
Decoded 0x10298 instruction 0x01010413 as addi s0,sp,16
Execute: 10294,  sd
Memory Access: 0,  addi
  Forward Data sp to Decode op1
WriteBack: 0 Bubble
-------------------------- CPU STATE -------------------------
PC: 0x102a4
00:         0 	ra:     101fc 	sp:  7ffffff0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000073 at address 0x102a4
Decoded 0x1029c instruction 0x00300893 as addi a7,00,3
Execute: 10298,  addi
Memory Access: 10294,  sd
WriteBack: 10294 addi
-------------------------- CPU STATE -------------------------
PC: 0x102a8
00:         0 	ra:     101fc 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00000013 at address 0x102a8
Decoded 0x102a0 instruction 0x00000073 as ecall
Execute: 1029c,  addi
  Forward Data a7 to Decode op2
Memory Access: 10298,  addi
WriteBack: 10298 sd
-------------------------- CPU STATE -------------------------
PC: 0x102ac
00:         0 	ra:     101fc 	sp:  7fffffe0 	gp:     13820 	tp:         0 	
t0:     10bf0 	t1:         f 	t2:         0 	s0:  80000000 	s1:         0 	
a0:     121b0 	a1:  80000008 	a2:         0 	a3:        10 	a4:     13008 	
a5:     12000 	a6:        1f 	a7:         0 	s2:         0 	s3:         0 	
s4:         0 	s5:         0 	s6:         0 	s7:         0 	s8:         0 	
s9:         0 	sa:         0 	sb:         0 	t3:         0 	t4:         0 	
t5:         0 	t6:         0 	
--------------------------------------------------------------

Fetched instruction 0x00813403 at address 0x102ac
Decoded 0x102a4 instruction 0x00000013 as addi 00,00,0
Execute: 102a0,  ecall
Program exit from an exit() system call
------------ STATISTICS -----------
Number of Instructions: 125
Number of Cycles: 215
Avg Cycles per Instrcution: 1.7200
Branch Perdiction Accuacy: 0.5000 (Strategy: Always Not Taken)
Number of Control Hazards: 24
Number of Data Hazards: 57
Number of Memory Hazards: 1
-----------------------------------
