#ifndef _MIPI_TX_PARAM_ZCT1429V1_H_
#define _MIPI_TX_PARAM_ZCT1429V1_H_

#include <linux/vo_mipi_tx.h>
#include <linux/cvi_comm_mipi_tx.h>

#define ZCT1429V1_VACT	1280
#define ZCT1429V1_VSA	2
#define ZCT1429V1_VBP	16
#define ZCT1429V1_VFP	10

#define ZCT1429V1_HACT	800
#define ZCT1429V1_HSA	10
#define ZCT1429V1_HBP	45
#define ZCT1429V1_HFP	45

#define ZCT1429_PIXEL_CLK(x) ((x##_VACT + x##_VSA + x##_VBP + x##_VFP) \
	* (x##_HACT + x##_HSA + x##_HBP + x##_HFP) * 60 / 1000)

struct combo_dev_cfg_s dev_cfg_zct1429v1_800x1280 = {
	.devno = 0,
	.lane_id = {MIPI_TX_LANE_0, MIPI_TX_LANE_CLK, MIPI_TX_LANE_1, -1, -1},
	.lane_pn_swap = {false, false, false, false, false},
	.output_mode = OUTPUT_MODE_DSI_VIDEO,
	.video_mode = BURST_MODE,
	.output_format = OUT_FORMAT_RGB_24_BIT,
	.sync_info = {
		.vid_hsa_pixels = ZCT1429V1_HSA,
		.vid_hbp_pixels = ZCT1429V1_HBP,
		.vid_hfp_pixels = ZCT1429V1_HFP,
		.vid_hline_pixels = ZCT1429V1_HACT,
		.vid_vsa_lines = ZCT1429V1_VSA,
		.vid_vbp_lines = ZCT1429V1_VBP,
		.vid_vfp_lines = ZCT1429V1_VFP,
		.vid_active_lines = ZCT1429V1_VACT,
		.vid_vsa_pos_polarity = true,
		.vid_hsa_pos_polarity = false,
	},
	.pixel_clk = ZCT1429_PIXEL_CLK(ZCT1429V1),
};

const struct hs_settle_s hs_timing_cfg_zct1429v1_800x1280 = { .prepare = 6, .zero = 32, .trail = 1 };

static CVI_U8 data_zct1429v1_0[] = { 0xE1, 0x93 };
static CVI_U8 data_zct1429v1_1[] = { 0xE2, 0x65 };
static CVI_U8 data_zct1429v1_2[] = { 0xE3, 0xF8 };
static CVI_U8 data_zct1429v1_3[] = { 0x80, 0x01 };
static CVI_U8 data_zct1429v1_4[] = { 0x11 };
// bist vvv
//static CVI_U8 data_zct1429v1_5[] = { 0xE0, 0x01 };
//static CVI_U8 data_zct1429v1_6[] = { 0x4A, 0x30 };
// bist ^^^
static CVI_U8 data_zct1429v1_7[] = { 0x29 };

// len == 1 , type 0x05
// len == 2 , type 0x15 or type 23
// len >= 3 , type 0x29 or type 0x39
#define TYPE1 0x05
#define TYPE2 0x15
#define TYPE3 0x29

const struct dsc_instr dsi_init_cmds_zct1429v1_800x1280[] = {
	{.delay = 0, .data_type = TYPE2, .size = 2, .data = data_zct1429v1_0 },
	{.delay = 0, .data_type = TYPE2, .size = 2, .data = data_zct1429v1_1 },
	{.delay = 0, .data_type = TYPE2, .size = 2, .data = data_zct1429v1_2 },
	{.delay = 0, .data_type = TYPE2, .size = 2, .data = data_zct1429v1_3 },
	{.delay = 120, .data_type = TYPE1, .size = 1, .data = data_zct1429v1_4 },
	// bist vvv
	// {.delay = 0, .data_type = TYPE2, .size = 2, .data = data_zct1429v1_5 },
	// {.delay = 0, .data_type = TYPE2, .size = 2, .data = data_zct1429v1_6 },
	// bist ^^^
	{.delay = 0, .data_type = TYPE1, .size = 1, .data = data_zct1429v1_7 },
};

#else
#error "MIPI_TX_PARAM multi-delcaration!!"
#endif // _MIPI_TX_PARAM_ZCT1429V1_H_
