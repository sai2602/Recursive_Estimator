#pragma once
#include <iostream>
#include<chrono>
#include<map>
#include <cassert>

typedef std::chrono::time_point<std::chrono::steady_clock> chrono_time;

class Recursive_Estimator {
protected:
	std::map<int64_t, int64_t> elements;

public:
	int64_t Input_Number;

	chrono_time start_time;

	Recursive_Estimator();

	bool power_of_2(int64_t number);

	void check_number_validity();

	int64_t evaluate(int64_t param);

	void read_input_number();

	void start_timer();

	void elapsed_time();
};
