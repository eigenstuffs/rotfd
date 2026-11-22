"""Complete the storage reporting co-output after every successful DTK split.

The frozen v2 tool performs every byte/metadata/input validation. Touching its
verified identical reporting copy makes the co-output newer than changed split
inputs, so Ninja can finish reconfiguration even when its bytes are unchanged.
The raw legacy linker object and both object payloads are never changed here.
"""

import argparse
import json
from pathlib import Path

if __package__:
    from .normalize_text_storage_v2 import main as normalize_main
else:
    from normalize_text_storage_v2 import main as normalize_main


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("build_dir", type=Path)
    parser.add_argument("--contract", type=Path, default=Path("config/GSQE78/text_storage.json"))
    args = parser.parse_args()
    contract = json.loads(args.contract.read_text())
    if contract["unit"] not in ("auto_03_801EF5C8_text", "Game/heap_manager_storage_801EF5C8.c"):
        raise ValueError("Unsupported storage reporting co-output")
    normalize_main()
    target = args.build_dir / "obj-report" / (Path(contract["unit"]).stem + ".o")
    target.touch()


if __name__ == "__main__":
    main()
