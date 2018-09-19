#include <common.h>

#include <thread>
#include <vector>
#include <future>

// Do costly operation in async (promise/future)
uint64_t square(uint64_t x, int time_cost)
{
	// wait radonmly to emulate a costly operation
	std::this_thread::sleep_for(std::chrono::seconds( time_cost ) );
	std::cout << "Thread " << x << " finished" << std::endl;
	return x*x;
}

int main()
{
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	auto tic = std::chrono::high_resolution_clock::now();

	uint64_t N = 10;
	std::vector< std::future<uint64_t> > tasks(N);
	for(int i = 0; i < N; i++)
	{
		int time_cost = std::round( 20*static_cast<double>( std::rand()) /RAND_MAX );
		std::cout << "Thread " << i+1 << " requires " << time_cost << " seconds to process, starting..." << std::endl;
		tasks.at(i) = std::async(std::launch::async, &square, i+1, time_cost);
	}

	// sum all the futures
	// it'll wait for the promises, so wait for everyone to finish
	uint64_t result = 0;
	for(auto& t : tasks)
	{
		result += t.get();
	}

	auto toc = std::chrono::high_resolution_clock::now();
	auto dt = 1.e-9*std::chrono::duration_cast<std::chrono::nanoseconds>(toc - tic ).count();

	// sum of all squares of first n numbers
	std::cout << "Finished, result = " << result << std::endl;
	// Check that the total time is less than the summ of running all threads in series
	// it actually equals the longest process time plus a little bit due other small operations
	std::cout << "Total time (seconds) = " << dt << std::endl;

	return 0;
}
