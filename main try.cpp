#include <allegro.h>
#include<alfont.h>
#include<string.h>

void init();
void deinit();

struct hiscore
      {
       int x;
       char name[25];
      }players[5];
      
int main() {
	init();
	BITMAP *bmp;
	PALETTE palette;
	bmp=load_bitmap("snowy.bmp",palette);
	blit(bmp,screen,0,0,0,0,bmp->w,bmp->h);
    PACKFILE *file;
	
	for(int i=0;i<5;i++)
        players[i].x=100;
    for(int i=0;i<5;i++)    
        strcpy(players[i].name,"UNKNOWN");  
	file=pack_fopen("scores\\scores1.txt","w");
	for(int i=0;i<5;i++)
	    pack_fwrite(&players[i],sizeof(hiscore),file);
	pack_fclose(file);
	/*strcpy(players[1].name,"durga");

	file=pack_fopen("scores.txt","r");
	pack_fseek(file,32);
	pack_fread(&players[2],sizeof(hiscore),file);*/
	while (!key[KEY_ESC]) {
		/*put your code here*/ 
     }

	deinit();
	return 0;
}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
