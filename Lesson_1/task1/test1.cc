#include <gtest/gtest.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
- 1 -
    2 5 3 -
    4 6

    TEST(Read, default) {
  int x1 = -1;
  int y1 = -2;
  int x2 = 5;
  int y2 = 3;
  int x = -4;
  int y = 6;
  Read EXPECT_EQ(process())
}
