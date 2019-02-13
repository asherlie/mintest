struct test{
      //void* function;
      _Bool (*function)(void);
      char label[50];
};

typedef struct test_container{
      char label[50];
      int n, cap;
      struct test* tests;
}test_container;

struct test_container tc_setup();
//void tc_add_test(struct test_container* tc, void* tst, char* label);
void tc_add_test(struct test_container* tc, _Bool (*function)(void), char* label);
void tc_run(struct test_container tc);
void tc_free(struct test_container* tc);
