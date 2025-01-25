#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include "loaders.h"
#include "zxfiles.h"
#include "cpcfiles.h"
#include "msxfiles.h"
#include "81files.h"

#define	SPECTRUM	"ZXS"
#define	AMSTRAD		"CPC"
#define	MSX			"MSX"
#define	ZX81		"81-"
#define	ND			"NOT"

#define MAX_FILEIN_LEN	256
#define	MAX_EXT_LEN		5

extern int invert_pol;
extern int forma_onda;
extern int freq_muestreo;
extern int s_p_b;
extern int acelerar;
extern int pausa_ms;
extern int make_loader;
extern int checkloaderror;
extern int enable_int;
bool nosbb = false;
bool nowav = false;
char *filename = NULL;
char ext[MAX_EXT_LEN];
char filein[MAX_FILEIN_LEN];
const int bitrate_mp3 = 256; //Default value for mp3 file
bool mp3 = false;
char platform[4];

ts_sbb_header batch_head;
ts_sbb_block batch_blocks[_MAX_SBB_BLOCKS_ + 1];

bool get_extension(char dst[5], char *src)
{
	char *ptr = NULL;

	ptr = strrchr(src, '.');
	if (ptr) {
		strncpy(dst, ptr+1, 5);
		return true;
	}

	return false;
}

bool remove_extension(char *srcdst)
{
	char *ptr = NULL;

	ptr = strrchr(srcdst, '.');
	if (ptr != NULL) {
		*ptr = '\0';	
		return true;		
	}
	
	return false;	
}

int analiza_tap()
{
	int res = 0;
	int b;
	for (b = 0; b < _MAX_SBB_BLOCKS_; b++) {
		if (b > batch_head.n_blocks || 0 == batch_blocks[0].block_type)
			break;

		if (_zx_program_ == batch_blocks[0].block_type)
			if (1 == batch_head.n_blocks) {
				zxbasic2bytes(batch_blocks);
				batch_head.usr_pc = batch_blocks->exec;
				break;
			} else {
				for (int i = b; i < _MAX_SBB_BLOCKS_; i++) {
					batch_blocks[i] = batch_blocks[i + 1];
				}
				b--;
				batch_head.n_blocks--;
				continue;
			}

		if (_zx_tap_hdlss_ == batch_blocks[b].block_type) {
			res = -11;
			break;
		}
		if (batch_blocks[b].ini + batch_blocks[b].size - 1 >=
		    MAX_DIR_ZX) {
			for (int i = _MAX_SBB_BLOCKS_; i > b; i--) {
				batch_blocks[i] = batch_blocks[i - 1];
			}
			zxlastbytes(&batch_head, &batch_blocks[b]);
			batch_head.n_blocks++;
			b++;
		}
	}
	return res;
}

int BuildSbb(char *filename, uint16_t M_y_E)
{
	int res;
	switch (M_y_E) {
	case 0x5a54:
		res = leetap(filename, &batch_head, batch_blocks);
		if (res)
			return res;
		res = analiza_tap();
		break;
	case 0x5a53:
		res = lee_zx_sna(filename, &batch_head, batch_blocks);
		break;
	case 0x5a5a:
		res = leez80(filename, &batch_head, batch_blocks);
		break;
	case 0x4342:
		res=lee_cpc_bin (filename,&batch_head,batch_blocks);
		break;
	case 0x4353:
		res = lee_cpc_sna(filename, &batch_head, batch_blocks);
		break;
	case 0x4d42:
		res=lee_msx_bin (filename,&batch_head,batch_blocks);
		break;
	case 0x4d43:
		res = leecas(filename, &batch_head, batch_blocks);
		break;
	case 0x4d52:
		//res = lee_msx_rom(filename, &batch_head, batch_blocks, NULL);
		break;
	case 0x3850:
		res = lee_p(filename, &batch_head, batch_blocks);
		break;
	case 0x385a:
		res = lee_z81(filename, &batch_head, batch_blocks);
		break;
	default:
		res = -1;
	}
	return res;
}

void convert2mp3(char *filename)
{
	char buf[1024];

	sprintf(buf, "lame \"%s\"  -m m -f -b %i", filename, bitrate_mp3);
	system(buf);
}

void usage(int argc, char *argv[])
{
	printf("Usage:\n");
	printf("%s [options] -p <ZXS|CPC|MSX|81-> -i <filename>             \n"
               "  OPTIONS:                             \n"
               "  -pol <1|-1>                          Inverse wav polarity (default: 1)\n\n"
               "  -form <0|1|2|3|4|5|6>                Waveform (default: 1 i.e. Cubic)\n"
               "                                       0: Square\n"
               "                                       1: Cubic\n"
               "                                       2: SqrSin\n"
               "                                       3: Shaw\n"
               "                                       4: E=cte\n"
               "                                       5: Delta\n"
               "                                       6: Delta2\n\n"
               "  -freq <44100|48000>                  Sampling frequency (default: 44100)\n\n"
               "  -spb <17|16|15|14|12|10|11|8|7>      Samples per bit\n"
               "                                       (default: 14 i.e. 3.75)\n"
               "                                       17: 4.25\n"
               "                                       16: 4.0\n"
               "                                       15: 3.75\n"
               "                                       14: 3.50\n"
               "                                       12: 3.0\n"
               "                                       10: 2.50\n"
               "                                       11: 2.75\n"
               "                                       8:  2.25\n"
               "                                       7:  1.75\n\n"
               "  -acc <0|1>                           Accelerate (default: 0)\n\n"
               "  -pause <ms>                          Pause between blocks (default: 500)\n\n"
               "  -loader <0|1>                        Make loader (default: 1)\n\n"
               "  -check <0|1>                         Check loading error (default: 1)\n\n"
               "  -int <0|1>                           Enable interrupts (default: 0)\n\n"
               "  -nosbb                               Remove SBB file\n\n"
               "  -nowav                               Remove WAV file\n\n"
               "  -mp3                                 Convert to mp3 (lame is needed)\n\n", argv[0]);

	exit(1);
}

void show_settings(int argc, char *argv[])
{
	printf("Current settings:\n");
	printf("====================================\n");
	printf("Inverse wav polarity:       %d\n", invert_pol);
	printf("Waveform:                   %d\n", forma_onda);
	printf("Sampling frequency:         %d\n", freq_muestreo);
	printf("Samples per bit:            %d\n", s_p_b);
	printf("Accelerate:                 %d\n", acelerar);
	printf("Pause between blocks:       %d\n", pausa_ms);
	printf("Make loader:                %d\n", make_loader);
	printf("Check loading error:        %d\n", checkloaderror);
	printf("Enable interrupts:          %d\n", enable_int);
	printf("PLATFORM:                   %s\n", platform);
	printf("====================================\n");
	printf("FILENAME: %s \n", (filename)?filename:"missing");

	if (!filename) {
		fprintf(stderr, "\nInput filename not specified\n");
		usage(argc, argv);
	}

	if (strcmp(platform, SPECTRUM) &&
		strcmp(platform, AMSTRAD) &&
		strcmp(platform, MSX) &&
		strcmp(platform, ZX81)) {
		fprintf(stderr, "\nWrong platform specified\n");
		usage(argc, argv);
	}
}

int commandline(int argc, char *argv[])
{
	char *buf, tmp[MAX_FILEIN_LEN];
	int cnt = 1;

	while (cnt<argc) {
		if (!strcmp(argv[cnt],"-i")) {
			filename = argv[++cnt];
			// Put in filein, the name without extension...
			// No names with . are allowed!!!
			strncpy(tmp, argv[cnt], MAX_FILEIN_LEN);
			if (!remove_extension(tmp)) {
				fprintf(stderr, "Error analyzing filename");
				exit(1);
			}
        	strncpy(filein, tmp, MAX_FILEIN_LEN);
        	get_extension(ext, filename);
		}
		else if (!strcmp(argv[cnt], "-p")) {
			strncpy(platform, argv[++cnt], 4);
		}
		else if (!strcmp(argv[cnt],"-pol")) {
			invert_pol = atoi(argv[++cnt]);	
		}
		else if (!strcmp(argv[cnt],"-form")) {
			forma_onda = (unsigned int)atoi(argv[++cnt]);
		}
		else if (!strcmp(argv[cnt],"-freq")) {
			freq_muestreo  = (unsigned int)atoi(argv[++cnt]);
		}
		else if (!strcmp(argv[cnt],"-sbp")) {
			s_p_b  = (unsigned int)atoi(argv[++cnt]);
		}
		else if (!strcmp(argv[cnt],"-acc")) {
			acelerar  = (unsigned int)atoi(argv[++cnt]);
		}
		else if (!strcmp(argv[cnt],"-pause")) {
			pausa_ms  = (unsigned int)atoi(argv[++cnt]);
		}
		else if (!strcmp(argv[cnt],"-loader")) {
			make_loader  = (unsigned int)atoi(argv[++cnt]);
		}
		else if (!strcmp(argv[cnt],"-check")) {
			checkloaderror  = (unsigned int)atoi(argv[++cnt]);
		}
		else if (!strcmp(argv[cnt],"-int")) {
			enable_int  = (unsigned int)atoi(argv[++cnt]);
		}
		else if (!strcmp(argv[cnt],"-nosbb")) {
			nosbb = true;
		}
		else if (!strcmp(argv[cnt],"-nowav")) {
			nowav = true;
		}
		else if (!strcmp(argv[cnt],"-mp3")) {
			mp3 = true;
		}
		else {
			usage(argc, argv);
		}
		cnt++;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	int res = 0;
	char sbb_filename[MAX_FILEIN_LEN+5];
	char wav_filename[MAX_FILEIN_LEN+5];
	uint16_t config;

	memset(platform, 0, 4);
	strncpy(platform, ND, 4);

	if (argc<2) {
		usage(argc, argv);
	}

	// Store filename
	commandline(argc, argv);

	// Show current settings
	show_settings(argc, argv);

	// Get the configuration from platform and extension
	config = (platform[0]<<8) + (uint16_t)toupper(ext[0]);
	//printf(">> %04x <<\n", config);

	// Convert from orig file to SBB
	sprintf(sbb_filename, "%s.sbb", filein);	
	printf("SBB:      %s", sbb_filename);
	res = BuildSbb(filename, config);
	printf("\t%s\n", (res==0)?"OK":"FAIL");
	if (res)
		exit(1);
        res = save_sbb_file(sbb_filename, &batch_head, batch_blocks); 

	// Convert from SBB to WAV
	sprintf(wav_filename, "%s.wav", filein);
	printf("WAV:      %s", wav_filename);
	res = sbb2wav(sbb_filename, wav_filename);
	printf("\t%s\n", (res==0)?"OK":"FAIL");
	if (res)
		exit(1);

	if (nosbb)
		unlink( sbb_filename );

	if (mp3) 
		convert2mp3(wav_filename);

	if (nowav)
		unlink( wav_filename );

	exit(0);
}
