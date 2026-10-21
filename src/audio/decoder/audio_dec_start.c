#include "types.h"
#include "rnc/audio/decoder/audio_dec.h"
extern void snd_start_movie_sound(s32, s32, s32, s32, s32) __asm__("func_0012F108");
void audio_dec_start(struct AudioDec *dec) __asm__("FUN_0023acb8");

void audio_dec_start(struct AudioDec *dec) {
    snd_start_movie_sound(dec->iopBuff, (dec->iopBuffSize / 0x400) * 0x400, dec->iopZero,
                          dec->hdr.rate, dec->hdr.ch);
    dec->state = 2;
}

extern __typeof__(audio_dec_start) func_0023ACB8 __attribute__((alias("FUN_0023acb8")));

/* Recovered original symbol name. */
extern __typeof__(audio_dec_start) audioDecStart __attribute__((alias("FUN_0023acb8")));
