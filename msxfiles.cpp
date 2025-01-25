//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "sbb.h"
#include "funciones.h"

#pragma hdrstop

#include "msxfiles.h"

//////////////////////////////////////////////////////////////
int lee_msx_bin(const char *filename, ts_sbb_header * head_sbb,
		ts_sbb_block * blocks_sbb)
{
	int x;
	st_header_binmsx *header_binmsx;

	memset(head_sbb, 0, sizeof(head_sbb));	//2.2
	strcpy(head_sbb->machine, "MSX");
	head_sbb->ei_di = 1;
	asigna_nombre(head_sbb, filename);
	head_sbb->locate = 0xf4;
	head_sbb->n_blocks = 1;
	head_sbb->origin = _binary_;

	x = load_file(filename);
	if (!x) {
		header_binmsx = (st_header_binmsx *) bufferfile;

		strncpy(blocks_sbb[0].blockname, head_sbb->nombre, 6);
		blocks_sbb[0].ini = header_binmsx->ini;
		blocks_sbb[0].size = header_binmsx->last - header_binmsx->ini;
		blocks_sbb[0].exec = header_binmsx->exec;
		blocks_sbb[0].param3 = 0;
		blocks_sbb[0].block_type = header_binmsx->type;

		copy_data(&blocks_sbb[0], bufferfile + 7);
		if (blocks_sbb[0].exec)
			execjump(&blocks_sbb[0], 0xcd);
		else
			execjump(&blocks_sbb[0], 0x01);
	}

	blocks_sbb[1].block_type = 0;
	return x;
}

/*int lee_msx_rom (const char *filename,ts_sbb_header *head,ts_sbb_block *blocks_rom,const char * rom2bin )
{
   int res=0;
   AnsiString comand_line;

   AnsiString SaveDir=GetCurrentDir();
   if (!SetCurrentDir (ExtractFilePath(ToolRom2Bin)))
   {
       // ShowMessage ("Coud not set directory for msx rom2bin");
        MessageDlg("Coud not set directory for msx rom2bin",  mtError, TMsgDlgButtons() << mbOK, 0);

        return -1;
   }

   AnsiString mask= ExtractFilePath(ToolRom2Bin) +"temp*.bin";
   //todo
   TSearchRec sr;

   if (FindFirst( mask ,  faArchive  ,sr) == 0)
   {
      do
      {
        DeleteFile (sr.Name) ; 
      } while (FindNext(sr) == 0);
   FindClose(sr);
   }

   DeleteFile("temp.rom");
   DeleteFile("out.txt");
   CopyFile(filename,"temp.rom",false);
   comand_line= ExtractFileName(ToolRom2Bin)+" temp.rom >> out.txt";

   system (comand_line.c_str());



   int b=0;
   if (FindFirst( mask ,  faArchive  ,sr) == 0)
   {
   do
   {
        lee_msx_bin (sr.Name.c_str(),head,&blocks_rom[b]);
        blocks_rom[b].blockname[0]=b+'1';
        memcpy (blocks_rom[b].blockname+1,ExtractFileName (filename ).c_str(),5);
        b++;
   } while (FindNext(sr) == 0);
   FindClose(sr);
   }
   if (b==0)
      res=-4;

   memset ( head,0, sizeof (head));   //2.2
   strcpy(head->machine,"MSX");
   head->model = -1;
   head->ei_di = 1;
   asigna_nombre (head, filename);
   head->locate  = 0xf4;
   head->n_blocks  = b;
   head->origin= _rom_;
   head->poke_ffff=170;


   InputBlocksDlg->Memo1->Lines->LoadFromFile ("out.txt");
   SetCurrentDir(SaveDir);

   return res;
}*/

char h_cas[9] = { 0x1F, 0xA6, 0xDE, 0xBA, 0xCC, 0x13, 0x7D, 0x74, 0 };
char h_ascii[10] =
    { 0xEA, 0xEA, 0xEA, 0xEA, 0xEA, 0xEA, 0xEA, 0xEA, 0xEA, 0xEA };
char h_bin[10] = { 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0 };
char h_token[10] =
    { 0xD3, 0xD3, 0xD3, 0xD3, 0xD3, 0xD3, 0xD3, 0xD3, 0xD3, 0xD3 };

unsigned short buscaclear(char *basic)
{
	int input = 0;

	char *p;		//=  strstr ("CLEAR" , basic);

	char numero[20];
	int i = 1;
	p = strstr(basic, "CLEAR");
	if (p != NULL) {
		p = strstr(p, ",");
		if (p != NULL)
			if (isdigit(p[i]))
				sscanf(p + 1, "%i", &input);
			else {
				sscanf(p + 2, "%x", &input);
				if (!input)
					sscanf(p + 3, "%x", &input);
			}
	}
	return input;
}

char *busca_h(char *p, int max)
{
	char *h = p;
	while (memcmp(h, h_cas, 8))
		if ((h = (char *)memchr(++h, h_cas[0], max - (h - p))) == NULL)
			break;
	return h;
}

int leecas(const char *filename, ts_sbb_header * head_sbb,
	   ts_sbb_block * blocks_sbb)
{

	int t = 0;
	char *p;
	int x;

	memset(head_sbb, 0, sizeof(head_sbb));	//2.2
	strcpy(head_sbb->machine, "MSX");
	head_sbb->ei_di = 1;
	asigna_nombre(head_sbb, filename);
	head_sbb->locate = 0xf4;

	head_sbb->origin = _cas_;

	x = load_file(filename);
	p = (char*)bufferfile;
	if (!x)
		while (p = busca_h(p, tamanyo - (p - (char*)bufferfile))) {

			if (t > _MAX_SBB_BLOCKS_)
				break;
			p = p + 8;

			if (t == 0)
				strncpy(head_sbb->nombre, p + 10, 6);

			strncpy(blocks_sbb[t].blockname, p + 10, 6);
			blocks_sbb[t].blockname[6] = 0;
			blocks_sbb[t].block_type = p[0];

			if (!memcmp(p, h_ascii, 10)) {
				int trozo = 0;
				do {
					if ((p =
					     busca_h(p,
						     tamanyo - (p -
								(char*)bufferfile))) ==
					    NULL)
						break;
					p = p + 8;
					memcpy(blocks_sbb[t].data +
					       (trozo++) * 0x100, p, 0x100);
				} while (p[0xff] != 0x1a);

				blocks_sbb[t].data[(trozo) * 0x100] = 0;
				blocks_sbb[t].ini = 0xffff;
				blocks_sbb[t].size = (trozo) * 0x100;
				blocks_sbb[t].exec = 0xffff;
				copy_data(&blocks_sbb[t], blocks_sbb[t].data);
				execjump(&blocks_sbb[t], 0x01);

				if (!head_sbb->clear_sp)
					head_sbb->clear_sp =
					    buscaclear((char*)(blocks_sbb[t].data));
			} else if (!memcmp(p, h_bin, 10)) {
				p = busca_h(p, tamanyo - (p - (char*)bufferfile));
				p = p + 8;
				blocks_sbb[t].ini = *(unsigned short *)(p + 0);
				blocks_sbb[t].size =
				    *(unsigned short *)(p + 2) -
				    blocks_sbb[t].ini;
				blocks_sbb[t].exec = *(unsigned short *)(p + 4);
				memcpy(blocks_sbb[t].data, p + 6,
				       blocks_sbb[t].size);
				copy_data(&blocks_sbb[t], blocks_sbb[t].data);
				if (blocks_sbb[t].exec)
					execjump(&blocks_sbb[t], 0xcd);
				else
					execjump(&blocks_sbb[t], 0x01);
			} else if (!memcmp(p, h_token, 10)) {
				p = busca_h(p, tamanyo - (p - (char*)bufferfile));
				p = p + 8;
				strcpy(blocks_sbb[t].blockname,
				       "Token not suported");
				blocks_sbb[t].size = 0;
			} else {
				strcpy(blocks_sbb[t].blockname,
				       "unreconized block");
				blocks_sbb[t].block_type = -1;
				blocks_sbb[t].size = 0;
				t++;
				continue;	//error 4
			}

			t++;
		}

	blocks_sbb[t].block_type = 0;

	strncpy(head_sbb->nombre, blocks_sbb[0].blockname, 6);
	head_sbb->n_blocks = t;
	return x;
}

//////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------

#pragma package(smart_init)
