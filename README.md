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

    | Atual: 0	Custo: 0	Pai: -1|
    | Atual: 1	Custo: 270	Pai: 0 |
    | Atual: 2	Custo: 504	Pai: 3 |
    | Atual: 3	Custo: 151	Pai: 4 |
    | Atual: 4	Custo: 2564	Pai: 1 |
    | Atual: 5	Custo: 272	Pai: 4 |
    | Atual: 6	Custo: 241	Pai: 5 |
    | Atual: 7	Custo: 1560	Pai: 5 |
    | Atual: 8	Custo: 1274	Pai: 7 |
    | Atual: 9	Custo: 236	Pai: 8 |

    Custo total: 7072


    | Djijkstra	Instances/dij10.txt |

    | Atual: 0	Custo: 0	Pai: -1|
    | Atual: 1	Custo: 270	Pai: 0 |
    | Atual: 2	Custo: 3173	Pai: 1 |
    | Atual: 3	Custo: 2985	Pai: 1 |
    | Atual: 4	Custo: 2834	Pai: 1 |
    | Atual: 5	Custo: 3025	Pai: 1 |
    | Atual: 6	Custo: 3266	Pai: 5 |
    | Atual: 7	Custo: 3738	Pai: 0 |
    | Atual: 8	Custo: 4947	Pai: 0 |
    | Atual: 9	Custo: 5183	Pai: 8 |

    Custo total: 5183
