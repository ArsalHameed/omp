# omp
This is the assignment Q1 on the topic openmp
Report on OpenMP Parallel Matrix Operations

1. Introduction

This report compares the performance of different parallelization strategies in OpenMP for matrix operations. The operations performed include matrix addition and matrix multiplication using:

Coarse-grained vs. fine-grained parallelism

Static, dynamic, and guided scheduling

The execution times for each approach have been recorded to evaluate their efficiency.

2. Parallelization Strategies

2.1 Coarse-Grained vs. Fine-Grained Parallelism

Coarse-Grained Parallelism:

Assigns large chunks of work to threads.

Threads complete larger sections before synchronization.

Less synchronization overhead but potential load imbalance.

Fine-Grained Parallelism:

Divides tasks into smaller chunks.

Threads synchronize more frequently.

Better load balancing but higher synchronization overhead.

2.2 OpenMP Scheduling Strategies

Static Scheduling:

Pre-assigns equal-sized work chunks to threads.

Low scheduling overhead but may cause load imbalance.

Dynamic Scheduling:

Assigns tasks dynamically as threads finish previous tasks.

Better load balancing but higher scheduling overhead.

Guided Scheduling:

Similar to dynamic but reduces chunk size over time.

A balance between load balancing and scheduling overhead.

3. Execution Time Analysis

3.1 Coarse-Grained vs. Fine-Grained Parallelism

Operation

Coarse-Grain Execution Time (s)

Fine-Grain Execution Time (s)

Matrix Multiplication

0.00048871

0.000170231

Matrix Addition

8.5702e-05

3.5278e-05

Analysis:

Fine-grained parallelism outperforms coarse-grained in both addition and multiplication.

Fine-grained has better load balancing, leading to lower execution times.

Coarse-grained approach suffers from imbalance where some threads finish early and remain idle.

3.2 OpenMP Scheduling Strategies for Matrix Multiplication

Scheduling Type

Execution Time (s)

Static

0.000213164

Dynamic

4.8263e-05

Guided

4.2388e-05

Analysis:

Dynamic and Guided scheduling significantly outperform static scheduling.

Static scheduling causes load imbalance, leading to longer execution times.

Dynamic scheduling provides better load distribution, minimizing idle time.

Guided scheduling has the best performance as it optimally reduces chunk size over time.

4. Conclusion

Fine-Grained parallelism is generally more efficient than coarse-grained, especially for operations requiring better load balancing.

Dynamic and Guided scheduling outperform Static scheduling, with Guided scheduling achieving the best balance between overhead and load balancing.

For future implementations, using a fine-grained approach with guided scheduling is recommended for achieving the best performance.

Recommendation: If load imbalance is a concern, use fine-grained parallelism with guided scheduling for better efficiency.

