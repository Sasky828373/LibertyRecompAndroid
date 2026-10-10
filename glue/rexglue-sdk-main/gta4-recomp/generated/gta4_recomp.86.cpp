#include "gta4_init.h"

DEFINE_REX_FUNC(sub_82A7B110) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c4
	ctx.lr = 0x82A7B118;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,8(r27)
	ctx.r11.u64 = REX_LOAD_U32(r27.u32 + 8);
	// lwz r8,4(r27)
	ctx.r8.u64 = REX_LOAD_U32(r27.u32 + 4);
	// lwz r9,0(r27)
	ctx.r9.u64 = REX_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(ctx.r11.u32, 4, xer);
	// bge cr6,0x82a7b15c
	if (!cr6.lt) goto loc_82A7B15C;
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subfic r6,r11,4
	xer.ca = ctx.r11.u32 <= 4;
	ctx.r6.u64 = static_cast<uint64_t>(4) - ctx.r11.u64;
	// addi r31,r11,28
	r31.s64 = ctx.r11.s64 + 28;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// slw r10,r7,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r11.u8 & 0x3F));
	// srw r30,r7,r6
	r30.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r6.u8 & 0x3F));
	// or r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 | ctx.r9.u64;
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// b 0x82a7b168
	goto loc_82A7B168;
loc_82A7B15C:
	// clrlwi r10,r9,28
	ctx.r10.u64 = ctx.r9.u32 & 0xF;
	// rlwinm r30,r9,28,4,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// addi r31,r11,-4
	r31.s64 = ctx.r11.s64 + -4;
loc_82A7B168:
	// lis r11,-31969
	ctx.r11.s64 = -2095120384;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-23744
	ctx.r11.s64 = ctx.r11.s64 + -23744;
	// lis r9,-32236
	ctx.r9.s64 = -2112618496;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r9,r9,-28208
	ctx.r9.s64 = ctx.r9.s64 + -28208;
	// lwzx r11,r7,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// lbzx r11,r10,r9
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// bne cr6,0x82a7b1bc
	if (!cr6.eq) goto loc_82A7B1BC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82A7B198:
	// stbx r11,r11,r28
	REX_STORE_U8(ctx.r11.u32 + r28.u32, ctx.r11.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(ctx.r11.u32, 16, xer);
	// blt cr6,0x82a7b198
	if (cr6.lt) goto loc_82A7B198;
	// stw r8,4(r27)
	REX_STORE_U32(r27.u32 + 4, ctx.r8.u32);
	// stw r30,0(r27)
	REX_STORE_U32(r27.u32 + 0, r30.u32);
	// stw r31,8(r27)
	REX_STORE_U32(r27.u32 + 8, r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff814
	return;
loc_82A7B1BC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82a7b1d8
	if (!cr6.eq) goto loc_82A7B1D8;
	// lwz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// rlwinm r10,r9,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7b1e4
	goto loc_82A7B1E4;
loc_82A7B1D8:
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// rlwinm r10,r30,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r31,-1
	ctx.r11.s64 = r31.s64 + -1;
loc_82A7B1E4:
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82a7b834
	if (!cr6.eq) goto loc_82A7B834;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(ctx.r11.u32, 2, xer);
	// bge cr6,0x82a7b21c
	if (!cr6.lt) goto loc_82A7B21C;
	// lwz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subfic r7,r11,2
	xer.ca = ctx.r11.u32 <= 2;
	ctx.r7.u64 = static_cast<uint64_t>(2) - ctx.r11.u64;
	// addi r31,r11,30
	r31.s64 = ctx.r11.s64 + 30;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// slw r6,r9,r11
	ctx.r6.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r11.u8 & 0x3F));
	// srw r30,r9,r7
	r30.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r7.u8 & 0x3F));
	// or r11,r6,r10
	ctx.r11.u64 = ctx.r6.u64 | ctx.r10.u64;
	// clrlwi r29,r11,30
	r29.u64 = ctx.r11.u32 & 0x3;
	// b 0x82a7b228
	goto loc_82A7B228;
loc_82A7B21C:
	// clrlwi r29,r10,30
	r29.u64 = ctx.r10.u32 & 0x3;
	// rlwinm r30,r10,30,2,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r31,r11,-2
	r31.s64 = ctx.r11.s64 + -2;
loc_82A7B228:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x82a7b2a8
	if (!cr6.eq) goto loc_82A7B2A8;
	// addi r9,r28,-1
	ctx.r9.s64 = r28.s64 + -1;
loc_82A7B238:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82a7b254
	if (!cr6.eq) goto loc_82A7B254;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// li r31,31
	r31.s64 = 31;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// rlwinm r30,r10,31,1,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7b260
	goto loc_82A7B260;
loc_82A7B254:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82A7B260:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r11,255
	ctx.r10.s64 = ctx.r11.s64 + 255;
	// beq cr6,0x82a7b27c
	if (cr6.eq) goto loc_82A7B27C;
	// stbx r11,r9,r11
	REX_STORE_U8(ctx.r9.u32 + ctx.r11.u32, ctx.r11.u8);
	// stbx r10,r11,r28
	REX_STORE_U8(ctx.r11.u32 + r28.u32, ctx.r10.u8);
	// b 0x82a7b284
	goto loc_82A7B284;
loc_82A7B27C:
	// stbx r11,r11,r28
	REX_STORE_U8(ctx.r11.u32 + r28.u32, ctx.r11.u8);
	// stbx r10,r9,r11
	REX_STORE_U8(ctx.r9.u32 + ctx.r11.u32, ctx.r10.u8);
loc_82A7B284:
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// blt cr6,0x82a7b238
	if (cr6.lt) goto loc_82A7B238;
	// stw r8,4(r27)
	REX_STORE_U32(r27.u32 + 4, ctx.r8.u32);
	// stw r30,0(r27)
	REX_STORE_U32(r27.u32 + 0, r30.u32);
	// stw r31,8(r27)
	REX_STORE_U32(r27.u32 + 8, r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff814
	return;
loc_82A7B2A8:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
loc_82A7B2B4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82a7b2d0
	if (!cr6.eq) goto loc_82A7B2D0;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// li r31,31
	r31.s64 = 31;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// rlwinm r30,r10,31,1,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7b2dc
	goto loc_82A7B2DC;
loc_82A7B2D0:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82A7B2DC:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a7b2f8
	if (cr6.eq) goto loc_82A7B2F8;
	// stbx r11,r7,r11
	REX_STORE_U8(ctx.r7.u32 + ctx.r11.u32, ctx.r11.u8);
	// stbx r9,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u8);
	// b 0x82a7b300
	goto loc_82A7B300;
loc_82A7B2F8:
	// stbx r9,r7,r11
	REX_STORE_U8(ctx.r7.u32 + ctx.r11.u32, ctx.r9.u8);
	// stbx r11,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r11.u8);
loc_82A7B300:
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// cmplwi cr6,r11,17
	cr6.compare<uint32_t>(ctx.r11.u32, 17, xer);
	// blt cr6,0x82a7b2b4
	if (cr6.lt) goto loc_82A7B2B4;
	// cmplwi cr6,r29,1
	cr6.compare<uint32_t>(r29.u32, 1, xer);
	// bne cr6,0x82a7b4bc
	if (!cr6.eq) goto loc_82A7B4BC;
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// bge cr6,0x82a7b334
	if (!cr6.lt) goto loc_82A7B334;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// b 0x82a7b338
	goto loc_82A7B338;
loc_82A7B334:
	// clrlwi r3,r30,29
	ctx.r3.u64 = r30.u32 & 0x7;
loc_82A7B338:
	// li r7,2
	ctx.r7.s64 = 2;
	// addi r6,r1,82
	ctx.r6.s64 = ctx.r1.s64 + 82;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B34C;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b370
	if (!cr6.lt) goto loc_82A7B370;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7b378
	goto loc_82A7B378;
loc_82A7B370:
	// subf r31,r3,r31
	r31.u64 = r31.u64 - ctx.r3.u64;
	// srw r30,r30,r3
	r30.u64 = ctx.r3.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r3.u8 & 0x3F));
loc_82A7B378:
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// bge cr6,0x82a7b394
	if (!cr6.lt) goto loc_82A7B394;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// b 0x82a7b398
	goto loc_82A7B398;
loc_82A7B394:
	// clrlwi r3,r30,29
	ctx.r3.u64 = r30.u32 & 0x7;
loc_82A7B398:
	// li r7,2
	ctx.r7.s64 = 2;
	// addi r6,r1,86
	ctx.r6.s64 = ctx.r1.s64 + 86;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r28,4
	ctx.r4.s64 = r28.s64 + 4;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B3AC;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b3d0
	if (!cr6.lt) goto loc_82A7B3D0;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7b3d8
	goto loc_82A7B3D8;
loc_82A7B3D0:
	// subf r31,r3,r31
	r31.u64 = r31.u64 - ctx.r3.u64;
	// srw r30,r30,r3
	r30.u64 = ctx.r3.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r3.u8 & 0x3F));
loc_82A7B3D8:
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// bge cr6,0x82a7b3f4
	if (!cr6.lt) goto loc_82A7B3F4;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// b 0x82a7b3f8
	goto loc_82A7B3F8;
loc_82A7B3F4:
	// clrlwi r3,r30,29
	ctx.r3.u64 = r30.u32 & 0x7;
loc_82A7B3F8:
	// li r7,2
	ctx.r7.s64 = 2;
	// addi r6,r1,90
	ctx.r6.s64 = ctx.r1.s64 + 90;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r28,8
	ctx.r4.s64 = r28.s64 + 8;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B40C;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b430
	if (!cr6.lt) goto loc_82A7B430;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7b438
	goto loc_82A7B438;
loc_82A7B430:
	// subf r31,r3,r31
	r31.u64 = r31.u64 - ctx.r3.u64;
	// srw r30,r30,r3
	r30.u64 = ctx.r3.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r3.u8 & 0x3F));
loc_82A7B438:
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// bge cr6,0x82a7b454
	if (!cr6.lt) goto loc_82A7B454;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// b 0x82a7b458
	goto loc_82A7B458;
loc_82A7B454:
	// clrlwi r3,r30,29
	ctx.r3.u64 = r30.u32 & 0x7;
loc_82A7B458:
	// li r7,2
	ctx.r7.s64 = 2;
	// addi r6,r1,94
	ctx.r6.s64 = ctx.r1.s64 + 94;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r28,12
	ctx.r4.s64 = r28.s64 + 12;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B46C;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b4a0
	if (!cr6.lt) goto loc_82A7B4A0;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// stw r8,4(r27)
	REX_STORE_U32(r27.u32 + 4, ctx.r8.u32);
	// stw r31,8(r27)
	REX_STORE_U32(r27.u32 + 8, r31.u32);
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// stw r30,0(r27)
	REX_STORE_U32(r27.u32 + 0, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff814
	return;
loc_82A7B4A0:
	// subf r31,r3,r31
	r31.u64 = r31.u64 - ctx.r3.u64;
	// stw r8,4(r27)
	REX_STORE_U32(r27.u32 + 4, ctx.r8.u32);
	// srw r30,r30,r3
	r30.u64 = ctx.r3.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r3.u8 & 0x3F));
	// stw r31,8(r27)
	REX_STORE_U32(r27.u32 + 8, r31.u32);
	// stw r30,0(r27)
	REX_STORE_U32(r27.u32 + 0, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff814
	return;
loc_82A7B4BC:
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// bge cr6,0x82a7b4d8
	if (!cr6.lt) goto loc_82A7B4D8;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// b 0x82a7b4dc
	goto loc_82A7B4DC;
loc_82A7B4D8:
	// clrlwi r3,r30,29
	ctx.r3.u64 = r30.u32 & 0x7;
loc_82A7B4DC:
	// li r7,2
	ctx.r7.s64 = 2;
	// addi r6,r1,82
	ctx.r6.s64 = ctx.r1.s64 + 82;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B4F0;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b514
	if (!cr6.lt) goto loc_82A7B514;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7b51c
	goto loc_82A7B51C;
loc_82A7B514:
	// subf r31,r3,r31
	r31.u64 = r31.u64 - ctx.r3.u64;
	// srw r30,r30,r3
	r30.u64 = ctx.r3.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r3.u8 & 0x3F));
loc_82A7B51C:
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// bge cr6,0x82a7b538
	if (!cr6.lt) goto loc_82A7B538;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// b 0x82a7b53c
	goto loc_82A7B53C;
loc_82A7B538:
	// clrlwi r3,r30,29
	ctx.r3.u64 = r30.u32 & 0x7;
loc_82A7B53C:
	// li r7,2
	ctx.r7.s64 = 2;
	// addi r6,r1,86
	ctx.r6.s64 = ctx.r1.s64 + 86;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B550;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b574
	if (!cr6.lt) goto loc_82A7B574;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7b57c
	goto loc_82A7B57C;
loc_82A7B574:
	// subf r31,r3,r31
	r31.u64 = r31.u64 - ctx.r3.u64;
	// srw r30,r30,r3
	r30.u64 = ctx.r3.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r3.u8 & 0x3F));
loc_82A7B57C:
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// bge cr6,0x82a7b598
	if (!cr6.lt) goto loc_82A7B598;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// b 0x82a7b59c
	goto loc_82A7B59C;
loc_82A7B598:
	// clrlwi r3,r30,29
	ctx.r3.u64 = r30.u32 & 0x7;
loc_82A7B59C:
	// li r7,2
	ctx.r7.s64 = 2;
	// addi r6,r1,90
	ctx.r6.s64 = ctx.r1.s64 + 90;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B5B0;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b5d4
	if (!cr6.lt) goto loc_82A7B5D4;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7b5dc
	goto loc_82A7B5DC;
loc_82A7B5D4:
	// subf r31,r3,r31
	r31.u64 = r31.u64 - ctx.r3.u64;
	// srw r30,r30,r3
	r30.u64 = ctx.r3.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r3.u8 & 0x3F));
loc_82A7B5DC:
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// bge cr6,0x82a7b5f8
	if (!cr6.lt) goto loc_82A7B5F8;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// b 0x82a7b5fc
	goto loc_82A7B5FC;
loc_82A7B5F8:
	// clrlwi r3,r30,29
	ctx.r3.u64 = r30.u32 & 0x7;
loc_82A7B5FC:
	// li r7,2
	ctx.r7.s64 = 2;
	// addi r6,r1,94
	ctx.r6.s64 = ctx.r1.s64 + 94;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,108
	ctx.r4.s64 = ctx.r1.s64 + 108;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B610;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b634
	if (!cr6.lt) goto loc_82A7B634;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7b63c
	goto loc_82A7B63C;
loc_82A7B634:
	// subf r31,r3,r31
	r31.u64 = r31.u64 - ctx.r3.u64;
	// srw r30,r30,r3
	r30.u64 = ctx.r3.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r3.u8 & 0x3F));
loc_82A7B63C:
	// cmplwi cr6,r29,2
	cr6.compare<uint32_t>(r29.u32, 2, xer);
	// bne cr6,0x82a7b70c
	if (!cr6.eq) goto loc_82A7B70C;
	// cmplwi cr6,r31,7
	cr6.compare<uint32_t>(r31.u32, 7, xer);
	// bge cr6,0x82a7b660
	if (!cr6.lt) goto loc_82A7B660;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,25
	ctx.r3.u64 = ctx.r11.u32 & 0x7F;
	// b 0x82a7b664
	goto loc_82A7B664;
loc_82A7B660:
	// clrlwi r3,r30,25
	ctx.r3.u64 = r30.u32 & 0x7F;
loc_82A7B664:
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B678;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b69c
	if (!cr6.lt) goto loc_82A7B69C;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7b6a4
	goto loc_82A7B6A4;
loc_82A7B69C:
	// subf r31,r3,r31
	r31.u64 = r31.u64 - ctx.r3.u64;
	// srw r30,r30,r3
	r30.u64 = ctx.r3.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r3.u8 & 0x3F));
loc_82A7B6A4:
	// cmplwi cr6,r31,7
	cr6.compare<uint32_t>(r31.u32, 7, xer);
	// bge cr6,0x82a7b6c0
	if (!cr6.lt) goto loc_82A7B6C0;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,25
	ctx.r3.u64 = ctx.r11.u32 & 0x7F;
	// b 0x82a7b6c4
	goto loc_82A7B6C4;
loc_82A7B6C0:
	// clrlwi r3,r30,25
	ctx.r3.u64 = r30.u32 & 0x7F;
loc_82A7B6C4:
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,108
	ctx.r6.s64 = ctx.r1.s64 + 108;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r28,8
	ctx.r4.s64 = r28.s64 + 8;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B6D8;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b4a0
	if (!cr6.lt) goto loc_82A7B4A0;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// stw r8,4(r27)
	REX_STORE_U32(r27.u32 + 4, ctx.r8.u32);
	// stw r31,8(r27)
	REX_STORE_U32(r27.u32 + 8, r31.u32);
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// stw r30,0(r27)
	REX_STORE_U32(r27.u32 + 0, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff814
	return;
loc_82A7B70C:
	// cmplwi cr6,r31,7
	cr6.compare<uint32_t>(r31.u32, 7, xer);
	// bge cr6,0x82a7b728
	if (!cr6.lt) goto loc_82A7B728;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,25
	ctx.r3.u64 = ctx.r11.u32 & 0x7F;
	// b 0x82a7b72c
	goto loc_82A7B72C;
loc_82A7B728:
	// clrlwi r3,r30,25
	ctx.r3.u64 = r30.u32 & 0x7F;
loc_82A7B72C:
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B740;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b764
	if (!cr6.lt) goto loc_82A7B764;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7b76c
	goto loc_82A7B76C;
loc_82A7B764:
	// subf r31,r3,r31
	r31.u64 = r31.u64 - ctx.r3.u64;
	// srw r30,r30,r3
	r30.u64 = ctx.r3.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r3.u8 & 0x3F));
loc_82A7B76C:
	// cmplwi cr6,r31,7
	cr6.compare<uint32_t>(r31.u32, 7, xer);
	// bge cr6,0x82a7b788
	if (!cr6.lt) goto loc_82A7B788;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,25
	ctx.r3.u64 = ctx.r11.u32 & 0x7F;
	// b 0x82a7b78c
	goto loc_82A7B78C;
loc_82A7B788:
	// clrlwi r3,r30,25
	ctx.r3.u64 = r30.u32 & 0x7F;
loc_82A7B78C:
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,108
	ctx.r6.s64 = ctx.r1.s64 + 108;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B7A0;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b7c4
	if (!cr6.lt) goto loc_82A7B7C4;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7b7cc
	goto loc_82A7B7CC;
loc_82A7B7C4:
	// subf r31,r3,r31
	r31.u64 = r31.u64 - ctx.r3.u64;
	// srw r30,r30,r3
	r30.u64 = ctx.r3.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r3.u8 & 0x3F));
loc_82A7B7CC:
	// cmplwi cr6,r31,15
	cr6.compare<uint32_t>(r31.u32, 15, xer);
	// bge cr6,0x82a7b7e8
	if (!cr6.lt) goto loc_82A7B7E8;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// slw r11,r11,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// clrlwi r3,r11,17
	ctx.r3.u64 = ctx.r11.u32 & 0x7FFF;
	// b 0x82a7b7ec
	goto loc_82A7B7EC;
loc_82A7B7E8:
	// clrlwi r3,r30,17
	ctx.r3.u64 = r30.u32 & 0x7FFF;
loc_82A7B7EC:
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82a7b070
	ctx.lr = 0x82A7B800;
	sub_82A7B070(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bge cr6,0x82a7b4a0
	if (!cr6.lt) goto loc_82A7B4A0;
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subf r9,r31,r3
	ctx.r9.u64 = ctx.r3.u64 - r31.u64;
	// subf r11,r3,r31
	ctx.r11.u64 = r31.u64 - ctx.r3.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// stw r8,4(r27)
	REX_STORE_U32(r27.u32 + 4, ctx.r8.u32);
	// stw r31,8(r27)
	REX_STORE_U32(r27.u32 + 8, r31.u32);
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// stw r30,0(r27)
	REX_STORE_U32(r27.u32 + 0, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff814
	return;
loc_82A7B834:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(ctx.r11.u32, 3, xer);
	// bge cr6,0x82a7b860
	if (!cr6.lt) goto loc_82A7B860;
	// lwz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subfic r6,r11,3
	xer.ca = ctx.r11.u32 <= 3;
	ctx.r6.u64 = static_cast<uint64_t>(3) - ctx.r11.u64;
	// addi r31,r11,29
	r31.s64 = ctx.r11.s64 + 29;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// slw r7,r9,r11
	ctx.r7.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r11.u8 & 0x3F));
	// srw r30,r9,r6
	r30.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r6.u8 & 0x3F));
	// or r11,r7,r10
	ctx.r11.u64 = ctx.r7.u64 | ctx.r10.u64;
	// clrlwi r7,r11,29
	ctx.r7.u64 = ctx.r11.u32 & 0x7;
	// b 0x82a7b86c
	goto loc_82A7B86C;
loc_82A7B860:
	// clrlwi r7,r10,29
	ctx.r7.u64 = ctx.r10.u32 & 0x7;
	// rlwinm r30,r10,29,3,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r31,r11,-3
	r31.s64 = ctx.r11.s64 + -3;
loc_82A7B86C:
	// lis r6,0
	ctx.r6.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r6,r6,65535
	ctx.r6.u64 = ctx.r6.u64 | 65535;
	// li r5,1
	ctx.r5.s64 = 1;
loc_82A7B87C:
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
	// bge cr6,0x82a7b8a8
	if (!cr6.lt) goto loc_82A7B8A8;
	// lwz r9,0(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// subfic r4,r31,4
	xer.ca = r31.u32 <= 4;
	ctx.r4.u64 = static_cast<uint64_t>(4) - r31.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// slw r11,r9,r31
	ctx.r11.u64 = r31.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// or r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 | r30.u64;
	// srw r30,r9,r4
	r30.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r4.u8 & 0x3F));
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// b 0x82a7b8b4
	goto loc_82A7B8B4;
loc_82A7B8A8:
	// clrlwi r11,r30,28
	ctx.r11.u64 = r30.u32 & 0xF;
	// rlwinm r30,r30,28,4,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 28) & 0xFFFFFFF;
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
loc_82A7B8B4:
	// stbx r11,r10,r28
	REX_STORE_U8(ctx.r10.u32 + r28.u32, ctx.r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// slw r11,r5,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r11.u8 & 0x3F));
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// andc r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 & ~ctx.r11.u64;
	// ble cr6,0x82a7b87c
	if (!cr6.gt) goto loc_82A7B87C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82A7B8D0:
	// clrlwi r10,r6,31
	ctx.r10.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a7b8ec
	if (cr6.eq) goto loc_82A7B8EC;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplwi cr6,r7,15
	cr6.compare<uint32_t>(ctx.r7.u32, 15, xer);
	// stbx r11,r7,r28
	REX_STORE_U8(ctx.r7.u32 + r28.u32, ctx.r11.u8);
	// beq cr6,0x82a7b8fc
	if (cr6.eq) goto loc_82A7B8FC;
loc_82A7B8EC:
	// rlwinm r6,r6,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82a7b8d0
	if (!cr6.eq) goto loc_82A7B8D0;
loc_82A7B8FC:
	// stw r8,4(r27)
	REX_STORE_U32(r27.u32 + 4, ctx.r8.u32);
	// stw r30,0(r27)
	REX_STORE_U32(r27.u32 + 0, r30.u32);
	// stw r31,8(r27)
	REX_STORE_U32(r27.u32 + 8, r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff814
	return;
}

DEFINE_REX_FUNC(sub_82A7B910) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7b4
	ctx.lr = 0x82A7B918;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82a7bc0c
	if (!cr6.eq) goto loc_82A7BC0C;
	// lwz r10,8(r24)
	ctx.r10.u64 = REX_LOAD_U32(r24.u32 + 8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r29,4(r24)
	r29.u64 = REX_LOAD_U32(r24.u32 + 4);
	// lwz r8,0(r24)
	ctx.r8.u64 = REX_LOAD_U32(r24.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, xer);
	// bge cr6,0x82a7b980
	if (!cr6.lt) goto loc_82A7B980;
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r7,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r7.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r4,r10,r11
	ctx.r4.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// slw r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// srw r7,r6,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r7.u8 & 0x3F));
	// or r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// srw r30,r9,r4
	r30.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r4.u8 & 0x3F));
	// and r5,r7,r11
	ctx.r5.u64 = ctx.r7.u64 & ctx.r11.u64;
	// b 0x82a7b994
	goto loc_82A7B994;
loc_82A7B980:
	// subfic r9,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r9.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r31,r11,r10
	r31.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srw r30,r8,r11
	r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r11.u8 & 0x3F));
	// srw r10,r6,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r9.u8 & 0x3F));
	// and r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 & ctx.r8.u64;
loc_82A7B994:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82a7bbf0
	if (cr6.eq) goto loc_82A7BBF0;
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, xer);
	// bgt cr6,0x82a7bbf0
	if (cr6.gt) goto loc_82A7BBF0;
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// add r10,r11,r5
	ctx.r10.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// bne cr6,0x82a7b9d4
	if (!cr6.eq) goto loc_82A7B9D4;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(r29.u32 + 0);
	// li r31,31
	r31.s64 = 31;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// rlwinm r30,r10,31,1,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7b9e0
	goto loc_82A7B9E0;
loc_82A7B9D4:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82A7B9E0:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82a7bb84
	if (!cr6.eq) goto loc_82A7BB84;
	// lis r10,-32236
	ctx.r10.s64 = -2112618496;
	// lwz r4,32(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r28,36(r3)
	r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// addi r27,r3,16
	r27.s64 = ctx.r3.s64 + 16;
	// li r26,0
	r26.s64 = 0;
	// addi r25,r10,-28192
	r25.s64 = ctx.r10.s64 + -28192;
loc_82A7BA04:
	// cmplw cr6,r31,r4
	cr6.compare<uint32_t>(r31.u32, ctx.r4.u32, xer);
	// blt cr6,0x82a7ba34
	if (cr6.lt) goto loc_82A7BA34;
	// subfic r10,r4,32
	xer.ca = ctx.r4.u32 <= 32;
	ctx.r10.u64 = static_cast<uint64_t>(32) - ctx.r4.u64;
	// srw r10,r6,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r10.u8 & 0x3F));
	// and r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 & r30.u64;
	// lbzx r10,r10,r28
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + r28.u32);
	// clrlwi r9,r10,28
	ctx.r9.u64 = ctx.r10.u32 & 0xF;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// subf r31,r10,r31
	r31.u64 = r31.u64 - ctx.r10.u64;
	// lbzx r8,r9,r27
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + r27.u32);
	// srw r30,r30,r10
	r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r10.u8 & 0x3F));
	// b 0x82a7ba8c
	goto loc_82A7BA8C;
loc_82A7BA34:
	// cmplw cr6,r29,r23
	cr6.compare<uint32_t>(r29.u32, r23.u32, xer);
	// bge cr6,0x82a7bbf0
	if (!cr6.lt) goto loc_82A7BBF0;
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r10,r4,32
	xer.ca = ctx.r4.u32 <= 32;
	ctx.r10.u64 = static_cast<uint64_t>(32) - ctx.r4.u64;
	// slw r8,r9,r31
	ctx.r8.u64 = r31.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r31.u8 & 0x3F));
	// srw r10,r6,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r10.u8 & 0x3F));
	// or r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 | r30.u64;
	// and r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
	// lbzx r10,r10,r28
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + r28.u32);
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// lbzx r8,r8,r27
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + r27.u32);
	// blt cr6,0x82a7ba78
	if (cr6.lt) goto loc_82A7BA78;
	// subf r31,r10,r31
	r31.u64 = r31.u64 - ctx.r10.u64;
	// srw r30,r30,r10
	r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r10.u8 & 0x3F));
	// b 0x82a7ba8c
	goto loc_82A7BA8C;
loc_82A7BA78:
	// subf r7,r31,r10
	ctx.r7.u64 = ctx.r10.u64 - r31.u64;
	// subf r10,r10,r31
	ctx.r10.u64 = r31.u64 - ctx.r10.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r10,32
	r31.s64 = ctx.r10.s64 + 32;
	// srw r30,r9,r7
	r30.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r7.u8 & 0x3F));
loc_82A7BA8C:
	// clrlwi r9,r8,24
	ctx.r9.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r9,12
	cr6.compare<uint32_t>(ctx.r9.u32, 12, xer);
	// blt cr6,0x82a7bb58
	if (cr6.lt) goto loc_82A7BB58;
	// rlwinm r10,r26,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 8) & 0xFFFFFF00;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + r25.u64;
	// or r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 | r26.u64;
	// rlwinm r8,r10,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// lbz r9,-12(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + -12);
	// or r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 | ctx.r10.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// bgt cr6,0x82a7bc00
	if (cr6.gt) goto loc_82A7BC00;
	// clrlwi r9,r11,30
	ctx.r9.u64 = ctx.r11.u32 & 0x3;
	// subf r5,r10,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82a7bb3c
	if (cr6.eq) goto loc_82A7BB3C;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
loc_82A7BAD0:
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r7,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r7.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82a7bad0
	if (!cr6.eq) goto loc_82A7BAD0;
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x82a7bb14
	if (cr6.lt) goto loc_82A7BB14;
loc_82A7BAF8:
	// addi r10,r10,252
	ctx.r10.s64 = ctx.r10.s64 + 252;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// bge cr6,0x82a7baf8
	if (!cr6.lt) goto loc_82A7BAF8;
loc_82A7BB14:
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a7bb68
	if (cr6.eq) goto loc_82A7BB68;
loc_82A7BB20:
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r7,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r7.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82a7bb20
	if (!cr6.eq) goto loc_82A7BB20;
	// b 0x82a7bb68
	goto loc_82A7BB68;
loc_82A7BB3C:
	// addi r10,r10,252
	ctx.r10.s64 = ctx.r10.s64 + 252;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82a7bb3c
	if (!cr6.eq) goto loc_82A7BB3C;
	// b 0x82a7bb68
	goto loc_82A7BB68;
loc_82A7BB58:
	// stb r8,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82A7BB68:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82a7ba04
	if (!cr6.eq) goto loc_82A7BA04;
	// stw r29,4(r24)
	REX_STORE_U32(r24.u32 + 4, r29.u32);
	// stw r30,0(r24)
	REX_STORE_U32(r24.u32 + 0, r30.u32);
	// stw r31,8(r24)
	REX_STORE_U32(r24.u32 + 8, r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff804
	return;
loc_82A7BB84:
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
	// bge cr6,0x82a7bbc8
	if (!cr6.lt) goto loc_82A7BBC8;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r9,r31,4
	xer.ca = r31.u32 <= 4;
	ctx.r9.u64 = static_cast<uint64_t>(4) - r31.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// slw r8,r10,r31
	ctx.r8.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// or r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 | r30.u64;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r4,r8,28
	ctx.r4.u64 = ctx.r8.u32 & 0xF;
	// bl 0x829ff840
	ctx.lr = 0x82A7BBB4;
	rexcrt_memset(ctx, base);
	// stw r29,4(r24)
	REX_STORE_U32(r24.u32 + 4, r29.u32);
	// stw r30,0(r24)
	REX_STORE_U32(r24.u32 + 0, r30.u32);
	// stw r31,8(r24)
	REX_STORE_U32(r24.u32 + 8, r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff804
	return;
loc_82A7BBC8:
	// clrlwi r4,r30,28
	ctx.r4.u64 = r30.u32 & 0xF;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// rlwinm r30,r30,28,4,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 28) & 0xFFFFFFF;
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// bl 0x829ff840
	ctx.lr = 0x82A7BBDC;
	rexcrt_memset(ctx, base);
	// stw r29,4(r24)
	REX_STORE_U32(r24.u32 + 4, r29.u32);
	// stw r30,0(r24)
	REX_STORE_U32(r24.u32 + 0, r30.u32);
	// stw r31,8(r24)
	REX_STORE_U32(r24.u32 + 8, r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff804
	return;
loc_82A7BBF0:
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_82A7BC00:
	// stw r29,4(r24)
	REX_STORE_U32(r24.u32 + 4, r29.u32);
	// stw r30,0(r24)
	REX_STORE_U32(r24.u32 + 0, r30.u32);
	// stw r31,8(r24)
	REX_STORE_U32(r24.u32 + 8, r31.u32);
loc_82A7BC0C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff804
	return;
}

DEFINE_REX_FUNC(sub_82A7BC18) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7ac
	ctx.lr = 0x82A7BC20;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82a7bec0
	if (!cr6.eq) goto loc_82A7BEC0;
	// lwz r10,8(r21)
	ctx.r10.u64 = REX_LOAD_U32(r21.u32 + 8);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r28,4(r21)
	r28.u64 = REX_LOAD_U32(r21.u32 + 4);
	// lwz r7,0(r21)
	ctx.r7.u64 = REX_LOAD_U32(r21.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, xer);
	// bge cr6,0x82a7bc88
	if (!cr6.lt) goto loc_82A7BC88;
	// lwz r8,0(r28)
	ctx.r8.u64 = REX_LOAD_U32(r28.u32 + 0);
	// subfic r5,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r5.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r4,r10,r11
	ctx.r4.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// slw r10,r8,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// srw r5,r9,r5
	ctx.r5.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r5.u8 & 0x3F));
	// or r11,r10,r7
	ctx.r11.u64 = ctx.r10.u64 | ctx.r7.u64;
	// srw r30,r8,r4
	r30.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r4.u8 & 0x3F));
	// and r24,r5,r11
	r24.u64 = ctx.r5.u64 & ctx.r11.u64;
	// b 0x82a7bc9c
	goto loc_82A7BC9C;
loc_82A7BC88:
	// subfic r8,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r8.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r31,r11,r10
	r31.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srw r30,r7,r11
	r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r11.u8 & 0x3F));
	// srw r10,r9,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// and r24,r10,r7
	r24.u64 = ctx.r10.u64 & ctx.r7.u64;
loc_82A7BC9C:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x82a7bea4
	if (cr6.eq) goto loc_82A7BEA4;
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, ctx.r11.s32, xer);
	// bgt cr6,0x82a7bea4
	if (cr6.gt) goto loc_82A7BEA4;
	// lwz r23,48(r3)
	r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r26,r3,16
	r26.s64 = ctx.r3.s64 + 16;
	// lwz r4,32(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// add r11,r23,r24
	ctx.r11.u64 = r23.u64 + r24.u64;
	// lwz r25,36(r3)
	r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// mr r22,r23
	r22.u64 = r23.u64;
	// stw r23,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, r23.u32);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r29,384(r27)
	r29.u64 = REX_LOAD_U32(r27.u32 + 384);
	// bne cr6,0x82a7bcf0
	if (!cr6.eq) goto loc_82A7BCF0;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(r28.u32 + 0);
	// li r31,31
	r31.s64 = 31;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// rlwinm r30,r11,31,1,31
	r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7bcfc
	goto loc_82A7BCFC;
loc_82A7BCF0:
	// mr r11,r30
	ctx.r11.u64 = r30.u64;
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82A7BCFC:
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7bd0c
	if (cr6.eq) goto loc_82A7BD0C;
	// subfic r24,r24,-20
	xer.ca = r24.u32 <= 4294967276;
	r24.u64 = static_cast<uint64_t>(-20) - r24.u64;
loc_82A7BD0C:
	// addi r11,r29,64
	ctx.r11.s64 = r29.s64 + 64;
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r27
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + r27.u32);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, ctx.r11.u32, xer);
	// blt cr6,0x82a7bd60
	if (cr6.lt) goto loc_82A7BD60;
	// subfic r11,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// addi r10,r29,80
	ctx.r10.s64 = r29.s64 + 80;
	// rlwinm r8,r29,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r27
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + r27.u32);
	// srw r11,r9,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r11.u8 & 0x3F));
	// and r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 & r30.u64;
	// lbzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lbzx r29,r10,r27
	r29.u64 = REX_LOAD_U8(ctx.r10.u32 + r27.u32);
	// srw r10,r30,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r11.u8 & 0x3F));
	// subf r11,r11,r31
	ctx.r11.u64 = r31.u64 - ctx.r11.u64;
	// b 0x82a7bdc8
	goto loc_82A7BDC8;
loc_82A7BD60:
	// cmplw cr6,r28,r6
	cr6.compare<uint32_t>(r28.u32, ctx.r6.u32, xer);
	// bge cr6,0x82a7bea4
	if (!cr6.lt) goto loc_82A7BEA4;
	// lwz r8,0(r28)
	ctx.r8.u64 = REX_LOAD_U32(r28.u32 + 0);
	// subfic r11,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// addi r10,r29,80
	ctx.r10.s64 = r29.s64 + 80;
	// rlwinm r5,r29,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r27
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + r27.u32);
	// slw r7,r8,r31
	ctx.r7.u64 = r31.u8 & 0x20 ? 0 : (ctx.r8.u32 << (r31.u8 & 0x3F));
	// srw r11,r9,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r11.u8 & 0x3F));
	// or r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 | r30.u64;
	// and r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 & ctx.r7.u64;
	// lbzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// clrlwi r7,r11,28
	ctx.r7.u64 = ctx.r11.u32 & 0xF;
	// rlwinm r10,r11,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// add r11,r7,r5
	ctx.r11.u64 = ctx.r7.u64 + ctx.r5.u64;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// lbzx r29,r11,r27
	r29.u64 = REX_LOAD_U8(ctx.r11.u32 + r27.u32);
	// subf r11,r10,r31
	ctx.r11.u64 = r31.u64 - ctx.r10.u64;
	// blt cr6,0x82a7bdb8
	if (cr6.lt) goto loc_82A7BDB8;
	// srw r10,r30,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r10.u8 & 0x3F));
	// b 0x82a7bdc8
	goto loc_82A7BDC8;
loc_82A7BDB8:
	// subf r7,r31,r10
	ctx.r7.u64 = ctx.r10.u64 - r31.u64;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// srw r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
loc_82A7BDC8:
	// subfic r8,r4,32
	xer.ca = ctx.r4.u32 <= 32;
	ctx.r8.u64 = static_cast<uint64_t>(32) - ctx.r4.u64;
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, xer);
	// srw r8,r9,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// blt cr6,0x82a7bdf8
	if (cr6.lt) goto loc_82A7BDF8;
	// and r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 & ctx.r10.u64;
	// lbzx r8,r8,r25
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + r25.u32);
	// clrlwi r7,r8,28
	ctx.r7.u64 = ctx.r8.u32 & 0xF;
	// rlwinm r8,r8,28,4,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xFFFFFFF;
	// subf r31,r8,r11
	r31.u64 = ctx.r11.u64 - ctx.r8.u64;
	// lbzx r5,r7,r26
	ctx.r5.u64 = REX_LOAD_U8(ctx.r7.u32 + r26.u32);
	// srw r30,r10,r8
	r30.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// b 0x82a7be40
	goto loc_82A7BE40;
loc_82A7BDF8:
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(r28.u32 + 0);
	// slw r5,r7,r11
	ctx.r5.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r11.u8 & 0x3F));
	// or r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 | ctx.r10.u64;
	// and r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 & ctx.r5.u64;
	// lbzx r8,r8,r25
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + r25.u32);
	// clrlwi r5,r8,28
	ctx.r5.u64 = ctx.r8.u32 & 0xF;
	// rlwinm r8,r8,28,4,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xFFFFFFF;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, xer);
	// lbzx r5,r5,r26
	ctx.r5.u64 = REX_LOAD_U8(ctx.r5.u32 + r26.u32);
	// blt cr6,0x82a7be2c
	if (cr6.lt) goto loc_82A7BE2C;
	// subf r31,r8,r11
	r31.u64 = ctx.r11.u64 - ctx.r8.u64;
	// srw r30,r10,r8
	r30.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// b 0x82a7be40
	goto loc_82A7BE40;
loc_82A7BE2C:
	// subf r10,r11,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r11.u64;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r7,r10
	r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r10.u8 & 0x3F));
loc_82A7BE40:
	// rlwinm r11,r29,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// or r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 | ctx.r5.u64;
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	// clrlwi r11,r11,25
	ctx.r11.u64 = ctx.r11.u32 & 0x7F;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a7be60
	if (cr6.eq) goto loc_82A7BE60;
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_82A7BE60:
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// stb r11,0(r22)
	REX_STORE_U8(r22.u32 + 0, ctx.r11.u8);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// bgt cr6,0x82a7bd0c
	if (cr6.gt) goto loc_82A7BD0C;
	// cmpwi cr6,r24,-22
	cr6.compare<int32_t>(r24.s32, -22, xer);
	// bge cr6,0x82a7be8c
	if (!cr6.lt) goto loc_82A7BE8C;
	// subfic r5,r24,-21
	xer.ca = r24.u32 <= 4294967275;
	ctx.r5.u64 = static_cast<uint64_t>(-21) - r24.u64;
	// lbz r4,0(r23)
	ctx.r4.u64 = REX_LOAD_U8(r23.u32 + 0);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x829ff840
	ctx.lr = 0x82A7BE8C;
	rexcrt_memset(ctx, base);
loc_82A7BE8C:
	// stw r29,384(r27)
	REX_STORE_U32(r27.u32 + 384, r29.u32);
	// stw r28,4(r21)
	REX_STORE_U32(r21.u32 + 4, r28.u32);
	// stw r30,0(r21)
	REX_STORE_U32(r21.u32 + 0, r30.u32);
	// stw r31,8(r21)
	REX_STORE_U32(r21.u32 + 8, r31.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x829ff7fc
	return;
loc_82A7BEA4:
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r28,4(r21)
	REX_STORE_U32(r21.u32 + 4, r28.u32);
	// stw r30,0(r21)
	REX_STORE_U32(r21.u32 + 0, r30.u32);
	// stw r31,8(r21)
	REX_STORE_U32(r21.u32 + 8, r31.u32);
loc_82A7BEC0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x829ff7fc
	return;
}

DEFINE_REX_FUNC(sub_82A7BEC8) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7a8
	ctx.lr = 0x82A7BED0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82a7c158
	if (!cr6.eq) goto loc_82A7C158;
	// lwz r9,8(r20)
	ctx.r9.u64 = REX_LOAD_U32(r20.u32 + 8);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r29,4(r20)
	r29.u64 = REX_LOAD_U32(r20.u32 + 4);
	// lwz r7,0(r20)
	ctx.r7.u64 = REX_LOAD_U32(r20.u32 + 0);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, xer);
	// bge cr6,0x82a7bf38
	if (!cr6.lt) goto loc_82A7BF38;
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r5,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r5.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r4,r9,r11
	ctx.r4.u64 = ctx.r11.u64 - ctx.r9.u64;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// slw r9,r8,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// srw r5,r10,r5
	ctx.r5.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r5.u8 & 0x3F));
	// or r11,r9,r7
	ctx.r11.u64 = ctx.r9.u64 | ctx.r7.u64;
	// srw r30,r8,r4
	r30.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r4.u8 & 0x3F));
	// and r23,r5,r11
	r23.u64 = ctx.r5.u64 & ctx.r11.u64;
	// b 0x82a7bf4c
	goto loc_82A7BF4C;
loc_82A7BF38:
	// subfic r8,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r8.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r31,r11,r9
	r31.u64 = ctx.r9.u64 - ctx.r11.u64;
	// srw r30,r7,r11
	r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r11.u8 & 0x3F));
	// srw r9,r10,r8
	ctx.r9.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// and r23,r9,r7
	r23.u64 = ctx.r9.u64 & ctx.r7.u64;
loc_82A7BF4C:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// beq cr6,0x82a7c13c
	if (cr6.eq) goto loc_82A7C13C;
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, ctx.r11.s32, xer);
	// bgt cr6,0x82a7c13c
	if (cr6.gt) goto loc_82A7C13C;
	// lwz r22,48(r3)
	r22.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r25,r3,16
	r25.s64 = ctx.r3.s64 + 16;
	// lwz r26,32(r3)
	r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// add r11,r22,r23
	ctx.r11.u64 = r22.u64 + r23.u64;
	// lwz r24,36(r3)
	r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// mr r21,r22
	r21.u64 = r22.u64;
	// stw r22,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, r22.u32);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r5,384(r28)
	ctx.r5.u64 = REX_LOAD_U32(r28.u32 + 384);
	// bne cr6,0x82a7bfa0
	if (!cr6.eq) goto loc_82A7BFA0;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(r29.u32 + 0);
	// li r31,31
	r31.s64 = 31;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// rlwinm r30,r11,31,1,31
	r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7bfac
	goto loc_82A7BFAC;
loc_82A7BFA0:
	// mr r11,r30
	ctx.r11.u64 = r30.u64;
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82A7BFAC:
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7bfbc
	if (cr6.eq) goto loc_82A7BFBC;
	// subfic r23,r23,-20
	xer.ca = r23.u32 <= 4294967276;
	r23.u64 = static_cast<uint64_t>(-20) - r23.u64;
loc_82A7BFBC:
	// addi r11,r5,64
	ctx.r11.s64 = ctx.r5.s64 + 64;
	// addi r23,r23,-1
	r23.s64 = r23.s64 + -1;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + r28.u32);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, ctx.r11.u32, xer);
	// blt cr6,0x82a7c010
	if (cr6.lt) goto loc_82A7C010;
	// subfic r11,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// addi r9,r5,80
	ctx.r9.s64 = ctx.r5.s64 + 80;
	// rlwinm r8,r5,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r28
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + r28.u32);
	// srw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r11.u8 & 0x3F));
	// and r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 & r30.u64;
	// lbzx r11,r11,r9
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// clrlwi r9,r11,28
	ctx.r9.u64 = ctx.r11.u32 & 0xF;
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r27,r9,r28
	r27.u64 = REX_LOAD_U8(ctx.r9.u32 + r28.u32);
	// srw r9,r30,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r11.u8 & 0x3F));
	// subf r11,r11,r31
	ctx.r11.u64 = r31.u64 - ctx.r11.u64;
	// b 0x82a7c078
	goto loc_82A7C078;
loc_82A7C010:
	// cmplw cr6,r29,r6
	cr6.compare<uint32_t>(r29.u32, ctx.r6.u32, xer);
	// bge cr6,0x82a7c13c
	if (!cr6.lt) goto loc_82A7C13C;
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r11,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// addi r9,r5,80
	ctx.r9.s64 = ctx.r5.s64 + 80;
	// rlwinm r5,r5,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r28
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + r28.u32);
	// slw r7,r8,r31
	ctx.r7.u64 = r31.u8 & 0x20 ? 0 : (ctx.r8.u32 << (r31.u8 & 0x3F));
	// srw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r11.u8 & 0x3F));
	// or r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 | r30.u64;
	// and r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 & ctx.r7.u64;
	// lbzx r11,r11,r9
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// clrlwi r7,r11,28
	ctx.r7.u64 = ctx.r11.u32 & 0xF;
	// rlwinm r9,r11,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// add r11,r7,r5
	ctx.r11.u64 = ctx.r7.u64 + ctx.r5.u64;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// lbzx r27,r11,r28
	r27.u64 = REX_LOAD_U8(ctx.r11.u32 + r28.u32);
	// subf r11,r9,r31
	ctx.r11.u64 = r31.u64 - ctx.r9.u64;
	// blt cr6,0x82a7c068
	if (cr6.lt) goto loc_82A7C068;
	// srw r9,r30,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7c078
	goto loc_82A7C078;
loc_82A7C068:
	// subf r7,r31,r9
	ctx.r7.u64 = ctx.r9.u64 - r31.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// srw r9,r8,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
loc_82A7C078:
	// subfic r8,r26,32
	xer.ca = r26.u32 <= 32;
	ctx.r8.u64 = static_cast<uint64_t>(32) - r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(ctx.r11.u32, r26.u32, xer);
	// srw r8,r10,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// blt cr6,0x82a7c0ac
	if (cr6.lt) goto loc_82A7C0AC;
	// and r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 & ctx.r9.u64;
	// lbzx r8,r8,r24
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + r24.u32);
	// clrlwi r7,r8,28
	ctx.r7.u64 = ctx.r8.u32 & 0xF;
	// rlwinm r8,r8,28,4,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xFFFFFFF;
	// subf r31,r8,r11
	r31.u64 = ctx.r11.u64 - ctx.r8.u64;
	// lbzx r4,r7,r25
	ctx.r4.u64 = REX_LOAD_U8(ctx.r7.u32 + r25.u32);
	// srw r30,r9,r8
	r30.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// b 0x82a7c0f4
	goto loc_82A7C0F4;
loc_82A7C0AC:
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(r29.u32 + 0);
	// slw r4,r7,r11
	ctx.r4.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r11.u8 & 0x3F));
	// or r4,r4,r9
	ctx.r4.u64 = ctx.r4.u64 | ctx.r9.u64;
	// and r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 & ctx.r4.u64;
	// lbzx r8,r8,r24
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + r24.u32);
	// clrlwi r4,r8,28
	ctx.r4.u64 = ctx.r8.u32 & 0xF;
	// rlwinm r8,r8,28,4,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xFFFFFFF;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, xer);
	// lbzx r4,r4,r25
	ctx.r4.u64 = REX_LOAD_U8(ctx.r4.u32 + r25.u32);
	// blt cr6,0x82a7c0e0
	if (cr6.lt) goto loc_82A7C0E0;
	// subf r31,r8,r11
	r31.u64 = ctx.r11.u64 - ctx.r8.u64;
	// srw r30,r9,r8
	r30.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// b 0x82a7c0f4
	goto loc_82A7C0F4;
loc_82A7C0E0:
	// subf r9,r11,r8
	ctx.r9.u64 = ctx.r8.u64 - ctx.r11.u64;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r7,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r9.u8 & 0x3F));
loc_82A7C0F4:
	// rlwinm r11,r27,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// or r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 | ctx.r4.u64;
	// stb r11,0(r21)
	REX_STORE_U8(r21.u32 + 0, ctx.r11.u8);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// bgt cr6,0x82a7bfbc
	if (cr6.gt) goto loc_82A7BFBC;
	// cmpwi cr6,r23,-22
	cr6.compare<int32_t>(r23.s32, -22, xer);
	// bge cr6,0x82a7c124
	if (!cr6.lt) goto loc_82A7C124;
	// subfic r5,r23,-21
	xer.ca = r23.u32 <= 4294967275;
	ctx.r5.u64 = static_cast<uint64_t>(-21) - r23.u64;
	// lbz r4,0(r22)
	ctx.r4.u64 = REX_LOAD_U8(r22.u32 + 0);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x829ff840
	ctx.lr = 0x82A7C124;
	rexcrt_memset(ctx, base);
loc_82A7C124:
	// stw r27,384(r28)
	REX_STORE_U32(r28.u32 + 384, r27.u32);
	// stw r29,4(r20)
	REX_STORE_U32(r20.u32 + 4, r29.u32);
	// stw r30,0(r20)
	REX_STORE_U32(r20.u32 + 0, r30.u32);
	// stw r31,8(r20)
	REX_STORE_U32(r20.u32 + 8, r31.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x829ff7f8
	return;
loc_82A7C13C:
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r29,4(r20)
	REX_STORE_U32(r20.u32 + 4, r29.u32);
	// stw r30,0(r20)
	REX_STORE_U32(r20.u32 + 0, r30.u32);
	// stw r31,8(r20)
	REX_STORE_U32(r20.u32 + 8, r31.u32);
loc_82A7C158:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x829ff7f8
	return;
}

DEFINE_REX_FUNC(sub_82A7C160) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c0
	ctx.lr = 0x82A7C168;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82a7c388
	if (!cr6.eq) goto loc_82A7C388;
	// lwz r10,8(r28)
	ctx.r10.u64 = REX_LOAD_U32(r28.u32 + 8);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r29,4(r28)
	r29.u64 = REX_LOAD_U32(r28.u32 + 4);
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, xer);
	// bge cr6,0x82a7c1d0
	if (!cr6.lt) goto loc_82A7C1D0;
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r6,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r6.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r4,r10,r11
	ctx.r4.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// slw r10,r8,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// srw r6,r9,r6
	ctx.r6.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r6.u8 & 0x3F));
	// or r11,r10,r7
	ctx.r11.u64 = ctx.r10.u64 | ctx.r7.u64;
	// srw r30,r8,r4
	r30.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r4.u8 & 0x3F));
	// and r5,r6,r11
	ctx.r5.u64 = ctx.r6.u64 & ctx.r11.u64;
	// b 0x82a7c1e4
	goto loc_82A7C1E4;
loc_82A7C1D0:
	// subfic r8,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r8.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r31,r11,r10
	r31.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srw r30,r7,r11
	r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r11.u8 & 0x3F));
	// srw r10,r9,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// and r5,r10,r7
	ctx.r5.u64 = ctx.r10.u64 & ctx.r7.u64;
loc_82A7C1E4:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82a7c36c
	if (cr6.eq) goto loc_82A7C36C;
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, xer);
	// bgt cr6,0x82a7c36c
	if (cr6.gt) goto loc_82A7C36C;
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// add r10,r11,r5
	ctx.r10.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// bne cr6,0x82a7c224
	if (!cr6.eq) goto loc_82A7C224;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(r29.u32 + 0);
	// li r31,31
	r31.s64 = 31;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// rlwinm r30,r10,31,1,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7c230
	goto loc_82A7C230;
loc_82A7C224:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82A7C230:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82a7c300
	if (!cr6.eq) goto loc_82A7C300;
	// lwz r7,32(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// lwz r6,36(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
loc_82A7C248:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// cmplw cr6,r31,r7
	cr6.compare<uint32_t>(r31.u32, ctx.r7.u32, xer);
	// blt cr6,0x82a7c284
	if (cr6.lt) goto loc_82A7C284;
	// subfic r10,r7,32
	xer.ca = ctx.r7.u32 <= 32;
	ctx.r10.u64 = static_cast<uint64_t>(32) - ctx.r7.u64;
	// srw r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r10.u8 & 0x3F));
	// and r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 & r30.u64;
	// lbzx r10,r10,r6
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r6.u32);
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// subf r31,r10,r31
	r31.u64 = r31.u64 - ctx.r10.u64;
	// lbzx r8,r8,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r4.u32);
	// stb r8,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r30,r30,r10
	r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r10.u8 & 0x3F));
	// b 0x82a7c2e4
	goto loc_82A7C2E4;
loc_82A7C284:
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// bge cr6,0x82a7c36c
	if (!cr6.lt) goto loc_82A7C36C;
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r10,r7,32
	xer.ca = ctx.r7.u32 <= 32;
	ctx.r10.u64 = static_cast<uint64_t>(32) - ctx.r7.u64;
	// slw r26,r8,r31
	r26.u64 = r31.u8 & 0x20 ? 0 : (ctx.r8.u32 << (r31.u8 & 0x3F));
	// srw r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r10.u8 & 0x3F));
	// or r26,r26,r30
	r26.u64 = r26.u64 | r30.u64;
	// and r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 & r26.u64;
	// lbzx r10,r10,r6
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r6.u32);
	// clrlwi r26,r10,28
	r26.u64 = ctx.r10.u32 & 0xF;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// lbzx r26,r26,r4
	r26.u64 = REX_LOAD_U8(r26.u32 + ctx.r4.u32);
	// stb r26,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, r26.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// blt cr6,0x82a7c2d0
	if (cr6.lt) goto loc_82A7C2D0;
	// subf r31,r10,r31
	r31.u64 = r31.u64 - ctx.r10.u64;
	// srw r30,r30,r10
	r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r10.u8 & 0x3F));
	// b 0x82a7c2e4
	goto loc_82A7C2E4;
loc_82A7C2D0:
	// subf r30,r31,r10
	r30.u64 = ctx.r10.u64 - r31.u64;
	// subf r10,r10,r31
	ctx.r10.u64 = r31.u64 - ctx.r10.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r10,32
	r31.s64 = ctx.r10.s64 + 32;
	// srw r30,r8,r30
	r30.u64 = r30.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (r30.u8 & 0x3F));
loc_82A7C2E4:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82a7c248
	if (!cr6.eq) goto loc_82A7C248;
	// stw r29,4(r28)
	REX_STORE_U32(r28.u32 + 4, r29.u32);
	// stw r30,0(r28)
	REX_STORE_U32(r28.u32 + 0, r30.u32);
	// stw r31,8(r28)
	REX_STORE_U32(r28.u32 + 8, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
loc_82A7C300:
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
	// bge cr6,0x82a7c344
	if (!cr6.lt) goto loc_82A7C344;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r9,r31,4
	xer.ca = r31.u32 <= 4;
	ctx.r9.u64 = static_cast<uint64_t>(4) - r31.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// slw r8,r10,r31
	ctx.r8.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// or r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 | r30.u64;
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r4,r8,28
	ctx.r4.u64 = ctx.r8.u32 & 0xF;
	// bl 0x829ff840
	ctx.lr = 0x82A7C330;
	rexcrt_memset(ctx, base);
	// stw r29,4(r28)
	REX_STORE_U32(r28.u32 + 4, r29.u32);
	// stw r30,0(r28)
	REX_STORE_U32(r28.u32 + 0, r30.u32);
	// stw r31,8(r28)
	REX_STORE_U32(r28.u32 + 8, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
loc_82A7C344:
	// clrlwi r4,r30,28
	ctx.r4.u64 = r30.u32 & 0xF;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// rlwinm r30,r30,28,4,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 28) & 0xFFFFFFF;
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// bl 0x829ff840
	ctx.lr = 0x82A7C358;
	rexcrt_memset(ctx, base);
	// stw r29,4(r28)
	REX_STORE_U32(r28.u32 + 4, r29.u32);
	// stw r30,0(r28)
	REX_STORE_U32(r28.u32 + 0, r30.u32);
	// stw r31,8(r28)
	REX_STORE_U32(r28.u32 + 8, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
loc_82A7C36C:
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r29,4(r28)
	REX_STORE_U32(r28.u32 + 4, r29.u32);
	// stw r30,0(r28)
	REX_STORE_U32(r28.u32 + 0, r30.u32);
	// stw r31,8(r28)
	REX_STORE_U32(r28.u32 + 8, r31.u32);
loc_82A7C388:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
}

DEFINE_REX_FUNC(sub_82A7C390) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7bc
	ctx.lr = 0x82A7C398;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82a7c57c
	if (!cr6.eq) goto loc_82A7C57C;
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// li r29,-1
	r29.s64 = -1;
	// lwz r10,40(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r6,4(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r8,0(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x82a7c3f4
	if (!cr6.lt) goto loc_82A7C3F4;
	// lwz r9,0(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// subfic r7,r10,32
	xer.ca = ctx.r10.u32 <= 32;
	ctx.r7.u64 = static_cast<uint64_t>(32) - ctx.r10.u64;
	// subf r31,r11,r10
	r31.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// slw r30,r9,r11
	r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r11.u8 & 0x3F));
	// addi r11,r10,32
	ctx.r11.s64 = ctx.r10.s64 + 32;
	// or r10,r30,r8
	ctx.r10.u64 = r30.u64 | ctx.r8.u64;
	// srw r7,r29,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (r29.u32 >> (ctx.r7.u8 & 0x3F));
	// and r26,r7,r10
	r26.u64 = ctx.r7.u64 & ctx.r10.u64;
	// srw r10,r9,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (r31.u8 & 0x3F));
	// b 0x82a7c408
	goto loc_82A7C408;
loc_82A7C3F4:
	// subfic r9,r10,32
	xer.ca = ctx.r10.u32 <= 32;
	ctx.r9.u64 = static_cast<uint64_t>(32) - ctx.r10.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srw r10,r8,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r10.u8 & 0x3F));
	// srw r9,r29,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r29.u32 >> (ctx.r9.u8 & 0x3F));
	// and r26,r9,r8
	r26.u64 = ctx.r9.u64 & ctx.r8.u64;
loc_82A7C408:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82a7c560
	if (cr6.eq) goto loc_82A7C560;
	// lwz r9,44(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// cmplw cr6,r26,r9
	cr6.compare<uint32_t>(r26.u32, ctx.r9.u32, xer);
	// bgt cr6,0x82a7c560
	if (cr6.gt) goto loc_82A7C560;
	// lwz r9,48(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r31,r3,16
	r31.s64 = ctx.r3.s64 + 16;
	// lwz r28,32(r3)
	r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// add r8,r9,r26
	ctx.r8.u64 = ctx.r9.u64 + r26.u64;
	// lwz r30,36(r3)
	r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r8,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
loc_82A7C43C:
	// addi r26,r26,-1
	r26.s64 = r26.s64 + -1;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(ctx.r11.u32, r28.u32, xer);
	// blt cr6,0x82a7c470
	if (cr6.lt) goto loc_82A7C470;
	// subfic r9,r28,32
	xer.ca = r28.u32 <= 32;
	ctx.r9.u64 = static_cast<uint64_t>(32) - r28.u64;
	// srw r9,r29,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r29.u32 >> (ctx.r9.u8 & 0x3F));
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// lbzx r8,r8,r30
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + r30.u32);
	// clrlwi r7,r8,28
	ctx.r7.u64 = ctx.r8.u32 & 0xF;
	// rlwinm r8,r8,28,4,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xFFFFFFF;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// lbzx r27,r7,r31
	r27.u64 = REX_LOAD_U8(ctx.r7.u32 + r31.u32);
	// srw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// b 0x82a7c4c8
	goto loc_82A7C4C8;
loc_82A7C470:
	// cmplw cr6,r6,r5
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, xer);
	// bge cr6,0x82a7c560
	if (!cr6.lt) goto loc_82A7C560;
	// lwz r7,0(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// subfic r9,r28,32
	xer.ca = r28.u32 <= 32;
	ctx.r9.u64 = static_cast<uint64_t>(32) - r28.u64;
	// slw r8,r7,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r11.u8 & 0x3F));
	// srw r9,r29,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r29.u32 >> (ctx.r9.u8 & 0x3F));
	// or r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 | ctx.r10.u64;
	// and r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 & ctx.r9.u64;
	// lbzx r8,r8,r30
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + r30.u32);
	// clrlwi r27,r8,28
	r27.u64 = ctx.r8.u32 & 0xF;
	// rlwinm r8,r8,28,4,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xFFFFFFF;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, xer);
	// lbzx r27,r27,r31
	r27.u64 = REX_LOAD_U8(r27.u32 + r31.u32);
	// blt cr6,0x82a7c4b4
	if (cr6.lt) goto loc_82A7C4B4;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// srw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// b 0x82a7c4c8
	goto loc_82A7C4C8;
loc_82A7C4B4:
	// subf r10,r11,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r11.u64;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// srw r10,r7,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r10.u8 & 0x3F));
loc_82A7C4C8:
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(ctx.r11.u32, r28.u32, xer);
	// blt cr6,0x82a7c4f0
	if (cr6.lt) goto loc_82A7C4F0;
	// and r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ctx.r10.u64;
	// lbzx r9,r9,r30
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + r30.u32);
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// rlwinm r9,r9,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lbzx r7,r8,r31
	ctx.r7.u64 = REX_LOAD_U8(ctx.r8.u32 + r31.u32);
	// srw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7c538
	goto loc_82A7C538;
loc_82A7C4F0:
	// lwz r8,0(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// slw r7,r8,r11
	ctx.r7.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r11.u8 & 0x3F));
	// or r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 | ctx.r10.u64;
	// and r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 & ctx.r9.u64;
	// lbzx r9,r9,r30
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + r30.u32);
	// clrlwi r7,r9,28
	ctx.r7.u64 = ctx.r9.u32 & 0xF;
	// rlwinm r9,r9,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, xer);
	// lbzx r7,r7,r31
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + r31.u32);
	// blt cr6,0x82a7c524
	if (cr6.lt) goto loc_82A7C524;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// srw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// b 0x82a7c538
	goto loc_82A7C538;
loc_82A7C524:
	// subf r10,r11,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r11.u64;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// srw r10,r8,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r10.u8 & 0x3F));
loc_82A7C538:
	// rlwinm r9,r7,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// or r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 | r27.u64;
	// stb r9,0(r25)
	REX_STORE_U8(r25.u32 + 0, ctx.r9.u8);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// bne cr6,0x82a7c43c
	if (!cr6.eq) goto loc_82A7C43C;
	// stw r6,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// stw r11,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// b 0x829ff80c
	return;
loc_82A7C560:
	// lwz r9,48(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r8,r9,4
	ctx.r8.s64 = ctx.r9.s64 + 4;
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r6,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// stw r11,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
loc_82A7C57C:
	// b 0x829ff80c
	return;
}

DEFINE_REX_FUNC(sub_82A7C580) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c0
	ctx.lr = 0x82A7C588;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82a7c80c
	if (!cr6.eq) goto loc_82A7C80C;
	// lwz r10,8(r27)
	ctx.r10.u64 = REX_LOAD_U32(r27.u32 + 8);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r29,4(r27)
	r29.u64 = REX_LOAD_U32(r27.u32 + 4);
	// lwz r7,0(r27)
	ctx.r7.u64 = REX_LOAD_U32(r27.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, xer);
	// bge cr6,0x82a7c5f0
	if (!cr6.lt) goto loc_82A7C5F0;
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r6,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r6.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r4,r10,r11
	ctx.r4.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// slw r10,r8,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// srw r6,r9,r6
	ctx.r6.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r6.u8 & 0x3F));
	// or r11,r10,r7
	ctx.r11.u64 = ctx.r10.u64 | ctx.r7.u64;
	// srw r30,r8,r4
	r30.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r4.u8 & 0x3F));
	// and r5,r6,r11
	ctx.r5.u64 = ctx.r6.u64 & ctx.r11.u64;
	// b 0x82a7c604
	goto loc_82A7C604;
loc_82A7C5F0:
	// subfic r8,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r8.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r31,r11,r10
	r31.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srw r30,r7,r11
	r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r11.u8 & 0x3F));
	// srw r10,r9,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// and r5,r10,r7
	ctx.r5.u64 = ctx.r10.u64 & ctx.r7.u64;
loc_82A7C604:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82a7c7f0
	if (cr6.eq) goto loc_82A7C7F0;
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, xer);
	// bgt cr6,0x82a7c7f0
	if (cr6.gt) goto loc_82A7C7F0;
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// add r11,r10,r5
	ctx.r11.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bne cr6,0x82a7c644
	if (!cr6.eq) goto loc_82A7C644;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(r29.u32 + 0);
	// li r31,31
	r31.s64 = 31;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// rlwinm r30,r11,31,1,31
	r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7c650
	goto loc_82A7C650;
loc_82A7C644:
	// mr r11,r30
	ctx.r11.u64 = r30.u64;
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82A7C650:
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a7c75c
	if (!cr6.eq) goto loc_82A7C75C;
	// lwz r7,32(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// lwz r6,36(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
loc_82A7C66C:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// cmplw cr6,r31,r7
	cr6.compare<uint32_t>(r31.u32, ctx.r7.u32, xer);
	// blt cr6,0x82a7c6a0
	if (cr6.lt) goto loc_82A7C6A0;
	// subfic r11,r7,32
	xer.ca = ctx.r7.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r7.u64;
	// srw r11,r9,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r11.u8 & 0x3F));
	// and r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 & r30.u64;
	// lbzx r11,r11,r6
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r6.u32);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// subf r31,r11,r31
	r31.u64 = r31.u64 - ctx.r11.u64;
	// lbzx r8,r10,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// srw r30,r30,r11
	r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r11.u8 & 0x3F));
	// b 0x82a7c6f8
	goto loc_82A7C6F8;
loc_82A7C6A0:
	// cmplw cr6,r29,r26
	cr6.compare<uint32_t>(r29.u32, r26.u32, xer);
	// bge cr6,0x82a7c7f0
	if (!cr6.lt) goto loc_82A7C7F0;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r11,r7,32
	xer.ca = ctx.r7.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r7.u64;
	// slw r8,r10,r31
	ctx.r8.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r31.u8 & 0x3F));
	// srw r11,r9,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r11.u8 & 0x3F));
	// or r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 | r30.u64;
	// and r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 & ctx.r8.u64;
	// lbzx r11,r11,r6
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r6.u32);
	// clrlwi r8,r11,28
	ctx.r8.u64 = ctx.r11.u32 & 0xF;
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, ctx.r11.u32, xer);
	// lbzx r8,r8,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r4.u32);
	// blt cr6,0x82a7c6e4
	if (cr6.lt) goto loc_82A7C6E4;
	// subf r31,r11,r31
	r31.u64 = r31.u64 - ctx.r11.u64;
	// srw r30,r30,r11
	r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r11.u8 & 0x3F));
	// b 0x82a7c6f8
	goto loc_82A7C6F8;
loc_82A7C6E4:
	// subf r30,r31,r11
	r30.u64 = ctx.r11.u64 - r31.u64;
	// subf r11,r11,r31
	ctx.r11.u64 = r31.u64 - ctx.r11.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// srw r30,r10,r30
	r30.u64 = r30.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (r30.u8 & 0x3F));
loc_82A7C6F8:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82a7c738
	if (cr6.eq) goto loc_82A7C738;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82a7c71c
	if (!cr6.eq) goto loc_82A7C71C;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(r29.u32 + 0);
	// li r31,31
	r31.s64 = 31;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// rlwinm r30,r11,31,1,31
	r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7c728
	goto loc_82A7C728;
loc_82A7C71C:
	// mr r11,r30
	ctx.r11.u64 = r30.u64;
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82A7C728:
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7c738
	if (cr6.eq) goto loc_82A7C738;
	// neg r8,r8
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r8.u64);
loc_82A7C738:
	// stb r8,0(r28)
	REX_STORE_U8(r28.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// bne cr6,0x82a7c66c
	if (!cr6.eq) goto loc_82A7C66C;
	// stw r29,4(r27)
	REX_STORE_U32(r27.u32 + 4, r29.u32);
	// stw r30,0(r27)
	REX_STORE_U32(r27.u32 + 0, r30.u32);
	// stw r31,8(r27)
	REX_STORE_U32(r27.u32 + 8, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
loc_82A7C75C:
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
	// bge cr6,0x82a7c788
	if (!cr6.lt) goto loc_82A7C788;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r9,r31,4
	xer.ca = r31.u32 <= 4;
	ctx.r9.u64 = static_cast<uint64_t>(4) - r31.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// slw r8,r11,r31
	ctx.r8.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// or r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 | r30.u64;
	// srw r30,r11,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r4,r8,28
	ctx.r4.u64 = ctx.r8.u32 & 0xF;
	// b 0x82a7c794
	goto loc_82A7C794;
loc_82A7C788:
	// clrlwi r4,r30,28
	ctx.r4.u64 = r30.u32 & 0xF;
	// rlwinm r30,r30,28,4,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 28) & 0xFFFFFFF;
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
loc_82A7C794:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82a7c7d4
	if (cr6.eq) goto loc_82A7C7D4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82a7c7b8
	if (!cr6.eq) goto loc_82A7C7B8;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(r29.u32 + 0);
	// li r31,31
	r31.s64 = 31;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// rlwinm r30,r11,31,1,31
	r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7c7c4
	goto loc_82A7C7C4;
loc_82A7C7B8:
	// mr r11,r30
	ctx.r11.u64 = r30.u64;
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82A7C7C4:
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7c7d4
	if (cr6.eq) goto loc_82A7C7D4;
	// neg r4,r4
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r4.u64);
loc_82A7C7D4:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x829ff840
	ctx.lr = 0x82A7C7DC;
	rexcrt_memset(ctx, base);
	// stw r29,4(r27)
	REX_STORE_U32(r27.u32 + 4, r29.u32);
	// stw r30,0(r27)
	REX_STORE_U32(r27.u32 + 0, r30.u32);
	// stw r31,8(r27)
	REX_STORE_U32(r27.u32 + 8, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
loc_82A7C7F0:
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r29,4(r27)
	REX_STORE_U32(r27.u32 + 4, r29.u32);
	// stw r30,0(r27)
	REX_STORE_U32(r27.u32 + 0, r30.u32);
	// stw r31,8(r27)
	REX_STORE_U32(r27.u32 + 8, r31.u32);
loc_82A7C80C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
}

DEFINE_REX_FUNC(sub_82A7C818) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7a8
	ctx.lr = 0x82A7C820;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(r22.u32 + 0);
	// lwz r10,4(r22)
	ctx.r10.u64 = REX_LOAD_U32(r22.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82a7cb38
	if (!cr6.eq) goto loc_82A7CB38;
	// lwz r10,8(r21)
	ctx.r10.u64 = REX_LOAD_U32(r21.u32 + 8);
	// li r25,-1
	r25.s64 = -1;
	// lwz r11,40(r22)
	ctx.r11.u64 = REX_LOAD_U32(r22.u32 + 40);
	// lwz r29,4(r21)
	r29.u64 = REX_LOAD_U32(r21.u32 + 4);
	// lwz r8,0(r21)
	ctx.r8.u64 = REX_LOAD_U32(r21.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, xer);
	// bge cr6,0x82a7c88c
	if (!cr6.lt) goto loc_82A7C88C;
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r7,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r7.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r6,r10,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// slw r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// srw r7,r25,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (r25.u32 >> (ctx.r7.u8 & 0x3F));
	// or r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// srw r30,r9,r6
	r30.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r6.u8 & 0x3F));
	// and r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 & ctx.r11.u64;
	// b 0x82a7c8a0
	goto loc_82A7C8A0;
loc_82A7C88C:
	// subfic r9,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r9.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r31,r11,r10
	r31.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srw r30,r8,r11
	r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r11.u8 & 0x3F));
	// srw r10,r25,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r25.u32 >> (ctx.r9.u8 & 0x3F));
	// and r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 & ctx.r8.u64;
loc_82A7C8A0:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82a7cb1c
	if (cr6.eq) goto loc_82A7CB1C;
	// lwz r11,44(r22)
	ctx.r11.u64 = REX_LOAD_U32(r22.u32 + 44);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, xer);
	// bgt cr6,0x82a7cb1c
	if (cr6.gt) goto loc_82A7CB1C;
	// lwz r11,12(r22)
	ctx.r11.u64 = REX_LOAD_U32(r22.u32 + 12);
	// lwz r8,48(r22)
	ctx.r8.u64 = REX_LOAD_U32(r22.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(ctx.r11.s32, 0, xer);
	// lwz r11,8(r22)
	ctx.r11.u64 = REX_LOAD_U32(r22.u32 + 8);
	// beq cr6,0x82a7c968
	if (cr6.eq) goto loc_82A7C968;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bge cr6,0x82a7c90c
	if (!cr6.lt) goto loc_82A7C90C;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subf r9,r31,r11
	ctx.r9.u64 = ctx.r11.u64 - r31.u64;
	// subfic r6,r11,33
	xer.ca = ctx.r11.u32 <= 33;
	ctx.r6.u64 = static_cast<uint64_t>(33) - ctx.r11.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// subf r11,r11,r31
	ctx.r11.u64 = r31.u64 - ctx.r11.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// slw r5,r10,r31
	ctx.r5.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r31.u8 & 0x3F));
	// addi r31,r11,33
	r31.s64 = ctx.r11.s64 + 33;
	// or r11,r5,r30
	ctx.r11.u64 = ctx.r5.u64 | r30.u64;
	// srw r6,r25,r6
	ctx.r6.u64 = ctx.r6.u8 & 0x20 ? 0 : (r25.u32 >> (ctx.r6.u8 & 0x3F));
	// srw r30,r10,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// and r26,r6,r11
	r26.u64 = ctx.r6.u64 & ctx.r11.u64;
	// b 0x82a7c924
	goto loc_82A7C924;
loc_82A7C90C:
	// subfic r9,r11,33
	xer.ca = ctx.r11.u32 <= 33;
	ctx.r9.u64 = static_cast<uint64_t>(33) - ctx.r11.u64;
	// subf r11,r11,r31
	ctx.r11.u64 = r31.u64 - ctx.r11.u64;
	// addi r31,r11,1
	r31.s64 = ctx.r11.s64 + 1;
	// srw r11,r25,r9
	ctx.r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (r25.u32 >> (ctx.r9.u8 & 0x3F));
	// and r26,r11,r30
	r26.u64 = ctx.r11.u64 & r30.u64;
	// srw r30,r30,r10
	r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r10.u8 & 0x3F));
loc_82A7C924:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x82a7c9b4
	if (cr6.eq) goto loc_82A7C9B4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82a7c948
	if (!cr6.eq) goto loc_82A7C948;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(r29.u32 + 0);
	// li r31,31
	r31.s64 = 31;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// rlwinm r30,r11,31,1,31
	r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7c954
	goto loc_82A7C954;
loc_82A7C948:
	// mr r11,r30
	ctx.r11.u64 = r30.u64;
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82A7C954:
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7c9b4
	if (cr6.eq) goto loc_82A7C9B4;
	// neg r26,r26
	r26.s64 = static_cast<int64_t>(-r26.u64);
	// b 0x82a7c9b4
	goto loc_82A7C9B4;
loc_82A7C968:
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, ctx.r11.u32, xer);
	// bge cr6,0x82a7c9a0
	if (!cr6.lt) goto loc_82A7C9A0;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r9,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r9.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r6,r31,r11
	ctx.r6.u64 = ctx.r11.u64 - r31.u64;
	// subf r11,r11,r31
	ctx.r11.u64 = r31.u64 - ctx.r11.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// slw r5,r10,r31
	ctx.r5.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r31.u8 & 0x3F));
	// addi r31,r11,32
	r31.s64 = ctx.r11.s64 + 32;
	// or r11,r5,r30
	ctx.r11.u64 = ctx.r5.u64 | r30.u64;
	// srw r9,r25,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r25.u32 >> (ctx.r9.u8 & 0x3F));
	// srw r30,r10,r6
	r30.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r6.u8 & 0x3F));
	// and r26,r9,r11
	r26.u64 = ctx.r9.u64 & ctx.r11.u64;
	// b 0x82a7c9b4
	goto loc_82A7C9B4;
loc_82A7C9A0:
	// subfic r10,r11,32
	xer.ca = ctx.r11.u32 <= 32;
	ctx.r10.u64 = static_cast<uint64_t>(32) - ctx.r11.u64;
	// subf r31,r11,r31
	r31.u64 = r31.u64 - ctx.r11.u64;
	// srw r10,r25,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r25.u32 >> (ctx.r10.u8 & 0x3F));
	// and r26,r10,r30
	r26.u64 = ctx.r10.u64 & r30.u64;
	// srw r30,r30,r11
	r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r11.u8 & 0x3F));
loc_82A7C9B4:
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,0(r22)
	REX_STORE_U32(r22.u32 + 0, ctx.r8.u32);
	// clrlwi r28,r26,16
	r28.u64 = r26.u32 & 0xFFFF;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r23,r7,-1
	r23.s64 = ctx.r7.s64 + -1;
	// addi r27,r8,2
	r27.s64 = ctx.r8.s64 + 2;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// sth r28,0(r8)
	REX_STORE_U16(ctx.r8.u32 + 0, r28.u16);
	// stw r11,4(r22)
	REX_STORE_U32(r22.u32 + 4, ctx.r11.u32);
	// beq cr6,0x82a7cb2c
	if (cr6.eq) goto loc_82A7CB2C;
loc_82A7C9DC:
	// cmplwi cr6,r23,8
	cr6.compare<uint32_t>(r23.u32, 8, xer);
	// li r24,8
	r24.s64 = 8;
	// bgt cr6,0x82a7c9ec
	if (cr6.gt) goto loc_82A7C9EC;
	// mr r24,r23
	r24.u64 = r23.u64;
loc_82A7C9EC:
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
	// bge cr6,0x82a7ca20
	if (!cr6.lt) goto loc_82A7CA20;
	// cmplw cr6,r29,r20
	cr6.compare<uint32_t>(r29.u32, r20.u32, xer);
	// bge cr6,0x82a7cb1c
	if (!cr6.lt) goto loc_82A7CB1C;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subfic r9,r31,4
	xer.ca = r31.u32 <= 4;
	ctx.r9.u64 = static_cast<uint64_t>(4) - r31.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// slw r10,r11,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// or r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 | r30.u64;
	// srw r30,r11,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// b 0x82a7ca2c
	goto loc_82A7CA2C;
loc_82A7CA20:
	// clrlwi r10,r30,28
	ctx.r10.u64 = r30.u32 & 0xF;
	// rlwinm r30,r30,28,4,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 28) & 0xFFFFFFF;
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
loc_82A7CA2C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a7cae4
	if (cr6.eq) goto loc_82A7CAE4;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x82a7cafc
	if (cr6.eq) goto loc_82A7CAFC;
	// subfic r11,r10,32
	xer.ca = ctx.r10.u32 <= 32;
	ctx.r11.u64 = static_cast<uint64_t>(32) - ctx.r10.u64;
	// srw r8,r25,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (r25.u32 >> (ctx.r11.u8 & 0x3F));
loc_82A7CA48:
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bge cr6,0x82a7ca7c
	if (!cr6.lt) goto loc_82A7CA7C;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(r29.u32 + 0);
	// subf r6,r31,r10
	ctx.r6.u64 = ctx.r10.u64 - r31.u64;
	// subf r9,r10,r31
	ctx.r9.u64 = r31.u64 - ctx.r10.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// slw r5,r11,r31
	ctx.r5.u64 = r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r9,32
	r31.s64 = ctx.r9.s64 + 32;
	// or r9,r5,r30
	ctx.r9.u64 = ctx.r5.u64 | r30.u64;
	// srw r30,r11,r6
	r30.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r6.u8 & 0x3F));
	// and r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 & ctx.r8.u64;
	// b 0x82a7ca88
	goto loc_82A7CA88;
loc_82A7CA7C:
	// and r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 & r30.u64;
	// subf r31,r10,r31
	r31.u64 = r31.u64 - ctx.r10.u64;
	// srw r30,r30,r10
	r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r10.u8 & 0x3F));
loc_82A7CA88:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82a7cac8
	if (cr6.eq) goto loc_82A7CAC8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82a7caac
	if (!cr6.eq) goto loc_82A7CAAC;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(r29.u32 + 0);
	// li r31,31
	r31.s64 = 31;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// rlwinm r30,r11,31,1,31
	r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7cab8
	goto loc_82A7CAB8;
loc_82A7CAAC:
	// mr r11,r30
	ctx.r11.u64 = r30.u64;
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82A7CAB8:
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7cac8
	if (cr6.eq) goto loc_82A7CAC8;
	// neg r9,r9
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r9.u64);
loc_82A7CAC8:
	// add r26,r9,r26
	r26.u64 = ctx.r9.u64 + r26.u64;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// clrlwi r28,r26,16
	r28.u64 = r26.u32 & 0xFFFF;
	// sth r28,0(r27)
	REX_STORE_U16(r27.u32 + 0, r28.u16);
	// addi r27,r27,2
	r27.s64 = r27.s64 + 2;
	// bne cr6,0x82a7ca48
	if (!cr6.eq) goto loc_82A7CA48;
	// b 0x82a7cafc
	goto loc_82A7CAFC;
loc_82A7CAE4:
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82a84538
	ctx.lr = 0x82A7CAF4;
	sub_82A84538(ctx, base);
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 1) & 0xFFFFFFFE;
	// add r27,r11,r27
	r27.u64 = ctx.r11.u64 + r27.u64;
loc_82A7CAFC:
	// subf r23,r24,r23
	r23.u64 = r23.u64 - r24.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x82a7c9dc
	if (!cr6.eq) goto loc_82A7C9DC;
	// stw r29,4(r21)
	REX_STORE_U32(r21.u32 + 4, r29.u32);
	// stw r30,0(r21)
	REX_STORE_U32(r21.u32 + 0, r30.u32);
	// stw r31,8(r21)
	REX_STORE_U32(r21.u32 + 8, r31.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x829ff7f8
	return;
loc_82A7CB1C:
	// lwz r11,48(r22)
	ctx.r11.u64 = REX_LOAD_U32(r22.u32 + 48);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,4(r22)
	REX_STORE_U32(r22.u32 + 4, ctx.r11.u32);
	// stw r10,0(r22)
	REX_STORE_U32(r22.u32 + 0, ctx.r10.u32);
loc_82A7CB2C:
	// stw r29,4(r21)
	REX_STORE_U32(r21.u32 + 4, r29.u32);
	// stw r30,0(r21)
	REX_STORE_U32(r21.u32 + 0, r30.u32);
	// stw r31,8(r21)
	REX_STORE_U32(r21.u32 + 8, r31.u32);
loc_82A7CB38:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x829ff7f8
	return;
}

DEFINE_REX_FUNC(sub_82A7CB40) {
	REX_FUNC_PROLOGUE();
	// rlwinm r11,r4,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r10,r4,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r11,515
	ctx.r11.s64 = ctx.r11.s64 + 515;
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r10,1,3,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1FFFFFFE;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r10,1027
	ctx.r10.s64 = ctx.r10.s64 + 1027;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r9,r10,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r10,r11,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r7,r11,3,3,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x1FFFFFF8;
	// clrlwi r8,r11,3
	ctx.r8.u64 = ctx.r11.u32 & 0x1FFFFFFF;
	// rlwinm r11,r6,1,3,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1FFFFFFE;
	// addi r7,r7,515
	ctx.r7.s64 = ctx.r7.s64 + 515;
	// stw r9,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// addi r8,r8,515
	ctx.r8.s64 = ctx.r8.s64 + 515;
	// stw r9,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// addi r11,r11,515
	ctx.r11.s64 = ctx.r11.s64 + 515;
	// addi r10,r10,515
	ctx.r10.s64 = ctx.r10.s64 + 515;
	// rlwinm r7,r7,0,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r8,r8,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r7,r7,64
	ctx.r7.s64 = ctx.r7.s64 + 64;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r7,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r8,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// stw r11,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r10,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A7CBD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r14{};
	PPCRegister r15{};
	PPCRegister r16{};
	PPCRegister r17{};
	PPCRegister r18{};
	PPCRegister r19{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff790
	ctx.lr = 0x82A7CBD8;
	// stwu r1,-1456(r1)
	ea = -1456 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
	// lwz r21,1540(r1)
	r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 1540);
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// stw r4,1484(r1)
	REX_STORE_U32(ctx.r1.u32 + 1484, ctx.r4.u32);
	// addi r11,r20,-8
	ctx.r11.s64 = r20.s64 + -8;
	// stw r8,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mr r17,r5
	r17.u64 = ctx.r5.u64;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(r30.s32);
	// stw r20,1500(r1)
	REX_STORE_U32(ctx.r1.u32 + 1500, r20.u32);
	// stw r30,1508(r1)
	REX_STORE_U32(ctx.r1.u32 + 1508, r30.u32);
	// stw r21,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, r21.u32);
	// stw r17,1492(r1)
	REX_STORE_U32(ctx.r1.u32 + 1492, r17.u32);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// li r23,0
	r23.s64 = 0;
	// rlwinm r10,r30,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r17
	ctx.r11.u64 = ctx.r11.u64 + r17.u64;
	// mr r14,r9
	r14.u64 = ctx.r9.u64;
	// lwz r9,1572(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 1572);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// subf r10,r17,r10
	ctx.r10.u64 = ctx.r10.u64 - r17.u64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// stw r23,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, r23.u32);
	// mr r22,r23
	r22.u64 = r23.u64;
	// stw r23,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, r23.u32);
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// stw r14,1524(r1)
	REX_STORE_U32(ctx.r1.u32 + 1524, r14.u32);
	// rlwinm r9,r9,0,16,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8000;
	// stw r29,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, r29.u32);
	// stw r10,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r10.u32);
	// stw r19,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, r19.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r22,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, r22.u32);
	// stw r11,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r11.u32);
	// stw r23,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, r23.u32);
	// beq cr6,0x82a7cc78
	if (cr6.eq) goto loc_82A7CC78;
	// lis r11,-32088
	ctx.r11.s64 = -2102919168;
	// addi r11,r11,-17384
	ctx.r11.s64 = ctx.r11.s64 + -17384;
	// b 0x82a7cc80
	goto loc_82A7CC80;
loc_82A7CC78:
	// lis r11,-32088
	ctx.r11.s64 = -2102919168;
	// addi r11,r11,-16696
	ctx.r11.s64 = ctx.r11.s64 + -16696;
loc_82A7CC80:
	// stw r11,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r11.u32);
	// rlwinm r10,r17,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 29) & 0x1FFFFFFF;
	// lwz r11,1564(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 1564);
	// rlwinm r6,r17,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 28) & 0xFFFFFFF;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r23,528(r1)
	REX_STORE_U32(ctx.r1.u32 + 528, r23.u32);
	// addi r18,r10,511
	r18.s64 = ctx.r10.s64 + 511;
	// stw r23,532(r1)
	REX_STORE_U32(ctx.r1.u32 + 532, r23.u32);
	// rlwinm r8,r10,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r23,540(r1)
	REX_STORE_U32(ctx.r1.u32 + 540, r23.u32);
	// clrlwi r18,r18,16
	r18.u64 = r18.u32 & 0xFFFF;
	// stw r23,592(r1)
	REX_STORE_U32(ctx.r1.u32 + 592, r23.u32);
	// lwz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r8,r8,511
	ctx.r8.s64 = ctx.r8.s64 + 511;
	// lwz r28,16(r11)
	r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cntlzw r18,r18
	r18.u64 = r18.u32 == 0 ? 32 : __builtin_clz(r18.u32);
	// lwz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// clrlwi r16,r8,16
	r16.u64 = ctx.r8.u32 & 0xFFFF;
	// stw r9,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r9.u32);
	// subfic r8,r18,32
	xer.ca = r18.u32 <= 32;
	ctx.r8.u64 = static_cast<uint64_t>(32) - r18.u64;
	// stw r9,472(r1)
	REX_STORE_U32(ctx.r1.u32 + 472, ctx.r9.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r5,640(r1)
	REX_STORE_U32(ctx.r1.u32 + 640, ctx.r5.u32);
	// addi r5,r6,511
	ctx.r5.s64 = ctx.r6.s64 + 511;
	// stw r28,384(r1)
	REX_STORE_U32(ctx.r1.u32 + 384, r28.u32);
	// cntlzw r18,r16
	r18.u64 = r16.u32 == 0 ? 32 : __builtin_clz(r16.u32);
	// clrlwi r28,r5,16
	r28.u64 = ctx.r5.u32 & 0xFFFF;
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// li r31,4
	r31.s64 = 4;
	// cntlzw r28,r28
	r28.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// stw r4,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r4.u32);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// stw r9,344(r1)
	REX_STORE_U32(ctx.r1.u32 + 344, ctx.r9.u32);
	// subfic r28,r28,32
	xer.ca = r28.u32 <= 32;
	r28.u64 = static_cast<uint64_t>(32) - r28.u64;
	// stw r9,216(r1)
	REX_STORE_U32(ctx.r1.u32 + 216, ctx.r9.u32);
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r7,576(r1)
	REX_STORE_U32(ctx.r1.u32 + 576, ctx.r7.u32);
	// addi r4,r4,515
	ctx.r4.s64 = ctx.r4.s64 + 515;
	// stw r3,512(r1)
	REX_STORE_U32(ctx.r1.u32 + 512, ctx.r3.u32);
	// lwz r27,20(r11)
	r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// li r24,16
	r24.s64 = 16;
	// li r25,11
	r25.s64 = 11;
	// lwz r26,24(r11)
	r26.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// stw r28,632(r1)
	REX_STORE_U32(ctx.r1.u32 + 632, r28.u32);
	// rlwinm r7,r9,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r3,r9,511
	ctx.r3.s64 = ctx.r9.s64 + 511;
	// stw r31,536(r1)
	REX_STORE_U32(ctx.r1.u32 + 536, r31.u32);
	// subfic r28,r18,32
	xer.ca = r18.u32 <= 32;
	r28.u64 = static_cast<uint64_t>(32) - r18.u64;
	// stw r23,596(r1)
	REX_STORE_U32(ctx.r1.u32 + 596, r23.u32);
	// rlwinm r4,r4,0,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r31,600(r1)
	REX_STORE_U32(ctx.r1.u32 + 600, r31.u32);
	// addi r7,r7,515
	ctx.r7.s64 = ctx.r7.s64 + 515;
	// stw r23,604(r1)
	REX_STORE_U32(ctx.r1.u32 + 604, r23.u32);
	// rlwinm r5,r9,3,3,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0x1FFFFFF8;
	// stw r23,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, r23.u32);
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r23,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, r23.u32);
	// clrlwi r6,r9,3
	ctx.r6.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// stw r23,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, r23.u32);
	// stw r23,464(r1)
	REX_STORE_U32(ctx.r1.u32 + 464, r23.u32);
	// rlwinm r7,r7,0,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r23,468(r1)
	REX_STORE_U32(ctx.r1.u32 + 468, r23.u32);
	// addi r5,r5,515
	ctx.r5.s64 = ctx.r5.s64 + 515;
	// stw r23,476(r1)
	REX_STORE_U32(ctx.r1.u32 + 476, r23.u32);
	// cntlzw r3,r3
	ctx.r3.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// stw r23,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, r23.u32);
	// addi r6,r6,515
	ctx.r6.s64 = ctx.r6.s64 + 515;
	// stw r23,340(r1)
	REX_STORE_U32(ctx.r1.u32 + 340, r23.u32);
	// stw r24,348(r1)
	REX_STORE_U32(ctx.r1.u32 + 348, r24.u32);
	// stw r23,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, r23.u32);
	// stw r23,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, r23.u32);
	// stw r24,220(r1)
	REX_STORE_U32(ctx.r1.u32 + 220, r24.u32);
	// stw r23,400(r1)
	REX_STORE_U32(ctx.r1.u32 + 400, r23.u32);
	// stw r23,404(r1)
	REX_STORE_U32(ctx.r1.u32 + 404, r23.u32);
	// stw r25,408(r1)
	REX_STORE_U32(ctx.r1.u32 + 408, r25.u32);
	// stw r23,412(r1)
	REX_STORE_U32(ctx.r1.u32 + 412, r23.u32);
	// stw r27,256(r1)
	REX_STORE_U32(ctx.r1.u32 + 256, r27.u32);
	// stw r28,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, r28.u32);
	// stw r8,568(r1)
	REX_STORE_U32(ctx.r1.u32 + 568, ctx.r8.u32);
	// stw r4,636(r1)
	REX_STORE_U32(ctx.r1.u32 + 636, ctx.r4.u32);
	// rlwinm r6,r6,0,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r7,572(r1)
	REX_STORE_U32(ctx.r1.u32 + 572, ctx.r7.u32);
	// stw r7,380(r1)
	REX_STORE_U32(ctx.r1.u32 + 380, ctx.r7.u32);
	// rlwinm r5,r5,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r7,252(r1)
	REX_STORE_U32(ctx.r1.u32 + 252, ctx.r7.u32);
	// addi r4,r1,564
	ctx.r4.s64 = ctx.r1.s64 + 564;
	// lwz r7,28(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r28,32(r11)
	r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// stw r6,508(r1)
	REX_STORE_U32(ctx.r1.u32 + 508, ctx.r6.u32);
	// rlwinm r6,r10,1,3,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1FFFFFFE;
	// stw r5,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r5.u32);
	// subfic r5,r3,32
	xer.ca = ctx.r3.u32 <= 32;
	ctx.r5.u64 = static_cast<uint64_t>(32) - ctx.r3.u64;
	// addi r11,r6,1027
	ctx.r11.s64 = ctx.r6.s64 + 1027;
	// stw r8,376(r1)
	REX_STORE_U32(ctx.r1.u32 + 376, ctx.r8.u32);
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,248(r1)
	REX_STORE_U32(ctx.r1.u32 + 248, ctx.r8.u32);
	// stw r8,440(r1)
	REX_STORE_U32(ctx.r1.u32 + 440, ctx.r8.u32);
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r8,760(r1)
	REX_STORE_U32(ctx.r1.u32 + 760, ctx.r8.u32);
	// li r8,1024
	ctx.r8.s64 = 1024;
	// stw r5,504(r1)
	REX_STORE_U32(ctx.r1.u32 + 504, ctx.r5.u32);
	// rlwinm r6,r10,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r26,448(r1)
	REX_STORE_U32(ctx.r1.u32 + 448, r26.u32);
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r23,720(r1)
	REX_STORE_U32(ctx.r1.u32 + 720, r23.u32);
	// addi r6,r6,511
	ctx.r6.s64 = ctx.r6.s64 + 511;
	// stw r23,724(r1)
	REX_STORE_U32(ctx.r1.u32 + 724, r23.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r25,728(r1)
	REX_STORE_U32(ctx.r1.u32 + 728, r25.u32);
	// clrlwi r9,r6,16
	ctx.r9.u64 = ctx.r6.u32 & 0xFFFF;
	// stw r8,732(r1)
	REX_STORE_U32(ctx.r1.u32 + 732, ctx.r8.u32);
	// rlwinm r10,r10,1,3,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1FFFFFFE;
	// stw r23,272(r1)
	REX_STORE_U32(ctx.r1.u32 + 272, r23.u32);
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stw r23,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, r23.u32);
	// addi r10,r10,515
	ctx.r10.s64 = ctx.r10.s64 + 515;
	// stw r31,280(r1)
	REX_STORE_U32(ctx.r1.u32 + 280, r31.u32);
	// subfic r9,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r9.u64 = static_cast<uint64_t>(32) - ctx.r9.u64;
	// stw r23,284(r1)
	REX_STORE_U32(ctx.r1.u32 + 284, r23.u32);
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r7,768(r1)
	REX_STORE_U32(ctx.r1.u32 + 768, ctx.r7.u32);
	// addi r6,r1,544
	ctx.r6.s64 = ctx.r1.s64 + 544;
	// stw r28,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, r28.u32);
	// addi r5,r1,560
	ctx.r5.s64 = ctx.r1.s64 + 560;
	// stw r11,444(r1)
	REX_STORE_U32(ctx.r1.u32 + 444, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,764(r1)
	REX_STORE_U32(ctx.r1.u32 + 764, ctx.r11.u32);
	// stw r9,312(r1)
	REX_STORE_U32(ctx.r1.u32 + 312, ctx.r9.u32);
	// stw r10,316(r1)
	REX_STORE_U32(ctx.r1.u32 + 316, ctx.r10.u32);
	// bl 0x82a7b110
	ctx.lr = 0x82A7CE90;
	sub_82A7B110(ctx, base);
	// addi r6,r1,608
	ctx.r6.s64 = ctx.r1.s64 + 608;
	// addi r5,r1,624
	ctx.r5.s64 = ctx.r1.s64 + 624;
	// addi r4,r1,628
	ctx.r4.s64 = ctx.r1.s64 + 628;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82a7b110
	ctx.lr = 0x82A7CEA4;
	sub_82A7B110(ctx, base);
	// addi r31,r1,1232
	r31.s64 = ctx.r1.s64 + 1232;
	// addi r28,r1,912
	r28.s64 = ctx.r1.s64 + 912;
loc_82A7CEAC:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r5,r31,-64
	ctx.r5.s64 = r31.s64 + -64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82a7b110
	ctx.lr = 0x82A7CEC0;
	sub_82A7B110(ctx, base);
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// addi r28,r28,16
	r28.s64 = r28.s64 + 16;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x82a7ceac
	if (!cr6.eq) goto loc_82A7CEAC;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,164
	ctx.r4.s64 = ctx.r1.s64 + 164;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82a7b110
	ctx.lr = 0x82A7CEE8;
	sub_82A7B110(ctx, base);
	// addi r6,r1,480
	ctx.r6.s64 = ctx.r1.s64 + 480;
	// addi r5,r1,496
	ctx.r5.s64 = ctx.r1.s64 + 496;
	// stw r23,1296(r1)
	REX_STORE_U32(ctx.r1.u32 + 1296, r23.u32);
	// addi r4,r1,500
	ctx.r4.s64 = ctx.r1.s64 + 500;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82a7b110
	ctx.lr = 0x82A7CF00;
	sub_82A7B110(ctx, base);
	// addi r6,r1,352
	ctx.r6.s64 = ctx.r1.s64 + 352;
	// addi r5,r1,368
	ctx.r5.s64 = ctx.r1.s64 + 368;
	// addi r4,r1,372
	ctx.r4.s64 = ctx.r1.s64 + 372;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82a7b110
	ctx.lr = 0x82A7CF14;
	sub_82A7B110(ctx, base);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// addi r4,r1,244
	ctx.r4.s64 = ctx.r1.s64 + 244;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82a7b110
	ctx.lr = 0x82A7CF28;
	sub_82A7B110(ctx, base);
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// addi r5,r1,304
	ctx.r5.s64 = ctx.r1.s64 + 304;
	// addi r4,r1,308
	ctx.r4.s64 = ctx.r1.s64 + 308;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82a7b110
	ctx.lr = 0x82A7CF3C;
	sub_82A7B110(ctx, base);
	// mr r15,r23
	r15.u64 = r23.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// stw r15,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, r15.u32);
	// beq cr6,0x82a7ef54
	if (cr6.eq) goto loc_82A7EF54;
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// li r18,1
	r18.s64 = 1;
	// addi r31,r11,-28184
	r31.s64 = ctx.r11.s64 + -28184;
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// addi r11,r11,-19744
	ctx.r11.s64 = ctx.r11.s64 + -19744;
	// stw r31,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, r31.u32);
	// stw r11,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r11.u32);
	// b 0x82a7cf74
	goto loc_82A7CF74;
loc_82A7CF6C:
	// lwz r14,1524(r1)
	r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 1524);
	// lwz r17,1492(r1)
	r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 1492);
loc_82A7CF74:
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82a7b910
	ctx.lr = 0x82A7CF84;
	sub_82A7B910(ctx, base);
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,592
	ctx.r3.s64 = ctx.r1.s64 + 592;
	// bl 0x82a7b910
	ctx.lr = 0x82A7CF94;
	sub_82A7B910(ctx, base);
	// lwz r11,196(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
	// addi r5,r1,912
	ctx.r5.s64 = ctx.r1.s64 + 912;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7CFB0;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// bl 0x82a7c390
	ctx.lr = 0x82A7CFC0;
	sub_82A7C390(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x82a7c580
	ctx.lr = 0x82A7CFCC;
	sub_82A7C580(ctx, base);
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82a7c580
	ctx.lr = 0x82A7CFDC;
	sub_82A7C580(ctx, base);
	// lwz r26,208(r1)
	r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 208);
	// lwz r11,256(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 256);
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// lwz r10,384(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 384);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// subf r11,r11,r26
	ctx.r11.u64 = r26.u64 - ctx.r11.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// add r20,r11,r10
	r20.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r20,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, r20.u32);
	// bl 0x82a7c818
	ctx.lr = 0x82A7D004;
	sub_82A7C818(ctx, base);
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,720
	ctx.r3.s64 = ctx.r1.s64 + 720;
	// bl 0x82a7c818
	ctx.lr = 0x82A7D014;
	sub_82A7C818(ctx, base);
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x82a7c160
	ctx.lr = 0x82A7D024;
	sub_82A7C160(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// lwz r24,88(r1)
	r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r27,80(r1)
	r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r25,464(r1)
	r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 464);
	// lwz r16,400(r1)
	r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 400);
	// lwz r17,272(r1)
	r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 272);
	// stw r4,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// b 0x82a7d050
	goto loc_82A7D050;
loc_82A7D04C:
	// lwz r14,1524(r1)
	r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 1524);
loc_82A7D050:
	// lwz r9,212(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 212);
	// cmplw cr6,r3,r14
	cr6.compare<uint32_t>(ctx.r3.u32, r14.u32, xer);
	// lwz r6,468(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 468);
	// lwz r28,404(r1)
	r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 404);
	// lwz r5,1484(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 1484);
	// lwz r7,1500(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 1500);
	// bge cr6,0x82a7eec0
	if (!cr6.lt) goto loc_82A7EEC0;
	// lwz r10,532(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 532);
	// lwz r8,528(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 528);
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bge cr6,0x82a7eec0
	if (!cr6.lt) goto loc_82A7EEC0;
	// lbz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r10,9
	cr6.compare<uint32_t>(ctx.r10.u32, 9, xer);
	// stw r8,528(r1)
	REX_STORE_U32(ctx.r1.u32 + 528, ctx.r8.u32);
	// bgt cr6,0x82a7eec0
	if (cr6.gt) goto loc_82A7EEC0;
	// lis r12,-32088
	ctx.r12.s64 = -2102919168;
	// addi r12,r12,-12120
	ctx.r12.s64 = ctx.r12.s64 + -12120;
	// rlwinm r0,r10,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_82A7D0D0;
	case 1:
		goto loc_82A7D160;
	case 2:
		goto loc_82A7DF0C;
	case 3:
		goto loc_82A7E308;
	case 4:
		goto loc_82A7E4D4;
	case 5:
		goto loc_82A7E5A8;
	case 6:
		goto loc_82A7E65C;
	case 7:
		goto loc_82A7E6F4;
	case 8:
		goto loc_82A7E814;
	case 9:
		goto loc_82A7EAE0;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82A7D0D0:
	// rlwinm r8,r22,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 31) & 0x7FFFFFFF;
	// lfd f0,0(r19)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(r19.u32 + 0);
	// add r10,r19,r30
	ctx.r10.u64 = r19.u64 + r30.u64;
	// stfd f0,0(r29)
	REX_STORE_U64(r29.u32 + 0, ctx.f0.u64);
	// add r9,r29,r30
	ctx.r9.u64 = r29.u64 + r30.u64;
	// lbzx r8,r8,r21
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + r21.u32);
	// lfd f0,0(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stfd f0,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.f0.u64);
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// lfd f0,0(r8)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r8.u32 + 0);
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// stfd f0,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.f0.u64);
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// lfd f0,0(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 0);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stfd f0,0(r8)
	REX_STORE_U64(ctx.r8.u32 + 0, ctx.f0.u64);
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// lfd f0,0(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// stfd f0,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.f0.u64);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// lfd f0,0(r8)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r8.u32 + 0);
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// stfd f0,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.f0.u64);
	// lfd f0,0(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 0);
	// stfd f0,0(r8)
	REX_STORE_U64(ctx.r8.u32 + 0, ctx.f0.u64);
	// lfdx f0,r9,r30
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + r30.u32);
	// stfdx f0,r8,r30
	REX_STORE_U64(ctx.r8.u32 + r30.u32, ctx.f0.u64);
	// bne cr6,0x82a7eec0
	if (!cr6.eq) goto loc_82A7EEC0;
	// lwz r10,180(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r10.u32);
	// b 0x82a7eec0
	goto loc_82A7EEC0;
loc_82A7D160:
	// cmplwi cr6,r4,16
	cr6.compare<uint32_t>(ctx.r4.u32, 16, xer);
	// blt cr6,0x82a7eec0
	if (cr6.lt) goto loc_82A7EEC0;
	// rlwinm r10,r15,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r15.u32 | (r15.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82a7dedc
	if (!cr6.eq) goto loc_82A7DEDC;
	// lwz r10,596(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 596);
	// lwz r9,592(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 592);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x82a7dedc
	if (!cr6.lt) goto loc_82A7DEDC;
	// lbz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,-3
	ctx.r10.s64 = ctx.r10.s64 + -3;
	// cmplwi cr6,r10,6
	cr6.compare<uint32_t>(ctx.r10.u32, 6, xer);
	// stw r9,592(r1)
	REX_STORE_U32(ctx.r1.u32 + 592, ctx.r9.u32);
	// bgt cr6,0x82a7dedc
	if (cr6.gt) goto loc_82A7DEDC;
	// lis r12,-32088
	ctx.r12.s64 = -2102919168;
	// addi r12,r12,-11852
	ctx.r12.s64 = ctx.r12.s64 + -11852;
	// rlwinm r0,r10,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r10.u32) {
	case 0:
		goto loc_82A7D1D0;
	case 1:
		goto loc_82A7DEDC;
	case 2:
		goto loc_82A7D57C;
	case 3:
		goto loc_82A7D634;
	case 4:
		goto loc_82A7DEDC;
	case 5:
		goto loc_82A7D7B4;
	case 6:
		goto loc_82A7DB80;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82A7D1D0:
	// subf r10,r15,r7
	ctx.r10.u64 = ctx.r7.u64 - r15.u64;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// blt cr6,0x82a7eec0
	if (cr6.lt) goto loc_82A7EEC0;
	// cmplwi cr6,r24,4
	cr6.compare<uint32_t>(r24.u32, 4, xer);
	// bge cr6,0x82a7d208
	if (!cr6.lt) goto loc_82A7D208;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// subfic r8,r24,4
	xer.ca = r24.u32 <= 4;
	ctx.r8.u64 = static_cast<uint64_t>(4) - r24.u64;
	// addi r5,r24,28
	ctx.r5.s64 = r24.s64 + 28;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// slw r9,r10,r24
	ctx.r9.u64 = r24.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r24.u8 & 0x3F));
	// srw r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// or r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 | r27.u64;
	// clrlwi r9,r9,28
	ctx.r9.u64 = ctx.r9.u32 & 0xF;
	// b 0x82a7d214
	goto loc_82A7D214;
loc_82A7D208:
	// clrlwi r9,r27,28
	ctx.r9.u64 = r27.u32 & 0xF;
	// rlwinm r4,r27,28,4,31
	ctx.r4.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 28) & 0xFFFFFFF;
	// addi r5,r24,-4
	ctx.r5.s64 = r24.s64 + -4;
loc_82A7D214:
	// rlwinm r10,r9,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r9,132(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, xer);
	// lwz r9,192(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// blt cr6,0x82a7d238
	if (cr6.lt) goto loc_82A7D238;
	// lwz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
loc_82A7D238:
	// lwz r10,276(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// cmplw cr6,r17,r10
	cr6.compare<uint32_t>(r17.u32, ctx.r10.u32, xer);
	// blt cr6,0x82a7d24c
	if (cr6.lt) goto loc_82A7D24C;
	// lwz r10,320(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 320);
	// addi r17,r10,4
	r17.s64 = ctx.r10.s64 + 4;
loc_82A7D24C:
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// li r6,64
	ctx.r6.s64 = 64;
loc_82A7D254:
	// lbz r10,0(r17)
	ctx.r10.u64 = REX_LOAD_U8(r17.u32 + 0);
	// addi r17,r17,1
	r17.s64 = r17.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bgt cr6,0x82a7d30c
	if (cr6.gt) goto loc_82A7D30C;
	// subf r6,r10,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r10.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82a7d288
	if (!cr6.eq) goto loc_82A7D288;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,31
	ctx.r5.s64 = 31;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// rlwinm r4,r8,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7d294
	goto loc_82A7D294;
loc_82A7D288:
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// rlwinm r4,r4,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
loc_82A7D294:
	// clrlwi r8,r8,31
	ctx.r8.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82a7d2d4
	if (cr6.eq) goto loc_82A7D2D4;
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// beq cr6,0x82a7d304
	if (cr6.eq) goto loc_82A7D304;
loc_82A7D2B4:
	// lbzx r28,r9,r7
	r28.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r7.u32);
	// addi r27,r1,656
	r27.s64 = ctx.r1.s64 + 656;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stbx r8,r28,r27
	REX_STORE_U8(r28.u32 + r27.u32, ctx.r8.u8);
	// bne cr6,0x82a7d2b4
	if (!cr6.eq) goto loc_82A7D2B4;
	// b 0x82a7d304
	goto loc_82A7D304;
loc_82A7D2D4:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82a7d304
	if (cr6.eq) goto loc_82A7D304;
loc_82A7D2DC:
	// lbz r28,0(r11)
	r28.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r27,r1,656
	r27.s64 = ctx.r1.s64 + 656;
	// lbzx r8,r9,r7
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r7.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// stbx r28,r8,r27
	REX_STORE_U8(ctx.r8.u32 + r27.u32, r28.u8);
	// bne cr6,0x82a7d2dc
	if (!cr6.eq) goto loc_82A7D2DC;
loc_82A7D304:
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// bgt cr6,0x82a7d254
	if (cr6.gt) goto loc_82A7D254;
loc_82A7D30C:
	// stw r17,272(r1)
	REX_STORE_U32(ctx.r1.u32 + 272, r17.u32);
	// cmpwi cr6,r9,63
	cr6.compare<int32_t>(ctx.r9.s32, 63, xer);
	// bne cr6,0x82a7d330
	if (!cr6.eq) goto loc_82A7D330;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r8,r1,656
	ctx.r8.s64 = ctx.r1.s64 + 656;
	// lbz r9,63(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + 63);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// stbx r10,r9,r8
	REX_STORE_U8(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u8);
loc_82A7D330:
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// add r8,r29,r30
	ctx.r8.u64 = r29.u64 + r30.u64;
	// addi r10,r1,660
	ctx.r10.s64 = ctx.r1.s64 + 660;
	// li r6,2
	ctx.r6.s64 = 2;
loc_82A7D340:
	// lhz r7,-4(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + -4);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,-2(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + -2);
	// stw r28,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, r27.u32);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// stw r28,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, r27.u32);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,2(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// stw r28,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, r27.u32);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,4(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// stw r28,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, r28.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r27,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, r27.u32);
	// rlwinm r8,r7,8,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwimi r7,r8,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,6(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// stw r28,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, r27.u32);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,8(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// stw r28,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, r27.u32);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,10(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// stw r28,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, r27.u32);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// stw r7,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r7.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// lhz r7,12(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// stw r28,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, r28.u32);
	// rlwinm r8,r7,8,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// or r28,r8,r7
	r28.u64 = ctx.r8.u64 | ctx.r7.u64;
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,14(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 14);
	// stw r28,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, r27.u32);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,16(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 16);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// stw r28,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, r27.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,18(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 18);
	// stw r28,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, r27.u32);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,20(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 20);
	// stw r28,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, r28.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r27,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, r27.u32);
	// rlwinm r8,r7,8,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwimi r7,r8,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,22(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 22);
	// stw r28,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, r27.u32);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,24(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 24);
	// stw r28,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, r27.u32);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r7,26(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 26);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// stw r28,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, r28.u32);
	// rlwinm r28,r7,8,0,15
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r27,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, r27.u32);
	// or r28,r28,r7
	r28.u64 = r28.u64 | ctx.r7.u64;
	// rlwimi r7,r28,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// stw r7,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r7.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r7,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r7.u32);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// bne cr6,0x82a7d340
	if (!cr6.eq) goto loc_82A7D340;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r24,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, r24.u32);
	// b 0x82a7dedc
	goto loc_82A7DEDC;
loc_82A7D57C:
	// subf r10,r15,r7
	ctx.r10.u64 = ctx.r7.u64 - r15.u64;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// blt cr6,0x82a7eec0
	if (cr6.lt) goto loc_82A7EEC0;
	// cmplw cr6,r16,r28
	cr6.compare<uint32_t>(r16.u32, r28.u32, xer);
	// blt cr6,0x82a7d598
	if (cr6.lt) goto loc_82A7D598;
	// lwz r11,448(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 448);
	// addi r16,r11,4
	r16.s64 = ctx.r11.s64 + 4;
loc_82A7D598:
	// lhz r11,0(r16)
	ctx.r11.u64 = REX_LOAD_U16(r16.u32 + 0);
	// addi r16,r16,2
	r16.s64 = r16.s64 + 2;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,784
	ctx.r3.s64 = ctx.r1.s64 + 784;
	// sth r11,784(r1)
	REX_STORE_U16(ctx.r1.u32 + 784, ctx.r11.u16);
	// stw r16,400(r1)
	REX_STORE_U32(ctx.r1.u32 + 400, r16.u32);
	// bl 0x82a84ff0
	ctx.lr = 0x82A7D5B4;
	sub_82A84FF0(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(ctx.r11.u32, 4, xer);
	// bge cr6,0x82a7d5f8
	if (!cr6.lt) goto loc_82A7D5F8;
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r8,r11,4
	xer.ca = ctx.r11.u32 <= 4;
	ctx.r8.u64 = static_cast<uint64_t>(4) - ctx.r11.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// slw r9,r10,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// clrlwi r6,r11,28
	ctx.r6.u64 = ctx.r11.u32 & 0xF;
	// srw r11,r10,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x82a7d610
	goto loc_82A7D610;
loc_82A7D5F8:
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// clrlwi r6,r10,28
	ctx.r6.u64 = ctx.r10.u32 & 0xF;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_82A7D610:
	// addi r5,r1,784
	ctx.r5.s64 = ctx.r1.s64 + 784;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82a84c50
	ctx.lr = 0x82A7D620;
	sub_82A84C50(ctx, base);
	// lwz r24,88(r1)
	r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r27,80(r1)
	r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// b 0x82a7dedc
	goto loc_82A7DEDC;
loc_82A7D634:
	// subf r10,r15,r7
	ctx.r10.u64 = ctx.r7.u64 - r15.u64;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// blt cr6,0x82a7eec0
	if (cr6.lt) goto loc_82A7EEC0;
	// lwz r10,132(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82a7d658
	if (cr6.lt) goto loc_82A7D658;
	// lwz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
loc_82A7D658:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r9,r29,r30
	ctx.r9.u64 = r29.u64 + r30.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rotlwi r7,r10,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
	// rlwinm r7,r10,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r10,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r10,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r10,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r10,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r10,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r10,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,0(r29)
	REX_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stw r10,4(r29)
	REX_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// stw r10,8(r29)
	REX_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// stw r10,12(r29)
	REX_STORE_U32(r29.u32 + 12, ctx.r10.u32);
	// stw r10,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r10,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// b 0x82a7dedc
	goto loc_82A7DEDC;
loc_82A7D7B4:
	// subf r10,r15,r7
	ctx.r10.u64 = ctx.r7.u64 - r15.u64;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// blt cr6,0x82a7eec0
	if (cr6.lt) goto loc_82A7EEC0;
	// lwz r10,132(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82a7d7d8
	if (cr6.lt) goto loc_82A7D7D8;
	// lwz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
loc_82A7D7D8:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r25,r6
	cr6.compare<uint32_t>(r25.u32, ctx.r6.u32, xer);
	// rotlwi r8,r10,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r8,r10,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rotlwi r7,r9,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// rlwinm r7,r9,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// blt cr6,0x82a7d820
	if (cr6.lt) goto loc_82A7D820;
	// lwz r8,512(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 512);
	// addi r25,r8,4
	r25.s64 = ctx.r8.s64 + 4;
loc_82A7D820:
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// add r7,r29,r30
	ctx.r7.u64 = r29.u64 + r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
loc_82A7D82C:
	// lbz r6,0(r25)
	ctx.r6.u64 = REX_LOAD_U8(r25.u32 + 0);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// addi r23,r31,144
	r23.s64 = r31.s64 + 144;
	// rlwinm r28,r6,2,28,29
	r28.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xC;
	// rlwinm r27,r6,0,28,29
	r27.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xC;
	// addi r22,r31,128
	r22.s64 = r31.s64 + 128;
	// addi r21,r31,144
	r21.s64 = r31.s64 + 144;
	// addi r4,r25,1
	ctx.r4.s64 = r25.s64 + 1;
	// lwzx r3,r28,r3
	ctx.r3.u64 = REX_LOAD_U32(r28.u32 + ctx.r3.u32);
	// rlwinm r26,r6,30,28,29
	r26.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0xC;
	// lwzx r28,r28,r23
	r28.u64 = REX_LOAD_U32(r28.u32 + r23.u32);
	// rlwinm r25,r6,28,4,29
	r25.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFC;
	// addi r19,r31,144
	r19.s64 = r31.s64 + 144;
	// lwzx r23,r27,r22
	r23.u64 = REX_LOAD_U32(r27.u32 + r22.u32);
	// addi r18,r31,128
	r18.s64 = r31.s64 + 128;
	// lwzx r27,r27,r21
	r27.u64 = REX_LOAD_U32(r27.u32 + r21.u32);
	// and r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 & ctx.r9.u64;
	// lbz r6,0(r4)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// and r28,r28,r10
	r28.u64 = r28.u64 & ctx.r10.u64;
	// addi r20,r31,128
	r20.s64 = r31.s64 + 128;
	// or r28,r3,r28
	r28.u64 = ctx.r3.u64 | r28.u64;
	// lwzx r3,r26,r19
	ctx.r3.u64 = REX_LOAD_U32(r26.u32 + r19.u32);
	// and r21,r27,r10
	r21.u64 = r27.u64 & ctx.r10.u64;
	// lwzx r27,r25,r18
	r27.u64 = REX_LOAD_U32(r25.u32 + r18.u32);
	// mr r19,r28
	r19.u64 = r28.u64;
	// mr r18,r28
	r18.u64 = r28.u64;
	// and r23,r23,r9
	r23.u64 = r23.u64 & ctx.r9.u64;
	// lwzx r22,r26,r20
	r22.u64 = REX_LOAD_U32(r26.u32 + r20.u32);
	// addi r17,r31,144
	r17.s64 = r31.s64 + 144;
	// or r28,r23,r21
	r28.u64 = r23.u64 | r21.u64;
	// and r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 & ctx.r10.u64;
	// stw r19,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, r19.u32);
	// and r22,r22,r9
	r22.u64 = r22.u64 & ctx.r9.u64;
	// stw r18,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, r18.u32);
	// mr r19,r28
	r19.u64 = r28.u64;
	// mr r18,r28
	r18.u64 = r28.u64;
	// lwzx r26,r25,r17
	r26.u64 = REX_LOAD_U32(r25.u32 + r17.u32);
	// or r28,r22,r3
	r28.u64 = r22.u64 | ctx.r3.u64;
	// and r25,r27,r9
	r25.u64 = r27.u64 & ctx.r9.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// and r20,r26,r10
	r20.u64 = r26.u64 & ctx.r10.u64;
	// stw r19,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, r19.u32);
	// mr r22,r28
	r22.u64 = r28.u64;
	// stw r18,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, r18.u32);
	// or r28,r25,r20
	r28.u64 = r25.u64 | r20.u64;
	// rlwinm r27,r6,2,28,29
	r27.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xC;
	// stw r3,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r3.u32);
	// addi r16,r31,128
	r16.s64 = r31.s64 + 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r15,r31,144
	r15.s64 = r31.s64 + 144;
	// stw r22,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, r22.u32);
	// mr r25,r28
	r25.u64 = r28.u64;
	// rlwinm r26,r6,0,28,29
	r26.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xC;
	// lwzx r23,r27,r16
	r23.u64 = REX_LOAD_U32(r27.u32 + r16.u32);
	// addi r14,r31,128
	r14.s64 = r31.s64 + 128;
	// stw r3,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r3.u32);
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// lwzx r27,r27,r15
	r27.u64 = REX_LOAD_U32(r27.u32 + r15.u32);
	// and r23,r23,r9
	r23.u64 = r23.u64 & ctx.r9.u64;
	// add r8,r7,r30
	ctx.r8.u64 = ctx.r7.u64 + r30.u64;
	// stw r25,12(r7)
	REX_STORE_U32(ctx.r7.u32 + 12, r25.u32);
	// and r27,r27,r10
	r27.u64 = r27.u64 & ctx.r10.u64;
	// add r7,r8,r30
	ctx.r7.u64 = ctx.r8.u64 + r30.u64;
	// lwzx r21,r26,r14
	r21.u64 = REX_LOAD_U32(r26.u32 + r14.u32);
	// or r28,r23,r27
	r28.u64 = r23.u64 | r27.u64;
	// lwzx r3,r26,r3
	ctx.r3.u64 = REX_LOAD_U32(r26.u32 + ctx.r3.u32);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// and r21,r21,r9
	r21.u64 = r21.u64 & ctx.r9.u64;
	// and r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 & ctx.r10.u64;
	// rlwinm r27,r6,28,4,29
	r27.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFC;
	// stw r28,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, r28.u32);
	// or r26,r21,r3
	r26.u64 = r21.u64 | ctx.r3.u64;
	// stw r28,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, r28.u32);
	// rlwinm r28,r6,30,28,29
	r28.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0xC;
	// lbz r6,0(r4)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// addi r25,r31,128
	r25.s64 = r31.s64 + 128;
	// addi r23,r31,144
	r23.s64 = r31.s64 + 144;
	// addi r22,r31,128
	r22.s64 = r31.s64 + 128;
	// addi r20,r31,144
	r20.s64 = r31.s64 + 144;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// addi r21,r31,144
	r21.s64 = r31.s64 + 144;
	// lwzx r25,r28,r25
	r25.u64 = REX_LOAD_U32(r28.u32 + r25.u32);
	// mr r15,r26
	r15.u64 = r26.u64;
	// lwzx r28,r28,r23
	r28.u64 = REX_LOAD_U32(r28.u32 + r23.u32);
	// mr r14,r26
	r14.u64 = r26.u64;
	// lwzx r22,r27,r22
	r22.u64 = REX_LOAD_U32(r27.u32 + r22.u32);
	// and r25,r25,r9
	r25.u64 = r25.u64 & ctx.r9.u64;
	// and r23,r28,r10
	r23.u64 = r28.u64 & ctx.r10.u64;
	// lwzx r27,r27,r20
	r27.u64 = REX_LOAD_U32(r27.u32 + r20.u32);
	// rlwinm r28,r6,2,28,29
	r28.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xC;
	// and r20,r27,r10
	r20.u64 = r27.u64 & ctx.r10.u64;
	// stw r15,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, r15.u32);
	// or r27,r25,r23
	r27.u64 = r25.u64 | r23.u64;
	// stw r14,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, r14.u32);
	// and r22,r22,r9
	r22.u64 = r22.u64 & ctx.r9.u64;
	// rlwinm r26,r6,0,28,29
	r26.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xC;
	// lwzx r3,r28,r3
	ctx.r3.u64 = REX_LOAD_U32(r28.u32 + ctx.r3.u32);
	// addi r19,r31,128
	r19.s64 = r31.s64 + 128;
	// lwzx r28,r28,r21
	r28.u64 = REX_LOAD_U32(r28.u32 + r21.u32);
	// addi r18,r31,144
	r18.s64 = r31.s64 + 144;
	// stw r27,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, r27.u32);
	// and r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 & ctx.r9.u64;
	// and r23,r28,r10
	r23.u64 = r28.u64 & ctx.r10.u64;
	// stw r27,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, r27.u32);
	// or r28,r22,r20
	r28.u64 = r22.u64 | r20.u64;
	// lwzx r21,r26,r19
	r21.u64 = REX_LOAD_U32(r26.u32 + r19.u32);
	// rlwinm r25,r6,30,28,29
	r25.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0xC;
	// mr r27,r28
	r27.u64 = r28.u64;
	// lwzx r26,r26,r18
	r26.u64 = REX_LOAD_U32(r26.u32 + r18.u32);
	// mr r20,r28
	r20.u64 = r28.u64;
	// or r28,r3,r23
	r28.u64 = ctx.r3.u64 | r23.u64;
	// and r22,r21,r9
	r22.u64 = r21.u64 & ctx.r9.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r27,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, r27.u32);
	// add r8,r7,r30
	ctx.r8.u64 = ctx.r7.u64 + r30.u64;
	// and r26,r26,r10
	r26.u64 = r26.u64 & ctx.r10.u64;
	// stw r20,12(r7)
	REX_STORE_U32(ctx.r7.u32 + 12, r20.u32);
	// mr r27,r28
	r27.u64 = r28.u64;
	// or r28,r22,r26
	r28.u64 = r22.u64 | r26.u64;
	// add r7,r8,r30
	ctx.r7.u64 = ctx.r8.u64 + r30.u64;
	// stw r3,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r17,r31,128
	r17.s64 = r31.s64 + 128;
	// mr r26,r28
	r26.u64 = r28.u64;
	// addi r16,r31,144
	r16.s64 = r31.s64 + 144;
	// stw r27,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, r27.u32);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stw r3,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r3.u32);
	// rlwinm r27,r6,28,4,29
	r27.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFC;
	// lwzx r21,r25,r17
	r21.u64 = REX_LOAD_U32(r25.u32 + r17.u32);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// stw r26,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, r26.u32);
	// addi r26,r31,144
	r26.s64 = r31.s64 + 144;
	// lwzx r25,r25,r16
	r25.u64 = REX_LOAD_U32(r25.u32 + r16.u32);
	// and r21,r21,r9
	r21.u64 = r21.u64 & ctx.r9.u64;
	// lbz r6,0(r4)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// addi r23,r31,128
	r23.s64 = r31.s64 + 128;
	// and r25,r25,r10
	r25.u64 = r25.u64 & ctx.r10.u64;
	// lwzx r3,r27,r3
	ctx.r3.u64 = REX_LOAD_U32(r27.u32 + ctx.r3.u32);
	// addi r22,r31,144
	r22.s64 = r31.s64 + 144;
	// or r28,r21,r25
	r28.u64 = r21.u64 | r25.u64;
	// lwzx r27,r27,r26
	r27.u64 = REX_LOAD_U32(r27.u32 + r26.u32);
	// addi r25,r4,1
	r25.s64 = ctx.r4.s64 + 1;
	// rlwinm r4,r6,2,28,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xC;
	// and r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 & ctx.r9.u64;
	// and r26,r27,r10
	r26.u64 = r27.u64 & ctx.r10.u64;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// stw r28,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, r28.u32);
	// stw r28,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, r28.u32);
	// or r26,r3,r26
	r26.u64 = ctx.r3.u64 | r26.u64;
	// lwzx r3,r4,r23
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + r23.u32);
	// rlwinm r28,r6,0,28,29
	r28.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xC;
	// rlwinm r27,r6,30,28,29
	r27.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0xC;
	// lwzx r4,r4,r22
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + r22.u32);
	// addi r21,r31,128
	r21.s64 = r31.s64 + 128;
	// addi r20,r31,144
	r20.s64 = r31.s64 + 144;
	// addi r19,r31,128
	r19.s64 = r31.s64 + 128;
	// addi r18,r31,144
	r18.s64 = r31.s64 + 144;
	// addi r17,r31,128
	r17.s64 = r31.s64 + 128;
	// addi r16,r31,144
	r16.s64 = r31.s64 + 144;
	// rlwinm r6,r6,28,4,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFC;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lwzx r23,r28,r21
	r23.u64 = REX_LOAD_U32(r28.u32 + r21.u32);
	// and r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 & ctx.r9.u64;
	// and r4,r4,r10
	ctx.r4.u64 = ctx.r4.u64 & ctx.r10.u64;
	// lwzx r28,r28,r20
	r28.u64 = REX_LOAD_U32(r28.u32 + r20.u32);
	// lwzx r21,r6,r17
	r21.u64 = REX_LOAD_U32(ctx.r6.u32 + r17.u32);
	// and r23,r23,r9
	r23.u64 = r23.u64 & ctx.r9.u64;
	// lwzx r22,r27,r19
	r22.u64 = REX_LOAD_U32(r27.u32 + r19.u32);
	// or r4,r3,r4
	ctx.r4.u64 = ctx.r3.u64 | ctx.r4.u64;
	// lwzx r6,r6,r16
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + r16.u32);
	// and r3,r28,r10
	ctx.r3.u64 = r28.u64 & ctx.r10.u64;
	// and r28,r22,r9
	r28.u64 = r22.u64 & ctx.r9.u64;
	// stw r26,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, r26.u32);
	// and r22,r6,r10
	r22.u64 = ctx.r6.u64 & ctx.r10.u64;
	// lwzx r27,r27,r18
	r27.u64 = REX_LOAD_U32(r27.u32 + r18.u32);
	// add r8,r7,r30
	ctx.r8.u64 = ctx.r7.u64 + r30.u64;
	// stw r26,12(r7)
	REX_STORE_U32(ctx.r7.u32 + 12, r26.u32);
	// or r6,r23,r3
	ctx.r6.u64 = r23.u64 | ctx.r3.u64;
	// add r7,r8,r30
	ctx.r7.u64 = ctx.r8.u64 + r30.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// and r27,r27,r10
	r27.u64 = r27.u64 & ctx.r10.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// stw r4,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// or r6,r28,r27
	ctx.r6.u64 = r28.u64 | r27.u64;
	// and r26,r21,r9
	r26.u64 = r21.u64 & ctx.r9.u64;
	// stw r4,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
	// stw r3,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r3.u32);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// or r6,r26,r22
	ctx.r6.u64 = r26.u64 | r22.u64;
	// stw r23,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, r23.u32);
	// stw r4,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r4.u32);
	// stw r3,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, ctx.r3.u32);
	// stw r6,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r6.u32);
	// add r8,r7,r30
	ctx.r8.u64 = ctx.r7.u64 + r30.u64;
	// stw r6,12(r7)
	REX_STORE_U32(ctx.r7.u32 + 12, ctx.r6.u32);
	// add r7,r8,r30
	ctx.r7.u64 = ctx.r8.u64 + r30.u64;
	// bne cr6,0x82a7d82c
	if (!cr6.eq) goto loc_82A7D82C;
	// lwz r16,400(r1)
	r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 400);
	// li r23,0
	r23.s64 = 0;
	// lwz r17,272(r1)
	r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 272);
	// li r18,1
	r18.s64 = 1;
	// lwz r20,336(r1)
	r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 336);
	// lwz r26,208(r1)
	r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 208);
	// lwz r15,104(r1)
	r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r27,80(r1)
	r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r22,112(r1)
	r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r19,96(r1)
	r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r21,116(r1)
	r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stw r25,464(r1)
	REX_STORE_U32(ctx.r1.u32 + 464, r25.u32);
	// b 0x82a7dedc
	goto loc_82A7DEDC;
loc_82A7DB80:
	// subf r10,r15,r7
	ctx.r10.u64 = ctx.r7.u64 - r15.u64;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// blt cr6,0x82a7eec0
	if (cr6.lt) goto loc_82A7EEC0;
	// lwz r7,132(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// add r8,r29,r30
	ctx.r8.u64 = r29.u64 + r30.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// rlwinm r9,r30,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x82a7dbb0
	if (cr6.lt) goto loc_82A7DBB0;
	// lwz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
loc_82A7DBB0:
	// clrlwi r7,r11,30
	ctx.r7.u64 = ctx.r11.u32 & 0x3;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82a7dc98
	if (cr6.eq) goto loc_82A7DC98;
	// subf r4,r29,r8
	ctx.r4.u64 = ctx.r8.u64 - r29.u64;
	// li r7,8
	ctx.r7.s64 = 8;
loc_82A7DBC4:
	// lbz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r8,r4,r10
	ctx.r8.u64 = ctx.r4.u64 + ctx.r10.u64;
	// lbz r5,1(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// rotlwi r28,r6,8
	r28.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// or r28,r28,r6
	r28.u64 = r28.u64 | ctx.r6.u64;
	// lbz r6,2(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r28,r28,8,0,23
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00;
	// or r28,r28,r5
	r28.u64 = r28.u64 | ctx.r5.u64;
	// rlwinm r28,r28,8,0,23
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r28,r5
	ctx.r5.u64 = r28.u64 | ctx.r5.u64;
	// rotlwi r28,r6,8
	r28.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// mr r15,r5
	r15.u64 = ctx.r5.u64;
	// or r28,r28,r6
	r28.u64 = r28.u64 | ctx.r6.u64;
	// lbz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// mr r14,r5
	r14.u64 = ctx.r5.u64;
	// lbz r5,3(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// rlwinm r28,r28,8,0,23
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00;
	// stw r15,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, r15.u32);
	// or r28,r28,r5
	r28.u64 = r28.u64 | ctx.r5.u64;
	// rotlwi r15,r6,8
	r15.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// rlwinm r28,r28,8,0,23
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00;
	// stwx r14,r4,r10
	REX_STORE_U32(ctx.r4.u32 + ctx.r10.u32, r14.u32);
	// or r15,r15,r6
	r15.u64 = r15.u64 | ctx.r6.u64;
	// lbz r6,6(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// or r5,r28,r5
	ctx.r5.u64 = r28.u64 | ctx.r5.u64;
	// rotlwi r28,r6,8
	r28.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// rlwinm r15,r15,8,0,23
	r15.u64 = __builtin_rotateleft64(r15.u32 | (r15.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r28,r6
	ctx.r6.u64 = r28.u64 | ctx.r6.u64;
	// rlwinm r28,r6,8,0,23
	r28.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r6,5(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// stw r5,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// stw r5,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r5.u32);
	// or r5,r15,r6
	ctx.r5.u64 = r15.u64 | ctx.r6.u64;
	// rlwinm r5,r5,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 | ctx.r6.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r15,r6
	r15.u64 = ctx.r6.u64;
	// lbz r6,7(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r5,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
	// or r5,r28,r6
	ctx.r5.u64 = r28.u64 | ctx.r6.u64;
	// stw r15,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, r15.u32);
	// rlwinm r5,r5,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// or r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 | ctx.r6.u64;
	// stw r6,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r6,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r6.u32);
	// bne cr6,0x82a7dbc4
	if (!cr6.eq) goto loc_82A7DBC4;
	// lwz r15,104(r1)
	r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// b 0x82a7dedc
	goto loc_82A7DEDC;
loc_82A7DC98:
	// li r6,2
	ctx.r6.s64 = 2;
loc_82A7DC9C:
	// lhz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,2(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// stw r5,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// stw r5,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,6(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r5,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// stw r5,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r4,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,2(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// stw r5,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// stw r5,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,6(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r5,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// stw r7,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lhz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// stw r5,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r5.u32);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,2(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// stw r5,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// stw r5,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,6(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r5,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// stw r5,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r4,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,2(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// stw r5,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// stw r5,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lhz r7,6(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 6);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r5,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// stw r4,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r4.u32);
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// stw r7,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r7,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r7.u32);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// bne cr6,0x82a7dc9c
	if (!cr6.eq) goto loc_82A7DC9C;
loc_82A7DEDC:
	// rlwinm r8,r22,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r9,1556(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 1556);
	// lwz r7,124(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// add r10,r22,r9
	ctx.r10.u64 = r22.u64 + ctx.r9.u64;
	// addi r19,r19,16
	r19.s64 = r19.s64 + 16;
	// addi r4,r7,-16
	ctx.r4.s64 = ctx.r7.s64 + -16;
	// stbx r18,r8,r21
	REX_STORE_U8(ctx.r8.u32 + r21.u32, r18.u8);
	// rlwinm r8,r10,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// add r22,r10,r9
	r22.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stbx r18,r8,r21
	REX_STORE_U8(ctx.r8.u32 + r21.u32, r18.u8);
	// b 0x82a7eed8
	goto loc_82A7EED8;
loc_82A7DF0C:
	// rlwinm r10,r22,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r26,r9
	cr6.compare<uint32_t>(r26.u32, ctx.r9.u32, xer);
	// stbx r18,r10,r21
	REX_STORE_U8(ctx.r10.u32 + r21.u32, r18.u8);
	// blt cr6,0x82a7df2c
	if (cr6.lt) goto loc_82A7DF2C;
	// lwz r10,256(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 256);
	// addi r26,r10,4
	r26.s64 = ctx.r10.s64 + 4;
	// lwz r10,384(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 384);
	// addi r20,r10,4
	r20.s64 = ctx.r10.s64 + 4;
loc_82A7DF2C:
	// lbz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U8(r26.u32 + 0);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// lbz r9,0(r20)
	ctx.r9.u64 = REX_LOAD_U8(r20.u32 + 0);
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// stw r26,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, r26.u32);
	// stw r20,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, r20.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r8,r10,r19
	ctx.r8.u64 = ctx.r10.u64 + r19.u64;
	// cmplw cr6,r8,r5
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, xer);
	// blt cr6,0x82a7eec0
	if (cr6.lt) goto loc_82A7EEC0;
	// lwz r10,188(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bgt cr6,0x82a7eec0
	if (cr6.gt) goto loc_82A7EEC0;
	// or r7,r8,r29
	ctx.r7.u64 = ctx.r8.u64 | r29.u64;
	// add r10,r29,r30
	ctx.r10.u64 = r29.u64 + r30.u64;
	// clrlwi r6,r7,29
	ctx.r6.u64 = ctx.r7.u32 & 0x7;
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82a7dff0
	if (!cr6.eq) goto loc_82A7DFF0;
	// lfd f0,0(r8)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r8.u32 + 0);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// lfd f13,0(r9)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r9.u32 + 0);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// stfd f13,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.f13.u64);
	// add r10,r8,r30
	ctx.r10.u64 = ctx.r8.u64 + r30.u64;
	// stfd f0,0(r29)
	REX_STORE_U64(r29.u32 + 0, ctx.f0.u64);
	// lfd f0,0(r8)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r8.u32 + 0);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// stfd f0,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.f0.u64);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// lfd f0,0(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// add r10,r8,r30
	ctx.r10.u64 = ctx.r8.u64 + r30.u64;
	// stfd f0,0(r8)
	REX_STORE_U64(ctx.r8.u32 + 0, ctx.f0.u64);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// lfd f0,0(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 0);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// stfd f0,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.f0.u64);
	// add r10,r8,r30
	ctx.r10.u64 = ctx.r8.u64 + r30.u64;
	// lfd f0,0(r8)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r8.u32 + 0);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// stfd f0,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.f0.u64);
	// lfd f0,0(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// stfd f0,0(r8)
	REX_STORE_U64(ctx.r8.u32 + 0, ctx.f0.u64);
	// lfdx f0,r10,r30
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + r30.u32);
	// stfdx f0,r8,r30
	REX_STORE_U64(ctx.r8.u32 + r30.u32, ctx.f0.u64);
	// b 0x82a7eec0
	goto loc_82A7EEC0;
loc_82A7DFF0:
	// clrlwi r7,r7,30
	ctx.r7.u64 = ctx.r7.u32 & 0x3;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// add r7,r10,r30
	ctx.r7.u64 = ctx.r10.u64 + r30.u64;
	// bne cr6,0x82a7e0b0
	if (!cr6.eq) goto loc_82A7E0B0;
	// lwz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r5,4(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// lwz r4,0(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r6,0(r29)
	REX_STORE_U32(r29.u32 + 0, ctx.r6.u32);
	// lwz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r4,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// add r10,r8,r30
	ctx.r10.u64 = ctx.r8.u64 + r30.u64;
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// add r9,r7,r30
	ctx.r9.u64 = ctx.r7.u64 + r30.u64;
	// stw r5,4(r29)
	REX_STORE_U32(r29.u32 + 4, ctx.r5.u32);
	// stw r6,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r8.u32);
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// add r7,r9,r30
	ctx.r7.u64 = ctx.r9.u64 + r30.u64;
	// stw r6,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// lwz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// add r10,r8,r30
	ctx.r10.u64 = ctx.r8.u64 + r30.u64;
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// add r9,r7,r30
	ctx.r9.u64 = ctx.r7.u64 + r30.u64;
	// stw r6,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r8.u32);
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// add r7,r9,r30
	ctx.r7.u64 = ctx.r9.u64 + r30.u64;
	// stw r6,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// lwz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// add r10,r8,r30
	ctx.r10.u64 = ctx.r8.u64 + r30.u64;
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// add r9,r7,r30
	ctx.r9.u64 = ctx.r7.u64 + r30.u64;
	// stw r6,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// stw r8,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r8.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// b 0x82a7eec0
	goto loc_82A7EEC0;
loc_82A7E0B0:
	// lbz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r5,1(r8)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r8.u32 + 1);
	// lbz r4,2(r8)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r8.u32 + 2);
	// lbz r28,3(r8)
	r28.u64 = REX_LOAD_U8(ctx.r8.u32 + 3);
	// lbz r26,4(r8)
	r26.u64 = REX_LOAD_U8(ctx.r8.u32 + 4);
	// lbz r23,5(r8)
	r23.u64 = REX_LOAD_U8(ctx.r8.u32 + 5);
	// lbz r22,6(r8)
	r22.u64 = REX_LOAD_U8(ctx.r8.u32 + 6);
	// lbz r21,7(r8)
	r21.u64 = REX_LOAD_U8(ctx.r8.u32 + 7);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// lbz r20,0(r9)
	r20.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r19,1(r9)
	r19.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r18,2(r9)
	r18.u64 = REX_LOAD_U8(ctx.r9.u32 + 2);
	// lbz r17,3(r9)
	r17.u64 = REX_LOAD_U8(ctx.r9.u32 + 3);
	// lbz r16,4(r9)
	r16.u64 = REX_LOAD_U8(ctx.r9.u32 + 4);
	// lbz r15,5(r9)
	r15.u64 = REX_LOAD_U8(ctx.r9.u32 + 5);
	// lbz r14,6(r9)
	r14.u64 = REX_LOAD_U8(ctx.r9.u32 + 6);
	// lbz r9,7(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 7);
	// stb r6,0(r29)
	REX_STORE_U8(r29.u32 + 0, ctx.r6.u8);
	// stb r5,1(r29)
	REX_STORE_U8(r29.u32 + 1, ctx.r5.u8);
	// stb r4,2(r29)
	REX_STORE_U8(r29.u32 + 2, ctx.r4.u8);
	// stb r28,3(r29)
	REX_STORE_U8(r29.u32 + 3, r28.u8);
	// stb r9,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r9.u8);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stb r26,4(r29)
	REX_STORE_U8(r29.u32 + 4, r26.u8);
	// stb r23,5(r29)
	REX_STORE_U8(r29.u32 + 5, r23.u8);
	// stb r22,6(r29)
	REX_STORE_U8(r29.u32 + 6, r22.u8);
	// lbz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r5,1(r8)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r8.u32 + 1);
	// lbz r4,2(r8)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r8.u32 + 2);
	// lbz r28,3(r8)
	r28.u64 = REX_LOAD_U8(ctx.r8.u32 + 3);
	// lbz r26,4(r8)
	r26.u64 = REX_LOAD_U8(ctx.r8.u32 + 4);
	// lbz r23,5(r8)
	r23.u64 = REX_LOAD_U8(ctx.r8.u32 + 5);
	// lbz r22,6(r8)
	r22.u64 = REX_LOAD_U8(ctx.r8.u32 + 6);
	// lbz r8,7(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 7);
	// stb r20,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, r20.u8);
	// stb r19,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, r19.u8);
	// stb r18,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, r18.u8);
	// stb r17,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, r17.u8);
	// stb r16,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, r16.u8);
	// stb r15,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, r15.u8);
	// stb r14,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, r14.u8);
	// add r10,r7,r30
	ctx.r10.u64 = ctx.r7.u64 + r30.u64;
	// stb r6,0(r7)
	REX_STORE_U8(ctx.r7.u32 + 0, ctx.r6.u8);
	// lbz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// stb r5,1(r7)
	REX_STORE_U8(ctx.r7.u32 + 1, ctx.r5.u8);
	// stb r4,2(r7)
	REX_STORE_U8(ctx.r7.u32 + 2, ctx.r4.u8);
	// stb r28,3(r7)
	REX_STORE_U8(ctx.r7.u32 + 3, r28.u8);
	// stb r26,4(r7)
	REX_STORE_U8(ctx.r7.u32 + 4, r26.u8);
	// stb r23,5(r7)
	REX_STORE_U8(ctx.r7.u32 + 5, r23.u8);
	// stb r22,6(r7)
	REX_STORE_U8(ctx.r7.u32 + 6, r22.u8);
	// stb r8,7(r7)
	REX_STORE_U8(ctx.r7.u32 + 7, ctx.r8.u8);
	// add r7,r9,r30
	ctx.r7.u64 = ctx.r9.u64 + r30.u64;
	// lbz r5,1(r9)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// lbz r4,2(r9)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + 2);
	// lbz r28,3(r9)
	r28.u64 = REX_LOAD_U8(ctx.r9.u32 + 3);
	// lbz r26,4(r9)
	r26.u64 = REX_LOAD_U8(ctx.r9.u32 + 4);
	// lbz r23,5(r9)
	r23.u64 = REX_LOAD_U8(ctx.r9.u32 + 5);
	// lbz r22,6(r9)
	r22.u64 = REX_LOAD_U8(ctx.r9.u32 + 6);
	// stb r6,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r6.u8);
	// lbz r9,7(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 7);
	// lbz r6,0(r7)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// stb r5,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r5.u8);
	// stb r4,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r4.u8);
	// stb r28,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, r28.u8);
	// lbz r5,1(r7)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// lbz r4,2(r7)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r7.u32 + 2);
	// lbz r28,3(r7)
	r28.u64 = REX_LOAD_U8(ctx.r7.u32 + 3);
	// stb r26,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, r26.u8);
	// stb r9,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r9.u8);
	// add r9,r7,r30
	ctx.r9.u64 = ctx.r7.u64 + r30.u64;
	// stb r23,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, r23.u8);
	// stb r22,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, r22.u8);
	// add r10,r8,r30
	ctx.r10.u64 = ctx.r8.u64 + r30.u64;
	// stb r6,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r6.u8);
	// lbz r26,4(r7)
	r26.u64 = REX_LOAD_U8(ctx.r7.u32 + 4);
	// lbz r6,5(r7)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r7.u32 + 5);
	// stb r21,7(r29)
	REX_STORE_U8(r29.u32 + 7, r21.u8);
	// stb r5,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r5.u8);
	// stb r4,2(r8)
	REX_STORE_U8(ctx.r8.u32 + 2, ctx.r4.u8);
	// stb r28,3(r8)
	REX_STORE_U8(ctx.r8.u32 + 3, r28.u8);
	// lbz r5,6(r7)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r7.u32 + 6);
	// li r18,1
	r18.s64 = 1;
	// lbz r4,7(r7)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r7.u32 + 7);
	// add r7,r9,r30
	ctx.r7.u64 = ctx.r9.u64 + r30.u64;
	// stb r26,4(r8)
	REX_STORE_U8(ctx.r8.u32 + 4, r26.u8);
	// stb r6,5(r8)
	REX_STORE_U8(ctx.r8.u32 + 5, ctx.r6.u8);
	// lbz r28,0(r9)
	r28.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// stb r5,6(r8)
	REX_STORE_U8(ctx.r8.u32 + 6, ctx.r5.u8);
	// stb r4,7(r8)
	REX_STORE_U8(ctx.r8.u32 + 7, ctx.r4.u8);
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// lbz r6,1(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r5,2(r9)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r9.u32 + 2);
	// lbz r4,3(r9)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r9.u32 + 3);
	// lbz r26,4(r9)
	r26.u64 = REX_LOAD_U8(ctx.r9.u32 + 4);
	// lbz r23,5(r9)
	r23.u64 = REX_LOAD_U8(ctx.r9.u32 + 5);
	// lbz r22,6(r9)
	r22.u64 = REX_LOAD_U8(ctx.r9.u32 + 6);
	// lbz r9,7(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 7);
	// stb r28,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, r28.u8);
	// stb r26,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, r26.u8);
	// stb r6,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r6.u8);
	// stb r5,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// stb r4,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, ctx.r4.u8);
	// stb r23,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, r23.u8);
	// stb r22,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, r22.u8);
	// stb r9,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r9.u8);
	// add r10,r7,r30
	ctx.r10.u64 = ctx.r7.u64 + r30.u64;
	// lbz r6,0(r7)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// lbz r5,1(r7)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// lbz r4,2(r7)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r7.u32 + 2);
	// lbz r28,3(r7)
	r28.u64 = REX_LOAD_U8(ctx.r7.u32 + 3);
	// lbz r26,4(r7)
	r26.u64 = REX_LOAD_U8(ctx.r7.u32 + 4);
	// lbz r23,5(r7)
	r23.u64 = REX_LOAD_U8(ctx.r7.u32 + 5);
	// lbz r22,6(r7)
	r22.u64 = REX_LOAD_U8(ctx.r7.u32 + 6);
	// lbz r7,7(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 7);
	// stb r6,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r6.u8);
	// stb r26,4(r8)
	REX_STORE_U8(ctx.r8.u32 + 4, r26.u8);
	// stb r5,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r5.u8);
	// stb r4,2(r8)
	REX_STORE_U8(ctx.r8.u32 + 2, ctx.r4.u8);
	// stb r28,3(r8)
	REX_STORE_U8(ctx.r8.u32 + 3, r28.u8);
	// stb r23,5(r8)
	REX_STORE_U8(ctx.r8.u32 + 5, r23.u8);
	// li r23,0
	r23.s64 = 0;
	// stb r22,6(r8)
	REX_STORE_U8(ctx.r8.u32 + 6, r22.u8);
	// stb r7,7(r8)
	REX_STORE_U8(ctx.r8.u32 + 7, ctx.r7.u8);
	// lbz r26,6(r10)
	r26.u64 = REX_LOAD_U8(ctx.r10.u32 + 6);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r7,1(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r6,2(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// lbz r5,3(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// lbz r4,4(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 4);
	// lbz r28,5(r10)
	r28.u64 = REX_LOAD_U8(ctx.r10.u32 + 5);
	// lbz r10,7(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 7);
	// stb r26,6(r9)
	REX_STORE_U8(ctx.r9.u32 + 6, r26.u8);
	// lwz r21,116(r1)
	r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r19,96(r1)
	r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r22,112(r1)
	r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r15,104(r1)
	r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r26,208(r1)
	r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 208);
	// lwz r20,336(r1)
	r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 336);
	// lwz r17,272(r1)
	r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 272);
	// lwz r16,400(r1)
	r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 400);
	// stb r8,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// stb r7,1(r9)
	REX_STORE_U8(ctx.r9.u32 + 1, ctx.r7.u8);
	// stb r6,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, ctx.r6.u8);
	// stb r5,3(r9)
	REX_STORE_U8(ctx.r9.u32 + 3, ctx.r5.u8);
	// stb r4,4(r9)
	REX_STORE_U8(ctx.r9.u32 + 4, ctx.r4.u8);
	// stb r28,5(r9)
	REX_STORE_U8(ctx.r9.u32 + 5, r28.u8);
	// stb r10,7(r9)
	REX_STORE_U8(ctx.r9.u32 + 7, ctx.r10.u8);
	// b 0x82a7eec0
	goto loc_82A7EEC0;
loc_82A7E308:
	// cmplwi cr6,r24,4
	cr6.compare<uint32_t>(r24.u32, 4, xer);
	// bge cr6,0x82a7e334
	if (!cr6.lt) goto loc_82A7E334;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// subfic r8,r24,4
	xer.ca = r24.u32 <= 4;
	ctx.r8.u64 = static_cast<uint64_t>(4) - r24.u64;
	// addi r6,r24,28
	ctx.r6.s64 = r24.s64 + 28;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// slw r9,r10,r24
	ctx.r9.u64 = r24.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r24.u8 & 0x3F));
	// srw r5,r10,r8
	ctx.r5.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// or r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 | r27.u64;
	// clrlwi r9,r9,28
	ctx.r9.u64 = ctx.r9.u32 & 0xF;
	// b 0x82a7e340
	goto loc_82A7E340;
loc_82A7E334:
	// clrlwi r9,r27,28
	ctx.r9.u64 = r27.u32 & 0xF;
	// rlwinm r5,r27,28,4,31
	ctx.r5.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 28) & 0xFFFFFFF;
	// addi r6,r24,-4
	ctx.r6.s64 = r24.s64 + -4;
loc_82A7E340:
	// rlwinm r10,r9,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r9,132(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, xer);
	// lwz r9,192(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// blt cr6,0x82a7e364
	if (cr6.lt) goto loc_82A7E364;
	// lwz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
loc_82A7E364:
	// lwz r10,276(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// cmplw cr6,r17,r10
	cr6.compare<uint32_t>(r17.u32, ctx.r10.u32, xer);
	// blt cr6,0x82a7e378
	if (cr6.lt) goto loc_82A7E378;
	// lwz r10,320(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 320);
	// addi r17,r10,4
	r17.s64 = ctx.r10.s64 + 4;
loc_82A7E378:
	// rlwinm r10,r22,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// stbx r18,r10,r21
	REX_STORE_U8(ctx.r10.u32 + r21.u32, r18.u8);
loc_82A7E388:
	// lbz r10,0(r17)
	ctx.r10.u64 = REX_LOAD_U8(r17.u32 + 0);
	// addi r17,r17,1
	r17.s64 = r17.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r10,r4
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, xer);
	// bgt cr6,0x82a7e440
	if (cr6.gt) goto loc_82A7E440;
	// subf r4,r10,r4
	ctx.r4.u64 = ctx.r4.u64 - ctx.r10.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82a7e3bc
	if (!cr6.eq) goto loc_82A7E3BC;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,31
	ctx.r6.s64 = 31;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// rlwinm r5,r8,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a7e3c8
	goto loc_82A7E3C8;
loc_82A7E3BC:
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// rlwinm r5,r5,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
loc_82A7E3C8:
	// clrlwi r8,r8,31
	ctx.r8.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82a7e408
	if (cr6.eq) goto loc_82A7E408;
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// beq cr6,0x82a7e438
	if (cr6.eq) goto loc_82A7E438;
loc_82A7E3E8:
	// lbzx r28,r9,r7
	r28.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r7.u32);
	// addi r27,r1,656
	r27.s64 = ctx.r1.s64 + 656;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stbx r8,r28,r27
	REX_STORE_U8(r28.u32 + r27.u32, ctx.r8.u8);
	// bne cr6,0x82a7e3e8
	if (!cr6.eq) goto loc_82A7E3E8;
	// b 0x82a7e438
	goto loc_82A7E438;
loc_82A7E408:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82a7e438
	if (cr6.eq) goto loc_82A7E438;
loc_82A7E410:
	// lbz r28,0(r11)
	r28.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r27,r1,656
	r27.s64 = ctx.r1.s64 + 656;
	// lbzx r8,r9,r7
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r7.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// stbx r28,r8,r27
	REX_STORE_U8(ctx.r8.u32 + r27.u32, r28.u8);
	// bne cr6,0x82a7e410
	if (!cr6.eq) goto loc_82A7E410;
loc_82A7E438:
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// bgt cr6,0x82a7e388
	if (cr6.gt) goto loc_82A7E388;
loc_82A7E440:
	// stw r17,272(r1)
	REX_STORE_U32(ctx.r1.u32 + 272, r17.u32);
	// cmpwi cr6,r9,63
	cr6.compare<int32_t>(ctx.r9.s32, 63, xer);
	// bne cr6,0x82a7e464
	if (!cr6.eq) goto loc_82A7E464;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r8,r1,656
	ctx.r8.s64 = ctx.r1.s64 + 656;
	// lbz r9,63(r7)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r7.u32 + 63);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// stbx r10,r9,r8
	REX_STORE_U8(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u8);
loc_82A7E464:
	// add r10,r29,r30
	ctx.r10.u64 = r29.u64 + r30.u64;
	// lfd f0,664(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 664);
	// lfd f13,672(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 672);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// lfd f12,680(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 680);
	// lfd f11,688(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 688);
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// lfd f9,656(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 656);
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// stfd f0,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.f0.u64);
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// lfd f10,696(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 696);
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stfd f13,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.f13.u64);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// stfd f9,0(r29)
	REX_STORE_U64(r29.u32 + 0, ctx.f9.u64);
	// stw r24,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, r24.u32);
	// lfd f9,704(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 704);
	// stfd f12,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.f12.u64);
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// lfd f8,712(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 712);
	// stfd f11,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.f11.u64);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// stfd f10,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.f10.u64);
	// stfd f9,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.f9.u64);
	// stfdx f8,r9,r30
	REX_STORE_U64(ctx.r9.u32 + r30.u32, ctx.f8.u64);
	// b 0x82a7eec0
	goto loc_82A7EEC0;
loc_82A7E4D4:
	// rlwinm r10,r22,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r26,r9
	cr6.compare<uint32_t>(r26.u32, ctx.r9.u32, xer);
	// stbx r18,r10,r21
	REX_STORE_U8(ctx.r10.u32 + r21.u32, r18.u8);
	// blt cr6,0x82a7e4f4
	if (cr6.lt) goto loc_82A7E4F4;
	// lwz r10,256(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 256);
	// addi r26,r10,4
	r26.s64 = ctx.r10.s64 + 4;
	// lwz r10,384(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 384);
	// addi r20,r10,4
	r20.s64 = ctx.r10.s64 + 4;
loc_82A7E4F4:
	// lbz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U8(r26.u32 + 0);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// lbz r9,0(r20)
	ctx.r9.u64 = REX_LOAD_U8(r20.u32 + 0);
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// stw r26,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, r26.u32);
	// stw r20,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, r20.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r7,r10,r19
	ctx.r7.u64 = ctx.r10.u64 + r19.u64;
	// cmplw cr6,r7,r5
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r5.u32, xer);
	// blt cr6,0x82a7eec0
	if (cr6.lt) goto loc_82A7EEC0;
	// lwz r10,188(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// cmplw cr6,r7,r10
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, xer);
	// bgt cr6,0x82a7eec0
	if (cr6.gt) goto loc_82A7EEC0;
	// cmplwi cr6,r24,7
	cr6.compare<uint32_t>(r24.u32, 7, xer);
	// bge cr6,0x82a7e56c
	if (!cr6.lt) goto loc_82A7E56C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// subfic r10,r24,7
	xer.ca = r24.u32 <= 7;
	ctx.r10.u64 = static_cast<uint64_t>(7) - r24.u64;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// addi r8,r24,25
	ctx.r8.s64 = r24.s64 + 25;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// slw r9,r11,r24
	ctx.r9.u64 = r24.u8 & 0x20 ? 0 : (ctx.r11.u32 << (r24.u8 & 0x3F));
	// srw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// or r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 | r27.u64;
	// clrlwi r6,r9,25
	ctx.r6.u64 = ctx.r9.u32 & 0x7F;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x82a7e580
	goto loc_82A7E580;
loc_82A7E56C:
	// rlwinm r11,r27,25,7,31
	ctx.r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 25) & 0x1FFFFFF;
	// clrlwi r6,r27,25
	ctx.r6.u64 = r27.u32 & 0x7F;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r11,r24,-7
	ctx.r11.s64 = r24.s64 + -7;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
loc_82A7E580:
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82a85ec8
	ctx.lr = 0x82A7E594;
	sub_82A85EC8(ctx, base);
	// lwz r24,88(r1)
	r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r27,80(r1)
	r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// b 0x82a7eec0
	goto loc_82A7EEC0;
loc_82A7E5A8:
	// rlwinm r11,r22,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r16,r28
	cr6.compare<uint32_t>(r16.u32, r28.u32, xer);
	// stbx r18,r11,r21
	REX_STORE_U8(ctx.r11.u32 + r21.u32, r18.u8);
	// blt cr6,0x82a7e5c0
	if (cr6.lt) goto loc_82A7E5C0;
	// lwz r11,448(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 448);
	// addi r16,r11,4
	r16.s64 = ctx.r11.s64 + 4;
loc_82A7E5C0:
	// lhz r11,0(r16)
	ctx.r11.u64 = REX_LOAD_U16(r16.u32 + 0);
	// addi r16,r16,2
	r16.s64 = r16.s64 + 2;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,784
	ctx.r3.s64 = ctx.r1.s64 + 784;
	// sth r11,784(r1)
	REX_STORE_U16(ctx.r1.u32 + 784, ctx.r11.u16);
	// stw r16,400(r1)
	REX_STORE_U32(ctx.r1.u32 + 400, r16.u32);
	// bl 0x82a84ff0
	ctx.lr = 0x82A7E5DC;
	sub_82A84FF0(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(ctx.r11.u32, 4, xer);
	// bge cr6,0x82a7e620
	if (!cr6.lt) goto loc_82A7E620;
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r8,r11,4
	xer.ca = ctx.r11.u32 <= 4;
	ctx.r8.u64 = static_cast<uint64_t>(4) - ctx.r11.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// slw r9,r10,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// clrlwi r6,r11,28
	ctx.r6.u64 = ctx.r11.u32 & 0xF;
	// srw r11,r10,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x82a7e638
	goto loc_82A7E638;
loc_82A7E620:
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// clrlwi r6,r10,28
	ctx.r6.u64 = ctx.r10.u32 & 0xF;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_82A7E638:
	// addi r5,r1,784
	ctx.r5.s64 = ctx.r1.s64 + 784;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82a84c38
	ctx.lr = 0x82A7E648;
	sub_82A84C38(ctx, base);
	// lwz r24,88(r1)
	r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r27,80(r1)
	r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// b 0x82a7eec0
	goto loc_82A7EEC0;
loc_82A7E65C:
	// lwz r10,132(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82a7e674
	if (cr6.lt) goto loc_82A7E674;
	// lwz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
loc_82A7E674:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r8,r22,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 31) & 0x7FFFFFFF;
	// add r9,r29,r30
	ctx.r9.u64 = r29.u64 + r30.u64;
	// rotlwi r7,r10,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
	// stbx r18,r8,r21
	REX_STORE_U8(ctx.r8.u32 + r21.u32, r18.u8);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// rlwinm r7,r10,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// stw r10,0(r29)
	REX_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stw r10,4(r29)
	REX_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// add r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 + r30.u64;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r10,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// b 0x82a7eebc
	goto loc_82A7EEBC;
loc_82A7E6F4:
	// rlwinm r10,r22,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r26,r9
	cr6.compare<uint32_t>(r26.u32, ctx.r9.u32, xer);
	// stbx r18,r10,r21
	REX_STORE_U8(ctx.r10.u32 + r21.u32, r18.u8);
	// blt cr6,0x82a7e714
	if (cr6.lt) goto loc_82A7E714;
	// lwz r10,256(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 256);
	// addi r26,r10,4
	r26.s64 = ctx.r10.s64 + 4;
	// lwz r10,384(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 384);
	// addi r20,r10,4
	r20.s64 = ctx.r10.s64 + 4;
loc_82A7E714:
	// lbz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U8(r26.u32 + 0);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// lbz r9,0(r20)
	ctx.r9.u64 = REX_LOAD_U8(r20.u32 + 0);
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// stw r26,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, r26.u32);
	// stw r20,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, r20.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r28,r10,r19
	r28.u64 = ctx.r10.u64 + r19.u64;
	// lwz r10,1484(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 1484);
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// blt cr6,0x82a7eec0
	if (cr6.lt) goto loc_82A7EEC0;
	// lwz r10,188(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// bgt cr6,0x82a7eec0
	if (cr6.gt) goto loc_82A7EEC0;
	// lwz r10,724(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 724);
	// lwz r11,720(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 720);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82a7e770
	if (cr6.lt) goto loc_82A7E770;
	// lwz r11,768(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 768);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_82A7E770:
	// lhz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,784
	ctx.r3.s64 = ctx.r1.s64 + 784;
	// sth r10,784(r1)
	REX_STORE_U16(ctx.r1.u32 + 784, ctx.r10.u16);
	// stw r11,720(r1)
	REX_STORE_U32(ctx.r1.u32 + 720, ctx.r11.u32);
	// bl 0x82a84ff0
	ctx.lr = 0x82A7E78C;
	sub_82A84FF0(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(ctx.r11.u32, 4, xer);
	// bge cr6,0x82a7e7d0
	if (!cr6.lt) goto loc_82A7E7D0;
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r8,r11,4
	xer.ca = ctx.r11.u32 <= 4;
	ctx.r8.u64 = static_cast<uint64_t>(4) - ctx.r11.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// slw r9,r10,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// clrlwi r6,r11,28
	ctx.r6.u64 = ctx.r11.u32 & 0xF;
	// srw r11,r10,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x82a7e7e8
	goto loc_82A7E7E8;
loc_82A7E7D0:
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// clrlwi r6,r10,28
	ctx.r6.u64 = ctx.r10.u32 & 0xF;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_82A7E7E8:
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// addi r5,r1,784
	ctx.r5.s64 = ctx.r1.s64 + 784;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82a84c68
	ctx.lr = 0x82A7E800;
	sub_82A84C68(ctx, base);
	// lwz r24,88(r1)
	r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r27,80(r1)
	r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// b 0x82a7eec0
	goto loc_82A7EEC0;
loc_82A7E814:
	// lwz r10,132(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82a7e82c
	if (cr6.lt) goto loc_82A7E82C;
	// lwz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
loc_82A7E82C:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r8,r22,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r25,r6
	cr6.compare<uint32_t>(r25.u32, ctx.r6.u32, xer);
	// add r7,r29,r30
	ctx.r7.u64 = r29.u64 + r30.u64;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stbx r18,r8,r21
	REX_STORE_U8(ctx.r8.u32 + r21.u32, r18.u8);
	// rotlwi r8,r10,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// rotlwi r6,r9,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
	// or r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 | ctx.r9.u64;
	// rlwinm r8,r10,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// rlwinm r6,r9,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
	// or r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 | ctx.r9.u64;
	// blt cr6,0x82a7e880
	if (cr6.lt) goto loc_82A7E880;
	// lwz r8,512(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 512);
	// addi r25,r8,4
	r25.s64 = ctx.r8.s64 + 4;
loc_82A7E880:
	// lbz r6,0(r25)
	ctx.r6.u64 = REX_LOAD_U8(r25.u32 + 0);
	// addi r28,r31,64
	r28.s64 = r31.s64 + 64;
	// addi r26,r31,64
	r26.s64 = r31.s64 + 64;
	// lbz r4,1(r25)
	ctx.r4.u64 = REX_LOAD_U8(r25.u32 + 1);
	// rlwinm r5,r6,2,26,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3C;
	// rlwinm r6,r6,30,2,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFC;
	// addi r20,r31,64
	r20.s64 = r31.s64 + 64;
	// addi r19,r31,64
	r19.s64 = r31.s64 + 64;
	// addi r18,r31,64
	r18.s64 = r31.s64 + 64;
	// lwzx r28,r5,r28
	r28.u64 = REX_LOAD_U32(ctx.r5.u32 + r28.u32);
	// addi r17,r31,64
	r17.s64 = r31.s64 + 64;
	// lwzx r26,r6,r26
	r26.u64 = REX_LOAD_U32(ctx.r6.u32 + r26.u32);
	// add r8,r7,r30
	ctx.r8.u64 = ctx.r7.u64 + r30.u64;
	// lwzx r15,r5,r31
	r15.u64 = REX_LOAD_U32(ctx.r5.u32 + r31.u32);
	// and r28,r28,r10
	r28.u64 = r28.u64 & ctx.r10.u64;
	// lwzx r14,r6,r31
	r14.u64 = REX_LOAD_U32(ctx.r6.u32 + r31.u32);
	// and r26,r26,r10
	r26.u64 = r26.u64 & ctx.r10.u64;
	// and r15,r15,r9
	r15.u64 = r15.u64 & ctx.r9.u64;
	// and r14,r14,r9
	r14.u64 = r14.u64 & ctx.r9.u64;
	// or r28,r15,r28
	r28.u64 = r15.u64 | r28.u64;
	// or r26,r14,r26
	r26.u64 = r14.u64 | r26.u64;
	// rlwinm r5,r4,2,26,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3C;
	// rlwinm r6,r4,30,2,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFC;
	// lbz r4,2(r25)
	ctx.r4.u64 = REX_LOAD_U8(r25.u32 + 2);
	// addi r16,r31,64
	r16.s64 = r31.s64 + 64;
	// stw r28,0(r29)
	REX_STORE_U32(r29.u32 + 0, r28.u32);
	// stw r26,4(r29)
	REX_STORE_U32(r29.u32 + 4, r26.u32);
	// lwzx r26,r5,r20
	r26.u64 = REX_LOAD_U32(ctx.r5.u32 + r20.u32);
	// lwzx r28,r5,r31
	r28.u64 = REX_LOAD_U32(ctx.r5.u32 + r31.u32);
	// rlwinm r5,r4,30,2,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFC;
	// lwzx r19,r6,r19
	r19.u64 = REX_LOAD_U32(ctx.r6.u32 + r19.u32);
	// and r26,r26,r10
	r26.u64 = r26.u64 & ctx.r10.u64;
	// lwzx r20,r6,r31
	r20.u64 = REX_LOAD_U32(ctx.r6.u32 + r31.u32);
	// and r28,r28,r9
	r28.u64 = r28.u64 & ctx.r9.u64;
	// and r19,r19,r10
	r19.u64 = r19.u64 & ctx.r10.u64;
	// and r20,r20,r9
	r20.u64 = r20.u64 & ctx.r9.u64;
	// or r28,r28,r26
	r28.u64 = r28.u64 | r26.u64;
	// or r26,r20,r19
	r26.u64 = r20.u64 | r19.u64;
	// lwzx r20,r5,r31
	r20.u64 = REX_LOAD_U32(ctx.r5.u32 + r31.u32);
	// rlwinm r6,r4,2,26,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3C;
	// lwzx r5,r5,r17
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + r17.u32);
	// and r20,r20,r9
	r20.u64 = r20.u64 & ctx.r9.u64;
	// lbz r4,3(r25)
	ctx.r4.u64 = REX_LOAD_U8(r25.u32 + 3);
	// and r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 & ctx.r10.u64;
	// stw r28,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, r28.u32);
	// addi r19,r31,64
	r19.s64 = r31.s64 + 64;
	// stw r26,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, r26.u32);
	// or r5,r20,r5
	ctx.r5.u64 = r20.u64 | ctx.r5.u64;
	// lwzx r26,r6,r18
	r26.u64 = REX_LOAD_U32(ctx.r6.u32 + r18.u32);
	// addi r20,r31,64
	r20.s64 = r31.s64 + 64;
	// lwzx r28,r6,r31
	r28.u64 = REX_LOAD_U32(ctx.r6.u32 + r31.u32);
	// rlwinm r6,r4,2,26,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3C;
	// and r26,r26,r10
	r26.u64 = r26.u64 & ctx.r10.u64;
	// and r28,r28,r9
	r28.u64 = r28.u64 & ctx.r9.u64;
	// stw r5,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r5.u32);
	// add r7,r8,r30
	ctx.r7.u64 = ctx.r8.u64 + r30.u64;
	// or r28,r28,r26
	r28.u64 = r28.u64 | r26.u64;
	// lwzx r5,r6,r31
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + r31.u32);
	// addi r18,r31,64
	r18.s64 = r31.s64 + 64;
	// addi r17,r31,64
	r17.s64 = r31.s64 + 64;
	// and r26,r5,r9
	r26.u64 = ctx.r5.u64 & ctx.r9.u64;
	// lbz r5,4(r25)
	ctx.r5.u64 = REX_LOAD_U8(r25.u32 + 4);
	// stw r28,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, r28.u32);
	// add r8,r7,r30
	ctx.r8.u64 = ctx.r7.u64 + r30.u64;
	// lwzx r28,r6,r16
	r28.u64 = REX_LOAD_U32(ctx.r6.u32 + r16.u32);
	// rlwinm r6,r4,30,2,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFC;
	// addi r16,r31,64
	r16.s64 = r31.s64 + 64;
	// and r4,r28,r10
	ctx.r4.u64 = r28.u64 & ctx.r10.u64;
	// addi r28,r31,64
	r28.s64 = r31.s64 + 64;
	// or r4,r26,r4
	ctx.r4.u64 = r26.u64 | ctx.r4.u64;
	// lwzx r20,r6,r20
	r20.u64 = REX_LOAD_U32(ctx.r6.u32 + r20.u32);
	// addi r26,r31,64
	r26.s64 = r31.s64 + 64;
	// lwzx r15,r6,r31
	r15.u64 = REX_LOAD_U32(ctx.r6.u32 + r31.u32);
	// rlwinm r6,r5,30,2,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFC;
	// and r20,r20,r10
	r20.u64 = r20.u64 & ctx.r10.u64;
	// and r15,r15,r9
	r15.u64 = r15.u64 & ctx.r9.u64;
	// stw r4,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
	// rlwinm r4,r5,2,26,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3C;
	// or r20,r15,r20
	r20.u64 = r15.u64 | r20.u64;
	// lbz r5,5(r25)
	ctx.r5.u64 = REX_LOAD_U8(r25.u32 + 5);
	// stw r20,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, r20.u32);
	// lwzx r19,r4,r19
	r19.u64 = REX_LOAD_U32(ctx.r4.u32 + r19.u32);
	// add r7,r8,r30
	ctx.r7.u64 = ctx.r8.u64 + r30.u64;
	// lwzx r20,r4,r31
	r20.u64 = REX_LOAD_U32(ctx.r4.u32 + r31.u32);
	// rlwinm r4,r5,2,26,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3C;
	// lwzx r18,r6,r18
	r18.u64 = REX_LOAD_U32(ctx.r6.u32 + r18.u32);
	// and r19,r19,r10
	r19.u64 = r19.u64 & ctx.r10.u64;
	// lwzx r15,r6,r31
	r15.u64 = REX_LOAD_U32(ctx.r6.u32 + r31.u32);
	// and r20,r20,r9
	r20.u64 = r20.u64 & ctx.r9.u64;
	// and r18,r18,r10
	r18.u64 = r18.u64 & ctx.r10.u64;
	// and r15,r15,r9
	r15.u64 = r15.u64 & ctx.r9.u64;
	// or r20,r20,r19
	r20.u64 = r20.u64 | r19.u64;
	// lwzx r28,r4,r28
	r28.u64 = REX_LOAD_U32(ctx.r4.u32 + r28.u32);
	// or r19,r15,r18
	r19.u64 = r15.u64 | r18.u64;
	// lwz r15,104(r1)
	r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r6,r5,30,2,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFC;
	// lbz r5,6(r25)
	ctx.r5.u64 = REX_LOAD_U8(r25.u32 + 6);
	// and r28,r28,r10
	r28.u64 = r28.u64 & ctx.r10.u64;
	// li r18,1
	r18.s64 = 1;
	// stw r20,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, r20.u32);
	// lwzx r20,r4,r31
	r20.u64 = REX_LOAD_U32(ctx.r4.u32 + r31.u32);
	// rlwinm r4,r5,2,26,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3C;
	// stw r19,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, r19.u32);
	// add r8,r7,r30
	ctx.r8.u64 = ctx.r7.u64 + r30.u64;
	// lwzx r26,r6,r26
	r26.u64 = REX_LOAD_U32(ctx.r6.u32 + r26.u32);
	// lwzx r19,r6,r31
	r19.u64 = REX_LOAD_U32(ctx.r6.u32 + r31.u32);
	// rlwinm r6,r5,30,2,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFC;
	// and r5,r20,r9
	ctx.r5.u64 = r20.u64 & ctx.r9.u64;
	// and r26,r26,r10
	r26.u64 = r26.u64 & ctx.r10.u64;
	// or r5,r5,r28
	ctx.r5.u64 = ctx.r5.u64 | r28.u64;
	// and r20,r19,r9
	r20.u64 = r19.u64 & ctx.r9.u64;
	// lwz r19,96(r1)
	r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// or r28,r20,r26
	r28.u64 = r20.u64 | r26.u64;
	// lwz r20,336(r1)
	r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 336);
	// addi r26,r31,64
	r26.s64 = r31.s64 + 64;
	// stw r5,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// lwzx r5,r4,r31
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + r31.u32);
	// lwzx r4,r4,r17
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + r17.u32);
	// stw r28,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, r28.u32);
	// and r5,r5,r9
	ctx.r5.u64 = ctx.r5.u64 & ctx.r9.u64;
	// lwzx r28,r6,r31
	r28.u64 = REX_LOAD_U32(ctx.r6.u32 + r31.u32);
	// and r4,r4,r10
	ctx.r4.u64 = ctx.r4.u64 & ctx.r10.u64;
	// lwzx r6,r6,r16
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + r16.u32);
	// add r7,r8,r30
	ctx.r7.u64 = ctx.r8.u64 + r30.u64;
	// or r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 | ctx.r4.u64;
	// lwz r16,400(r1)
	r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 400);
	// and r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 & ctx.r10.u64;
	// lwz r17,272(r1)
	r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 272);
	// and r28,r28,r9
	r28.u64 = r28.u64 & ctx.r9.u64;
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// or r6,r28,r6
	ctx.r6.u64 = r28.u64 | ctx.r6.u64;
	// stw r5,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// lbz r5,7(r25)
	ctx.r5.u64 = REX_LOAD_U8(r25.u32 + 7);
	// addi r25,r25,8
	r25.s64 = r25.s64 + 8;
	// stw r6,4(r8)
	REX_STORE_U32(ctx.r8.u32 + 4, ctx.r6.u32);
	// rlwinm r8,r5,2,26,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3C;
	// rlwinm r6,r5,30,2,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFC;
	// stw r25,464(r1)
	REX_STORE_U32(ctx.r1.u32 + 464, r25.u32);
	// lwzx r5,r8,r31
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwzx r8,r8,r4
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r4.u32);
	// lwzx r4,r6,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + r31.u32);
	// and r5,r5,r9
	ctx.r5.u64 = ctx.r5.u64 & ctx.r9.u64;
	// lwzx r6,r6,r26
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + r26.u32);
	// and r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 & ctx.r10.u64;
	// and r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 & ctx.r9.u64;
	// lwz r26,208(r1)
	r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 208);
	// and r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 & ctx.r10.u64;
	// or r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
	// stw r10,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r10.u32);
	// b 0x82a7eec0
	goto loc_82A7EEC0;
loc_82A7EAE0:
	// rlwinm r10,r22,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r9,132(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, xer);
	// stbx r18,r10,r21
	REX_STORE_U8(ctx.r10.u32 + r21.u32, r18.u8);
	// blt cr6,0x82a7eb00
	if (cr6.lt) goto loc_82A7EB00;
	// lwz r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
loc_82A7EB00:
	// or r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 | r29.u64;
	// add r10,r29,r30
	ctx.r10.u64 = r29.u64 + r30.u64;
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82a7eb6c
	if (!cr6.eq) goto loc_82A7EB6C;
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// lfd f0,8(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// stfd f0,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.f0.u64);
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// lfd f0,16(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 16);
	// lfd f13,24(r11)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r11.u32 + 24);
	// lfd f12,32(r11)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r11.u32 + 32);
	// stfd f0,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.f0.u64);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// lfd f11,40(r11)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r11.u32 + 40);
	// stfd f13,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.f13.u64);
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// lfd f10,0(r11)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// lfd f9,48(r11)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r11.u32 + 48);
	// stfd f12,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.f12.u64);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// lfd f8,56(r11)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r11.u32 + 56);
	// stfd f11,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.f11.u64);
	// stfd f10,0(r29)
	REX_STORE_U64(r29.u32 + 0, ctx.f10.u64);
	// stfd f9,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.f9.u64);
	// stfdx f8,r9,r30
	REX_STORE_U64(ctx.r9.u32 + r30.u32, ctx.f8.u64);
	// b 0x82a7eeb8
	goto loc_82A7EEB8;
loc_82A7EB6C:
	// clrlwi r9,r9,30
	ctx.r9.u64 = ctx.r9.u32 & 0x3;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// bne cr6,0x82a7ec14
	if (!cr6.eq) goto loc_82A7EC14;
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r6,16(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r5,20(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r4,24(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r7,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,28(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// stw r6,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// stw r5,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r5.u32);
	// lwz r7,32(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// stw r10,0(r29)
	REX_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// lwz r28,36(r11)
	r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// lwz r20,40(r11)
	r20.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// lwz r19,44(r11)
	r19.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r18,4(r11)
	r18.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r4,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stw r8,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// stw r7,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// stw r28,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, r28.u32);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// lwz r17,48(r11)
	r17.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// lwz r16,52(r11)
	r16.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// stw r20,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, r20.u32);
	// stw r19,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, r19.u32);
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// lwz r15,56(r11)
	r15.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lwz r14,60(r11)
	r14.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// stw r18,4(r29)
	REX_STORE_U32(r29.u32 + 4, r18.u32);
	// stw r17,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, r17.u32);
	// stw r16,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, r16.u32);
	// stw r15,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, r15.u32);
	// stw r14,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, r14.u32);
	// b 0x82a7eea0
	goto loc_82A7EEA0;
loc_82A7EC14:
	// stw r9,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
	// lbz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 8);
	// lbz r8,9(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// lbz r7,10(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 10);
	// lbz r6,11(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 11);
	// lbz r5,12(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 12);
	// lbz r4,13(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 13);
	// lbz r3,14(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 14);
	// lbz r31,15(r11)
	r31.u64 = REX_LOAD_U8(ctx.r11.u32 + 15);
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// stb r8,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r8.u8);
	// stb r7,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r7.u8);
	// stb r6,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, ctx.r6.u8);
	// stb r5,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r5.u8);
	// stb r4,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, ctx.r4.u8);
	// stb r3,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, ctx.r3.u8);
	// stb r31,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, r31.u8);
	// lbz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
	// lbz r30,0(r11)
	r30.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r9,22(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
	// lbz r8,23(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// lbz r26,1(r11)
	r26.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// stb r10,109(r1)
	REX_STORE_U8(ctx.r1.u32 + 109, ctx.r10.u8);
	// lbz r10,17(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 17);
	// lbz r25,2(r11)
	r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r24,3(r11)
	r24.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r23,4(r11)
	r23.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r22,5(r11)
	r22.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// stb r10,103(r1)
	REX_STORE_U8(ctx.r1.u32 + 103, ctx.r10.u8);
	// lbz r10,18(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// lbz r21,6(r11)
	r21.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// lbz r20,7(r11)
	r20.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// lbz r7,24(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 24);
	// lbz r6,25(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 25);
	// stb r10,102(r1)
	REX_STORE_U8(ctx.r1.u32 + 102, ctx.r10.u8);
	// lbz r10,19(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 19);
	// lbz r5,26(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 26);
	// lbz r4,27(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 27);
	// lbz r3,28(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 28);
	// lbz r31,29(r11)
	r31.u64 = REX_LOAD_U8(ctx.r11.u32 + 29);
	// stb r10,108(r1)
	REX_STORE_U8(ctx.r1.u32 + 108, ctx.r10.u8);
	// lbz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 20);
	// lbz r28,30(r11)
	r28.u64 = REX_LOAD_U8(ctx.r11.u32 + 30);
	// lbz r27,31(r11)
	r27.u64 = REX_LOAD_U8(ctx.r11.u32 + 31);
	// lbz r19,32(r11)
	r19.u64 = REX_LOAD_U8(ctx.r11.u32 + 32);
	// lbz r18,33(r11)
	r18.u64 = REX_LOAD_U8(ctx.r11.u32 + 33);
	// stb r10,100(r1)
	REX_STORE_U8(ctx.r1.u32 + 100, ctx.r10.u8);
	// lbz r10,21(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// lbz r17,34(r11)
	r17.u64 = REX_LOAD_U8(ctx.r11.u32 + 34);
	// lbz r16,35(r11)
	r16.u64 = REX_LOAD_U8(ctx.r11.u32 + 35);
	// lbz r15,36(r11)
	r15.u64 = REX_LOAD_U8(ctx.r11.u32 + 36);
	// lbz r14,37(r11)
	r14.u64 = REX_LOAD_U8(ctx.r11.u32 + 37);
	// lbz r11,38(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 38);
	// stb r30,0(r29)
	REX_STORE_U8(r29.u32 + 0, r30.u8);
	// lwz r30,184(r1)
	r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// stb r26,1(r29)
	REX_STORE_U8(r29.u32 + 1, r26.u8);
	// stb r25,2(r29)
	REX_STORE_U8(r29.u32 + 2, r25.u8);
	// stb r11,101(r1)
	REX_STORE_U8(ctx.r1.u32 + 101, ctx.r11.u8);
	// mr r11,r30
	ctx.r11.u64 = r30.u64;
	// lwz r30,1508(r1)
	r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 1508);
	// lwz r29,120(r1)
	r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// add r30,r11,r30
	r30.u64 = ctx.r11.u64 + r30.u64;
	// stb r10,5(r11)
	REX_STORE_U8(ctx.r11.u32 + 5, ctx.r10.u8);
	// stb r9,6(r11)
	REX_STORE_U8(ctx.r11.u32 + 6, ctx.r9.u8);
	// stb r8,7(r11)
	REX_STORE_U8(ctx.r11.u32 + 7, ctx.r8.u8);
	// stw r30,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, r30.u32);
	// stb r24,3(r29)
	REX_STORE_U8(r29.u32 + 3, r24.u8);
	// stb r23,4(r29)
	REX_STORE_U8(r29.u32 + 4, r23.u8);
	// stb r22,5(r29)
	REX_STORE_U8(r29.u32 + 5, r22.u8);
	// stb r21,6(r29)
	REX_STORE_U8(r29.u32 + 6, r21.u8);
	// stb r20,7(r29)
	REX_STORE_U8(r29.u32 + 7, r20.u8);
	// lbz r30,109(r1)
	r30.u64 = REX_LOAD_U8(ctx.r1.u32 + 109);
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, r30.u8);
	// lbz r30,103(r1)
	r30.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// stb r30,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, r30.u8);
	// lbz r30,102(r1)
	r30.u64 = REX_LOAD_U8(ctx.r1.u32 + 102);
	// stb r30,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, r30.u8);
	// lbz r30,108(r1)
	r30.u64 = REX_LOAD_U8(ctx.r1.u32 + 108);
	// stb r30,3(r11)
	REX_STORE_U8(ctx.r11.u32 + 3, r30.u8);
	// lbz r30,100(r1)
	r30.u64 = REX_LOAD_U8(ctx.r1.u32 + 100);
	// stb r30,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, r30.u8);
	// lwz r11,184(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// lwz r30,1508(r1)
	r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 1508);
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + r30.u64;
	// stb r7,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r7.u8);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// stb r3,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r3.u8);
	// stb r6,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r6.u8);
	// stb r5,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r5.u8);
	// stb r4,3(r11)
	REX_STORE_U8(ctx.r11.u32 + 3, ctx.r4.u8);
	// stb r31,5(r11)
	REX_STORE_U8(ctx.r11.u32 + 5, r31.u8);
	// stb r28,6(r11)
	REX_STORE_U8(ctx.r11.u32 + 6, r28.u8);
	// stb r27,7(r11)
	REX_STORE_U8(ctx.r11.u32 + 7, r27.u8);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lbz r7,101(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 101);
	// stb r19,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, r19.u8);
	// stb r18,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, r18.u8);
	// stb r17,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, r17.u8);
	// lbz r8,39(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 39);
	// stb r7,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, ctx.r7.u8);
	// lbz r7,40(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 40);
	// lbz r6,41(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 41);
	// lbz r5,42(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 42);
	// stb r8,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r8.u8);
	// lbz r8,43(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 43);
	// lbz r4,44(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 44);
	// lbz r3,45(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 45);
	// lbz r31,46(r11)
	r31.u64 = REX_LOAD_U8(ctx.r11.u32 + 46);
	// lbz r28,47(r11)
	r28.u64 = REX_LOAD_U8(ctx.r11.u32 + 47);
	// stb r16,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, r16.u8);
	// stb r15,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, r15.u8);
	// stb r14,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, r14.u8);
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// stb r3,5(r9)
	REX_STORE_U8(ctx.r9.u32 + 5, ctx.r3.u8);
	// stb r7,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r7.u8);
	// stb r6,1(r9)
	REX_STORE_U8(ctx.r9.u32 + 1, ctx.r6.u8);
	// stb r5,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, ctx.r5.u8);
	// stb r8,3(r9)
	REX_STORE_U8(ctx.r9.u32 + 3, ctx.r8.u8);
	// stb r4,4(r9)
	REX_STORE_U8(ctx.r9.u32 + 4, ctx.r4.u8);
	// stb r31,6(r9)
	REX_STORE_U8(ctx.r9.u32 + 6, r31.u8);
	// stb r28,7(r9)
	REX_STORE_U8(ctx.r9.u32 + 7, r28.u8);
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// lbz r3,53(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 53);
	// lbz r27,56(r11)
	r27.u64 = REX_LOAD_U8(ctx.r11.u32 + 56);
	// lbz r26,57(r11)
	r26.u64 = REX_LOAD_U8(ctx.r11.u32 + 57);
	// lbz r25,58(r11)
	r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 58);
	// lbz r24,59(r11)
	r24.u64 = REX_LOAD_U8(ctx.r11.u32 + 59);
	// lbz r23,60(r11)
	r23.u64 = REX_LOAD_U8(ctx.r11.u32 + 60);
	// lbz r22,61(r11)
	r22.u64 = REX_LOAD_U8(ctx.r11.u32 + 61);
	// lbz r21,62(r11)
	r21.u64 = REX_LOAD_U8(ctx.r11.u32 + 62);
	// lbz r8,48(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 48);
	// lbz r7,49(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 49);
	// lbz r6,50(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 50);
	// lbz r5,51(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 51);
	// lbz r4,52(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 52);
	// lbz r31,54(r11)
	r31.u64 = REX_LOAD_U8(ctx.r11.u32 + 54);
	// lbz r28,55(r11)
	r28.u64 = REX_LOAD_U8(ctx.r11.u32 + 55);
	// lbz r20,63(r11)
	r20.u64 = REX_LOAD_U8(ctx.r11.u32 + 63);
	// stb r3,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, ctx.r3.u8);
	// stb r27,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, r27.u8);
	// stb r26,1(r9)
	REX_STORE_U8(ctx.r9.u32 + 1, r26.u8);
	// stb r25,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, r25.u8);
	// stb r24,3(r9)
	REX_STORE_U8(ctx.r9.u32 + 3, r24.u8);
	// stb r23,4(r9)
	REX_STORE_U8(ctx.r9.u32 + 4, r23.u8);
	// li r23,0
	r23.s64 = 0;
	// stb r22,5(r9)
	REX_STORE_U8(ctx.r9.u32 + 5, r22.u8);
	// stb r21,6(r9)
	REX_STORE_U8(ctx.r9.u32 + 6, r21.u8);
	// lwz r21,116(r1)
	r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r22,112(r1)
	r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r24,88(r1)
	r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r27,80(r1)
	r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r26,208(r1)
	r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 208);
	// lwz r25,464(r1)
	r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 464);
	// stb r8,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// stb r7,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r7.u8);
	// stb r6,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r6.u8);
	// stb r5,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, ctx.r5.u8);
	// stb r4,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r4.u8);
	// stb r31,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, r31.u8);
	// stb r28,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, r28.u8);
	// stb r20,7(r9)
	REX_STORE_U8(ctx.r9.u32 + 7, r20.u8);
	// lwz r31,200(r1)
	r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
loc_82A7EEA0:
	// lwz r16,400(r1)
	r16.u64 = REX_LOAD_U32(ctx.r1.u32 + 400);
	// li r18,1
	r18.s64 = 1;
	// lwz r17,272(r1)
	r17.u64 = REX_LOAD_U32(ctx.r1.u32 + 272);
	// lwz r20,336(r1)
	r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 336);
	// lwz r15,104(r1)
	r15.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r19,96(r1)
	r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
loc_82A7EEB8:
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
loc_82A7EEBC:
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
loc_82A7EEC0:
	// lwz r9,1556(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 1556);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// lwz r10,124(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// addi r19,r19,8
	r19.s64 = r19.s64 + 8;
	// add r22,r22,r9
	r22.u64 = r22.u64 + ctx.r9.u64;
	// addi r4,r10,-8
	ctx.r4.s64 = ctx.r10.s64 + -8;
loc_82A7EED8:
	// stw r4,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r19,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, r19.u32);
	// stw r29,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, r29.u32);
	// stw r22,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, r22.u32);
	// bne cr6,0x82a7d04c
	if (!cr6.eq) goto loc_82A7D04C;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x82a7ef04
	if (!cr6.eq) goto loc_82A7EF04;
	// rlwinm r11,r15,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(r15.u32 | (r15.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7ef10
	if (cr6.eq) goto loc_82A7EF10;
loc_82A7EF04:
	// lwz r11,1548(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 1548);
	// add r21,r21,r11
	r21.u64 = r21.u64 + ctx.r11.u64;
	// stw r21,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, r21.u32);
loc_82A7EF10:
	// lwz r11,204(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 204);
	// addi r15,r15,8
	r15.s64 = r15.s64 + 8;
	// mr r22,r23
	r22.u64 = r23.u64;
	// add r29,r29,r11
	r29.u64 = r29.u64 + ctx.r11.u64;
	// add r19,r19,r11
	r19.u64 = r19.u64 + ctx.r11.u64;
	// lwz r11,1500(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 1500);
	// stw r15,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, r15.u32);
	// cmplw cr6,r15,r11
	cr6.compare<uint32_t>(r15.u32, ctx.r11.u32, xer);
	// stw r22,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, r22.u32);
	// stw r29,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, r29.u32);
	// stw r19,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, r19.u32);
	// blt cr6,0x82a7cf6c
	if (cr6.lt) goto loc_82A7CF6C;
	// lwz r11,1580(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 1580);
	// lwz r10,180(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,1456
	ctx.r1.s64 = ctx.r1.s64 + 1456;
	// b 0x829ff7e0
	return;
loc_82A7EF54:
	// lwz r11,1580(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 1580);
	// lwz r10,180(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,1456
	ctx.r1.s64 = ctx.r1.s64 + 1456;
	// b 0x829ff7e0
	return;
}

DEFINE_REX_FUNC(sub_82A7EF70) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r18{};
	PPCRegister r19{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7a0
	ctx.lr = 0x82A7EF78;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// lwz r30,20(r31)
	r30.u64 = REX_LOAD_U32(r31.u32 + 20);
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// xori r11,r30,1
	ctx.r11.u64 = r30.u64 ^ 1;
	// mr r22,r19
	r22.u64 = r19.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// lwz r10,28(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a7efc4
	if (cr6.eq) goto loc_82A7EFC4;
	// stw r11,20(r31)
	REX_STORE_U32(r31.u32 + 20, ctx.r11.u32);
loc_82A7EFC4:
	// lwz r11,340(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 340);
	// li r18,0
	r18.s64 = 0;
	// lwz r29,20(r31)
	r29.u64 = REX_LOAD_U32(r31.u32 + 20);
	// addi r27,r7,4
	r27.s64 = ctx.r7.s64 + 4;
	// rlwinm r11,r11,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// li r20,1
	r20.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// stw r18,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, r18.u32);
	// beq cr6,0x82a7f05c
	if (cr6.eq) goto loc_82A7F05C;
	// rlwinm r11,r28,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f054
	if (cr6.eq) goto loc_82A7F054;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lwz r6,8(r31)
	ctx.r6.u64 = REX_LOAD_U32(r31.u32 + 8);
	// rlwinm r7,r29,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(r31.u32 + 4);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// stw r28,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, r28.u32);
	// add r7,r29,r7
	ctx.r7.u64 = r29.u64 + ctx.r7.u64;
	// stw r23,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, r23.u32);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// stw r25,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r7,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// add r11,r30,r11
	ctx.r11.u64 = r30.u64 + ctx.r11.u64;
	// stw r20,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, r20.u32);
	// add r7,r7,r31
	ctx.r7.u64 = ctx.r7.u64 + r31.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r19,4
	ctx.r8.s64 = r19.s64 + 4;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + r31.u64;
	// lwz r3,64(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// lwz r7,68(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// lwz r4,64(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// bl 0x82a7cbd0
	ctx.lr = 0x82A7F054;
	sub_82A7CBD0(ctx, base);
loc_82A7F054:
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(r19.u32 + 0);
	// add r22,r11,r19
	r22.u64 = ctx.r11.u64 + r19.u64;
loc_82A7F05C:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// rlwinm r21,r28,0,16,16
	r21.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// stw r3,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// bne cr6,0x82a7f074
	if (!cr6.eq) goto loc_82A7F074;
	// addi r22,r22,4
	r22.s64 = r22.s64 + 4;
loc_82A7F074:
	// cmplw cr6,r22,r19
	cr6.compare<uint32_t>(r22.u32, r19.u32, xer);
	// blt cr6,0x82a7f1bc
	if (cr6.lt) goto loc_82A7F1BC;
	// cmplw cr6,r22,r27
	cr6.compare<uint32_t>(r22.u32, r27.u32, xer);
	// bge cr6,0x82a7f1bc
	if (!cr6.lt) goto loc_82A7F1BC;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lwz r6,8(r31)
	ctx.r6.u64 = REX_LOAD_U32(r31.u32 + 8);
	// rlwinm r7,r30,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(r31.u32 + 4);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// stw r28,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, r28.u32);
	// add r7,r30,r7
	ctx.r7.u64 = r30.u64 + ctx.r7.u64;
	// stw r23,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, r23.u32);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// stw r25,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r7,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// add r11,r29,r11
	ctx.r11.u64 = r29.u64 + ctx.r11.u64;
	// stw r20,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, r20.u32);
	// add r30,r7,r31
	r30.u64 = ctx.r7.u64 + r31.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// add r29,r11,r31
	r29.u64 = ctx.r11.u64 + r31.u64;
	// lwz r7,32(r30)
	ctx.r7.u64 = REX_LOAD_U32(r30.u32 + 32);
	// lwz r4,28(r30)
	ctx.r4.u64 = REX_LOAD_U32(r30.u32 + 28);
	// lwz r3,28(r29)
	ctx.r3.u64 = REX_LOAD_U32(r29.u32 + 28);
	// bl 0x82a7cbd0
	ctx.lr = 0x82A7F0E4;
	sub_82A7CBD0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x82a7f0fc
	if (!cr6.eq) goto loc_82A7F0FC;
	// lwz r11,-4(r22)
	ctx.r11.u64 = REX_LOAD_U32(r22.u32 + -4);
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + r22.u64;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
loc_82A7F0FC:
	// lwz r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// rlwinm r11,r28,0,14,14
	ctx.r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x20000;
	// rlwinm r3,r10,30,2,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// stw r3,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// bne cr6,0x82a7f1bc
	if (!cr6.eq) goto loc_82A7F1BC;
	// cmplw cr6,r8,r19
	cr6.compare<uint32_t>(ctx.r8.u32, r19.u32, xer);
	// blt cr6,0x82a7f1bc
	if (cr6.lt) goto loc_82A7F1BC;
	// cmplw cr6,r8,r27
	cr6.compare<uint32_t>(ctx.r8.u32, r27.u32, xer);
	// bge cr6,0x82a7f1bc
	if (!cr6.lt) goto loc_82A7F1BC;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lwz r7,44(r30)
	ctx.r7.u64 = REX_LOAD_U32(r30.u32 + 44);
	// li r22,2
	r22.s64 = 2;
	// lwz r6,16(r31)
	ctx.r6.u64 = REX_LOAD_U32(r31.u32 + 16);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = REX_LOAD_U32(r31.u32 + 12);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// lwz r4,40(r30)
	ctx.r4.u64 = REX_LOAD_U32(r30.u32 + 40);
	// lwz r3,40(r29)
	ctx.r3.u64 = REX_LOAD_U32(r29.u32 + 40);
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// stw r28,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, r28.u32);
	// stw r23,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, r23.u32);
	// stw r22,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, r22.u32);
	// stw r25,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// bl 0x82a7cbd0
	ctx.lr = 0x82A7F164;
	sub_82A7CBD0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplw cr6,r8,r19
	cr6.compare<uint32_t>(ctx.r8.u32, r19.u32, xer);
	// blt cr6,0x82a7f1b8
	if (cr6.lt) goto loc_82A7F1B8;
	// cmplw cr6,r8,r27
	cr6.compare<uint32_t>(ctx.r8.u32, r27.u32, xer);
	// bge cr6,0x82a7f1b8
	if (!cr6.lt) goto loc_82A7F1B8;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lwz r7,56(r30)
	ctx.r7.u64 = REX_LOAD_U32(r30.u32 + 56);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// lwz r6,16(r31)
	ctx.r6.u64 = REX_LOAD_U32(r31.u32 + 16);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = REX_LOAD_U32(r31.u32 + 12);
	// lwz r4,52(r30)
	ctx.r4.u64 = REX_LOAD_U32(r30.u32 + 52);
	// lwz r3,52(r29)
	ctx.r3.u64 = REX_LOAD_U32(r29.u32 + 52);
	// stw r18,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, r18.u32);
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// stw r28,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, r28.u32);
	// stw r23,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, r23.u32);
	// stw r22,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, r22.u32);
	// stw r25,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// bl 0x82a7cbd0
	ctx.lr = 0x82A7F1B8;
	sub_82A7CBD0(ctx, base);
loc_82A7F1B8:
	// lwz r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
loc_82A7F1BC:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x829ff7f0
	return;
}

DEFINE_REX_FUNC(sub_82A7F1C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c8
	ctx.lr = 0x82A7F1D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f1f8
	if (cr6.eq) goto loc_82A7F1F8;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7F1F8;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
loc_82A7F1F8:
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x82a7f228
	if (cr6.eq) goto loc_82A7F228;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 88);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(ctx.r11.u32, r30.u32, xer);
	// beq cr6,0x82a7f228
	if (cr6.eq) goto loc_82A7F228;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 124);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(r31.u32 + 84);
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + r30.u64;
	// bl 0x82a127e0
	ctx.lr = 0x82A7F224;
	SetFilePointer(ctx, base);
	// stw r30,88(r31)
	REX_STORE_U32(r31.u32 + 88, r30.u32);
loc_82A7F228:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(r31.u32 + 84);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82a12958
	ctx.lr = 0x82A7F240;
	ReadFile(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// beq cr6,0x82a7f254
	if (cr6.eq) goto loc_82A7F254;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,32(r31)
	REX_STORE_U32(r31.u32 + 32, ctx.r11.u32);
loc_82A7F254:
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 88);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stw r11,88(r31)
	REX_STORE_U32(r31.u32 + 88, ctx.r11.u32);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 88);
	// stw r11,92(r31)
	REX_STORE_U32(r31.u32 + 92, ctx.r11.u32);
	// lwz r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 128);
	// lwz r10,92(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 92);
	// lwz r9,64(r31)
	ctx.r9.u64 = REX_LOAD_U32(r31.u32 + 64);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82a7f284
	if (cr6.lt) goto loc_82A7F284;
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 64);
loc_82A7F284:
	// lwz r10,252(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 252);
	// stw r11,72(r31)
	REX_STORE_U32(r31.u32 + 72, ctx.r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a7f2a4
	if (cr6.eq) goto loc_82A7F2A4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82A7F2A0;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_82A7F2A4:
	// addi r11,r3,3
	ctx.r11.s64 = ctx.r3.s64 + 3;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f2d0
	if (cr6.eq) goto loc_82A7F2D0;
loc_82A7F2B8:
	// lwbrx r9,0,r10
	ctx.r9.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r10.u32));
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne cr6,0x82a7f2b8
	if (!cr6.eq) goto loc_82A7F2B8;
loc_82A7F2D0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x829ff818
	return;
}

DEFINE_REX_FUNC(sub_82A7F2D8) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c8
	ctx.lr = 0x82A7F2E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrldi r11,r4,32
	ctx.r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mulli r11,r11,1000
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(1000));
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 132);
	// divdu r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 ? ctx.r11.u64 / ctx.r10.u64 : 0;
	// rotlwi r28,r11,0
	r28.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82a7a318
	ctx.lr = 0x82A7F304;
	sub_82A7A318(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 136);
	// subf r11,r30,r28
	ctx.r11.u64 = r28.u64 - r30.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + r29.u64;
	// stw r11,136(r31)
	REX_STORE_U32(r31.u32 + 136, ctx.r11.u32);
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(ctx.r11.s32, 0, xer);
	// ble cr6,0x82a7f35c
	if (!cr6.gt) goto loc_82A7F35C;
loc_82A7F328:
	// bl 0x82a7a318
	ctx.lr = 0x82A7F32C;
	sub_82A7A318(ctx, base);
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 136);
	// subf r10,r30,r3
	ctx.r10.u64 = ctx.r3.u64 - r30.u64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, xer);
	// blt cr6,0x82a7f328
	if (cr6.lt) goto loc_82A7F328;
	// lwz r10,136(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 136);
	// subf r11,r3,r30
	ctx.r11.u64 = r30.u64 - ctx.r3.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,136(r31)
	REX_STORE_U32(r31.u32 + 136, ctx.r11.u32);
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(ctx.r11.s32, 0, xer);
	// bgt cr6,0x82a7f328
	if (cr6.gt) goto loc_82A7F328;
loc_82A7F35C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x829ff818
	return;
}

DEFINE_REX_FUNC(sub_82A7F368) {
	REX_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7b0
	ctx.lr = 0x82A7F370;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 32);
	// mr r23,r25
	r23.u64 = r25.u64;
	// mr r22,r28
	r22.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f3a8
	if (cr6.eq) goto loc_82A7F3A8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x829ff800
	return;
loc_82A7F3A8:
	// bl 0x82a7a318
	ctx.lr = 0x82A7F3AC;
	sub_82A7A318(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x82a7f48c
	if (cr6.eq) goto loc_82A7F48C;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 92);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(ctx.r11.u32, r30.u32, xer);
	// beq cr6,0x82a7f48c
	if (cr6.eq) goto loc_82A7F48C;
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 244);
	// li r23,1
	r23.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f3e0
	if (cr6.eq) goto loc_82A7F3E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7F3E0;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
loc_82A7F3E0:
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 92);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, ctx.r11.u32, xer);
	// ble cr6,0x82a7f450
	if (!cr6.gt) goto loc_82A7F450;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 88);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, ctx.r11.u32, xer);
	// bgt cr6,0x82a7f450
	if (cr6.gt) goto loc_82A7F450;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 92);
	// stw r30,92(r31)
	REX_STORE_U32(r31.u32 + 92, r30.u32);
	// lwz r10,100(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 100);
	// subf r11,r11,r30
	ctx.r11.u64 = r30.u64 - ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,100(r31)
	REX_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// lwz r10,76(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 76);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r10,76(r31)
	REX_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 96);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,96(r31)
	REX_STORE_U32(r31.u32 + 96, ctx.r11.u32);
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 112);
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, xer);
	// ble cr6,0x82a7f48c
	if (!cr6.gt) goto loc_82A7F48C;
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 64);
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 96);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r11,96(r31)
	REX_STORE_U32(r31.u32 + 96, ctx.r11.u32);
	// b 0x82a7f48c
	goto loc_82A7F48C;
loc_82A7F450:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 124);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(r31.u32 + 84);
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + r30.u64;
	// bl 0x82a127e0
	ctx.lr = 0x82A7F468;
	SetFilePointer(ctx, base);
	// stw r30,88(r31)
	REX_STORE_U32(r31.u32 + 88, r30.u32);
	// stw r30,92(r31)
	REX_STORE_U32(r31.u32 + 92, r30.u32);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 64);
	// stw r11,100(r31)
	REX_STORE_U32(r31.u32 + 100, ctx.r11.u32);
	// stw r25,76(r31)
	REX_STORE_U32(r31.u32 + 76, r25.u32);
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 108);
	// stw r11,96(r31)
	REX_STORE_U32(r31.u32 + 96, ctx.r11.u32);
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 108);
	// stw r11,116(r31)
	REX_STORE_U32(r31.u32 + 116, ctx.r11.u32);
loc_82A7F48C:
	// addi r26,r31,76
	r26.s64 = r31.s64 + 76;
loc_82A7F490:
	// lwz r30,0(r26)
	r30.u64 = REX_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82a7f598
	if (cr6.eq) goto loc_82A7F598;
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// ble cr6,0x82a7f4a8
	if (!cr6.gt) goto loc_82A7F4A8;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_82A7F4A8:
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 92);
	// subf r27,r30,r27
	r27.u64 = r27.u64 - r30.u64;
	// add r25,r30,r25
	r25.u64 = r30.u64 + r25.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + r30.u64;
	// stw r11,92(r31)
	REX_STORE_U32(r31.u32 + 92, ctx.r11.u32);
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 112);
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 96);
	// subf r29,r10,r11
	r29.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplw cr6,r29,r30
	cr6.compare<uint32_t>(r29.u32, r30.u32, xer);
	// bgt cr6,0x82a7f538
	if (cr6.gt) goto loc_82A7F538;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,96(r31)
	ctx.r4.u64 = REX_LOAD_U32(r31.u32 + 96);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82a00dc0
	ctx.lr = 0x82A7F4E0;
	rexcrt_memcpy(ctx, base);
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 108);
	// add r28,r29,r28
	r28.u64 = r29.u64 + r28.u64;
	// subf r30,r29,r30
	r30.u64 = r30.u64 - r29.u64;
	// neg r8,r29
	ctx.r8.s64 = static_cast<int64_t>(-r29.u64);
	// stw r11,96(r31)
	REX_STORE_U32(r31.u32 + 96, ctx.r11.u32);
loc_82A7F4F4:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r26
	ea = r26.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stwcx. r9,0,r26
	ea = r26.u32;
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	cr0.so = xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82a7f4f4
	if (!cr0.eq) goto loc_82A7F4F4;
	// addi r11,r31,100
	ctx.r11.s64 = r31.s64 + 100;
loc_82A7F514:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r29,r10
	ctx.r9.u64 = r29.u64 + ctx.r10.u64;
	// stwcx. r9,0,r11
	ea = ctx.r11.u32;
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	cr0.so = xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82a7f514
	if (!cr0.eq) goto loc_82A7F514;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82a7f598
	if (cr6.eq) goto loc_82A7F598;
loc_82A7F538:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,96(r31)
	ctx.r4.u64 = REX_LOAD_U32(r31.u32 + 96);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82a00dc0
	ctx.lr = 0x82A7F548;
	rexcrt_memcpy(ctx, base);
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 96);
	// add r28,r30,r28
	r28.u64 = r30.u64 + r28.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + r30.u64;
	// neg r8,r30
	ctx.r8.s64 = static_cast<int64_t>(-r30.u64);
	// stw r11,96(r31)
	REX_STORE_U32(r31.u32 + 96, ctx.r11.u32);
loc_82A7F55C:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r26
	ea = r26.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stwcx. r9,0,r26
	ea = r26.u32;
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	cr0.so = xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82a7f55c
	if (!cr0.eq) goto loc_82A7F55C;
	// addi r11,r31,100
	ctx.r11.s64 = r31.s64 + 100;
loc_82A7F57C:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r30,r10
	ctx.r9.u64 = r30.u64 + ctx.r10.u64;
	// stwcx. r9,0,r11
	ea = ctx.r11.u32;
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	cr0.so = xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82a7f57c
	if (!cr0.eq) goto loc_82A7F57C;
loc_82A7F598:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82a7f654
	if (cr6.eq) goto loc_82A7F654;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// bne cr6,0x82a7f5c8
	if (!cr6.eq) goto loc_82A7F5C8;
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 244);
	// li r23,1
	r23.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f490
	if (cr6.eq) goto loc_82A7F490;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7F5C4;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82a7f490
	goto loc_82A7F490;
loc_82A7F5C8:
	// bl 0x82a7a318
	ctx.lr = 0x82A7F5CC;
	sub_82A7A318(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(r31.u32 + 84);
	// bl 0x82a12958
	ctx.lr = 0x82A7F5E8;
	ReadFile(ctx, base);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r4,r27
	cr6.compare<uint32_t>(ctx.r4.u32, r27.u32, xer);
	// bge cr6,0x82a7f5fc
	if (!cr6.lt) goto loc_82A7F5FC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,32(r31)
	REX_STORE_U32(r31.u32 + 32, ctx.r11.u32);
loc_82A7F5FC:
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 88);
	// add r25,r4,r25
	r25.u64 = ctx.r4.u64 + r25.u64;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// stw r11,88(r31)
	REX_STORE_U32(r31.u32 + 88, ctx.r11.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 92);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// stw r11,92(r31)
	REX_STORE_U32(r31.u32 + 92, ctx.r11.u32);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 40);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// stw r11,40(r31)
	REX_STORE_U32(r31.u32 + 40, ctx.r11.u32);
	// lwz r11,132(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f63c
	if (cr6.eq) goto loc_82A7F63C;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a7f2d8
	ctx.lr = 0x82A7F63C;
	sub_82A7F2D8(ctx, base);
loc_82A7F63C:
	// bl 0x82a7a318
	ctx.lr = 0x82A7F640;
	sub_82A7A318(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(r31.u32 + 48);
	// subf r10,r30,r3
	ctx.r10.u64 = ctx.r3.u64 - r30.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,48(r31)
	REX_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// b 0x82a7f658
	goto loc_82A7F658;
loc_82A7F654:
	// bl 0x82a7a318
	ctx.lr = 0x82A7F658;
	sub_82A7A318(ctx, base);
loc_82A7F658:
	// lwz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 52);
	// subf r11,r24,r3
	ctx.r11.u64 = ctx.r3.u64 - r24.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,52(r31)
	REX_STORE_U32(r31.u32 + 52, ctx.r11.u32);
	// lwz r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 128);
	// lwz r10,92(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 92);
	// lwz r9,64(r31)
	ctx.r9.u64 = REX_LOAD_U32(r31.u32 + 64);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// blt cr6,0x82a7f688
	if (cr6.lt) goto loc_82A7F688;
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 64);
loc_82A7F688:
	// stw r11,72(r31)
	REX_STORE_U32(r31.u32 + 72, ctx.r11.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(r26.u32 + 0);
	// lwz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 72);
	// addis r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 131072;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x82a7f6a8
	if (!cr6.gt) goto loc_82A7F6A8;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(r26.u32 + 0);
	// stw r11,72(r31)
	REX_STORE_U32(r31.u32 + 72, ctx.r11.u32);
loc_82A7F6A8:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// beq cr6,0x82a7f6c8
	if (cr6.eq) goto loc_82A7F6C8;
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f6c8
	if (cr6.eq) goto loc_82A7F6C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7F6C8;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
loc_82A7F6C8:
	// addi r11,r25,3
	ctx.r11.s64 = r25.s64 + 3;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f6f4
	if (cr6.eq) goto loc_82A7F6F4;
loc_82A7F6DC:
	// lwbrx r9,0,r10
	ctx.r9.u64 = __builtin_bswap32(REX_LOAD_U32(ctx.r10.u32));
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne cr6,0x82a7f6dc
	if (!cr6.eq) goto loc_82A7F6DC;
loc_82A7F6F4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x829ff800
	return;
}

DEFINE_REX_FUNC(sub_82A7F700) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// addis r10,r4,2
	ctx.r10.s64 = ctx.r4.s64 + 131072;
	// lis r11,4
	ctx.r11.s64 = 262144;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// rlwinm r10,r10,0,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFE0000;
	// addi r3,r10,4096
	ctx.r3.s64 = ctx.r10.s64 + 4096;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A7F728) {
	REX_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c4
	ctx.lr = 0x82A7F730;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f75c
	if (cr6.eq) goto loc_82A7F75C;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7F75C;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
loc_82A7F75C:
	// addi r11,r30,4095
	ctx.r11.s64 = r30.s64 + 4095;
	// lwz r9,252(r31)
	ctx.r9.u64 = REX_LOAD_U32(r31.u32 + 252);
	// rlwinm r10,r29,0,0,14
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFE0000;
	// rlwinm r11,r11,0,0,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFF000;
	// li r8,0
	ctx.r8.s64 = 0;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r11,108(r31)
	REX_STORE_U32(r31.u32 + 108, ctx.r11.u32);
	// stw r11,96(r31)
	REX_STORE_U32(r31.u32 + 96, ctx.r11.u32);
	// stw r11,116(r31)
	REX_STORE_U32(r31.u32 + 116, ctx.r11.u32);
	// stw r7,112(r31)
	REX_STORE_U32(r31.u32 + 112, ctx.r7.u32);
	// stw r10,64(r31)
	REX_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// stw r10,100(r31)
	REX_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// stw r8,76(r31)
	REX_STORE_U32(r31.u32 + 76, ctx.r8.u32);
	// stw r28,128(r31)
	REX_STORE_U32(r31.u32 + 128, r28.u32);
	// stw r27,132(r31)
	REX_STORE_U32(r31.u32 + 132, r27.u32);
	// beq cr6,0x82a7f7ac
	if (cr6.eq) goto loc_82A7F7AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82A7F7AC;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
loc_82A7F7AC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x829ff814
	return;
}

DEFINE_REX_FUNC(sub_82A7F7B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f7e0
	if (cr6.eq) goto loc_82A7F7E0;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7F7E0;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
loc_82A7F7E0:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a7f7f4
	if (!cr6.eq) goto loc_82A7F7F4;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(r31.u32 + 84);
	// bl 0x82a11f68
	ctx.lr = 0x82A7F7F4;
	CloseHandle(ctx, base);
loc_82A7F7F4:
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f80c
	if (cr6.eq) goto loc_82A7F80C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7F80C;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
loc_82A7F80C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A7F820) {
	REX_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7b8
	ctx.lr = 0x82A7F828;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lwz r24,44(r31)
	r24.u64 = REX_LOAD_U32(r31.u32 + 44);
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 32);
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f854
	if (cr6.eq) goto loc_82A7F854;
loc_82A7F848:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff808
	return;
loc_82A7F854:
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a7f848
	if (!cr6.eq) goto loc_82A7F848;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7fa64
	if (cr6.eq) goto loc_82A7FA64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7F878;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82a7fa64
	if (cr6.eq) goto loc_82A7FA64;
	// lwz r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 128);
	// lis r28,2
	r28.s64 = 131072;
	// lwz r10,88(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 88);
	// addi r25,r31,100
	r25.s64 = r31.s64 + 100;
	// lwz r9,100(r31)
	ctx.r9.u64 = REX_LOAD_U32(r31.u32 + 100);
	// subf r29,r10,r11
	r29.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplw cr6,r9,r28
	cr6.compare<uint32_t>(ctx.r9.u32, r28.u32, xer);
	// blt cr6,0x82a7fa34
	if (cr6.lt) goto loc_82A7FA34;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82a7fa34
	if (cr6.eq) goto loc_82A7FA34;
	// mr r30,r28
	r30.u64 = r28.u64;
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// bge cr6,0x82a7f8b8
	if (!cr6.lt) goto loc_82A7F8B8;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82A7F8B8:
	// bl 0x82a7a318
	ctx.lr = 0x82A7F8BC;
	sub_82A7A318(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 88);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// clrlwi r11,r11,15
	ctx.r11.u64 = ctx.r11.u32 & 0x1FFFF;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(ctx.r11.u32, r30.u32, xer);
	// bgt cr6,0x82a7f8d8
	if (cr6.gt) goto loc_82A7F8D8;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// bne cr6,0x82a7f8e0
	if (!cr6.eq) goto loc_82A7F8E0;
loc_82A7F8D8:
	// mr r11,r27
	ctx.r11.u64 = r27.u64;
	// b 0x82a7f8f4
	goto loc_82A7F8F4;
loc_82A7F8E0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f8f4
	if (cr6.eq) goto loc_82A7F8F4;
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 96);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r10,96(r31)
	REX_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_82A7F8F4:
	// li r29,1
	r29.s64 = 1;
	// subf r30,r11,r30
	r30.u64 = r30.u64 - ctx.r11.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r29,36(r31)
	REX_STORE_U32(r31.u32 + 36, r29.u32);
	// lwz r10,116(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 116);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(r31.u32 + 84);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x82a12958
	ctx.lr = 0x82A7F91C;
	ReadFile(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r27,36(r31)
	REX_STORE_U32(r31.u32 + 36, r27.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// beq cr6,0x82a7f930
	if (cr6.eq) goto loc_82A7F930;
	// stw r29,32(r31)
	REX_STORE_U32(r31.u32 + 32, r29.u32);
loc_82A7F930:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82a7fa40
	if (cr6.eq) goto loc_82A7FA40;
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 40);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stw r11,40(r31)
	REX_STORE_U32(r31.u32 + 40, ctx.r11.u32);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 88);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stw r11,88(r31)
	REX_STORE_U32(r31.u32 + 88, ctx.r11.u32);
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 116);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + r28.u64;
	// stw r11,116(r31)
	REX_STORE_U32(r31.u32 + 116, ctx.r11.u32);
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 112);
	// lwz r10,116(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 116);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, xer);
	// blt cr6,0x82a7f974
	if (cr6.lt) goto loc_82A7F974;
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 108);
	// stw r11,116(r31)
	REX_STORE_U32(r31.u32 + 116, ctx.r11.u32);
loc_82A7F974:
	// neg r11,r3
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r3.u64);
loc_82A7F978:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r25
	ea = r25.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stwcx. r9,0,r25
	ea = r25.u32;
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	cr0.so = xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82a7f978
	if (!cr0.eq) goto loc_82A7F978;
	// lwz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r31,76
	ctx.r11.s64 = r31.s64 + 76;
loc_82A7F99C:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// add r9,r7,r10
	ctx.r9.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stwcx. r9,0,r11
	ea = ctx.r11.u32;
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	cr0.so = xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82a7f99c
	if (!cr0.eq) goto loc_82A7F99C;
	// lwz r10,76(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 76);
	// lwz r9,68(r31)
	ctx.r9.u64 = REX_LOAD_U32(r31.u32 + 68);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x82a7f9d0
	if (!cr6.gt) goto loc_82A7F9D0;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,68(r31)
	REX_STORE_U32(r31.u32 + 68, ctx.r11.u32);
loc_82A7F9D0:
	// lwz r11,132(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7f9ec
	if (cr6.eq) goto loc_82A7F9EC;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a7f2d8
	ctx.lr = 0x82A7F9EC;
	sub_82A7F2D8(ctx, base);
loc_82A7F9EC:
	// bl 0x82a7a318
	ctx.lr = 0x82A7F9F0;
	sub_82A7A318(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 48);
	// subf r11,r26,r3
	ctx.r11.u64 = ctx.r3.u64 - r26.u64;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r10,48(r31)
	REX_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// bne cr6,0x82a7fa24
	if (!cr6.eq) goto loc_82A7FA24;
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 44);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82a7fa24
	if (!cr6.eq) goto loc_82A7FA24;
	// lwz r10,56(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 56);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,56(r31)
	REX_STORE_U32(r31.u32 + 56, ctx.r11.u32);
	// b 0x82a7fa3c
	goto loc_82A7FA3C;
loc_82A7FA24:
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 60);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,60(r31)
	REX_STORE_U32(r31.u32 + 60, ctx.r11.u32);
	// b 0x82a7fa3c
	goto loc_82A7FA3C;
loc_82A7FA34:
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 76);
	// stw r11,72(r31)
	REX_STORE_U32(r31.u32 + 72, ctx.r11.u32);
loc_82A7FA3C:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_82A7FA40:
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7fa80
	if (cr6.eq) goto loc_82A7FA80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7FA58;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff808
	return;
loc_82A7FA64:
	// lwz r11,256(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7fa7c
	if (cr6.eq) goto loc_82A7FA7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7FA7C;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
loc_82A7FA7C:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82A7FA80:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff808
	return;
}

DEFINE_REX_FUNC(sub_82A7FA88) {
	REX_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,31
	ctx.r11.u64 = ctx.r4.u32 & 0x1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7fafc
	if (cr6.eq) goto loc_82A7FAFC;
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a7fabc
	if (!cr6.eq) goto loc_82A7FABC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,80(r31)
	REX_STORE_U32(r31.u32 + 80, ctx.r11.u32);
loc_82A7FABC:
	// rlwinm r11,r4,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7fb30
	if (cr6.eq) goto loc_82A7FB30;
	// lwz r11,244(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7fae0
	if (cr6.eq) goto loc_82A7FAE0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7FAE0;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
loc_82A7FAE0:
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7fb30
	if (cr6.eq) goto loc_82A7FB30;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82A7FAF8;
	REX_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82a7fb30
	goto loc_82A7FB30;
loc_82A7FAFC:
	// rlwinm r11,r4,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7fb30
	if (cr6.eq) goto loc_82A7FB30;
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(ctx.r11.u32, 1, xer);
	// bne cr6,0x82a7fb1c
	if (!cr6.eq) goto loc_82A7FB1C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,80(r31)
	REX_STORE_U32(r31.u32 + 80, ctx.r11.u32);
loc_82A7FB1C:
	// rlwinm r11,r4,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7fb30
	if (cr6.eq) goto loc_82A7FB30;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a7f820
	ctx.lr = 0x82A7FB30;
	sub_82A7F820(ctx, base);
loc_82A7FB30:
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(r31.u32 + 80);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A7FB48) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7cc
	ctx.lr = 0x82A7FB50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r5,324
	ctx.r5.s64 = 324;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x829ff840
	ctx.lr = 0x82A7FB6C;
	rexcrt_memset(ctx, base);
	// rlwinm r11,r29,0,8,8
	ctx.r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x800000;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a7fbfc
	if (cr6.eq) goto loc_82A7FBFC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r30,84(r31)
	REX_STORE_U32(r31.u32 + 84, r30.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,120(r31)
	REX_STORE_U32(r31.u32 + 120, ctx.r11.u32);
	// bl 0x82a127e0
	ctx.lr = 0x82A7FB98;
	SetFilePointer(ctx, base);
	// stw r3,124(r31)
	REX_STORE_U32(r31.u32 + 124, ctx.r3.u32);
loc_82A7FB9C:
	// lis r5,-32088
	ctx.r5.s64 = -2102919168;
	// lis r6,-32088
	ctx.r6.s64 = -2102919168;
	// lis r7,-32088
	ctx.r7.s64 = -2102919168;
	// lis r8,-32088
	ctx.r8.s64 = -2102919168;
	// lis r9,-32088
	ctx.r9.s64 = -2102919168;
	// lis r10,-32088
	ctx.r10.s64 = -2102919168;
	// lis r11,-32088
	ctx.r11.s64 = -2102919168;
	// addi r5,r5,-3640
	ctx.r5.s64 = ctx.r5.s64 + -3640;
	// addi r6,r6,-3224
	ctx.r6.s64 = ctx.r6.s64 + -3224;
	// addi r7,r7,-2304
	ctx.r7.s64 = ctx.r7.s64 + -2304;
	// addi r8,r8,-2264
	ctx.r8.s64 = ctx.r8.s64 + -2264;
	// addi r9,r9,-2016
	ctx.r9.s64 = ctx.r9.s64 + -2016;
	// addi r10,r10,-2120
	ctx.r10.s64 = ctx.r10.s64 + -2120;
	// stw r5,0(r31)
	REX_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r11,r11,-1400
	ctx.r11.s64 = ctx.r11.s64 + -1400;
	// stw r6,4(r31)
	REX_STORE_U32(r31.u32 + 4, ctx.r6.u32);
	// stw r7,8(r31)
	REX_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,12(r31)
	REX_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// stw r9,16(r31)
	REX_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// stw r10,20(r31)
	REX_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// stw r11,24(r31)
	REX_STORE_U32(r31.u32 + 24, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x829ff81c
	return;
loc_82A7FBFC:
	// lis r8,2048
	ctx.r8.s64 = 134217728;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r8,r8,128
	ctx.r8.u64 = ctx.r8.u64 | 128;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// bl 0x82a131b0
	ctx.lr = 0x82A7FC1C;
	CreateFileA(ctx, base);
	// stw r3,84(r31)
	REX_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(ctx.r11.s32, -1, xer);
	// bne cr6,0x82a7fb9c
	if (!cr6.eq) goto loc_82A7FB9C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x829ff81c
	return;
}

DEFINE_REX_FUNC(sub_82A7FC38) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c8
	ctx.lr = 0x82A7FC40;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x82a01320
	ctx.lr = 0x82A7FC48;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// stw r11,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// ble cr6,0x82a7fe48
	if (!cr6.gt) goto loc_82A7FE48;
	// srawi r31,r3,1
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	r31.s64 = ctx.r3.s32 >> 1;
	// extsw r11,r31
	ctx.r11.s64 = r31.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lfs f13,-30204(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30204);
	ctx.f13.f64 = double(temp.f32);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fdivs f30,f13,f0
	f30.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(ctx.f0.f64 * f30.f64));
	// bl 0x829ffe18
	ctx.lr = 0x82A7FC90;
	sub_829FFE18(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// frsp f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = double(float(ctx.f1.f64));
	// stfs f26,4(r30)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(r30.u32 + 4, temp.u32);
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// lfs f27,3400(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3400);
	f27.f64 = double(temp.f32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stfs f27,0(r30)
	temp.f32 = float(f27.f64);
	REX_STORE_U32(r30.u32 + 0, temp.u32);
	// lfs f28,3444(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3444);
	f28.f64 = double(temp.f32);
	// blt cr6,0x82a7fcf0
	if (cr6.lt) goto loc_82A7FCF0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,3528(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3528);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f30,f0
	ctx.f1.f64 = double(float(f30.f64 * ctx.f0.f64));
	// bl 0x829ffe18
	ctx.lr = 0x82A7FCC4;
	sub_829FFE18(ctx, base);
	// fmr f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f1.f64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,26808(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26808);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f30,f0
	ctx.f1.f64 = double(float(f30.f64 * ctx.f0.f64));
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// fdivs f0,f28,f0
	ctx.f0.f64 = double(float(f28.f64 / ctx.f0.f64));
	// stfs f0,8(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r30.u32 + 8, temp.u32);
	// bl 0x829ffe18
	ctx.lr = 0x82A7FCE4;
	sub_829FFE18(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fdivs f0,f28,f0
	ctx.f0.f64 = double(float(f28.f64 / ctx.f0.f64));
	// stfs f0,12(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r30.u32 + 12, temp.u32);
loc_82A7FCF0:
	// li r28,4
	r28.s64 = 4;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// ble cr6,0x82a7fd7c
	if (!cr6.gt) goto loc_82A7FD7C;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addi r29,r30,24
	r29.s64 = r30.s64 + 24;
	// lfs f29,-26300(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26300);
	f29.f64 = double(temp.f32);
loc_82A7FD08:
	// extsw r11,r28
	ctx.r11.s64 = r28.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f31,f0,f30
	f31.f64 = double(float(ctx.f0.f64 * f30.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x829ffe18
	ctx.lr = 0x82A7FD28;
	sub_829FFE18(ctx, base);
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,-8(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r29.u32 + -8, temp.u32);
	// bl 0x829ffd48
	ctx.lr = 0x82A7FD3C;
	sub_829FFD48(ctx, base);
	// fmuls f31,f31,f29
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(f31.f64 * f29.f64));
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,-4(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r29.u32 + -4, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x829ffe18
	ctx.lr = 0x82A7FD50;
	sub_829FFE18(ctx, base);
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r29.u32 + 0, temp.u32);
	// bl 0x829ffd48
	ctx.lr = 0x82A7FD64;
	sub_829FFD48(ctx, base);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,4(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r29.u32 + 4, temp.u32);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// cmpw cr6,r28,r31
	cr6.compare<int32_t>(r28.s32, r31.s32, xer);
	// blt cr6,0x82a7fd08
	if (cr6.lt) goto loc_82A7FD08;
loc_82A7FD7C:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// ble cr6,0x82a7fe48
	if (!cr6.gt) goto loc_82A7FE48;
loc_82A7FD88:
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + r31.u64;
	// srawi r31,r31,1
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1) != 0);
	r31.s64 = r31.s32 >> 1;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// stfs f27,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f26,4(r10)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// blt cr6,0x82a7fe3c
	if (cr6.lt) goto loc_82A7FE3C;
	// addi r10,r11,6
	ctx.r10.s64 = ctx.r11.s64 + 6;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r8,2
	ctx.r7.s64 = ctx.r8.s64 + 2;
	// addi r6,r8,3
	ctx.r6.s64 = ctx.r8.s64 + 3;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r10,r30
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r30
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + r30.u32);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f28,f0
	ctx.f0.f64 = double(float(f28.f64 / ctx.f0.f64));
	// fdivs f13,f28,f13
	ctx.f13.f64 = double(float(f28.f64 / ctx.f13.f64));
	// stfsx f13,r7,r30
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r7.u32 + r30.u32, temp.u32);
	// stfsx f0,r10,r30
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + r30.u32, temp.u32);
	// ble cr6,0x82a7fe3c
	if (!cr6.gt) goto loc_82A7FE3C;
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// addi r10,r8,4
	ctx.r10.s64 = ctx.r8.s64 + 4;
	// addi r9,r31,-5
	ctx.r9.s64 = r31.s64 + -5;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + r30.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_82A7FE08:
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f11,-8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f0,4(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f13,8(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// stfs f12,12(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne cr6,0x82a7fe08
	if (!cr6.eq) goto loc_82A7FE08;
loc_82A7FE3C:
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bgt cr6,0x82a7fd88
	if (cr6.gt) goto loc_82A7FD88;
loc_82A7FE48:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x82a0136c
	ctx.lr = 0x82A7FE54;
	// b 0x829ff818
	return;
}

DEFINE_REX_FUNC(sub_82A7FE58) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c8
	ctx.lr = 0x82A7FE60;
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, f29.u64);
	// stfd f30,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// stw r30,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, r30.u32);
	// ble cr6,0x82a7ff40
	if (!cr6.gt) goto loc_82A7FF40;
	// srawi r28,r30,1
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1) != 0);
	r28.s64 = r30.s32 >> 1;
	// extsw r11,r28
	ctx.r11.s64 = r28.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lfs f13,-30204(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30204);
	ctx.f13.f64 = double(temp.f32);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fdivs f29,f13,f0
	f29.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// fmuls f1,f0,f29
	ctx.f1.f64 = double(float(ctx.f0.f64 * f29.f64));
	// bl 0x829ffe18
	ctx.lr = 0x82A7FEB0;
	sub_829FFE18(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r29.u32 + 0, temp.u32);
	// li r31,1
	r31.s64 = 1;
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// lfs f31,3444(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3444);
	f31.f64 = double(temp.f32);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * f31.f64));
	// stfsx f0,r10,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + r29.u32, temp.u32);
	// ble cr6,0x82a7ff40
	if (!cr6.gt) goto loc_82A7FF40;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r29,4
	r30.s64 = r29.s64 + 4;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + r29.u64;
	// addi r29,r11,-4
	r29.s64 = ctx.r11.s64 + -4;
loc_82A7FEE8:
	// extsw r11,r31
	ctx.r11.s64 = r31.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f30,f0,f29
	f30.f64 = double(float(ctx.f0.f64 * f29.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x829ffe18
	ctx.lr = 0x82A7FF08;
	sub_829FFE18(ctx, base);
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * f31.f64));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r30.u32 + 0, temp.u32);
	// bl 0x829ffd48
	ctx.lr = 0x82A7FF20;
	sub_829FFD48(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * f31.f64));
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r29,r29,-4
	r29.s64 = r29.s64 + -4;
	// blt cr6,0x82a7fee8
	if (cr6.lt) goto loc_82A7FEE8;
loc_82A7FF40:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x829ff818
	return;
}

DEFINE_REX_FUNC(sub_82A7FF58) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7b4
	ctx.lr = 0x82A7FF60;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r23,1
	r23.s64 = 1;
	// cmpwi cr6,r7,8
	cr6.compare<int32_t>(ctx.r7.s32, 8, xer);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// ble cr6,0x82a7ffc4
	if (!cr6.gt) goto loc_82A7FFC4;
loc_82A7FF78:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// srawi r7,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 1;
	// ble cr6,0x82a7ffb4
	if (!cr6.gt) goto loc_82A7FFB4;
	// rlwinm r11,r23,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// mr r11,r23
	ctx.r11.u64 = r23.u64;
loc_82A7FF94:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne cr6,0x82a7ff94
	if (!cr6.eq) goto loc_82A7FF94;
loc_82A7FFB4:
	// rlwinm r23,r23,1,0,30
	r23.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r23,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 3) & 0xFFFFFFF8;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x82a7ff78
	if (cr6.lt) goto loc_82A7FF78;
loc_82A7FFC4:
	// rlwinm r10,r23,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r11,r23,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// bne cr6,0x82a80154
	if (!cr6.eq) goto loc_82A80154;
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x82a80444
	if (!cr6.gt) goto loc_82A80444;
	// li r25,0
	r25.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
loc_82A7FFE8:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x82a800fc
	if (!cr6.gt) goto loc_82A800FC;
	// rlwinm r30,r11,1,0,30
	r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
loc_82A80000:
	// lwz r9,0(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(r26.u32 + 0);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// add r3,r25,r9
	ctx.r3.u64 = r25.u64 + ctx.r9.u64;
	// add r31,r6,r10
	r31.u64 = ctx.r6.u64 + ctx.r10.u64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r3,r30,r3
	ctx.r3.u64 = r30.u64 + ctx.r3.u64;
	// add r31,r31,r11
	r31.u64 = r31.u64 + ctx.r11.u64;
	// rlwinm r28,r3,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r29,r31,2,0,29
	r29.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// subf r3,r11,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r11.u64;
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// add r31,r31,r11
	r31.u64 = r31.u64 + ctx.r11.u64;
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r27,r3,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// add r3,r30,r3
	ctx.r3.u64 = r30.u64 + ctx.r3.u64;
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// add r9,r29,r5
	ctx.r9.u64 = r29.u64 + ctx.r5.u64;
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// rlwinm r29,r3,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// add r10,r28,r5
	ctx.r10.u64 = r28.u64 + ctx.r5.u64;
	// rlwinm r28,r31,2,0,29
	r28.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r31,r11
	r31.u64 = r31.u64 + ctx.r11.u64;
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r6,2
	ctx.r6.s64 = ctx.r6.s64 + 2;
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// add r9,r28,r5
	ctx.r9.u64 = r28.u64 + ctx.r5.u64;
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// add r10,r27,r5
	ctx.r10.u64 = r27.u64 + ctx.r5.u64;
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// add r9,r3,r5
	ctx.r9.u64 = ctx.r3.u64 + ctx.r5.u64;
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// add r10,r29,r5
	ctx.r10.u64 = r29.u64 + ctx.r5.u64;
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// bne cr6,0x82a80000
	if (!cr6.eq) goto loc_82A80000;
loc_82A800FC:
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(r26.u32 + 0);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// add r10,r25,r10
	ctx.r10.u64 = r25.u64 + ctx.r10.u64;
	// addi r25,r25,2
	r25.s64 = r25.s64 + 2;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpw cr6,r24,r23
	cr6.compare<int32_t>(r24.s32, r23.s32, xer);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,0(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f13,4(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// blt cr6,0x82a7ffe8
	if (cr6.lt) goto loc_82A7FFE8;
	// b 0x829ff804
	return;
loc_82A80154:
	// li r25,1
	r25.s64 = 1;
	// cmpwi cr6,r23,1
	cr6.compare<int32_t>(r23.s32, 1, xer);
	// ble cr6,0x82a80444
	if (!cr6.gt) goto loc_82A80444;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r6,r4,4
	ctx.r6.s64 = ctx.r4.s64 + 4;
loc_82A80168:
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r25,4
	cr6.compare<int32_t>(r25.s32, 4, xer);
	// blt cr6,0x82a8038c
	if (cr6.lt) goto loc_82A8038C;
	// addi r10,r25,-4
	ctx.r10.s64 = r25.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r8,r10,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// addi r31,r8,1
	r31.s64 = ctx.r8.s64 + 1;
	// rlwinm r26,r31,2,0,29
	r26.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
loc_82A8018C:
	// lwz r7,-8(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + -8);
	// lwz r8,0(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// add r30,r7,r3
	r30.u64 = ctx.r7.u64 + ctx.r3.u64;
	// add r29,r8,r9
	r29.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r29,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// add r30,r30,r11
	r30.u64 = r30.u64 + ctx.r11.u64;
	// add r29,r29,r11
	r29.u64 = r29.u64 + ctx.r11.u64;
	// rlwinm r28,r30,2,0,29
	r28.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r30,r29,2,0,29
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// add r7,r30,r5
	ctx.r7.u64 = r30.u64 + ctx.r5.u64;
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// add r8,r28,r5
	ctx.r8.u64 = r28.u64 + ctx.r5.u64;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lwz r8,0(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r7,-4(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + -4);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r30,r7,r3
	r30.u64 = ctx.r7.u64 + ctx.r3.u64;
	// addi r29,r8,2
	r29.s64 = ctx.r8.s64 + 2;
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r29,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// add r30,r30,r11
	r30.u64 = r30.u64 + ctx.r11.u64;
	// add r29,r29,r11
	r29.u64 = r29.u64 + ctx.r11.u64;
	// rlwinm r28,r30,2,0,29
	r28.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r30,r29,2,0,29
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// add r7,r30,r5
	ctx.r7.u64 = r30.u64 + ctx.r5.u64;
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r30,r9,6
	r30.s64 = ctx.r9.s64 + 6;
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// add r8,r28,r5
	ctx.r8.u64 = r28.u64 + ctx.r5.u64;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lwz r7,0(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// add r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 + r30.u64;
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// addi r7,r7,-2
	ctx.r7.s64 = ctx.r7.s64 + -2;
	// rlwinm r28,r8,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r8,r11
	r29.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r27,r7,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r28,r5
	ctx.r8.u64 = r28.u64 + ctx.r5.u64;
	// add r28,r7,r11
	r28.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r7,r27,r5
	ctx.r7.u64 = r27.u64 + ctx.r5.u64;
	// rlwinm r29,r29,2,0,29
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r28,2,0,29
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// add r7,r28,r5
	ctx.r7.u64 = r28.u64 + ctx.r5.u64;
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// add r8,r29,r5
	ctx.r8.u64 = r29.u64 + ctx.r5.u64;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lfs f0,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f12,4(r7)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f0,0(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f13,4(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lwz r7,4(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,0(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// add r29,r7,r3
	r29.u64 = ctx.r7.u64 + ctx.r3.u64;
	// add r30,r8,r30
	r30.u64 = ctx.r8.u64 + r30.u64;
	// rlwinm r8,r29,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// add r29,r29,r11
	r29.u64 = r29.u64 + ctx.r11.u64;
	// add r30,r30,r11
	r30.u64 = r30.u64 + ctx.r11.u64;
	// rlwinm r29,r29,2,0,29
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r30,r30,2,0,29
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// add r7,r30,r5
	ctx.r7.u64 = r30.u64 + ctx.r5.u64;
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// add r8,r29,r5
	ctx.r8.u64 = r29.u64 + ctx.r5.u64;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// bne cr6,0x82a8018c
	if (!cr6.eq) goto loc_82A8018C;
loc_82A8038C:
	// cmpw cr6,r26,r25
	cr6.compare<int32_t>(r26.s32, r25.s32, xer);
	// bge cr6,0x82a80430
	if (!cr6.lt) goto loc_82A80430;
	// rlwinm r10,r26,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r31,r26,1,0,30
	r31.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r4
	ctx.r7.u64 = ctx.r10.u64 + ctx.r4.u64;
	// subf r8,r26,r25
	ctx.r8.u64 = r25.u64 - r26.u64;
loc_82A803A4:
	// lwz r9,0(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// lwz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// add r30,r3,r9
	r30.u64 = ctx.r3.u64 + ctx.r9.u64;
	// add r29,r10,r31
	r29.u64 = ctx.r10.u64 + r31.u64;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r29,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r30,r30,r11
	r30.u64 = r30.u64 + ctx.r11.u64;
	// add r29,r29,r11
	r29.u64 = r29.u64 + ctx.r11.u64;
	// rlwinm r28,r30,2,0,29
	r28.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r30,r29,2,0,29
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// add r9,r30,r5
	ctx.r9.u64 = r30.u64 + ctx.r5.u64;
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// add r10,r28,r5
	ctx.r10.u64 = r28.u64 + ctx.r5.u64;
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// bne cr6,0x82a803a4
	if (!cr6.eq) goto loc_82A803A4;
loc_82A80430:
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// cmpw cr6,r25,r23
	cr6.compare<int32_t>(r25.s32, r23.s32, xer);
	// blt cr6,0x82a80168
	if (cr6.lt) goto loc_82A80168;
loc_82A80444:
	// b 0x829ff804
	return;
}

DEFINE_REX_FUNC(sub_82A80448) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7b4
	ctx.lr = 0x82A80450;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r23,1
	r23.s64 = 1;
	// cmpwi cr6,r7,8
	cr6.compare<int32_t>(ctx.r7.s32, 8, xer);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// ble cr6,0x82a804b4
	if (!cr6.gt) goto loc_82A804B4;
loc_82A80468:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// srawi r7,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 1;
	// ble cr6,0x82a804a4
	if (!cr6.gt) goto loc_82A804A4;
	// rlwinm r11,r23,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// mr r11,r23
	ctx.r11.u64 = r23.u64;
loc_82A80484:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne cr6,0x82a80484
	if (!cr6.eq) goto loc_82A80484;
loc_82A804A4:
	// rlwinm r23,r23,1,0,30
	r23.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r23,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 3) & 0xFFFFFFF8;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x82a80468
	if (cr6.lt) goto loc_82A80468;
loc_82A804B4:
	// rlwinm r10,r23,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r11,r23,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// bne cr6,0x82a80698
	if (!cr6.eq) goto loc_82A80698;
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x82a80a2c
	if (!cr6.gt) goto loc_82A80A2C;
	// li r25,0
	r25.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
loc_82A804D8:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x82a8060c
	if (!cr6.gt) goto loc_82A8060C;
	// rlwinm r30,r11,1,0,30
	r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
loc_82A804F0:
	// lwz r9,0(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(r26.u32 + 0);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// add r3,r9,r25
	ctx.r3.u64 = ctx.r9.u64 + r25.u64;
	// add r31,r10,r7
	r31.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r3,r30,r3
	ctx.r3.u64 = r30.u64 + ctx.r3.u64;
	// add r31,r31,r11
	r31.u64 = r31.u64 + ctx.r11.u64;
	// rlwinm r28,r3,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r29,r31,2,0,29
	r29.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// subf r3,r11,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r11.u64;
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// add r31,r31,r11
	r31.u64 = r31.u64 + ctx.r11.u64;
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// add r9,r29,r5
	ctx.r9.u64 = r29.u64 + ctx.r5.u64;
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// rlwinm r27,r3,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// add r10,r28,r5
	ctx.r10.u64 = r28.u64 + ctx.r5.u64;
	// rlwinm r28,r31,2,0,29
	r28.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r30,r3
	ctx.r3.u64 = r30.u64 + ctx.r3.u64;
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// add r31,r31,r11
	r31.u64 = r31.u64 + ctx.r11.u64;
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r29,r3,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// add r9,r28,r5
	ctx.r9.u64 = r28.u64 + ctx.r5.u64;
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// addi r7,r7,2
	ctx.r7.s64 = ctx.r7.s64 + 2;
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// add r10,r27,r5
	ctx.r10.u64 = r27.u64 + ctx.r5.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// add r9,r3,r5
	ctx.r9.u64 = ctx.r3.u64 + ctx.r5.u64;
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// add r10,r29,r5
	ctx.r10.u64 = r29.u64 + ctx.r5.u64;
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// bne cr6,0x82a804f0
	if (!cr6.eq) goto loc_82A804F0;
loc_82A8060C:
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(r26.u32 + 0);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + r25.u64;
	// addi r25,r25,2
	r25.s64 = r25.s64 + 2;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// lfsx f0,r7,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfsx f0,r7,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + ctx.r5.u32, temp.u32);
	// cmpw cr6,r24,r23
	cr6.compare<int32_t>(r24.s32, r23.s32, xer);
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// lfs f11,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,0(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f13,4(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// lfsx f0,r8,r5
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	ctx.f0.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfsx f0,r8,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + ctx.r5.u32, temp.u32);
	// blt cr6,0x82a804d8
	if (cr6.lt) goto loc_82A804D8;
	// b 0x829ff804
	return;
loc_82A80698:
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,4(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r25,1
	r25.s64 = 1;
	// cmpwi cr6,r23,1
	cr6.compare<int32_t>(r23.s32, 1, xer);
	// lfsx f0,r10,r5
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	ctx.f0.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfsx f0,r10,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r5.u32, temp.u32);
	// ble cr6,0x82a80a2c
	if (!cr6.gt) goto loc_82A80A2C;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r6,r4,4
	ctx.r6.s64 = ctx.r4.s64 + 4;
loc_82A806CC:
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r25,4
	cr6.compare<int32_t>(r25.s32, 4, xer);
	// blt cr6,0x82a80930
	if (cr6.lt) goto loc_82A80930;
	// addi r10,r25,-4
	ctx.r10.s64 = r25.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r8,r10,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// addi r31,r8,1
	r31.s64 = ctx.r8.s64 + 1;
	// rlwinm r26,r31,2,0,29
	r26.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
loc_82A806F0:
	// lwz r7,-8(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + -8);
	// lwz r8,0(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// add r30,r7,r3
	r30.u64 = ctx.r7.u64 + ctx.r3.u64;
	// add r29,r9,r8
	r29.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r29,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// add r30,r30,r11
	r30.u64 = r30.u64 + ctx.r11.u64;
	// add r29,r29,r11
	r29.u64 = r29.u64 + ctx.r11.u64;
	// rlwinm r28,r30,2,0,29
	r28.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r30,r29,2,0,29
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// add r7,r30,r5
	ctx.r7.u64 = r30.u64 + ctx.r5.u64;
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// add r8,r28,r5
	ctx.r8.u64 = r28.u64 + ctx.r5.u64;
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lwz r8,0(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r7,-4(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + -4);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r30,r7,r3
	r30.u64 = ctx.r7.u64 + ctx.r3.u64;
	// addi r29,r8,2
	r29.s64 = ctx.r8.s64 + 2;
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r29,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// add r30,r30,r11
	r30.u64 = r30.u64 + ctx.r11.u64;
	// add r29,r29,r11
	r29.u64 = r29.u64 + ctx.r11.u64;
	// rlwinm r30,r30,2,0,29
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r29,r29,2,0,29
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// add r7,r30,r5
	ctx.r7.u64 = r30.u64 + ctx.r5.u64;
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r30,r9,6
	r30.s64 = ctx.r9.s64 + 6;
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// add r8,r29,r5
	ctx.r8.u64 = r29.u64 + ctx.r5.u64;
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f11,0(r8)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// stfs f13,0(r7)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// lwz r7,0(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// add r7,r30,r7
	ctx.r7.u64 = r30.u64 + ctx.r7.u64;
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// addi r7,r7,-2
	ctx.r7.s64 = ctx.r7.s64 + -2;
	// rlwinm r28,r8,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r8,r11
	r29.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r27,r7,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r28,r5
	ctx.r8.u64 = r28.u64 + ctx.r5.u64;
	// add r28,r7,r11
	r28.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r7,r27,r5
	ctx.r7.u64 = r27.u64 + ctx.r5.u64;
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r29,r29,2,0,29
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r28,r28,2,0,29
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// add r7,r28,r5
	ctx.r7.u64 = r28.u64 + ctx.r5.u64;
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// add r8,r29,r5
	ctx.r8.u64 = r29.u64 + ctx.r5.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lfs f13,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// lfs f12,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f12,4(r7)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f0,0(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f13,4(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lwz r7,4(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,0(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// add r29,r7,r3
	r29.u64 = ctx.r7.u64 + ctx.r3.u64;
	// add r30,r30,r8
	r30.u64 = r30.u64 + ctx.r8.u64;
	// rlwinm r8,r29,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// add r29,r29,r11
	r29.u64 = r29.u64 + ctx.r11.u64;
	// add r30,r30,r11
	r30.u64 = r30.u64 + ctx.r11.u64;
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r30,r30,2,0,29
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f12,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// add r7,r30,r5
	ctx.r7.u64 = r30.u64 + ctx.r5.u64;
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f12,4(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// rlwinm r8,r29,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// lfs f13,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// lfs f12,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f12,4(r7)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f0,0(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f13,4(r8)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// bne cr6,0x82a806f0
	if (!cr6.eq) goto loc_82A806F0;
loc_82A80930:
	// cmpw cr6,r26,r25
	cr6.compare<int32_t>(r26.s32, r25.s32, xer);
	// bge cr6,0x82a809e4
	if (!cr6.lt) goto loc_82A809E4;
	// rlwinm r10,r26,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r31,r26,1,0,30
	r31.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r4
	ctx.r7.u64 = ctx.r10.u64 + ctx.r4.u64;
	// subf r8,r26,r25
	ctx.r8.u64 = r25.u64 - r26.u64;
loc_82A80948:
	// lwz r9,0(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// lwz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// add r30,r3,r9
	r30.u64 = ctx.r3.u64 + ctx.r9.u64;
	// add r29,r31,r10
	r29.u64 = r31.u64 + ctx.r10.u64;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r29,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r30,r30,r11
	r30.u64 = r30.u64 + ctx.r11.u64;
	// add r29,r29,r11
	r29.u64 = r29.u64 + ctx.r11.u64;
	// rlwinm r28,r30,2,0,29
	r28.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r30,r29,2,0,29
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// add r9,r30,r5
	ctx.r9.u64 = r30.u64 + ctx.r5.u64;
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// add r10,r28,r5
	ctx.r10.u64 = r28.u64 + ctx.r5.u64;
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// bne cr6,0x82a80948
	if (!cr6.eq) goto loc_82A80948;
loc_82A809E4:
	// lwz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r25,r23
	cr6.compare<int32_t>(r25.s32, r23.s32, xer);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r9,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	ctx.f0.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfsx f0,r9,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r5.u32, temp.u32);
	// lfsx f0,r10,r5
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	ctx.f0.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfsx f0,r10,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r5.u32, temp.u32);
	// blt cr6,0x82a806cc
	if (cr6.lt) goto loc_82A806CC;
loc_82A80A2C:
	// b 0x829ff804
	return;
}

DEFINE_REX_FUNC(sub_82A80A30) {
	REX_FUNC_PROLOGUE();
	PPCRegister f17{};
	PPCRegister f18{};
	PPCRegister f19{};
	PPCRegister f20{};
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82a012fc
	ctx.lr = 0x82A80A40;
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f2,64(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 64);
	ctx.f2.f64 = double(temp.f32);
	// stfs f0,64(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// lfs f13,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,28(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,40(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// lfs f27,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	f27.f64 = double(temp.f32);
	// lfs f26,60(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 60);
	f26.f64 = double(temp.f32);
	// lfs f25,72(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 72);
	f25.f64 = double(temp.f32);
	// lfs f8,16(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,32(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,36(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,48(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,52(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,68(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f1.f64 = double(temp.f32);
	// lfs f24,120(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 120);
	f24.f64 = double(temp.f32);
	// lfs f23,124(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 124);
	f23.f64 = double(temp.f32);
	// lfs f22,88(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 88);
	f22.f64 = double(temp.f32);
	// lfs f21,92(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 92);
	f21.f64 = double(temp.f32);
	// lfs f20,104(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 104);
	f20.f64 = double(temp.f32);
	// lfs f19,108(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 108);
	f19.f64 = double(temp.f32);
	// lfs f18,76(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 76);
	f18.f64 = double(temp.f32);
	// lfs f17,112(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 112);
	f17.f64 = double(temp.f32);
	// lfs f31,80(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 80);
	f31.f64 = double(temp.f32);
	// lfs f30,84(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 84);
	f30.f64 = double(temp.f32);
	// lfs f29,96(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 96);
	f29.f64 = double(temp.f32);
	// lfs f28,100(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 100);
	f28.f64 = double(temp.f32);
	// lfs f0,116(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f24,8(r3)
	temp.f32 = float(f24.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f23,12(r3)
	temp.f32 = float(f23.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f27,16(r3)
	temp.f32 = float(f27.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f26,20(r3)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f22,24(r3)
	temp.f32 = float(f22.f64);
	REX_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f21,28(r3)
	temp.f32 = float(f21.f64);
	REX_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f20,40(r3)
	temp.f32 = float(f20.f64);
	REX_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f19,44(r3)
	temp.f32 = float(f19.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f25,56(r3)
	temp.f32 = float(f25.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f18,60(r3)
	temp.f32 = float(f18.f64);
	REX_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f17,72(r3)
	temp.f32 = float(f17.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f13,68(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f12,32(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f11,36(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f10,48(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f9,52(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f0,76(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f4,80(r3)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f3,84(r3)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f31,88(r3)
	temp.f32 = float(f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f30,92(r3)
	temp.f32 = float(f30.f64);
	REX_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// stfs f8,96(r3)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stfs f7,100(r3)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stfs f29,104(r3)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stfs f28,108(r3)
	temp.f32 = float(f28.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stfs f6,112(r3)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// stfs f5,116(r3)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// stfs f2,120(r3)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// stfs f1,124(r3)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82a01348
	ctx.lr = 0x82A80B38;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A80B48) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f14{};
	PPCRegister f15{};
	PPCRegister f16{};
	PPCRegister f17{};
	PPCRegister f18{};
	PPCRegister f19{};
	PPCRegister f20{};
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7bc
	ctx.lr = 0x82A80B50;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x82a012f0
	ctx.lr = 0x82A80B58;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f10,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// srawi r29,r3,3
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	r29.s64 = ctx.r3.s32 >> 3;
	// lfs f9,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r30,r5,8
	r30.s64 = ctx.r5.s64 + 8;
	// addi r27,r29,-2
	r27.s64 = r29.s64 + -2;
	// lfs f0,3400(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3400);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmr f12,f0
	ctx.f12.f64 = ctx.f0.f64;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// lfs f13,2612(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2612);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lfs f6,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fadds f2,f10,f6
	ctx.f2.f64 = double(float(ctx.f10.f64 + ctx.f6.f64));
	// lfs f4,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f10,f10,f6
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f6.f64));
	// lfs f8,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fadds f1,f9,f5
	ctx.f1.f64 = double(float(ctx.f9.f64 + ctx.f5.f64));
	// lfs f7,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fadds f6,f8,f4
	ctx.f6.f64 = double(float(ctx.f8.f64 + ctx.f4.f64));
	// lfs f3,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f9,f9,f5
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f5.f64));
	// fadds f5,f7,f3
	ctx.f5.f64 = double(float(ctx.f7.f64 + ctx.f3.f64));
	// fsubs f7,f7,f3
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f3.f64));
	// fsubs f8,f8,f4
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f4.f64));
	// fadds f4,f6,f2
	ctx.f4.f64 = double(float(ctx.f6.f64 + ctx.f2.f64));
	// stfs f4,0(r4)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fsubs f6,f2,f6
	ctx.f6.f64 = double(float(ctx.f2.f64 - ctx.f6.f64));
	// fadds f4,f5,f1
	ctx.f4.f64 = double(float(ctx.f5.f64 + ctx.f1.f64));
	// stfs f4,4(r4)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// stfs f6,0(r10)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fsubs f6,f1,f5
	ctx.f6.f64 = double(float(ctx.f1.f64 - ctx.f5.f64));
	// stfs f6,4(r10)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fsubs f6,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 - ctx.f7.f64));
	// stfs f6,0(r9)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fadds f6,f8,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// stfs f6,4(r9)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fadds f10,f7,f10
	ctx.f10.f64 = double(float(ctx.f7.f64 + ctx.f10.f64));
	// stfs f10,0(r8)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fsubs f10,f9,f8
	ctx.f10.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// stfs f10,4(r8)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lfs f10,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f15,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	f15.f64 = double(temp.f32);
	// lfs f14,12(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 12);
	f14.f64 = double(temp.f32);
	// stfs f10,-224(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -224, temp.u32);
	// ble cr6,0x82a80fb4
	if (!cr6.gt) goto loc_82A80FB4;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// addi r5,r11,-2
	ctx.r5.s64 = ctx.r11.s64 + -2;
	// rlwinm r3,r9,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r31,r27,-3
	r31.s64 = r27.s64 + -3;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r7,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r5,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r10,r4
	ctx.r7.u64 = ctx.r10.u64 + ctx.r4.u64;
	// rlwinm r5,r31,30,2,31
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 30) & 0x3FFFFFFF;
	// add r31,r3,r4
	r31.u64 = ctx.r3.u64 + ctx.r4.u64;
	// add r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 + ctx.r4.u64;
	// addi r6,r7,-16
	ctx.r6.s64 = ctx.r7.s64 + -16;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r28,r5,1
	r28.s64 = ctx.r5.s64 + 1;
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r4,16
	ctx.r10.s64 = ctx.r4.s64 + 16;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 + ctx.r4.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// addi r5,r7,16
	ctx.r5.s64 = ctx.r7.s64 + 16;
	// addi r7,r7,-16
	ctx.r7.s64 = ctx.r7.s64 + -16;
loc_82A80C9C:
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// lfs f10,-8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + -8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,-8(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,-4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -4);
	ctx.f6.f64 = double(temp.f32);
	// fadds f23,f8,f10
	f23.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// lfs f5,-4(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + -4);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f19,f8,f10
	f19.f64 = double(float(ctx.f8.f64 - ctx.f10.f64));
	// lfs f9,-8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -8);
	ctx.f9.f64 = double(temp.f32);
	// fadds f8,f5,f6
	ctx.f8.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// lfs f7,-8(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + -8);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f18,f5,f6
	f18.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// lfs f4,-4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + -4);
	ctx.f4.f64 = double(temp.f32);
	// fadds f21,f7,f9
	f21.f64 = double(float(ctx.f7.f64 + ctx.f9.f64));
	// lfs f3,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f9.f64));
	// lfs f30,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	f30.f64 = double(temp.f32);
	// lfs f29,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	f29.f64 = double(temp.f32);
	// fadds f9,f30,f4
	ctx.f9.f64 = double(float(f30.f64 + ctx.f4.f64));
	// lfs f24,-4(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + -4);
	f24.f64 = double(temp.f32);
	// fadds f7,f3,f29
	ctx.f7.f64 = double(float(ctx.f3.f64 + f29.f64));
	// lfs f1,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f3,f29,f3
	ctx.f3.f64 = double(float(f29.f64 - ctx.f3.f64));
	// lfs f27,0(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 0);
	f27.f64 = double(temp.f32);
	// fadds f29,f24,f13
	f29.f64 = double(float(f24.f64 + ctx.f13.f64));
	// lfs f31,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	f31.f64 = double(temp.f32);
	// fadds f17,f27,f1
	f17.f64 = double(float(f27.f64 + ctx.f1.f64));
	// lfs f2,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f4,f30,f4
	ctx.f4.f64 = double(float(f30.f64 - ctx.f4.f64));
	// lfs f28,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	f28.f64 = double(temp.f32);
	// fsubs f30,f19,f18
	f30.f64 = double(float(f19.f64 - f18.f64));
	// lfs f26,4(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 4);
	f26.f64 = double(temp.f32);
	// fadds f5,f28,f2
	ctx.f5.f64 = double(float(f28.f64 + ctx.f2.f64));
	// fadds f16,f26,f31
	f16.f64 = double(float(f26.f64 + f31.f64));
	// lfs f25,-8(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + -8);
	f25.f64 = double(temp.f32);
	// fsubs f31,f26,f31
	f31.f64 = double(float(f26.f64 - f31.f64));
	// lfs f22,0(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 0);
	f22.f64 = double(temp.f32);
	// fadds f26,f8,f9
	f26.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// lfs f20,4(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 4);
	f20.f64 = double(temp.f32);
	// fsubs f8,f9,f8
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// stfs f26,-4(r10)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r10.u32 + -4, temp.u32);
	// fadds f10,f25,f0
	ctx.f10.f64 = double(float(f25.f64 + ctx.f0.f64));
	// fmuls f9,f29,f15
	ctx.f9.f64 = double(float(f29.f64 * f15.f64));
	// fadds f29,f17,f7
	f29.f64 = double(float(f17.f64 + ctx.f7.f64));
	// stfs f29,0(r10)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fadds f0,f21,f23
	ctx.f0.f64 = double(float(f21.f64 + f23.f64));
	// stfs f0,-8(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -8, temp.u32);
	// fsubs f2,f28,f2
	ctx.f2.f64 = double(float(f28.f64 - ctx.f2.f64));
	// fadds f28,f22,f12
	f28.f64 = double(float(f22.f64 + ctx.f12.f64));
	// fadds f29,f16,f5
	f29.f64 = double(float(f16.f64 + ctx.f5.f64));
	// stfs f29,4(r10)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fsubs f5,f5,f16
	ctx.f5.f64 = double(float(ctx.f5.f64 - f16.f64));
	// stfs f5,4(r31)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(r31.u32 + 4, temp.u32);
	// fadds f5,f6,f4
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f4.f64));
	// stfs f8,-4(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(r31.u32 + -4, temp.u32);
	// fsubs f1,f27,f1
	ctx.f1.f64 = double(float(f27.f64 - ctx.f1.f64));
	// fsubs f27,f23,f21
	f27.f64 = double(float(f23.f64 - f21.f64));
	// stfs f27,-8(r31)
	temp.f32 = float(f27.f64);
	REX_STORE_U32(r31.u32 + -8, temp.u32);
	// fmuls f10,f10,f15
	ctx.f10.f64 = double(float(ctx.f10.f64 * f15.f64));
	// fmr f29,f30
	f29.f64 = f30.f64;
	// fmuls f26,f9,f30
	f26.f64 = double(float(ctx.f9.f64 * f30.f64));
	// fsubs f11,f11,f20
	ctx.f11.f64 = double(float(ctx.f11.f64 - f20.f64));
	// fmuls f8,f28,f14
	ctx.f8.f64 = double(float(f28.f64 * f14.f64));
	// fmr f13,f24
	ctx.f13.f64 = f24.f64;
	// fsubs f7,f7,f17
	ctx.f7.f64 = double(float(ctx.f7.f64 - f17.f64));
	// stfs f7,0(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(r31.u32 + 0, temp.u32);
	// fmuls f28,f9,f5
	f28.f64 = double(float(ctx.f9.f64 * ctx.f5.f64));
	// fmr f27,f5
	f27.f64 = ctx.f5.f64;
	// fsubs f5,f3,f31
	ctx.f5.f64 = double(float(ctx.f3.f64 - f31.f64));
	// fadds f30,f1,f2
	f30.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fmr f0,f25
	ctx.f0.f64 = f25.f64;
	// fmr f12,f22
	ctx.f12.f64 = f22.f64;
	// fmuls f7,f11,f14
	ctx.f7.f64 = double(float(ctx.f11.f64 * f14.f64));
	// fneg f11,f20
	ctx.f11.u64 = f20.u64 ^ 0x8000000000000000;
	// fmsubs f29,f10,f29,f28
	f29.f64 = double(float(std::fma(ctx.f10.f64, f29.f64, -f28.f64)));
	// stfs f29,-8(r3)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(ctx.r3.u32 + -8, temp.u32);
	// fmadds f29,f10,f27,f26
	f29.f64 = double(float(std::fma(ctx.f10.f64, f27.f64, f26.f64)));
	// stfs f29,-4(r3)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(ctx.r3.u32 + -4, temp.u32);
	// fmr f29,f5
	f29.f64 = ctx.f5.f64;
	// fmuls f27,f13,f5
	f27.f64 = double(float(ctx.f13.f64 * ctx.f5.f64));
	// fmuls f28,f13,f30
	f28.f64 = double(float(ctx.f13.f64 * f30.f64));
	// fadds f5,f18,f19
	ctx.f5.f64 = double(float(f18.f64 + f19.f64));
	// fsubs f6,f4,f6
	ctx.f6.f64 = double(float(ctx.f4.f64 - ctx.f6.f64));
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// fmsubs f4,f0,f29,f28
	ctx.f4.f64 = double(float(std::fma(ctx.f0.f64, f29.f64, -f28.f64)));
	// stfs f4,0(r3)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fmadds f4,f0,f30,f27
	ctx.f4.f64 = double(float(std::fma(ctx.f0.f64, f30.f64, f27.f64)));
	// stfs f4,4(r3)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fmuls f4,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f5.f64));
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// fmuls f28,f7,f5
	f28.f64 = double(float(ctx.f7.f64 * ctx.f5.f64));
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// fsubs f5,f2,f1
	ctx.f5.f64 = double(float(ctx.f2.f64 - ctx.f1.f64));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// fmr f30,f6
	f30.f64 = ctx.f6.f64;
	// fmr f29,f6
	f29.f64 = ctx.f6.f64;
	// fadds f6,f31,f3
	ctx.f6.f64 = double(float(f31.f64 + ctx.f3.f64));
	// fmadds f4,f7,f30,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f7.f64, f30.f64, ctx.f4.f64)));
	// stfs f4,-8(r5)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r5.u32 + -8, temp.u32);
	// fmsubs f4,f8,f29,f28
	ctx.f4.f64 = double(float(std::fma(ctx.f8.f64, f29.f64, -f28.f64)));
	// stfs f4,-4(r5)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r5.u32 + -4, temp.u32);
	// fmuls f4,f12,f6
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f6.f64));
	// fmuls f6,f11,f6
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f6.f64));
	// fmadds f4,f11,f5,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f11.f64, ctx.f5.f64, ctx.f4.f64)));
	// stfs f4,0(r5)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fmsubs f6,f12,f5,f6
	ctx.f6.f64 = double(float(std::fma(ctx.f12.f64, ctx.f5.f64, -ctx.f6.f64)));
	// stfs f6,4(r5)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lfs f5,8(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// lfs f6,8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// lfs f3,12(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// fadds f23,f6,f5
	f23.f64 = double(float(ctx.f6.f64 + ctx.f5.f64));
	// lfs f4,12(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f6,f6,f5
	ctx.f6.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// lfs f1,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fadds f5,f3,f4
	ctx.f5.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// lfs f2,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f4,f4,f3
	ctx.f4.f64 = double(float(ctx.f4.f64 - ctx.f3.f64));
	// lfs f30,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	f30.f64 = double(temp.f32);
	// fadds f3,f1,f2
	ctx.f3.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// lfs f31,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	f31.f64 = double(temp.f32);
	// fsubs f2,f2,f1
	ctx.f2.f64 = double(float(ctx.f2.f64 - ctx.f1.f64));
	// lfs f29,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	f29.f64 = double(temp.f32);
	// fadds f1,f30,f31
	ctx.f1.f64 = double(float(f30.f64 + f31.f64));
	// lfs f28,8(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 8);
	f28.f64 = double(temp.f32);
	// fsubs f31,f31,f30
	f31.f64 = double(float(f31.f64 - f30.f64));
	// fadds f30,f29,f28
	f30.f64 = double(float(f29.f64 + f28.f64));
	// lfs f27,12(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12);
	f27.f64 = double(temp.f32);
	// lfs f26,12(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12);
	f26.f64 = double(temp.f32);
	// fsubs f29,f28,f29
	f29.f64 = double(float(f28.f64 - f29.f64));
	// fadds f28,f26,f27
	f28.f64 = double(float(f26.f64 + f27.f64));
	// lfs f25,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	f25.f64 = double(temp.f32);
	// fsubs f27,f26,f27
	f27.f64 = double(float(f26.f64 - f27.f64));
	// lfs f24,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	f24.f64 = double(temp.f32);
	// fadds f26,f25,f24
	f26.f64 = double(float(f25.f64 + f24.f64));
	// lfs f22,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	f22.f64 = double(temp.f32);
	// lfs f21,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	f21.f64 = double(temp.f32);
	// fadds f20,f30,f23
	f20.f64 = double(float(f30.f64 + f23.f64));
	// stfs f20,8(r9)
	temp.f32 = float(f20.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// fsubs f23,f23,f30
	f23.f64 = double(float(f23.f64 - f30.f64));
	// fadds f30,f29,f4
	f30.f64 = double(float(f29.f64 + ctx.f4.f64));
	// fadds f19,f28,f5
	f19.f64 = double(float(f28.f64 + ctx.f5.f64));
	// stfs f19,12(r9)
	temp.f32 = float(f19.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// fsubs f18,f5,f28
	f18.f64 = double(float(ctx.f5.f64 - f28.f64));
	// fsubs f5,f6,f27
	ctx.f5.f64 = double(float(ctx.f6.f64 - f27.f64));
	// fsubs f28,f24,f25
	f28.f64 = double(float(f24.f64 - f25.f64));
	// fadds f25,f26,f3
	f25.f64 = double(float(f26.f64 + ctx.f3.f64));
	// stfs f25,0(r9)
	temp.f32 = float(f25.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fsubs f25,f3,f26
	f25.f64 = double(float(ctx.f3.f64 - f26.f64));
	// fadds f26,f22,f21
	f26.f64 = double(float(f22.f64 + f21.f64));
	// fsubs f3,f21,f22
	ctx.f3.f64 = double(float(f21.f64 - f22.f64));
	// fmuls f24,f10,f30
	f24.f64 = double(float(ctx.f10.f64 * f30.f64));
	// fmuls f22,f10,f5
	f22.f64 = double(float(ctx.f10.f64 * ctx.f5.f64));
	// fadds f10,f28,f31
	ctx.f10.f64 = double(float(f28.f64 + f31.f64));
	// fmsubs f5,f9,f5,f24
	ctx.f5.f64 = double(float(std::fma(ctx.f9.f64, ctx.f5.f64, -f24.f64)));
	// fadds f24,f26,f1
	f24.f64 = double(float(f26.f64 + ctx.f1.f64));
	// stfs f24,4(r9)
	temp.f32 = float(f24.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f23,8(r8)
	temp.f32 = float(f23.f64);
	REX_STORE_U32(ctx.r8.u32 + 8, temp.u32);
	// fsubs f1,f1,f26
	ctx.f1.f64 = double(float(ctx.f1.f64 - f26.f64));
	// fmadds f30,f9,f30,f22
	f30.f64 = double(float(std::fma(ctx.f9.f64, f30.f64, f22.f64)));
	// stfs f18,12(r8)
	temp.f32 = float(f18.f64);
	REX_STORE_U32(ctx.r8.u32 + 12, temp.u32);
	// fsubs f9,f2,f3
	ctx.f9.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// stfs f1,4(r8)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// fmr f1,f10
	ctx.f1.f64 = ctx.f10.f64;
	// stfs f25,0(r8)
	temp.f32 = float(f25.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r9,r9,-16
	ctx.r9.s64 = ctx.r9.s64 + -16;
	// stfs f5,8(r7)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// fmuls f5,f0,f10
	ctx.f5.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// fsubs f10,f4,f29
	ctx.f10.f64 = double(float(ctx.f4.f64 - f29.f64));
	// stfs f30,12(r7)
	temp.f32 = float(f30.f64);
	REX_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// fmr f4,f9
	ctx.f4.f64 = ctx.f9.f64;
	// addi r8,r8,-16
	ctx.r8.s64 = ctx.r8.s64 + -16;
	// fmuls f30,f0,f9
	f30.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// fadds f9,f27,f6
	ctx.f9.f64 = double(float(f27.f64 + ctx.f6.f64));
	// fmr f6,f10
	ctx.f6.f64 = ctx.f10.f64;
	// fmsubs f5,f13,f4,f5
	ctx.f5.f64 = double(float(std::fma(ctx.f13.f64, ctx.f4.f64, -ctx.f5.f64)));
	// stfs f5,0(r7)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fmadds f5,f13,f1,f30
	ctx.f5.f64 = double(float(std::fma(ctx.f13.f64, ctx.f1.f64, f30.f64)));
	// stfs f5,4(r7)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// fmuls f5,f7,f9
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// addi r7,r7,-16
	ctx.r7.s64 = ctx.r7.s64 + -16;
	// fmuls f4,f8,f9
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// fmr f29,f10
	f29.f64 = ctx.f10.f64;
	// fadds f9,f3,f2
	ctx.f9.f64 = double(float(ctx.f3.f64 + ctx.f2.f64));
	// fsubs f10,f31,f28
	ctx.f10.f64 = double(float(f31.f64 - f28.f64));
	// fmadds f8,f8,f6,f5
	ctx.f8.f64 = double(float(std::fma(ctx.f8.f64, ctx.f6.f64, ctx.f5.f64)));
	// stfs f8,8(r6)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// fmsubs f8,f7,f29,f4
	ctx.f8.f64 = double(float(std::fma(ctx.f7.f64, f29.f64, -ctx.f4.f64)));
	// stfs f8,12(r6)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// fmuls f8,f11,f9
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// fmuls f9,f12,f9
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// fmadds f8,f12,f10,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f12.f64, ctx.f10.f64, ctx.f8.f64)));
	// stfs f8,0(r6)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fmsubs f10,f11,f10,f9
	ctx.f10.f64 = double(float(std::fma(ctx.f11.f64, ctx.f10.f64, -ctx.f9.f64)));
	// stfs f10,4(r6)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// addi r6,r6,-16
	ctx.r6.s64 = ctx.r6.s64 + -16;
	// bne cr6,0x82a80c9c
	if (!cr6.eq) goto loc_82A80C9C;
	// lfs f10,-224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -224);
	ctx.f10.f64 = double(temp.f32);
loc_82A80FB4:
	// add r7,r11,r29
	ctx.r7.u64 = ctx.r11.u64 + r29.u64;
	// fadds f13,f13,f10
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f10.f64));
	// fadds f9,f0,f10
	ctx.f9.f64 = double(float(ctx.f0.f64 + ctx.f10.f64));
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r7,-2
	ctx.r8.s64 = ctx.r7.s64 + -2;
	// fsubs f12,f12,f10
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// add r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 + ctx.r11.u64;
	// fsubs f11,f11,f10
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// rlwinm r30,r8,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r6,-2
	ctx.r8.s64 = ctx.r6.s64 + -2;
	// add r5,r6,r11
	ctx.r5.u64 = ctx.r6.u64 + ctx.r11.u64;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r31,r8,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f6,r30,r4
	temp.u32 = REX_LOAD_U32(r30.u32 + ctx.r4.u32);
	ctx.f6.f64 = double(temp.f32);
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f0,f13,f15
	ctx.f0.f64 = double(float(ctx.f13.f64 * f15.f64));
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// fmuls f13,f9,f15
	ctx.f13.f64 = double(float(ctx.f9.f64 * f15.f64));
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// fmuls f12,f12,f14
	ctx.f12.f64 = double(float(ctx.f12.f64 * f14.f64));
	// addi r3,r5,-2
	ctx.r3.s64 = ctx.r5.s64 + -2;
	// lfsx f4,r31,r4
	temp.u32 = REX_LOAD_U32(r31.u32 + ctx.r4.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r28,r27,2,0,29
	r28.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f11,f11,f14
	ctx.f11.f64 = double(float(ctx.f11.f64 * f14.f64));
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lfs f8,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f5,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f5.f64 = double(temp.f32);
	// fadds f1,f8,f5
	ctx.f1.f64 = double(float(ctx.f8.f64 + ctx.f5.f64));
	// addi r26,r5,2
	r26.s64 = ctx.r5.s64 + 2;
	// lfsx f9,r28,r4
	temp.u32 = REX_LOAD_U32(r28.u32 + ctx.r4.u32);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f8,f5
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f5.f64));
	// lfs f3,-4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f3.f64 = double(temp.f32);
	// fadds f31,f9,f4
	f31.f64 = double(float(ctx.f9.f64 + ctx.f4.f64));
	// lfs f7,-4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f9,f9,f4
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f4.f64));
	// lfsx f2,r3,r4
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	ctx.f2.f64 = double(temp.f32);
	// fadds f5,f7,f3
	ctx.f5.f64 = double(float(ctx.f7.f64 + ctx.f3.f64));
	// fadds f4,f6,f2
	ctx.f4.f64 = double(float(ctx.f6.f64 + ctx.f2.f64));
	// addi r25,r7,2
	r25.s64 = ctx.r7.s64 + 2;
	// fsubs f6,f6,f2
	ctx.f6.f64 = double(float(ctx.f6.f64 - ctx.f2.f64));
	// fsubs f7,f7,f3
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f3.f64));
	// fadds f3,f5,f1
	ctx.f3.f64 = double(float(ctx.f5.f64 + ctx.f1.f64));
	// stfs f3,-4(r10)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r10.u32 + -4, temp.u32);
	// fadds f3,f4,f31
	ctx.f3.f64 = double(float(ctx.f4.f64 + f31.f64));
	// stfsx f3,r28,r4
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(r28.u32 + ctx.r4.u32, temp.u32);
	// fsubs f4,f31,f4
	ctx.f4.f64 = double(float(f31.f64 - ctx.f4.f64));
	// stfsx f4,r30,r4
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(r30.u32 + ctx.r4.u32, temp.u32);
	// fadds f4,f6,f8
	ctx.f4.f64 = double(float(ctx.f6.f64 + ctx.f8.f64));
	// addi r30,r29,3
	r30.s64 = r29.s64 + 3;
	// fsubs f5,f1,f5
	ctx.f5.f64 = double(float(ctx.f1.f64 - ctx.f5.f64));
	// stfs f5,-4(r9)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// fsubs f5,f9,f7
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f7.f64));
	// fadds f9,f7,f9
	ctx.f9.f64 = double(float(ctx.f7.f64 + ctx.f9.f64));
	// fsubs f8,f8,f6
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f6.f64));
	// fmuls f3,f0,f4
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f4.f64));
	// fmuls f2,f0,f5
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f5.f64));
	// fmsubs f7,f13,f5,f3
	ctx.f7.f64 = double(float(std::fma(ctx.f13.f64, ctx.f5.f64, -ctx.f3.f64)));
	// stfsx f7,r31,r4
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(r31.u32 + ctx.r4.u32, temp.u32);
	// addi r31,r6,2
	r31.s64 = ctx.r6.s64 + 2;
	// fmadds f7,f13,f4,f2
	ctx.f7.f64 = double(float(std::fma(ctx.f13.f64, ctx.f4.f64, ctx.f2.f64)));
	// stfs f7,-4(r11)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// fmuls f7,f12,f9
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// lfs f5,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f9,f11,f9
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// lfs f3,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// addi r6,r6,3
	ctx.r6.s64 = ctx.r6.s64 + 3;
	// rlwinm r28,r31,2,0,29
	r28.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f7,f11,f8,f7
	ctx.f7.f64 = double(float(std::fma(ctx.f11.f64, ctx.f8.f64, ctx.f7.f64)));
	// stfsx f7,r3,r4
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r3.u32 + ctx.r4.u32, temp.u32);
	// addi r3,r29,2
	ctx.r3.s64 = r29.s64 + 2;
	// fmsubs f9,f12,f8,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f12.f64, ctx.f8.f64, -ctx.f9.f64)));
	// stfs f9,-4(r8)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r8.u32 + -4, temp.u32);
	// lfs f9,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r27,r3,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f8,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// fadds f31,f9,f8
	f31.f64 = double(float(ctx.f9.f64 + ctx.f8.f64));
	// lfs f2,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f9,f9,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// rlwinm r29,r30,2,0,29
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f8,f7,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 + ctx.f6.f64));
	// rlwinm r30,r6,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f7,f7,f6
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// rlwinm r31,r26,2,0,29
	r31.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f6,f4,f5
	ctx.f6.f64 = double(float(ctx.f4.f64 + ctx.f5.f64));
	// rlwinm r3,r25,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f5,f4,f5
	ctx.f5.f64 = double(float(ctx.f4.f64 - ctx.f5.f64));
	// addi r6,r5,3
	ctx.r6.s64 = ctx.r5.s64 + 3;
	// fadds f4,f2,f3
	ctx.f4.f64 = double(float(ctx.f2.f64 + ctx.f3.f64));
	// addi r7,r7,3
	ctx.r7.s64 = ctx.r7.s64 + 3;
	// fsubs f3,f2,f3
	ctx.f3.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// fneg f1,f10
	ctx.f1.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f2,f6,f31
	ctx.f2.f64 = double(float(ctx.f6.f64 + f31.f64));
	// stfs f2,0(r10)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fsubs f6,f31,f6
	ctx.f6.f64 = double(float(f31.f64 - ctx.f6.f64));
	// fadds f2,f4,f8
	ctx.f2.f64 = double(float(ctx.f4.f64 + ctx.f8.f64));
	// stfs f2,4(r10)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f6,0(r9)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fsubs f4,f8,f4
	ctx.f4.f64 = double(float(ctx.f8.f64 - ctx.f4.f64));
	// fsubs f8,f9,f3
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f3.f64));
	// stfs f4,4(r9)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fadds f6,f5,f7
	ctx.f6.f64 = double(float(ctx.f5.f64 + ctx.f7.f64));
	// fadds f9,f3,f9
	ctx.f9.f64 = double(float(ctx.f3.f64 + ctx.f9.f64));
	// fsubs f4,f8,f6
	ctx.f4.f64 = double(float(ctx.f8.f64 - ctx.f6.f64));
	// fadds f6,f6,f8
	ctx.f6.f64 = double(float(ctx.f6.f64 + ctx.f8.f64));
	// fsubs f8,f7,f5
	ctx.f8.f64 = double(float(ctx.f7.f64 - ctx.f5.f64));
	// fmuls f7,f4,f10
	ctx.f7.f64 = double(float(ctx.f4.f64 * ctx.f10.f64));
	// stfs f7,0(r11)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fmuls f10,f6,f10
	ctx.f10.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// stfs f10,4(r11)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fadds f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// lfsx f10,r31,r4
	temp.u32 = REX_LOAD_U32(r31.u32 + ctx.r4.u32);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f8,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// lfsx f3,r6,r4
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + ctx.r4.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f8,f7,f1
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f1.f64));
	// stfs f8,0(r8)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmuls f9,f9,f1
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f1.f64));
	// stfs f9,4(r8)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lfsx f8,r28,r4
	temp.u32 = REX_LOAD_U32(r28.u32 + ctx.r4.u32);
	ctx.f8.f64 = double(temp.f32);
	// lfsx f9,r27,r4
	temp.u32 = REX_LOAD_U32(r27.u32 + ctx.r4.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfsx f6,r30,r4
	temp.u32 = REX_LOAD_U32(r30.u32 + ctx.r4.u32);
	ctx.f6.f64 = double(temp.f32);
	// fadds f4,f9,f8
	ctx.f4.f64 = double(float(ctx.f9.f64 + ctx.f8.f64));
	// lfsx f7,r29,r4
	temp.u32 = REX_LOAD_U32(r29.u32 + ctx.r4.u32);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f9,f9,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// lfsx f5,r3,r4
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	ctx.f5.f64 = double(temp.f32);
	// fadds f8,f7,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 + ctx.f6.f64));
	// fsubs f7,f7,f6
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fadds f6,f5,f10
	ctx.f6.f64 = double(float(ctx.f5.f64 + ctx.f10.f64));
	// fsubs f10,f5,f10
	ctx.f10.f64 = double(float(ctx.f5.f64 - ctx.f10.f64));
	// lfsx f5,r7,r4
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	ctx.f5.f64 = double(temp.f32);
	// fadds f2,f6,f4
	ctx.f2.f64 = double(float(ctx.f6.f64 + ctx.f4.f64));
	// stfsx f2,r27,r4
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(r27.u32 + ctx.r4.u32, temp.u32);
	// fsubs f4,f4,f6
	ctx.f4.f64 = double(float(ctx.f4.f64 - ctx.f6.f64));
	// fadds f6,f5,f3
	ctx.f6.f64 = double(float(ctx.f5.f64 + ctx.f3.f64));
	// fsubs f5,f5,f3
	ctx.f5.f64 = double(float(ctx.f5.f64 - ctx.f3.f64));
	// fadds f3,f6,f8
	ctx.f3.f64 = double(float(ctx.f6.f64 + ctx.f8.f64));
	// stfsx f3,r29,r4
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(r29.u32 + ctx.r4.u32, temp.u32);
	// fsubs f6,f8,f6
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f6.f64));
	// stfsx f6,r7,r4
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r7.u32 + ctx.r4.u32, temp.u32);
	// fadds f6,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 + ctx.f7.f64));
	// stfsx f4,r3,r4
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r3.u32 + ctx.r4.u32, temp.u32);
	// fsubs f8,f9,f5
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f5.f64));
	// fsubs f10,f7,f10
	ctx.f10.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// fmuls f4,f13,f6
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// fmuls f3,f13,f8
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// fadds f13,f5,f9
	ctx.f13.f64 = double(float(ctx.f5.f64 + ctx.f9.f64));
	// fmsubs f9,f0,f8,f4
	ctx.f9.f64 = double(float(std::fma(ctx.f0.f64, ctx.f8.f64, -ctx.f4.f64)));
	// stfsx f9,r28,r4
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(r28.u32 + ctx.r4.u32, temp.u32);
	// fmadds f0,f0,f6,f3
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f6.f64, ctx.f3.f64)));
	// stfsx f0,r30,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r30.u32 + ctx.r4.u32, temp.u32);
	// fmuls f0,f11,f13
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmadds f0,f12,f10,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f10.f64, ctx.f0.f64)));
	// stfsx f0,r31,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + ctx.r4.u32, temp.u32);
	// fmsubs f0,f11,f10,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f10.f64, -ctx.f13.f64)));
	// stfsx f0,r6,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + ctx.r4.u32, temp.u32);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x82a0133c
	ctx.lr = 0x82A81248;
	// b 0x829ff80c
	return;
}

DEFINE_REX_FUNC(sub_82A81250) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f14{};
	PPCRegister f15{};
	PPCRegister f16{};
	PPCRegister f17{};
	PPCRegister f18{};
	PPCRegister f19{};
	PPCRegister f20{};
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7bc
	ctx.lr = 0x82A81258;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x82a012f0
	ctx.lr = 0x82A81260;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f10,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// srawi r29,r3,3
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	r29.s64 = ctx.r3.s32 >> 3;
	// fneg f1,f10
	ctx.f1.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// lfs f9,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// addi r30,r5,8
	r30.s64 = ctx.r5.s64 + 8;
	// addi r27,r29,-2
	r27.s64 = r29.s64 + -2;
	// lfs f0,3400(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3400);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmr f12,f0
	ctx.f12.f64 = ctx.f0.f64;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// lfs f13,2612(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2612);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lfs f6,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f8,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fadds f2,f9,f6
	ctx.f2.f64 = double(float(ctx.f9.f64 + ctx.f6.f64));
	// lfs f4,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f9,f9,f6
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f6.f64));
	// lfs f5,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fadds f6,f8,f4
	ctx.f6.f64 = double(float(ctx.f8.f64 + ctx.f4.f64));
	// lfs f7,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f10,f5,f10
	ctx.f10.f64 = double(float(ctx.f5.f64 - ctx.f10.f64));
	// lfs f3,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f1,f1,f5
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f5.f64));
	// fadds f5,f7,f3
	ctx.f5.f64 = double(float(ctx.f7.f64 + ctx.f3.f64));
	// fsubs f7,f7,f3
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f3.f64));
	// fsubs f8,f8,f4
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f4.f64));
	// fadds f4,f6,f2
	ctx.f4.f64 = double(float(ctx.f6.f64 + ctx.f2.f64));
	// stfs f4,0(r4)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fsubs f6,f2,f6
	ctx.f6.f64 = double(float(ctx.f2.f64 - ctx.f6.f64));
	// fsubs f4,f1,f5
	ctx.f4.f64 = double(float(ctx.f1.f64 - ctx.f5.f64));
	// stfs f4,4(r4)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// stfs f6,0(r10)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fadds f6,f5,f1
	ctx.f6.f64 = double(float(ctx.f5.f64 + ctx.f1.f64));
	// stfs f6,4(r10)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fadds f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f9.f64));
	// stfs f6,0(r9)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fadds f6,f8,f10
	ctx.f6.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// stfs f6,4(r9)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fsubs f10,f10,f8
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// fsubs f9,f9,f7
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f7.f64));
	// stfs f10,4(r8)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// stfs f9,0(r8)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// lfs f10,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,12(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// stfs f10,-212(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -212, temp.u32);
	// stfs f9,-220(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -220, temp.u32);
	// stfs f8,-224(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -224, temp.u32);
	// ble cr6,0x82a816f4
	if (!cr6.gt) goto loc_82A816F4;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// addi r5,r11,-2
	ctx.r5.s64 = ctx.r11.s64 + -2;
	// addi r3,r27,-3
	ctx.r3.s64 = r27.s64 + -3;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r7,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r5,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// rlwinm r5,r3,30,2,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3FFFFFFF;
	// add r3,r7,r4
	ctx.r3.u64 = ctx.r7.u64 + ctx.r4.u64;
	// add r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 + ctx.r4.u64;
	// addi r8,r9,-16
	ctx.r8.s64 = ctx.r9.s64 + -16;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r5,1
	r28.s64 = ctx.r5.s64 + 1;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// addi r31,r4,16
	r31.s64 = ctx.r4.s64 + 16;
	// addi r5,r9,16
	ctx.r5.s64 = ctx.r9.s64 + 16;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// addi r9,r9,-16
	ctx.r9.s64 = ctx.r9.s64 + -16;
loc_82A813B0:
	// lfs f7,-4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + -4);
	ctx.f7.f64 = double(temp.f32);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// lfs f10,-4(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f1,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f21,f7,f10
	f21.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// lfs f26,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	f26.f64 = double(temp.f32);
	// fneg f18,f10
	f18.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// fadds f10,f1,f26
	ctx.f10.f64 = double(float(ctx.f1.f64 + f26.f64));
	// stfs f10,-216(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -216, temp.u32);
	// lfs f9,4(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f1,f26,f1
	ctx.f1.f64 = double(float(f26.f64 - ctx.f1.f64));
	// fneg f16,f9
	f16.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// lfs f8,-8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f31,-8(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + -8);
	f31.f64 = double(temp.f32);
	// lfs f25,-8(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + -8);
	f25.f64 = double(temp.f32);
	// fadds f19,f8,f31
	f19.f64 = double(float(ctx.f8.f64 + f31.f64));
	// lfs f6,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f31,f31,f8
	f31.f64 = double(float(f31.f64 - ctx.f8.f64));
	// lfs f30,0(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 0);
	f30.f64 = double(temp.f32);
	// fadds f10,f0,f25
	ctx.f10.f64 = double(float(ctx.f0.f64 + f25.f64));
	// lfs f24,-4(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + -4);
	f24.f64 = double(temp.f32);
	// fadds f17,f30,f6
	f17.f64 = double(float(f30.f64 + ctx.f6.f64));
	// lfs f5,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f6,f30,f6
	ctx.f6.f64 = double(float(f30.f64 - ctx.f6.f64));
	// lfs f23,0(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 0);
	f23.f64 = double(temp.f32);
	// fsubs f20,f5,f9
	f20.f64 = double(float(ctx.f5.f64 - ctx.f9.f64));
	// lfs f4,-8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -8);
	ctx.f4.f64 = double(temp.f32);
	// fadds f8,f13,f24
	ctx.f8.f64 = double(float(ctx.f13.f64 + f24.f64));
	// lfs f29,-8(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8);
	f29.f64 = double(temp.f32);
	// fadds f30,f23,f12
	f30.f64 = double(float(f23.f64 + ctx.f12.f64));
	// fsubs f5,f16,f5
	ctx.f5.f64 = double(float(f16.f64 - ctx.f5.f64));
	// lfs f3,-4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + -4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f28,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	f28.f64 = double(temp.f32);
	// fadds f16,f4,f29
	f16.f64 = double(float(ctx.f4.f64 + f29.f64));
	// lfs f2,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f18,f18,f7
	f18.f64 = double(float(f18.f64 - ctx.f7.f64));
	// lfs f27,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	f27.f64 = double(temp.f32);
	// fadds f15,f3,f28
	f15.f64 = double(float(ctx.f3.f64 + f28.f64));
	// fadds f14,f27,f2
	f14.f64 = double(float(f27.f64 + ctx.f2.f64));
	// lfs f22,4(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 4);
	f22.f64 = double(temp.f32);
	// fsubs f4,f29,f4
	ctx.f4.f64 = double(float(f29.f64 - ctx.f4.f64));
	// lfs f9,-220(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -220);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f29,f11,f22
	f29.f64 = double(float(ctx.f11.f64 - f22.f64));
	// lfs f7,-224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -224);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f10,f10,f9
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f9.f64));
	// fmuls f9,f8,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// fmuls f8,f30,f7
	ctx.f8.f64 = double(float(f30.f64 * ctx.f7.f64));
	// fsubs f3,f28,f3
	ctx.f3.f64 = double(float(f28.f64 - ctx.f3.f64));
	// fadds f30,f16,f19
	f30.f64 = double(float(f16.f64 + f19.f64));
	// stfs f30,-8(r31)
	temp.f32 = float(f30.f64);
	REX_STORE_U32(r31.u32 + -8, temp.u32);
	// fsubs f2,f27,f2
	ctx.f2.f64 = double(float(f27.f64 - ctx.f2.f64));
	// fsubs f30,f18,f15
	f30.f64 = double(float(f18.f64 - f15.f64));
	// stfs f30,-4(r31)
	temp.f32 = float(f30.f64);
	REX_STORE_U32(r31.u32 + -4, temp.u32);
	// fadds f30,f14,f17
	f30.f64 = double(float(f14.f64 + f17.f64));
	// stfs f30,0(r31)
	temp.f32 = float(f30.f64);
	REX_STORE_U32(r31.u32 + 0, temp.u32);
	// fmr f0,f25
	ctx.f0.f64 = f25.f64;
	// fmuls f7,f29,f7
	ctx.f7.f64 = double(float(f29.f64 * ctx.f7.f64));
	// fmr f13,f24
	ctx.f13.f64 = f24.f64;
	// fmr f12,f23
	ctx.f12.f64 = f23.f64;
	// fneg f11,f22
	ctx.f11.u64 = f22.u64 ^ 0x8000000000000000;
	// lfs f30,-216(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -216);
	f30.f64 = double(temp.f32);
	// fsubs f29,f5,f30
	f29.f64 = double(float(ctx.f5.f64 - f30.f64));
	// stfs f29,4(r31)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(r31.u32 + 4, temp.u32);
	// fadds f5,f30,f5
	ctx.f5.f64 = double(float(f30.f64 + ctx.f5.f64));
	// stfs f5,4(r10)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fadds f5,f3,f31
	ctx.f5.f64 = double(float(ctx.f3.f64 + f31.f64));
	// fadds f30,f4,f21
	f30.f64 = double(float(ctx.f4.f64 + f21.f64));
	// fsubs f29,f19,f16
	f29.f64 = double(float(f19.f64 - f16.f64));
	// stfs f29,-8(r10)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(ctx.r10.u32 + -8, temp.u32);
	// fadds f29,f15,f18
	f29.f64 = double(float(f15.f64 + f18.f64));
	// stfs f29,-4(r10)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(ctx.r10.u32 + -4, temp.u32);
	// fsubs f29,f17,f14
	f29.f64 = double(float(f17.f64 - f14.f64));
	// stfs f29,0(r10)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fmr f29,f5
	f29.f64 = ctx.f5.f64;
	// fmuls f28,f9,f30
	f28.f64 = double(float(ctx.f9.f64 * f30.f64));
	// fmr f27,f30
	f27.f64 = f30.f64;
	// fmuls f26,f9,f5
	f26.f64 = double(float(ctx.f9.f64 * ctx.f5.f64));
	// fadds f5,f1,f6
	ctx.f5.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// fadds f30,f2,f20
	f30.f64 = double(float(ctx.f2.f64 + f20.f64));
	// fmsubs f29,f10,f29,f28
	f29.f64 = double(float(std::fma(ctx.f10.f64, f29.f64, -f28.f64)));
	// stfs f29,-8(r3)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(ctx.r3.u32 + -8, temp.u32);
	// fmadds f29,f10,f27,f26
	f29.f64 = double(float(std::fma(ctx.f10.f64, f27.f64, f26.f64)));
	// stfs f29,-4(r3)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(ctx.r3.u32 + -4, temp.u32);
	// fmr f29,f5
	f29.f64 = ctx.f5.f64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// fmuls f27,f13,f5
	f27.f64 = double(float(ctx.f13.f64 * ctx.f5.f64));
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// fmuls f28,f13,f30
	f28.f64 = double(float(ctx.f13.f64 * f30.f64));
	// fsubs f5,f21,f4
	ctx.f5.f64 = double(float(f21.f64 - ctx.f4.f64));
	// fsubs f4,f31,f3
	ctx.f4.f64 = double(float(f31.f64 - ctx.f3.f64));
	// fsubs f6,f6,f1
	ctx.f6.f64 = double(float(ctx.f6.f64 - ctx.f1.f64));
	// fmsubs f3,f0,f29,f28
	ctx.f3.f64 = double(float(std::fma(ctx.f0.f64, f29.f64, -f28.f64)));
	// stfs f3,0(r3)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fmadds f3,f0,f30,f27
	ctx.f3.f64 = double(float(std::fma(ctx.f0.f64, f30.f64, f27.f64)));
	// stfs f3,4(r3)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fmuls f31,f8,f4
	f31.f64 = double(float(ctx.f8.f64 * ctx.f4.f64));
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// fmr f30,f5
	f30.f64 = ctx.f5.f64;
	// fmuls f4,f7,f4
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f4.f64));
	// fmr f3,f5
	ctx.f3.f64 = ctx.f5.f64;
	// fsubs f5,f20,f2
	ctx.f5.f64 = double(float(f20.f64 - ctx.f2.f64));
	// fmsubs f4,f8,f30,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f8.f64, f30.f64, -ctx.f4.f64)));
	// stfs f4,-4(r5)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r5.u32 + -4, temp.u32);
	// fmuls f4,f12,f6
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f6.f64));
	// fmuls f6,f11,f6
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f6.f64));
	// fmadds f3,f7,f3,f31
	ctx.f3.f64 = double(float(std::fma(ctx.f7.f64, ctx.f3.f64, f31.f64)));
	// stfs f3,-8(r5)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r5.u32 + -8, temp.u32);
	// fmadds f4,f11,f5,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f11.f64, ctx.f5.f64, ctx.f4.f64)));
	// stfs f4,0(r5)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fmsubs f6,f12,f5,f6
	ctx.f6.f64 = double(float(std::fma(ctx.f12.f64, ctx.f5.f64, -ctx.f6.f64)));
	// stfs f6,4(r5)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lfs f6,12(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f6.f64 = double(temp.f32);
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// fneg f24,f6
	f24.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// lfs f3,8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f4,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// lfs f31,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	f31.f64 = double(temp.f32);
	// fadds f25,f3,f4
	f25.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// lfs f2,12(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f4,f4,f3
	ctx.f4.f64 = double(float(ctx.f4.f64 - ctx.f3.f64));
	// lfs f1,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f6,f2,f6
	ctx.f6.f64 = double(float(ctx.f2.f64 - ctx.f6.f64));
	// lfs f5,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fadds f3,f31,f1
	ctx.f3.f64 = double(float(f31.f64 + ctx.f1.f64));
	// lfs f28,8(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8);
	f28.f64 = double(temp.f32);
	// fneg f23,f5
	f23.u64 = ctx.f5.u64 ^ 0x8000000000000000;
	// lfs f27,12(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12);
	f27.f64 = double(temp.f32);
	// fsubs f1,f1,f31
	ctx.f1.f64 = double(float(ctx.f1.f64 - f31.f64));
	// lfs f26,12(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12);
	f26.f64 = double(temp.f32);
	// lfs f29,8(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 8);
	f29.f64 = double(temp.f32);
	// fsubs f2,f24,f2
	ctx.f2.f64 = double(float(f24.f64 - ctx.f2.f64));
	// lfs f30,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	f30.f64 = double(temp.f32);
	// fadds f24,f26,f27
	f24.f64 = double(float(f26.f64 + f27.f64));
	// lfs f22,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	f22.f64 = double(temp.f32);
	// fadds f31,f28,f29
	f31.f64 = double(float(f28.f64 + f29.f64));
	// fsubs f29,f28,f29
	f29.f64 = double(float(f28.f64 - f29.f64));
	// fsubs f28,f26,f27
	f28.f64 = double(float(f26.f64 - f27.f64));
	// lfs f27,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	f27.f64 = double(temp.f32);
	// fsubs f5,f30,f5
	ctx.f5.f64 = double(float(f30.f64 - ctx.f5.f64));
	// lfs f26,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	f26.f64 = double(temp.f32);
	// fsubs f30,f23,f30
	f30.f64 = double(float(f23.f64 - f30.f64));
	// lfs f23,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	f23.f64 = double(temp.f32);
	// fsubs f20,f2,f24
	f20.f64 = double(float(ctx.f2.f64 - f24.f64));
	// stfs f20,12(r6)
	temp.f32 = float(f20.f64);
	REX_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// fadds f18,f24,f2
	f18.f64 = double(float(f24.f64 + ctx.f2.f64));
	// fadds f21,f31,f25
	f21.f64 = double(float(f31.f64 + f25.f64));
	// stfs f21,8(r6)
	temp.f32 = float(f21.f64);
	REX_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// fsubs f19,f25,f31
	f19.f64 = double(float(f25.f64 - f31.f64));
	// fadds f2,f29,f6
	ctx.f2.f64 = double(float(f29.f64 + ctx.f6.f64));
	// fsubs f25,f23,f27
	f25.f64 = double(float(f23.f64 - f27.f64));
	// fadds f31,f28,f4
	f31.f64 = double(float(f28.f64 + ctx.f4.f64));
	// fadds f27,f27,f23
	f27.f64 = double(float(f27.f64 + f23.f64));
	// fsubs f24,f22,f26
	f24.f64 = double(float(f22.f64 - f26.f64));
	// fmuls f23,f10,f2
	f23.f64 = double(float(ctx.f10.f64 * ctx.f2.f64));
	// fmr f21,f2
	f21.f64 = ctx.f2.f64;
	// fadds f2,f22,f26
	ctx.f2.f64 = double(float(f22.f64 + f26.f64));
	// fmuls f22,f10,f31
	f22.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fmr f26,f31
	f26.f64 = f31.f64;
	// fadds f20,f27,f3
	f20.f64 = double(float(f27.f64 + ctx.f3.f64));
	// stfs f20,0(r6)
	temp.f32 = float(f20.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fadds f10,f25,f5
	ctx.f10.f64 = double(float(f25.f64 + ctx.f5.f64));
	// fadds f31,f24,f1
	f31.f64 = double(float(f24.f64 + ctx.f1.f64));
	// fsubs f3,f3,f27
	ctx.f3.f64 = double(float(ctx.f3.f64 - f27.f64));
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// fsubs f27,f30,f2
	f27.f64 = double(float(f30.f64 - ctx.f2.f64));
	// stfs f27,4(r6)
	temp.f32 = float(f27.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stfs f3,0(r7)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fadds f2,f2,f30
	ctx.f2.f64 = double(float(ctx.f2.f64 + f30.f64));
	// stfs f2,4(r7)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// fmsubs f3,f9,f26,f23
	ctx.f3.f64 = double(float(std::fma(ctx.f9.f64, f26.f64, -f23.f64)));
	// stfs f19,8(r7)
	temp.f32 = float(f19.f64);
	REX_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// fmr f2,f10
	ctx.f2.f64 = ctx.f10.f64;
	// stfs f18,12(r7)
	temp.f32 = float(f18.f64);
	REX_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// fmadds f9,f9,f21,f22
	ctx.f9.f64 = double(float(std::fma(ctx.f9.f64, f21.f64, f22.f64)));
	// stfs f3,8(r9)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// fmuls f3,f0,f10
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// fmuls f30,f0,f31
	f30.f64 = double(float(ctx.f0.f64 * f31.f64));
	// stfs f9,12(r9)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// fsubs f9,f6,f29
	ctx.f9.f64 = double(float(ctx.f6.f64 - f29.f64));
	// addi r7,r7,-16
	ctx.r7.s64 = ctx.r7.s64 + -16;
	// fsubs f10,f4,f28
	ctx.f10.f64 = double(float(ctx.f4.f64 - f28.f64));
	// addi r6,r6,-16
	ctx.r6.s64 = ctx.r6.s64 + -16;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// fmsubs f6,f13,f31,f3
	ctx.f6.f64 = double(float(std::fma(ctx.f13.f64, f31.f64, -ctx.f3.f64)));
	// stfs f6,0(r9)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fmadds f6,f13,f2,f30
	ctx.f6.f64 = double(float(std::fma(ctx.f13.f64, ctx.f2.f64, f30.f64)));
	// stfs f6,4(r9)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fmr f4,f9
	ctx.f4.f64 = ctx.f9.f64;
	// addi r9,r9,-16
	ctx.r9.s64 = ctx.r9.s64 + -16;
	// fmuls f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// fmuls f2,f8,f10
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// fmr f3,f9
	ctx.f3.f64 = ctx.f9.f64;
	// fsubs f10,f1,f24
	ctx.f10.f64 = double(float(ctx.f1.f64 - f24.f64));
	// fsubs f9,f5,f25
	ctx.f9.f64 = double(float(ctx.f5.f64 - f25.f64));
	// fmadds f8,f8,f4,f6
	ctx.f8.f64 = double(float(std::fma(ctx.f8.f64, ctx.f4.f64, ctx.f6.f64)));
	// stfs f8,8(r8)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r8.u32 + 8, temp.u32);
	// fmsubs f8,f7,f3,f2
	ctx.f8.f64 = double(float(std::fma(ctx.f7.f64, ctx.f3.f64, -ctx.f2.f64)));
	// stfs f8,12(r8)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r8.u32 + 12, temp.u32);
	// fmuls f8,f11,f10
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// fmuls f10,f12,f10
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// fmadds f8,f12,f9,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f12.f64, ctx.f9.f64, ctx.f8.f64)));
	// stfs f8,0(r8)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmsubs f10,f11,f9,f10
	ctx.f10.f64 = double(float(std::fma(ctx.f11.f64, ctx.f9.f64, -ctx.f10.f64)));
	// stfs f10,4(r8)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// addi r8,r8,-16
	ctx.r8.s64 = ctx.r8.s64 + -16;
	// bne cr6,0x82a813b0
	if (!cr6.eq) goto loc_82A813B0;
	// lfs f8,-224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -224);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,-220(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -220);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,-212(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -212);
	ctx.f10.f64 = double(temp.f32);
loc_82A816F4:
	// fadds f13,f13,f10
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f10.f64));
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f7,f0,f10
	ctx.f7.f64 = double(float(ctx.f0.f64 + ctx.f10.f64));
	// add r7,r11,r29
	ctx.r7.u64 = ctx.r11.u64 + r29.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// fsubs f12,f12,f10
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// addi r8,r7,-2
	ctx.r8.s64 = ctx.r7.s64 + -2;
	// fsubs f11,f11,f10
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// add r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 + ctx.r11.u64;
	// rlwinm r30,r8,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r6,-2
	ctx.r8.s64 = ctx.r6.s64 + -2;
	// add r5,r6,r11
	ctx.r5.u64 = ctx.r6.u64 + ctx.r11.u64;
	// rlwinm r31,r8,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f0,f13,f9
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f13,f7,f9
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// lfs f9,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f9.f64 = double(temp.f32);
	// fneg f1,f9
	ctx.f1.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// fmuls f12,f12,f8
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f8.f64));
	// addi r3,r5,-2
	ctx.r3.s64 = ctx.r5.s64 + -2;
	// fmuls f11,f11,f8
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lfsx f4,r31,r4
	temp.u32 = REX_LOAD_U32(r31.u32 + ctx.r4.u32);
	ctx.f4.f64 = double(temp.f32);
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lfsx f6,r30,r4
	temp.u32 = REX_LOAD_U32(r30.u32 + ctx.r4.u32);
	ctx.f6.f64 = double(temp.f32);
	// rlwinm r28,r27,2,0,29
	r28.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f5,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f9,f5,f9
	ctx.f9.f64 = double(float(ctx.f5.f64 - ctx.f9.f64));
	// lfs f7,-4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f3,-4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f3.f64 = double(temp.f32);
	// lfsx f8,r28,r4
	temp.u32 = REX_LOAD_U32(r28.u32 + ctx.r4.u32);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f1,f1,f5
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f5.f64));
	// lfsx f2,r3,r4
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	ctx.f2.f64 = double(temp.f32);
	// fadds f5,f7,f3
	ctx.f5.f64 = double(float(ctx.f7.f64 + ctx.f3.f64));
	// fadds f31,f8,f4
	f31.f64 = double(float(ctx.f8.f64 + ctx.f4.f64));
	// fsubs f8,f8,f4
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f4.f64));
	// fadds f4,f6,f2
	ctx.f4.f64 = double(float(ctx.f6.f64 + ctx.f2.f64));
	// fsubs f6,f6,f2
	ctx.f6.f64 = double(float(ctx.f6.f64 - ctx.f2.f64));
	// fsubs f7,f7,f3
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f3.f64));
	// fsubs f3,f1,f5
	ctx.f3.f64 = double(float(ctx.f1.f64 - ctx.f5.f64));
	// stfs f3,-4(r10)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r10.u32 + -4, temp.u32);
	// fadds f5,f5,f1
	ctx.f5.f64 = double(float(ctx.f5.f64 + ctx.f1.f64));
	// fadds f3,f4,f31
	ctx.f3.f64 = double(float(ctx.f4.f64 + f31.f64));
	// stfsx f3,r28,r4
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(r28.u32 + ctx.r4.u32, temp.u32);
	// fsubs f4,f31,f4
	ctx.f4.f64 = double(float(f31.f64 - ctx.f4.f64));
	// stfsx f4,r30,r4
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(r30.u32 + ctx.r4.u32, temp.u32);
	// fadds f4,f6,f9
	ctx.f4.f64 = double(float(ctx.f6.f64 + ctx.f9.f64));
	// stfs f5,-4(r9)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// fadds f5,f7,f8
	ctx.f5.f64 = double(float(ctx.f7.f64 + ctx.f8.f64));
	// fsubs f8,f8,f7
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fsubs f9,f9,f6
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f6.f64));
	// fmuls f3,f0,f4
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f4.f64));
	// fmuls f2,f0,f5
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f5.f64));
	// fmsubs f7,f13,f5,f3
	ctx.f7.f64 = double(float(std::fma(ctx.f13.f64, ctx.f5.f64, -ctx.f3.f64)));
	// stfsx f7,r31,r4
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(r31.u32 + ctx.r4.u32, temp.u32);
	// fmadds f7,f13,f4,f2
	ctx.f7.f64 = double(float(std::fma(ctx.f13.f64, ctx.f4.f64, ctx.f2.f64)));
	// stfs f7,-4(r11)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// fmuls f7,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f8.f64));
	// addi r31,r6,2
	r31.s64 = ctx.r6.s64 + 2;
	// fmuls f8,f11,f8
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// lfs f4,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lfs f2,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// addi r6,r6,3
	ctx.r6.s64 = ctx.r6.s64 + 3;
	// fmadds f7,f11,f9,f7
	ctx.f7.f64 = double(float(std::fma(ctx.f11.f64, ctx.f9.f64, ctx.f7.f64)));
	// stfsx f7,r3,r4
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r3.u32 + ctx.r4.u32, temp.u32);
	// addi r3,r29,3
	ctx.r3.s64 = r29.s64 + 3;
	// fmsubs f9,f12,f9,f8
	ctx.f9.f64 = double(float(std::fma(ctx.f12.f64, ctx.f9.f64, -ctx.f8.f64)));
	// stfs f9,-4(r8)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r8.u32 + -4, temp.u32);
	// fneg f7,f10
	ctx.f7.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// rlwinm r27,r3,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f9,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addi r3,r29,2
	ctx.r3.s64 = r29.s64 + 2;
	// lfs f6,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// lfs f3,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// fneg f30,f9
	f30.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// addi r26,r5,2
	r26.s64 = ctx.r5.s64 + 2;
	// fadds f31,f8,f6
	f31.f64 = double(float(ctx.f8.f64 + ctx.f6.f64));
	// addi r25,r7,2
	r25.s64 = ctx.r7.s64 + 2;
	// fsubs f8,f8,f6
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f6.f64));
	// rlwinm r28,r3,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f6,f3,f4
	ctx.f6.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// rlwinm r29,r31,2,0,29
	r29.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f9,f5,f9
	ctx.f9.f64 = double(float(ctx.f5.f64 - ctx.f9.f64));
	// rlwinm r3,r25,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f4,f3,f4
	ctx.f4.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// rlwinm r31,r26,2,0,29
	r31.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f3,f1,f2
	ctx.f3.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// rlwinm r30,r6,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f2,f1,f2
	ctx.f2.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// addi r6,r5,3
	ctx.r6.s64 = ctx.r5.s64 + 3;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f5,f30,f5
	ctx.f5.f64 = double(float(f30.f64 - ctx.f5.f64));
	// fadds f1,f6,f31
	ctx.f1.f64 = double(float(ctx.f6.f64 + f31.f64));
	// stfs f1,0(r10)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fsubs f1,f31,f6
	ctx.f1.f64 = double(float(f31.f64 - ctx.f6.f64));
	// fadds f6,f2,f8
	ctx.f6.f64 = double(float(ctx.f2.f64 + ctx.f8.f64));
	// fsubs f8,f8,f2
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f2.f64));
	// fsubs f31,f5,f3
	f31.f64 = double(float(ctx.f5.f64 - ctx.f3.f64));
	// stfs f31,4(r10)
	temp.f32 = float(f31.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fadds f3,f3,f5
	ctx.f3.f64 = double(float(ctx.f3.f64 + ctx.f5.f64));
	// stfs f3,4(r9)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fadds f5,f4,f9
	ctx.f5.f64 = double(float(ctx.f4.f64 + ctx.f9.f64));
	// stfs f1,0(r9)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fsubs f9,f9,f4
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f4.f64));
	// fsubs f3,f6,f5
	ctx.f3.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// fadds f6,f5,f6
	ctx.f6.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// fmuls f5,f3,f10
	ctx.f5.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// stfs f5,0(r11)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fmuls f10,f6,f10
	ctx.f10.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// stfs f10,4(r11)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fadds f6,f9,f8
	ctx.f6.f64 = double(float(ctx.f9.f64 + ctx.f8.f64));
	// lfsx f10,r31,r4
	temp.u32 = REX_LOAD_U32(r31.u32 + ctx.r4.u32);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f9,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// addi r11,r7,3
	ctx.r11.s64 = ctx.r7.s64 + 3;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f8,f6,f7
	ctx.f8.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// stfs f8,0(r8)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmuls f9,f9,f7
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f7.f64));
	// stfs f9,4(r8)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lfsx f7,r29,r4
	temp.u32 = REX_LOAD_U32(r29.u32 + ctx.r4.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f8,r28,r4
	temp.u32 = REX_LOAD_U32(r28.u32 + ctx.r4.u32);
	ctx.f8.f64 = double(temp.f32);
	// lfsx f5,r3,r4
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	ctx.f5.f64 = double(temp.f32);
	// fadds f4,f8,f7
	ctx.f4.f64 = double(float(ctx.f8.f64 + ctx.f7.f64));
	// lfsx f9,r27,r4
	temp.u32 = REX_LOAD_U32(r27.u32 + ctx.r4.u32);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f8,f7
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fadds f7,f5,f10
	ctx.f7.f64 = double(float(ctx.f5.f64 + ctx.f10.f64));
	// lfsx f6,r30,r4
	temp.u32 = REX_LOAD_U32(r30.u32 + ctx.r4.u32);
	ctx.f6.f64 = double(temp.f32);
	// fneg f3,f9
	ctx.f3.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// fsubs f10,f5,f10
	ctx.f10.f64 = double(float(ctx.f5.f64 - ctx.f10.f64));
	// fsubs f9,f6,f9
	ctx.f9.f64 = double(float(ctx.f6.f64 - ctx.f9.f64));
	// fadds f5,f7,f4
	ctx.f5.f64 = double(float(ctx.f7.f64 + ctx.f4.f64));
	// fsubs f6,f3,f6
	ctx.f6.f64 = double(float(ctx.f3.f64 - ctx.f6.f64));
	// lfsx f3,r6,r4
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + ctx.r4.u32);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f4,f4,f7
	ctx.f4.f64 = double(float(ctx.f4.f64 - ctx.f7.f64));
	// lfsx f7,r11,r4
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r4.u32);
	ctx.f7.f64 = double(temp.f32);
	// stfsx f5,r28,r4
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(r28.u32 + ctx.r4.u32, temp.u32);
	// fadds f5,f7,f3
	ctx.f5.f64 = double(float(ctx.f7.f64 + ctx.f3.f64));
	// fsubs f7,f7,f3
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f3.f64));
	// fsubs f3,f6,f5
	ctx.f3.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// stfsx f3,r27,r4
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(r27.u32 + ctx.r4.u32, temp.u32);
	// fadds f5,f5,f6
	ctx.f5.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// stfsx f5,r11,r4
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r4.u32, temp.u32);
	// fadds f5,f10,f9
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f9.f64));
	// stfsx f4,r3,r4
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r3.u32 + ctx.r4.u32, temp.u32);
	// fadds f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f8.f64));
	// fsubs f10,f9,f10
	ctx.f10.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmuls f4,f13,f5
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f5.f64));
	// fmuls f3,f13,f6
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// fsubs f13,f8,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fmsubs f9,f0,f6,f4
	ctx.f9.f64 = double(float(std::fma(ctx.f0.f64, ctx.f6.f64, -ctx.f4.f64)));
	// stfsx f9,r29,r4
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(r29.u32 + ctx.r4.u32, temp.u32);
	// fmadds f0,f0,f5,f3
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f5.f64, ctx.f3.f64)));
	// stfsx f0,r30,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r30.u32 + ctx.r4.u32, temp.u32);
	// fmuls f0,f11,f13
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmadds f0,f12,f10,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f10.f64, ctx.f0.f64)));
	// stfsx f0,r31,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + ctx.r4.u32, temp.u32);
	// fmsubs f0,f11,f10,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f10.f64, -ctx.f13.f64)));
	// stfsx f0,r6,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + ctx.r4.u32, temp.u32);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x82a0133c
	ctx.lr = 0x82A81994;
	// b 0x829ff80c
	return;
}

DEFINE_REX_FUNC(sub_82A81998) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c8
	ctx.lr = 0x82A819A0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// srawi r28,r3,3
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	r28.s64 = ctx.r3.s32 >> 3;
	// lfs f0,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r11,r28,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lfs f10,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fadds f6,f0,f10
	ctx.f6.f64 = double(float(ctx.f0.f64 + ctx.f10.f64));
	// lfs f8,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f10.f64));
	// lfs f12,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fadds f5,f13,f9
	ctx.f5.f64 = double(float(ctx.f13.f64 + ctx.f9.f64));
	// lfs f11,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f12,f8
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f8.f64));
	// lfs f7,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// fadds f9,f11,f7
	ctx.f9.f64 = double(float(ctx.f11.f64 + ctx.f7.f64));
	// fsubs f11,f11,f7
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f7.f64));
	// fsubs f12,f12,f8
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// fadds f8,f10,f6
	ctx.f8.f64 = double(float(ctx.f10.f64 + ctx.f6.f64));
	// stfs f8,0(r4)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fsubs f10,f6,f10
	ctx.f10.f64 = double(float(ctx.f6.f64 - ctx.f10.f64));
	// fadds f8,f9,f5
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f5.f64));
	// stfs f8,4(r4)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// stfs f10,0(r10)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fsubs f10,f5,f9
	ctx.f10.f64 = double(float(ctx.f5.f64 - ctx.f9.f64));
	// stfs f10,4(r10)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// stfs f10,0(r9)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fadds f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f10,4(r9)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fadds f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// stfs f0,0(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fsubs f0,f13,f12
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// stfs f0,4(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lfs f31,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	f31.f64 = double(temp.f32);
	// ble cr6,0x82a81c40
	if (!cr6.gt) goto loc_82A81C40;
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r3,r5,8
	ctx.r3.s64 = ctx.r5.s64 + 8;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// addi r6,r28,-3
	ctx.r6.s64 = r28.s64 + -3;
	// addi r5,r8,-8
	ctx.r5.s64 = ctx.r8.s64 + -8;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r6,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r29,r6,1
	r29.s64 = ctx.r6.s64 + 1;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// addi r7,r11,-2
	ctx.r7.s64 = ctx.r11.s64 + -2;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r10,8
	r31.s64 = ctx.r10.s64 + 8;
	// addi r8,r10,-8
	ctx.r8.s64 = ctx.r10.s64 + -8;
	// addi r10,r6,8
	ctx.r10.s64 = ctx.r6.s64 + 8;
	// addi r30,r4,8
	r30.s64 = ctx.r4.s64 + 8;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 + ctx.r4.u64;
	// addi r6,r6,-8
	ctx.r6.s64 = ctx.r6.s64 + -8;
loc_82A81AB8:
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// lfs f12,0(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// lfs f8,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fadds f5,f12,f13
	ctx.f5.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// lfs f9,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f4,f13,f12
	ctx.f4.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fadds f2,f9,f8
	ctx.f2.f64 = double(float(ctx.f9.f64 + ctx.f8.f64));
	// lfs f11,4(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f9,f8,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// lfs f10,4(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lfs f7,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fadds f3,f10,f11
	ctx.f3.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// fadds f8,f7,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 + ctx.f6.f64));
	// lfs f0,-4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f7,f6,f7
	ctx.f7.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// lfs f1,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f10,f11,f10
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f13,-8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fneg f11,f1
	ctx.f11.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fadds f6,f2,f5
	ctx.f6.f64 = double(float(ctx.f2.f64 + ctx.f5.f64));
	// stfs f6,0(r30)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(r30.u32 + 0, temp.u32);
	// fsubs f6,f5,f2
	ctx.f6.f64 = double(float(ctx.f5.f64 - ctx.f2.f64));
	// fadds f5,f8,f3
	ctx.f5.f64 = double(float(ctx.f8.f64 + ctx.f3.f64));
	// stfs f5,4(r30)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(r30.u32 + 4, temp.u32);
	// stfs f6,0(r9)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fsubs f5,f3,f8
	ctx.f5.f64 = double(float(ctx.f3.f64 - ctx.f8.f64));
	// fadds f6,f9,f10
	ctx.f6.f64 = double(float(ctx.f9.f64 + ctx.f10.f64));
	// stfs f5,4(r9)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fsubs f8,f4,f7
	ctx.f8.f64 = double(float(ctx.f4.f64 - ctx.f7.f64));
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// fsubs f10,f10,f9
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// fmuls f3,f0,f6
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f6.f64));
	// fmr f5,f8
	ctx.f5.f64 = ctx.f8.f64;
	// fmuls f2,f0,f8
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
	// fadds f8,f7,f4
	ctx.f8.f64 = double(float(ctx.f7.f64 + ctx.f4.f64));
	// fmsubs f9,f13,f5,f3
	ctx.f9.f64 = double(float(std::fma(ctx.f13.f64, ctx.f5.f64, -ctx.f3.f64)));
	// stfs f9,0(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(r31.u32 + 0, temp.u32);
	// fmadds f9,f13,f6,f2
	ctx.f9.f64 = double(float(std::fma(ctx.f13.f64, ctx.f6.f64, ctx.f2.f64)));
	// stfs f9,4(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(r31.u32 + 4, temp.u32);
	// fmuls f9,f12,f8
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f8.f64));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// fmuls f8,f11,f8
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fmadds f9,f11,f10,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f11.f64, ctx.f10.f64, ctx.f9.f64)));
	// stfs f9,0(r10)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fmsubs f10,f12,f10,f8
	ctx.f10.f64 = double(float(std::fma(ctx.f12.f64, ctx.f10.f64, -ctx.f8.f64)));
	// stfs f10,4(r10)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfs f9,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// lfs f10,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f7,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fadds f2,f9,f10
	ctx.f2.f64 = double(float(ctx.f9.f64 + ctx.f10.f64));
	// lfs f8,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f10,f10,f9
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f4,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// fadds f9,f8,f7
	ctx.f9.f64 = double(float(ctx.f8.f64 + ctx.f7.f64));
	// lfs f3,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f8,f7,f8
	ctx.f8.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// lfs f6,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fadds f1,f6,f3
	ctx.f1.f64 = double(float(ctx.f6.f64 + ctx.f3.f64));
	// fadds f7,f5,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 + ctx.f4.f64));
	// fsubs f5,f4,f5
	ctx.f5.f64 = double(float(ctx.f4.f64 - ctx.f5.f64));
	// fsubs f6,f3,f6
	ctx.f6.f64 = double(float(ctx.f3.f64 - ctx.f6.f64));
	// fadds f4,f9,f2
	ctx.f4.f64 = double(float(ctx.f9.f64 + ctx.f2.f64));
	// stfs f4,0(r7)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fsubs f3,f2,f9
	ctx.f3.f64 = double(float(ctx.f2.f64 - ctx.f9.f64));
	// fadds f4,f7,f1
	ctx.f4.f64 = double(float(ctx.f7.f64 + ctx.f1.f64));
	// stfs f4,4(r7)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// fsubs f2,f1,f7
	ctx.f2.f64 = double(float(ctx.f1.f64 - ctx.f7.f64));
	// stfs f3,0(r8)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f2,4(r8)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// fsubs f9,f10,f5
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f5.f64));
	// fadds f7,f8,f6
	ctx.f7.f64 = double(float(ctx.f8.f64 + ctx.f6.f64));
	// addi r8,r8,-8
	ctx.r8.s64 = ctx.r8.s64 + -8;
	// addi r7,r7,-8
	ctx.r7.s64 = ctx.r7.s64 + -8;
	// fmuls f4,f13,f7
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f7.f64));
	// fmuls f3,f13,f9
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// fadds f13,f5,f10
	ctx.f13.f64 = double(float(ctx.f5.f64 + ctx.f10.f64));
	// fsubs f10,f6,f8
	ctx.f10.f64 = double(float(ctx.f6.f64 - ctx.f8.f64));
	// fmsubs f9,f0,f9,f4
	ctx.f9.f64 = double(float(std::fma(ctx.f0.f64, ctx.f9.f64, -ctx.f4.f64)));
	// stfs f9,0(r6)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fmadds f0,f0,f7,f3
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f7.f64, ctx.f3.f64)));
	// stfs f0,4(r6)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// fmuls f0,f11,f13
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// addi r6,r6,-8
	ctx.r6.s64 = ctx.r6.s64 + -8;
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmadds f0,f12,f10,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f10.f64, ctx.f0.f64)));
	// stfs f0,0(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fmsubs f0,f11,f10,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f10.f64, -ctx.f13.f64)));
	// stfs f0,4(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// addi r5,r5,-8
	ctx.r5.s64 = ctx.r5.s64 + -8;
	// bne cr6,0x82a81ab8
	if (!cr6.eq) goto loc_82A81AB8;
loc_82A81C40:
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + r28.u64;
	// fneg f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = f31.u64 ^ 0x8000000000000000;
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fadds f5,f13,f9
	ctx.f5.f64 = double(float(ctx.f13.f64 + ctx.f9.f64));
	// lfs f7,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f12,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fadds f4,f12,f8
	ctx.f4.f64 = double(float(ctx.f12.f64 + ctx.f8.f64));
	// lfs f10,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f11,f7
	ctx.f9.f64 = double(float(ctx.f11.f64 + ctx.f7.f64));
	// lfs f6,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f12,f12,f8
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// fadds f8,f10,f6
	ctx.f8.f64 = double(float(ctx.f10.f64 + ctx.f6.f64));
	// fsubs f11,f11,f7
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f7.f64));
	// fsubs f10,f10,f6
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f6.f64));
	// fadds f7,f9,f5
	ctx.f7.f64 = double(float(ctx.f9.f64 + ctx.f5.f64));
	// stfs f7,0(r10)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fsubs f9,f5,f9
	ctx.f9.f64 = double(float(ctx.f5.f64 - ctx.f9.f64));
	// fadds f7,f8,f4
	ctx.f7.f64 = double(float(ctx.f8.f64 + ctx.f4.f64));
	// stfs f7,4(r10)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f9,0(r9)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fsubs f9,f4,f8
	ctx.f9.f64 = double(float(ctx.f4.f64 - ctx.f8.f64));
	// stfs f9,4(r9)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fadds f8,f11,f12
	ctx.f8.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// fsubs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// fsubs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fadds f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 + ctx.f13.f64));
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// fadds f9,f8,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// fmuls f11,f7,f31
	ctx.f11.f64 = double(float(ctx.f7.f64 * f31.f64));
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fmuls f11,f9,f31
	ctx.f11.f64 = double(float(ctx.f9.f64 * f31.f64));
	// stfs f11,4(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// fsubs f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmuls f12,f11,f0
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f12,0(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,4(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lfd f31,-48(r1)
	f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x829ff818
	return;
}

DEFINE_REX_FUNC(sub_82A81D18) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7bc
	ctx.lr = 0x82A81D20;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x82a01320
	ctx.lr = 0x82A81D28;
	// srawi r26,r3,3
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	r26.s64 = ctx.r3.s32 >> 3;
	// lfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f0,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r25,r11,2,0,29
	r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lfsx f11,r25,r4
	temp.u32 = REX_LOAD_U32(r25.u32 + ctx.r4.u32);
	ctx.f11.f64 = double(temp.f32);
	// add r8,r25,r4
	ctx.r8.u64 = r25.u64 + ctx.r4.u64;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f9,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f5,f13,f9
	ctx.f5.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fadds f4,f12,f8
	ctx.f4.f64 = double(float(ctx.f12.f64 + ctx.f8.f64));
	// lfs f6,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fadds f13,f9,f13
	ctx.f13.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// lfs f10,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f12,f12,f8
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// fadds f8,f6,f10
	ctx.f8.f64 = double(float(ctx.f6.f64 + ctx.f10.f64));
	// fsubs f9,f11,f7
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f7.f64));
	// fadds f11,f7,f11
	ctx.f11.f64 = double(float(ctx.f7.f64 + ctx.f11.f64));
	// fsubs f10,f10,f6
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f6.f64));
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// fadds f9,f8,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// fadds f6,f10,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// fsubs f8,f11,f10
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fmuls f11,f7,f0
	ctx.f11.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// fmuls f10,f9,f0
	ctx.f10.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fadds f9,f11,f5
	ctx.f9.f64 = double(float(ctx.f11.f64 + ctx.f5.f64));
	// stfs f9,0(r4)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fadds f9,f10,f4
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f4.f64));
	// stfs f9,4(r4)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// fsubs f11,f5,f11
	ctx.f11.f64 = double(float(ctx.f5.f64 - ctx.f11.f64));
	// stfsx f11,r25,r4
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(r25.u32 + ctx.r4.u32, temp.u32);
	// fsubs f11,f4,f10
	ctx.f11.f64 = double(float(ctx.f4.f64 - ctx.f10.f64));
	// stfs f11,4(r8)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// fmuls f11,f8,f0
	ctx.f11.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmuls f0,f6,f0
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// fadds f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// stfs f10,4(r10)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f10,0(r10)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,0(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fsubs f0,f12,f11
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// ble cr6,0x82a82048
	if (!cr6.gt) goto loc_82A82048;
	// addi r6,r7,2
	ctx.r6.s64 = ctx.r7.s64 + 2;
	// rlwinm r7,r11,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r31,r26,-3
	r31.s64 = r26.s64 + -3;
	// add r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 + ctx.r4.u64;
	// rlwinm r31,r31,31,1,31
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r29,r7,-8
	r29.s64 = ctx.r7.s64 + -8;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r27,r31,1
	r27.s64 = r31.s64 + 1;
	// add r31,r11,r7
	r31.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r28,r31,2,0,29
	r28.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r11,-2
	ctx.r3.s64 = ctx.r11.s64 + -2;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r28,r4
	r28.u64 = r28.u64 + ctx.r4.u64;
	// rlwinm r30,r3,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r8,r4
	ctx.r6.u64 = ctx.r8.u64 + ctx.r4.u64;
	// addi r7,r10,8
	ctx.r7.s64 = ctx.r10.s64 + 8;
	// addi r31,r10,-8
	r31.s64 = ctx.r10.s64 + -8;
	// add r8,r9,r5
	ctx.r8.u64 = ctx.r9.u64 + ctx.r5.u64;
	// addi r10,r28,8
	ctx.r10.s64 = r28.s64 + 8;
	// addi r3,r4,8
	ctx.r3.s64 = ctx.r4.s64 + 8;
	// addi r9,r5,8
	ctx.r9.s64 = ctx.r5.s64 + 8;
	// add r30,r30,r4
	r30.u64 = r30.u64 + ctx.r4.u64;
	// addi r28,r28,-8
	r28.s64 = r28.s64 + -8;
loc_82A81E6C:
	// lfs f9,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lfs f8,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addi r8,r8,-16
	ctx.r8.s64 = ctx.r8.s64 + -16;
	// lfs f11,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fadds f31,f8,f9
	f31.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// lfs f10,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f30,f9,f8
	f30.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// lfs f4,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f2,f11,f10
	ctx.f2.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f3,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// fadds f1,f10,f11
	ctx.f1.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// lfs f5,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fadds f28,f4,f3
	f28.f64 = double(float(ctx.f4.f64 + ctx.f3.f64));
	// lfs f6,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// fsubs f29,f6,f5
	f29.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// lfs f7,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f13,-4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f6,f5,f6
	ctx.f6.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// lfs f27,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	f27.f64 = double(temp.f32);
	// fsubs f5,f3,f4
	ctx.f5.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// lfs f12,-8(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// fneg f9,f7
	ctx.f9.u64 = ctx.f7.u64 ^ 0x8000000000000000;
	// fneg f7,f27
	ctx.f7.u64 = f27.u64 ^ 0x8000000000000000;
	// lfs f0,-8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f4,f13,f31
	ctx.f4.f64 = double(float(ctx.f13.f64 * f31.f64));
	// lfs f11,-4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f3,f13,f2
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f2.f64));
	// lfs f10,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f27,f12,f28
	f27.f64 = double(float(ctx.f12.f64 * f28.f64));
	// fmuls f26,f12,f29
	f26.f64 = double(float(ctx.f12.f64 * f29.f64));
	// fmsubs f4,f0,f2,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f0.f64, ctx.f2.f64, -ctx.f4.f64)));
	// fmadds f3,f0,f31,f3
	ctx.f3.f64 = double(float(std::fma(ctx.f0.f64, f31.f64, ctx.f3.f64)));
	// fmuls f31,f10,f1
	f31.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// fmsubs f2,f11,f29,f27
	ctx.f2.f64 = double(float(std::fma(ctx.f11.f64, f29.f64, -f27.f64)));
	// fmuls f29,f9,f1
	f29.f64 = double(float(ctx.f9.f64 * ctx.f1.f64));
	// fmadds f1,f11,f28,f26
	ctx.f1.f64 = double(float(std::fma(ctx.f11.f64, f28.f64, f26.f64)));
	// fmuls f28,f7,f6
	f28.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fmuls f27,f8,f6
	f27.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// fadds f6,f2,f4
	ctx.f6.f64 = double(float(ctx.f2.f64 + ctx.f4.f64));
	// stfs f6,0(r3)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fsubs f4,f4,f2
	ctx.f4.f64 = double(float(ctx.f4.f64 - ctx.f2.f64));
	// fadds f2,f1,f3
	ctx.f2.f64 = double(float(ctx.f1.f64 + ctx.f3.f64));
	// stfs f2,4(r3)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fsubs f3,f3,f1
	ctx.f3.f64 = double(float(ctx.f3.f64 - ctx.f1.f64));
	// stfs f3,4(r6)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// fmadds f3,f8,f5,f28
	ctx.f3.f64 = double(float(std::fma(ctx.f8.f64, ctx.f5.f64, f28.f64)));
	// stfs f4,0(r6)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fmadds f6,f9,f30,f31
	ctx.f6.f64 = double(float(std::fma(ctx.f9.f64, f30.f64, f31.f64)));
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// fmsubs f4,f10,f30,f29
	ctx.f4.f64 = double(float(std::fma(ctx.f10.f64, f30.f64, -f29.f64)));
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// fmsubs f5,f7,f5,f27
	ctx.f5.f64 = double(float(std::fma(ctx.f7.f64, ctx.f5.f64, -f27.f64)));
	// fadds f2,f3,f6
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f6.f64));
	// stfs f2,0(r7)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fsubs f6,f6,f3
	ctx.f6.f64 = double(float(ctx.f6.f64 - ctx.f3.f64));
	// fadds f2,f5,f4
	ctx.f2.f64 = double(float(ctx.f5.f64 + ctx.f4.f64));
	// stfs f2,4(r7)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f6,0(r10)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fsubs f6,f4,f5
	ctx.f6.f64 = double(float(ctx.f4.f64 - ctx.f5.f64));
	// stfs f6,4(r10)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// lfs f5,4(r28)
	temp.u32 = REX_LOAD_U32(r28.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// lfs f6,0(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f3,0(r28)
	temp.u32 = REX_LOAD_U32(r28.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f29,f6,f5
	f29.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// lfs f4,4(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// fadds f6,f5,f6
	ctx.f6.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// lfs f1,4(r29)
	temp.u32 = REX_LOAD_U32(r29.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// fadds f5,f3,f4
	ctx.f5.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// lfs f2,0(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f4,f4,f3
	ctx.f4.f64 = double(float(ctx.f4.f64 - ctx.f3.f64));
	// lfs f31,0(r29)
	temp.u32 = REX_LOAD_U32(r29.u32 + 0);
	f31.f64 = double(temp.f32);
	// fsubs f3,f2,f1
	ctx.f3.f64 = double(float(ctx.f2.f64 - ctx.f1.f64));
	// lfs f30,4(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 4);
	f30.f64 = double(temp.f32);
	// fadds f2,f1,f2
	ctx.f2.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fadds f1,f31,f30
	ctx.f1.f64 = double(float(f31.f64 + f30.f64));
	// fsubs f31,f30,f31
	f31.f64 = double(float(f30.f64 - f31.f64));
	// fmuls f30,f11,f29
	f30.f64 = double(float(ctx.f11.f64 * f29.f64));
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// fmuls f11,f11,f5
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f5.f64));
	// fmuls f27,f0,f1
	f27.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// fmuls f28,f0,f3
	f28.f64 = double(float(ctx.f0.f64 * ctx.f3.f64));
	// fmuls f26,f8,f6
	f26.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// fmuls f6,f7,f6
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fmsubs f0,f12,f29,f11
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, f29.f64, -ctx.f11.f64)));
	// fmsubs f11,f13,f3,f27
	ctx.f11.f64 = double(float(std::fma(ctx.f13.f64, ctx.f3.f64, -f27.f64)));
	// fmadds f12,f12,f5,f30
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f5.f64, f30.f64)));
	// fmadds f13,f13,f1,f28
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f1.f64, f28.f64)));
	// fmuls f5,f9,f2
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f2.f64));
	// fmuls f3,f10,f2
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f2.f64));
	// fadds f2,f11,f0
	ctx.f2.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// stfs f2,0(r30)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(r30.u32 + 0, temp.u32);
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// fadds f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f2,4(r30)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(r30.u32 + 4, temp.u32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 0, temp.u32);
	// fsubs f0,f12,f13
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 4, temp.u32);
	// fmadds f12,f10,f31,f5
	ctx.f12.f64 = double(float(std::fma(ctx.f10.f64, f31.f64, ctx.f5.f64)));
	// fmadds f0,f7,f4,f26
	ctx.f0.f64 = double(float(std::fma(ctx.f7.f64, ctx.f4.f64, f26.f64)));
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// fmsubs f13,f8,f4,f6
	ctx.f13.f64 = double(float(std::fma(ctx.f8.f64, ctx.f4.f64, -ctx.f6.f64)));
	// addi r30,r30,-8
	r30.s64 = r30.s64 + -8;
	// fmsubs f11,f9,f31,f3
	ctx.f11.f64 = double(float(std::fma(ctx.f9.f64, f31.f64, -ctx.f3.f64)));
	// fadds f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f10,0(r28)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(r28.u32 + 0, temp.u32);
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// fadds f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stfs f10,4(r28)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(r28.u32 + 4, temp.u32);
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r29.u32 + 0, temp.u32);
	// fsubs f0,f13,f11
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// stfs f0,4(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r29.u32 + 4, temp.u32);
	// addi r28,r28,-8
	r28.s64 = r28.s64 + -8;
	// addi r29,r29,-8
	r29.s64 = r29.s64 + -8;
	// bne cr6,0x82a81e6c
	if (!cr6.eq) goto loc_82A81E6C;
loc_82A82048:
	// add r7,r25,r5
	ctx.r7.u64 = r25.u64 + ctx.r5.u64;
	// lfsx f0,r25,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r25.u32 + ctx.r5.u32);
	ctx.f0.f64 = double(temp.f32);
	// add r9,r11,r26
	ctx.r9.u64 = ctx.r11.u64 + r26.u64;
	// rlwinm r10,r26,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// lfs f13,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// add r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lfs f11,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lfs f7,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fadds f3,f7,f11
	ctx.f3.f64 = double(float(ctx.f7.f64 + ctx.f11.f64));
	// fsubs f4,f12,f8
	ctx.f4.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// lfs f9,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f6,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fadds f12,f8,f12
	ctx.f12.f64 = double(float(ctx.f8.f64 + ctx.f12.f64));
	// lfs f5,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fadds f8,f9,f6
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f6.f64));
	// lfs f10,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f11,f11,f7
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f7.f64));
	// fsubs f7,f10,f5
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f5.f64));
	// fsubs f9,f9,f6
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f6.f64));
	// fadds f10,f5,f10
	ctx.f10.f64 = double(float(ctx.f5.f64 + ctx.f10.f64));
	// fmuls f2,f13,f3
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f3.f64));
	// fmuls f1,f13,f4
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f4.f64));
	// fmuls f30,f0,f12
	f30.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fmuls f31,f0,f11
	f31.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// fmsubs f6,f0,f4,f2
	ctx.f6.f64 = double(float(std::fma(ctx.f0.f64, ctx.f4.f64, -ctx.f2.f64)));
	// fmuls f4,f0,f8
	ctx.f4.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
	// fmadds f5,f0,f3,f1
	ctx.f5.f64 = double(float(std::fma(ctx.f0.f64, ctx.f3.f64, ctx.f1.f64)));
	// fmuls f3,f0,f7
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f7.f64));
	// fmuls f2,f13,f9
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// fmuls f1,f13,f10
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmsubs f12,f13,f12,f31
	ctx.f12.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, -f31.f64)));
	// fmsubs f7,f13,f7,f4
	ctx.f7.f64 = double(float(std::fma(ctx.f13.f64, ctx.f7.f64, -ctx.f4.f64)));
	// fmadds f8,f13,f8,f3
	ctx.f8.f64 = double(float(std::fma(ctx.f13.f64, ctx.f8.f64, ctx.f3.f64)));
	// fmadds f13,f13,f11,f30
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f11.f64, f30.f64)));
	// fmsubs f11,f0,f10,f2
	ctx.f11.f64 = double(float(std::fma(ctx.f0.f64, ctx.f10.f64, -ctx.f2.f64)));
	// fmadds f0,f0,f9,f1
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f9.f64, ctx.f1.f64)));
	// fadds f4,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 + ctx.f6.f64));
	// stfs f4,0(r10)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fsubs f7,f6,f7
	ctx.f7.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fadds f6,f8,f5
	ctx.f6.f64 = double(float(ctx.f8.f64 + ctx.f5.f64));
	// stfs f6,4(r10)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fsubs f8,f5,f8
	ctx.f8.f64 = double(float(ctx.f5.f64 - ctx.f8.f64));
	// stfs f7,0(r9)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f8,4(r9)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fsubs f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// stfs f10,0(r11)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f10,4(r11)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fadds f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f12,0(r8)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f0,4(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x82a0136c
	ctx.lr = 0x82A82148;
	// b 0x829ff80c
	return;
}

DEFINE_REX_FUNC(sub_82A82150) {
	REX_FUNC_PROLOGUE();
	PPCRegister f14{};
	PPCRegister f15{};
	PPCRegister f16{};
	PPCRegister f17{};
	PPCRegister f18{};
	PPCRegister f19{};
	PPCRegister f20{};
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82a012f0
	ctx.lr = 0x82A82160;
	// lfs f10,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,68(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,64(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// fadds f26,f10,f11
	f26.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// lfs f8,32(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f11,f10,f11
	ctx.f11.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// lfs f12,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f9,96(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// fadds f27,f12,f13
	f27.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// lfs f6,36(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// fadds f10,f8,f9
	ctx.f10.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// lfs f7,100(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 100);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f9,f8,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fadds f8,f6,f7
	ctx.f8.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// lfs f4,8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f7,f6,f7
	ctx.f7.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// lfs f5,72(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f5.f64 = double(temp.f32);
	// lfs f3,76(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f2,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// lfs f28,8(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 8);
	f28.f64 = double(temp.f32);
	// fadds f25,f2,f3
	f25.f64 = double(float(ctx.f2.f64 + ctx.f3.f64));
	// lfs f0,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f30,108(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 108);
	f30.f64 = double(temp.f32);
	// fmuls f13,f28,f0
	ctx.f13.f64 = double(float(f28.f64 * ctx.f0.f64));
	// lfs f29,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	f29.f64 = double(temp.f32);
	// fadds f6,f10,f27
	ctx.f6.f64 = double(float(ctx.f10.f64 + f27.f64));
	// lfs f1,104(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f10,f27,f10
	ctx.f10.f64 = double(float(f27.f64 - ctx.f10.f64));
	// lfs f31,40(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	f31.f64 = double(temp.f32);
	// fadds f27,f8,f26
	f27.f64 = double(float(ctx.f8.f64 + f26.f64));
	// lfs f21,48(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	f21.f64 = double(temp.f32);
	// fsubs f8,f26,f8
	ctx.f8.f64 = double(float(f26.f64 - ctx.f8.f64));
	// lfs f20,116(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 116);
	f20.f64 = double(temp.f32);
	// fadds f26,f4,f5
	f26.f64 = double(float(ctx.f4.f64 + ctx.f5.f64));
	// lfs f19,52(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	f19.f64 = double(temp.f32);
	// fsubs f5,f4,f5
	ctx.f5.f64 = double(float(ctx.f4.f64 - ctx.f5.f64));
	// lfs f18,88(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 88);
	f18.f64 = double(temp.f32);
	// fsubs f4,f2,f3
	ctx.f4.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// lfs f17,24(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 24);
	f17.f64 = double(temp.f32);
	// fsubs f2,f29,f30
	ctx.f2.f64 = double(float(f29.f64 - f30.f64));
	// lfs f16,92(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 92);
	f16.f64 = double(temp.f32);
	// fsubs f3,f31,f1
	ctx.f3.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fsubs f24,f12,f7
	f24.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fadds f7,f7,f12
	ctx.f7.f64 = double(float(ctx.f7.f64 + ctx.f12.f64));
	// fadds f12,f28,f13
	ctx.f12.f64 = double(float(f28.f64 + ctx.f13.f64));
	// fadds f22,f29,f30
	f22.f64 = double(float(f29.f64 + f30.f64));
	// fadds f23,f9,f11
	f23.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// fsubs f11,f11,f9
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// fadds f9,f31,f1
	ctx.f9.f64 = double(float(f31.f64 + ctx.f1.f64));
	// fsubs f28,f5,f2
	f28.f64 = double(float(ctx.f5.f64 - ctx.f2.f64));
	// fadds f29,f3,f4
	f29.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// fsubs f4,f4,f3
	ctx.f4.f64 = double(float(ctx.f4.f64 - ctx.f3.f64));
	// fadds f5,f2,f5
	ctx.f5.f64 = double(float(ctx.f2.f64 + ctx.f5.f64));
	// fadds f31,f22,f25
	f31.f64 = double(float(f22.f64 + f25.f64));
	// fsubs f30,f25,f22
	f30.f64 = double(float(f25.f64 - f22.f64));
	// lfs f22,112(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 112);
	f22.f64 = double(temp.f32);
	// fadds f1,f9,f26
	ctx.f1.f64 = double(float(ctx.f9.f64 + f26.f64));
	// fsubs f9,f26,f9
	ctx.f9.f64 = double(float(f26.f64 - ctx.f9.f64));
	// fmuls f25,f28,f13
	f25.f64 = double(float(f28.f64 * ctx.f13.f64));
	// fmuls f26,f29,f13
	f26.f64 = double(float(f29.f64 * ctx.f13.f64));
	// fmuls f15,f4,f13
	f15.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fmadds f2,f29,f12,f25
	ctx.f2.f64 = double(float(std::fma(f29.f64, ctx.f12.f64, f25.f64)));
	// lfs f25,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	f25.f64 = double(temp.f32);
	// fmuls f29,f4,f12
	f29.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// lfs f4,16(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// fmsubs f3,f28,f12,f26
	ctx.f3.f64 = double(float(std::fma(f28.f64, ctx.f12.f64, -f26.f64)));
	// lfs f28,80(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 80);
	f28.f64 = double(temp.f32);
	// lfs f26,84(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 84);
	f26.f64 = double(temp.f32);
	// fadds f14,f4,f28
	f14.f64 = double(float(ctx.f4.f64 + f28.f64));
	// fsubs f28,f4,f28
	f28.f64 = double(float(ctx.f4.f64 - f28.f64));
	// stfs f28,-188(r1)
	temp.f32 = float(f28.f64);
	REX_STORE_U32(ctx.r1.u32 + -188, temp.u32);
	// fadds f4,f25,f26
	ctx.f4.f64 = double(float(f25.f64 + f26.f64));
	// fsubs f26,f25,f26
	f26.f64 = double(float(f25.f64 - f26.f64));
	// stfs f26,-192(r1)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r1.u32 + -192, temp.u32);
	// fadds f26,f21,f22
	f26.f64 = double(float(f21.f64 + f22.f64));
	// fsubs f22,f21,f22
	f22.f64 = double(float(f21.f64 - f22.f64));
	// fadds f25,f19,f20
	f25.f64 = double(float(f19.f64 + f20.f64));
	// fmsubs f29,f5,f13,f29
	f29.f64 = double(float(std::fma(ctx.f5.f64, ctx.f13.f64, -f29.f64)));
	// fmadds f5,f5,f12,f15
	ctx.f5.f64 = double(float(std::fma(ctx.f5.f64, ctx.f12.f64, f15.f64)));
	// lfs f15,28(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	f15.f64 = double(temp.f32);
	// fsubs f21,f19,f20
	f21.f64 = double(float(f19.f64 - f20.f64));
	// fadds f20,f26,f14
	f20.f64 = double(float(f26.f64 + f14.f64));
	// stfs f20,-168(r1)
	temp.f32 = float(f20.f64);
	REX_STORE_U32(ctx.r1.u32 + -168, temp.u32);
	// fsubs f26,f14,f26
	f26.f64 = double(float(f14.f64 - f26.f64));
	// stfs f26,-172(r1)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r1.u32 + -172, temp.u32);
	// fadds f26,f25,f4
	f26.f64 = double(float(f25.f64 + ctx.f4.f64));
	// stfs f26,-164(r1)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r1.u32 + -164, temp.u32);
	// fsubs f4,f4,f25
	ctx.f4.f64 = double(float(ctx.f4.f64 - f25.f64));
	// stfs f4,-176(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + -176, temp.u32);
	// lfs f4,-192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -192);
	ctx.f4.f64 = double(temp.f32);
	// fadds f19,f22,f4
	f19.f64 = double(float(f22.f64 + ctx.f4.f64));
	// lfs f4,120(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 120);
	ctx.f4.f64 = double(temp.f32);
	// lfs f25,60(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 60);
	f25.f64 = double(temp.f32);
	// fsubs f20,f28,f21
	f20.f64 = double(float(f28.f64 - f21.f64));
	// lfs f28,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	f28.f64 = double(temp.f32);
	// fadds f26,f28,f4
	f26.f64 = double(float(f28.f64 + ctx.f4.f64));
	// stfs f26,-184(r1)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r1.u32 + -184, temp.u32);
	// lfs f26,124(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 124);
	f26.f64 = double(temp.f32);
	// fsubs f4,f28,f4
	ctx.f4.f64 = double(float(f28.f64 - ctx.f4.f64));
	// fadds f14,f25,f26
	f14.f64 = double(float(f25.f64 + f26.f64));
	// stfs f14,-180(r1)
	temp.f32 = float(f14.f64);
	REX_STORE_U32(ctx.r1.u32 + -180, temp.u32);
	// fsubs f26,f25,f26
	f26.f64 = double(float(f25.f64 - f26.f64));
	// fsubs f25,f15,f16
	f25.f64 = double(float(f15.f64 - f16.f64));
	// fsubs f14,f20,f19
	f14.f64 = double(float(f20.f64 - f19.f64));
	// fadds f19,f19,f20
	f19.f64 = double(float(f19.f64 + f20.f64));
	// lfs f20,-188(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -188);
	f20.f64 = double(temp.f32);
	// fadds f21,f21,f20
	f21.f64 = double(float(f21.f64 + f20.f64));
	// lfs f20,-192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -192);
	f20.f64 = double(temp.f32);
	// fsubs f22,f20,f22
	f22.f64 = double(float(f20.f64 - f22.f64));
	// fsubs f20,f17,f18
	f20.f64 = double(float(f17.f64 - f18.f64));
	// fmuls f28,f14,f0
	f28.f64 = double(float(f14.f64 * ctx.f0.f64));
	// fmuls f19,f19,f0
	f19.f64 = double(float(f19.f64 * ctx.f0.f64));
	// fadds f14,f22,f21
	f14.f64 = double(float(f22.f64 + f21.f64));
	// fsubs f22,f22,f21
	f22.f64 = double(float(f22.f64 - f21.f64));
	// stfs f22,-188(r1)
	temp.f32 = float(f22.f64);
	REX_STORE_U32(ctx.r1.u32 + -188, temp.u32);
	// fadds f22,f17,f18
	f22.f64 = double(float(f17.f64 + f18.f64));
	// fadds f21,f15,f16
	f21.f64 = double(float(f15.f64 + f16.f64));
	// fmuls f18,f14,f0
	f18.f64 = double(float(f14.f64 * ctx.f0.f64));
	// lfs f15,-184(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -184);
	f15.f64 = double(temp.f32);
	// fadds f16,f15,f22
	f16.f64 = double(float(f15.f64 + f22.f64));
	// fsubs f22,f22,f15
	f22.f64 = double(float(f22.f64 - f15.f64));
	// stfs f22,-184(r1)
	temp.f32 = float(f22.f64);
	REX_STORE_U32(ctx.r1.u32 + -184, temp.u32);
	// lfs f22,-180(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -180);
	f22.f64 = double(temp.f32);
	// fadds f15,f22,f21
	f15.f64 = double(float(f22.f64 + f21.f64));
	// fsubs f22,f21,f22
	f22.f64 = double(float(f21.f64 - f22.f64));
	// stfs f22,-180(r1)
	temp.f32 = float(f22.f64);
	REX_STORE_U32(ctx.r1.u32 + -180, temp.u32);
	// fadds f21,f4,f25
	f21.f64 = double(float(ctx.f4.f64 + f25.f64));
	// fsubs f22,f20,f26
	f22.f64 = double(float(f20.f64 - f26.f64));
	// fadds f26,f26,f20
	f26.f64 = double(float(f26.f64 + f20.f64));
	// fsubs f4,f25,f4
	ctx.f4.f64 = double(float(f25.f64 - ctx.f4.f64));
	// fmr f20,f26
	f20.f64 = f26.f64;
	// lfs f14,-188(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -188);
	f14.f64 = double(temp.f32);
	// fmuls f17,f14,f0
	f17.f64 = double(float(f14.f64 * ctx.f0.f64));
	// stfs f15,-188(r1)
	temp.f32 = float(f15.f64);
	REX_STORE_U32(ctx.r1.u32 + -188, temp.u32);
	// fmuls f14,f21,f12
	f14.f64 = double(float(f21.f64 * ctx.f12.f64));
	// fmuls f21,f21,f13
	f21.f64 = double(float(f21.f64 * ctx.f13.f64));
	// fmr f15,f22
	f15.f64 = f22.f64;
	// fadds f25,f17,f11
	f25.f64 = double(float(f17.f64 + ctx.f11.f64));
	// fmsubs f22,f22,f13,f14
	f22.f64 = double(float(std::fma(f22.f64, ctx.f13.f64, -f14.f64)));
	// fmadds f21,f15,f12,f21
	f21.f64 = double(float(std::fma(f15.f64, ctx.f12.f64, f21.f64)));
	// fmuls f15,f26,f13
	f15.f64 = double(float(f26.f64 * ctx.f13.f64));
	// fsubs f26,f7,f18
	f26.f64 = double(float(ctx.f7.f64 - f18.f64));
	// fadds f7,f18,f7
	ctx.f7.f64 = double(float(f18.f64 + ctx.f7.f64));
	// fmuls f18,f4,f13
	f18.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fsubs f13,f11,f17
	ctx.f13.f64 = double(float(ctx.f11.f64 - f17.f64));
	// fmsubs f11,f20,f12,f18
	ctx.f11.f64 = double(float(std::fma(f20.f64, ctx.f12.f64, -f18.f64)));
	// fmadds f12,f4,f12,f15
	ctx.f12.f64 = double(float(std::fma(ctx.f4.f64, ctx.f12.f64, f15.f64)));
	// fsubs f4,f29,f11
	ctx.f4.f64 = double(float(f29.f64 - ctx.f11.f64));
	// fsubs f20,f5,f12
	f20.f64 = double(float(ctx.f5.f64 - ctx.f12.f64));
	// fadds f12,f12,f5
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f5.f64));
	// fadds f11,f11,f29
	ctx.f11.f64 = double(float(ctx.f11.f64 + f29.f64));
	// fadds f5,f4,f26
	ctx.f5.f64 = double(float(ctx.f4.f64 + f26.f64));
	// stfs f5,96(r3)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// fadds f5,f20,f13
	ctx.f5.f64 = double(float(f20.f64 + ctx.f13.f64));
	// stfs f5,100(r3)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// fsubs f5,f26,f4
	ctx.f5.f64 = double(float(f26.f64 - ctx.f4.f64));
	// stfs f5,104(r3)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// fsubs f13,f13,f20
	ctx.f13.f64 = double(float(ctx.f13.f64 - f20.f64));
	// stfs f13,108(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// fadds f13,f28,f24
	ctx.f13.f64 = double(float(f28.f64 + f24.f64));
	// fadds f5,f19,f23
	ctx.f5.f64 = double(float(f19.f64 + f23.f64));
	// fadds f4,f22,f3
	ctx.f4.f64 = double(float(f22.f64 + ctx.f3.f64));
	// fadds f29,f21,f2
	f29.f64 = double(float(f21.f64 + ctx.f2.f64));
	// fsubs f26,f7,f12
	f26.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// stfs f26,112(r3)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// fadds f12,f12,f7
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f7.f64));
	// stfs f12,120(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// fsubs f7,f3,f22
	ctx.f7.f64 = double(float(ctx.f3.f64 - f22.f64));
	// fsubs f3,f2,f21
	ctx.f3.f64 = double(float(ctx.f2.f64 - f21.f64));
	// fsubs f12,f25,f11
	ctx.f12.f64 = double(float(f25.f64 - ctx.f11.f64));
	// stfs f12,124(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// fadds f26,f11,f25
	f26.f64 = double(float(ctx.f11.f64 + f25.f64));
	// stfs f26,116(r3)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// fsubs f11,f23,f19
	ctx.f11.f64 = double(float(f23.f64 - f19.f64));
	// fsubs f12,f24,f28
	ctx.f12.f64 = double(float(f24.f64 - f28.f64));
	// fadds f2,f4,f13
	ctx.f2.f64 = double(float(ctx.f4.f64 + ctx.f13.f64));
	// stfs f2,64(r3)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// fsubs f13,f13,f4
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f4.f64));
	// stfs f13,72(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// fadds f2,f29,f5
	ctx.f2.f64 = double(float(f29.f64 + ctx.f5.f64));
	// stfs f2,68(r3)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// fsubs f13,f5,f29
	ctx.f13.f64 = double(float(ctx.f5.f64 - f29.f64));
	// lfs f2,-184(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -184);
	ctx.f2.f64 = double(temp.f32);
	// lfs f29,-180(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -180);
	f29.f64 = double(temp.f32);
	// fadds f5,f2,f30
	ctx.f5.f64 = double(float(ctx.f2.f64 + f30.f64));
	// stfs f13,76(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// fsubs f13,f9,f29
	ctx.f13.f64 = double(float(ctx.f9.f64 - f29.f64));
	// fadds f4,f7,f11
	ctx.f4.f64 = double(float(ctx.f7.f64 + ctx.f11.f64));
	// stfs f4,84(r3)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// fsubs f4,f12,f3
	ctx.f4.f64 = double(float(ctx.f12.f64 - ctx.f3.f64));
	// stfs f4,80(r3)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// fadds f12,f3,f12
	ctx.f12.f64 = double(float(ctx.f3.f64 + ctx.f12.f64));
	// stfs f12,88(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// fsubs f12,f11,f7
	ctx.f12.f64 = double(float(ctx.f11.f64 - ctx.f7.f64));
	// lfs f3,-176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -176);
	ctx.f3.f64 = double(temp.f32);
	// lfs f4,-172(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -172);
	ctx.f4.f64 = double(temp.f32);
	// stfs f12,92(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// fadds f12,f3,f10
	ctx.f12.f64 = double(float(ctx.f3.f64 + ctx.f10.f64));
	// fsubs f11,f8,f4
	ctx.f11.f64 = double(float(ctx.f8.f64 - ctx.f4.f64));
	// fsubs f7,f13,f5
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f5.f64));
	// fadds f5,f5,f13
	ctx.f5.f64 = double(float(ctx.f5.f64 + ctx.f13.f64));
	// fadds f13,f29,f9
	ctx.f13.f64 = double(float(f29.f64 + ctx.f9.f64));
	// fsubs f9,f30,f2
	ctx.f9.f64 = double(float(f30.f64 - ctx.f2.f64));
	// fmuls f7,f7,f0
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// fmuls f5,f5,f0
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// fsubs f2,f13,f9
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// fadds f30,f9,f13
	f30.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// fsubs f13,f10,f3
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f3.f64));
	// fadds f10,f4,f8
	ctx.f10.f64 = double(float(ctx.f4.f64 + ctx.f8.f64));
	// fmuls f9,f2,f0
	ctx.f9.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// fmuls f0,f30,f0
	ctx.f0.f64 = double(float(f30.f64 * ctx.f0.f64));
	// fadds f8,f7,f13
	ctx.f8.f64 = double(float(ctx.f7.f64 + ctx.f13.f64));
	// stfs f8,32(r3)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// fsubs f13,f13,f7
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f7.f64));
	// stfs f13,40(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// fsubs f13,f10,f5
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f5.f64));
	// stfs f13,44(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// fadds f8,f5,f10
	ctx.f8.f64 = double(float(ctx.f5.f64 + ctx.f10.f64));
	// lfs f7,-188(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -188);
	ctx.f7.f64 = double(temp.f32);
	// fadds f10,f16,f1
	ctx.f10.f64 = double(float(f16.f64 + ctx.f1.f64));
	// stfs f8,36(r3)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// fsubs f8,f1,f16
	ctx.f8.f64 = double(float(ctx.f1.f64 - f16.f64));
	// fsubs f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f0,56(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// lfs f12,-168(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -168);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f11,f9
	ctx.f0.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// fadds f13,f9,f11
	ctx.f13.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// stfs f0,60(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// lfs f11,-164(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -164);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f12,f6
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f6.f64));
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// fadds f9,f7,f31
	ctx.f9.f64 = double(float(ctx.f7.f64 + f31.f64));
	// fadds f13,f11,f27
	ctx.f13.f64 = double(float(ctx.f11.f64 + f27.f64));
	// fsubs f12,f6,f12
	ctx.f12.f64 = double(float(ctx.f6.f64 - ctx.f12.f64));
	// fsubs f11,f27,f11
	ctx.f11.f64 = double(float(f27.f64 - ctx.f11.f64));
	// fsubs f7,f31,f7
	ctx.f7.f64 = double(float(f31.f64 - ctx.f7.f64));
	// fadds f6,f10,f0
	ctx.f6.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// stfs f6,0(r3)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fadds f6,f9,f13
	ctx.f6.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// stfs f6,4(r3)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fsubs f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f10.f64));
	// stfs f0,8(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fsubs f0,f13,f9
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// stfs f0,12(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fsubs f0,f12,f7
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// stfs f0,16(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// fadds f0,f8,f11
	ctx.f0.f64 = double(float(ctx.f8.f64 + ctx.f11.f64));
	// stfs f0,20(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// fadds f0,f7,f12
	ctx.f0.f64 = double(float(ctx.f7.f64 + ctx.f12.f64));
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// fsubs f0,f11,f8
	ctx.f0.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// stfs f0,28(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82a0133c
	ctx.lr = 0x82A82564;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A82570) {
	REX_FUNC_PROLOGUE();
	PPCRegister f14{};
	PPCRegister f15{};
	PPCRegister f16{};
	PPCRegister f17{};
	PPCRegister f18{};
	PPCRegister f19{};
	PPCRegister f20{};
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82a012f0
	ctx.lr = 0x82A82580;
	// lfs f6,100(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 100);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,96(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,36(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f4.f64 = double(temp.f32);
	// lfs f7,32(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// fadds f21,f4,f5
	f21.f64 = double(float(ctx.f4.f64 + ctx.f5.f64));
	// fsubs f22,f7,f6
	f22.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// lfs f0,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fadds f7,f6,f7
	ctx.f7.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// lfs f28,64(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 64);
	f28.f64 = double(temp.f32);
	// fsubs f6,f4,f5
	ctx.f6.f64 = double(float(ctx.f4.f64 - ctx.f5.f64));
	// lfs f27,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	f27.f64 = double(temp.f32);
	// fadds f19,f27,f28
	f19.f64 = double(float(f27.f64 + f28.f64));
	// lfs f3,8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,76(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,72(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	f31.f64 = double(temp.f32);
	// lfs f29,68(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 68);
	f29.f64 = double(temp.f32);
	// lfs f30,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	f30.f64 = double(temp.f32);
	// fsubs f20,f30,f29
	f20.f64 = double(float(f30.f64 - f29.f64));
	// lfs f13,16(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f18,f22,f21
	f18.f64 = double(float(f22.f64 - f21.f64));
	// lfs f12,20(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fadds f22,f21,f22
	f22.f64 = double(float(f21.f64 + f22.f64));
	// lfs f24,104(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 104);
	f24.f64 = double(temp.f32);
	// fadds f17,f6,f7
	f17.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// lfs f23,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	f23.f64 = double(temp.f32);
	// fadds f30,f29,f30
	f30.f64 = double(float(f29.f64 + f30.f64));
	// lfs f26,40(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	f26.f64 = double(temp.f32);
	// fsubs f29,f27,f28
	f29.f64 = double(float(f27.f64 - f28.f64));
	// lfs f25,108(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 108);
	f25.f64 = double(temp.f32);
	// lfs f11,24(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,28(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,32(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,36(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 36);
	ctx.f8.f64 = double(temp.f32);
	// lfs f15,116(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 116);
	f15.f64 = double(temp.f32);
	// fmuls f5,f18,f0
	ctx.f5.f64 = double(float(f18.f64 * ctx.f0.f64));
	// fsubs f18,f7,f6
	f18.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fmuls f4,f22,f0
	ctx.f4.f64 = double(float(f22.f64 * ctx.f0.f64));
	// fsubs f7,f3,f2
	ctx.f7.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f6,f31,f1
	ctx.f6.f64 = double(float(f31.f64 + ctx.f1.f64));
	// fmuls f27,f17,f0
	f27.f64 = double(float(f17.f64 * ctx.f0.f64));
	// fadds f22,f5,f20
	f22.f64 = double(float(ctx.f5.f64 + f20.f64));
	// fmuls f28,f18,f0
	f28.f64 = double(float(f18.f64 * ctx.f0.f64));
	// fadds f21,f4,f19
	f21.f64 = double(float(ctx.f4.f64 + f19.f64));
	// fsubs f4,f19,f4
	ctx.f4.f64 = double(float(f19.f64 - ctx.f4.f64));
	// fmr f19,f7
	f19.f64 = ctx.f7.f64;
	// fmuls f18,f6,f12
	f18.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// fmuls f16,f6,f13
	f16.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fadds f6,f23,f24
	ctx.f6.f64 = double(float(f23.f64 + f24.f64));
	// fsubs f5,f20,f5
	ctx.f5.f64 = double(float(f20.f64 - ctx.f5.f64));
	// fmr f17,f7
	f17.f64 = ctx.f7.f64;
	// fsubs f7,f26,f25
	ctx.f7.f64 = double(float(f26.f64 - f25.f64));
	// fadds f20,f28,f29
	f20.f64 = double(float(f28.f64 + f29.f64));
	// fsubs f29,f29,f28
	f29.f64 = double(float(f29.f64 - f28.f64));
	// fsubs f28,f30,f27
	f28.f64 = double(float(f30.f64 - f27.f64));
	// fadds f30,f27,f30
	f30.f64 = double(float(f27.f64 + f30.f64));
	// fmsubs f27,f19,f13,f18
	f27.f64 = double(float(std::fma(f19.f64, ctx.f13.f64, -f18.f64)));
	// fmuls f18,f6,f11
	f18.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fmadds f19,f17,f12,f16
	f19.f64 = double(float(std::fma(f17.f64, ctx.f12.f64, f16.f64)));
	// fmuls f16,f7,f11
	f16.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// fmr f17,f6
	f17.f64 = ctx.f6.f64;
	// fadds f6,f2,f3
	ctx.f6.f64 = double(float(ctx.f2.f64 + ctx.f3.f64));
	// stfs f6,-200(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + -200, temp.u32);
	// fsubs f2,f31,f1
	ctx.f2.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lfs f3,16(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,84(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,80(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 80);
	f31.f64 = double(temp.f32);
	// fmsubs f7,f7,f10,f18
	ctx.f7.f64 = double(float(std::fma(ctx.f7.f64, ctx.f10.f64, -f18.f64)));
	// fmadds f18,f17,f10,f16
	f18.f64 = double(float(std::fma(f17.f64, ctx.f10.f64, f16.f64)));
	// lfs f17,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	f17.f64 = double(temp.f32);
	// lfs f16,48(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	f16.f64 = double(temp.f32);
	// fadds f14,f7,f27
	f14.f64 = double(float(ctx.f7.f64 + f27.f64));
	// fsubs f7,f27,f7
	ctx.f7.f64 = double(float(f27.f64 - ctx.f7.f64));
	// stfs f7,-192(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -192, temp.u32);
	// fmr f7,f6
	ctx.f7.f64 = ctx.f6.f64;
	// stfs f7,-204(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -204, temp.u32);
	// fmuls f27,f2,f10
	f27.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// fmuls f2,f2,f11
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f11.f64));
	// stfs f2,-196(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -196, temp.u32);
	// fadds f7,f25,f26
	ctx.f7.f64 = double(float(f25.f64 + f26.f64));
	// fsubs f6,f23,f24
	ctx.f6.f64 = double(float(f23.f64 - f24.f64));
	// stfs f27,-208(r1)
	temp.f32 = float(f27.f64);
	REX_STORE_U32(ctx.r1.u32 + -208, temp.u32);
	// fadds f2,f18,f19
	ctx.f2.f64 = double(float(f18.f64 + f19.f64));
	// lfs f26,-204(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -204);
	f26.f64 = double(temp.f32);
	// fsubs f27,f19,f18
	f27.f64 = double(float(f19.f64 - f18.f64));
	// lfs f24,-196(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -196);
	f24.f64 = double(temp.f32);
	// fmuls f19,f7,f12
	f19.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// fmr f23,f6
	f23.f64 = ctx.f6.f64;
	// lfs f25,-208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -208);
	f25.f64 = double(temp.f32);
	// fmsubs f25,f26,f11,f25
	f25.f64 = double(float(std::fma(f26.f64, ctx.f11.f64, -f25.f64)));
	// stfs f25,-204(r1)
	temp.f32 = float(f25.f64);
	REX_STORE_U32(ctx.r1.u32 + -204, temp.u32);
	// lfs f26,-200(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -200);
	f26.f64 = double(temp.f32);
	// fmadds f26,f26,f10,f24
	f26.f64 = double(float(std::fma(f26.f64, ctx.f10.f64, f24.f64)));
	// stfs f26,-208(r1)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r1.u32 + -208, temp.u32);
	// fmuls f26,f7,f13
	f26.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// fmr f24,f6
	f24.f64 = ctx.f6.f64;
	// fsubs f7,f3,f1
	ctx.f7.f64 = double(float(ctx.f3.f64 - ctx.f1.f64));
	// fadds f6,f17,f31
	ctx.f6.f64 = double(float(f17.f64 + f31.f64));
	// fadds f3,f1,f3
	ctx.f3.f64 = double(float(ctx.f1.f64 + ctx.f3.f64));
	// fsubs f1,f17,f31
	ctx.f1.f64 = double(float(f17.f64 - f31.f64));
	// fmadds f26,f24,f12,f26
	f26.f64 = double(float(std::fma(f24.f64, ctx.f12.f64, f26.f64)));
	// fmsubs f24,f23,f13,f19
	f24.f64 = double(float(std::fma(f23.f64, ctx.f13.f64, -f19.f64)));
	// stfs f24,-196(r1)
	temp.f32 = float(f24.f64);
	REX_STORE_U32(ctx.r1.u32 + -196, temp.u32);
	// fmr f18,f7
	f18.f64 = ctx.f7.f64;
	// fmr f23,f7
	f23.f64 = ctx.f7.f64;
	// fmuls f7,f6,f9
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f9.f64));
	// stfs f7,-200(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -200, temp.u32);
	// fmuls f19,f6,f8
	f19.f64 = double(float(ctx.f6.f64 * ctx.f8.f64));
	// lfs f6,52(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f6.f64 = double(temp.f32);
	// lfs f7,112(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// fmr f17,f1
	f17.f64 = ctx.f1.f64;
	// fsubs f25,f25,f26
	f25.f64 = double(float(f25.f64 - f26.f64));
	// stfs f25,-176(r1)
	temp.f32 = float(f25.f64);
	REX_STORE_U32(ctx.r1.u32 + -176, temp.u32);
	// fmsubs f23,f23,f9,f19
	f23.f64 = double(float(std::fma(f23.f64, ctx.f9.f64, -f19.f64)));
	// lfs f25,-204(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -204);
	f25.f64 = double(temp.f32);
	// fadds f26,f26,f25
	f26.f64 = double(float(f26.f64 + f25.f64));
	// stfs f26,-188(r1)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r1.u32 + -188, temp.u32);
	// fmr f26,f24
	f26.f64 = f24.f64;
	// lfs f25,-208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -208);
	f25.f64 = double(temp.f32);
	// fsubs f25,f25,f26
	f25.f64 = double(float(f25.f64 - f26.f64));
	// stfs f25,-172(r1)
	temp.f32 = float(f25.f64);
	REX_STORE_U32(ctx.r1.u32 + -172, temp.u32);
	// lfs f25,-208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -208);
	f25.f64 = double(temp.f32);
	// fadds f24,f26,f25
	f24.f64 = double(float(f26.f64 + f25.f64));
	// fadds f25,f6,f7
	f25.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// fsubs f7,f6,f7
	ctx.f7.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// lfs f19,-200(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -200);
	f19.f64 = double(temp.f32);
	// fmadds f26,f18,f8,f19
	f26.f64 = double(float(std::fma(f18.f64, ctx.f8.f64, f19.f64)));
	// stfs f26,-208(r1)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r1.u32 + -208, temp.u32);
	// fsubs f26,f16,f15
	f26.f64 = double(float(f16.f64 - f15.f64));
	// fmuls f19,f25,f9
	f19.f64 = double(float(f25.f64 * ctx.f9.f64));
	// fmuls f18,f26,f9
	f18.f64 = double(float(f26.f64 * ctx.f9.f64));
	// fmsubs f31,f26,f8,f19
	f31.f64 = double(float(std::fma(f26.f64, ctx.f8.f64, -f19.f64)));
	// fmr f19,f3
	f19.f64 = ctx.f3.f64;
	// fmuls f3,f3,f9
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f9.f64));
	// stfs f3,-196(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + -196, temp.u32);
	// fadds f3,f15,f16
	ctx.f3.f64 = double(float(f15.f64 + f16.f64));
	// fmuls f16,f7,f8
	f16.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// fmadds f26,f25,f8,f18
	f26.f64 = double(float(std::fma(f25.f64, ctx.f8.f64, f18.f64)));
	// fmuls f18,f1,f9
	f18.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// fmuls f15,f7,f9
	f15.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// fadds f6,f31,f23
	ctx.f6.f64 = double(float(f31.f64 + f23.f64));
	// fsubs f1,f23,f31
	ctx.f1.f64 = double(float(f23.f64 - f31.f64));
	// fmsubs f7,f3,f9,f16
	ctx.f7.f64 = double(float(std::fma(ctx.f3.f64, ctx.f9.f64, -f16.f64)));
	// lfs f9,28(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f9.f64 = double(temp.f32);
	// lfs f25,-208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -208);
	f25.f64 = double(temp.f32);
	// fadds f31,f26,f25
	f31.f64 = double(float(f26.f64 + f25.f64));
	// fsubs f26,f25,f26
	f26.f64 = double(float(f25.f64 - f26.f64));
	// fmsubs f25,f19,f8,f18
	f25.f64 = double(float(std::fma(f19.f64, ctx.f8.f64, -f18.f64)));
	// lfs f18,92(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 92);
	f18.f64 = double(temp.f32);
	// lfs f19,-196(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -196);
	f19.f64 = double(temp.f32);
	// fmadds f23,f17,f8,f19
	f23.f64 = double(float(std::fma(f17.f64, ctx.f8.f64, f19.f64)));
	// lfs f19,24(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 24);
	f19.f64 = double(temp.f32);
	// fmadds f8,f3,f8,f15
	ctx.f8.f64 = double(float(std::fma(ctx.f3.f64, ctx.f8.f64, f15.f64)));
	// lfs f17,88(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 88);
	f17.f64 = double(temp.f32);
	// fsubs f15,f25,f7
	f15.f64 = double(float(f25.f64 - ctx.f7.f64));
	// stfs f15,-184(r1)
	temp.f32 = float(f15.f64);
	REX_STORE_U32(ctx.r1.u32 + -184, temp.u32);
	// fadds f7,f7,f25
	ctx.f7.f64 = double(float(ctx.f7.f64 + f25.f64));
	// stfs f7,-164(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -164, temp.u32);
	// fsubs f3,f19,f18
	ctx.f3.f64 = double(float(f19.f64 - f18.f64));
	// fadds f16,f9,f17
	f16.f64 = double(float(ctx.f9.f64 + f17.f64));
	// fsubs f7,f23,f8
	ctx.f7.f64 = double(float(f23.f64 - ctx.f8.f64));
	// stfs f7,-180(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -180, temp.u32);
	// fadds f8,f8,f23
	ctx.f8.f64 = double(float(ctx.f8.f64 + f23.f64));
	// stfs f8,-168(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -168, temp.u32);
	// fmuls f8,f16,f10
	ctx.f8.f64 = double(float(f16.f64 * ctx.f10.f64));
	// stfs f8,-196(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -196, temp.u32);
	// fmr f25,f3
	f25.f64 = ctx.f3.f64;
	// lfs f7,120(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 120);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f16,f16,f11
	f16.f64 = double(float(f16.f64 * ctx.f11.f64));
	// lfs f8,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f8.f64 = double(temp.f32);
	// fmr f15,f3
	f15.f64 = ctx.f3.f64;
	// lfs f3,60(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 60);
	ctx.f3.f64 = double(temp.f32);
	// fadds f23,f3,f7
	f23.f64 = double(float(ctx.f3.f64 + ctx.f7.f64));
	// stfs f23,-200(r1)
	temp.f32 = float(f23.f64);
	REX_STORE_U32(ctx.r1.u32 + -200, temp.u32);
	// fsubs f9,f9,f17
	ctx.f9.f64 = double(float(ctx.f9.f64 - f17.f64));
	// fmuls f17,f9,f13
	f17.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// lfs f3,-196(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -196);
	ctx.f3.f64 = double(temp.f32);
	// fmsubs f3,f25,f11,f3
	ctx.f3.f64 = double(float(std::fma(f25.f64, ctx.f11.f64, -ctx.f3.f64)));
	// stfs f3,-204(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + -204, temp.u32);
	// fmadds f3,f15,f10,f16
	ctx.f3.f64 = double(float(std::fma(f15.f64, ctx.f10.f64, f16.f64)));
	// stfs f3,-208(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + -208, temp.u32);
	// lfs f3,124(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 124);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f15,f23,f13
	f15.f64 = double(float(f23.f64 * ctx.f13.f64));
	// fsubs f25,f8,f3
	f25.f64 = double(float(ctx.f8.f64 - ctx.f3.f64));
	// fmr f16,f25
	f16.f64 = f25.f64;
	// fmuls f25,f25,f13
	f25.f64 = double(float(f25.f64 * ctx.f13.f64));
	// stfs f25,-196(r1)
	temp.f32 = float(f25.f64);
	REX_STORE_U32(ctx.r1.u32 + -196, temp.u32);
	// fadds f25,f18,f19
	f25.f64 = double(float(f18.f64 + f19.f64));
	// fmsubs f23,f16,f12,f15
	f23.f64 = double(float(std::fma(f16.f64, ctx.f12.f64, -f15.f64)));
	// lfs f15,-200(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -200);
	f15.f64 = double(temp.f32);
	// fmr f18,f25
	f18.f64 = f25.f64;
	// lfs f16,-196(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -196);
	f16.f64 = double(temp.f32);
	// fmadds f19,f15,f12,f16
	f19.f64 = double(float(std::fma(f15.f64, ctx.f12.f64, f16.f64)));
	// fmr f16,f9
	f16.f64 = ctx.f9.f64;
	// lfs f9,60(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 60);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f9,f9,f7
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f7.f64));
	// lfs f7,-204(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -204);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f15,f25,f13
	f15.f64 = double(float(f25.f64 * ctx.f13.f64));
	// lfs f25,-208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -208);
	f25.f64 = double(temp.f32);
	// fadds f13,f3,f8
	ctx.f13.f64 = double(float(ctx.f3.f64 + ctx.f8.f64));
	// fadds f8,f23,f7
	ctx.f8.f64 = double(float(f23.f64 + ctx.f7.f64));
	// fsubs f7,f7,f23
	ctx.f7.f64 = double(float(ctx.f7.f64 - f23.f64));
	// fmadds f23,f18,f12,f17
	f23.f64 = double(float(std::fma(f18.f64, ctx.f12.f64, f17.f64)));
	// fadds f3,f19,f25
	ctx.f3.f64 = double(float(f19.f64 + f25.f64));
	// fsubs f25,f25,f19
	f25.f64 = double(float(f25.f64 - f19.f64));
	// fmuls f19,f9,f11
	f19.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fmsubs f12,f16,f12,f15
	ctx.f12.f64 = double(float(std::fma(f16.f64, ctx.f12.f64, -f15.f64)));
	// lfs f15,-192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -192);
	f15.f64 = double(temp.f32);
	// fmuls f11,f13,f11
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fadds f18,f3,f2
	f18.f64 = double(float(ctx.f3.f64 + ctx.f2.f64));
	// fsubs f17,f15,f25
	f17.f64 = double(float(f15.f64 - f25.f64));
	// fmsubs f13,f13,f10,f19
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f10.f64, -f19.f64)));
	// fmadds f11,f9,f10,f11
	ctx.f11.f64 = double(float(std::fma(ctx.f9.f64, ctx.f10.f64, ctx.f11.f64)));
	// fadds f9,f6,f22
	ctx.f9.f64 = double(float(ctx.f6.f64 + f22.f64));
	// fadds f10,f13,f23
	ctx.f10.f64 = double(float(ctx.f13.f64 + f23.f64));
	// fsubs f13,f23,f13
	ctx.f13.f64 = double(float(f23.f64 - ctx.f13.f64));
	// fadds f23,f8,f14
	f23.f64 = double(float(ctx.f8.f64 + f14.f64));
	// fadds f19,f11,f12
	f19.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// fsubs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fadds f11,f31,f21
	ctx.f11.f64 = double(float(f31.f64 + f21.f64));
	// fsubs f8,f14,f8
	ctx.f8.f64 = double(float(f14.f64 - ctx.f8.f64));
	// fadds f16,f23,f9
	f16.f64 = double(float(f23.f64 + ctx.f9.f64));
	// stfs f16,0(r3)
	temp.f32 = float(f16.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fsubs f9,f9,f23
	ctx.f9.f64 = double(float(ctx.f9.f64 - f23.f64));
	// stfs f9,8(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fadds f16,f7,f27
	f16.f64 = double(float(ctx.f7.f64 + f27.f64));
	// fadds f9,f18,f11
	ctx.f9.f64 = double(float(f18.f64 + ctx.f11.f64));
	// stfs f9,4(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fsubs f9,f21,f31
	ctx.f9.f64 = double(float(f21.f64 - f31.f64));
	// fsubs f11,f11,f18
	ctx.f11.f64 = double(float(ctx.f11.f64 - f18.f64));
	// stfs f11,12(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fsubs f11,f22,f6
	ctx.f11.f64 = double(float(f22.f64 - ctx.f6.f64));
	// fsubs f6,f2,f3
	ctx.f6.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// fsubs f7,f27,f7
	ctx.f7.f64 = double(float(f27.f64 - ctx.f7.f64));
	// fadds f3,f25,f15
	ctx.f3.f64 = double(float(f25.f64 + f15.f64));
	// fsubs f2,f17,f16
	ctx.f2.f64 = double(float(f17.f64 - f16.f64));
	// fadds f31,f16,f17
	f31.f64 = double(float(f16.f64 + f17.f64));
	// fadds f27,f8,f9
	f27.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// stfs f27,20(r3)
	temp.f32 = float(f27.f64);
	REX_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// fsubs f9,f9,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// stfs f9,28(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// fsubs f9,f11,f6
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f6.f64));
	// stfs f9,16(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// fadds f11,f6,f11
	ctx.f11.f64 = double(float(ctx.f6.f64 + ctx.f11.f64));
	// stfs f11,24(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// fsubs f11,f5,f26
	ctx.f11.f64 = double(float(ctx.f5.f64 - f26.f64));
	// fmuls f8,f2,f0
	ctx.f8.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// fadds f9,f1,f4
	ctx.f9.f64 = double(float(ctx.f1.f64 + ctx.f4.f64));
	// fmuls f6,f31,f0
	ctx.f6.f64 = double(float(f31.f64 * ctx.f0.f64));
	// lfs f31,-188(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -188);
	f31.f64 = double(temp.f32);
	// fsubs f2,f3,f7
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f7.f64));
	// fadds f27,f7,f3
	f27.f64 = double(float(ctx.f7.f64 + ctx.f3.f64));
	// fsubs f3,f24,f13
	ctx.f3.f64 = double(float(f24.f64 - ctx.f13.f64));
	// fadds f7,f12,f31
	ctx.f7.f64 = double(float(ctx.f12.f64 + f31.f64));
	// fadds f13,f13,f24
	ctx.f13.f64 = double(float(ctx.f13.f64 + f24.f64));
	// fsubs f12,f31,f12
	ctx.f12.f64 = double(float(f31.f64 - ctx.f12.f64));
	// fadds f25,f8,f11
	f25.f64 = double(float(ctx.f8.f64 + ctx.f11.f64));
	// stfs f25,32(r3)
	temp.f32 = float(f25.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// fsubs f11,f11,f8
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// stfs f11,40(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// fadds f11,f6,f9
	ctx.f11.f64 = double(float(ctx.f6.f64 + ctx.f9.f64));
	// stfs f11,36(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// fsubs f11,f9,f6
	ctx.f11.f64 = double(float(ctx.f9.f64 - ctx.f6.f64));
	// stfs f11,44(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// fsubs f9,f4,f1
	ctx.f9.f64 = double(float(ctx.f4.f64 - ctx.f1.f64));
	// lfs f4,-180(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -180);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f8,f2,f0
	ctx.f8.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// lfs f2,-176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -176);
	ctx.f2.f64 = double(temp.f32);
	// fadds f11,f26,f5
	ctx.f11.f64 = double(float(f26.f64 + ctx.f5.f64));
	// lfs f1,-172(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -172);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f6,f27,f0
	ctx.f6.f64 = double(float(f27.f64 * ctx.f0.f64));
	// fsubs f27,f7,f3
	f27.f64 = double(float(ctx.f7.f64 - ctx.f3.f64));
	// fadds f7,f3,f7
	ctx.f7.f64 = double(float(ctx.f3.f64 + ctx.f7.f64));
	// fadds f5,f8,f9
	ctx.f5.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// stfs f5,52(r3)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// fsubs f9,f9,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// stfs f9,60(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// fsubs f9,f11,f6
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f6.f64));
	// lfs f5,-184(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -184);
	ctx.f5.f64 = double(temp.f32);
	// fadds f11,f6,f11
	ctx.f11.f64 = double(float(ctx.f6.f64 + ctx.f11.f64));
	// stfs f11,56(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// fsubs f8,f2,f10
	ctx.f8.f64 = double(float(ctx.f2.f64 - ctx.f10.f64));
	// stfs f9,48(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// fadds f11,f5,f28
	ctx.f11.f64 = double(float(ctx.f5.f64 + f28.f64));
	// fadds f9,f4,f20
	ctx.f9.f64 = double(float(ctx.f4.f64 + f20.f64));
	// fsubs f6,f1,f19
	ctx.f6.f64 = double(float(ctx.f1.f64 - f19.f64));
	// fadds f10,f10,f2
	ctx.f10.f64 = double(float(ctx.f10.f64 + ctx.f2.f64));
	// fadds f26,f8,f11
	f26.f64 = double(float(ctx.f8.f64 + ctx.f11.f64));
	// stfs f26,64(r3)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// fsubs f11,f11,f8
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// stfs f11,72(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// fadds f11,f6,f9
	ctx.f11.f64 = double(float(ctx.f6.f64 + ctx.f9.f64));
	// stfs f11,68(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// fsubs f11,f9,f6
	ctx.f11.f64 = double(float(ctx.f9.f64 - ctx.f6.f64));
	// stfs f11,76(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// fsubs f9,f20,f4
	ctx.f9.f64 = double(float(f20.f64 - ctx.f4.f64));
	// fsubs f11,f28,f5
	ctx.f11.f64 = double(float(f28.f64 - ctx.f5.f64));
	// fadds f8,f19,f1
	ctx.f8.f64 = double(float(f19.f64 + ctx.f1.f64));
	// fadds f6,f10,f9
	ctx.f6.f64 = double(float(ctx.f10.f64 + ctx.f9.f64));
	// stfs f6,84(r3)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// fsubs f10,f9,f10
	ctx.f10.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// stfs f10,92(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// fsubs f10,f11,f8
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// lfs f6,-168(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -168);
	ctx.f6.f64 = double(temp.f32);
	// fadds f11,f8,f11
	ctx.f11.f64 = double(float(ctx.f8.f64 + ctx.f11.f64));
	// stfs f11,88(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// fsubs f11,f30,f6
	ctx.f11.f64 = double(float(f30.f64 - ctx.f6.f64));
	// lfs f8,-164(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -164);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f9,f27,f0
	ctx.f9.f64 = double(float(f27.f64 * ctx.f0.f64));
	// stfs f10,80(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// fadds f10,f8,f29
	ctx.f10.f64 = double(float(ctx.f8.f64 + f29.f64));
	// fadds f5,f9,f11
	ctx.f5.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// stfs f5,96(r3)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// fsubs f11,f11,f9
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// stfs f11,104(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// fmuls f9,f7,f0
	ctx.f9.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// fadds f11,f6,f30
	ctx.f11.f64 = double(float(ctx.f6.f64 + f30.f64));
	// fsubs f7,f12,f13
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fadds f6,f13,f12
	ctx.f6.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fadds f13,f9,f10
	ctx.f13.f64 = double(float(ctx.f9.f64 + ctx.f10.f64));
	// stfs f13,100(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// fsubs f13,f10,f9
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// stfs f13,108(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// fsubs f13,f29,f8
	ctx.f13.f64 = double(float(f29.f64 - ctx.f8.f64));
	// fmuls f12,f7,f0
	ctx.f12.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// fmuls f0,f6,f0
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// fadds f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f10,116(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// stfs f10,112(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// fadds f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// stfs f0,120(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// fsubs f0,f13,f12
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// stfs f0,124(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82a0133c
	ctx.lr = 0x82A82AC0;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A82AD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82a01318
	ctx.lr = 0x82A82AE0;
	// lfs f11,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,32(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,36(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// fadds f28,f11,f13
	f28.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// lfs f7,52(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f7.f64 = double(temp.f32);
	// fadds f27,f10,f12
	f27.f64 = double(float(ctx.f10.f64 + ctx.f12.f64));
	// lfs f9,48(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f8,16(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f12,f10,f12
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// lfs f6,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// fadds f11,f8,f9
	ctx.f11.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// fadds f10,f6,f7
	ctx.f10.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// lfs f5,40(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f9,f8,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// lfs f3,8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f8,f6,f7
	ctx.f8.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// lfs f4,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f4.f64 = double(temp.f32);
	// lfs f2,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f1.f64 = double(temp.f32);
	// fadds f26,f2,f4
	f26.f64 = double(float(ctx.f2.f64 + ctx.f4.f64));
	// lfs f30,60(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 60);
	f30.f64 = double(temp.f32);
	// lfs f31,24(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 24);
	f31.f64 = double(temp.f32);
	// lfs f29,28(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	f29.f64 = double(temp.f32);
	// fadds f25,f31,f1
	f25.f64 = double(float(f31.f64 + ctx.f1.f64));
	// fadds f24,f29,f30
	f24.f64 = double(float(f29.f64 + f30.f64));
	// lfs f0,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fadds f7,f11,f28
	ctx.f7.f64 = double(float(ctx.f11.f64 + f28.f64));
	// fadds f6,f10,f27
	ctx.f6.f64 = double(float(ctx.f10.f64 + f27.f64));
	// fsubs f11,f28,f11
	ctx.f11.f64 = double(float(f28.f64 - ctx.f11.f64));
	// fsubs f10,f27,f10
	ctx.f10.f64 = double(float(f27.f64 - ctx.f10.f64));
	// fsubs f28,f13,f8
	f28.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// fadds f27,f9,f12
	f27.f64 = double(float(ctx.f9.f64 + ctx.f12.f64));
	// fsubs f12,f12,f9
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f9.f64));
	// fadds f13,f8,f13
	ctx.f13.f64 = double(float(ctx.f8.f64 + ctx.f13.f64));
	// fadds f8,f3,f5
	ctx.f8.f64 = double(float(ctx.f3.f64 + ctx.f5.f64));
	// fsubs f9,f3,f5
	ctx.f9.f64 = double(float(ctx.f3.f64 - ctx.f5.f64));
	// fsubs f5,f2,f4
	ctx.f5.f64 = double(float(ctx.f2.f64 - ctx.f4.f64));
	// fsubs f3,f29,f30
	ctx.f3.f64 = double(float(f29.f64 - f30.f64));
	// fsubs f4,f31,f1
	ctx.f4.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fadds f1,f24,f26
	ctx.f1.f64 = double(float(f24.f64 + f26.f64));
	// fsubs f31,f26,f24
	f31.f64 = double(float(f26.f64 - f24.f64));
	// fadds f2,f25,f8
	ctx.f2.f64 = double(float(f25.f64 + ctx.f8.f64));
	// fsubs f8,f8,f25
	ctx.f8.f64 = double(float(ctx.f8.f64 - f25.f64));
	// fsubs f29,f9,f3
	f29.f64 = double(float(ctx.f9.f64 - ctx.f3.f64));
	// fadds f30,f4,f5
	f30.f64 = double(float(ctx.f4.f64 + ctx.f5.f64));
	// fadds f9,f3,f9
	ctx.f9.f64 = double(float(ctx.f3.f64 + ctx.f9.f64));
	// fsubs f5,f5,f4
	ctx.f5.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// fsubs f4,f29,f30
	ctx.f4.f64 = double(float(f29.f64 - f30.f64));
	// fadds f3,f30,f29
	ctx.f3.f64 = double(float(f30.f64 + f29.f64));
	// fadds f30,f5,f9
	f30.f64 = double(float(ctx.f5.f64 + ctx.f9.f64));
	// fsubs f29,f9,f5
	f29.f64 = double(float(ctx.f9.f64 - ctx.f5.f64));
	// fmuls f9,f4,f0
	ctx.f9.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// fmuls f5,f3,f0
	ctx.f5.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// fmuls f4,f30,f0
	ctx.f4.f64 = double(float(f30.f64 * ctx.f0.f64));
	// fmuls f0,f29,f0
	ctx.f0.f64 = double(float(f29.f64 * ctx.f0.f64));
	// fadds f3,f9,f28
	ctx.f3.f64 = double(float(ctx.f9.f64 + f28.f64));
	// stfs f3,32(r3)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// fsubs f9,f28,f9
	ctx.f9.f64 = double(float(f28.f64 - ctx.f9.f64));
	// stfs f9,40(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// fsubs f9,f27,f5
	ctx.f9.f64 = double(float(f27.f64 - ctx.f5.f64));
	// stfs f9,44(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// fsubs f9,f13,f4
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f4.f64));
	// stfs f9,48(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// fadds f13,f4,f13
	ctx.f13.f64 = double(float(ctx.f4.f64 + ctx.f13.f64));
	// stfs f13,56(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// fadds f3,f5,f27
	ctx.f3.f64 = double(float(ctx.f5.f64 + f27.f64));
	// stfs f3,36(r3)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// fadds f5,f0,f12
	ctx.f5.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f5,52(r3)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f0,60(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// fadds f13,f2,f7
	ctx.f13.f64 = double(float(ctx.f2.f64 + ctx.f7.f64));
	// stfs f13,0(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fadds f0,f1,f6
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fsubs f13,f7,f2
	ctx.f13.f64 = double(float(ctx.f7.f64 - ctx.f2.f64));
	// stfs f13,8(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fsubs f0,f6,f1
	ctx.f0.f64 = double(float(ctx.f6.f64 - ctx.f1.f64));
	// fsubs f13,f11,f31
	ctx.f13.f64 = double(float(ctx.f11.f64 - f31.f64));
	// stfs f0,12(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fadds f0,f8,f10
	ctx.f0.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// fadds f13,f31,f11
	ctx.f13.f64 = double(float(f31.f64 + ctx.f11.f64));
	// stfs f0,20(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// fsubs f0,f10,f8
	ctx.f0.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// stfs f13,24(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82a01364
	ctx.lr = 0x82A82C4C;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A82C58) {
	REX_FUNC_PROLOGUE();
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82a0130c
	ctx.lr = 0x82A82C68;
	// lfs f10,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,48(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// lfs f11,16(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fadds f25,f8,f9
	f25.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// fsubs f26,f11,f10
	f26.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f30,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	f30.f64 = double(temp.f32);
	// lfs f29,36(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	f29.f64 = double(temp.f32);
	// fadds f11,f10,f11
	ctx.f11.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// lfs f27,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	f27.f64 = double(temp.f32);
	// fsubs f24,f30,f29
	f24.f64 = double(float(f30.f64 - f29.f64));
	// lfs f28,32(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	f28.f64 = double(temp.f32);
	// fadds f30,f29,f30
	f30.f64 = double(float(f29.f64 + f30.f64));
	// fadds f29,f27,f28
	f29.f64 = double(float(f27.f64 + f28.f64));
	// lfs f12,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f28,f27,f28
	f28.f64 = double(float(f27.f64 - f28.f64));
	// lfs f7,8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f10,f8,f9
	ctx.f10.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// lfs f4,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// lfs f6,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f0,16(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f27,f26,f25
	f27.f64 = double(float(f26.f64 - f25.f64));
	// lfs f13,20(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fadds f26,f25,f26
	f26.f64 = double(float(f25.f64 + f26.f64));
	// lfs f3,24(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,60(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 60);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,28(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	f31.f64 = double(temp.f32);
	// fmuls f9,f27,f12
	ctx.f9.f64 = double(float(f27.f64 * ctx.f12.f64));
	// fsubs f27,f11,f10
	f27.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fmuls f8,f26,f12
	ctx.f8.f64 = double(float(f26.f64 * ctx.f12.f64));
	// fadds f26,f10,f11
	f26.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// fsubs f11,f7,f6
	ctx.f11.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fadds f10,f4,f5
	ctx.f10.f64 = double(float(ctx.f4.f64 + ctx.f5.f64));
	// fmuls f27,f27,f12
	f27.f64 = double(float(f27.f64 * ctx.f12.f64));
	// fmuls f12,f26,f12
	ctx.f12.f64 = double(float(f26.f64 * ctx.f12.f64));
	// fmr f26,f11
	f26.f64 = ctx.f11.f64;
	// fmr f25,f11
	f25.f64 = ctx.f11.f64;
	// fmuls f23,f10,f13
	f23.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmuls f22,f10,f0
	f22.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fadds f11,f6,f7
	ctx.f11.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// fsubs f10,f4,f5
	ctx.f10.f64 = double(float(ctx.f4.f64 - ctx.f5.f64));
	// fmsubs f7,f26,f0,f23
	ctx.f7.f64 = double(float(std::fma(f26.f64, ctx.f0.f64, -f23.f64)));
	// fmadds f6,f25,f13,f22
	ctx.f6.f64 = double(float(std::fma(f25.f64, ctx.f13.f64, f22.f64)));
	// fmuls f4,f11,f0
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmr f5,f11
	ctx.f5.f64 = ctx.f11.f64;
	// fmuls f26,f10,f0
	f26.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fmr f25,f10
	f25.f64 = ctx.f10.f64;
	// fsubs f11,f3,f2
	ctx.f11.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f10,f31,f1
	ctx.f10.f64 = double(float(f31.f64 + ctx.f1.f64));
	// fmsubs f5,f5,f13,f26
	ctx.f5.f64 = double(float(std::fma(ctx.f5.f64, ctx.f13.f64, -f26.f64)));
	// fmadds f4,f25,f13,f4
	ctx.f4.f64 = double(float(std::fma(f25.f64, ctx.f13.f64, ctx.f4.f64)));
	// fmr f26,f11
	f26.f64 = ctx.f11.f64;
	// fmuls f23,f10,f0
	f23.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fmuls f25,f11,f0
	f25.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fadds f11,f2,f3
	ctx.f11.f64 = double(float(ctx.f2.f64 + ctx.f3.f64));
	// fsubs f2,f31,f1
	ctx.f2.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fmsubs f3,f26,f13,f23
	ctx.f3.f64 = double(float(std::fma(f26.f64, ctx.f13.f64, -f23.f64)));
	// fmadds f10,f10,f13,f25
	ctx.f10.f64 = double(float(std::fma(ctx.f10.f64, ctx.f13.f64, f25.f64)));
	// fmr f26,f11
	f26.f64 = ctx.f11.f64;
	// fmr f25,f11
	f25.f64 = ctx.f11.f64;
	// fadds f11,f9,f24
	ctx.f11.f64 = double(float(ctx.f9.f64 + f24.f64));
	// fmuls f23,f2,f13
	f23.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// fmuls f22,f2,f0
	f22.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// fadds f2,f8,f29
	ctx.f2.f64 = double(float(ctx.f8.f64 + f29.f64));
	// fsubs f8,f29,f8
	ctx.f8.f64 = double(float(f29.f64 - ctx.f8.f64));
	// fadds f1,f3,f7
	ctx.f1.f64 = double(float(ctx.f3.f64 + ctx.f7.f64));
	// fadds f31,f10,f6
	f31.f64 = double(float(ctx.f10.f64 + ctx.f6.f64));
	// fmsubs f0,f26,f0,f23
	ctx.f0.f64 = double(float(std::fma(f26.f64, ctx.f0.f64, -f23.f64)));
	// fmadds f13,f25,f13,f22
	ctx.f13.f64 = double(float(std::fma(f25.f64, ctx.f13.f64, f22.f64)));
	// fadds f21,f1,f11
	f21.f64 = double(float(ctx.f1.f64 + ctx.f11.f64));
	// stfs f21,0(r3)
	temp.f32 = float(f21.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fsubs f11,f11,f1
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f1.f64));
	// stfs f11,8(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fsubs f11,f24,f9
	ctx.f11.f64 = double(float(f24.f64 - ctx.f9.f64));
	// fsubs f9,f7,f3
	ctx.f9.f64 = double(float(ctx.f7.f64 - ctx.f3.f64));
	// fadds f7,f31,f2
	ctx.f7.f64 = double(float(f31.f64 + ctx.f2.f64));
	// stfs f7,4(r3)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fsubs f7,f2,f31
	ctx.f7.f64 = double(float(ctx.f2.f64 - f31.f64));
	// stfs f7,12(r3)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fsubs f10,f6,f10
	ctx.f10.f64 = double(float(ctx.f6.f64 - ctx.f10.f64));
	// fadds f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 + ctx.f8.f64));
	// stfs f7,20(r3)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// fsubs f7,f11,f10
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// stfs f7,16(r3)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// fadds f11,f10,f11
	ctx.f11.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// stfs f11,24(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// fsubs f11,f8,f9
	ctx.f11.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// stfs f11,28(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// fsubs f9,f5,f0
	ctx.f9.f64 = double(float(ctx.f5.f64 - ctx.f0.f64));
	// fsubs f11,f30,f12
	ctx.f11.f64 = double(float(f30.f64 - ctx.f12.f64));
	// fsubs f8,f4,f13
	ctx.f8.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// fadds f10,f27,f28
	ctx.f10.f64 = double(float(f27.f64 + f28.f64));
	// fadds f0,f0,f5
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f5.f64));
	// fadds f12,f12,f30
	ctx.f12.f64 = double(float(ctx.f12.f64 + f30.f64));
	// fadds f13,f13,f4
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f4.f64));
	// fadds f7,f9,f11
	ctx.f7.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// stfs f7,32(r3)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// fsubs f11,f11,f9
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// stfs f11,40(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// fsubs f11,f10,f8
	ctx.f11.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// stfs f11,44(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// fsubs f11,f28,f27
	ctx.f11.f64 = double(float(f28.f64 - f27.f64));
	// fadds f7,f8,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// stfs f7,36(r3)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// fadds f10,f0,f11
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// stfs f10,52(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// fsubs f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfs f10,48(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f13,56(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// fsubs f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// stfs f0,60(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82a01358
	ctx.lr = 0x82A82E38;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A82E48) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister temp{};
	// srawi r10,r3,1
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 1;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// divw r11,r11,r10
	ctx.r11.u64 = uint32_t((ctx.r10.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r11.s32 / ctx.r10.s32 : 0);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r9,r3,-2
	ctx.r9.s64 = ctx.r3.s64 + -2;
	// neg r3,r11
	ctx.r3.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r6,r4
	ctx.r11.u64 = ctx.r6.u64 + ctx.r4.u64;
	// addi r10,r10,-3
	ctx.r10.s64 = ctx.r10.s64 + -3;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lfs f8,3444(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 3444);
	ctx.f8.f64 = double(temp.f32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
loc_82A82E98:
	// add r9,r3,r9
	ctx.r9.u64 = ctx.r3.u64 + ctx.r9.u64;
	// lfs f13,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// add r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 + ctx.r8.u64;
	// fadds f9,f9,f13
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// fsubs f12,f0,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfs f10,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// fsubs f10,f8,f10
	ctx.f10.f64 = double(float(ctx.f8.f64 - ctx.f10.f64));
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f7,f9,f11
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fmuls f9,f9,f10
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fmsubs f10,f12,f10,f7
	ctx.f10.f64 = double(float(std::fma(ctx.f12.f64, ctx.f10.f64, -ctx.f7.f64)));
	// fmadds f12,f12,f11,f9
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f11.f64, ctx.f9.f64)));
	// fsubs f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f10.f64));
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fsubs f0,f13,f12
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// stfs f0,4(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f10.f64));
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// bne cr6,0x82a82e98
	if (!cr6.eq) goto loc_82A82E98;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A82F18) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister temp{};
	// srawi r10,r3,1
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 1;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// divw r11,r11,r10
	ctx.r11.u64 = uint32_t((ctx.r10.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r11.s32 / ctx.r10.s32 : 0);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r9,r3,-2
	ctx.r9.s64 = ctx.r3.s64 + -2;
	// neg r3,r11
	ctx.r3.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r6,r4
	ctx.r11.u64 = ctx.r6.u64 + ctx.r4.u64;
	// addi r10,r10,-3
	ctx.r10.s64 = ctx.r10.s64 + -3;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lfs f8,3444(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 3444);
	ctx.f8.f64 = double(temp.f32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
loc_82A82F68:
	// add r9,r3,r9
	ctx.r9.u64 = ctx.r3.u64 + ctx.r9.u64;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 + ctx.r8.u64;
	// fsubs f12,f0,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfs f13,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// fadds f9,f9,f13
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// lfs f10,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// fsubs f10,f8,f10
	ctx.f10.f64 = double(float(ctx.f8.f64 - ctx.f10.f64));
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f6,f12,f11
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmuls f7,f12,f10
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// fmadds f12,f9,f11,f7
	ctx.f12.f64 = double(float(std::fma(ctx.f9.f64, ctx.f11.f64, ctx.f7.f64)));
	// fmsubs f11,f9,f10,f6
	ctx.f11.f64 = double(float(std::fma(ctx.f9.f64, ctx.f10.f64, -ctx.f6.f64)));
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fsubs f0,f13,f11
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// stfs f0,4(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// fsubs f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// bne cr6,0x82a82f68
	if (!cr6.eq) goto loc_82A82F68;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A82FE8) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c0
	ctx.lr = 0x82A82FF0;
	// srawi r26,r3,1
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	r26.s64 = ctx.r3.s32 >> 1;
	// divw r9,r5,r3
	ctx.r9.u64 = uint32_t((ctx.r3.s32 && !(ctx.r5.s32 == INT32_MIN && ctx.r3.s32 == -1)) ? ctx.r5.s32 / ctx.r3.s32 : 0);
	// addi r11,r26,-1
	ctx.r11.s64 = r26.s64 + -1;
	// li r28,0
	r28.s64 = 0;
	// li r27,1
	r27.s64 = 1;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(ctx.r11.s32, 4, xer);
	// blt cr6,0x82a8314c
	if (cr6.lt) goto loc_82A8314C;
	// addi r11,r26,-5
	ctx.r11.s64 = r26.s64 + -5;
	// addi r10,r3,-3
	ctx.r10.s64 = ctx.r3.s64 + -3;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r29,r5,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,1
	r31.s64 = ctx.r11.s64 + 1;
	// neg r11,r9
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r9.u64);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r27,r31,2,0,29
	r27.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// addi r11,r4,12
	ctx.r11.s64 = ctx.r4.s64 + 12;
	// add r29,r29,r6
	r29.u64 = r29.u64 + ctx.r6.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_82A83048:
	// add r29,r7,r29
	r29.u64 = ctx.r7.u64 + r29.u64;
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// add r30,r30,r8
	r30.u64 = r30.u64 + ctx.r8.u64;
	// lfs f13,-8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// add r28,r28,r9
	r28.u64 = r28.u64 + ctx.r9.u64;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// add r28,r28,r9
	r28.u64 = r28.u64 + ctx.r9.u64;
	// lfs f12,0(r29)
	temp.u32 = REX_LOAD_U32(r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r29,r7,r29
	r29.u64 = ctx.r7.u64 + r29.u64;
	// lfs f11,0(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// add r30,r30,r8
	r30.u64 = r30.u64 + ctx.r8.u64;
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// add r28,r28,r9
	r28.u64 = r28.u64 + ctx.r9.u64;
	// fadds f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// add r28,r28,r9
	r28.u64 = r28.u64 + ctx.r9.u64;
	// fmuls f11,f0,f10
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// fmuls f9,f0,f12
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fmsubs f0,f13,f12,f11
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, -ctx.f11.f64)));
	// fmadds f13,f13,f10,f9
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f10.f64, ctx.f9.f64)));
	// stfs f13,-8(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + -8, temp.u32);
	// stfs f0,8(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// add r29,r7,r29
	r29.u64 = ctx.r7.u64 + r29.u64;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// add r30,r30,r8
	r30.u64 = r30.u64 + ctx.r8.u64;
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f12,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f11,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f13,f12,f10
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmsubs f0,f11,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, -ctx.f13.f64)));
	// fmadds f13,f11,f10,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f11.f64, ctx.f10.f64, ctx.f12.f64)));
	// stfs f13,-4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// stfs f0,4(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// add r29,r7,r29
	r29.u64 = ctx.r7.u64 + r29.u64;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// add r30,r30,r8
	r30.u64 = r30.u64 + ctx.r8.u64;
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// fmuls f13,f11,f10
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// fmuls f10,f12,f10
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// fmsubs f13,f12,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
	// fmadds f0,f11,f0,f10
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f10.f64)));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f11,-4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f12,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f11,f10
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// fmsubs f13,f12,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmadds f0,f12,f10,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f10.f64, ctx.f0.f64)));
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f13,-4(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + -4, temp.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// bne cr6,0x82a83048
	if (!cr6.eq) goto loc_82A83048;
loc_82A8314C:
	// cmpw cr6,r27,r26
	cr6.compare<int32_t>(r27.s32, r26.s32, xer);
	// bge cr6,0x82a831d8
	if (!cr6.lt) goto loc_82A831D8;
	// subf r7,r28,r5
	ctx.r7.u64 = ctx.r5.u64 - r28.u64;
	// subf r10,r27,r3
	ctx.r10.u64 = ctx.r3.u64 - r27.u64;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r3,r9
	ctx.r3.s64 = static_cast<int64_t>(-ctx.r9.u64);
	// rlwinm r11,r27,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r28,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r7,r6
	ctx.r9.u64 = ctx.r7.u64 + ctx.r6.u64;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// subf r7,r27,r26
	ctx.r7.u64 = r26.u64 - r27.u64;
loc_82A8318C:
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f12,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fadds f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// fmuls f11,f13,f10
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmuls f10,f0,f10
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// fmsubs f0,f0,f12,f11
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f12.f64, -ctx.f11.f64)));
	// fmadds f13,f13,f12,f10
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, ctx.f10.f64)));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bne cr6,0x82a8318c
	if (!cr6.eq) goto loc_82A8318C;
loc_82A831D8:
	// rlwinm r11,r26,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r11,r4
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfsx f0,r11,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r4.u32, temp.u32);
	// b 0x829ff810
	return;
}

DEFINE_REX_FUNC(sub_82A831F0) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmpwi cr6,r3,128
	cr6.compare<int32_t>(ctx.r3.s32, 128, xer);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bne cr6,0x82a83258
	if (!cr6.eq) goto loc_82A83258;
	// addi r11,r5,-8
	ctx.r11.s64 = ctx.r5.s64 + -8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A83220;
	sub_82A82150(ctx, base);
	// addi r11,r5,-32
	ctx.r11.s64 = ctx.r5.s64 + -32;
	// addi r3,r10,128
	ctx.r3.s64 = ctx.r10.s64 + 128;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r6
	ctx.r4.u64 = ctx.r11.u64 + ctx.r6.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A83234;
	sub_82A82570(ctx, base);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// addi r3,r10,256
	ctx.r3.s64 = ctx.r10.s64 + 256;
	// bl 0x82a82150
	ctx.lr = 0x82A83240;
	sub_82A82150(ctx, base);
	// addi r3,r10,384
	ctx.r3.s64 = ctx.r10.s64 + 384;
	// bl 0x82a82150
	ctx.lr = 0x82A83248;
	sub_82A82150(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82A83258:
	// addi r11,r5,-16
	ctx.r11.s64 = ctx.r5.s64 + -16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r6
	ctx.r4.u64 = ctx.r11.u64 + ctx.r6.u64;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83268;
	sub_82A82AD0(ctx, base);
	// addi r3,r10,64
	ctx.r3.s64 = ctx.r10.s64 + 64;
	// bl 0x82a82c58
	ctx.lr = 0x82A83270;
	sub_82A82C58(ctx, base);
	// addi r3,r10,128
	ctx.r3.s64 = ctx.r10.s64 + 128;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83278;
	sub_82A82AD0(ctx, base);
	// addi r3,r10,192
	ctx.r3.s64 = ctx.r10.s64 + 192;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83280;
	sub_82A82AD0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A83290) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r18{};
	PPCRegister r19{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7a0
	ctx.lr = 0x82A83298;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// srawi r31,r18,2
	xer.ca = (r18.s32 < 0) & ((r18.u32 & 0x3) != 0);
	r31.s64 = r18.s32 >> 2;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// ble cr6,0x82a8339c
	if (!cr6.gt) goto loc_82A8339C;
loc_82A832B8:
	// mr r23,r31
	r23.u64 = r31.u64;
	// cmpw cr6,r31,r18
	cr6.compare<int32_t>(r31.s32, r18.s32, xer);
	// bge cr6,0x82a8336c
	if (!cr6.lt) goto loc_82A8336C;
loc_82A832C4:
	// subf r30,r31,r23
	r30.u64 = r23.u64 - r31.u64;
	// cmpw cr6,r30,r18
	cr6.compare<int32_t>(r30.s32, r18.s32, xer);
	// bge cr6,0x82a83360
	if (!cr6.lt) goto loc_82A83360;
	// srawi r10,r31,1
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1) != 0);
	ctx.r10.s64 = r31.s32 >> 1;
	// rlwinm r11,r23,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r10,r29
	ctx.r10.u64 = r29.u64 - ctx.r10.u64;
	// subf r9,r31,r29
	ctx.r9.u64 = r29.u64 - r31.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + r30.u64;
	// add r6,r30,r23
	ctx.r6.u64 = r30.u64 + r23.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r21,r7,r28
	r21.u64 = ctx.r7.u64 + r28.u64;
	// add r22,r8,r28
	r22.u64 = ctx.r8.u64 + r28.u64;
	// rlwinm r20,r23,2,0,29
	r20.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r24,r23,4,0,27
	r24.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 4) & 0xFFFFFFF0;
	// add r27,r9,r19
	r27.u64 = ctx.r9.u64 + r19.u64;
	// add r25,r10,r19
	r25.u64 = ctx.r10.u64 + r19.u64;
	// add r26,r11,r19
	r26.u64 = ctx.r11.u64 + r19.u64;
loc_82A83318:
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A83328;
	sub_82A81998(ctx, base);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81d18
	ctx.lr = 0x82A83338;
	sub_82A81D18(ctx, base);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A83348;
	sub_82A81998(ctx, base);
	// add r30,r20,r30
	r30.u64 = r20.u64 + r30.u64;
	// add r27,r24,r27
	r27.u64 = r24.u64 + r27.u64;
	// add r26,r24,r26
	r26.u64 = r24.u64 + r26.u64;
	// add r25,r24,r25
	r25.u64 = r24.u64 + r25.u64;
	// cmpw cr6,r30,r18
	cr6.compare<int32_t>(r30.s32, r18.s32, xer);
	// blt cr6,0x82a83318
	if (cr6.lt) goto loc_82A83318;
loc_82A83360:
	// rlwinm r23,r23,2,0,29
	r23.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r23,r18
	cr6.compare<int32_t>(r23.s32, r18.s32, xer);
	// blt cr6,0x82a832c4
	if (cr6.lt) goto loc_82A832C4;
loc_82A8336C:
	// subf r11,r31,r18
	ctx.r11.u64 = r18.u64 - r31.u64;
	// srawi r10,r31,1
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1) != 0);
	ctx.r10.s64 = r31.s32 >> 1;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r10,r29
	ctx.r10.u64 = r29.u64 - ctx.r10.u64;
	// add r4,r11,r19
	ctx.r4.u64 = ctx.r11.u64 + r19.u64;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + r28.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A83390;
	sub_82A81998(ctx, base);
	// srawi r31,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	r31.s64 = r31.s32 >> 2;
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// bgt cr6,0x82a832b8
	if (cr6.gt) goto loc_82A832B8;
loc_82A8339C:
	// mr r24,r31
	r24.u64 = r31.u64;
	// cmpw cr6,r31,r18
	cr6.compare<int32_t>(r31.s32, r18.s32, xer);
	// bge cr6,0x82a835c0
	if (!cr6.lt) goto loc_82A835C0;
loc_82A833A8:
	// subf r25,r31,r24
	r25.u64 = r24.u64 - r31.u64;
	// cmpw cr6,r25,r18
	cr6.compare<int32_t>(r25.s32, r18.s32, xer);
	// bge cr6,0x82a835b4
	if (!cr6.lt) goto loc_82A835B4;
	// addi r11,r24,48
	ctx.r11.s64 = r24.s64 + 48;
	// srawi r9,r31,1
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1) != 0);
	ctx.r9.s64 = r31.s32 >> 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r25,r24
	ctx.r11.u64 = r25.u64 + r24.u64;
	// subf r8,r31,r29
	ctx.r8.u64 = r29.u64 - r31.u64;
	// subf r9,r9,r29
	ctx.r9.u64 = r29.u64 - ctx.r9.u64;
	// addi r6,r25,96
	ctx.r6.s64 = r25.s64 + 96;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + r25.u64;
	// addi r11,r11,96
	ctx.r11.s64 = ctx.r11.s64 + 96;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r20,r7,r28
	r20.u64 = ctx.r7.u64 + r28.u64;
	// add r22,r8,r28
	r22.u64 = ctx.r8.u64 + r28.u64;
	// rlwinm r21,r24,2,0,29
	r21.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r23,r24,4,0,27
	r23.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 4) & 0xFFFFFFF0;
	// add r27,r9,r19
	r27.u64 = ctx.r9.u64 + r19.u64;
	// add r26,r10,r19
	r26.u64 = ctx.r10.u64 + r19.u64;
	// add r30,r11,r19
	r30.u64 = ctx.r11.u64 + r19.u64;
loc_82A83408:
	// addi r4,r27,-384
	ctx.r4.s64 = r27.s64 + -384;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A83418;
	sub_82A81998(ctx, base);
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bne cr6,0x82a83464
	if (!cr6.eq) goto loc_82A83464;
	// addi r11,r29,-8
	ctx.r11.s64 = r29.s64 + -8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + r28.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A83438;
	sub_82A82150(ctx, base);
	// addi r11,r29,-32
	ctx.r11.s64 = r29.s64 + -32;
	// addi r3,r27,-256
	ctx.r3.s64 = r27.s64 + -256;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + r28.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A8344C;
	sub_82A82570(ctx, base);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r27,-128
	ctx.r3.s64 = r27.s64 + -128;
	// bl 0x82a82150
	ctx.lr = 0x82A83458;
	sub_82A82150(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A83460;
	sub_82A82150(ctx, base);
	// b 0x82a8348c
	goto loc_82A8348C;
loc_82A83464:
	// addi r11,r29,-16
	ctx.r11.s64 = r29.s64 + -16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + r28.u64;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83474;
	sub_82A82AD0(ctx, base);
	// addi r3,r27,-320
	ctx.r3.s64 = r27.s64 + -320;
	// bl 0x82a82c58
	ctx.lr = 0x82A8347C;
	sub_82A82C58(ctx, base);
	// addi r3,r27,-256
	ctx.r3.s64 = r27.s64 + -256;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83484;
	sub_82A82AD0(ctx, base);
	// addi r3,r27,-192
	ctx.r3.s64 = r27.s64 + -192;
	// bl 0x82a82ad0
	ctx.lr = 0x82A8348C;
	sub_82A82AD0(ctx, base);
loc_82A8348C:
	// addi r4,r30,-384
	ctx.r4.s64 = r30.s64 + -384;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81d18
	ctx.lr = 0x82A8349C;
	sub_82A81D18(ctx, base);
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bne cr6,0x82a834f0
	if (!cr6.eq) goto loc_82A834F0;
	// addi r11,r29,-8
	ctx.r11.s64 = r29.s64 + -8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + r28.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A834BC;
	sub_82A82150(ctx, base);
	// addi r11,r29,-32
	ctx.r11.s64 = r29.s64 + -32;
	// addi r3,r30,-256
	ctx.r3.s64 = r30.s64 + -256;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + r28.u64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A834D4;
	sub_82A82570(ctx, base);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r30,-128
	ctx.r3.s64 = r30.s64 + -128;
	// bl 0x82a82150
	ctx.lr = 0x82A834E0;
	sub_82A82150(ctx, base);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A834EC;
	sub_82A82570(ctx, base);
	// b 0x82a83518
	goto loc_82A83518;
loc_82A834F0:
	// addi r11,r29,-16
	ctx.r11.s64 = r29.s64 + -16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + r28.u64;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83500;
	sub_82A82AD0(ctx, base);
	// addi r3,r30,-320
	ctx.r3.s64 = r30.s64 + -320;
	// bl 0x82a82c58
	ctx.lr = 0x82A83508;
	sub_82A82C58(ctx, base);
	// addi r3,r30,-256
	ctx.r3.s64 = r30.s64 + -256;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83510;
	sub_82A82AD0(ctx, base);
	// addi r3,r30,-192
	ctx.r3.s64 = r30.s64 + -192;
	// bl 0x82a82c58
	ctx.lr = 0x82A83518;
	sub_82A82C58(ctx, base);
loc_82A83518:
	// addi r4,r26,-384
	ctx.r4.s64 = r26.s64 + -384;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A83528;
	sub_82A81998(ctx, base);
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bne cr6,0x82a83574
	if (!cr6.eq) goto loc_82A83574;
	// addi r11,r29,-8
	ctx.r11.s64 = r29.s64 + -8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + r28.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A83548;
	sub_82A82150(ctx, base);
	// addi r11,r29,-32
	ctx.r11.s64 = r29.s64 + -32;
	// addi r3,r26,-256
	ctx.r3.s64 = r26.s64 + -256;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + r28.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A8355C;
	sub_82A82570(ctx, base);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r26,-128
	ctx.r3.s64 = r26.s64 + -128;
	// bl 0x82a82150
	ctx.lr = 0x82A83568;
	sub_82A82150(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A83570;
	sub_82A82150(ctx, base);
	// b 0x82a8359c
	goto loc_82A8359C;
loc_82A83574:
	// addi r11,r29,-16
	ctx.r11.s64 = r29.s64 + -16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + r28.u64;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83584;
	sub_82A82AD0(ctx, base);
	// addi r3,r26,-320
	ctx.r3.s64 = r26.s64 + -320;
	// bl 0x82a82c58
	ctx.lr = 0x82A8358C;
	sub_82A82C58(ctx, base);
	// addi r3,r26,-256
	ctx.r3.s64 = r26.s64 + -256;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83594;
	sub_82A82AD0(ctx, base);
	// addi r3,r26,-192
	ctx.r3.s64 = r26.s64 + -192;
	// bl 0x82a82ad0
	ctx.lr = 0x82A8359C;
	sub_82A82AD0(ctx, base);
loc_82A8359C:
	// add r25,r21,r25
	r25.u64 = r21.u64 + r25.u64;
	// add r27,r27,r23
	r27.u64 = r27.u64 + r23.u64;
	// add r30,r30,r23
	r30.u64 = r30.u64 + r23.u64;
	// add r26,r26,r23
	r26.u64 = r26.u64 + r23.u64;
	// cmpw cr6,r25,r18
	cr6.compare<int32_t>(r25.s32, r18.s32, xer);
	// blt cr6,0x82a83408
	if (cr6.lt) goto loc_82A83408;
loc_82A835B4:
	// rlwinm r24,r24,2,0,29
	r24.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r24,r18
	cr6.compare<int32_t>(r24.s32, r18.s32, xer);
	// blt cr6,0x82a833a8
	if (cr6.lt) goto loc_82A833A8;
loc_82A835C0:
	// subf r11,r31,r18
	ctx.r11.u64 = r18.u64 - r31.u64;
	// srawi r10,r31,1
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1) != 0);
	ctx.r10.s64 = r31.s32 >> 1;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r30,r11,r19
	r30.u64 = ctx.r11.u64 + r19.u64;
	// subf r11,r10,r29
	ctx.r11.u64 = r29.u64 - ctx.r10.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + r28.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A835E8;
	sub_82A81998(ctx, base);
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x82a83638
	if (!cr6.eq) goto loc_82A83638;
	// addi r11,r29,-8
	ctx.r11.s64 = r29.s64 + -8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + r28.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A83608;
	sub_82A82150(ctx, base);
	// addi r11,r29,-32
	ctx.r11.s64 = r29.s64 + -32;
	// addi r3,r30,128
	ctx.r3.s64 = r30.s64 + 128;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + r28.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A8361C;
	sub_82A82570(ctx, base);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r30,256
	ctx.r3.s64 = r30.s64 + 256;
	// bl 0x82a82150
	ctx.lr = 0x82A83628;
	sub_82A82150(ctx, base);
	// addi r3,r30,384
	ctx.r3.s64 = r30.s64 + 384;
	// bl 0x82a82150
	ctx.lr = 0x82A83630;
	sub_82A82150(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x829ff7f0
	return;
loc_82A83638:
	// addi r11,r29,-16
	ctx.r11.s64 = r29.s64 + -16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + r28.u64;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83648;
	sub_82A82AD0(ctx, base);
	// addi r3,r30,64
	ctx.r3.s64 = r30.s64 + 64;
	// bl 0x82a82c58
	ctx.lr = 0x82A83650;
	sub_82A82C58(ctx, base);
	// addi r3,r30,128
	ctx.r3.s64 = r30.s64 + 128;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83658;
	sub_82A82AD0(ctx, base);
	// addi r3,r30,192
	ctx.r3.s64 = r30.s64 + 192;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83660;
	sub_82A82AD0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x829ff7f0
	return;
}

DEFINE_REX_FUNC(sub_82A83668) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7a8
	ctx.lr = 0x82A83670;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// srawi r22,r3,1
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	r22.s64 = ctx.r3.s32 >> 1;
	// srawi r31,r3,2
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3) != 0);
	r31.s64 = ctx.r3.s32 >> 2;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// ble cr6,0x82a83784
	if (!cr6.gt) goto loc_82A83784;
loc_82A83690:
	// mr r23,r31
	r23.u64 = r31.u64;
	// cmpw cr6,r31,r22
	cr6.compare<int32_t>(r31.s32, r22.s32, xer);
	// bge cr6,0x82a83778
	if (!cr6.lt) goto loc_82A83778;
loc_82A8369C:
	// subf r30,r31,r23
	r30.u64 = r23.u64 - r31.u64;
	// cmpw cr6,r30,r22
	cr6.compare<int32_t>(r30.s32, r22.s32, xer);
	// bge cr6,0x82a83708
	if (!cr6.lt) goto loc_82A83708;
	// srawi r9,r31,1
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1) != 0);
	ctx.r9.s64 = r31.s32 >> 1;
	// add r11,r30,r22
	ctx.r11.u64 = r30.u64 + r22.u64;
	// subf r9,r9,r27
	ctx.r9.u64 = r27.u64 - ctx.r9.u64;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r21,r23,1,0,30
	r21.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// add r25,r9,r26
	r25.u64 = ctx.r9.u64 + r26.u64;
	// rlwinm r24,r23,3,0,28
	r24.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 3) & 0xFFFFFFF8;
	// add r29,r10,r20
	r29.u64 = ctx.r10.u64 + r20.u64;
	// add r28,r11,r20
	r28.u64 = ctx.r11.u64 + r20.u64;
loc_82A836D4:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A836E4;
	sub_82A81998(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A836F4;
	sub_82A81998(ctx, base);
	// add r30,r21,r30
	r30.u64 = r21.u64 + r30.u64;
	// add r29,r24,r29
	r29.u64 = r24.u64 + r29.u64;
	// add r28,r24,r28
	r28.u64 = r24.u64 + r28.u64;
	// cmpw cr6,r30,r22
	cr6.compare<int32_t>(r30.s32, r22.s32, xer);
	// blt cr6,0x82a836d4
	if (cr6.lt) goto loc_82A836D4;
loc_82A83708:
	// rlwinm r11,r23,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r30,r31,r11
	r30.u64 = ctx.r11.u64 - r31.u64;
	// cmpw cr6,r30,r22
	cr6.compare<int32_t>(r30.s32, r22.s32, xer);
	// bge cr6,0x82a8376c
	if (!cr6.lt) goto loc_82A8376C;
	// subf r11,r31,r27
	ctx.r11.u64 = r27.u64 - r31.u64;
	// add r8,r30,r22
	ctx.r8.u64 = r30.u64 + r22.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r9,r26
	ctx.r5.u64 = ctx.r9.u64 + r26.u64;
	// rlwinm r24,r23,2,0,29
	r24.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r25,r23,4,0,27
	r25.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 4) & 0xFFFFFFF0;
	// add r29,r10,r20
	r29.u64 = ctx.r10.u64 + r20.u64;
	// add r28,r11,r20
	r28.u64 = ctx.r11.u64 + r20.u64;
loc_82A83740:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81d18
	ctx.lr = 0x82A8374C;
	sub_82A81D18(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81d18
	ctx.lr = 0x82A83758;
	sub_82A81D18(ctx, base);
	// add r30,r24,r30
	r30.u64 = r24.u64 + r30.u64;
	// add r29,r25,r29
	r29.u64 = r25.u64 + r29.u64;
	// add r28,r25,r28
	r28.u64 = r25.u64 + r28.u64;
	// cmpw cr6,r30,r22
	cr6.compare<int32_t>(r30.s32, r22.s32, xer);
	// blt cr6,0x82a83740
	if (cr6.lt) goto loc_82A83740;
loc_82A8376C:
	// rlwinm r23,r23,2,0,29
	r23.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r23,r22
	cr6.compare<int32_t>(r23.s32, r22.s32, xer);
	// blt cr6,0x82a8369c
	if (cr6.lt) goto loc_82A8369C;
loc_82A83778:
	// srawi r31,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	r31.s64 = r31.s32 >> 2;
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// bgt cr6,0x82a83690
	if (cr6.gt) goto loc_82A83690;
loc_82A83784:
	// mr r21,r31
	r21.u64 = r31.u64;
	// cmpw cr6,r31,r22
	cr6.compare<int32_t>(r31.s32, r22.s32, xer);
	// bge cr6,0x82a83a5c
	if (!cr6.lt) goto loc_82A83A5C;
loc_82A83790:
	// subf r28,r31,r21
	r28.u64 = r21.u64 - r31.u64;
	// cmpw cr6,r28,r22
	cr6.compare<int32_t>(r28.s32, r22.s32, xer);
	// bge cr6,0x82a838ec
	if (!cr6.lt) goto loc_82A838EC;
	// srawi r10,r31,1
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1) != 0);
	ctx.r10.s64 = r31.s32 >> 1;
	// add r11,r28,r22
	ctx.r11.u64 = r28.u64 + r22.u64;
	// subf r10,r10,r27
	ctx.r10.u64 = r27.u64 - ctx.r10.u64;
	// addi r8,r28,96
	ctx.r8.s64 = r28.s64 + 96;
	// addi r11,r11,96
	ctx.r11.s64 = ctx.r11.s64 + 96;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r24,r9,r26
	r24.u64 = ctx.r9.u64 + r26.u64;
	// rlwinm r23,r21,1,0,30
	r23.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r25,r21,3,0,28
	r25.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r10,r20
	r30.u64 = ctx.r10.u64 + r20.u64;
	// add r29,r11,r20
	r29.u64 = ctx.r11.u64 + r20.u64;
loc_82A837D0:
	// addi r4,r30,-384
	ctx.r4.s64 = r30.s64 + -384;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A837E0;
	sub_82A81998(ctx, base);
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bne cr6,0x82a8382c
	if (!cr6.eq) goto loc_82A8382C;
	// addi r11,r27,-8
	ctx.r11.s64 = r27.s64 + -8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + r26.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A83800;
	sub_82A82150(ctx, base);
	// addi r11,r27,-32
	ctx.r11.s64 = r27.s64 + -32;
	// addi r3,r30,-256
	ctx.r3.s64 = r30.s64 + -256;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r26
	ctx.r4.u64 = ctx.r11.u64 + r26.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A83814;
	sub_82A82570(ctx, base);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r30,-128
	ctx.r3.s64 = r30.s64 + -128;
	// bl 0x82a82150
	ctx.lr = 0x82A83820;
	sub_82A82150(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A83828;
	sub_82A82150(ctx, base);
	// b 0x82a83854
	goto loc_82A83854;
loc_82A8382C:
	// addi r11,r27,-16
	ctx.r11.s64 = r27.s64 + -16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r26
	ctx.r4.u64 = ctx.r11.u64 + r26.u64;
	// bl 0x82a82ad0
	ctx.lr = 0x82A8383C;
	sub_82A82AD0(ctx, base);
	// addi r3,r30,-320
	ctx.r3.s64 = r30.s64 + -320;
	// bl 0x82a82c58
	ctx.lr = 0x82A83844;
	sub_82A82C58(ctx, base);
	// addi r3,r30,-256
	ctx.r3.s64 = r30.s64 + -256;
	// bl 0x82a82ad0
	ctx.lr = 0x82A8384C;
	sub_82A82AD0(ctx, base);
	// addi r3,r30,-192
	ctx.r3.s64 = r30.s64 + -192;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83854;
	sub_82A82AD0(ctx, base);
loc_82A83854:
	// addi r4,r29,-384
	ctx.r4.s64 = r29.s64 + -384;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A83864;
	sub_82A81998(ctx, base);
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bne cr6,0x82a838b0
	if (!cr6.eq) goto loc_82A838B0;
	// addi r11,r27,-8
	ctx.r11.s64 = r27.s64 + -8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + r26.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A83884;
	sub_82A82150(ctx, base);
	// addi r11,r27,-32
	ctx.r11.s64 = r27.s64 + -32;
	// addi r3,r29,-256
	ctx.r3.s64 = r29.s64 + -256;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r26
	ctx.r4.u64 = ctx.r11.u64 + r26.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A83898;
	sub_82A82570(ctx, base);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r29,-128
	ctx.r3.s64 = r29.s64 + -128;
	// bl 0x82a82150
	ctx.lr = 0x82A838A4;
	sub_82A82150(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A838AC;
	sub_82A82150(ctx, base);
	// b 0x82a838d8
	goto loc_82A838D8;
loc_82A838B0:
	// addi r11,r27,-16
	ctx.r11.s64 = r27.s64 + -16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r26
	ctx.r4.u64 = ctx.r11.u64 + r26.u64;
	// bl 0x82a82ad0
	ctx.lr = 0x82A838C0;
	sub_82A82AD0(ctx, base);
	// addi r3,r29,-320
	ctx.r3.s64 = r29.s64 + -320;
	// bl 0x82a82c58
	ctx.lr = 0x82A838C8;
	sub_82A82C58(ctx, base);
	// addi r3,r29,-256
	ctx.r3.s64 = r29.s64 + -256;
	// bl 0x82a82ad0
	ctx.lr = 0x82A838D0;
	sub_82A82AD0(ctx, base);
	// addi r3,r29,-192
	ctx.r3.s64 = r29.s64 + -192;
	// bl 0x82a82ad0
	ctx.lr = 0x82A838D8;
	sub_82A82AD0(ctx, base);
loc_82A838D8:
	// add r28,r23,r28
	r28.u64 = r23.u64 + r28.u64;
	// add r30,r30,r25
	r30.u64 = r30.u64 + r25.u64;
	// add r29,r29,r25
	r29.u64 = r29.u64 + r25.u64;
	// cmpw cr6,r28,r22
	cr6.compare<int32_t>(r28.s32, r22.s32, xer);
	// blt cr6,0x82a837d0
	if (cr6.lt) goto loc_82A837D0;
loc_82A838EC:
	// rlwinm r11,r21,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r28,r31,r11
	r28.u64 = ctx.r11.u64 - r31.u64;
	// cmpw cr6,r28,r22
	cr6.compare<int32_t>(r28.s32, r22.s32, xer);
	// bge cr6,0x82a83a50
	if (!cr6.lt) goto loc_82A83A50;
	// add r11,r28,r22
	ctx.r11.u64 = r28.u64 + r22.u64;
	// subf r10,r31,r27
	ctx.r10.u64 = r27.u64 - r31.u64;
	// addi r8,r28,96
	ctx.r8.s64 = r28.s64 + 96;
	// addi r11,r11,96
	ctx.r11.s64 = ctx.r11.s64 + 96;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r9,r26
	ctx.r5.u64 = ctx.r9.u64 + r26.u64;
	// rlwinm r24,r21,2,0,29
	r24.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r25,r21,4,0,27
	r25.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 4) & 0xFFFFFFF0;
	// add r30,r10,r20
	r30.u64 = ctx.r10.u64 + r20.u64;
	// add r29,r11,r20
	r29.u64 = ctx.r11.u64 + r20.u64;
loc_82A8392C:
	// addi r4,r30,-384
	ctx.r4.s64 = r30.s64 + -384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81d18
	ctx.lr = 0x82A83938;
	sub_82A81D18(ctx, base);
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bne cr6,0x82a8398c
	if (!cr6.eq) goto loc_82A8398C;
	// addi r11,r27,-8
	ctx.r11.s64 = r27.s64 + -8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + r26.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A83958;
	sub_82A82150(ctx, base);
	// addi r11,r27,-32
	ctx.r11.s64 = r27.s64 + -32;
	// addi r3,r30,-256
	ctx.r3.s64 = r30.s64 + -256;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r26
	ctx.r9.u64 = ctx.r11.u64 + r26.u64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A83970;
	sub_82A82570(ctx, base);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r30,-128
	ctx.r3.s64 = r30.s64 + -128;
	// bl 0x82a82150
	ctx.lr = 0x82A8397C;
	sub_82A82150(ctx, base);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A83988;
	sub_82A82570(ctx, base);
	// b 0x82a839b4
	goto loc_82A839B4;
loc_82A8398C:
	// addi r11,r27,-16
	ctx.r11.s64 = r27.s64 + -16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r26
	ctx.r4.u64 = ctx.r11.u64 + r26.u64;
	// bl 0x82a82ad0
	ctx.lr = 0x82A8399C;
	sub_82A82AD0(ctx, base);
	// addi r3,r30,-320
	ctx.r3.s64 = r30.s64 + -320;
	// bl 0x82a82c58
	ctx.lr = 0x82A839A4;
	sub_82A82C58(ctx, base);
	// addi r3,r30,-256
	ctx.r3.s64 = r30.s64 + -256;
	// bl 0x82a82ad0
	ctx.lr = 0x82A839AC;
	sub_82A82AD0(ctx, base);
	// addi r3,r30,-192
	ctx.r3.s64 = r30.s64 + -192;
	// bl 0x82a82c58
	ctx.lr = 0x82A839B4;
	sub_82A82C58(ctx, base);
loc_82A839B4:
	// addi r4,r29,-384
	ctx.r4.s64 = r29.s64 + -384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a81d18
	ctx.lr = 0x82A839C0;
	sub_82A81D18(ctx, base);
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bne cr6,0x82a83a14
	if (!cr6.eq) goto loc_82A83A14;
	// addi r11,r27,-8
	ctx.r11.s64 = r27.s64 + -8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + r26.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A839E0;
	sub_82A82150(ctx, base);
	// addi r11,r27,-32
	ctx.r11.s64 = r27.s64 + -32;
	// addi r3,r29,-256
	ctx.r3.s64 = r29.s64 + -256;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r26
	ctx.r9.u64 = ctx.r11.u64 + r26.u64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A839F8;
	sub_82A82570(ctx, base);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r29,-128
	ctx.r3.s64 = r29.s64 + -128;
	// bl 0x82a82150
	ctx.lr = 0x82A83A04;
	sub_82A82150(ctx, base);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82a82570
	ctx.lr = 0x82A83A10;
	sub_82A82570(ctx, base);
	// b 0x82a83a3c
	goto loc_82A83A3C;
loc_82A83A14:
	// addi r11,r27,-16
	ctx.r11.s64 = r27.s64 + -16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r26
	ctx.r4.u64 = ctx.r11.u64 + r26.u64;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83A24;
	sub_82A82AD0(ctx, base);
	// addi r3,r29,-320
	ctx.r3.s64 = r29.s64 + -320;
	// bl 0x82a82c58
	ctx.lr = 0x82A83A2C;
	sub_82A82C58(ctx, base);
	// addi r3,r29,-256
	ctx.r3.s64 = r29.s64 + -256;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83A34;
	sub_82A82AD0(ctx, base);
	// addi r3,r29,-192
	ctx.r3.s64 = r29.s64 + -192;
	// bl 0x82a82c58
	ctx.lr = 0x82A83A3C;
	sub_82A82C58(ctx, base);
loc_82A83A3C:
	// add r28,r24,r28
	r28.u64 = r24.u64 + r28.u64;
	// add r30,r25,r30
	r30.u64 = r25.u64 + r30.u64;
	// add r29,r25,r29
	r29.u64 = r25.u64 + r29.u64;
	// cmpw cr6,r28,r22
	cr6.compare<int32_t>(r28.s32, r22.s32, xer);
	// blt cr6,0x82a8392c
	if (cr6.lt) goto loc_82A8392C;
loc_82A83A50:
	// rlwinm r21,r21,2,0,29
	r21.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r21,r22
	cr6.compare<int32_t>(r21.s32, r22.s32, xer);
	// blt cr6,0x82a83790
	if (cr6.lt) goto loc_82A83790;
loc_82A83A5C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x829ff7f8
	return;
}

DEFINE_REX_FUNC(sub_82A83A68) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c4
	ctx.lr = 0x82A83A70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// srawi r31,r27,2
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x3) != 0);
	r31.s64 = r27.s32 >> 2;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// subf r11,r11,r29
	ctx.r11.u64 = r29.u64 - ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + r28.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A83A9C;
	sub_82A81998(ctx, base);
	// cmpwi cr6,r27,512
	cr6.compare<int32_t>(r27.s32, 512, xer);
	// ble cr6,0x82a83b28
	if (!cr6.gt) goto loc_82A83B28;
loc_82A83AA4:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a83a68
	ctx.lr = 0x82A83AB8;
	sub_82A83A68(ctx, base);
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a83b48
	ctx.lr = 0x82A83AD0;
	sub_82A83B48(ctx, base);
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a83a68
	ctx.lr = 0x82A83AE8;
	sub_82A83A68(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = r31.u64;
	// mr r27,r31
	r27.u64 = r31.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r31,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	r31.s64 = r31.s32 >> 2;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r10,r29
	ctx.r10.u64 = r29.u64 - ctx.r10.u64;
	// add r30,r11,r30
	r30.u64 = ctx.r11.u64 + r30.u64;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82a81998
	ctx.lr = 0x82A83B20;
	sub_82A81998(ctx, base);
	// cmpwi cr6,r27,512
	cr6.compare<int32_t>(r27.s32, 512, xer);
	// bgt cr6,0x82a83aa4
	if (cr6.gt) goto loc_82A83AA4;
loc_82A83B28:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82a83290
	ctx.lr = 0x82A83B3C;
	sub_82A83290(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x829ff814
	return;
}

DEFINE_REX_FUNC(sub_82A83B48) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c4
	ctx.lr = 0x82A83B50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// subf r11,r29,r28
	ctx.r11.u64 = r28.u64 - r29.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r31,r29,2
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x3) != 0);
	r31.s64 = r29.s32 >> 2;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + r27.u64;
	// bl 0x82a81d18
	ctx.lr = 0x82A83B78;
	sub_82A81D18(ctx, base);
	// cmpwi cr6,r29,512
	cr6.compare<int32_t>(r29.s32, 512, xer);
	// ble cr6,0x82a83c00
	if (!cr6.gt) goto loc_82A83C00;
loc_82A83B80:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a83a68
	ctx.lr = 0x82A83B94;
	sub_82A83A68(ctx, base);
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a83b48
	ctx.lr = 0x82A83BAC;
	sub_82A83B48(ctx, base);
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a83a68
	ctx.lr = 0x82A83BC4;
	sub_82A83A68(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = r31.u64;
	// mr r29,r31
	r29.u64 = r31.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r9,r29,r28
	ctx.r9.u64 = r28.u64 - r29.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + r27.u64;
	// add r30,r11,r30
	r30.u64 = ctx.r11.u64 + r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// srawi r31,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	r31.s64 = r31.s32 >> 2;
	// bl 0x82a81d18
	ctx.lr = 0x82A83BF8;
	sub_82A81D18(ctx, base);
	// cmpwi cr6,r29,512
	cr6.compare<int32_t>(r29.s32, 512, xer);
	// bgt cr6,0x82a83b80
	if (cr6.gt) goto loc_82A83B80;
loc_82A83C00:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82a83668
	ctx.lr = 0x82A83C14;
	sub_82A83668(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x829ff814
	return;
}

DEFINE_REX_FUNC(sub_82A83C20) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c0
	ctx.lr = 0x82A83C28;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x82a01310
	ctx.lr = 0x82A83C30;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// cmpwi cr6,r27,32
	cr6.compare<int32_t>(r27.s32, 32, xer);
	// ble cr6,0x82a83d40
	if (!cr6.gt) goto loc_82A83D40;
	// srawi r30,r27,2
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x3) != 0);
	r30.s64 = r27.s32 >> 2;
	// subf r11,r30,r28
	ctx.r11.u64 = r28.u64 - r30.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r29
	ctx.r5.u64 = ctx.r11.u64 + r29.u64;
	// bl 0x82a80b48
	ctx.lr = 0x82A83C64;
	sub_82A80B48(ctx, base);
	// cmpwi cr6,r27,512
	cr6.compare<int32_t>(r27.s32, 512, xer);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// ble cr6,0x82a83cec
	if (!cr6.gt) goto loc_82A83CEC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82a83a68
	ctx.lr = 0x82A83C7C;
	sub_82A83A68(ctx, base);
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82a83b48
	ctx.lr = 0x82A83C94;
	sub_82A83B48(ctx, base);
	// rlwinm r11,r30,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82a83a68
	ctx.lr = 0x82A83CAC;
	sub_82A83A68(ctx, base);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// add r11,r30,r11
	ctx.r11.u64 = r30.u64 + ctx.r11.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + r31.u64;
	// bl 0x82a83a68
	ctx.lr = 0x82A83CCC;
	sub_82A83A68(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82a7ff58
	ctx.lr = 0x82A83CDC;
	sub_82A7FF58(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x82a0135c
	ctx.lr = 0x82A83CE8;
	// b 0x829ff810
	return;
loc_82A83CEC:
	// cmpwi cr6,r30,32
	cr6.compare<int32_t>(r30.s32, 32, xer);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// ble cr6,0x82a83d1c
	if (!cr6.gt) goto loc_82A83D1C;
	// bl 0x82a83290
	ctx.lr = 0x82A83CFC;
	sub_82A83290(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82a7ff58
	ctx.lr = 0x82A83D0C;
	sub_82A7FF58(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x82a0135c
	ctx.lr = 0x82A83D18;
	// b 0x829ff810
	return;
loc_82A83D1C:
	// bl 0x82a831f0
	ctx.lr = 0x82A83D20;
	sub_82A831F0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82a7ff58
	ctx.lr = 0x82A83D30;
	sub_82A7FF58(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x82a0135c
	ctx.lr = 0x82A83D3C;
	// b 0x829ff810
	return;
loc_82A83D40:
	// cmpwi cr6,r27,8
	cr6.compare<int32_t>(r27.s32, 8, xer);
	// ble cr6,0x82a83e8c
	if (!cr6.gt) goto loc_82A83E8C;
	// cmpwi cr6,r27,32
	cr6.compare<int32_t>(r27.s32, 32, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x82a83e34
	if (!cr6.eq) goto loc_82A83E34;
	// addi r11,r28,-8
	ctx.r11.s64 = r28.s64 + -8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + r29.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A83D64;
	sub_82A82150(ctx, base);
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,20(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,24(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,40(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 40);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,44(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,28(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 28);
	ctx.f7.f64 = double(temp.f32);
	// lfs f2,64(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 64);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,68(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 68);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,32(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 32);
	f31.f64 = double(temp.f32);
	// lfs f30,36(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 36);
	f30.f64 = double(temp.f32);
	// lfs f29,96(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 96);
	f29.f64 = double(temp.f32);
	// lfs f28,80(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 80);
	f28.f64 = double(temp.f32);
	// lfs f27,84(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 84);
	f27.f64 = double(temp.f32);
	// lfs f6,56(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 56);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,60(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 60);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,88(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 88);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,92(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 92);
	ctx.f3.f64 = double(temp.f32);
	// lfs f26,100(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 100);
	f26.f64 = double(temp.f32);
	// lfs f25,112(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 112);
	f25.f64 = double(temp.f32);
	// lfs f24,116(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 116);
	f24.f64 = double(temp.f32);
	// lfs f23,104(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 104);
	f23.f64 = double(temp.f32);
	// lfs f22,108(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 108);
	f22.f64 = double(temp.f32);
	// stfs f2,8(r31)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f1,12(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f31,16(r31)
	temp.f32 = float(f31.f64);
	REX_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f30,20(r31)
	temp.f32 = float(f30.f64);
	REX_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f29,24(r31)
	temp.f32 = float(f29.f64);
	REX_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f26,28(r31)
	temp.f32 = float(f26.f64);
	REX_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f28,40(r31)
	temp.f32 = float(f28.f64);
	REX_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f27,44(r31)
	temp.f32 = float(f27.f64);
	REX_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f25,56(r31)
	temp.f32 = float(f25.f64);
	REX_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f24,60(r31)
	temp.f32 = float(f24.f64);
	REX_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f23,88(r31)
	temp.f32 = float(f23.f64);
	REX_STORE_U32(r31.u32 + 88, temp.u32);
	// stfs f22,92(r31)
	temp.f32 = float(f22.f64);
	REX_STORE_U32(r31.u32 + 92, temp.u32);
	// stfs f0,64(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f13,68(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f12,32(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f11,36(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f10,96(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f9,80(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f8,84(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f7,100(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f4,104(r31)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f3,108(r31)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f6,112(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f5,116(r31)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(r31.u32 + 116, temp.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x82a0135c
	ctx.lr = 0x82A83E30;
	// b 0x829ff810
	return;
loc_82A83E34:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82a82ad0
	ctx.lr = 0x82A83E3C;
	sub_82A82AD0(ctx, base);
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,28(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,32(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,36(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 36);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,48(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 48);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,52(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 52);
	ctx.f7.f64 = double(temp.f32);
	// stfs f9,12(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f8,24(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f7,28(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f12,48(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f11,52(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f10,8(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(r31.u32 + 8, temp.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x82a0135c
	ctx.lr = 0x82A83E88;
	// b 0x829ff810
	return;
loc_82A83E8C:
	// bne cr6,0x82a83f20
	if (!cr6.eq) goto loc_82A83F20;
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,16(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fadds f6,f13,f0
	ctx.f6.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f11,4(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,20(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfs f9,8(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fadds f13,f11,f12
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// lfs f10,24(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fadds f11,f10,f9
	ctx.f11.f64 = double(float(ctx.f10.f64 + ctx.f9.f64));
	// lfs f7,12(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,28(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f10,f9,f10
	ctx.f10.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fadds f9,f8,f7
	ctx.f9.f64 = double(float(ctx.f8.f64 + ctx.f7.f64));
	// fsubs f8,f7,f8
	ctx.f8.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fadds f7,f11,f6
	ctx.f7.f64 = double(float(ctx.f11.f64 + ctx.f6.f64));
	// stfs f7,0(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(r31.u32 + 0, temp.u32);
	// fsubs f11,f6,f11
	ctx.f11.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// stfs f11,16(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(r31.u32 + 16, temp.u32);
	// fadds f11,f9,f13
	ctx.f11.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// stfs f11,4(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(r31.u32 + 4, temp.u32);
	// fsubs f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r31.u32 + 20, temp.u32);
	// fsubs f13,f0,f8
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r31.u32 + 8, temp.u32);
	// fadds f0,f8,f0
	ctx.f0.f64 = double(float(ctx.f8.f64 + ctx.f0.f64));
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 24, temp.u32);
	// fadds f13,f10,f12
	ctx.f13.f64 = double(float(ctx.f10.f64 + ctx.f12.f64));
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r31.u32 + 12, temp.u32);
	// fsubs f0,f12,f10
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 28, temp.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x82a0135c
	ctx.lr = 0x82A83F1C;
	// b 0x829ff810
	return;
loc_82A83F20:
	// cmpwi cr6,r27,4
	cr6.compare<int32_t>(r27.s32, 4, xer);
	// bne cr6,0x82a83f58
	if (!cr6.eq) goto loc_82A83F58;
	// lfs f13,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f12,4(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 0, temp.u32);
	// fadds f13,f12,f11
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// fsubs f0,f12,f11
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f10,8(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(r31.u32 + 8, temp.u32);
loc_82A83F58:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x82a0135c
	ctx.lr = 0x82A83F64;
	// b 0x829ff810
	return;
}

DEFINE_REX_FUNC(sub_82A83F68) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7c0
	ctx.lr = 0x82A83F70;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// cmpwi cr6,r27,32
	cr6.compare<int32_t>(r27.s32, 32, xer);
	// ble cr6,0x82a84068
	if (!cr6.gt) goto loc_82A84068;
	// srawi r30,r27,2
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x3) != 0);
	r30.s64 = r27.s32 >> 2;
	// subf r11,r30,r28
	ctx.r11.u64 = r28.u64 - r30.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r29
	ctx.r5.u64 = ctx.r11.u64 + r29.u64;
	// bl 0x82a81250
	ctx.lr = 0x82A83FA4;
	sub_82A81250(ctx, base);
	// cmpwi cr6,r27,512
	cr6.compare<int32_t>(r27.s32, 512, xer);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// ble cr6,0x82a84024
	if (!cr6.gt) goto loc_82A84024;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82a83a68
	ctx.lr = 0x82A83FBC;
	sub_82A83A68(ctx, base);
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82a83b48
	ctx.lr = 0x82A83FD4;
	sub_82A83B48(ctx, base);
	// rlwinm r11,r30,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82a83a68
	ctx.lr = 0x82A83FEC;
	sub_82A83A68(ctx, base);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// add r11,r30,r11
	ctx.r11.u64 = r30.u64 + ctx.r11.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + r31.u64;
	// bl 0x82a83a68
	ctx.lr = 0x82A8400C;
	sub_82A83A68(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82a80448
	ctx.lr = 0x82A8401C;
	sub_82A80448(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
loc_82A84024:
	// cmpwi cr6,r30,32
	cr6.compare<int32_t>(r30.s32, 32, xer);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// ble cr6,0x82a8404c
	if (!cr6.gt) goto loc_82A8404C;
	// bl 0x82a83290
	ctx.lr = 0x82A84034;
	sub_82A83290(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82a80448
	ctx.lr = 0x82A84044;
	sub_82A80448(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
loc_82A8404C:
	// bl 0x82a831f0
	ctx.lr = 0x82A84050;
	sub_82A831F0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82a80448
	ctx.lr = 0x82A84060;
	sub_82A80448(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
loc_82A84068:
	// cmpwi cr6,r27,8
	cr6.compare<int32_t>(r27.s32, 8, xer);
	// ble cr6,0x82a84118
	if (!cr6.gt) goto loc_82A84118;
	// cmpwi cr6,r27,32
	cr6.compare<int32_t>(r27.s32, 32, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x82a84098
	if (!cr6.eq) goto loc_82A84098;
	// addi r11,r28,-8
	ctx.r11.s64 = r28.s64 + -8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + r29.u64;
	// bl 0x82a82150
	ctx.lr = 0x82A8408C;
	sub_82A82150(ctx, base);
	// bl 0x82a80a30
	ctx.lr = 0x82A84090;
	sub_82A80A30(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
loc_82A84098:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82a82ad0
	ctx.lr = 0x82A840A0;
	sub_82A82AD0(ctx, base);
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,20(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,32(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,36(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 36);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,56(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 56);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,60(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 60);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,24(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 24);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,40(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,48(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 48);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,52(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 52);
	ctx.f1.f64 = double(temp.f32);
	// stfs f8,8(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f7,12(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f6,16(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f5,20(r31)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f4,24(r31)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f3,28(r31)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f2,40(r31)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f1,44(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f12,48(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f11,52(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f10,56(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f9,60(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(r31.u32 + 60, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
loc_82A84118:
	// bne cr6,0x82a841a4
	if (!cr6.eq) goto loc_82A841A4;
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,16(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fadds f6,f13,f0
	ctx.f6.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f11,4(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,20(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfs f9,8(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fadds f13,f11,f12
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// lfs f10,24(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fadds f11,f10,f9
	ctx.f11.f64 = double(float(ctx.f10.f64 + ctx.f9.f64));
	// lfs f7,12(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,28(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f10,f9,f10
	ctx.f10.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fadds f9,f8,f7
	ctx.f9.f64 = double(float(ctx.f8.f64 + ctx.f7.f64));
	// fsubs f8,f7,f8
	ctx.f8.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fadds f7,f11,f6
	ctx.f7.f64 = double(float(ctx.f11.f64 + ctx.f6.f64));
	// stfs f7,0(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(r31.u32 + 0, temp.u32);
	// fsubs f11,f6,f11
	ctx.f11.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// stfs f11,16(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(r31.u32 + 16, temp.u32);
	// fadds f11,f9,f13
	ctx.f11.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// stfs f11,4(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(r31.u32 + 4, temp.u32);
	// fsubs f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r31.u32 + 20, temp.u32);
	// fadds f13,f8,f0
	ctx.f13.f64 = double(float(ctx.f8.f64 + ctx.f0.f64));
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r31.u32 + 8, temp.u32);
	// fsubs f0,f0,f8
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 24, temp.u32);
	// fsubs f13,f12,f10
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r31.u32 + 12, temp.u32);
	// fadds f0,f10,f12
	ctx.f0.f64 = double(float(ctx.f10.f64 + ctx.f12.f64));
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 28, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
loc_82A841A4:
	// cmpwi cr6,r27,4
	cr6.compare<int32_t>(r27.s32, 4, xer);
	// bne cr6,0x82a841dc
	if (!cr6.eq) goto loc_82A841DC;
	// lfs f13,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f12,4(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12(r31)
	temp.u32 = REX_LOAD_U32(r31.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 0, temp.u32);
	// fadds f13,f12,f11
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// fsubs f0,f12,f11
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f10,8(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r31.u32 + 12, temp.u32);
loc_82A841DC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff810
	return;
}

DEFINE_REX_FUNC(sub_82A841E8) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7bc
	ctx.lr = 0x82A841F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lwz r30,0(r27)
	r30.u64 = REX_LOAD_U32(r27.u32 + 0);
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, ctx.r11.s32, xer);
	// ble cr6,0x82a8422c
	if (!cr6.gt) goto loc_82A8422C;
	// srawi r30,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	r30.s64 = r31.s32 >> 2;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82a7fc38
	ctx.lr = 0x82A8422C;
	sub_82A7FC38(ctx, base);
loc_82A8422C:
	// lwz r26,4(r27)
	r26.u64 = REX_LOAD_U32(r27.u32 + 4);
	// rlwinm r11,r26,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, ctx.r11.s32, xer);
	// ble cr6,0x82a84254
	if (!cr6.gt) goto loc_82A84254;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r26,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	r26.s64 = r31.s32 >> 2;
	// add r5,r11,r29
	ctx.r5.u64 = ctx.r11.u64 + r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82a7fe58
	ctx.lr = 0x82A84254;
	sub_82A7FE58(ctx, base);
loc_82A84254:
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// blt cr6,0x82a842d4
	if (cr6.lt) goto loc_82A842D4;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// ble cr6,0x82a84298
	if (!cr6.gt) goto loc_82A84298;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r27,8
	ctx.r5.s64 = r27.s64 + 8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a83c20
	ctx.lr = 0x82A8427C;
	sub_82A83C20(ctx, base);
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// add r6,r11,r29
	ctx.r6.u64 = ctx.r11.u64 + r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a82e48
	ctx.lr = 0x82A84294;
	sub_82A82E48(ctx, base);
	// b 0x82a842b4
	goto loc_82A842B4;
loc_82A84298:
	// bne cr6,0x82a842b4
	if (!cr6.eq) goto loc_82A842B4;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r27,8
	ctx.r5.s64 = r27.s64 + 8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82a83c20
	ctx.lr = 0x82A842B4;
	sub_82A83C20(ctx, base);
loc_82A842B4:
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r28)
	temp.u32 = REX_LOAD_U32(r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f12,4(r28)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(r28.u32 + 4, temp.u32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,0(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r28.u32 + 0, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff80c
	return;
loc_82A842D4:
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,4(r28)
	temp.u32 = REX_LOAD_U32(r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f13,3444(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3444);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f13,4(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r28.u32 + 4, temp.u32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,0(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r28.u32 + 0, temp.u32);
	// ble cr6,0x82a84320
	if (!cr6.gt) goto loc_82A84320;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// add r6,r11,r29
	ctx.r6.u64 = ctx.r11.u64 + r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a82f18
	ctx.lr = 0x82A84318;
	sub_82A82F18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x82a84328
	goto loc_82A84328;
loc_82A84320:
	// bne cr6,0x82a8433c
	if (!cr6.eq) goto loc_82A8433C;
	// li r3,4
	ctx.r3.s64 = 4;
loc_82A84328:
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r27,8
	ctx.r5.s64 = r27.s64 + 8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82a83f68
	ctx.lr = 0x82A8433C;
	sub_82A83F68(ctx, base);
loc_82A8433C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x829ff80c
	return;
}

DEFINE_REX_FUNC(sub_82A84348) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7b8
	ctx.lr = 0x82A84350;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// lwz r29,0(r26)
	r29.u64 = REX_LOAD_U32(r26.u32 + 0);
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, ctx.r11.s32, xer);
	// ble cr6,0x82a8438c
	if (!cr6.gt) goto loc_82A8438C;
	// srawi r29,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	r29.s64 = r31.s32 >> 2;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82a7fc38
	ctx.lr = 0x82A8438C;
	sub_82A7FC38(ctx, base);
loc_82A8438C:
	// lwz r25,4(r26)
	r25.u64 = REX_LOAD_U32(r26.u32 + 4);
	// cmpw cr6,r31,r25
	cr6.compare<int32_t>(r31.s32, r25.s32, xer);
	// ble cr6,0x82a843b0
	if (!cr6.gt) goto loc_82A843B0;
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r25,r31
	r25.u64 = r31.u64;
	// bl 0x82a7fe58
	ctx.lr = 0x82A843B0;
	sub_82A7FE58(ctx, base);
loc_82A843B0:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bge cr6,0x82a8445c
	if (!cr6.lt) goto loc_82A8445C;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r31,-2
	ctx.r11.s64 = r31.s64 + -2;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(ctx.r11.s32, 2, xer);
	// lfs f12,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// blt cr6,0x82a84404
	if (cr6.lt) goto loc_82A84404;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// add r11,r9,r30
	ctx.r11.u64 = ctx.r9.u64 + r30.u64;
loc_82A843DC:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lfs f13,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f11,4(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// bne cr6,0x82a843dc
	if (!cr6.eq) goto loc_82A843DC;
loc_82A84404:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// fsubs f13,f0,f12
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(r30.u32 + 4, temp.u32);
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(r30.u32 + 0, temp.u32);
	// ble cr6,0x82a84440
	if (!cr6.gt) goto loc_82A84440;
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// add r6,r11,r28
	ctx.r6.u64 = ctx.r11.u64 + r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a82f18
	ctx.lr = 0x82A84438;
	sub_82A82F18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x82a84448
	goto loc_82A84448;
loc_82A84440:
	// bne cr6,0x82a8445c
	if (!cr6.eq) goto loc_82A8445C;
	// li r3,4
	ctx.r3.s64 = 4;
loc_82A84448:
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r26,8
	ctx.r5.s64 = r26.s64 + 8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82a83f68
	ctx.lr = 0x82A8445C;
	sub_82A83F68(ctx, base);
loc_82A8445C:
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// add r27,r11,r28
	r27.u64 = ctx.r11.u64 + r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// bl 0x82a82fe8
	ctx.lr = 0x82A84478;
	sub_82A82FE8(ctx, base);
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// blt cr6,0x82a84530
	if (cr6.lt) goto loc_82A84530;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// ble cr6,0x82a844b4
	if (!cr6.gt) goto loc_82A844B4;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r26,8
	ctx.r5.s64 = r26.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a83c20
	ctx.lr = 0x82A8449C;
	sub_82A83C20(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82a82e48
	ctx.lr = 0x82A844B0;
	sub_82A82E48(ctx, base);
	// b 0x82a844d0
	goto loc_82A844D0;
loc_82A844B4:
	// bne cr6,0x82a844d0
	if (!cr6.eq) goto loc_82A844D0;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r26,8
	ctx.r5.s64 = r26.s64 + 8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82a83c20
	ctx.lr = 0x82A844D0;
	sub_82A83C20(ctx, base);
loc_82A844D0:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,0(r30)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(r30.u32 + 0, temp.u32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// ble cr6,0x82a84524
	if (!cr6.gt) goto loc_82A84524;
	// addi r10,r31,-3
	ctx.r10.s64 = r31.s64 + -3;
	// addi r11,r30,8
	ctx.r11.s64 = r30.s64 + 8;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82A844FC:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f11,-4(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bne cr6,0x82a844fc
	if (!cr6.eq) goto loc_82A844FC;
loc_82A84524:
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + r30.u64;
	// stfs f12,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
loc_82A84530:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x829ff808
	return;
}

DEFINE_REX_FUNC(sub_82A84538) {
	REX_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwinm r10,r5,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// or r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 | ctx.r11.u64;
	// beq cr6,0x82a84570
	if (cr6.eq) goto loc_82A84570;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82A8455C:
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82a8455c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82A8455C;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r3
	ctx.r9.u64 = ctx.r11.u64 + ctx.r3.u64;
loc_82A84570:
	// clrlwi r11,r5,31
	ctx.r11.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// sth r8,0(r9)
	REX_STORE_U16(ctx.r9.u32 + 0, ctx.r8.u16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82A84588) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7a8
	ctx.lr = 0x82A84590;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r11,r1,-368
	ctx.r11.s64 = ctx.r1.s64 + -368;
	// li r25,8
	r25.s64 = 8;
loc_82A8459C:
	// lhz r7,48(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 48);
	// lhz r8,16(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 16);
	// lhz r9,32(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 32);
	// extsh r30,r7
	r30.s64 = ctx.r7.s16;
	// lhz r7,80(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 80);
	// extsh r31,r8
	r31.s64 = ctx.r8.s16;
	// lhz r5,96(r10)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r10.u32 + 96);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// extsh r29,r7
	r29.s64 = ctx.r7.s16;
	// lhz r8,64(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 64);
	// extsh r7,r5
	ctx.r7.s64 = ctx.r5.s16;
	// lhz r28,112(r10)
	r28.u64 = REX_LOAD_U16(ctx.r10.u32 + 112);
	// or r5,r31,r9
	ctx.r5.u64 = r31.u64 | ctx.r9.u64;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// or r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 | r30.u64;
	// extsh r28,r28
	r28.s64 = r28.s16;
	// or r5,r5,r8
	ctx.r5.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r5,r5,r29
	ctx.r5.u64 = ctx.r5.u64 | r29.u64;
	// or r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 | ctx.r7.u64;
	// or r5,r5,r28
	ctx.r5.u64 = ctx.r5.u64 | r28.u64;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x82a84634
	if (!cr6.eq) goto loc_82A84634;
	// lhz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// lwz r8,0(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// srawi r9,r9,11
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 11;
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r9,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r9.u32);
	// stw r9,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
	// stw r9,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r9.u32);
	// stw r9,160(r11)
	REX_STORE_U32(ctx.r11.u32 + 160, ctx.r9.u32);
	// stw r9,192(r11)
	REX_STORE_U32(ctx.r11.u32 + 192, ctx.r9.u32);
	// stw r9,224(r11)
	REX_STORE_U32(ctx.r11.u32 + 224, ctx.r9.u32);
	// b 0x82a8475c
	goto loc_82A8475C;
loc_82A84634:
	// lhz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// lwz r27,0(r6)
	r27.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// lwz r26,64(r6)
	r26.u64 = REX_LOAD_U32(ctx.r6.u32 + 64);
	// lwz r24,128(r6)
	r24.u64 = REX_LOAD_U32(ctx.r6.u32 + 128);
	// mullw r5,r5,r27
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(r27.s32);
	// lwz r23,192(r6)
	r23.u64 = REX_LOAD_U32(ctx.r6.u32 + 192);
	// lwz r27,32(r6)
	r27.u64 = REX_LOAD_U32(ctx.r6.u32 + 32);
	// lwz r22,96(r6)
	r22.u64 = REX_LOAD_U32(ctx.r6.u32 + 96);
	// lwz r21,160(r6)
	r21.u64 = REX_LOAD_U32(ctx.r6.u32 + 160);
	// lwz r20,224(r6)
	r20.u64 = REX_LOAD_U32(ctx.r6.u32 + 224);
	// mullw r9,r26,r9
	ctx.r9.s64 = int64_t(r26.s32) * int64_t(ctx.r9.s32);
	// mullw r26,r24,r8
	r26.s64 = int64_t(r24.s32) * int64_t(ctx.r8.s32);
	// srawi r8,r5,11
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 11;
	// mullw r5,r23,r7
	ctx.r5.s64 = int64_t(r23.s32) * int64_t(ctx.r7.s32);
	// srawi r9,r9,11
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 11;
	// srawi r7,r26,11
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x7FF) != 0);
	ctx.r7.s64 = r26.s32 >> 11;
	// srawi r5,r5,11
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 11;
	// mullw r27,r27,r31
	r27.s64 = int64_t(r27.s32) * int64_t(r31.s32);
	// subf r26,r5,r9
	r26.u64 = ctx.r9.u64 - ctx.r5.u64;
	// add r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 + ctx.r9.u64;
	// mulli r5,r26,2896
	ctx.r5.s64 = static_cast<int64_t>(r26.u64 * static_cast<uint64_t>(2896));
	// mullw r30,r22,r30
	r30.s64 = int64_t(r22.s32) * int64_t(r30.s32);
	// srawi r26,r5,11
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FF) != 0);
	r26.s64 = ctx.r5.s32 >> 11;
	// mullw r29,r21,r29
	r29.s64 = int64_t(r21.s32) * int64_t(r29.s32);
	// add r31,r7,r8
	r31.u64 = ctx.r7.u64 + ctx.r8.u64;
	// mullw r28,r20,r28
	r28.s64 = int64_t(r20.s32) * int64_t(r28.s32);
	// srawi r5,r27,11
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x7FF) != 0);
	ctx.r5.s64 = r27.s32 >> 11;
	// srawi r30,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r30.s64 = r30.s32 >> 11;
	// srawi r29,r29,11
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x7FF) != 0);
	r29.s64 = r29.s32 >> 11;
	// subf r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	// add r27,r9,r31
	r27.u64 = ctx.r9.u64 + r31.u64;
	// srawi r28,r28,11
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x7FF) != 0);
	r28.s64 = r28.s32 >> 11;
	// subf r7,r9,r26
	ctx.r7.u64 = r26.u64 - ctx.r9.u64;
	// subf r31,r9,r31
	r31.u64 = r31.u64 - ctx.r9.u64;
	// subf r9,r30,r29
	ctx.r9.u64 = r29.u64 - r30.u64;
	// subf r26,r28,r5
	r26.u64 = ctx.r5.u64 - r28.u64;
	// add r30,r29,r30
	r30.u64 = r29.u64 + r30.u64;
	// add r29,r7,r8
	r29.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r5,r28,r5
	ctx.r5.u64 = r28.u64 + ctx.r5.u64;
	// subf r7,r7,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r7.u64;
	// add r8,r26,r9
	ctx.r8.u64 = r26.u64 + ctx.r9.u64;
	// mulli r28,r9,-5352
	r28.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(-5352));
	// add r9,r5,r30
	ctx.r9.u64 = ctx.r5.u64 + r30.u64;
	// subf r5,r30,r5
	ctx.r5.u64 = ctx.r5.u64 - r30.u64;
	// mulli r8,r8,3784
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(3784));
	// srawi r8,r8,11
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 11;
	// mulli r5,r5,2896
	ctx.r5.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(2896));
	// srawi r28,r28,11
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x7FF) != 0);
	r28.s64 = r28.s32 >> 11;
	// mulli r30,r26,2217
	r30.s64 = static_cast<int64_t>(r26.u64 * static_cast<uint64_t>(2217));
	// srawi r26,r5,11
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FF) != 0);
	r26.s64 = ctx.r5.s32 >> 11;
	// subf r5,r9,r28
	ctx.r5.u64 = r28.u64 - ctx.r9.u64;
	// add r28,r9,r27
	r28.u64 = ctx.r9.u64 + r27.u64;
	// subf r9,r9,r27
	ctx.r9.u64 = r27.u64 - ctx.r9.u64;
	// srawi r30,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r30.s64 = r30.s32 >> 11;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, r28.u32);
	// stw r9,224(r11)
	REX_STORE_U32(ctx.r11.u32 + 224, ctx.r9.u32);
	// add r9,r5,r8
	ctx.r9.u64 = ctx.r5.u64 + ctx.r8.u64;
	// subf r5,r8,r30
	ctx.r5.u64 = r30.u64 - ctx.r8.u64;
	// subf r8,r9,r26
	ctx.r8.u64 = r26.u64 - ctx.r9.u64;
	// add r30,r9,r29
	r30.u64 = ctx.r9.u64 + r29.u64;
	// subf r9,r9,r29
	ctx.r9.u64 = r29.u64 - ctx.r9.u64;
	// stw r30,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, r30.u32);
	// stw r9,192(r11)
	REX_STORE_U32(ctx.r11.u32 + 192, ctx.r9.u32);
	// add r9,r5,r8
	ctx.r9.u64 = ctx.r5.u64 + ctx.r8.u64;
	// add r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 + ctx.r7.u64;
	// subf r8,r8,r7
	ctx.r8.u64 = ctx.r7.u64 - ctx.r8.u64;
	// stw r5,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r5.u32);
	// stw r8,160(r11)
	REX_STORE_U32(ctx.r11.u32 + 160, ctx.r8.u32);
	// add r8,r9,r31
	ctx.r8.u64 = ctx.r9.u64 + r31.u64;
	// subf r9,r9,r31
	ctx.r9.u64 = r31.u64 - ctx.r9.u64;
	// stw r8,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r8.u32);
loc_82A8475C:
	// addi r25,r25,-1
	r25.s64 = r25.s64 + -1;
	// stw r9,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bgt cr6,0x82a8459c
	if (cr6.gt) goto loc_82A8459C;
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// addi r11,r1,-344
	ctx.r11.s64 = ctx.r1.s64 + -344;
	// li r7,8
	ctx.r7.s64 = 8;
loc_82A8477C:
	// lwz r9,-4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// lwz r8,-12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -12);
	// lwz r5,-20(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + -20);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lwz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf r28,r8,r9
	r28.u64 = ctx.r9.u64 - ctx.r8.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// add r27,r8,r9
	r27.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r31,-16(r11)
	r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -16);
	// subf r26,r6,r5
	r26.u64 = ctx.r5.u64 - ctx.r6.u64;
	// lwz r30,-8(r11)
	r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -8);
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// add r9,r3,r31
	ctx.r9.u64 = ctx.r3.u64 + r31.u64;
	// lwz r29,-24(r11)
	r29.u64 = REX_LOAD_U32(ctx.r11.u32 + -24);
	// subf r8,r3,r31
	ctx.r8.u64 = r31.u64 - ctx.r3.u64;
	// add r31,r26,r28
	r31.u64 = r26.u64 + r28.u64;
	// mulli r8,r8,2896
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(2896));
	// subf r3,r30,r29
	ctx.r3.u64 = r29.u64 - r30.u64;
	// add r5,r29,r30
	ctx.r5.u64 = r29.u64 + r30.u64;
	// mulli r31,r31,3784
	r31.s64 = static_cast<int64_t>(r31.u64 * static_cast<uint64_t>(3784));
	// mulli r30,r28,-5352
	r30.s64 = static_cast<int64_t>(r28.u64 * static_cast<uint64_t>(-5352));
	// srawi r25,r8,11
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	r25.s64 = ctx.r8.s32 >> 11;
	// srawi r31,r31,11
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x7FF) != 0);
	r31.s64 = r31.s32 >> 11;
	// srawi r29,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r29.s64 = r30.s32 >> 11;
	// subf r30,r27,r6
	r30.u64 = ctx.r6.u64 - r27.u64;
	// add r8,r6,r27
	ctx.r8.u64 = ctx.r6.u64 + r27.u64;
	// mulli r30,r30,2896
	r30.s64 = static_cast<int64_t>(r30.u64 * static_cast<uint64_t>(2896));
	// srawi r28,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r28.s64 = r30.s32 >> 11;
	// mulli r27,r26,2217
	r27.s64 = static_cast<int64_t>(r26.u64 * static_cast<uint64_t>(2217));
	// add r30,r9,r5
	r30.u64 = ctx.r9.u64 + ctx.r5.u64;
	// subf r6,r9,r25
	ctx.r6.u64 = r25.u64 - ctx.r9.u64;
	// subf r5,r9,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r9.u64;
	// subf r9,r8,r29
	ctx.r9.u64 = r29.u64 - ctx.r8.u64;
	// srawi r27,r27,11
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x7FF) != 0);
	r27.s64 = r27.s32 >> 11;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// subf r29,r31,r27
	r29.u64 = r27.u64 - r31.u64;
	// add r31,r6,r3
	r31.u64 = ctx.r6.u64 + ctx.r3.u64;
	// subf r6,r6,r3
	ctx.r6.u64 = ctx.r3.u64 - ctx.r6.u64;
	// add r3,r8,r30
	ctx.r3.u64 = ctx.r8.u64 + r30.u64;
	// subf r8,r8,r30
	ctx.r8.u64 = r30.u64 - ctx.r8.u64;
	// addi r3,r3,127
	ctx.r3.s64 = ctx.r3.s64 + 127;
	// addi r8,r8,127
	ctx.r8.s64 = ctx.r8.s64 + 127;
	// srawi r3,r3,8
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 8;
	// srawi r8,r8,8
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 8;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// stb r3,-1(r10)
	REX_STORE_U8(ctx.r10.u32 + -1, ctx.r3.u8);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// stb r8,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, ctx.r8.u8);
	// subf r8,r9,r28
	ctx.r8.u64 = r28.u64 - ctx.r9.u64;
	// subf r9,r9,r31
	ctx.r9.u64 = r31.u64 - ctx.r9.u64;
	// addi r3,r3,127
	ctx.r3.s64 = ctx.r3.s64 + 127;
	// addi r9,r9,127
	ctx.r9.s64 = ctx.r9.s64 + 127;
	// srawi r3,r3,8
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 8;
	// srawi r9,r9,8
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 8;
	// stb r3,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r3.u8);
	// add r3,r8,r6
	ctx.r3.u64 = ctx.r8.u64 + ctx.r6.u64;
	// stb r9,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, ctx.r9.u8);
	// add r9,r29,r8
	ctx.r9.u64 = r29.u64 + ctx.r8.u64;
	// subf r8,r8,r6
	ctx.r8.u64 = ctx.r6.u64 - ctx.r8.u64;
	// addi r6,r3,127
	ctx.r6.s64 = ctx.r3.s64 + 127;
	// addi r8,r8,127
	ctx.r8.s64 = ctx.r8.s64 + 127;
	// srawi r6,r6,8
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 8;
	// srawi r8,r8,8
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 8;
	// stb r6,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r6.u8);
	// stb r8,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r8.u8);
	// add r8,r9,r5
	ctx.r8.u64 = ctx.r9.u64 + ctx.r5.u64;
	// subf r9,r9,r5
	ctx.r9.u64 = ctx.r5.u64 - ctx.r9.u64;
	// addi r8,r8,127
	ctx.r8.s64 = ctx.r8.s64 + 127;
	// addi r9,r9,127
	ctx.r9.s64 = ctx.r9.s64 + 127;
	// srawi r8,r8,8
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 8;
	// srawi r9,r9,8
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 8;
	// stb r8,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, ctx.r8.u8);
	// stb r9,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r9.u8);
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// bne cr6,0x82a8477c
	if (!cr6.eq) goto loc_82A8477C;
	// b 0x829ff7f8
	return;
}

DEFINE_REX_FUNC(sub_82A848B0) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r19{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7a4
	ctx.lr = 0x82A848B8;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// add r9,r3,r4
	ctx.r9.u64 = ctx.r3.u64 + ctx.r4.u64;
	// rlwinm r25,r4,1,0,30
	r25.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r1,-368
	ctx.r11.s64 = ctx.r1.s64 + -368;
	// li r24,8
	r24.s64 = 8;
loc_82A848CC:
	// lhz r5,48(r10)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r10.u32 + 48);
	// lhz r7,16(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 16);
	// lhz r8,32(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 32);
	// extsh r30,r5
	r30.s64 = ctx.r5.s16;
	// lhz r5,80(r10)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r10.u32 + 80);
	// extsh r31,r7
	r31.s64 = ctx.r7.s16;
	// lhz r4,96(r10)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r10.u32 + 96);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// extsh r29,r5
	r29.s64 = ctx.r5.s16;
	// lhz r7,64(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 64);
	// extsh r5,r4
	ctx.r5.s64 = ctx.r4.s16;
	// lhz r28,112(r10)
	r28.u64 = REX_LOAD_U16(ctx.r10.u32 + 112);
	// or r4,r31,r8
	ctx.r4.u64 = r31.u64 | ctx.r8.u64;
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// or r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 | r30.u64;
	// extsh r28,r28
	r28.s64 = r28.s16;
	// or r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 | ctx.r7.u64;
	// or r4,r4,r29
	ctx.r4.u64 = ctx.r4.u64 | r29.u64;
	// or r4,r4,r5
	ctx.r4.u64 = ctx.r4.u64 | ctx.r5.u64;
	// or r4,r4,r28
	ctx.r4.u64 = ctx.r4.u64 | r28.u64;
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x82a84964
	if (!cr6.eq) goto loc_82A84964;
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// lwz r7,0(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// mullw r8,r8,r7
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// srawi r8,r8,11
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 11;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stw r8,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r8.u32);
	// stw r8,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r8.u32);
	// stw r8,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r8.u32);
	// stw r8,160(r11)
	REX_STORE_U32(ctx.r11.u32 + 160, ctx.r8.u32);
	// stw r8,192(r11)
	REX_STORE_U32(ctx.r11.u32 + 192, ctx.r8.u32);
	// stw r8,224(r11)
	REX_STORE_U32(ctx.r11.u32 + 224, ctx.r8.u32);
	// b 0x82a84a8c
	goto loc_82A84A8C;
loc_82A84964:
	// lhz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// lwz r27,0(r6)
	r27.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// lwz r26,64(r6)
	r26.u64 = REX_LOAD_U32(ctx.r6.u32 + 64);
	// lwz r23,128(r6)
	r23.u64 = REX_LOAD_U32(ctx.r6.u32 + 128);
	// mullw r4,r4,r27
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(r27.s32);
	// lwz r22,192(r6)
	r22.u64 = REX_LOAD_U32(ctx.r6.u32 + 192);
	// lwz r27,32(r6)
	r27.u64 = REX_LOAD_U32(ctx.r6.u32 + 32);
	// lwz r21,96(r6)
	r21.u64 = REX_LOAD_U32(ctx.r6.u32 + 96);
	// lwz r20,160(r6)
	r20.u64 = REX_LOAD_U32(ctx.r6.u32 + 160);
	// lwz r19,224(r6)
	r19.u64 = REX_LOAD_U32(ctx.r6.u32 + 224);
	// mullw r8,r26,r8
	ctx.r8.s64 = int64_t(r26.s32) * int64_t(ctx.r8.s32);
	// mullw r26,r23,r7
	r26.s64 = int64_t(r23.s32) * int64_t(ctx.r7.s32);
	// srawi r7,r4,11
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FF) != 0);
	ctx.r7.s64 = ctx.r4.s32 >> 11;
	// mullw r4,r22,r5
	ctx.r4.s64 = int64_t(r22.s32) * int64_t(ctx.r5.s32);
	// srawi r8,r8,11
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 11;
	// srawi r5,r26,11
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x7FF) != 0);
	ctx.r5.s64 = r26.s32 >> 11;
	// srawi r4,r4,11
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 11;
	// mullw r27,r27,r31
	r27.s64 = int64_t(r27.s32) * int64_t(r31.s32);
	// subf r26,r4,r8
	r26.u64 = ctx.r8.u64 - ctx.r4.u64;
	// add r8,r4,r8
	ctx.r8.u64 = ctx.r4.u64 + ctx.r8.u64;
	// mulli r4,r26,2896
	ctx.r4.s64 = static_cast<int64_t>(r26.u64 * static_cast<uint64_t>(2896));
	// mullw r30,r21,r30
	r30.s64 = int64_t(r21.s32) * int64_t(r30.s32);
	// srawi r26,r4,11
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FF) != 0);
	r26.s64 = ctx.r4.s32 >> 11;
	// mullw r29,r20,r29
	r29.s64 = int64_t(r20.s32) * int64_t(r29.s32);
	// add r31,r5,r7
	r31.u64 = ctx.r5.u64 + ctx.r7.u64;
	// mullw r28,r19,r28
	r28.s64 = int64_t(r19.s32) * int64_t(r28.s32);
	// srawi r4,r27,11
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x7FF) != 0);
	ctx.r4.s64 = r27.s32 >> 11;
	// srawi r30,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r30.s64 = r30.s32 >> 11;
	// srawi r29,r29,11
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x7FF) != 0);
	r29.s64 = r29.s32 >> 11;
	// subf r7,r5,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r5.u64;
	// add r27,r8,r31
	r27.u64 = ctx.r8.u64 + r31.u64;
	// srawi r28,r28,11
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x7FF) != 0);
	r28.s64 = r28.s32 >> 11;
	// subf r5,r8,r26
	ctx.r5.u64 = r26.u64 - ctx.r8.u64;
	// subf r31,r8,r31
	r31.u64 = r31.u64 - ctx.r8.u64;
	// subf r8,r30,r29
	ctx.r8.u64 = r29.u64 - r30.u64;
	// subf r26,r28,r4
	r26.u64 = ctx.r4.u64 - r28.u64;
	// add r30,r29,r30
	r30.u64 = r29.u64 + r30.u64;
	// add r29,r5,r7
	r29.u64 = ctx.r5.u64 + ctx.r7.u64;
	// add r4,r28,r4
	ctx.r4.u64 = r28.u64 + ctx.r4.u64;
	// subf r5,r5,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r5.u64;
	// add r7,r26,r8
	ctx.r7.u64 = r26.u64 + ctx.r8.u64;
	// mulli r28,r8,-5352
	r28.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(-5352));
	// add r8,r4,r30
	ctx.r8.u64 = ctx.r4.u64 + r30.u64;
	// subf r4,r30,r4
	ctx.r4.u64 = ctx.r4.u64 - r30.u64;
	// mulli r7,r7,3784
	ctx.r7.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(3784));
	// srawi r7,r7,11
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 11;
	// mulli r4,r4,2896
	ctx.r4.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(2896));
	// srawi r28,r28,11
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x7FF) != 0);
	r28.s64 = r28.s32 >> 11;
	// mulli r30,r26,2217
	r30.s64 = static_cast<int64_t>(r26.u64 * static_cast<uint64_t>(2217));
	// srawi r26,r4,11
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FF) != 0);
	r26.s64 = ctx.r4.s32 >> 11;
	// subf r4,r8,r28
	ctx.r4.u64 = r28.u64 - ctx.r8.u64;
	// add r28,r8,r27
	r28.u64 = ctx.r8.u64 + r27.u64;
	// subf r8,r8,r27
	ctx.r8.u64 = r27.u64 - ctx.r8.u64;
	// srawi r30,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r30.s64 = r30.s32 >> 11;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, r28.u32);
	// stw r8,224(r11)
	REX_STORE_U32(ctx.r11.u32 + 224, ctx.r8.u32);
	// add r8,r4,r7
	ctx.r8.u64 = ctx.r4.u64 + ctx.r7.u64;
	// subf r4,r7,r30
	ctx.r4.u64 = r30.u64 - ctx.r7.u64;
	// subf r7,r8,r26
	ctx.r7.u64 = r26.u64 - ctx.r8.u64;
	// add r30,r8,r29
	r30.u64 = ctx.r8.u64 + r29.u64;
	// subf r8,r8,r29
	ctx.r8.u64 = r29.u64 - ctx.r8.u64;
	// stw r30,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, r30.u32);
	// stw r8,192(r11)
	REX_STORE_U32(ctx.r11.u32 + 192, ctx.r8.u32);
	// add r8,r4,r7
	ctx.r8.u64 = ctx.r4.u64 + ctx.r7.u64;
	// add r4,r7,r5
	ctx.r4.u64 = ctx.r7.u64 + ctx.r5.u64;
	// subf r7,r7,r5
	ctx.r7.u64 = ctx.r5.u64 - ctx.r7.u64;
	// stw r4,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r4.u32);
	// stw r7,160(r11)
	REX_STORE_U32(ctx.r11.u32 + 160, ctx.r7.u32);
	// add r7,r8,r31
	ctx.r7.u64 = ctx.r8.u64 + r31.u64;
	// subf r8,r8,r31
	ctx.r8.u64 = r31.u64 - ctx.r8.u64;
	// stw r7,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r7.u32);
loc_82A84A8C:
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// stw r8,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r8.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bgt cr6,0x82a848cc
	if (cr6.gt) goto loc_82A848CC;
	// addi r11,r1,-344
	ctx.r11.s64 = ctx.r1.s64 + -344;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
	// li r6,8
	ctx.r6.s64 = 8;
loc_82A84AAC:
	// lwz r8,-4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// lwz r7,-12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + -12);
	// lwz r4,-20(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + -20);
	// lwz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf r28,r7,r8
	r28.u64 = ctx.r8.u64 - ctx.r7.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// add r27,r7,r8
	r27.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lwz r31,-16(r11)
	r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -16);
	// subf r26,r5,r4
	r26.u64 = ctx.r4.u64 - ctx.r5.u64;
	// lwz r30,-8(r11)
	r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -8);
	// add r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 + ctx.r5.u64;
	// add r8,r31,r3
	ctx.r8.u64 = r31.u64 + ctx.r3.u64;
	// lwz r29,-24(r11)
	r29.u64 = REX_LOAD_U32(ctx.r11.u32 + -24);
	// subf r7,r3,r31
	ctx.r7.u64 = r31.u64 - ctx.r3.u64;
	// add r31,r26,r28
	r31.u64 = r26.u64 + r28.u64;
	// mulli r7,r7,2896
	ctx.r7.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(2896));
	// subf r3,r30,r29
	ctx.r3.u64 = r29.u64 - r30.u64;
	// add r4,r29,r30
	ctx.r4.u64 = r29.u64 + r30.u64;
	// mulli r31,r31,3784
	r31.s64 = static_cast<int64_t>(r31.u64 * static_cast<uint64_t>(3784));
	// mulli r30,r28,-5352
	r30.s64 = static_cast<int64_t>(r28.u64 * static_cast<uint64_t>(-5352));
	// srawi r24,r7,11
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FF) != 0);
	r24.s64 = ctx.r7.s32 >> 11;
	// srawi r31,r31,11
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x7FF) != 0);
	r31.s64 = r31.s32 >> 11;
	// srawi r29,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r29.s64 = r30.s32 >> 11;
	// subf r30,r27,r5
	r30.u64 = ctx.r5.u64 - r27.u64;
	// add r7,r5,r27
	ctx.r7.u64 = ctx.r5.u64 + r27.u64;
	// mulli r30,r30,2896
	r30.s64 = static_cast<int64_t>(r30.u64 * static_cast<uint64_t>(2896));
	// srawi r28,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r28.s64 = r30.s32 >> 11;
	// mulli r30,r26,2217
	r30.s64 = static_cast<int64_t>(r26.u64 * static_cast<uint64_t>(2217));
	// srawi r27,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r27.s64 = r30.s32 >> 11;
	// add r30,r8,r4
	r30.u64 = ctx.r8.u64 + ctx.r4.u64;
	// subf r4,r8,r4
	ctx.r4.u64 = ctx.r4.u64 - ctx.r8.u64;
	// subf r5,r8,r24
	ctx.r5.u64 = r24.u64 - ctx.r8.u64;
	// subf r8,r7,r29
	ctx.r8.u64 = r29.u64 - ctx.r7.u64;
	// subf r29,r31,r27
	r29.u64 = r27.u64 - r31.u64;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + r31.u64;
	// add r31,r5,r3
	r31.u64 = ctx.r5.u64 + ctx.r3.u64;
	// subf r5,r5,r3
	ctx.r5.u64 = ctx.r3.u64 - ctx.r5.u64;
	// add r3,r7,r30
	ctx.r3.u64 = ctx.r7.u64 + r30.u64;
	// subf r7,r7,r30
	ctx.r7.u64 = r30.u64 - ctx.r7.u64;
	// addi r3,r3,127
	ctx.r3.s64 = ctx.r3.s64 + 127;
	// addi r30,r7,127
	r30.s64 = ctx.r7.s64 + 127;
	// srawi r7,r3,8
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r3.s32 >> 8;
	// add r3,r8,r31
	ctx.r3.u64 = ctx.r8.u64 + r31.u64;
	// rlwinm r27,r7,16,8,15
	r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFF0000;
	// subf r7,r8,r28
	ctx.r7.u64 = r28.u64 - ctx.r8.u64;
	// subf r8,r8,r31
	ctx.r8.u64 = r31.u64 - ctx.r8.u64;
	// addi r3,r3,127
	ctx.r3.s64 = ctx.r3.s64 + 127;
	// addi r8,r8,127
	ctx.r8.s64 = ctx.r8.s64 + 127;
	// srawi r3,r3,8
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 8;
	// srawi r8,r8,8
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 8;
	// srawi r31,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r31.s64 = r30.s32 >> 8;
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r30,r8,16,8,15
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFF0000;
	// clrlwi r31,r31,24
	r31.u64 = r31.u32 & 0xFF;
	// or r8,r27,r3
	ctx.r8.u64 = r27.u64 | ctx.r3.u64;
	// or r3,r30,r31
	ctx.r3.u64 = r30.u64 | r31.u64;
	// add r31,r29,r7
	r31.u64 = r29.u64 + ctx.r7.u64;
	// subf r30,r7,r5
	r30.u64 = ctx.r5.u64 - ctx.r7.u64;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// add r5,r31,r4
	ctx.r5.u64 = r31.u64 + ctx.r4.u64;
	// addi r29,r7,127
	r29.s64 = ctx.r7.s64 + 127;
	// addi r5,r5,127
	ctx.r5.s64 = ctx.r5.s64 + 127;
	// addi r30,r30,127
	r30.s64 = r30.s64 + 127;
	// subf r7,r31,r4
	ctx.r7.u64 = ctx.r4.u64 - r31.u64;
	// srawi r5,r5,8
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 8;
	// srawi r4,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r4.s64 = r30.s32 >> 8;
	// addi r7,r7,127
	ctx.r7.s64 = ctx.r7.s64 + 127;
	// clrlwi r4,r4,24
	ctx.r4.u64 = ctx.r4.u32 & 0xFF;
	// srawi r31,r29,8
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0xFF) != 0);
	r31.s64 = r29.s32 >> 8;
	// rlwinm r5,r5,16,8,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFF0000;
	// srawi r30,r7,8
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	r30.s64 = ctx.r7.s32 >> 8;
	// or r7,r5,r4
	ctx.r7.u64 = ctx.r5.u64 | ctx.r4.u64;
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// rlwinm r5,r31,16,8,15
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 16) & 0xFF0000;
	// rlwinm r31,r8,8,0,23
	r31.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 | ctx.r4.u64;
	// rlwinm r4,r3,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r30,r7,8,0,23
	r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r31,r8
	ctx.r8.u64 = r31.u64 | ctx.r8.u64;
	// or r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 | ctx.r3.u64;
	// or r7,r30,r7
	ctx.r7.u64 = r30.u64 | ctx.r7.u64;
	// rlwinm r3,r5,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// stw r8,-8(r10)
	REX_STORE_U32(ctx.r10.u32 + -8, ctx.r8.u32);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// stw r4,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// or r5,r3,r5
	ctx.r5.u64 = ctx.r3.u64 | ctx.r5.u64;
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r5,-4(r10)
	REX_STORE_U32(ctx.r10.u32 + -4, ctx.r5.u32);
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + r25.u64;
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// stw r5,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r5.u32);
	// stw r7,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// stw r4,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r4.u32);
	// add r9,r25,r9
	ctx.r9.u64 = r25.u64 + ctx.r9.u64;
	// bne cr6,0x82a84aac
	if (!cr6.eq) goto loc_82A84AAC;
	// b 0x829ff7f4
	return;
}

DEFINE_REX_FUNC(sub_82A84C38) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// rlwinm r10,r6,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// addi r11,r11,-28000
	ctx.r11.s64 = ctx.r11.s64 + -28000;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x82a84588
	sub_82A84588(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82A84C50) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// rlwinm r10,r6,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// addi r11,r11,-28000
	ctx.r11.s64 = ctx.r11.s64 + -28000;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x82a848b0
	sub_82A848B0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82A84C68) {
	REX_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r18{};
	PPCRegister r19{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7a0
	ctx.lr = 0x82A84C70;
	// lis r11,-32236
	ctx.r11.s64 = -2112618496;
	// rlwinm r10,r6,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// addi r11,r11,-23904
	ctx.r11.s64 = ctx.r11.s64 + -23904;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r1,-384
	ctx.r11.s64 = ctx.r1.s64 + -384;
	// li r23,8
	r23.s64 = 8;
loc_82A84C8C:
	// lhz r31,48(r9)
	r31.u64 = REX_LOAD_U16(ctx.r9.u32 + 48);
	// lhz r5,16(r9)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r9.u32 + 16);
	// lhz r6,32(r9)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r9.u32 + 32);
	// extsh r28,r31
	r28.s64 = r31.s16;
	// lhz r31,80(r9)
	r31.u64 = REX_LOAD_U16(ctx.r9.u32 + 80);
	// extsh r29,r5
	r29.s64 = ctx.r5.s16;
	// lhz r30,96(r9)
	r30.u64 = REX_LOAD_U16(ctx.r9.u32 + 96);
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// extsh r27,r31
	r27.s64 = r31.s16;
	// lhz r5,64(r9)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r9.u32 + 64);
	// extsh r31,r30
	r31.s64 = r30.s16;
	// lhz r26,112(r9)
	r26.u64 = REX_LOAD_U16(ctx.r9.u32 + 112);
	// or r30,r29,r6
	r30.u64 = r29.u64 | ctx.r6.u64;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// or r30,r30,r28
	r30.u64 = r30.u64 | r28.u64;
	// extsh r26,r26
	r26.s64 = r26.s16;
	// or r30,r30,r5
	r30.u64 = r30.u64 | ctx.r5.u64;
	// or r30,r30,r27
	r30.u64 = r30.u64 | r27.u64;
	// or r30,r30,r31
	r30.u64 = r30.u64 | r31.u64;
	// or r30,r30,r26
	r30.u64 = r30.u64 | r26.u64;
	// extsh r30,r30
	r30.s64 = r30.s16;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x82a84d24
	if (!cr6.eq) goto loc_82A84D24;
	// lhz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// mullw r6,r6,r5
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// srawi r6,r6,11
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 11;
	// stw r6,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// stw r6,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// stw r6,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r6.u32);
	// stw r6,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r6.u32);
	// stw r6,160(r11)
	REX_STORE_U32(ctx.r11.u32 + 160, ctx.r6.u32);
	// stw r6,192(r11)
	REX_STORE_U32(ctx.r11.u32 + 192, ctx.r6.u32);
	// stw r6,224(r11)
	REX_STORE_U32(ctx.r11.u32 + 224, ctx.r6.u32);
	// b 0x82a84e4c
	goto loc_82A84E4C;
loc_82A84D24:
	// lhz r30,0(r9)
	r30.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// lwz r25,0(r10)
	r25.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// extsh r30,r30
	r30.s64 = r30.s16;
	// lwz r24,64(r10)
	r24.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r22,128(r10)
	r22.u64 = REX_LOAD_U32(ctx.r10.u32 + 128);
	// mullw r30,r30,r25
	r30.s64 = int64_t(r30.s32) * int64_t(r25.s32);
	// lwz r21,192(r10)
	r21.u64 = REX_LOAD_U32(ctx.r10.u32 + 192);
	// lwz r25,32(r10)
	r25.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// lwz r20,96(r10)
	r20.u64 = REX_LOAD_U32(ctx.r10.u32 + 96);
	// lwz r19,160(r10)
	r19.u64 = REX_LOAD_U32(ctx.r10.u32 + 160);
	// lwz r18,224(r10)
	r18.u64 = REX_LOAD_U32(ctx.r10.u32 + 224);
	// mullw r6,r24,r6
	ctx.r6.s64 = int64_t(r24.s32) * int64_t(ctx.r6.s32);
	// mullw r24,r22,r5
	r24.s64 = int64_t(r22.s32) * int64_t(ctx.r5.s32);
	// srawi r5,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	ctx.r5.s64 = r30.s32 >> 11;
	// mullw r30,r21,r31
	r30.s64 = int64_t(r21.s32) * int64_t(r31.s32);
	// srawi r6,r6,11
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 11;
	// srawi r31,r24,11
	xer.ca = (r24.s32 < 0) & ((r24.u32 & 0x7FF) != 0);
	r31.s64 = r24.s32 >> 11;
	// srawi r30,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r30.s64 = r30.s32 >> 11;
	// mullw r25,r25,r29
	r25.s64 = int64_t(r25.s32) * int64_t(r29.s32);
	// subf r24,r30,r6
	r24.u64 = ctx.r6.u64 - r30.u64;
	// add r6,r30,r6
	ctx.r6.u64 = r30.u64 + ctx.r6.u64;
	// mulli r30,r24,2896
	r30.s64 = static_cast<int64_t>(r24.u64 * static_cast<uint64_t>(2896));
	// mullw r28,r20,r28
	r28.s64 = int64_t(r20.s32) * int64_t(r28.s32);
	// srawi r24,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r24.s64 = r30.s32 >> 11;
	// mullw r27,r19,r27
	r27.s64 = int64_t(r19.s32) * int64_t(r27.s32);
	// add r29,r31,r5
	r29.u64 = r31.u64 + ctx.r5.u64;
	// mullw r26,r18,r26
	r26.s64 = int64_t(r18.s32) * int64_t(r26.s32);
	// srawi r30,r25,11
	xer.ca = (r25.s32 < 0) & ((r25.u32 & 0x7FF) != 0);
	r30.s64 = r25.s32 >> 11;
	// srawi r28,r28,11
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x7FF) != 0);
	r28.s64 = r28.s32 >> 11;
	// srawi r27,r27,11
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x7FF) != 0);
	r27.s64 = r27.s32 >> 11;
	// subf r5,r31,r5
	ctx.r5.u64 = ctx.r5.u64 - r31.u64;
	// add r25,r6,r29
	r25.u64 = ctx.r6.u64 + r29.u64;
	// srawi r26,r26,11
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x7FF) != 0);
	r26.s64 = r26.s32 >> 11;
	// subf r31,r6,r24
	r31.u64 = r24.u64 - ctx.r6.u64;
	// subf r29,r6,r29
	r29.u64 = r29.u64 - ctx.r6.u64;
	// subf r6,r28,r27
	ctx.r6.u64 = r27.u64 - r28.u64;
	// subf r24,r26,r30
	r24.u64 = r30.u64 - r26.u64;
	// add r28,r27,r28
	r28.u64 = r27.u64 + r28.u64;
	// add r27,r31,r5
	r27.u64 = r31.u64 + ctx.r5.u64;
	// add r30,r26,r30
	r30.u64 = r26.u64 + r30.u64;
	// subf r31,r31,r5
	r31.u64 = ctx.r5.u64 - r31.u64;
	// add r5,r24,r6
	ctx.r5.u64 = r24.u64 + ctx.r6.u64;
	// mulli r26,r6,-5352
	r26.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(-5352));
	// add r6,r30,r28
	ctx.r6.u64 = r30.u64 + r28.u64;
	// subf r30,r28,r30
	r30.u64 = r30.u64 - r28.u64;
	// mulli r5,r5,3784
	ctx.r5.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(3784));
	// srawi r5,r5,11
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 11;
	// mulli r30,r30,2896
	r30.s64 = static_cast<int64_t>(r30.u64 * static_cast<uint64_t>(2896));
	// srawi r26,r26,11
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x7FF) != 0);
	r26.s64 = r26.s32 >> 11;
	// mulli r28,r24,2217
	r28.s64 = static_cast<int64_t>(r24.u64 * static_cast<uint64_t>(2217));
	// srawi r24,r30,11
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7FF) != 0);
	r24.s64 = r30.s32 >> 11;
	// subf r30,r6,r26
	r30.u64 = r26.u64 - ctx.r6.u64;
	// add r26,r6,r25
	r26.u64 = ctx.r6.u64 + r25.u64;
	// subf r6,r6,r25
	ctx.r6.u64 = r25.u64 - ctx.r6.u64;
	// srawi r28,r28,11
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x7FF) != 0);
	r28.s64 = r28.s32 >> 11;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r26,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, r26.u32);
	// stw r6,224(r11)
	REX_STORE_U32(ctx.r11.u32 + 224, ctx.r6.u32);
	// add r6,r30,r5
	ctx.r6.u64 = r30.u64 + ctx.r5.u64;
	// subf r30,r5,r28
	r30.u64 = r28.u64 - ctx.r5.u64;
	// subf r5,r6,r24
	ctx.r5.u64 = r24.u64 - ctx.r6.u64;
	// add r28,r6,r27
	r28.u64 = ctx.r6.u64 + r27.u64;
	// subf r6,r6,r27
	ctx.r6.u64 = r27.u64 - ctx.r6.u64;
	// stw r28,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, r28.u32);
	// stw r6,192(r11)
	REX_STORE_U32(ctx.r11.u32 + 192, ctx.r6.u32);
	// add r6,r30,r5
	ctx.r6.u64 = r30.u64 + ctx.r5.u64;
	// add r30,r5,r31
	r30.u64 = ctx.r5.u64 + r31.u64;
	// subf r5,r5,r31
	ctx.r5.u64 = r31.u64 - ctx.r5.u64;
	// stw r30,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, r30.u32);
	// stw r5,160(r11)
	REX_STORE_U32(ctx.r11.u32 + 160, ctx.r5.u32);
	// add r5,r6,r29
	ctx.r5.u64 = ctx.r6.u64 + r29.u64;
	// subf r6,r6,r29
	ctx.r6.u64 = r29.u64 - ctx.r6.u64;
	// stw r5,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r5.u32);
loc_82A84E4C:
	// addi r23,r23,-1
	r23.s64 = r23.s64 + -1;
	// stw r6,96(r11)
	REX_STORE_U32(ctx.r11.u32 + 96, ctx.r6.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// bgt cr6,0x82a84c8c
	if (cr6.gt) goto loc_82A84C8C;
	// addi r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 1;
	// addi r10,r7,1
	ctx.r10.s64 = ctx.r7.s64 + 1;
	// addi r11,r1,-360
	ctx.r11.s64 = ctx.r1.s64 + -360;
	// li r5,8
	ctx.r5.s64 = 8;
loc_82A84E70:
	// lwz r7,-4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// lwz r6,-12(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -12);
	// lwz r30,0(r11)
	r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r29,-16(r11)
	r29.u64 = REX_LOAD_U32(ctx.r11.u32 + -16);
	// subf r26,r6,r7
	r26.u64 = ctx.r7.u64 - ctx.r6.u64;
	// add r25,r6,r7
	r25.u64 = ctx.r6.u64 + ctx.r7.u64;
	// lwz r31,-20(r11)
	r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -20);
	// subf r6,r30,r29
	ctx.r6.u64 = r29.u64 - r30.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// add r7,r29,r30
	ctx.r7.u64 = r29.u64 + r30.u64;
	// lwz r28,-8(r11)
	r28.u64 = REX_LOAD_U32(ctx.r11.u32 + -8);
	// subf r24,r3,r31
	r24.u64 = r31.u64 - ctx.r3.u64;
	// lwz r27,-24(r11)
	r27.u64 = REX_LOAD_U32(ctx.r11.u32 + -24);
	// mulli r6,r6,2896
	ctx.r6.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(2896));
	// lbz r23,-1(r10)
	r23.u64 = REX_LOAD_U8(ctx.r10.u32 + -1);
	// add r3,r31,r3
	ctx.r3.u64 = r31.u64 + ctx.r3.u64;
	// srawi r22,r6,11
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FF) != 0);
	r22.s64 = ctx.r6.s32 >> 11;
	// add r29,r24,r26
	r29.u64 = r24.u64 + r26.u64;
	// add r6,r3,r25
	ctx.r6.u64 = ctx.r3.u64 + r25.u64;
	// subf r3,r25,r3
	ctx.r3.u64 = ctx.r3.u64 - r25.u64;
	// mulli r29,r29,3784
	r29.s64 = static_cast<int64_t>(r29.u64 * static_cast<uint64_t>(3784));
	// mulli r21,r26,-5352
	r21.s64 = static_cast<int64_t>(r26.u64 * static_cast<uint64_t>(-5352));
	// add r31,r27,r28
	r31.u64 = r27.u64 + r28.u64;
	// mulli r3,r3,2896
	ctx.r3.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(2896));
	// srawi r29,r29,11
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x7FF) != 0);
	r29.s64 = r29.s32 >> 11;
	// subf r30,r28,r27
	r30.u64 = r27.u64 - r28.u64;
	// srawi r26,r21,11
	xer.ca = (r21.s32 < 0) & ((r21.u32 & 0x7FF) != 0);
	r26.s64 = r21.s32 >> 11;
	// mulli r25,r24,2217
	r25.s64 = static_cast<int64_t>(r24.u64 * static_cast<uint64_t>(2217));
	// add r27,r7,r31
	r27.u64 = ctx.r7.u64 + r31.u64;
	// srawi r24,r3,11
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FF) != 0);
	r24.s64 = ctx.r3.s32 >> 11;
	// subf r3,r7,r31
	ctx.r3.u64 = r31.u64 - ctx.r7.u64;
	// subf r28,r7,r22
	r28.u64 = r22.u64 - ctx.r7.u64;
	// subf r7,r6,r26
	ctx.r7.u64 = r26.u64 - ctx.r6.u64;
	// add r26,r6,r27
	r26.u64 = ctx.r6.u64 + r27.u64;
	// add r31,r28,r30
	r31.u64 = r28.u64 + r30.u64;
	// addi r26,r26,127
	r26.s64 = r26.s64 + 127;
	// subf r30,r28,r30
	r30.u64 = r30.u64 - r28.u64;
	// subf r28,r6,r27
	r28.u64 = r27.u64 - ctx.r6.u64;
	// srawi r25,r25,11
	xer.ca = (r25.s32 < 0) & ((r25.u32 & 0x7FF) != 0);
	r25.s64 = r25.s32 >> 11;
	// srawi r6,r26,8
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0xFF) != 0);
	ctx.r6.s64 = r26.s32 >> 8;
	// addi r28,r28,127
	r28.s64 = r28.s64 + 127;
	// add r27,r6,r23
	r27.u64 = ctx.r6.u64 + r23.u64;
	// srawi r6,r28,8
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0xFF) != 0);
	ctx.r6.s64 = r28.s32 >> 8;
	// add r7,r7,r29
	ctx.r7.u64 = ctx.r7.u64 + r29.u64;
	// subf r29,r29,r25
	r29.u64 = r25.u64 - r29.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// stb r27,-1(r9)
	REX_STORE_U8(ctx.r9.u32 + -1, r27.u8);
	// add r27,r7,r31
	r27.u64 = ctx.r7.u64 + r31.u64;
	// lbz r28,6(r10)
	r28.u64 = REX_LOAD_U8(ctx.r10.u32 + 6);
	// add r6,r6,r28
	ctx.r6.u64 = ctx.r6.u64 + r28.u64;
	// stb r6,6(r9)
	REX_STORE_U8(ctx.r9.u32 + 6, ctx.r6.u8);
	// subf r6,r7,r24
	ctx.r6.u64 = r24.u64 - ctx.r7.u64;
	// subf r7,r7,r31
	ctx.r7.u64 = r31.u64 - ctx.r7.u64;
	// lbz r28,0(r10)
	r28.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r31,r27,127
	r31.s64 = r27.s64 + 127;
	// addi r7,r7,127
	ctx.r7.s64 = ctx.r7.s64 + 127;
	// srawi r31,r31,8
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0xFF) != 0);
	r31.s64 = r31.s32 >> 8;
	// srawi r7,r7,8
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 8;
	// add r31,r31,r28
	r31.u64 = r31.u64 + r28.u64;
	// stb r31,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, r31.u8);
	// lbz r31,5(r10)
	r31.u64 = REX_LOAD_U8(ctx.r10.u32 + 5);
	// add r7,r7,r31
	ctx.r7.u64 = ctx.r7.u64 + r31.u64;
	// stb r7,5(r9)
	REX_STORE_U8(ctx.r9.u32 + 5, ctx.r7.u8);
	// add r7,r6,r30
	ctx.r7.u64 = ctx.r6.u64 + r30.u64;
	// subf r30,r6,r30
	r30.u64 = r30.u64 - ctx.r6.u64;
	// lbz r31,1(r10)
	r31.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// addi r28,r7,127
	r28.s64 = ctx.r7.s64 + 127;
	// add r7,r29,r6
	ctx.r7.u64 = r29.u64 + ctx.r6.u64;
	// srawi r6,r28,8
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0xFF) != 0);
	ctx.r6.s64 = r28.s32 >> 8;
	// addi r30,r30,127
	r30.s64 = r30.s64 + 127;
	// add r6,r6,r31
	ctx.r6.u64 = ctx.r6.u64 + r31.u64;
	// srawi r31,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r31.s64 = r30.s32 >> 8;
	// stb r6,1(r9)
	REX_STORE_U8(ctx.r9.u32 + 1, ctx.r6.u8);
	// lbz r6,4(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 4);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// subf r6,r7,r3
	ctx.r6.u64 = ctx.r3.u64 - ctx.r7.u64;
	// add r31,r31,r30
	r31.u64 = r31.u64 + r30.u64;
	// addi r6,r6,127
	ctx.r6.s64 = ctx.r6.s64 + 127;
	// add r7,r7,r3
	ctx.r7.u64 = ctx.r7.u64 + ctx.r3.u64;
	// srawi r6,r6,8
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 8;
	// stb r31,4(r9)
	REX_STORE_U8(ctx.r9.u32 + 4, r31.u8);
	// addi r7,r7,127
	ctx.r7.s64 = ctx.r7.s64 + 127;
	// lbz r3,2(r10)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// srawi r7,r7,8
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 8;
	// add r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 + ctx.r3.u64;
	// stb r6,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, ctx.r6.u8);
	// lbz r6,3(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stb r7,3(r9)
	REX_STORE_U8(ctx.r9.u32 + 3, ctx.r7.u8);
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// bne cr6,0x82a84e70
	if (!cr6.eq) goto loc_82A84E70;
	// b 0x829ff7f0
	return;
}

DEFINE_REX_FUNC(sub_82A84FF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r18{};
	PPCRegister r19{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7a0
	ctx.lr = 0x82A84FF8;
	// vspltisw v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r9,r1,-384
	ctx.r9.s64 = ctx.r1.s64 + -384;
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r5,4(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(ctx.r11.u32, 4, xer);
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,-368
	ctx.r9.s64 = ctx.r1.s64 + -368;
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,-352
	ctx.r9.s64 = ctx.r1.s64 + -352;
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,-336
	ctx.r9.s64 = ctx.r1.s64 + -336;
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,-320
	ctx.r9.s64 = ctx.r1.s64 + -320;
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,-304
	ctx.r9.s64 = ctx.r1.s64 + -304;
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,-288
	ctx.r9.s64 = ctx.r1.s64 + -288;
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,-272
	ctx.r9.s64 = ctx.r1.s64 + -272;
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bge cr6,0x82a8507c
	if (!cr6.lt) goto loc_82A8507C;
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// subfic r8,r11,4
	xer.ca = ctx.r11.u32 <= 4;
	ctx.r8.u64 = static_cast<uint64_t>(4) - ctx.r11.u64;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// slw r7,r9,r11
	ctx.r7.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r11.u8 & 0x3F));
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// clrlwi r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
	// clrlwi r25,r10,28
	r25.u64 = ctx.r10.u32 & 0xF;
	// srw r10,r9,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// b 0x82a8508c
	goto loc_82A8508C;
loc_82A8507C:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// clrlwi r25,r9,28
	r25.u64 = ctx.r9.u32 & 0xF;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
loc_82A8508C:
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r9,r25,-1
	ctx.r9.s64 = r25.s64 + -1;
	// li r22,1
	r22.s64 = 1;
	// addi r24,r1,-188
	r24.s64 = ctx.r1.s64 + -188;
	// addi r23,r1,-182
	r23.s64 = ctx.r1.s64 + -182;
	// stb r8,-188(r1)
	REX_STORE_U8(ctx.r1.u32 + -188, ctx.r8.u8);
	// li r8,96
	ctx.r8.s64 = 96;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// cmplwi cr6,r25,1
	cr6.compare<uint32_t>(r25.u32, 1, xer);
	// li r21,0
	r21.s64 = 0;
	// stb r8,-187(r1)
	REX_STORE_U8(ctx.r1.u32 + -187, ctx.r8.u8);
	// li r8,176
	ctx.r8.s64 = 176;
	// stb r8,-186(r1)
	REX_STORE_U8(ctx.r1.u32 + -186, ctx.r8.u8);
	// li r8,7
	ctx.r8.s64 = 7;
	// slw r27,r22,r9
	r27.u64 = ctx.r9.u8 & 0x20 ? 0 : (r22.u32 << (ctx.r9.u8 & 0x3F));
	// stb r8,-185(r1)
	REX_STORE_U8(ctx.r1.u32 + -185, ctx.r8.u8);
	// li r8,11
	ctx.r8.s64 = 11;
	// stb r8,-184(r1)
	REX_STORE_U8(ctx.r1.u32 + -184, ctx.r8.u8);
	// li r8,15
	ctx.r8.s64 = 15;
	// stb r8,-183(r1)
	REX_STORE_U8(ctx.r1.u32 + -183, ctx.r8.u8);
	// ble cr6,0x82a85530
	if (!cr6.gt) goto loc_82A85530;
	// li r26,-1
	r26.s64 = -1;
loc_82A850E4:
	// addi r31,r7,1
	r31.s64 = ctx.r7.s64 + 1;
	// mr r30,r24
	r30.u64 = r24.u64;
	// addi r9,r31,-2
	ctx.r9.s64 = r31.s64 + -2;
	// cmplw cr6,r24,r23
	cr6.compare<uint32_t>(r24.u32, r23.u32, xer);
	// slw r29,r22,r9
	r29.u64 = ctx.r9.u8 & 0x20 ? 0 : (r22.u32 << (ctx.r9.u8 & 0x3F));
	// addi r28,r29,-1
	r28.s64 = r29.s64 + -1;
	// bge cr6,0x82a85520
	if (!cr6.lt) goto loc_82A85520;
loc_82A85100:
	// lbz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82a85514
	if (cr6.eq) goto loc_82A85514;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85128
	if (!cr6.eq) goto loc_82A85128;
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// rlwinm r10,r9,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85134
	goto loc_82A85134;
loc_82A85128:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85134:
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82a85514
	if (cr6.eq) goto loc_82A85514;
	// clrlwi r9,r8,30
	ctx.r9.u64 = ctx.r8.u32 & 0x3;
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// bgt cr6,0x82a85514
	if (cr6.gt) goto loc_82A85514;
	// lis r12,-32088
	ctx.r12.s64 = -2102919168;
	// addi r12,r12,20836
	ctx.r12.s64 = ctx.r12.s64 + 20836;
	// rlwinm r0,r9,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r9.u32) {
	case 0:
		goto loc_82A85174;
	case 1:
		goto loc_82A85188;
	case 2:
		goto loc_82A851C0;
	case 3:
		goto loc_82A8549C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82A85174:
	// rlwinm r6,r8,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,17
	ctx.r9.s64 = ctx.r9.s64 + 17;
	// stb r9,0(r30)
	REX_STORE_U8(r30.u32 + 0, ctx.r9.u8);
	// b 0x82a851cc
	goto loc_82A851CC;
loc_82A85188:
	// rlwinm r9,r8,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r8,r9,2
	ctx.r8.s64 = ctx.r9.s64 + 2;
	// addi r6,r9,18
	ctx.r6.s64 = ctx.r9.s64 + 18;
	// addi r20,r9,34
	r20.s64 = ctx.r9.s64 + 34;
	// addi r9,r9,50
	ctx.r9.s64 = ctx.r9.s64 + 50;
	// stb r8,0(r30)
	REX_STORE_U8(r30.u32 + 0, ctx.r8.u8);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// addi r9,r23,1
	ctx.r9.s64 = r23.s64 + 1;
	// stb r6,0(r23)
	REX_STORE_U8(r23.u32 + 0, ctx.r6.u8);
	// stb r20,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, r20.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r23,r9,1
	r23.s64 = ctx.r9.s64 + 1;
	// stb r8,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// b 0x82a85518
	goto loc_82A85518;
loc_82A851C0:
	// stb r21,0(r30)
	REX_STORE_U8(r30.u32 + 0, r21.u8);
	// rlwinm r6,r8,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82A851CC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85328
	if (!cr6.eq) goto loc_82A85328;
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a8530c
	if (!cr6.eq) goto loc_82A8530C;
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// subfic r11,r7,31
	xer.ca = ctx.r7.u32 <= 31;
	ctx.r11.u64 = static_cast<uint64_t>(31) - ctx.r7.u64;
loc_82A851F0:
	// srw r10,r10,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (r31.u8 & 0x3F));
loc_82A851F4:
	// and r20,r9,r29
	r20.u64 = ctx.r9.u64 & r29.u64;
	// and r8,r9,r28
	ctx.r8.u64 = ctx.r9.u64 & r28.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// or r9,r8,r27
	ctx.r9.u64 = ctx.r8.u64 | r27.u64;
	// beq cr6,0x82a8520c
	if (cr6.eq) goto loc_82A8520C;
	// neg r9,r9
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r9.u64);
loc_82A8520C:
	// rlwinm r8,r6,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r20,r1,-384
	r20.s64 = ctx.r1.s64 + -384;
	// sthx r9,r8,r20
	REX_STORE_U16(ctx.r8.u32 + r20.u32, ctx.r9.u16);
loc_82A85218:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a8538c
	if (!cr6.eq) goto loc_82A8538C;
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85370
	if (!cr6.eq) goto loc_82A85370;
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// subfic r11,r7,31
	xer.ca = ctx.r7.u32 <= 31;
	ctx.r11.u64 = static_cast<uint64_t>(31) - ctx.r7.u64;
loc_82A85240:
	// srw r10,r10,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (r31.u8 & 0x3F));
loc_82A85244:
	// and r20,r9,r29
	r20.u64 = ctx.r9.u64 & r29.u64;
	// and r8,r9,r28
	ctx.r8.u64 = ctx.r9.u64 & r28.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// or r9,r8,r27
	ctx.r9.u64 = ctx.r8.u64 | r27.u64;
	// beq cr6,0x82a8525c
	if (cr6.eq) goto loc_82A8525C;
	// neg r9,r9
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r9.u64);
loc_82A8525C:
	// rlwinm r8,r6,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r20,r1,-384
	r20.s64 = ctx.r1.s64 + -384;
	// sthx r9,r8,r20
	REX_STORE_U16(ctx.r8.u32 + r20.u32, ctx.r9.u16);
loc_82A85268:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a853f0
	if (!cr6.eq) goto loc_82A853F0;
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a853d4
	if (!cr6.eq) goto loc_82A853D4;
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// subfic r11,r7,31
	xer.ca = ctx.r7.u32 <= 31;
	ctx.r11.u64 = static_cast<uint64_t>(31) - ctx.r7.u64;
loc_82A85290:
	// srw r10,r10,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (r31.u8 & 0x3F));
loc_82A85294:
	// and r20,r9,r29
	r20.u64 = ctx.r9.u64 & r29.u64;
	// and r8,r9,r28
	ctx.r8.u64 = ctx.r9.u64 & r28.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// or r9,r8,r27
	ctx.r9.u64 = ctx.r8.u64 | r27.u64;
	// beq cr6,0x82a852ac
	if (cr6.eq) goto loc_82A852AC;
	// neg r9,r9
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r9.u64);
loc_82A852AC:
	// rlwinm r8,r6,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r20,r1,-384
	r20.s64 = ctx.r1.s64 + -384;
	// sthx r9,r8,r20
	REX_STORE_U16(ctx.r8.u32 + r20.u32, ctx.r9.u16);
loc_82A852B8:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85454
	if (!cr6.eq) goto loc_82A85454;
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85438
	if (!cr6.eq) goto loc_82A85438;
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// subfic r11,r7,31
	xer.ca = ctx.r7.u32 <= 31;
	ctx.r11.u64 = static_cast<uint64_t>(31) - ctx.r7.u64;
loc_82A852E0:
	// srw r10,r10,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (r31.u8 & 0x3F));
loc_82A852E4:
	// and r20,r9,r29
	r20.u64 = ctx.r9.u64 & r29.u64;
	// and r8,r9,r28
	ctx.r8.u64 = ctx.r9.u64 & r28.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// or r9,r8,r27
	ctx.r9.u64 = ctx.r8.u64 | r27.u64;
	// beq cr6,0x82a852fc
	if (cr6.eq) goto loc_82A852FC;
	// neg r9,r9
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r9.u64);
loc_82A852FC:
	// rlwinm r8,r6,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r1,-384
	ctx.r6.s64 = ctx.r1.s64 + -384;
	// sthx r9,r8,r6
	REX_STORE_U16(ctx.r8.u32 + ctx.r6.u32, ctx.r9.u16);
	// b 0x82a85518
	goto loc_82A85518;
loc_82A8530C:
	// li r11,31
	ctx.r11.s64 = 31;
loc_82A85310:
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// stb r9,0(r24)
	REX_STORE_U8(r24.u32 + 0, ctx.r9.u8);
	// b 0x82a85218
	goto loc_82A85218;
loc_82A85328:
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82a85310
	if (!cr6.eq) goto loc_82A85310;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, xer);
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// bge cr6,0x82a85368
	if (!cr6.lt) goto loc_82A85368;
	// lwz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// subf r20,r11,r7
	r20.u64 = ctx.r7.u64 - ctx.r11.u64;
	// subf r10,r7,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r7.u64;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// slw r19,r8,r11
	r19.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r11.u8 & 0x3F));
	// addi r11,r10,32
	ctx.r11.s64 = ctx.r10.s64 + 32;
	// or r9,r19,r9
	ctx.r9.u64 = r19.u64 | ctx.r9.u64;
	// srw r10,r8,r20
	ctx.r10.u64 = r20.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (r20.u8 & 0x3F));
	// b 0x82a851f4
	goto loc_82A851F4;
loc_82A85368:
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// b 0x82a851f0
	goto loc_82A851F0;
loc_82A85370:
	// li r11,31
	ctx.r11.s64 = 31;
loc_82A85374:
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// stb r9,0(r24)
	REX_STORE_U8(r24.u32 + 0, ctx.r9.u8);
	// b 0x82a85268
	goto loc_82A85268;
loc_82A8538C:
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82a85374
	if (!cr6.eq) goto loc_82A85374;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, xer);
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// bge cr6,0x82a853cc
	if (!cr6.lt) goto loc_82A853CC;
	// lwz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// subf r20,r11,r7
	r20.u64 = ctx.r7.u64 - ctx.r11.u64;
	// subf r10,r7,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r7.u64;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// slw r19,r8,r11
	r19.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r11.u8 & 0x3F));
	// addi r11,r10,32
	ctx.r11.s64 = ctx.r10.s64 + 32;
	// or r9,r19,r9
	ctx.r9.u64 = r19.u64 | ctx.r9.u64;
	// srw r10,r8,r20
	ctx.r10.u64 = r20.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (r20.u8 & 0x3F));
	// b 0x82a85244
	goto loc_82A85244;
loc_82A853CC:
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// b 0x82a85240
	goto loc_82A85240;
loc_82A853D4:
	// li r11,31
	ctx.r11.s64 = 31;
loc_82A853D8:
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// stb r9,0(r24)
	REX_STORE_U8(r24.u32 + 0, ctx.r9.u8);
	// b 0x82a852b8
	goto loc_82A852B8;
loc_82A853F0:
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82a853d8
	if (!cr6.eq) goto loc_82A853D8;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, xer);
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// bge cr6,0x82a85430
	if (!cr6.lt) goto loc_82A85430;
	// lwz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// subf r20,r11,r7
	r20.u64 = ctx.r7.u64 - ctx.r11.u64;
	// subf r10,r7,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r7.u64;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// slw r19,r8,r11
	r19.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r11.u8 & 0x3F));
	// addi r11,r10,32
	ctx.r11.s64 = ctx.r10.s64 + 32;
	// or r9,r19,r9
	ctx.r9.u64 = r19.u64 | ctx.r9.u64;
	// srw r10,r8,r20
	ctx.r10.u64 = r20.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (r20.u8 & 0x3F));
	// b 0x82a85294
	goto loc_82A85294;
loc_82A85430:
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// b 0x82a85290
	goto loc_82A85290;
loc_82A85438:
	// li r11,31
	ctx.r11.s64 = 31;
loc_82A8543C:
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// stb r9,0(r24)
	REX_STORE_U8(r24.u32 + 0, ctx.r9.u8);
	// b 0x82a85518
	goto loc_82A85518;
loc_82A85454:
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82a8543c
	if (!cr6.eq) goto loc_82A8543C;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, xer);
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// bge cr6,0x82a85494
	if (!cr6.lt) goto loc_82A85494;
	// lwz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// subf r20,r11,r7
	r20.u64 = ctx.r7.u64 - ctx.r11.u64;
	// subf r10,r7,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r7.u64;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// slw r19,r8,r11
	r19.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r11.u8 & 0x3F));
	// addi r11,r10,32
	ctx.r11.s64 = ctx.r10.s64 + 32;
	// or r9,r19,r9
	ctx.r9.u64 = r19.u64 | ctx.r9.u64;
	// srw r10,r8,r20
	ctx.r10.u64 = r20.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (r20.u8 & 0x3F));
	// b 0x82a852e4
	goto loc_82A852E4;
loc_82A85494:
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// b 0x82a852e0
	goto loc_82A852E0;
loc_82A8549C:
	// rlwinm r6,r8,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, xer);
	// bge cr6,0x82a854d8
	if (!cr6.lt) goto loc_82A854D8;
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// subfic r20,r7,32
	xer.ca = ctx.r7.u32 <= 32;
	r20.u64 = static_cast<uint64_t>(32) - ctx.r7.u64;
	// subf r19,r11,r7
	r19.u64 = ctx.r7.u64 - ctx.r11.u64;
	// subf r8,r7,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r7.u64;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// slw r18,r9,r11
	r18.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r11.u8 & 0x3F));
	// srw r20,r26,r20
	r20.u64 = r20.u8 & 0x20 ? 0 : (r26.u32 >> (r20.u8 & 0x3F));
	// or r10,r18,r10
	ctx.r10.u64 = r18.u64 | ctx.r10.u64;
	// addi r11,r8,32
	ctx.r11.s64 = ctx.r8.s64 + 32;
	// and r8,r20,r10
	ctx.r8.u64 = r20.u64 & ctx.r10.u64;
	// srw r10,r9,r19
	ctx.r10.u64 = r19.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (r19.u8 & 0x3F));
	// b 0x82a854ec
	goto loc_82A854EC;
loc_82A854D8:
	// subfic r9,r7,32
	xer.ca = ctx.r7.u32 <= 32;
	ctx.r9.u64 = static_cast<uint64_t>(32) - ctx.r7.u64;
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// srw r9,r26,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r26.u32 >> (ctx.r9.u8 & 0x3F));
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// srw r10,r10,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r7.u8 & 0x3F));
loc_82A854EC:
	// and r9,r8,r28
	ctx.r9.u64 = ctx.r8.u64 & r28.u64;
	// and r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 & r29.u64;
	// or r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 | r27.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82a85504
	if (cr6.eq) goto loc_82A85504;
	// neg r9,r9
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r9.u64);
loc_82A85504:
	// rlwinm r8,r6,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// stb r21,0(r30)
	REX_STORE_U8(r30.u32 + 0, r21.u8);
	// addi r6,r1,-384
	ctx.r6.s64 = ctx.r1.s64 + -384;
	// sthx r9,r8,r6
	REX_STORE_U16(ctx.r8.u32 + ctx.r6.u32, ctx.r9.u16);
loc_82A85514:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82A85518:
	// cmplw cr6,r30,r23
	cr6.compare<uint32_t>(r30.u32, r23.u32, xer);
	// blt cr6,0x82a85100
	if (cr6.lt) goto loc_82A85100;
loc_82A85520:
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// srawi r27,r27,1
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x1) != 0);
	r27.s64 = r27.s32 >> 1;
	// cmplwi cr6,r7,1
	cr6.compare<uint32_t>(ctx.r7.u32, 1, xer);
	// bgt cr6,0x82a850e4
	if (cr6.gt) goto loc_82A850E4;
loc_82A85530:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82a85894
	if (cr6.eq) goto loc_82A85894;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// cmplw cr6,r24,r23
	cr6.compare<uint32_t>(r24.u32, r23.u32, xer);
	// bge cr6,0x82a85894
	if (!cr6.lt) goto loc_82A85894;
loc_82A85544:
	// lbz r8,0(r6)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82a85888
	if (cr6.eq) goto loc_82A85888;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a8556c
	if (!cr6.eq) goto loc_82A8556C;
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// rlwinm r10,r9,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85578
	goto loc_82A85578;
loc_82A8556C:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85578:
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82a85888
	if (cr6.eq) goto loc_82A85888;
	// clrlwi r9,r8,30
	ctx.r9.u64 = ctx.r8.u32 & 0x3;
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// bgt cr6,0x82a85888
	if (cr6.gt) goto loc_82A85888;
	// lis r12,-32088
	ctx.r12.s64 = -2102919168;
	// addi r12,r12,21928
	ctx.r12.s64 = ctx.r12.s64 + 21928;
	// rlwinm r0,r9,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r9.u32) {
	case 0:
		goto loc_82A855B8;
	case 1:
		goto loc_82A855CC;
	case 2:
		goto loc_82A85604;
	case 3:
		goto loc_82A85840;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82A855B8:
	// rlwinm r7,r8,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,17
	ctx.r9.s64 = ctx.r9.s64 + 17;
	// stb r9,0(r6)
	REX_STORE_U8(ctx.r6.u32 + 0, ctx.r9.u8);
	// b 0x82a85610
	goto loc_82A85610;
loc_82A855CC:
	// rlwinm r9,r8,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r8,r9,2
	ctx.r8.s64 = ctx.r9.s64 + 2;
	// addi r7,r9,18
	ctx.r7.s64 = ctx.r9.s64 + 18;
	// addi r31,r9,34
	r31.s64 = ctx.r9.s64 + 34;
	// addi r9,r9,50
	ctx.r9.s64 = ctx.r9.s64 + 50;
	// stb r8,0(r6)
	REX_STORE_U8(ctx.r6.u32 + 0, ctx.r8.u8);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// addi r9,r23,1
	ctx.r9.s64 = r23.s64 + 1;
	// stb r7,0(r23)
	REX_STORE_U8(r23.u32 + 0, ctx.r7.u8);
	// stb r31,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, r31.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r23,r9,1
	r23.s64 = ctx.r9.s64 + 1;
	// stb r8,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// b 0x82a8588c
	goto loc_82A8588C;
loc_82A85604:
	// stb r21,0(r6)
	REX_STORE_U8(ctx.r6.u32 + 0, r21.u8);
	// rlwinm r7,r8,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_82A85610:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a8562c
	if (!cr6.eq) goto loc_82A8562C;
	// lwz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r9,31
	ctx.r9.s64 = 31;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// rlwinm r10,r8,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85638
	goto loc_82A85638;
loc_82A8562C:
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
loc_82A85638:
	// clrlwi r11,r8,31
	ctx.r11.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// beq cr6,0x82a85658
	if (cr6.eq) goto loc_82A85658;
	// rlwinm r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// stb r11,0(r24)
	REX_STORE_U8(r24.u32 + 0, ctx.r11.u8);
	// b 0x82a85698
	goto loc_82A85698;
loc_82A85658:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82a85674
	if (!cr6.eq) goto loc_82A85674;
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r9,31
	ctx.r9.s64 = 31;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85680
	goto loc_82A85680;
loc_82A85674:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
loc_82A85680:
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r11,r11
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// addi r31,r1,-384
	r31.s64 = ctx.r1.s64 + -384;
	// rlwimi r11,r22,0,31,15
	ctx.r11.u64 = (__builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0xFFFFFFFFFFFF0001) | (ctx.r11.u64 & 0xFFFE);
	// sthx r11,r8,r31
	REX_STORE_U16(ctx.r8.u32 + r31.u32, ctx.r11.u16);
loc_82A85698:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82a856b8
	if (!cr6.eq) goto loc_82A856B8;
	// lwz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r10,31
	ctx.r10.s64 = 31;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// rlwinm r11,r8,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a856c4
	goto loc_82A856C4;
loc_82A856B8:
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// rlwinm r11,r10,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
loc_82A856C4:
	// clrlwi r9,r8,31
	ctx.r9.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82a856e4
	if (cr6.eq) goto loc_82A856E4;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// stb r9,0(r24)
	REX_STORE_U8(r24.u32 + 0, ctx.r9.u8);
	// b 0x82a85724
	goto loc_82A85724;
loc_82A856E4:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82a85700
	if (!cr6.eq) goto loc_82A85700;
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r10,31
	ctx.r10.s64 = 31;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a8570c
	goto loc_82A8570C;
loc_82A85700:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_82A8570C:
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r9,r9
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r9.u64);
	// addi r31,r1,-384
	r31.s64 = ctx.r1.s64 + -384;
	// rlwimi r9,r22,0,31,15
	ctx.r9.u64 = (__builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0xFFFFFFFFFFFF0001) | (ctx.r9.u64 & 0xFFFE);
	// sthx r9,r8,r31
	REX_STORE_U16(ctx.r8.u32 + r31.u32, ctx.r9.u16);
loc_82A85724:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82a85744
	if (!cr6.eq) goto loc_82A85744;
	// lwz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r9,31
	ctx.r9.s64 = 31;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// rlwinm r11,r8,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85750
	goto loc_82A85750;
loc_82A85744:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
loc_82A85750:
	// clrlwi r10,r8,31
	ctx.r10.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a85770
	if (cr6.eq) goto loc_82A85770;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// stb r10,0(r24)
	REX_STORE_U8(r24.u32 + 0, ctx.r10.u8);
	// b 0x82a857b0
	goto loc_82A857B0;
loc_82A85770:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82a8578c
	if (!cr6.eq) goto loc_82A8578C;
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r9,31
	ctx.r9.s64 = 31;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// rlwinm r11,r10,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85798
	goto loc_82A85798;
loc_82A8578C:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
loc_82A85798:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r10,r10
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// addi r31,r1,-384
	r31.s64 = ctx.r1.s64 + -384;
	// rlwimi r10,r22,0,31,15
	ctx.r10.u64 = (__builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0xFFFFFFFFFFFF0001) | (ctx.r10.u64 & 0xFFFE);
	// sthx r10,r8,r31
	REX_STORE_U16(ctx.r8.u32 + r31.u32, ctx.r10.u16);
loc_82A857B0:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82a857d0
	if (!cr6.eq) goto loc_82A857D0;
	// lwz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// rlwinm r10,r8,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a857dc
	goto loc_82A857DC;
loc_82A857D0:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r9,-1
	ctx.r11.s64 = ctx.r9.s64 + -1;
loc_82A857DC:
	// clrlwi r9,r8,31
	ctx.r9.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82a857fc
	if (cr6.eq) goto loc_82A857FC;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// stb r9,0(r24)
	REX_STORE_U8(r24.u32 + 0, ctx.r9.u8);
	// b 0x82a8588c
	goto loc_82A8588C;
loc_82A857FC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85818
	if (!cr6.eq) goto loc_82A85818;
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// rlwinm r10,r9,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85824
	goto loc_82A85824;
loc_82A85818:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85824:
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r9,r9
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r9.u64);
	// addi r7,r1,-384
	ctx.r7.s64 = ctx.r1.s64 + -384;
	// rlwimi r9,r22,0,31,15
	ctx.r9.u64 = (__builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0xFFFFFFFFFFFF0001) | (ctx.r9.u64 & 0xFFFE);
	// sthx r9,r8,r7
	REX_STORE_U16(ctx.r8.u32 + ctx.r7.u32, ctx.r9.u16);
	// b 0x82a8588c
	goto loc_82A8588C;
loc_82A85840:
	// rlwinm r8,r8,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85860
	if (!cr6.eq) goto loc_82A85860;
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// rlwinm r10,r9,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a8586c
	goto loc_82A8586C;
loc_82A85860:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A8586C:
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	// stb r21,0(r6)
	REX_STORE_U8(ctx.r6.u32 + 0, r21.u8);
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r9,r9
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r9.u64);
	// addi r7,r1,-384
	ctx.r7.s64 = ctx.r1.s64 + -384;
	// rlwimi r9,r22,0,31,15
	ctx.r9.u64 = (__builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0xFFFFFFFFFFFF0001) | (ctx.r9.u64 & 0xFFFE);
	// sthx r9,r8,r7
	REX_STORE_U16(ctx.r8.u32 + ctx.r7.u32, ctx.r9.u16);
loc_82A85888:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_82A8588C:
	// cmplw cr6,r6,r23
	cr6.compare<uint32_t>(ctx.r6.u32, r23.u32, xer);
	// blt cr6,0x82a85544
	if (cr6.lt) goto loc_82A85544;
loc_82A85894:
	// lhz r9,-382(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + -382);
	// lwz r8,-376(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -376);
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// stw r11,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// lwz r7,-368(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// sth r9,2(r3)
	REX_STORE_U16(ctx.r3.u32 + 2, ctx.r9.u16);
	// stw r8,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// lwz r6,-360(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// lwz r10,-380(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -380);
	// lwz r11,-372(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -372);
	// lwz r9,-364(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -364);
	// lwz r8,-356(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -356);
	// stw r7,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r6,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// stw r10,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r9,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// stw r8,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
	// lwz r7,-336(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -336);
	// lwz r6,-296(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -296);
	// lwz r10,-352(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -352);
	// lwz r11,-344(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// lwz r9,-332(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -332);
	// lwz r8,-292(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -292);
	// stw r7,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r7.u32);
	// stw r6,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r6.u32);
	// stw r10,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// stw r11,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// stw r9,48(r3)
	REX_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r8,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r8.u32);
	// lwz r7,-348(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -348);
	// lwz r6,-340(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -340);
	// lwz r10,-328(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -328);
	// lwz r11,-320(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -320);
	// lwz r9,-288(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -288);
	// lwz r8,-280(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -280);
	// stw r7,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r7.u32);
	// stw r6,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r6.u32);
	// stw r10,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// stw r11,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// stw r9,72(r3)
	REX_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// stw r8,76(r3)
	REX_STORE_U32(ctx.r3.u32 + 76, ctx.r8.u32);
	// lwz r7,-324(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -324);
	// lwz r6,-316(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -316);
	// lwz r10,-284(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -284);
	// lwz r11,-276(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -276);
	// lwz r9,-312(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -312);
	// lwz r8,-304(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -304);
	// stw r7,80(r3)
	REX_STORE_U32(ctx.r3.u32 + 80, ctx.r7.u32);
	// stw r6,84(r3)
	REX_STORE_U32(ctx.r3.u32 + 84, ctx.r6.u32);
	// stw r10,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r10.u32);
	// stw r11,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
	// stw r9,96(r3)
	REX_STORE_U32(ctx.r3.u32 + 96, ctx.r9.u32);
	// stw r8,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r8.u32);
	// lwz r7,-272(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -272);
	// lwz r6,-264(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -264);
	// lwz r10,-308(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -308);
	// lwz r11,-300(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -300);
	// lwz r9,-268(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -268);
	// lwz r8,-260(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -260);
	// stw r5,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r5.u32);
	// stw r7,104(r3)
	REX_STORE_U32(ctx.r3.u32 + 104, ctx.r7.u32);
	// stw r6,108(r3)
	REX_STORE_U32(ctx.r3.u32 + 108, ctx.r6.u32);
	// stw r10,112(r3)
	REX_STORE_U32(ctx.r3.u32 + 112, ctx.r10.u32);
	// stw r11,116(r3)
	REX_STORE_U32(ctx.r3.u32 + 116, ctx.r11.u32);
	// stw r9,120(r3)
	REX_STORE_U32(ctx.r3.u32 + 120, ctx.r9.u32);
	// stw r8,124(r3)
	REX_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// b 0x829ff7f0
	return;
}

DEFINE_REX_FUNC(sub_82A859A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff7b0
	ctx.lr = 0x82A859B0;
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// li r25,0
	r25.s64 = 0;
	// lwz r31,4(r4)
	r31.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r30,r25
	r30.u64 = r25.u64;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(ctx.r11.u32, 3, xer);
	// bge cr6,0x82a859f4
	if (!cr6.lt) goto loc_82A859F4;
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(r31.u32 + 0);
	// subfic r8,r11,3
	xer.ca = ctx.r11.u32 <= 3;
	ctx.r8.u64 = static_cast<uint64_t>(3) - ctx.r11.u64;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// slw r7,r9,r11
	ctx.r7.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r11.u8 & 0x3F));
	// addi r11,r11,29
	ctx.r11.s64 = ctx.r11.s64 + 29;
	// clrlwi r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
	// srw r7,r9,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// b 0x82a859fc
	goto loc_82A859FC;
loc_82A859F4:
	// rlwinm r7,r10,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
loc_82A859FC:
	// li r8,16
	ctx.r8.s64 = 16;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r28,r1,-236
	r28.s64 = ctx.r1.s64 + -236;
	// stb r8,-236(r1)
	REX_STORE_U8(ctx.r1.u32 + -236, ctx.r8.u8);
	// li r8,96
	ctx.r8.s64 = 96;
	// addi r26,r1,-232
	r26.s64 = ctx.r1.s64 + -232;
	// mr r29,r25
	r29.u64 = r25.u64;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r8,-235(r1)
	REX_STORE_U8(ctx.r1.u32 + -235, ctx.r8.u8);
	// li r8,176
	ctx.r8.s64 = 176;
	// stb r8,-234(r1)
	REX_STORE_U8(ctx.r1.u32 + -234, ctx.r8.u8);
	// li r8,2
	ctx.r8.s64 = 2;
	// stb r8,-233(r1)
	REX_STORE_U8(ctx.r1.u32 + -233, ctx.r8.u8);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// slw r27,r9,r8
	r27.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r8.u8 & 0x3F));
	// beq cr6,0x82a85eb4
	if (cr6.eq) goto loc_82A85EB4;
loc_82A85A48:
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82a85ac8
	if (!cr6.gt) goto loc_82A85AC8;
loc_82A85A54:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85a70
	if (!cr6.eq) goto loc_82A85A70;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85a7c
	goto loc_82A85A7C;
loc_82A85A70:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85A7C:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a85abc
	if (cr6.eq) goto loc_82A85ABC;
	// addi r10,r1,-160
	ctx.r10.s64 = ctx.r1.s64 + -160;
	// lbzx r8,r6,r10
	ctx.r8.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// lbzx r10,r8,r3
	ctx.r10.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r3.u32);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// neg r10,r27
	ctx.r10.s64 = static_cast<int64_t>(-r27.u64);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x82a85aa8
	if (cr6.lt) goto loc_82A85AA8;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82A85AA8:
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplw cr6,r30,r5
	cr6.compare<uint32_t>(r30.u32, ctx.r5.u32, xer);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stbx r10,r8,r3
	REX_STORE_U8(ctx.r8.u32 + ctx.r3.u32, ctx.r10.u8);
	// beq cr6,0x82a85eb4
	if (cr6.eq) goto loc_82A85EB4;
loc_82A85ABC:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r6,r29
	cr6.compare<int32_t>(ctx.r6.s32, r29.s32, xer);
	// blt cr6,0x82a85a54
	if (cr6.lt) goto loc_82A85A54;
loc_82A85AC8:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// cmplw cr6,r28,r26
	cr6.compare<uint32_t>(r28.u32, r26.u32, xer);
	// bge cr6,0x82a85ea4
	if (!cr6.lt) goto loc_82A85EA4;
	// addi r10,r1,-160
	ctx.r10.s64 = ctx.r1.s64 + -160;
	// add r8,r29,r10
	ctx.r8.u64 = r29.u64 + ctx.r10.u64;
loc_82A85ADC:
	// lbz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a85e98
	if (cr6.eq) goto loc_82A85E98;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85b04
	if (!cr6.eq) goto loc_82A85B04;
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(r31.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// rlwinm r7,r9,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85b10
	goto loc_82A85B10;
loc_82A85B04:
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85B10:
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82a85e98
	if (cr6.eq) goto loc_82A85E98;
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// bgt cr6,0x82a85e98
	if (cr6.gt) goto loc_82A85E98;
	// lis r12,-32088
	ctx.r12.s64 = -2102919168;
	// addi r12,r12,23360
	ctx.r12.s64 = ctx.r12.s64 + 23360;
	// rlwinm r0,r9,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r9.u32) {
	case 0:
		goto loc_82A85B50;
	case 1:
		goto loc_82A85B64;
	case 2:
		goto loc_82A85B9C;
	case 3:
		goto loc_82A85E38;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82A85B50:
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,17
	ctx.r10.s64 = ctx.r10.s64 + 17;
	// stb r10,0(r6)
	REX_STORE_U8(ctx.r6.u32 + 0, ctx.r10.u8);
	// b 0x82a85ba8
	goto loc_82A85BA8;
loc_82A85B64:
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// addi r23,r10,18
	r23.s64 = ctx.r10.s64 + 18;
	// addi r22,r10,34
	r22.s64 = ctx.r10.s64 + 34;
	// addi r10,r10,50
	ctx.r10.s64 = ctx.r10.s64 + 50;
	// stb r9,0(r6)
	REX_STORE_U8(ctx.r6.u32 + 0, ctx.r9.u8);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r10,r26,1
	ctx.r10.s64 = r26.s64 + 1;
	// stb r23,0(r26)
	REX_STORE_U8(r26.u32 + 0, r23.u8);
	// stb r22,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, r22.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r26,r10,1
	r26.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// b 0x82a85e9c
	goto loc_82A85E9C;
loc_82A85B9C:
	// stb r25,0(r6)
	REX_STORE_U8(ctx.r6.u32 + 0, r25.u8);
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_82A85BA8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85bc4
	if (!cr6.eq) goto loc_82A85BC4;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85bd0
	goto loc_82A85BD0;
loc_82A85BC4:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85BD0:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a85bf0
	if (cr6.eq) goto loc_82A85BF0;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// stb r10,0(r28)
	REX_STORE_U8(r28.u32 + 0, ctx.r10.u8);
	// b 0x82a85c48
	goto loc_82A85C48;
loc_82A85BF0:
	// stb r9,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r9.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bne cr6,0x82a85c18
	if (!cr6.eq) goto loc_82A85C18;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85c24
	goto loc_82A85C24;
loc_82A85C18:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85C24:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// neg r10,r27
	ctx.r10.s64 = static_cast<int64_t>(-r27.u64);
	// bne cr6,0x82a85c38
	if (!cr6.eq) goto loc_82A85C38;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82A85C38:
	// cmplw cr6,r30,r5
	cr6.compare<uint32_t>(r30.u32, ctx.r5.u32, xer);
	// stbx r10,r9,r3
	REX_STORE_U8(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// beq cr6,0x82a85eb4
	if (cr6.eq) goto loc_82A85EB4;
loc_82A85C48:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85c68
	if (!cr6.eq) goto loc_82A85C68;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85c74
	goto loc_82A85C74;
loc_82A85C68:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85C74:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a85c94
	if (cr6.eq) goto loc_82A85C94;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// stb r10,0(r28)
	REX_STORE_U8(r28.u32 + 0, ctx.r10.u8);
	// b 0x82a85cec
	goto loc_82A85CEC;
loc_82A85C94:
	// stb r9,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r9.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bne cr6,0x82a85cbc
	if (!cr6.eq) goto loc_82A85CBC;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85cc8
	goto loc_82A85CC8;
loc_82A85CBC:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85CC8:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// neg r10,r27
	ctx.r10.s64 = static_cast<int64_t>(-r27.u64);
	// bne cr6,0x82a85cdc
	if (!cr6.eq) goto loc_82A85CDC;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82A85CDC:
	// cmplw cr6,r30,r5
	cr6.compare<uint32_t>(r30.u32, ctx.r5.u32, xer);
	// stbx r10,r9,r3
	REX_STORE_U8(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// beq cr6,0x82a85eb4
	if (cr6.eq) goto loc_82A85EB4;
loc_82A85CEC:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85d0c
	if (!cr6.eq) goto loc_82A85D0C;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85d18
	goto loc_82A85D18;
loc_82A85D0C:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85D18:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a85d38
	if (cr6.eq) goto loc_82A85D38;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// stb r10,0(r28)
	REX_STORE_U8(r28.u32 + 0, ctx.r10.u8);
	// b 0x82a85d90
	goto loc_82A85D90;
loc_82A85D38:
	// stb r9,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r9.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bne cr6,0x82a85d60
	if (!cr6.eq) goto loc_82A85D60;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85d6c
	goto loc_82A85D6C;
loc_82A85D60:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85D6C:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// neg r10,r27
	ctx.r10.s64 = static_cast<int64_t>(-r27.u64);
	// bne cr6,0x82a85d80
	if (!cr6.eq) goto loc_82A85D80;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82A85D80:
	// cmplw cr6,r30,r5
	cr6.compare<uint32_t>(r30.u32, ctx.r5.u32, xer);
	// stbx r10,r9,r3
	REX_STORE_U8(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// beq cr6,0x82a85eb4
	if (cr6.eq) goto loc_82A85EB4;
loc_82A85D90:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// bne cr6,0x82a85db0
	if (!cr6.eq) goto loc_82A85DB0;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85dbc
	goto loc_82A85DBC;
loc_82A85DB0:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85DBC:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82a85ddc
	if (cr6.eq) goto loc_82A85DDC;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// stb r10,0(r28)
	REX_STORE_U8(r28.u32 + 0, ctx.r10.u8);
	// b 0x82a85e9c
	goto loc_82A85E9C;
loc_82A85DDC:
	// stb r9,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r9.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bne cr6,0x82a85e04
	if (!cr6.eq) goto loc_82A85E04;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85e10
	goto loc_82A85E10;
loc_82A85E04:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85E10:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// neg r10,r27
	ctx.r10.s64 = static_cast<int64_t>(-r27.u64);
	// bne cr6,0x82a85e24
	if (!cr6.eq) goto loc_82A85E24;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82A85E24:
	// cmplw cr6,r30,r5
	cr6.compare<uint32_t>(r30.u32, ctx.r5.u32, xer);
	// stbx r10,r9,r3
	REX_STORE_U8(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// beq cr6,0x82a85eb4
	if (cr6.eq) goto loc_82A85EB4;
	// b 0x82a85e9c
	goto loc_82A85E9C;
loc_82A85E38:
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(ctx.r11.u32, 0, xer);
	// stb r9,0(r8)
	REX_STORE_U8(ctx.r8.u32 + 0, ctx.r9.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bne cr6,0x82a85e64
	if (!cr6.eq) goto loc_82A85E64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(r31.u32 + 0);
	// li r11,31
	ctx.r11.s64 = 31;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// b 0x82a85e70
	goto loc_82A85E70;
loc_82A85E64:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82A85E70:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// neg r10,r27
	ctx.r10.s64 = static_cast<int64_t>(-r27.u64);
	// bne cr6,0x82a85e84
	if (!cr6.eq) goto loc_82A85E84;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82A85E84:
	// cmplw cr6,r30,r5
	cr6.compare<uint32_t>(r30.u32, ctx.r5.u32, xer);
	// stbx r10,r9,r3
	REX_STORE_U8(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// beq cr6,0x82a85eb4
	if (cr6.eq) goto loc_82A85EB4;
	// stb r25,0(r6)
	REX_STORE_U8(ctx.r6.u32 + 0, r25.u8);
loc_82A85E98:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_82A85E9C:
	// cmplw cr6,r6,r26
	cr6.compare<uint32_t>(ctx.r6.u32, r26.u32, xer);
	// blt cr6,0x82a85adc
	if (cr6.lt) goto loc_82A85ADC;
loc_82A85EA4:
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// srawi r27,r27,1
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x1) != 0);
	r27.s64 = r27.s32 >> 1;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x82a85a48
	if (!cr6.eq) goto loc_82A85A48;
loc_82A85EB4:
	// stw r31,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, r31.u32);
	// stw r7,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r7.u32);
	// stw r11,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// b 0x829ff800
	return;
}

DEFINE_REX_FUNC(sub_82A85EC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister r17{};
	PPCRegister r18{};
	PPCRegister r19{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x829ff79c
	ctx.lr = 0x82A85ED0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82a859a8
	ctx.lr = 0x82A85F18;
	sub_82A859A8(ctx, base);
	// lbz r4,6(r30)
	ctx.r4.u64 = REX_LOAD_U8(r30.u32 + 6);
	// add r11,r30,r28
	ctx.r11.u64 = r30.u64 + r28.u64;
	// lbz r3,92(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + 92);
	// add r10,r31,r29
	ctx.r10.u64 = r31.u64 + r29.u64;
	// lbz r8,5(r30)
	ctx.r8.u64 = REX_LOAD_U8(r30.u32 + 5);
	// lbz r18,0(r30)
	r18.u64 = REX_LOAD_U8(r30.u32 + 0);
	// add r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 + ctx.r3.u64;
	// lbz r20,1(r30)
	r20.u64 = REX_LOAD_U8(r30.u32 + 1);
	// lbz r22,2(r30)
	r22.u64 = REX_LOAD_U8(r30.u32 + 2);
	// lbz r24,3(r30)
	r24.u64 = REX_LOAD_U8(r30.u32 + 3);
	// lbz r26,4(r30)
	r26.u64 = REX_LOAD_U8(r30.u32 + 4);
	// lbz r9,7(r30)
	ctx.r9.u64 = REX_LOAD_U8(r30.u32 + 7);
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// lbz r7,93(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 93);
	// lbz r27,89(r1)
	r27.u64 = REX_LOAD_U8(ctx.r1.u32 + 89);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// stb r4,6(r31)
	REX_STORE_U8(r31.u32 + 6, ctx.r4.u8);
	// add r30,r30,r27
	r30.u64 = r30.u64 + r27.u64;
	// lbz r17,80(r1)
	r17.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r19,81(r1)
	r19.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r21,84(r1)
	r21.u64 = REX_LOAD_U8(ctx.r1.u32 + 84);
	// add r18,r18,r17
	r18.u64 = r18.u64 + r17.u64;
	// lbz r23,85(r1)
	r23.u64 = REX_LOAD_U8(ctx.r1.u32 + 85);
	// add r20,r20,r19
	r20.u64 = r20.u64 + r19.u64;
	// lbz r25,88(r1)
	r25.u64 = REX_LOAD_U8(ctx.r1.u32 + 88);
	// add r22,r22,r21
	r22.u64 = r22.u64 + r21.u64;
	// lbz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r24,r24,r23
	r24.u64 = r24.u64 + r23.u64;
	// lbz r3,2(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// add r26,r26,r25
	r26.u64 = r26.u64 + r25.u64;
	// lbz r6,83(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r8,86(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 86);
	// lbz r7,1(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r5,82(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// stb r9,7(r31)
	REX_STORE_U8(r31.u32 + 7, ctx.r9.u8);
	// add r9,r3,r8
	ctx.r9.u64 = ctx.r3.u64 + ctx.r8.u64;
	// stb r30,5(r31)
	REX_STORE_U8(r31.u32 + 5, r30.u8);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// lbz r30,3(r11)
	r30.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r27,87(r1)
	r27.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// stb r18,0(r31)
	REX_STORE_U8(r31.u32 + 0, r18.u8);
	// add r30,r30,r27
	r30.u64 = r30.u64 + r27.u64;
	// stb r20,1(r31)
	REX_STORE_U8(r31.u32 + 1, r20.u8);
	// stb r22,2(r31)
	REX_STORE_U8(r31.u32 + 2, r22.u8);
	// stb r24,3(r31)
	REX_STORE_U8(r31.u32 + 3, r24.u8);
	// stb r26,4(r31)
	REX_STORE_U8(r31.u32 + 4, r26.u8);
	// stb r5,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r5.u8);
	// stb r7,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r7.u8);
	// stb r9,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r9.u8);
	// lbz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r5,5(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r7,6(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// lbz r9,7(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + r28.u64;
	// lbz r31,90(r1)
	r31.u64 = REX_LOAD_U8(ctx.r1.u32 + 90);
	// lbz r4,91(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 91);
	// lbz r6,94(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 94);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
	// lbz r8,95(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 95);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stb r30,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, r30.u8);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stb r7,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, ctx.r7.u8);
	// stb r9,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r9.u8);
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r31,96(r1)
	r31.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// lbz r9,6(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// lbz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 100);
	// stb r3,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r3.u8);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// stb r5,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, ctx.r5.u8);
	// add r7,r9,r6
	ctx.r7.u64 = ctx.r9.u64 + ctx.r6.u64;
	// lbz r19,7(r11)
	r19.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// lbz r8,101(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 101);
	// lbz r20,0(r11)
	r20.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r24,1(r11)
	r24.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// add r9,r19,r8
	ctx.r9.u64 = r19.u64 + ctx.r8.u64;
	// lbz r30,3(r11)
	r30.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r5,5(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r23,105(r1)
	r23.u64 = REX_LOAD_U8(ctx.r1.u32 + 105);
	// lbz r27,125(r1)
	r27.u64 = REX_LOAD_U8(ctx.r1.u32 + 125);
	// lbz r4,97(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 97);
	// add r24,r24,r23
	r24.u64 = r24.u64 + r23.u64;
	// lbz r21,104(r1)
	r21.u64 = REX_LOAD_U8(ctx.r1.u32 + 104);
	// add r30,r30,r27
	r30.u64 = r30.u64 + r27.u64;
	// lbz r26,2(r11)
	r26.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + r28.u64;
	// lbz r25,124(r1)
	r25.u64 = REX_LOAD_U8(ctx.r1.u32 + 124);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// add r21,r21,r20
	r21.u64 = r21.u64 + r20.u64;
	// stb r9,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r9.u8);
	// add r26,r26,r25
	r26.u64 = r26.u64 + r25.u64;
	// stb r3,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r3.u8);
	// stb r30,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, r30.u8);
	// stb r7,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, ctx.r7.u8);
	// stb r24,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, r24.u8);
	// stb r5,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, ctx.r5.u8);
	// stb r21,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, r21.u8);
	// lbz r9,2(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r25,126(r1)
	r25.u64 = REX_LOAD_U8(ctx.r1.u32 + 126);
	// lbz r21,0(r11)
	r21.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r24,1(r11)
	r24.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r30,3(r11)
	r30.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r5,5(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r7,6(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// lbz r20,7(r11)
	r20.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + r28.u64;
	// lbz r27,127(r1)
	r27.u64 = REX_LOAD_U8(ctx.r1.u32 + 127);
	// lbz r4,99(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 99);
	// lbz r6,102(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 102);
	// add r30,r30,r27
	r30.u64 = r30.u64 + r27.u64;
	// lbz r8,103(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 103);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// lbz r22,106(r1)
	r22.u64 = REX_LOAD_U8(ctx.r1.u32 + 106);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// lbz r23,107(r1)
	r23.u64 = REX_LOAD_U8(ctx.r1.u32 + 107);
	// lbz r31,98(r1)
	r31.u64 = REX_LOAD_U8(ctx.r1.u32 + 98);
	// add r22,r22,r21
	r22.u64 = r22.u64 + r21.u64;
	// stb r26,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, r26.u8);
	// add r26,r9,r25
	r26.u64 = ctx.r9.u64 + r25.u64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// lbz r27,108(r1)
	r27.u64 = REX_LOAD_U8(ctx.r1.u32 + 108);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
	// lbz r6,113(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 113);
	// add r9,r20,r8
	ctx.r9.u64 = r20.u64 + ctx.r8.u64;
	// lbz r4,129(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 129);
	// add r24,r24,r23
	r24.u64 = r24.u64 + r23.u64;
	// lbz r8,128(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 128);
	// stb r26,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, r26.u8);
	// stb r30,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, r30.u8);
	// stb r3,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r3.u8);
	// stb r7,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, ctx.r7.u8);
	// stb r22,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, r22.u8);
	// stb r24,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, r24.u8);
	// stb r5,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, ctx.r5.u8);
	// stb r9,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r9.u8);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// lbz r30,109(r1)
	r30.u64 = REX_LOAD_U8(ctx.r1.u32 + 109);
	// lbz r3,112(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// lbz r26,0(r11)
	r26.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,1(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r9,3(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r31,r7,r30
	r31.u64 = ctx.r7.u64 + r30.u64;
	// lbz r25,4(r11)
	r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// add r27,r27,r26
	r27.u64 = r27.u64 + r26.u64;
	// add r7,r9,r6
	ctx.r7.u64 = ctx.r9.u64 + ctx.r6.u64;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// add r9,r25,r8
	ctx.r9.u64 = r25.u64 + ctx.r8.u64;
	// lbz r24,5(r11)
	r24.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// add r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lbz r8,133(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 133);
	// lbz r6,132(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 132);
	// stb r27,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, r27.u8);
	// stb r7,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, ctx.r7.u8);
	// stb r9,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r9.u8);
	// lbz r9,7(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// stb r5,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// add r5,r24,r4
	ctx.r5.u64 = r24.u64 + ctx.r4.u64;
	// lbz r7,6(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + r28.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r27,130(r1)
	r27.u64 = REX_LOAD_U8(ctx.r1.u32 + 130);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// lbz r4,134(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 134);
	// stb r31,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, r31.u8);
	// stb r5,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, ctx.r5.u8);
	// lbz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// stb r9,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r9.u8);
	// lbz r9,6(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// add r30,r5,r27
	r30.u64 = ctx.r5.u64 + r27.u64;
	// stb r7,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, ctx.r7.u8);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// lbz r19,0(r11)
	r19.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r5,r9,r4
	ctx.r5.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lbz r22,1(r11)
	r22.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r24,2(r11)
	r24.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r26,3(r11)
	r26.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r3,5(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r18,7(r11)
	r18.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + r28.u64;
	// lbz r25,115(r1)
	r25.u64 = REX_LOAD_U8(ctx.r1.u32 + 115);
	// lbz r31,131(r1)
	r31.u64 = REX_LOAD_U8(ctx.r1.u32 + 131);
	// lbz r6,135(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 135);
	// add r26,r26,r25
	r26.u64 = r26.u64 + r25.u64;
	// lbz r20,110(r1)
	r20.u64 = REX_LOAD_U8(ctx.r1.u32 + 110);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
	// lbz r21,111(r1)
	r21.u64 = REX_LOAD_U8(ctx.r1.u32 + 111);
	// add r9,r18,r6
	ctx.r9.u64 = r18.u64 + ctx.r6.u64;
	// lbz r23,114(r1)
	r23.u64 = REX_LOAD_U8(ctx.r1.u32 + 114);
	// add r20,r20,r19
	r20.u64 = r20.u64 + r19.u64;
	// add r22,r22,r21
	r22.u64 = r22.u64 + r21.u64;
	// stb r5,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, ctx.r5.u8);
	// add r24,r24,r23
	r24.u64 = r24.u64 + r23.u64;
	// lbz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r5,1(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r8,117(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 117);
	// lbz r7,116(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 116);
	// stb r9,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r9.u8);
	// add r9,r5,r8
	ctx.r9.u64 = ctx.r5.u64 + ctx.r8.u64;
	// stb r26,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, r26.u8);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stb r30,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, r30.u8);
	// stb r3,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, ctx.r3.u8);
	// stb r20,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, r20.u8);
	// stb r22,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, r22.u8);
	// stb r24,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, r24.u8);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// lbz r26,2(r11)
	r26.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r30,3(r11)
	r30.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r5,5(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// stb r7,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// stb r9,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r9.u8);
	// lbz r7,6(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// lbz r9,7(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + r28.u64;
	// lbz r25,120(r1)
	r25.u64 = REX_LOAD_U8(ctx.r1.u32 + 120);
	// lbz r27,121(r1)
	r27.u64 = REX_LOAD_U8(ctx.r1.u32 + 121);
	// lbz r31,136(r1)
	r31.u64 = REX_LOAD_U8(ctx.r1.u32 + 136);
	// lbz r4,137(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 137);
	// lbz r6,140(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 140);
	// lbz r8,141(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 141);
	// add r28,r26,r25
	r28.u64 = r26.u64 + r25.u64;
	// lbz r23,6(r11)
	r23.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// add r30,r30,r27
	r30.u64 = r30.u64 + r27.u64;
	// lbz r25,0(r11)
	r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
	// lbz r24,7(r11)
	r24.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// lbz r26,118(r1)
	r26.u64 = REX_LOAD_U8(ctx.r1.u32 + 118);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// lbz r27,119(r1)
	r27.u64 = REX_LOAD_U8(ctx.r1.u32 + 119);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stb r28,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, r28.u8);
	// stb r30,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, r30.u8);
	// add r26,r26,r25
	r26.u64 = r26.u64 + r25.u64;
	// stb r3,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r3.u8);
	// stb r5,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, ctx.r5.u8);
	// stb r7,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, ctx.r7.u8);
	// stb r9,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r9.u8);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// lbz r8,142(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 142);
	// lbz r29,1(r11)
	r29.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r30,2(r11)
	r30.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r3,3(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r29,r29,r27
	r29.u64 = r29.u64 + r27.u64;
	// lbz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r7,5(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// add r11,r23,r8
	ctx.r11.u64 = r23.u64 + ctx.r8.u64;
	// lbz r28,122(r1)
	r28.u64 = REX_LOAD_U8(ctx.r1.u32 + 122);
	// lbz r31,123(r1)
	r31.u64 = REX_LOAD_U8(ctx.r1.u32 + 123);
	// lbz r4,138(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 138);
	// add r30,r30,r28
	r30.u64 = r30.u64 + r28.u64;
	// lbz r6,139(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 139);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
	// lbz r9,143(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 143);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// stb r11,6(r10)
	REX_STORE_U8(ctx.r10.u32 + 6, ctx.r11.u8);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// add r11,r24,r9
	ctx.r11.u64 = r24.u64 + ctx.r9.u64;
	// stb r26,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, r26.u8);
	// stb r29,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, r29.u8);
	// stb r30,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, r30.u8);
	// stb r3,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, ctx.r3.u8);
	// stb r5,4(r10)
	REX_STORE_U8(ctx.r10.u32 + 4, ctx.r5.u8);
	// stb r7,5(r10)
	REX_STORE_U8(ctx.r10.u32 + 5, ctx.r7.u8);
	// stb r11,7(r10)
	REX_STORE_U8(ctx.r10.u32 + 7, ctx.r11.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x829ff7ec
	return;
}

