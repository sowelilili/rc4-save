#include "rc4-save.h"

// #define memcpy2(dst, src, n) do { \
//     char *csrc = (char *)src; \
//     char *cdst = (char *)dst; \
//     for (int i = 0; i < n; i++) { cdst[i] = csrc[i]; } \
// } while (0)

void _start(void) 
{
    api_mod = 1;
    if (frame_timer > 0)
        frame_timer -= 1;


    if (api_setaside == 1) {
        // set aside file
        api_setaside = 0;
        for(api_i = 0; api_i < 0x100000; api_i += 0x8000) {
            memcpy((void*)((int)api_aside_buf + api_i), (void*)((int)savedata_buf + api_i), 0x8000);
        }
    }

    if (api_load == 1) {
        if (frame_timer == 0) {
            // load set aside file
            if (*(int*)api_aside_buf == 0) {
                // oops! client requested load before setting aside file
                // set aside the file first
                for(api_i = 0; api_i < 0x100000; api_i += 0x8000) {
                    memcpy((void*)((int)api_aside_buf + api_i), (void*)((int)savedata_buf + api_i), 0x8000);
                }
            }

            frame_timer = 4;
            prev_game_mode = game_mode;
            game_mode = 3;
        // wait 3 frames to pull up the file so the game is actually paused
        } else if (frame_timer == 1) {
            restore_saved_game(0, api_aside_buf);
            api_load = 2;
        }

    } else if (api_load == 2) {
        // do load
        if (magic_addr == 15 || magic_addr == 24) {
            api_load = 0;
            magic_load(); 

        // cancel load
        } else if (magic_addr == 28) {
            api_load = 0;
            game_mode = prev_game_mode;
        }
    }

    return;
}