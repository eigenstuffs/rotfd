# Grid index records

`src/Game/index_grid_collect.cpp` and `src/Game/index_grid_records.cpp`
reconstruct three consecutive functions
at `80267248..80267400`, totaling 440 code bytes:

| Entry | Size | Observed operation |
| --- | ---: | --- |
| `fn_80267248` | 132 | Insert records for each cell in caller bounds |
| `fn_802672CC` | 160 | Acquire and link one cell record |
| `fn_8026736C` | 148 | Unlink and release a temporary record chain |

The native grid has a column count at `18`, free-list head/count at `20/24`,
a cell-head array at `28`, and a record array at `34`. Both arrays use native
count/capacity/data fields and an unsigned index accessor. The accessor
reproduces the original indexed-address instructions. Each 20-byte record
contains its previous/next cell links, temporary chain link, cell index and
caller context pointer. Names describe observed behavior and remain inferred.

The rectangle routine uses half-open x/y bounds. Insertion asks the external
`fn_80267400` for an index, updates the old cell head's next link, and records
the previous temporary-chain head. Release removes each record from the cell
links, updates the cell-head array when needed, and returns the record to the
free chain while increasing the free count. Empty cell/chain sentinels are `-1`.

GC/1.3.2 with the recorded optimized Game flags reproduces the two complete objects:
exactly 440 text bytes, three functions, and two actual branch relocations.
One relocation calls the separately reconstructed insertion unit; the other targets
`fn_80267400`, which retains original ownership. There are no constants, data,
BSS, weak functions or alignment bytes. Strict verification:

```
python3 scratch/game_index_grid_collect/verify_collect.py
python3 scratch/game_index_grid_collect/verify.py
```

The candidate manifest and applied-relocation evidence are in the same scratch
folder. These splits are integrated and pass the original DOL SHA-1 and native objdiff.
The partial split does not establish an original translation-unit boundary.
