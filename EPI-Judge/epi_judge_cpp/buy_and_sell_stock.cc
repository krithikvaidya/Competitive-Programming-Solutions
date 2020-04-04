#include <vector>

#include "test_framework/generic_test.h"
using namespace std;
  
double BuyAndSellStockOnce(const vector<double>& prices) {
  
  // Considering 0 profit in case of decreasing array (buy and sell on same day)

  double min_encountered_price = numeric_limits<double>::max();
  double max_profit = numeric_limits<double>::min();

  for (int i = 0; i < prices.size(); i++)
  {

    if (prices[i] < min_encountered_price)
      min_encountered_price = prices[i] ;

    max_profit = max(max_profit, (prices[i] - min_encountered_price));

  }
  return max_profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
