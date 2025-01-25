//---------------------------------------------------------------------------

//#include <mem.h>
#include <string.h>

#pragma hdrstop

#include "wav2.h"
#include "signaltest.h"

//---------------------------------------------------------------------------

unsigned char h_prog_zx[19] = {
	0x00, 0x00, 0x61, 0x64, 0x6A, 0x75, 0x73, 0x74, 0x20, 0x70, 0x20, 0x20,
	0x33, 0x01, 0x01, 0x00,
	0x33, 0x01, 0x4C
};

unsigned char prog_zx[309] = {
	0xFF, 0x00, 0x01, 0x0D, 0x00, 0xFD, 0x34, 0x39, 0x36, 0x36, 0x33, 0x0E,
	0x00, 0x00, 0xFF, 0xC1,
	0x00, 0x0D, 0x00, 0x02, 0x05, 0x00, 0xEF, 0x22, 0x22, 0xAF, 0x0D, 0x00,
	0x03, 0x35, 0x00, 0xFB,
	0x3A, 0xF5, 0xAC, 0x35, 0x0E, 0x00, 0x00, 0x05, 0x00, 0x00, 0x2C, 0x31,
	0x31, 0x0E, 0x00, 0x00,
	0x0B, 0x00, 0x00, 0x3B, 0xDB, 0x31, 0x0E, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x3B, 0x22, 0x50, 0x4C,
	0x41, 0x59, 0x20, 0x54, 0x45, 0x53, 0x54, 0x20, 0x53, 0x49, 0x47, 0x4E,
	0x41, 0x4C, 0x20, 0x57,
	0x41, 0x56, 0x22, 0x0D, 0x00, 0x05, 0x0F, 0x00, 0xF1, 0x64, 0x3D, 0x34,
	0x39, 0x36, 0x36, 0x34,
	0x0E, 0x00, 0x00, 0x00, 0xC2, 0x00, 0x0D, 0x00, 0x06, 0x04, 0x00, 0xF9,
	0xC0, 0x64, 0x0D, 0x00,
	0x09, 0x02, 0x00, 0xFB, 0x0D, 0x00, 0x0A, 0x0F, 0x00, 0xF1, 0x64, 0x3D,
	0x64, 0x2B, 0x32, 0x35,
	0x36, 0x0E, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0D, 0x00, 0x0B, 0x1D, 0x00,
	0xF5, 0xBE, 0x28, 0x64,
	0x29, 0x2C, 0xBE, 0x28, 0x64, 0x2B, 0x31, 0x0E, 0x00, 0x00, 0x01, 0x00,
	0x00, 0x29, 0x2D, 0x31,
	0x32, 0x38, 0x0E, 0x00, 0x00, 0x80, 0x00, 0x00, 0x0D, 0x00, 0x0C, 0x3B,
	0x00, 0xF5, 0xBE, 0x28,
	0x64, 0x2B, 0x32, 0x0E, 0x00, 0x00, 0x02, 0x00, 0x00, 0x29, 0x2F, 0x31,
	0x36, 0x0E, 0x00, 0x00,
	0x10, 0x00, 0x00, 0x2C, 0xBE, 0x28, 0x64, 0x2B, 0x35, 0x0E, 0x00, 0x00,
	0x05, 0x00, 0x00, 0x29,
	0x2B, 0xBE, 0x28, 0x64, 0x2B, 0x34, 0x0E, 0x00, 0x00, 0x04, 0x00, 0x00,
	0x29, 0x2F, 0x32, 0x35,
	0x36, 0x0E, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0D, 0x00, 0x0D, 0x3B, 0x00,
	0xF5, 0xBE, 0x28, 0x64,
	0x2B, 0x36, 0x0E, 0x00, 0x00, 0x06, 0x00, 0x00, 0x29, 0x2F, 0x31, 0x36,
	0x0E, 0x00, 0x00, 0x10,
	0x00, 0x00, 0x2C, 0xBE, 0x28, 0x64, 0x2B, 0x39, 0x0E, 0x00, 0x00, 0x09,
	0x00, 0x00, 0x29, 0x2B,
	0xBE, 0x28, 0x64, 0x2B, 0x38, 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x29,
	0x2F, 0x32, 0x35, 0x36,
	0x0E, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0D, 0x00, 0x14, 0x09, 0x00, 0xEC,
	0x35, 0x0E, 0x00, 0x00,
	0x05, 0x00, 0x00, 0x0D, 0xD2
};

unsigned char h_code_zx[19] = {
	0x00, 0x03, 0x63, 0x6F, 0x64, 0x65, 0x20, 0x61, 0x64, 0x6A, 0x20, 0x20,
	0xC2, 0x00, 0x00, 0xC2,
	0x00, 0x00, 0x41
};

unsigned char code_zx[196] = {
	0xff,
	0xF3, 0xD9, 0xE5, 0x01, 0xFE, 0x0E, 0x1E, 0x0A, 0x53, 0xAF, 0xED, 0x41,
	0x3C, 0xED, 0x70, 0xE2,
	0x0C, 0xC2, 0xED, 0x59, 0x3C, 0xED, 0x70, 0xEA, 0x14, 0xC2, 0xFE, 0x39,
	0xCB, 0x12, 0xFE, 0x29,
	0x30, 0xE7, 0x14, 0x20, 0xE3, 0x32, 0x00, 0xC3, 0x11, 0x0A, 0xC3, 0x21,
	0xFF, 0xC6, 0x7D, 0x3C,
	0xED, 0x70, 0xEA, 0x2F, 0xC2, 0x12, 0x13, 0x7A, 0xBC, 0xCA, 0x4A, 0xC2,
	0x7D, 0x3C, 0xED, 0x70,
	0xE2, 0x3D, 0xC2, 0x12, 0x13, 0x7A, 0xBC, 0xC2, 0x2E, 0xC2, 0x21, 0x1E,
	0xC3, 0x06, 0x20, 0x3E,
	0x80, 0x86, 0x23, 0x96, 0x23, 0x10, 0xFA, 0x32, 0x01, 0xC3, 0x21, 0x1E,
	0xC3, 0xCD, 0x80, 0xC2,
	0xED, 0x53, 0x02, 0xC3, 0xCD, 0x9D, 0xC2, 0xDD, 0x22, 0x04, 0xC3, 0x21,
	0x1F, 0xC3, 0xCD, 0x80,
	0xC2, 0xED, 0x53, 0x06, 0xC3, 0xCD, 0x9D, 0xC2, 0xDD, 0x22, 0x08, 0xC3,
	0xE1, 0xD9, 0xFB, 0xC9,
	0xDD, 0x21, 0x00, 0x00, 0x11, 0x00, 0x00, 0x06, 0x20, 0x5E, 0xDD, 0x19,
	0xAF, 0xED, 0x6F, 0x23,
	0x23, 0x10, 0xF6, 0xDD, 0xE5, 0xD1, 0xCB, 0x1A, 0xCB, 0x1B, 0xD0, 0x13,
	0xC9, 0xDD, 0x21, 0x00,
	0x00, 0x4B, 0x06, 0x20, 0x2B, 0x2B, 0x7E, 0x91, 0x30, 0x02, 0xED, 0x44,
	0xD9, 0x21, 0x00, 0x00,
	0x54, 0x5F, 0xB7, 0x28, 0x04, 0x19, 0x3D, 0x20, 0xFC, 0xE5, 0xD9, 0xD1,
	0xDD, 0x19, 0x10, 0xE4,
	0xC9, 0, 0
};

	/*
	   unsigned char h_prog_zx[19] = {
	   0x00, 0x00, 0x61, 0x64, 0x6A, 0x75, 0x73, 0x74, 0x20, 0x50, 0x20, 0x20, 0x43, 0x01, 0x01, 0x00,
	   0x43, 0x01, 0x6C
	   };

	   unsigned char prog_zx[325] = {
	   0xFF, 0x00, 0x01, 0x0D, 0x00, 0xFD, 0x34, 0x39, 0x36, 0x36, 0x33, 0x0E, 0x00, 0x00, 0xFF, 0xC1,
	   0x00, 0x0D, 0x00, 0x02, 0x05, 0x00, 0xEF, 0x22, 0x22, 0xAF, 0x0D, 0x00, 0x03, 0x35, 0x00, 0xFB, 
	   0x3A, 0xF5, 0xAC, 0x31, 0x31, 0x0E, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x2C, 0x35, 0x0E, 0x00, 0x00, 
	   0x05, 0x00, 0x00, 0x3B, 0xDB, 0x31, 0x0E, 0x00, 0x00, 0x01, 0x00, 0x00, 0x3B, 0x22, 0x50, 0x4C, 
	   0x41, 0x59, 0x20, 0x54, 0x45, 0x53, 0x54, 0x20, 0x53, 0x49, 0x47, 0x4E, 0x41, 0x4C, 0x20, 0x57, 
	   0x41, 0x56, 0x22, 0x0D, 0x00, 0x05, 0x0F, 0x00, 0xF1, 0x64, 0x3D, 0x34, 0x39, 0x36, 0x36, 0x34, 
	   0x0E, 0x00, 0x00, 0x00, 0xC2, 0x00, 0x0D, 0x00, 0x06, 0x04, 0x00, 0xF9, 0xC0, 0x64, 0x0D, 0x00, 
	   0x09, 0x02, 0x00, 0xFB, 0x0D, 0x00, 0x0A, 0x0F, 0x00, 0xF1, 0x64, 0x3D, 0x64, 0x2B, 0x32, 0x35, 
	   0x36, 0x0E, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0D, 0x00, 0x0B, 0xAB, 0x00, 0xF5, 0xBE, 0x28, 0x64, 
	   0x29, 0x2C, 0xBE, 0x28, 0x64, 0x2B, 0x31, 0x0E, 0x00, 0x00, 0x01, 0x00, 0x00, 0x29, 0x2D, 0x31, 
	   0x32, 0x38, 0x0E, 0x00, 0x00, 0x80, 0x00, 0x00, 0x2C, 0xBE, 0x28, 0x64, 0x2B, 0x32, 0x0E, 0x00, 
	   0x00, 0x02, 0x00, 0x00, 0x29, 0x2F, 0x31, 0x36, 0x0E, 0x00, 0x00, 0x10, 0x00, 0x00, 0x2C, 0xBE, 
	   0x28, 0x64, 0x2B, 0x35, 0x0E, 0x00, 0x00, 0x05, 0x00, 0x00, 0x29, 0x2B, 0xBE, 0x28, 0x64, 0x2B, 
	   0x34, 0x0E, 0x00, 0x00, 0x04, 0x00, 0x00, 0x29, 0x2F, 0x32, 0x35, 0x36, 0x0E, 0x00, 0x00, 0x00, 
	   0x01, 0x00, 0x2C, 0xBE, 0x28, 0x64, 0x2B, 0x36, 0x0E, 0x00, 0x00, 0x06, 0x00, 0x00, 0x29, 0x2F, 
	   0x31, 0x36, 0x0E, 0x00, 0x00, 0x10, 0x00, 0x00, 0x2C, 0xBE, 0x28, 0x64, 0x2B, 0x39, 0x0E, 0x00, 
	   0x00, 0x09, 0x00, 0x00, 0x29, 0x2B, 0xBE, 0x28, 0x64, 0x2B, 0x38, 0x0E, 0x00, 0x00, 0x08, 0x00, 
	   0x00, 0x29, 0x2F, 0x32, 0x35, 0x36, 0x0E, 0x00, 0x00, 0x00, 0x01, 0x00, 0x2C, 0xBE, 0x28, 0x64, 
	   0x2D, 0x31, 0x0E, 0x00, 0x00, 0x01, 0x00, 0x00, 0x29, 0x2C, 0xBE, 0x28, 0x64, 0x2D, 0x32, 0x0E, 
	   0x00, 0x00, 0x02, 0x00, 0x00, 0x29, 0x0D, 0x00, 0x14, 0x09, 0x00, 0xEC, 0x35, 0x0E, 0x00, 0x00, 
	   0x05, 0x00, 0x00, 0x0D, 0x65
	   };

	   unsigned char h_code_zx[19] = {
	   0x00, 0x03, 0x61, 0x64, 0x6A, 0x75, 0x73, 0x74, 0x20, 0x43, 0x20, 0x20, 0xE6, 0x00, 0x00, 0xC2, 
	   0x00, 0x00, 0x59
	   };

	   unsigned char code_zx[232] = {
	   0xFF, 0xF3, 0xD9, 0xE5, 0x01, 0xFE, 0x0E, 0x1E, 0x0A, 0x53, 0xAF, 0xED, 0x41, 0x3C, 0xED, 0x70, 
	   0xE2, 0x0C, 0xC2, 0xED, 0x59, 0x3C, 0xED, 0x70, 0xEA, 0x14, 0xC2, 0xFE, 0x39, 0xCB, 0x12, 0xFE, 
	   0x29, 0x30, 0xE7, 0x14, 0x20, 0xE3, 0x32, 0x00, 0xC3, 0x11, 0x0A, 0xC3, 0x21, 0xFF, 0xC6, 0x7D, 
	   0x3C, 0xED, 0x70, 0xEA, 0x2F, 0xC2, 0x12, 0x13, 0x7A, 0xBC, 0xCA, 0x4A, 0xC2, 0x7D, 0x3C, 0xED, 
	   0x70, 0xE2, 0x3D, 0xC2, 0x12, 0x13, 0x7A, 0xBC, 0xC2, 0x2E, 0xC2, 0x21, 0x1E, 0xC3, 0x06, 0x20, 
	   0x3E, 0x80, 0x86, 0x23, 0x96, 0x23, 0x10, 0xFA, 0x32, 0x01, 0xC3, 0x21, 0x1E, 0xC3, 0xCD, 0x86, 
	   0xC2, 0xED, 0x53, 0x02, 0xC3, 0xCD, 0xA3, 0xC2, 0xDD, 0x22, 0x04, 0xC3, 0x21, 0x1F, 0xC3, 0xCD, 
	   0x86, 0xC2, 0xED, 0x53, 0x06, 0xC3, 0xCD, 0xA3, 0xC2, 0xDD, 0x22, 0x08, 0xC3, 0x21, 0x5E, 0xC3, 
	   0xCD, 0xC7, 0xC2, 0xE1, 0xD9, 0xFB, 0xC9, 0xDD, 0x21, 0x00, 0x00, 0x11, 0x00, 0x00, 0x06, 0x20, 
	   0x5E, 0xDD, 0x19, 0xAF, 0xED, 0x6F, 0x23, 0x23, 0x10, 0xF6, 0xDD, 0xE5, 0xD1, 0xCB, 0x1A, 0xCB, 
	   0x1B, 0xD0, 0x13, 0xC9, 0xDD, 0x21, 0x00, 0x00, 0x4B, 0x06, 0x20, 0x2B, 0x2B, 0x7E, 0x91, 0x30, 
	   0x02, 0xED, 0x44, 0xD9, 0x21, 0x00, 0x00, 0x54, 0x5F, 0xB7, 0x28, 0x04, 0x19, 0x3D, 0x20, 0xFC, 
	   0xE5, 0xD9, 0xD1, 0xDD, 0x19, 0x10, 0xE4, 0xC9, 0x16, 0x00, 0x1E, 0xFF, 0x06, 0x40, 0x2B, 0xAF, 
	   0xED, 0x67, 0x10, 0xFA, 0x06, 0x00, 0x7E, 0x23, 0xBA, 0x38, 0x01, 0x57, 0xBB, 0x30, 0x01, 0x5F, 
	   0x10, 0xF4, 0xED, 0x53, 0xFE, 0xC2, 0xC9, 0x0F
	   };        */
////////////////////////////////////////////////////////////////////////////////
int adjust_zx(char *f_out)
{
	int r;
	r = open_wav(f_out);

	block2zx_wav(h_prog_zx, sizeof(h_prog_zx));
	block2zx_wav(prog_zx, sizeof(prog_zx));

	block2zx_wav(h_code_zx, sizeof(h_code_zx));
	block2zx_wav(code_zx, sizeof(code_zx));

	close_wav();
	return r;
}

////////////////////////////////////////////////////////////////////////////////

unsigned char bas_msx[256] = {
	"1 CLEAR100,&Hc5ff:screen 1:PRINT\"otla adjust...\"\r\n"
	    "3 BLOAD \"CAS:\":PRINT\"Play test\"\r\n"
	    "4 d=&Hc600:DEF USR=d:a=USR(0)\r\n"
	    "5 d=d+256:locate 0,0:print peek(d),peek(d+1)-128"
	    ",peek(d+2)/16,peek(d+5)+peek(d+4)/256"
	    ",peek(d+6)/16,peek(d+9)+peek(d+8)/256\r\n" "8 GOTO 4\r\n"
};

unsigned char bin_msx[212] = {
	0x00, 0xC6, 0xCD, 0xC6, 0x00, 0xC6, 0xF3, 0x3E, 0x0F, 0xD3, 0xAA, 0x3E,
	0x0E, 0xD3, 0xA0, 0xD3,
	0x99, 0x01, 0xA2, 0x87, 0x11, 0x10, 0x08, 0x78, 0xD3, 0x99, 0x3C, 0xED,
	0x70, 0xFA, 0x14, 0xC6,
	0xD3, 0x99, 0x3C, 0xED, 0x70, 0xF2, 0x1C, 0xC6, 0xFE, 0xBA, 0xCB, 0x13,
	0xFE, 0xAC, 0x30, 0xE7,
	0x1C, 0x20, 0xE1, 0x90, 0x32, 0x00, 0xC7, 0x11, 0x0A, 0xC7, 0x21, 0xFF,
	0xCA, 0x7D, 0x3C, 0xED,
	0x70, 0xEA, 0x38, 0xC6, 0x12, 0x13, 0x7A, 0xBC, 0xCA, 0x53, 0xC6, 0x7D,
	0x3C, 0xED, 0x70, 0xE2,
	0x46, 0xC6, 0x12, 0x13, 0x7A, 0xBC, 0xC2, 0x37, 0xC6, 0x21, 0x1E, 0xC7,
	0x06, 0x20, 0xAF, 0x86,
	0x23, 0x96, 0x23, 0x10, 0xFA, 0xC6, 0x80, 0x32, 0x01, 0xC7, 0x21, 0x1E,
	0xC7, 0xCD, 0x8C, 0xC6,
	0xED, 0x53, 0x02, 0xC7, 0xCD, 0xA9, 0xC6, 0xDD, 0x22, 0x04, 0xC7, 0x21,
	0x1F, 0xC7, 0xCD, 0x8C,
	0xC6, 0xED, 0x53, 0x06, 0xC7, 0xCD, 0xA9, 0xC6, 0xDD, 0x22, 0x08, 0xC7,
	0x3E, 0x4F, 0xD3, 0xAA,
	0xFB, 0xC9, 0xDD, 0x21, 0x00, 0x00, 0x11, 0x00, 0x00, 0x06, 0x20, 0x5E,
	0xDD, 0x19, 0xAF, 0xED,
	0x6F, 0x23, 0x23, 0x10, 0xF6, 0xDD, 0xE5, 0xD1, 0xCB, 0x1A, 0xCB, 0x1B,
	0xD0, 0x13, 0xC9, 0xDD,
	0x21, 0x00, 0x00, 0x4B, 0x06, 0x20, 0x2B, 0x2B, 0x7E, 0x91, 0x30, 0x02,
	0xED, 0x44, 0xD9, 0x21,
	0x00, 0x00, 0x54, 0x5F, 0xB7, 0x28, 0x04, 0x19, 0x3D, 0x20, 0xFC, 0xE5,
	0xD9, 0xD1, 0xDD, 0x19,
	0x10, 0xE4, 0xC9, 0x00
};

////////////////////////////////////////////////////////////////////////////////

extern int motor;
int adjust_msx(char *f_out)
{
	int r;
	bas_msx[255] = 0x1a;	//EOT
	if (motor) {
		bin_msx[0x08] = 0x0f;
		bin_msx[0x08d] = 0x4f;
	} else {
		bin_msx[0x08] = 0x1f;
		bin_msx[0x08d] = 0x5f;
	}
	r = open_wav(f_out);
	block2msx_bin_wav("ADJUST", bas_msx, 256, 0xEA);
	pseudopause(500);
	block2msx_bin_wav("BIN..1", bin_msx, sizeof(bin_msx), 0xd0);
	close_wav();
	return r;
}

////////////////////////////////////////////////////////////////////////////////

unsigned char h_bas_cpc[259] = {
	0x2C,			//flag
	0x4F, 0x54, 0x4C, 0x41, 0x20, 0x41, 0x44, 0x4A, 0x55, 0x53, 0x54, 0x20,
	0x54, 0x4F, 0x4F, 0x4C,
	0x01,
	0xFF,
	0x00,			//type basic
	0xE7, 0x00,		//length
	0x70, 0x01,		//start address
	0xFF,			//flag first block
	0xE7, 0x00,		//logical length
	0x00, 0x00		//exec address
};

unsigned char bas_cpc[259] = {
	0x16, 0x1E, 0x00, 0x01, 0x00, 0x8A, 0x01, 0xAA, 0x20, 0x1A, 0x30, 0x75,
	0x01, 0xBF, 0x22, 0x6F,
	0x74, 0x6C, 0x61, 0x20, 0x61, 0x64, 0x6A, 0x75, 0x73, 0x74, 0x2E, 0x2E,
	0x2E, 0x22, 0x00, 0x17,
	0x00, 0x03, 0x00, 0xA8, 0x22, 0x21, 0x22, 0x01, 0xBF, 0x22, 0x70, 0x6C,
	0x61, 0x79, 0x20, 0x74,
	0x65, 0x73, 0x74, 0x22, 0x20, 0x00, 0x28, 0x00, 0x07, 0x00, 0x0D, 0x00,
	0x00, 0xE4, 0xEF, 0x1C,
	0x00, 0x80, 0x01, 0x83, 0x20, 0x0D, 0x00, 0x00, 0xE4, 0x01, 0xA9, 0x20,
	0x0F, 0x2C, 0x0F, 0x01,
	0x0D, 0x00, 0x00, 0xE4, 0xEF, 0x0D, 0x00, 0x00, 0xE4, 0xF4, 0x1A, 0x00,
	0x01, 0x00, 0x71, 0x00,
	0x08, 0x00, 0xBF, 0x20, 0xFF, 0x12, 0x28, 0x0D, 0x00, 0x00, 0xE4, 0x29,
	0x2C, 0xFF, 0x12, 0x28,
	0x0D, 0x00, 0x00, 0xE4, 0xF4, 0x0F, 0x29, 0xF5, 0x19, 0x80, 0x01, 0xBF,
	0x20, 0xFF, 0x12, 0x28,
	0x0D, 0x00, 0x00, 0xE4, 0xF4, 0x10, 0x29, 0xF7, 0x19, 0x10, 0x2C, 0xFF,
	0x12, 0x28, 0x0D, 0x00,
	0x00, 0xE4, 0xF4, 0x13, 0x29, 0xF4, 0xFF, 0x12, 0x28, 0x0D, 0x00, 0x00,
	0xE4, 0xF4, 0x12, 0x29,
	0xF7, 0x1A, 0x00, 0x01, 0x01, 0xBF, 0x20, 0xFF, 0x12, 0x28, 0x0D, 0x00,
	0x00, 0xE4, 0xF4, 0x14,
	0x29, 0xF7, 0x19, 0x10, 0x2C, 0xFF, 0x12, 0x28, 0x0D, 0x00, 0x00, 0xE4,
	0xF4, 0x17, 0x29, 0xF4,
	0xFF, 0x12, 0x28, 0x0D, 0x00, 0x00, 0xE4, 0xF4, 0x16, 0x29, 0xF7, 0x1A,
	0x00, 0x01, 0x00, 0x0A,
	0x00, 0x09, 0x00, 0xA0, 0x20, 0x1E, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x8D, 0xE4
};

unsigned char h_bin_cpc[259] = {
	0x2c,			//flag
	'o', 't', 'l', 'a', 't', 'e', 's', 't', ' ', 'c', 'o', 'd', 'e', 0x00,
	0x00, 0x00,
	1,			//block number
	0xff,			//flag last block
	2,			//type machine code
	255, 0,			//length
	0x00, 0x80,		//start address
	0xff,			//flag first block
	255, 0,			//logical length
	0x00, 0x80		//exec address
};

unsigned char bin_cpc[257] = { 0x16,
	0xF3, 0xD9, 0xC5, 0x01, 0x10, 0xF6, 0xED, 0x49, 0x01, 0x10, 0x7F, 0xED,
	0x49, 0x0E, 0x44, 0xD9,
	0x01, 0x10, 0xF5, 0xD9, 0xED, 0x41, 0xD9, 0xAF, 0x3C, 0xED, 0x70, 0xFA,
	0x18, 0x80, 0xD9, 0xED,
	0x49, 0xD9, 0x3C, 0xED, 0x70, 0xF2, 0x22, 0x80, 0xFE, 0x39, 0xCB, 0x11,
	0xFE, 0x29, 0x30, 0xE3,
	0x0C, 0x20, 0xDD, 0x32, 0x00, 0x81, 0x11, 0x0A, 0x81, 0x21, 0xFF, 0x84,
	0x7D, 0x3C, 0xED, 0x70,
	0xFA, 0x3D, 0x80, 0x12, 0x13, 0x7A, 0xBC, 0xCA, 0x58, 0x80, 0x7D, 0x3C,
	0xED, 0x70, 0xF2, 0x4B,
	0x80, 0x12, 0x13, 0x7A, 0xBC, 0xC2, 0x3C, 0x80, 0x21, 0x1E, 0x81, 0x06,
	0x20, 0xAF, 0x86, 0x23,
	0x96, 0x23, 0x10, 0xFA, 0xC6, 0x80, 0x32, 0x01, 0x81, 0x21, 0x1E, 0x81,
	0xCD, 0x8F, 0x80, 0xED,
	0x53, 0x02, 0x81, 0xCD, 0xAC, 0x80, 0xDD, 0x22, 0x04, 0x81, 0x21, 0x1F,
	0x81, 0xCD, 0x8F, 0x80,
	0xED, 0x53, 0x06, 0x81, 0xCD, 0xAC, 0x80, 0xDD, 0x22, 0x08, 0x81, 0xC1,
	0xD9, 0xFB, 0xC9, 0xDD,
	0x21, 0x00, 0x00, 0x11, 0x00, 0x00, 0x06, 0x20, 0x5E, 0xDD, 0x19, 0xAF,
	0xED, 0x6F, 0x23, 0x23,
	0x10, 0xF6, 0xDD, 0xE5, 0xD1, 0xCB, 0x1A, 0xCB, 0x1B, 0xD0, 0x13, 0xC9,
	0xDD, 0x21, 0x00, 0x00,
	0x4B, 0x06, 0x20, 0x2B, 0x2B, 0x7E, 0x91, 0x30, 0x02, 0xED, 0x44, 0xD9,
	0x21, 0x00, 0x00, 0x54,
	0x5F, 0xB7, 0x28, 0x04, 0x19, 0x3D, 0x20, 0xFC, 0xE5, 0xD9, 0xD1, 0xDD,
	0x19, 0x10, 0xE4, 0xC9
};

////////////////////////////////////////////////////////////////////////////////
int adjust_cpc(char *f_out)
{
	int r;

	int tmp = acelerar;
	acelerar = 0;
	if (motor)
		bin_cpc[5] = 0x10;
	else
		bin_cpc[5] = 0x00;

	r = open_wav(f_out);
	block2cpc_wav(h_bas_cpc);
	block2cpc_wav(bas_cpc);
	pseudopause(2000);
	block2cpc_wav(h_bin_cpc);
	block2cpc_wav(bin_cpc);

	close_wav();
	acelerar = tmp;
	return r;
}

////////////////////////////////////////////////////////////////////////////////

unsigned char prog_81[2 + 661] = { 0x1d, 0x9d,
	0x00, 0x04, 0x00, 0x7E, 0x42, 0x7F, 0x42, 0x97, 0x42, 0x97, 0x42, 0x9E,
	0x42, 0xA2, 0x42, 0x00,
	0x00, 0xA3, 0x42, 0xA3, 0x42, 0x00, 0x5D, 0x40, 0x00, 0x02, 0x02, 0x00,
	0xBF, 0xFD, 0xFF, 0x37,
	0x7E, 0x42, 0xFE, 0xFF, 0x00, 0x69, 0xD2, 0x8D, 0x0C, 0x00, 0x00, 0x60,
	0xFD, 0x00, 0x00, 0xBC,
	0x21, 0x18, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x84, 0x20,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x18, 0x01, 0xEA, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17,
	0x17, 0x17, 0x17, 0x76,
	0x00, 0x02, 0x02, 0x00, 0xFB, 0x76, 0x00, 0x03, 0x0F, 0x00, 0xF1, 0x29,
	0x14, 0x1D, 0x22, 0x20,
	0x20, 0x20, 0x7E, 0x8F, 0x00, 0x78, 0x00, 0x00, 0x76, 0x00, 0x04, 0x1B,
	0x00, 0xF5, 0xD3, 0x29,
	0x1A, 0xD3, 0x10, 0x29, 0x15, 0x1D, 0x7E, 0x81, 0x00, 0x00, 0x00, 0x00,
	0x11, 0x16, 0x1D, 0x1E,
	0x24, 0x7E, 0x88, 0x00, 0x00, 0x00, 0x00, 0x76, 0x00, 0x05, 0x3B, 0x00,
	0xF5, 0xD3, 0x10, 0x29,
	0x15, 0x1E, 0x7E, 0x82, 0x00, 0x00, 0x00, 0x00, 0x11, 0x18, 0x1D, 0x22,
	0x7E, 0x85, 0x00, 0x00,
	0x00, 0x00, 0x1A, 0xD3, 0x10, 0x29, 0x15, 0x21, 0x7E, 0x83, 0x20, 0x00,
	0x00, 0x00, 0x11, 0x15,
	0xD3, 0x10, 0x29, 0x15, 0x20, 0x7E, 0x83, 0x00, 0x00, 0x00, 0x00, 0x11,
	0x18, 0x1E, 0x21, 0x22,
	0x7E, 0x89, 0x00, 0x00, 0x00, 0x00, 0x76, 0x00, 0x06, 0x3B, 0x00, 0xF5,
	0xD3, 0x10, 0x29, 0x15,
	0x22, 0x7E, 0x83, 0x40, 0x00, 0x00, 0x00, 0x11, 0x18, 0x1D, 0x22, 0x7E,
	0x85, 0x00, 0x00, 0x00,
	0x00, 0x1A, 0xD3, 0x10, 0x29, 0x15, 0x25, 0x7E, 0x84, 0x10, 0x00, 0x00,
	0x00, 0x11, 0x15, 0xD3,
	0x10, 0x29, 0x15, 0x24, 0x7E, 0x84, 0x00, 0x00, 0x00, 0x00, 0x11, 0x18,
	0x1E, 0x21, 0x22, 0x7E,
	0x89, 0x00, 0x00, 0x00, 0x00, 0x76, 0x00, 0x07, 0x0B, 0x00, 0xF2, 0x1D,
	0x1C, 0x1C, 0x7E, 0x87,
	0x48, 0x00, 0x00, 0x00, 0x76, 0x00, 0x08, 0x0F, 0x00, 0xF9, 0xD4, 0x00,
	0x1D, 0x22, 0x21, 0x1D,
	0x20, 0x7E, 0x8F, 0x01, 0x04, 0x00, 0x00, 0x76, 0x00, 0x09, 0x09, 0x00,
	0xEC, 0x1E, 0x7E, 0x82,
	0x00, 0x00, 0x00, 0x00, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
	0x76, 0x76, 0x76, 0x76,
	0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
	0x76, 0x76, 0x69, 0x8F,
	0x00, 0x78, 0x00, 0x00, 0x80
};

unsigned char code_81[192] = {
	0xD3, 0xFD, 0x0E, 0xFE, 0x51, 0xAF, 0xD3, 0xFF, 0x3C, 0xED, 0x70, 0xE2,
	0x8A, 0x40, 0xD3, 0xFF,
	0x3C, 0xED, 0x70, 0xEA, 0x92, 0x40, 0xFE, 0x39, 0xCB, 0x12, 0xFE, 0x29,
	0x30, 0xE7, 0x14, 0x20,
	0xE3, 0x32, 0x3C, 0x40, 0x11, 0x41, 0x41, 0x06, 0x4E, 0x79, 0x3C, 0x3C,
	0xED, 0x70, 0xEA, 0xAD,
	0x40, 0x12, 0x13, 0x05, 0xCA, 0xC7, 0x40, 0x79, 0x3C, 0x3C, 0xED, 0x70,
	0xE2, 0xBB, 0x40, 0x12,
	0x13, 0x05, 0xC2, 0xAB, 0x40, 0xD3, 0xFF, 0x21, 0x8D, 0x41, 0x06, 0x20,
	0x3E, 0x80, 0x2B, 0x96,
	0x2B, 0x86, 0x10, 0xFA, 0x32, 0x3D, 0x40, 0xFD, 0xE5, 0xCD, 0x01, 0x41,
	0xED, 0x53, 0x3E, 0x40,
	0xCD, 0x1E, 0x41, 0xFD, 0x22, 0x40, 0x40, 0x21, 0x4E, 0x41, 0xCD, 0x01,
	0x41, 0xED, 0x53, 0x42,
	0x40, 0xCD, 0x1E, 0x41, 0xFD, 0x22, 0x44, 0x40, 0xFD, 0xE1, 0xD3, 0xFE,
	0x10, 0xFE, 0xC9, 0xFD,
	0x21, 0x00, 0x00, 0x11, 0x00, 0x00, 0x06, 0x20, 0x5E, 0xFD, 0x19, 0xAF,
	0xED, 0x6F, 0x23, 0x23,
	0x10, 0xF6, 0xFD, 0xE5, 0xD1, 0xCB, 0x1A, 0xCB, 0x1B, 0xD0, 0x13, 0xC9,
	0xFD, 0x21, 0x00, 0x00,
	0x4B, 0x06, 0x20, 0x2B, 0x2B, 0x7E, 0x91, 0x30, 0x02, 0xED, 0x44, 0xE5,
	0x21, 0x00, 0x00, 0x54,
	0x5F, 0xB7, 0x28, 0x04, 0x19, 0x3D, 0x20, 0xFC, 0xEB, 0xE1, 0xFD, 0x19,
	0x10, 0xE5, 0xC9, 0x00
};

////////////////////////////////////////////////////////////////////////////////
int adjust_81(char *f_out)
{
	int r;
	r = open_wav(f_out);

	memcpy(prog_81 + 123, code_81, sizeof(code_81));
	block281_wav(prog_81, sizeof(prog_81));

	close_wav();
	return r;
}

////////////////////////////////////////////////////////////////////////////////
#pragma package(smart_init)
