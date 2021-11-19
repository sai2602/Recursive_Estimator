#include "includes.h"


int main(int argc, char* argv[]) {

	Recursive_Estimator my_estimator;

	my_estimator.read_input_number();

	my_estimator.check_number_validity();

	my_estimator.start_timer();

	std::cout << "The result is: " << my_estimator.evaluate(my_estimator.Input_Number) << std::endl;
	
	my_estimator.elapsed_time();

	return 0;
}


int64_t Recursive_Estimator::evaluate(int64_t param) {
	
	if (this->power_of_2(param)) {
		return 1;
	}
	else if (this->elements.count(param)) {
		return this->elements.at(param);
	}

	this->elements[param] = param % 2 == 0 ? this->evaluate(param / 2) : this->evaluate((param - 1) / 2) + this->evaluate(((param - 1) / 2) - 1);

	return this->elements.at(param);
}


bool Recursive_Estimator::power_of_2(int64_t number) {

	if (!(number & (number - 1))) {
		return true;
	}
	return false;
}


void Recursive_Estimator::check_number_validity() {

	assert(this->Input_Number >= 0 && this->Input_Number <= INT64_MAX);
	std::cout << "Valid number entered!!!" << std::endl;
}


Recursive_Estimator::Recursive_Estimator() {

	this->Input_Number = 0;
	this->elements[0] = 1;
	this->elements[1] = 1;
}

void Recursive_Estimator::read_input_number() {
	std::cout << "Enter the input number(0 to " << std::to_string(INT64_MAX) << "): ";
	std::cin >> this->Input_Number;
}

void Recursive_Estimator::start_timer() {

	start_time = std::chrono::steady_clock::now();
}

void Recursive_Estimator::elapsed_time() {

	if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - this->start_time).count() != 0)
		std::cout << "Elapsed Time(ms): " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - this->start_time).count() << std::endl;
	else
		std::cout << "Elapsed Time(\xe6s): " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - this->start_time).count() << std::endl;
}

