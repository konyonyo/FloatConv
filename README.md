FloatConv (Floating point number Converter)
===

# What is this?

This is Floating point number Converter.  
By using this, you can convert a floating point number to its hexadecimal representation, and  
convert a hexadecimal representation to its corresponding floating point number.

For example, you can get the hexadecimal representation of 1.0 (64-bit floating point number)  
by the following commands.

```
fp64 hex 1.0
```

The answer is:

```
3ff0000000000000
```

The supported floating point number formats are:

- bf16 (bfloat16)
- fp16 (IEEE 754 binary16)
- fp32 (IEEE 754 binary32)
- fp64 (IEEE 754 binary64)

# How to build?

```
$ g++ main.cpp
```

# How to use?

```
$ g++ main.cpp
$ ./a.out
Please input <from> <to> <value>. (e.g. fp64 hex 1.0)
(<from>, <to>) should be one of the following patterns.
(bf16, hex), (fp16, hex), (fp32, hex), (fp64, hex),
(hex, bf16), (hex, fp16), (hex, fp32), (hex, fp64)
fp64 hex 1.0
3ff0000000000000
```

# Dependency

This is using [FloatX (Float eXtended)](https://github.com/oprecomp/FloatX).
