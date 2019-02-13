#include "mintest.h"

int add_nums(int x, int y){
      return x+y;
}

_Bool test_0(){
      return add_nums(0, 0) == 0;
}

_Bool test_1(){
      return add_nums(5, 9) == 14;
}

int main(){
      test_container tc = tc_setup();
      tc_add_test(&tc, &test_0, "addition test 0");
      tc_add_test(&tc, &test_1, "addition test 1");
      tc_run(tc);
      tc_free(&tc);
      return 0;
}
