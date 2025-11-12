#ifndef RC4_SAVE_H
    #define RC4_SAVE_H

    // Game functions
    #define memcpy               ((void (*)(void*, void*, int))0x7e61f4)
    #define restore_saved_game          ((void (*)(int, void*))0x3c902c)
    #define magic_load                            ((void (*)())0x3c9398)

    // Game addresses
    #define savedata_info (*((void**)0xa28e68))
    #define savedata_buf (*(void**)((int)savedata_info + 4))
    // #define savedata_buf (*((void**)0xa28e6c))
    // #define savedata_buf (*(void**)((int)savedata_info + 4))
    #define level_id           (*(int*)0x09c3240)
    #define destination_planet (*(int*)0x0b36dd0)
    #define should_load        (*(int*)0x0b36dcc)
    #define magic_addr         (*(int*)0x119f8dc)
    #define game_mode          (*(int*)0x0b3c5a0)

    // I/O addresses
    #define api_mod        (*(char*)0x15CD71D)
    #define api_load       (*(char*)0x15CD71E)
    #define api_setaside   (*(char*)0x15CD71F)
    #define api_i          (*((int*)0x15CD720))
    #define load_arg      (*((char*)0x15CD740))
    #define prev_game_mode (*((int*)0x15CD750))
    #define frame_timer    (*((int*)0x15CD760))
    #define api_aside_buf   ((void*)0x1600000)

#endif // RC4_SAVE_H