#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int totalWeight = 0;
  vector<double> div(values.size());

  for (int i = 0; i < weights.size(); ++i)
  {
    div[i] = (double)values[i]/(double)weights[i];
  }  

  for (int i = 0; i < div.size(); ++i)
  {
  	auto biggest = std::max_element(std::begin(div), std::end(div));
  	auto biggestIndex = std::distance(std::begin(div), biggest);

  	if (capacity >= weights[biggestIndex])
    {
      value = value + (*biggest * (double)weights[biggestIndex]);
      capacity = capacity - weights[biggestIndex];
      div[biggestIndex] = 0;
    } else {
      value = value + (*biggest * (double)capacity);
      capacity = capacity - capacity;
      div[biggestIndex] = 0;
    }
  }
  return value;
}


int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}