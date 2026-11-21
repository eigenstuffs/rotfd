#!/usr/bin/env python3
"""Overwrite uninitialized padding bytes in an object's extab section.

CodeWarrior leaves some extab action records with uninitialized padding (stack
garbage at compile time).  `dtk extab clean --padding` normalizes these, but
dtk 1.8.3 cannot decode every action type (e.g. action 17), so objects whose
records contain such actions use this explicit patch instead.

Usage: extab_patch.py <object.o> <offset>:<hexbytes> [...]

Offsets are relative to the start of the object's `extab` section.  Only
bytes inside that section can be patched; the script refuses anything else.
"""
import struct
import sys


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    path = sys.argv[1]
    data = bytearray(open(path, "rb").read())
    (shoff,) = struct.unpack(">I", data[0x20:0x24])
    shentsize, shnum, shstrndx = struct.unpack(">HHH", data[0x2E:0x34])
    hdrs = [struct.unpack(">IIIIIIIIII", data[shoff + i * shentsize:shoff + (i + 1) * shentsize])
            for i in range(shnum)]
    strtab = hdrs[shstrndx]
    extab = None
    for h in hdrs:
        name = bytes(data[strtab[4] + h[0]:]).split(b"\0")[0]
        if name == b"extab":
            extab = h
    if extab is None:
        sys.exit(f"{path}: no extab section")
    base, size = extab[4], extab[5]
    for spec in sys.argv[2:]:
        off_s, hexbytes = spec.split(":")
        off = int(off_s, 0)
        patch = bytes.fromhex(hexbytes)
        if off < 0 or off + len(patch) > size:
            sys.exit(f"{path}: patch {spec} outside extab (size {size:#x})")
        data[base + off:base + off + len(patch)] = patch
    open(path, "wb").write(data)


if __name__ == "__main__":
    main()
