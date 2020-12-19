#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// POW = Power of 2
// MAX = 2^POW - 1

#ifdef B
#define CHAR '0'
#define POW 1
#define MAX 1
#elif Q
#define CHAR '0'
#define POW 2
#define MAX 3
#elif O
#define CHAR '0'
#define POW 3
#define MAX 7
#elif X
#define CHAR (last <= 9 ? '0' : ('A' - 10))
#define POW 4
#define MAX 15
#endif

#ifdef B2
#define BASE 2
#elif Q2
#define BASE 4
#elif O2
#define BASE 8
#elif X2
#define BASE 16
#else
#define BASE 10
#endif

// Digit Count
static uint8_t dc(uint64_t x) {
	uint8_t c = 1;

	while ((x >>= POW) != 0)
		++c;

	return c;
}

// Number 2 String
static void n2s(uint64_t x, uint8_t n, char s[n + 1]) {
	s[n] = '\0';

	while (n-- != 0) {
		const uint8_t last = x & MAX;
		s[n] = CHAR + last;
		x >>= POW;
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "%s: Expected 1 argument got %d\n", argv[0], argc - 1);
		return 1;
	}

	char* end;

	errno = 0;
	long int l = strtol(argv[1], &end, BASE);

	#define E ERANGE
	#define LMAX LONG_MAX
	#define LMIN LONG_MIN

	if ((errno == E && (l == LMAX || l == LMIN)) || (errno != 0 && l == 0)) {
		perror(argv[0]);
		return 2;
	}

	if (*end != '\0') {
		fprintf(stderr, "%s: Found unexpected characters\n", argv[0]);
		return 3;
	}

	if (end == argv[1]) {
		fprintf(stderr, "%s: No digits were found\n", argv[0]);
		return 4;
	}

	if (l < 0) {
		fprintf(stderr, "%s: Expected positive input\n", argv[0]);
		return 5;
	}

	uint64_t x = l;

	uint8_t n = dc(x);

	char s[n + 1];

	n2s(x, n, s);

	puts(s);

	return 0;
}
