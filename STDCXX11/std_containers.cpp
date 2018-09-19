#include <common.h>

// containers
#include <vector>

// operations on containers, like sorting
#include <algorithm>

// a type of things that we are going to put in containers
class Cable
{
public:
	// we need a default constructor, since most conntainers use it
	Cable()
	{
		length__ = 0.000001;
	}

	Cable(double L) :
		length__(L)
	{}

	double getLength()
	{
		return length__;
	}

protected:
	double length__;
};

// declaration of auxiliary black-box function to have a 5-chars random string
std::string generate5CharsRandomString();

// declaration of auxiliary function to compare two cables
bool isAlongerThanB(std::pair<std::string, Cable>& __A, std::pair<std::string, Cable>& __B)
{
	return( __A.second.getLength() > __B.second.getLength() );
}

int main()
{
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	int n_tubes = 10;
	std::vector<Cable> cable_chunks;

	// sets the capacity, but not the size as there are no elements within.. reserves memory
	cable_chunks.reserve(50);

	// sets the actual size of elements, uses default construction, so it can't be used with Cable above
	cable_chunks.resize(1); // adds a cable of length 0.000001 as in default constructor

	std::cout << std::endl << "Size of cable_chunks is " << cable_chunks.size() << std::endl; // should be 1
	std::cout << "Capacity of cable_chunks is " << cable_chunks.capacity() << std::endl; // should be 50

	// keep adding chunks of random length between 0 and 1
	for(int i = 0; i < n_tubes; i++)
		cable_chunks.push_back( Cable( static_cast<double>(std::rand())/RAND_MAX ) );

	// assign codes to the chunks
	std::cout << std::endl << "Unordered cable chunks with code: " << std::endl;
	std::vector< std::pair<std::string, Cable> > chunk_codes;
	for(auto c : cable_chunks)
	{
		std::string code = generate5CharsRandomString();
		double length = c.getLength();
		std::cout << "\t" << code << "\t" << length << std::endl;

		// save the pair of code and cable chunk in the set to sort them further
		chunk_codes.push_back( std::make_pair(code, c) );
	}

	// order by length
	std::sort( chunk_codes.begin(), chunk_codes.end(), isAlongerThanB );

	std::cout << std::endl << "Ordered by length cable chunks with code: " << std::endl;
	for(auto c: chunk_codes)
		std::cout << "\t" << c.first << "\t" << c.second.getLength() << std::endl;
	std::cout << std::endl;

	// sum all lengths and measure time
	auto tic = std::chrono::high_resolution_clock::now();
	double sum_of_lengths = 0;
	for(auto c : cable_chunks)
		sum_of_lengths = sum_of_lengths + c.getLength();
	auto toc = std::chrono::high_resolution_clock::now();

	auto dt = 1.e-9*std::chrono::duration_cast<std::chrono::nanoseconds>( toc - tic ).count();

	std::cout << "All lenghts sumed in " << dt << " nanoseconds, giving " << std::endl;
	std::cout << "Result: " << sum_of_lengths << std::endl << std::endl;

	return 0;
}


// definition of auxiliary black-box function to have a 5-chars random string
std::string generate5CharsRandomString()
{
	static auto& chr_set = "0123456789"
	"abcdefghijklmnopqrstuvwxyz"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	thread_local static std::mt19937 rg{std::random_device{}()};
	thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chr_set) - 2);

	std::string::size_type length = 5;
	std::string s;

	s.reserve(length);

	while(length--)
		s += chr_set[pick(rg)];

	return s;
}
