_This project has been created as part of the 42 curriculum by sturuvek and ebroeker._

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

Run the executable with a list of unsorted integers passed as arguments. By default, the program uses the dynamic `--adaptive` selection strategy based on the initial disorder metric of the stack:

```bash
./push_swap 7 2 9 4 3
```

You can also pass the numbers as a single quoted string:

```bash
ARG="4 67 3 87 23"; ./push_swap \$ARG
```

### Strategy Selection & Benchmark Mode

The binary embeds four unique sorting regimes that can be explicitly forced using strategy flags. Any selector flag works regardless of the input size or current stack arrangement:

*   `--simple`: Forces the use of the O(n²) baseline algorithm (optimized for $\le$ 5 elements).
*   `--medium`: Forces the use of the O(n√n) chunk-based partitioning framework (optimized for 100 elements).
*   `--complex`: Forces the use of the O(n log n) Radix sorting infrastructure (optimized for 500+ elements).
*   `--adaptive`: Evaluates the raw disorder metric before any mutation and dynamically branches into the ideal regime (Default behavior).

#### Forcing a Specific Strategy
To bypass the automatic dispatcher and force a specific algorithm, append the corresponding flag before the integer list:

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium \$(shuf -i 1-100 -n 100)
```

#### Running the Performance Benchmark (`--bench`)
The program includes an advanced performance tracking engine. Adding the `--bench` flag outputs analytical metrics directly to the Standard Error (`stderr`), while keeping the actual instruction stream clean on the Standard Output (`stdout`).

Execute a benchmark test by routing the execution data:

```bash
ARG="4 67 3 87 23"; ./push_swap --bench --adaptive \$ARG
```

The benchmark evaluation outputs the following metrics to `stderr`:
1.  **Computed Disorder:** The precise initial chaos percentage of the stack calculated before operations start.
2.  **Strategy Details:** The explicit name of the chosen strategy and its theoretical complexity model.
3.  **Total Operation Cost:** The aggregated sum of all generated operations.
4.  **Operational Profile:** An exact breakdown counter for each separate instruction type (`sa`, `pa`, `ra`, `rra`, etc.).

To hide the output instruction stream entirely and analyze only the diagnostic block, pipe `stdout` to a null route or verify via the internal validator check:

```bash
shuf -i 0-9999 -n 100 > args.txt
./push_swap --bench \$(cat args.txt) > /dev/null
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

The core architecture of push_swap is built around a centralized dynamic dispatcher located in main.c. Upon validating and parsing the integer inputs, the program evaluates the total capacity of the stack to assign the most efficient sorting pipeline. The program manages memory through a strict tracking architecture where instructions are recorded into an internal operations list (t_op) to be processed, combined, and compressed by a dedicated post-processor before being pushed onto the standard output via write calls.

### Complexity Model & Big-O Constraints
In accordance with the project requirements, all stated complexity classes reflect the cost measured strictly in the **number of generated Push_swap operations**, rather than theoretical array-based operations.

### 1. Simple Sort Framework (O(n²))
For small data volumes (sets containing up to 5 elements), the application invokes the `simple_sort` infrastructure to minimize operations deterministically.

*   **Three Elements (`sort_three`):** The engine reads the values of the first three nodes. It applies a hardcoded decision tree using conditional relational checks. By evaluating whether `first > second`, `second > third`, or `first > third`, it maps the state to a precise sequence of `sa`, `ra`, or `rra`. This achieves a complete sort within a strict maximum upper bound of 2 operations.
*   **Four to Five Elements (`simple_sort`):** The routine runs a loop until exactly 3 elements remain in stack a. In each iteration, it calls `find_min_value` to locate the smallest integer and `get_position` to find its distance from the top node. It then invokes an auxiliary routine, `bring_min_to_top`. If the target node is in the upper half of the stack (`pos <= size / 2`), it pushes iterative `ra` instructions; otherwise, it executes `rra` instructions. Once the minimum element reaches the apex, it is pushed to stack b via `pb`. After sorting the remaining 3 elements using `sort_three`, the engine safely recovers the stack by pushing all elements back with `pa`.

### 2. Medium Sort Framework (O(n√n))
For mid-sized data sets (optimized specifically for 100 elements), the system executes a chunk-based partitioning scheme inside `medium_sort.c`.

*   **Pre-Sorting Rank Pass (`rank_stack`):** Before any stack mutation occurs, the engine initializes a dual-pointer loop that compares every node's content against the rest of the stack. It increments a counter for every element that contains a smaller value. This counter is saved into the node's `rank` field. This effectively normalizes any raw input (including negative numbers and large gaps) into sequential indices from `0` to `N-1`.
*   **Chunk Partitioning & Sandglass Distribution (`push_chunks_to_b`):** The algorithm calculates an optimized chunk window size dynamically using a square root approximation (`ft_int_sqrt(size) * 3`). It maintains an execution index variable `i`. Stack a is evaluated row by row within a while loop:
    *   If the current top node's rank is less than or equal to `i`, it falls into the core chunk boundary. It is pushed to stack b (`pb`) and `i` is incremented.
    *   If the rank is less than or equal to `i + chunk_size`, it falls into the extended chunk boundary. It is pushed to stack b (`pb`), but immediately followed by a `rb` rotation. This creates a "sandglass" effect, shifting smaller values to the bottom of stack b and keeping medium values near the top. This step drastically reduces future rotation costs.
    *   If the element does not fit either boundary, it is rotated to the back via `ra`.
*   **Retrieval Loop (`bring_max_to_top`):** Once stack a is entirely exhausted, stack b is systematically emptied in descending order. The loop determines the absolute maximum rank remaining (`stack_b->size - 1`) and calls `get_max_index_pos`. It applies the closest rotation path (`rb` or `rrb`) to pivot the maximum element to the top before pulling it back to stack a using `pa`, resulting in a perfectly ordered stack a.




### Complex

### Adapting


### Theoretical Complexity Classes per Algorithm

| Algorithm | Big-O Target (Operation Cost) | Architectural Bounds |
|-----------|-------------------------------|----------------------|
| `simple_sort` | O(n²) | Hardcoded sorting up to 3 nodes; structural min-extraction for 4-5 nodes. |
| `medium_sort` | O(n√n) | Chunk-based partitioning using √n total blocks with automated post-processing optimization. |

### Performance Benchmarks
To fulfill the project validation targets, the following maximum operation constraints are verified during testing:

| Input Volume | Passing Limit | Good Performance | Excellent Performance |
|--------------|---------------|------------------|-----------------------|
| **100 Random Numbers** | < 2000 ops | < 1500 ops | < 700 ops |
| **500 Random Numbers** | < 12000 ops | < 8000 ops | < 5500 ops |

------------------------------
## Team Contributions
As required by the group project guidelines, both learners have contributed meaningfully to the codebase and thoroughly understand the architecture:
*   **Sturuvek:** Implemented the complete input parsing system, string-to-integer conversion routines, input duplication validation, stack data initializations, the O(n log n) complex sorting infrastructure (Radix Sort), and the real-time operational performance benchmarking engine (`--bench`).
*   **ebroeker:** Engineered the zirkular-verkettete Stack-Infrastruktur, the O(n²) baseline simple sorting strategy, the O(n√n) chunk-based `medium_sort` framework, mathematical index ranking algorithms, and the double-pointer operation optimizer pipeline.

## Resources & AI Usage
### Project Documentation & References
*   Donald Knuth: *The Art of Computer Programming, Volume 3: Sorting and Searching* (Algorithmic scaling and complexity analysis).
*   42 Network Project Subject Guidelines (Disorder metric configurations and execution requirements).

### AI Tool Implementation Disclosure
In fulfillment of the 42 AI usage policy, large language models were utilized during development for the following specific workflows:
1.  **Refactoring and Code Quality:** Assisting in structural variable naming transitions (such as indexing definitions) and splitting long structural pipelines into multiple compliant modules to satisfy strict 25-line-per-function restrictions.
2.  **Formatting and Code Style (Norminette Compliance):** Correcting tabulator and whitespace formatting mismatches, optimizing logical line-breaks below the 80-character maximum, and restructuring nested C-conditional branching blocks into compact execution profiles.
3.  **Documentation Drafting:** Scaffolding structural templates and proofreading narrative summaries inside this README file to accurately reflect the technical choices implemented throughout our custom repository.

## Testing
 - Checker_linux

