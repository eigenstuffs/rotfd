# Nine original delegates

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The new unregistered `src/Game/small_delegate_*.cpp` candidates retain nine original C entries and partial object views. All456 code bytes and the three naturally emitted frame EH/index pairs60 match. No other allocation or unused helper is emitted. Full-game acceptance is required before progress credit.

The entries are8001FAE0/36 (module load with the borrowed seven-byte small token),8009FDD0/56 and8009FE08/56 (record-field forwarding),801AD678/40 (wrapped array resize with preservation disabled),801AE21C/36 and801AEFD0/36 (member handle/action cleanup),801B3A90/72 and801B4BF4/60 (manager virtual reset/clear) and801C2B58/64 (first occupied slot or-1). The two record delegates ignore the third incoming argument and pass the fourth through two positions; the declarations describe the observed ABI, without claiming original type names. The manager vptr is at24 and its first native virtual slot is8.

GC1.3.2 O4,p, hardware FP, RTTI off and lmw/stmw off reproduce every byte and all18 actual relocation operands. Exceptions are enabled only for the first three entries because the original complete index owns their8-byte frame records and12-byte index records. Original function, external storage and callee identities stay unchanged; borrowed storage receives no credit.

Each accepted preflight scanned every current canonical text range and all current source/header/private bodies before the first probe. Two additional ranges,80235C08 and802781AC, were rejected because earlier bodies existed; they were not reprobed. Their failures and earlier research remain preserved. The complete original3,144-slot EH index and constructor/destructor tables are audited, including descriptor and zero padding. Only the three claimed original frame pairs refer to this batch; there is no startup ownership.
