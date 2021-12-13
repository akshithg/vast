// RUN: vast-cc --from-source %s | FileCheck %s
// RUN: vast-cc --from-source %s > %t && vast-opt %t | diff -B %t -

int add1(int a, int b)
{
    // CHECK: [[V1:%[0-9]+]] = hl.declref @a : !hl.int
    // CHECK: [[V2:%[0-9]+]] = hl.implicit_cast [[V1]] LValueToRValue : !hl.int -> !hl.int
    // CHECK: [[V3:%[0-9]+]] = hl.declref @b : !hl.int
    // CHECK: [[V4:%[0-9]+]] = hl.implicit_cast [[V3]] LValueToRValue : !hl.int -> !hl.int
    // CHECK: hl.add [[V2]], [[V4]] : !hl.int
    return a + b;
}

int add2(int a, int b)
{
    // CHECK: hl.var @r : !hl.int
    // CHECK: [[V1:%[0-9]+]] = hl.declref @a : !hl.int
    // CHECK: [[V2:%[0-9]+]] = hl.implicit_cast [[V1]] LValueToRValue : !hl.int -> !hl.int
    // CHECK: [[V3:%[0-9]+]] = hl.declref @b : !hl.int
    // CHECK: [[V4:%[0-9]+]] = hl.implicit_cast [[V3]] LValueToRValue : !hl.int -> !hl.int
    // CHECK: [[V5:%[0-9]+]] = hl.add [[V2]], [[V4]] : !hl.int
    // CHECK: hl.value.yield [[V5]]
    int r = a + b;

    // CHECK: [[V7:%[0-9]+]] = hl.declref @r : !hl.int
    // CHECK: [[V8:%[0-9]+]] = hl.implicit_cast [[V7]] LValueToRValue : !hl.int -> !hl.int
    // CHECK: return [[V8]] : !hl.int
    return r;
}

void add3()
{
    // CHECK: hl.var @v : !hl.int
    // CHECK: [[V1:%[0-9]+]] = hl.constant(#hl.int<1>) : !hl.int
    // CHECK: [[V2:%[0-9]+]] = hl.constant(#hl.int<2>) : !hl.int
    // CHECK: [[V3:%[0-9]+]] = hl.add %0, %1 : !hl.int
    // CHECK: hl.value.yield [[V3]]
    int v = 1 + 2;
}
