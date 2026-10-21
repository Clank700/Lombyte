#include "types.h"
extern void copy_matrix_rotation(void *, void *) __asm__("func_001FA298");
extern void copy_matrix3x4(void *, void *) __asm__("func_001FA2B8");
extern void matrix_to_quaternion(void *, void *) __asm__("func_00214260");
void extract_matrix_rotation_quaternion(void *arg0, void *arg1) __asm__("FUN_002144d8");

/* The matrix's rotation as a quaternion; the matrix keeps only its rotation. */
void extract_matrix_rotation_quaternion(void *output_quaternion, void *matrix) {
    u8 rotation[0x40];

    copy_matrix_rotation(rotation, matrix);
    matrix_to_quaternion(output_quaternion, rotation);
    copy_matrix3x4(matrix, rotation);
}

extern __typeof__(extract_matrix_rotation_quaternion) func_002144D8 __attribute__((alias("FUN_002144d8")));
