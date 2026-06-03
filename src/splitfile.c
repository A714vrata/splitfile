#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_FN 50 //maxsize for output filename
#define SIZE_LNBUF 255 //line buffer max size
#define SIZE_TXBUF 5000 //text file buffer for each split file

int main(int argc, char *argv[]) {
  int bufsize = 0;
  int runs = 0;

  char lnbuf[SIZE_LNBUF] = "";

  char *txbuf = malloc(SIZE_TXBUF); //allocate split file buffer 
  if (txbuf == NULL) {
    fprintf(stderr, "Memory allocation failed\nExiting\n");
    return EXIT_FAILURE;
  }

  if (argc < 2)
  {
    fprintf(
      stderr,
      "Error: Missing argument. Usage %s <filename>\n", argv[0]
    );
    return EXIT_FAILURE;
  }
  else if (argc > 2) {
    fprintf(
      stderr,
      "Error: Too many arguments. Usage %s <filename>\n", argv[0]
    );
    return EXIT_FAILURE;
  }

  /* gets file name from argument 1 */
  char *filename = argv[1];

  FILE *readpoint = fopen(filename, "r"); //open fstream, read input file
  if (readpoint == NULL) {
    fprintf(stderr, "Failed to open file %s\nExiting\n", filename);
    free(txbuf);
    txbuf = NULL;
    return EXIT_FAILURE;
  }

  while (!feof(readpoint)) {
    bufsize = 0;
    txbuf[0] = '\0';

    //read to buffer until 5000 character limit is reached

    while (bufsize < SIZE_TXBUF && fgets(lnbuf, SIZE_LNBUF, readpoint)) {
      if (bufsize + strlen(lnbuf) >= SIZE_TXBUF) {
        break;
      }
      strcat(txbuf, lnbuf);
      bufsize += strlen(lnbuf);
    }
    /* split file into sections
     * create new file per section
     * 5000 char limit per split file
     */
    snprintf(filename, SIZE_FN, "section%d.txt", runs + 1);
    FILE *writepoint = fopen(filename, "w");
    if (writepoint == NULL) {
      fprintf(stderr,
              "Failed to create file %s\nPrinting to output instead\n\n\n",
              filename);
      printf("%s", txbuf);
    } else {
      fprintf(writepoint, "%s", txbuf); // Write file buffer to split file "section"
    }
    fclose(writepoint);
    runs++;
  }
  fclose(readpoint);
  free(txbuf);
  txbuf = NULL;

  return EXIT_SUCCESS;
}
