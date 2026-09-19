
typedef unsigned char u8;
typedef unsigned __int128 u128;
typedef struct Src
{
  u8 unk_00[0x80];
  u128 v80;
  u128 v90;
  u128 vA0;
} Src;
typedef struct Dst
{
  u8 unk_00[0x28C];
  u8 flag;
  u8 unk_28D[0x310 - 0x28D];
  u128 v310;
  u128 v320;
  u128 v330;
} Dst;
void func_00162900(Dst *arg0, Src *arg1)
{
  u128 a;
  u128 b;
  Dst *new_var;
  u128 c;
  new_var = arg0;
  new_var->flag = 1;
  c = arg1->vA0;
  b = arg1->v90;
  ;
  new_var->v310 = arg1->v80;
  new_var->v320 = b;
  new_var->v330 = (int) c;
}
