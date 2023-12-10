#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "util.h"

// Assuming the Process structure is defined like this:
typedef struct {
    int pid;
    int arrival_time;
    int priority;
} Process;

/**
 * Signature for a function pointer that can compare.
 * You need to cast the input into its actual 
 * type and then compare them according to your
 * custom logic.
 */
typedef int (*Comparer)(const void *a, const void *b);

/**
 * Compares two processes based on priority and arrival time.
 */
int my_comparer(const void *a, const void *b) {
    const Process *processA = (const Process *)a;
    const Process *processB = (const Process *)b;

    // Sort based on priority in descending order
    if (processA->priority != processB->priority) {
        return processB->priority - processA->priority;
    }

    // If priorities are equal, sort based on arrival time in ascending order
    return processA->arrival_time - processB->arrival_time;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./func-ptr <input-file-path>\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error: Invalid filepath\n");
        return 1;
    }

    // Assuming P_SIZE is defined somewhere in your code.
    // If not, replace it with the actual size of your processes array.
    Process *processes = parse_file(input_file, P_SIZE);

    if (!processes) {
        fprintf(stderr, "Error: Failed to parse the input file\n");
        fclose(input_file);
        return 1;
    }

    Comparer process_comparer = &my_comparer;

    qsort(processes, P_SIZE, sizeof(Process), process_comparer);

    for (int i = 0; i < P_SIZE; i++) {
        printf("%d (%d, %d)\n", processes[i].pid, processes[i].priority, processes[i].arrival_time);
    }

    free(processes);
    fclose(input_file);

    return 0;
}
