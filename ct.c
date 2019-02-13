/* mintest OR [a][s][h]unit
 *            ash saves hours
 */
#include "ct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct test_container* tc_init(struct test_container* tc){
      if(!tc)tc = malloc(sizeof(struct test_container*));
      tc->n = 0;
      tc->cap = 10;
      tc->tests = malloc(sizeof(struct test)*tc->cap);
      return tc;
}

struct test_container tc_setup(){
      struct test_container tc;
      tc_init(&tc);
      return tc;
}

// tests should be int(void)
void tc_add_test(struct test_container* tc, _Bool (*tst)(void), char* label){
      if(tc->n == tc->cap){
            tc->cap *= 2;
            struct test* tmp_t = malloc(sizeof(struct test)*tc->cap);
            memcpy(tmp_t, tc->tests, sizeof(struct test)*tc->n);
            free(tc->tests);
            tc->tests = tmp_t;
      }
      tc->tests[tc->n].function = tst;
      strncpy(tc->tests[tc->n++].label, label, 49);
}

void tc_run(struct test_container tc){
      _Bool ret = 0;
      for(int i = 0; i < tc.n; ++i){
            if((ret = tc.tests[i].function())){
                  printf("fuck yeah we passed test with label %s\n", tc.tests[i].label);
            }
            else puts("we failed");
      }
      printf("got %i\n", ret);
}

void tc_free(struct test_container* tc){
      free(tc->tests);
}

_Bool test_0(){
      return 1+1 == 2;
}

int main(){
      struct test_container tc = tc_setup();
      tc_add_test(&tc, &test_0, "addition test");
      tc_run(tc);
      tc_free(&tc);
      return 0;
}
