#include <getopt.h>
#include <stdio.h>

static void read();
static void cli(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  cli(argc, argv);

  return 0;
}

static void read() { printf("meh"); }

static void cli(int argc, char *argv[]) {
  struct option longy[] = {{"grab", no_argument, NULL, 'g'},
                           {"help", no_argument, NULL, 'h'},
                           {"version", no_argument, NULL, 'v'},
                           {"archive", required_argument, NULL, 'a'},
                           {NULL, 0, NULL, 0}};

  while (1) {
    const int opt = getopt_long(argc, argv, "ghva:", longy, NULL);

    if (opt == -1) {
      break;
    }

    switch (opt) {
    case 'g':
      read();
      break;
    case 'a':
      if (optarg) {
        printf("%s", optarg);
      } else {
        printf("provide arguments separated by ,: meh,foo,bar");
      }
      break;
    case 'v':
      printf("0.0.1");
      break;
    case 'h':
      printf("usage");
      break;
    default:
      printf("usage");
    }
  }
}
