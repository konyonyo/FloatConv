#include "floatx.hpp"
#include <iostream>
#include <string>
#include <sstream>

void print_help() {
  std::cout << "Please input <from> <to> <value>. (e.g. fp64 hex 1.0)" << std::endl;
  std::cout << "(<from>, <to>) should be one of the following patterns." << std::endl;
  std::cout << "(bf16, hex), (fp16, hex), (fp32, hex), (fp64, hex)," << std::endl;
  std::cout << "(hex, bf16), (hex, fp16), (hex, fp32), (hex, fp64)" << std::endl;
}

int main() {
  print_help();
  std::string from;
  std::string to;
  std::string value_str;
  std::cin >> from >> to >> value_str;

  double value;

  if (from == "bf16" && to == "hex") {
    std::bitset<16> bits = flx::detail::get_fullbit_representation_BS<8,7>(std::stod(value_str));
    std::cout << std::hex << bits.to_ulong() << std::endl;
  } else if (from == "fp16" && to == "hex") {
    std::bitset<16> bits = flx::detail::get_fullbit_representation_BS<5,10>(std::stod(value_str));
    std::cout << std::hex << bits.to_ulong() << std::endl;
  } else if (from == "fp32" && to == "hex") {
    std::bitset<32> bits = flx::detail::get_fullbit_representation_BS<8,23>(std::stod(value_str));
    std::cout << std::hex << bits.to_ulong() << std::endl;
  } else if (from == "fp64" && to == "hex") {
    std::bitset<64> bits = flx::detail::get_fullbit_representation_BS<11,52>(std::stod(value_str));
    std::cout << std::hex << bits.to_ulong() << std::endl;
  } else if (from == "hex" && to == "bf16") {
    uint16_t x;
    std::stringstream ss;
    ss << std::hex << value_str;
    ss >> x;
    std::bitset<16> bits(x);
    std::cout << std::fixed << flx::detail::construct_number<8,7>(bits) << std::endl;
  } else if (from == "hex" && to == "fp16") {
    uint16_t x;
    std::stringstream ss;
    ss << std::hex << value_str;
    ss >> x;
    std::bitset<16> bits(x);
    std::cout << std::fixed << flx::detail::construct_number<5,10>(bits) << std::endl;
  } else if (from == "hex" && to == "fp32") {
    uint32_t x;
    std::stringstream ss;
    ss << std::hex << value_str;
    ss >> x;
    std::bitset<32> bits(x);
    std::cout << std::fixed << flx::detail::construct_number<8,23>(bits) << std::endl;
  } else if (from == "hex" && to == "fp64") {
    uint64_t x;
    std::stringstream ss;
    ss << std::hex << value_str;
    ss >> x;
    std::bitset<64> bits(x);
    std::cout << std::fixed << flx::detail::construct_number<11,52>(bits) << std::endl;
  } else {
    std::cout << "Error" << std::endl;
    print_help();
    return 1;
  }

  return 0;
}
