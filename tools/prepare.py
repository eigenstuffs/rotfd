#!/usr/bin/env python3
"""Prepare and verify the local GSQE78 reference executable from a disc or DOL."""

import argparse
import hashlib
import mmap
from pathlib import Path
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from gcm_extract import parse_dol


def prepare(source, destination, expected):
    if source.suffix.lower() == ".dol":
        dol = source.read_bytes()
    else:
        with source.open("rb") as stream:
            with mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_READ) as disc:
                if len(disc) < 0x460 or disc[:6] != b"GSQE78":
                    raise ValueError("Expected a GSQE78 GameCube disc")
                offset = struct.unpack_from(">I", disc, 0x420)[0]
                if offset + 0x100 > len(disc):
                    raise ValueError("Disc executable header is outside the image")
                dol, _ = parse_dol(disc, offset)
    actual = hashlib.sha1(dol).hexdigest()
    if actual != expected:
        raise ValueError(f"Reference SHA-1 mismatch: expected {expected}, got {actual}")
    if destination.exists():
        if destination.read_bytes() != dol:
            raise ValueError(f"Refusing to replace a different reference: {destination}")
        print(f"Verified existing {destination} ({actual})")
        return
    destination.parent.mkdir(parents=True, exist_ok=True)
    # Exclusive creation preserves an existing reference even if another process
    # prepares it between our check and write.
    with destination.open("xb") as stream:
        stream.write(dol)
    print(f"Prepared {destination} ({actual})")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path, help="local GSQE78 disc image or standard main.dol")
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    expected = (root / "config/GSQE78/build.sha1").read_text().split()[0]
    try:
        prepare(args.source, root / "orig/GSQE78/main.dol", expected)
    except (OSError, ValueError, AssertionError, struct.error) as error:
        parser.exit(1, f"prepare: {error}\n")


if __name__ == "__main__":
    main()
