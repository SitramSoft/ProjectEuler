CC :=gcc
CFLAGS :=
LDFLAGS :=-lm
C_EXECUTABLE :=$(C_SOURCES:.c=)
ALL_TARGETS := 0001 0002 0003 0004 0005 0006 0007 0008 0009 0010 0011 0012 0013 0014 0015 template
 
all: $(ALL_TARGETS)

0001:0001_multiple_of_3_and_5.c
	$(CC) $< -Wall -o $@

0002:0002_even_fibonacci_numbers.c
	$(CC) $< -Wall -o $@

0003:0003_larget_prime_factor.c
	$(CC) $< -Wall -o $@

0004:0004_largest_palindrome_product.c
	$(CC) $< -Wall -o $@

0005:0005_smallest_multiple.c
	$(CC) $< -Wall -o $@

0006:0006_sum_square_difference.c
	$(CC) $< -Wall -o $@

0007:0007_10001st_prime.c
	$(CC) $< -Wall -lm -o $@

0008:0008_largest_produc_in_series.c
	$(CC) $< -Wall -o $@

0009:0009_special_pythagorean_triplet.c
	$(CC) $< -Wall -o $@

0010:0010_sumation_of_primes.c
	$(CC) $< -Wall -lm -o $@

0011:0011_largest_product_in_a_grid.c
	$(CC) $< -Wall -o $@

0012:0012_highly_divisible_triangular_number.c
	$(CC) $< -Wall -lm -o $@

0013:0013_large_sum.c
	$(CC) $< -Wall -lm -o $@

0014:0014_longest_collatz_sequence.c
	$(CC) $< -Wall -lm -o $@

0015:0015_lattice_paths.c
	$(CC) $< -Wall -lm -o $@

template: c_program_template.c
	$(CC) $< -Wall -o $@

clean:
	rm -rf $(ALL_TARGETS)