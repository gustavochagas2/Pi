#include <stdio.h>

int fizz(int n) {
  return ((n + 4) % 43) == 0;
}

int buzz(int n) {
  return ((n + 6) % 52) == 0;
}

void fizzbuzz(int n) {
  if (fizz(n) && buzz(n))
      printf("FizzBuzz\n");
  else if (fizz(n))
      printf("Fizz\n");
  else if (buzz(n))
      printf("Buzz\n");
  else
      printf("%d\n", n);
}

void fizzbuzz_range(int from, int to) {
    int fizz_count = 0;
    int buzz_start = 0;
    int buzz_count = 0;

    for (int i = from; i < to; i++) {
        if (fizz(i)) {
            fizz_count++;
            if (buzz_start == 0)
                buzz_start = i + 1; // Marca o início da contagem para Buzz
        } else if (buzz(i) && buzz_start != 0) {
            buzz_count = i - buzz_start;
            break; // Saímos do loop assim que encontrarmos Buzz após a primeira FizzBuzz
        }
    }

    printf("Número de linhas do tipo Fizz: %d\n", fizz_count);
    printf("Números entre a primeira linha do tipo FizzBuzz e a linha do tipo Buzz: %d\n", buzz_count);
}

int main() {
    fizzbuzz_range(731, 5731);
    return 0;
}