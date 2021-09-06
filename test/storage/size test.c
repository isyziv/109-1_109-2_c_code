#include <stdio.h>
#include <stdlib.h>
//s
struct struct__null
{
} struct_null_;
struct a33
{
    char an[3];
} a3;
struct a44
{
    char an[4];
} a4;
struct a55
{
    char an[5];
} a5;
struct a66
{
    char an[6];
} a6;
struct b33
{
    int b;
    char bn[3];
} b3;
struct ab33
{
    struct a33 ab1;
    struct b33 ab2;
} ab3;
struct b44
{
    int b;
    char bn[4];
} b4;
struct b55
{
    int b;
    char bn[5];
} b5;
struct b66
{
    int b;
    char bn[6];
} b6;
//u
union union__null
{
} union_null_;
union ua33
{
    char an[3];
} ua3;
union ua44
{
    char an[4];
} ua4;
union ua55
{
    char an[5];
} ua5;
union ua66
{
    char an[6];
} ua6;
union ub33
{
    int b;
    char bn[3];
} ub3;
union ub44
{
    int b;
    char bn[4];
} ub4;
union ub55
{
    int b;
    char bn[5];
} ub5;
union ub66
{
    int b;
    char bn[6];
} ub6;
//e
enum null_e
{

} en_null;
enum ea33
{
    a0 = 1,
    b0,
    c0
} ea3;
enum ea45
{
    a1sa1d6sa51d6a1s2x = 1,
    b11s456a4d5s4a6d4sa54das54d1s456a4d5s4a6d4sa54das54d1s456a4d5s4a6d4sa54das54d,
    c1s456a4d5s4a6d4sa54das54d8c46xz51c32zx,
    d1
} ea4;
enum ea55
{
    a2 = 1,
    b2,
    c2,
    d2,
    e2,
    f,
    g,
    h,
    i,
    k,
    l,
    m,
    n,
    o,
    p,
    q
} ea5;
enum etest
{
    //4 294 967 296
    a4k0 = 4294967290,
    a4k1,
    a4k2,
    a4k3,
    a4k4,
    a4k5,
    a4k6, /*4G*/
    a51,
    a52,
} enum_test;
enum eover
{
    //4 294 967 296
    a8G1 = 18446744073709551611,
    a8G2,
    a8G3,
    a8G4,
    a8G5,
    a8G6,
    a8G7

} enum_over;
int main(void)
{
    int int_s = (sizeof(int));
    int int_pt = (sizeof(int *));
    int char_s = (sizeof(char));
    int char_pt = (sizeof(char *));
    /////struct/////
    int struct_null = (sizeof(struct_null_));
    int aa3 = (sizeof(a3));
    int aa4 = (sizeof(a4));
    int aa5 = (sizeof(a5));
    int aa6 = (sizeof(a6));
    int ba3 = (sizeof(b3));
    int ba4 = (sizeof(b4));
    int ba5 = (sizeof(b5));
    int ba6 = (sizeof(b6));
    int aabb3 = (sizeof(ab3));
    /////union/////
    int union_null = (sizeof(union_null_));
    int uaa3 = (sizeof(ua3));
    int uaa4 = (sizeof(ua4));
    int uaa5 = (sizeof(ua5));
    int uaa6 = (sizeof(ua6));
    int uba3 = (sizeof(ub3));
    int uba4 = (sizeof(ub4));
    int uba5 = (sizeof(ub5));
    int uba6 = (sizeof(ub6));
    /////enum/////
    int enum_null = (sizeof(en_null));
    int eaa3 = (sizeof(ea3));
    int eaa4 = (sizeof(ea4));
    int eaa5 = (sizeof(ea5));
    int en_4bit = (sizeof(enum_test));
    int en_over = (sizeof(enum_over));
    system("pause");

    return 0;
}
//https://docs.microsoft.com/zh-tw/cpp/cpp/data-type-ranges?view=msvc-160