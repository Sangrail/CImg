// CImgTestConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace cimg_library;
using namespace std;

#ifndef cimg_imagepath
#define cimg_imagepath "img/"
#endif


std::ifstream::pos_type filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}

typedef std::tuple<unsigned char, unsigned char> key_t;

namespace std
{

	template<typename... T>
	struct hash<tuple<T...>>
	{
		size_t operator()(tuple<T...> const& arg) const noexcept
		{
			return boost::hash_value(arg);
		}
	};

}


struct HexCharStruct
{
	unsigned char c;
	HexCharStruct(unsigned char _c) : c(_c) { }
};

inline std::ostream& operator<<(std::ostream& o, const HexCharStruct& hs)
{
	return (o << std::hex << (int)hs.c);
}

inline HexCharStruct hex(unsigned char _c)
{
	return HexCharStruct(_c);
}

struct key_hash : public std::unary_function<key_t, std::size_t>
{
	std::size_t operator()(const key_t& k) const
	{
		return boost::hash_value(k);
	}
};

struct key_equal : public std::binary_function<key_t, key_t, bool>
{
	bool operator()(const key_t& v0, const key_t& v1) const
	{
		return std::get<0>(v0) == std::get<0>(v1) && std::get<1>(v0) == std::get<1>(v1);
	}
};

typedef std::unordered_map<key_t, unsigned long long, key_hash, key_equal> bigram_map_t;
bigram_map_t bigram_map;

std::vector<BYTE> readFile(const char* filename)
{
	// open the file:
	std::ifstream file(filename, std::ios::binary);

	// Stop eating new lines in binary mode!!!
	file.unsetf(std::ios::skipws);

	// get its size:
	std::streampos fileSize;

	file.seekg(0, std::ios::end);
	fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	// reserve capacity
	std::vector<BYTE> vec;
	vec.reserve(fileSize);

	// read the data:
	vec.insert(vec.begin(),
		std::istream_iterator<BYTE>(file),
		std::istream_iterator<BYTE>());

	return vec;
}

bigram_map_t GenerateBiGram(vector<unsigned char> rawbytes)
{
	bigram_map_t biGram;

	if (rawbytes.size() == 0)
	{
		std::stringstream ss;
		ss << "Could not access raw bytes";
		cout << ss.str() << '\n';
		return biGram;
	}

	auto currentByte = std::begin(rawbytes);

	while (true) {
		auto nextByte = std::next(currentByte);

		if (nextByte == std::end(rawbytes)) {
			break;
		}

		auto bigram = std::make_tuple(*currentByte, *nextByte);

		auto got = biGram.find(bigram);

		if (got == biGram.end())
		{
			biGram.insert(std::make_pair(bigram, 1));
		}
		else
		{
			biGram[bigram]++;
		}

		currentByte = nextByte;
	}

	return biGram;
}

void CreateBigramFile(std::string filename, bigram_map_t bigramMap)
{
	if (bigramMap.size() == 0)
		return;

	std::ofstream bigram(filename);

	bigram << "FirstByte_hex,SecondByte_hex,Count" << std::endl;

	for (auto& entry : bigramMap) {

		auto tup = entry.first;
		auto count = entry.second;

		bigram << hex(std::get<0>(tup)) << "," << hex(std::get<1>(tup)) << "," << std::dec << count << "\n";
	}

	bigram.close();
}

int main(int argc, char **argv)
{
	auto filename = argv[1];

	auto data = readFile(filename);
	auto fsize = data.size();

	int width = 256;

	CImgDisplay *disp;
	CImg <unsigned char>img3(&data[0], width, fsize/ width, 1, 1);
	disp = new CImgDisplay(width, fsize / width, ".Text", 100);
	disp->display(img3);

	auto biGram = GenerateBiGram(data);
	CreateBigramFile(".text.csv", biGram);

	CImg <double>biImg( 256, 256, 1, 3);

	double total = 0.0;
	for (auto& entry : biGram) {
		total += entry.second;
	}

	cimg_foroff(biImg, off) { biImg[off] = 0.0f; }    // Equivalent to 'img.fill(0);'

	for (auto& entry : biGram) {

		auto tup = entry.first;
		auto count = (double)entry.second/ total;

		biImg(std::get<0>(tup), std::get<1>(tup)) = count*3000000;
	}

	biImg.display("Bi-Gram Colour");


	CImg <unsigned char>biImgGray(256, 256, 1, 1);

	cimg_foroff(biImgGray, off) { biImgGray[off] = 255; }    // Equivalent to 'img.fill(0);'

	for (auto& entry : biGram) {

		auto tup = entry.first;
		auto count = entry.second;

		biImgGray(std::get<0>(tup), std::get<1>(tup)) = count;
	}

	biImgGray.display("Bi-Gram (grayscale)");

	biImgGray.save_bmp("grayscale.bmp");

	getchar();

    return 0;
}

