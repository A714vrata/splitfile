#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FNAME 50
#define LNBUF 255
#define TXBUF 5000

int main() {
  int bufsize = 0;
  int runs = 0;

  char filename[FNAME] = "";
  char lnbuf[LNBUF] = "";

  char *txbuf = malloc(TXBUF);
  if (txbuf == NULL) {
    fprintf(stderr, "Memory allocation failed\nExiting\n");
    return EXIT_FAILURE;
  }

  printf("Enter file name to be split: ");
  scanf("%s", filename);

  FILE *readpoint = fopen(filename, "r");
  if (readpoint == NULL) {
    fprintf(stderr, "Failed to open file %s\nExiting\n", filename);
    return EXIT_FAILURE;
  }

  while (!feof(readpoint)) {
    bufsize = 0;
    txbuf[0] = '\0';

    while (bufsize < TXBUF && fgets(lnbuf, LNBUF, readpoint)) {
      if (bufsize + strlen(lnbuf) >= TXBUF) {
        break;
      }
      strcat(txbuf, lnbuf);
      bufsize += strlen(lnbuf);
    }
    snprintf(filename, FNAME, "section%d.txt", runs + 1);
    FILE *writepoint = fopen(filename, "w");
    if (writepoint == NULL) {
      fprintf(stderr,
              "Failed to create file %s\nPrinting to output instead\n\n\n",
              filename);
      printf("%s", txbuf);
    }
    fprintf(writepoint, "%s", txbuf);
    fclose(writepoint);
    runs++;
  }
  fclose(readpoint);
  free(txbuf);

  return EXIT_SUCCESS;
}
