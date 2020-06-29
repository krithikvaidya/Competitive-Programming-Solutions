#include <tuple>
#include <bits/stdc++.h>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using namespace std;

struct Rect {
  int x, y, width, height;
};

bool operator==(const Rect& r1, const Rect& r2) {
  return std::tie(r1.x, r1.y, r1.width, r1.height) ==
         std::tie(r2.x, r2.y, r2.width, r2.height);
}


Rect IntersectRectangle(const Rect& r1, const Rect& r2) {
  
  Rect min_x = min (r1.x, r2.x) == r1.x ? r1 : r2;
  Rect max_x = (min_x == r1) ? r2 : r1;
  Rect min_y = min (r1.y, r2.y) == r1.y ? r1 : r2;
  Rect max_y = (min_y == r1) ? r2 : r1;

  Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.width = -1;
  rect.height = -1;

  if (min_x.x + min_x.width >= max_x.x)
  {
    if (min_y.y + min_y.height >= max_y.y)
    {

      rect.x = max_x.x;
      rect.y = max_y.y;
      rect.width = min (min_x.x + min_x.width, max_x.x + max_x.width) - max_x.x;
      rect.height = min (min_y.y + min_y.height, max_y.y + max_y.height) - max_y.y;

    }
  }

  return rect;

  // bool flag = true;
  // if (r1.y > r2.y + r2.height || r1.y + r1.height < r2.y)
  //   flag = false;  // y-disjoint
  // if (r1.x > r2.x + r2.width || r1.x + r1.width < r2.x)
  //   flag = false;  // x-disjoint

  // Rect rect;
  // rect.x = 0;
  // rect.y = 0;
  // rect.width = -1;
  // rect.height = -1;

  // if(flag)
  // {
  //   if(r1.y < r2.y)
  //   {
  //     rect.y = r2.y;
  //   }
  //   else
  //   {
  //     rect.y = r1.y;
  //   }

  //   if(r1.x < r2.x)
  //     rect.x = r2.x;
  //   else
  //   {
  //     rect.x = r1.x;
  //   }

  //   rect.height = min((r1.y + r1.height - rect.y), (r2.y + r2.height - rect.y));
  //   rect.width = min((r1.x + r1.width - rect.x), (r2.x + r2.width - rect.x));

  // }

  // return rect;
}


namespace test_framework {
template <>
struct SerializationTrait<Rect> : UserSerTrait<Rect, int, int, int, int> {
  static std::vector<std::string> GetMetricNames(const std::string& arg_name) {
    return {FmtStr("height({})", arg_name), FmtStr("width({})", arg_name)};
  }

  static std::vector<int> GetMetrics(const Rect& x) {
    return {x.height, x.width};
  }
};
}  // namespace test_framework

std::ostream& operator<<(std::ostream& out, const Rect& r) {
  return PrintTo(out, std::make_tuple(r.x, r.y, r.width, r.height));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"r1", "r2"};
  return GenericTestMain(args, "rectangle_intersection.cc",
                         "rectangle_intersection.tsv", &IntersectRectangle,
                         DefaultComparator{}, param_names);
}
