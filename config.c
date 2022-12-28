#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>

void read_file() {}

void rea_file() {
  FILE *ptr;
  /* char buffer[]; */
  char ch;

  ptr = fopen("/da/personal/lar/.config/qas/c.json", "r");

  if (NULL == ptr) {
    printf("file can't be opened \n");
  }

  do {
    ch = fgetc(ptr);
  } while (ch != EOF);

  fclose(ptr);
}

/* void parse_array(cJSON *array) { */
/*   cJSON *item = array ? array->child : 0; */

/*   while (item) { */
/*     cJSON *name = cJSON_GetObjectItem(item, "name"); */
/*     cJSON *index = cJSON_GetObjectItem(item, "index"); */
/*     cJSON *optional = cJSON_GetObjectItem(item, "optional"); */

/*     item = item->next; */
/*   } */
/* } */
