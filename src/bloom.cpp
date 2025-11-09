#pragma once
#include <bitset>
#include <MurmurHash3.h>
#define bloom_size 320

enum HASH_TYPE
{
  TYPE_1,
  TYPE_2,
  TYPE_3
};

class Bloom
{
  std::bitset<bloom_size> bitArr;

public:
  Bloom() {}

  void insert(const std::string key)
  {

    int ans1 = hash(key, TYPE_1);
    int ans2 = hash(key, TYPE_2);
    int ans3 = hash(key, TYPE_3);

    bitArr[ans2] = 1;
    bitArr[ans1] = 1;
    bitArr[ans3] = 1;

    return;
  }

  bool isPresent(const std::string key)
  {
    int ans1 = hash(key, TYPE_1);
    int ans2 = hash(key, TYPE_2);
    int ans3 = hash(key, TYPE_3);

    return (this->bitArr[ans1] == 1 && this->bitArr[ans2] &&
            this->bitArr[ans3]);
  }

  int hash(const std::string key, HASH_TYPE type)
  {

    uint32_t seed;
    switch (type)
    {
    case TYPE_1:
      seed = 192;
      break;

    case TYPE_2:
      seed = 224;
      break;

    case TYPE_3:
      seed = 446;
      break;
    }

    uint32_t hash_result;

    const void *p = key.c_str();

    MurmurHash3_x86_32(p, key.length(), seed, &hash_result);
    return hash_result % bloom_size;
  }
};
