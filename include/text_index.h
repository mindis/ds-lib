#ifndef DSL_TEXT_INDEX_H_
#define DSL_TEXT_INDEX_H_

#include <cstdint>
#include <vector>
#include <iostream>

namespace dsl {

class TextIndex {
 public:
  TextIndex() {
  }

  virtual ~TextIndex() {
  }

  virtual std::vector<int64_t> search(const std::string& query) const = 0;
  virtual int64_t count(const std::string& query) const = 0;

  virtual size_t serialize(std::ostream& out) = 0;
  virtual size_t deserialize(std::istream& in) = 0;
};

}
#endif // DSL_TEXT_INDEX_H_
