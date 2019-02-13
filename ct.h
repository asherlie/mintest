struct test{
      _Bool (*function)(void);
      char label[50];
};

typedef struct test_container{
      char label[50];
      int n, cap;
      struct test* tests;
}test_container;

test_container tc_setup();
void tc_add_test(test_container* tc, _Bool (*function)(void), char* label);
void tc_run(test_container tc);
void tc_free(test_container* tc);
