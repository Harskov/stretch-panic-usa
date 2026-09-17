# macro.inc — assembler macros used by the splat-generated .s files.
# Written by gen_splat_yaml.py; every asm file starts with .include "macro.inc".
.macro glabel label
    .global \label
    .type \label, @function
    \label:
.endm

.macro dlabel label
    .global \label
    \label:
.endm

.macro jlabel label
    \label:
.endm

.macro alabel label
    \label:
.endm

# splat emits these bookkeeping markers around functions and data; they assemble to nothing
.macro nonmatching label, size
.endm

.macro endlabel label
.endm

.macro enddlabel label
.endm
