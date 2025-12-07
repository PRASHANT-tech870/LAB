#include <sys/time.h>
#include <stdio.h>
#include <openacc.h>
// To actually run this on gpu we need to compile it with nvidia hpc sdk

#define SIZE 1000

double A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE], D[SIZE][SIZE];

int main()
{
    int i, j, k;
    struct timeval time;
    double t1, t2;
    double temp;
    printf("OpenACC device type: %s\n", acc_get_device_type() == acc_device_nvidia ? "NVIDIA GPU" : "Host/CPU");
    printf("Number of OpenACC devices: %d\n", acc_get_num_devices(acc_device_nvidia));

    // Initialize matrices A and B
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            A[i][j] = (double)(i + j);
            B[i][j] = (double)(i - j);
            C[i][j] = (double)0.0;
            D[i][j] = (double)0.0;
        }
    }

    // Time stamp t1
    gettimeofday(&time, NULL);
    t1 = time.tv_sec + time.tv_usec / 1000000.0;

    // Perform matrix multiplication

#pragma acc data copyin(A, B) copy(C)

#pragma acc kernels

#pragma acc loop tile(32, 32)

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            temp = 0.0;
#pragma acc loop reduction(+ : temp)
            for (k = 0; k < SIZE; k++)
            {
                temp += A[i][k] * B[k][j];
            }
            C[i][j] = temp;
        }
    }

    // Time stamp t2
    gettimeofday(&time, NULL);
    t2 = time.tv_sec + time.tv_usec / 1000000.0;

    // Print the time taken
    printf("Time: %f seconds taken by OpenACC\n", t2 - t1);

    gettimeofday(&time, NULL);
    t1 = time.tv_sec + time.tv_usec / 1000000.0;
    // Cross check the result by multiplying A and B
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            temp = 0.0;
            for (k = 0; k < SIZE; k++)
            {
                temp += A[i][k] * B[k][j];
            }
            D[i][j] = temp;
        }
    }
    gettimeofday(&time, NULL);
    t2 = time.tv_sec + time.tv_usec / 1000000.0;
    // Compare the two results
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (C[i][j] != D[i][j])
            {
                printf("Error in matrix multiplication at (%d, %d), mismatch: %f %f\n", i, j, C[i][j], D[i][j]);
                return 1;
            }
        }
    }
    printf("Time: %f seconds taken by CPU\n", t2 - t1);

    printf("Matrix multiplication successful\n");
    return 0;
}

// gcc -fopenacc -o dma_mat_mul dma_mat_mul.c
