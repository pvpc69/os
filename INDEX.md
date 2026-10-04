# Keyword index

Find the keyword in the question, then open `<keyword>.c`. Run: `./run.sh <keyword>` (uses `<keyword>.in` if it exists).

Tier: 1 = most repeated, 2 = high-moderate, 3 = moderate, 4 = low. 'Qs' = how many of the 60 slip questions use it. 'Learn first' = the program it is built from (diff = lines that differ, % = similarity).

| Keyword file | Question says | Tier | Qs | Lines | Learn first (diff) |
|---|---|---|---|---|---|
| `look.c` | LOOK disk scheduling | 1 | 3 | 51 | learn this one fully |
| `scan.c` | SCAN disk scheduling | 1 | 2 | 53 | `look.c` (2 lines differ, 98% same) |
| `cscan.c` | C-SCAN (circular scan) | 1 | 1 | 41 | `look.c` (16 lines differ, 80% same) |
| `sstf.c` | SSTF disk scheduling | 3 | 2 | 35 | learn this one fully |
| `fcfsdisk.c` | FCFS disk scheduling | 3 | 1 | 28 | `sstf.c` (9 lines differ, 83% same) |
| `sjfnp.c` | Non-preemptive Shortest Job First | 1 | 4 | 47 | learn this one fully |
| `fcfscpu.c` | FCFS CPU scheduling | 1 | 2 | 47 | `sjfnp.c` (1 lines differ, 98% same) |
| `prinp.c` | Non-preemptive Priority scheduling | 1 | 1 | 47 | `sjfnp.c` (4 lines differ, 91% same) |
| `prip.c` | Preemptive Priority scheduling | 2 | 3 | 45 | learn this one fully |
| `sjfp.c` | Preemptive SJF | 2 | 1 | 45 | `prip.c` (4 lines differ, 91% same) |
| `rr.c` | Round Robin | 3 | 2 | 67 | learn this one fully |
| `rrio.c` | Round Robin with fixed IO waiting time (2 units) | 3 | 1 | 81 | `rr.c` (21 lines differ, 81% same) |
| `lru.c` | LRU page replacement (counter) | 1 | 3 | 53 | learn this one fully |
| `fifo.c` | FIFO page replacement | 1 | 3 | 49 | `lru.c` (8 lines differ, 88% same) |
| `mfu.c` | MFU page replacement | 1 | 3 | 53 | `lru.c` (4 lines differ, 92% same) |
| `opt.c` | Optimal page replacement | 1 | 2 | 56 | `lru.c` (16 lines differ, 83% same) |
| `bankmenu.c` | Banker menu: Accept Available, Display Allocation/Max, Need | 1 | 3 | 69 | `banksafe.c` (55 lines differ, 64% same) |
| `banksafe.c` | Banker: need matrix + safe state / safe sequence | 1 | 2 | 99 | learn this one fully |
| `bankreq.c` | Banker: resource request granted or not | 1 | 1 | 140 | `banksafe.c` (58 lines differ, 74% same) |
| `seq.c` | Sequential (contiguous) file allocation | 2 | 1 | 77 | learn this one fully |
| `seqdel.c` | Sequential file allocation with Delete File | 2 | 1 | 95 | `seq.c` (20 lines differ, 87% same) |
| `linked.c` | Linked file allocation | 2 | 1 | 89 | `seq.c` (44 lines differ, 69% same) |
| `linkdel.c` | Linked file allocation with Delete File | 2 | 1 | 107 | `linked.c` (20 lines differ, 89% same) |
| `index.c` | Index file allocation | 2 | 1 | 90 | `seq.c` (44 lines differ, 68% same) |
| `nice.c` | nice() system call | 2 | 4 | 22 | learn this one fully |
| `orphan.c` | orphan process | 3 | 3 | 19 | learn this one fully |
| `execve.c` | execve() + binary search | 3 | 3 | 70 | learn this one fully |
| `sort.c` | bubble sort (parent) + insertion sort (child) | 4 | 2 | 44 | learn this one fully |
| `count.c` | shell with count command | 3 | 2 | 62 | learn this one fully |
| `search.c` | shell with search command | 3 | 1 | 68 | `count.c` (26 lines differ, 69% same) |

## Name rule (one word, no symbols)
- `np` = non-preemptive, `p` = preemptive: `sjfnp` `sjfp` `prinp` `prip`
- `del` = with Delete File: `seqdel` `linkdel`
- `io` = with fixed IO wait: `rrio`
- `fcfsdisk` = FCFS disk scheduling, `fcfscpu` = FCFS CPU scheduling
- `bankmenu` = menu, `banksafe` = safe sequence, `bankreq` = resource request

## Notes
- `nice` needs `sudo`; `execve` runs itself again through execve; `count` and `search` read `sample.txt`.
- Slips 1, 4, 11 Banker data is inconsistent (negative Need); ask the examiner. SCAN/C-SCAN disk size 200 is assumed.
- `cscan` counts the 199->0 jump (378 for the slip data; 179 without).
- Code is exactly as in your os-main files, only renamed.
