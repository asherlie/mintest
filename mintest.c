/* mintest OR [a][s][h]unit
 *            ash saves hours
 */
#include "mintest.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

test_container* tc_init(test_container* tc){
      if(!tc)tc = malloc(sizeof(test_container*));
      tc->n = 0;
      tc->cap = 10;
      tc->tests = malloc(sizeof(struct test)*tc->cap);
      return tc;
}

test_container tc_setup(){
      test_container tc;
      tc_init(&tc);
      return tc;
}

// tests should be int(void)
void tc_add_test(test_container* tc, _Bool (*tst)(void), char* label){
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

void pass_print(char* label){
      printf("test: \"%s\" %sPASSED%s\n", label, ANSI_GRE, ANSI_NON);
}

void fail_print(char* label){
      printf("test: \"%s\" %sFAILED%s\n", label, ANSI_RED, ANSI_NON);
}

void tc_run(test_container tc){
      _Bool ret = 0;
      for(int i = 0; i < tc.n; ++i){
            if((ret = tc.tests[i].function())){
                  pass_print(tc.tests[i].label);
            }
            else fail_print(tc.tests[i].label);
      }
}

void tc_free(test_container* tc){
      free(tc->tests);
}
