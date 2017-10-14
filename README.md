# GreedyAlgorithms
Repository for allocating some greedy algorithms implementations for the Analysis and Project of Algorithms course at Federal University of Paraiba.

## Implemented Algorithms
* Prim
* Djijkstra

The output is composed by measurements of efficiency for each of the algorithms implemented.

## Compiling and Running:

To compile, just run the command:

```bash
make
```

To run the executable:

```bash
./prim_djijkstra PATH_TO_INPUT_FILE.txt
```

## Example of output:

```bash
./prim_djijkstra Instances/dij10.txt
```

    | Prim	Instances/dij10.txt |

    | Current: 0	Cost: 0		Parent: -1|
    | Current: 1	Cost: 270	Parent: 0 |
    | Current: 2	Cost: 504	Parent: 3 |
    | Current: 3	Cost: 151	Parent: 4 |
    | Current: 4	Cost: 2564	Parent: 1 |
    | Current: 5	Cost: 272	Parent: 4 |
    | Current: 6	Cost: 241	Parent: 5 |
    | Current: 7	Cost: 1560	Parent: 5 |
    | Current: 8	Cost: 1274	Parent: 7 |
    | Current: 9	Cost: 236	Parent: 8 |

    Total cost: 7072


    | Djijkstra	Instances/dij10.txt |

    | Current: 0	Cost: 0		Parent: -1|
    | Current: 1	Cost: 270	Parent: 0 |
    | Current: 2	Cost: 3173	Parent: 1 |
    | Current: 3	Cost: 2985	Parent: 1 |
    | Current: 4	Cost: 2834	Parent: 1 |
    | Current: 5	Cost: 3025	Parent: 1 |
    | Current: 6	Cost: 3266	Parent: 5 |
    | Current: 7	Cost: 3738	Parent: 0 |
    | Current: 8	Cost: 4947	Parent: 0 |
    | Current: 9	Cost: 5183	Parent: 8 |
    
    Total cost: 5183
