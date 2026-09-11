_This project has been created as part of the 42 curriculum by Sturuvek and ebroeker._

# push_swap

## Description

This project involves sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you will have to manipulate various types of algorithms and choose the most appropriate solution (optimized radical sorting or chunk-based partitioning) for an optimized data sorting. The final output is an executable program named push_swap that outputs the minimal list of instructions.

## Instructions

Clone the repository:
   ```bash
   git clone https://github.com
   cd push_swap
   ```

### Compilation

```bash
make
```

This produces the `push_swap` executable at the root of the repository.

### Usage

Run the executable with a list of unsorted integers passed as arguments:

```bash
./push_swap 7 2 9 4 3
```

You can also pass the numbers as a single quoted string or test validity:

```bash
./push_swap "7 2 9 4 3"
```

### Cleaning Up

*   To remove object files:
    ```bash
    make clean
    ```
*   To remove object files and the executable:
    ```bash
    make fclean
    ```
*   To force recompilation:
    ```bash
    make re
    ```

### Makefile 

| Rule | Effect |
|------|--------|
| `make` / `make all` | Compiles the push_swap program |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the `push_swap` binary |
| `make re` | Runs fclean then all |

## Supported operations

| Operation | Description |
|-----------|-------------|
| `sa` / `sb` | Swap the first 2 elements at the top of stack a / stack b |
| `ss` | sa and sb at the same time |
| `pa` | Push the first element at the top of b and put it at the top of a |
| `pb` | Push the first element at the top of a and put it at the top of b |
| `ra` / `rb` | Shift up all elements of stack a / stack b by 1. The first element becomes the last one |
| `rr` | ra and rb at the same time |
| `rra` / `rrb` | Shift down all elements of stack a / stack b by 1. The last element becomes the first one |
| `rrr` | rra and rrb at the same time |

------------------------------
## Algorithm & Architecture

The core architecture of push_swap is built around a centralized dynamic dispatcher located in main.c. Upon validating and parsing the integer inputs, the program evaluates the total capacity of the stack to assign the most efficient sorting pipeline. The input parsing logic isolates numeric strings, converts them into standard integers, protects against overflows, and guarantees that no duplicate values enter the data structures. The program manages memory through a strict tracking architecture where instructions are recorded into an internal operations list (t_op) to be processed, combined, and compressed by a dedicated post-processor before being pushed onto the standard output via write calls.

### Simple
For small data volumes (sets containing up to 5 elements), the application invokes the simple_sort infrastructure. This framework applies a combination of predictive logic and target selection. When sorting three elements, the pipeline utilizes hardcoded relational tests (sort_three) to order the values within a maximum of two operations. For sets of 4 or 5 elements, the engine continuously calculates the absolute minimum value in stack a, computes its current index distance from the head pointer, and dynamically pushes the cheapest rotations (ra or rra) to bring it to the apex. The element is then moved into stack b (pb). Once stack a is reduced to 3 elements, it is ordered via sort_three, and the isolated elements are safely recovered using pa.

### Medium
For mid-sized and large data sets, the pipeline executes the chunk-based partition system managed within medium_sort.c. Before any element is shifted, the engine executes a pre-sorting index pass (rank_stack) that computes the relative rank of each integer node against the entire stack matrix, transforming arbitrary absolute inputs into sequential indices ranging from 0 to N-1. The stack is then split into dynamic numerical blocks (chunks) calculated through an integrated mathematical square root estimation (ft_int_sqrt). Elements are scanned sequentially; those matching the current active chunk parameters are immediately moved to stack b. To maintain optimal compression and mitigate operation counts, a secondary sandglass distribution routine shifts elements falling into the lower boundaries of the current block to the bottom of stack b via immediate rb interventions. Finally, a retrieval routine scans stack b for the highest sequential rank, uses optimal rotation directions to position it at the peak, and shifts it back to stack a completely sorted.

### Complex

### Adapting


## Testing
 - Checker_linux

## Resources


