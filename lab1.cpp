#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv) {
    const int count = 10000000;     ///< Number of array elements
    const int threads = 16;         ///< Number of parallel threads to use
    const int random_seed = 920215; ///< RNG seed

    int* array = 0;                 ///< The array we need to find the max in
    int  max   = -1;                ///< The maximal element

    /* Initialize the RNG */
    srand(random_seed);

    /* Generate the random array */
    array = (int*)malloc(count*sizeof(int));
    for(int i=0; i<count; i++) { array[i] = rand(); }

    double start_time = omp_get_wtime();

    /* Find the maximal element */
    #pragma omp parallel num_threads(threads) shared(array, count) reduction(max: max) default(none)
    {
        #pragma omp for
        for(int i=0; i<count; i++)
        {
            if(array[i] > max) { max = array[i]; };
        }
    }

    double end_time = omp_get_wtime();
    printf("%f\n", end_time - start_time);
    free(array);

    return(0);
}
