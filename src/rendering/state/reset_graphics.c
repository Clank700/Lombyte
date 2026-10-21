#include "types.h"
#include "sda.h"
#include "rnc/rendering/dma_tag.h"

extern s32 D_0015ED80[] MACRO_ADDR;
extern s32 D_0015EE78[] MACRO_ADDR;
extern s32 D_0015EE78_gp;
extern s32 space_load_in_progress[] __asm__("D_0015F618") MACRO_ADDR;
extern volatile s32 vif_chain_flags __asm__("D_00160EE0") MACRO_ADDR;
extern void reset_vif1_gif(void) __asm__("func_001204B8");
extern void set_pal_mode(void) __asm__("func_001F34E8");
extern void init_dma(void) __asm__("func_0020B418");
extern void vu1_init_chain(void) __asm__("func_002335D0");
extern void dmac_vif1_enable(void) __asm__("func_00233D00");
extern void dmac_vif1_disable(void) __asm__("func_00233D90");
extern s32 sceDmaReset();
extern s32 sceGsResetGraph();

void reset_graphics(void) __asm__("FUN_001f21c0");

void reset_graphics(void) {
    s32 saved;

    /* The volatile flag store stays out of the call's delay slot, as retail. */
    space_load_in_progress[0] = 1;
    vif_chain_flags = 0;
    dmac_vif1_disable();
    sceDmaReset(1);
    init_dma();
    sceGsResetGraph(0, 1, (D_0015ED80[0] != 0) ? 3 : 2, 0);
    reset_vif1_gif();
    vu1_init_chain();
    saved = D_0015EE78[0];
    render_packet_cursor.addr = 0;
    set_pal_mode();
    /* set_pal_mode rewrites the second image buffer address; keep the old one. */
    D_0015EE78_gp = saved;
    vu1_init_chain();
    dmac_vif1_enable();
}
