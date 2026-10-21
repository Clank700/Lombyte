/* Set the state field to one. Callers ignore the result: the 1 left in v0 is
   only the stored value. */

void video_dec_abort(int *state_fields) __asm__("func_0023CC70");

void video_dec_abort(int *state_fields) {
    state_fields[42] = 1;
}
