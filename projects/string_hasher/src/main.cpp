#include <charconv>
#include <cstring>
#include <print>
#include <system_error>
int encode(int number, int key) {
  return number ^ key;
}
int decode(int number, int key) {
  return number ^ key;
}
int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::println("Incorrect use!");
    std::println("Usage: ./hasher <number_to_hash> <key> <decode/uncode(0/1)>");
    return -1;
  }
  char *number_to_hash_c = argv[1];
  char *key_c = argv[2];
  char *mode_c = argv[3];
  int number_to_hash;
  int key;
  int mode;
  auto [ptr1, ec1] = std::from_chars(number_to_hash_c, number_to_hash_c + std::strlen(number_to_hash_c), number_to_hash);
  auto [ptr2, ec2] = std::from_chars(key_c, key_c + std::strlen(key_c), key);
  auto [ptr3, ec3] = std::from_chars(mode_c, mode_c+ std::strlen(mode_c), mode);
  if (ec1 != std::errc{} || ec1 != std::errc{} || ec3 != std::errc{}) {
    std::println("Invalid parameters");
    return -2;
  }
  if (mode == 0) {
    std::println("Your number encoded is: {}", encode(number_to_hash, key));
  } else if (mode == 1) {
    std::println("Your number decoded is: {}", decode(number_to_hash, key));
  } else {
    std::println("Mode not supported");
  }
  return 0;
}
